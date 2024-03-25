/* dap1.c -- sort and table */

/*  Copyright (C) 2001, 2002, 2003 Free Software Foundation, Inc.
 *
 *  This file is part of Dap.
 *
 *  Dap is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Dap is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Dap.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "dap_make.h"
#include "externs.h"

extern char *dap_dapname;	/* name of program running */
extern DFILE *dap_in[2];	/* input dataset files */
extern DFILE *dap_out[2];	/* output dataset files */
extern dataobs dap_obs[];	/* values from current input line */
extern dataobs dap_prev[];	/* values from previous input line */
extern int dap_ono;            /* specifies which set of variable values (dataobs) to use */
extern FILE *dap_lst;		/* .lst file */
extern FILE *dap_err;		/* .err file */
extern FILE *dap_log;		/* .log file */
extern char *dap_title;		/* title for sections in .lst file */

extern int dap_maxlines;	/* maximum number of lines in a ramfile */

static int *startmem;
static int *start[2];

static void sortparse(char line[], int which)
{
  int v;
  int l;
  int newfield;

  for (v = 0, l = 0, newfield = 1; line[l] && line[l] != '\n'; l++)
    {
      if (newfield)
	start[which][v++] = l;
      newfield = (line[l] == SETDELIM);
    }
}

static char *mod;
static int nmods;
static int *varv;
static int nvar;

static int fieldcmp(char f1[], char f2[])
{
  int f;

  for (f = 0; f1[f] && f1[f] != SETDELIM && f1[f] != '\n' && f1[f] == f2[f]; f++)
    ;
  if (f1[f] == f2[f])
    return 0;
  if (!f1[f] || f1[f] == SETDELIM || f1[f] == '\n')
    return -1;
  if (!f2[f] || f2[f] == SETDELIM || f2[f] == '\n')
    return 1;
  return f1[f] - f2[f];
}

static int sortcmp(char **e0, char **e1)
{
  int v;
  int cmp;

  cmp = 0;
  sortparse(*e0, 0);
  sortparse(*e1, 1);
  for (v = 0; v < nvar; v++)
    {
      cmp = fieldcmp(*e0 + start[0][varv[v]], *e1 + start[1][varv[v]]);
      if (cmp)
	break;
    }
  if (nmods && mod[v] == 'd')
    cmp = -cmp;
  return cmp;
}

static int linediff(char l1[], char l2[])
{
  int l;

  for (l = 0; l1[l] && l1[l] != '\n' && l1[l] == l2[l]; l++)
    ;
  return l1[l] != l2[l];
}

static void dsort(char *origset, char *sortset, int sortvar[], int nfields,
	   int unique, char *mod, int nmods); /* disk file sorting function */

void sort(char *fname, char *varlist, char *modifiers)
{
  static int sortinit = 0;	/* memory allocated? */
  int unique; /* in sorted dataset, include only one of a group of lines with matching keys? */
  int lastun;
  int l;
  int i;
  int v;
  int vn;
  char *dsrt0;
  char *dsrt;
  char *dfile;
  static char **line;
  int newline;
  int nlines;
  char *c;
  int flen;
  int (*scmp)();

  if (!sortinit)
    {
      sortinit = 1;
      line = (char **) dap_malloc(sizeof(char *) * dap_maxlines, "");
      startmem = (int *) dap_malloc(sizeof(int) * 2 * dap_maxvar, "");
      start[0] = startmem;
      start[1] = startmem + dap_maxvar;
      mod = dap_malloc(dap_maxvar, "");
      varv = (int *) dap_malloc(sizeof(int) * dap_maxvar, "");
    }
  if (!fname)
    {
      fprintf(dap_err, "%s:sort: no dataset name given\n", dap_dapname);
      exit(1);
    }
  scmp = &sortcmp;
  unique = 0;
  if (modifiers)
    {
      for (l = 0; modifiers[l] == ' '; l++)
	;
      for (nmods = 0, unique = 0; modifiers[l]; )
	{
	  if (modifiers[l] == 'u')
	    {
	      unique = 1;
	      l++;
	    }
	  else if (modifiers[l] == 'i' || modifiers[l] == 'd')
	    {
	      while (modifiers[l] == 'i' || modifiers[l] == 'd')
		mod[nmods++] = modifiers[l++];
	    }
	  else
	    {
	      fprintf(dap_err, "(sort) Bad modifier(s): %s\n", modifiers);
	      exit(1);
	    }
	  while (modifiers[l] == ' ')
	    l++;
	}
    }
  else
    nmods = 0;
  dsrt0 = dap_malloc(strlen(fname) + 5, "");
  dap_suffix(dsrt0, fname, ".srt");
  inset(fname);
  outset(dsrt0, "");
  nvar = dap_list(varlist, varv, dap_maxvar);
  if (nmods && (nvar != nmods))
    {
      fprintf(dap_err,
	      "(sort) Number of modifiers %d does not equal number of sort variables %d.\n",
	      nmods, nvar);
      exit(1);
    }
  if (fname[0] == '<')
    {
      for (nlines = 0, i = dap_ftell(dap_in[0]), newline = 1;
	   i < dap_in[0]->dfile_ram->rfile_end -
	     dap_in[0]->dfile_ram->rfile_str; i++)
	{
	  if (newline)
	    {
	      if (nlines < dap_maxlines)
		line[nlines++] = dap_in[0]->dfile_ram->rfile_str + i;
	      else
		{
		  fprintf(dap_err, "(sort) Too many lines in ramfile %s\n",
			  fname);
		  exit(1);
		}
	    }
	  newline = (dap_in[0]->dfile_ram->rfile_str[i] == '\n');
	}
      qsort(line, nlines, sizeof(char *), scmp);
      for (l = 0, lastun = -1; l < nlines; l++)
	{
	  if (!unique || lastun < 0 || linediff(line[lastun], line[l]))
	    {
	      for (c = line[l]; c < dap_in[0]->dfile_ram->rfile_end && *c != '\n';
		   c++)
		dap_putc(*c, dap_out[0]);
	      dap_putc('\n', dap_out[0]);
	      lastun = l;
	    }
	  else
	    {
	      for (c = line[l]; c < dap_in[0]->dfile_ram->rfile_end && *c != '\n';
		   c++)
		;
	    }
	}
      flen = dap_out[0]->dfile_ram->rfile_end - dap_out[0]->dfile_ram->rfile_str;
      memcpy(dap_in[0]->dfile_ram->rfile_str, dap_out[0]->dfile_ram->rfile_str, flen);
      dap_in[0]->dfile_ram->rfile_end = dap_in[0]->dfile_ram->rfile_str + flen;
    }
  else
    {
      inset(NULL); /* because we had to call inset before and now we don't want it */
      dfile = dap_malloc(strlen(fname) + strlen(dap_setdir) + 2, "");
      dap_name(dfile, fname);
      dsrt = dap_malloc(strlen(dsrt0) + strlen(dap_setdir) + 2, "");
      dap_name(dsrt, dsrt0);
      dsort(dfile, dsrt, varv, nvar, unique, mod, nmods);
      dap_free(dsrt, "");
      dap_free(dfile, "");
    }
  dap_free(dsrt0, "");
}

/* Print header for function "print" */
static void printhead(char **formstr, int space, char *fname, int *varv, int nvar)
{
  int v;
  int d;
  char *ttext;
  int wastitle;	/* flag: was there a title? */

  ttext = dap_malloc(strlen(fname) + 11, "");
  if (dap_title)
    wastitle = 1;
  else
    {
      wastitle = 0;
      strcpy(ttext, "Printing: ");
      strcat(ttext, fname);
      title(ttext);
    }
  dap_head((int *) NULL, 0);
  if (space == ' ')
    fprintf(dap_lst, "  Obs ");
  for (v = 0; v < nvar; v++)
    {
      if (space != ' ' && !strcmp(dap_obs[0].do_nam[varv[v]], "_type_"))
	continue;
      if (dap_obs[0].do_len[varv[v]] <= 0)
	{
	  if (space == ' ')
	    fprintf(dap_lst, "%12s", dap_obs[0].do_nam[varv[v]]);
	  else
	    fprintf(dap_lst, "%s", dap_obs[0].do_nam[varv[v]]);
	}
      else
	fprintf(dap_lst, formstr[v], dap_obs[0].do_nam[varv[v]]);
      if (v < nvar - 1)
	putc(space, dap_lst);
    }
  putc('\n', dap_lst);
  if (space == ' ')
    {
      fprintf(dap_lst, "----- ");
      for (v = 0; v < nvar; v++)
	{
	  for (d = 0; dap_obs[0].do_nam[varv[v]][d]; d++)
	    putc('-', dap_lst);
	  if (dap_obs[0].do_len[varv[v]] <= 0)	/* DBL or INT */
	    {
	      while (d < 12)
		{
		  putc('-', dap_lst);
		  d++;
		}
	    }
	  else
	    {
	      while (d < dap_obs[0].do_len[varv[v]])
		{
		  putc('-', dap_lst);
		  d++;
		}
	    }
	  putc(' ', dap_lst);
	}
      putc('\n', dap_lst);
    }
  if (!wastitle)
    title(NULL);
  dap_free(ttext, "");
}

/* Print values in dataset. If varlist is NULL or "" or "\t" or ",", print values
 * of all variables, otherwise just print those of named variables.
 * If the variables in varlist are separated by spaces, then output
 * contains value of _type_ variable and the observation number.
 * Otherwise, the variables must be separated by tabs or commas and
 * the value of _type_ variable and the observation number are omitted.
 * No special handling is performed for strings containing tabs or commas.
 */
void print(char fname[], char *varlist)
{
  char *varlist1; /* copy of varlist, changing tabs to spaces if necessary */
  int space; /* space character for output: space, tab, or comma */
  int *varv; /* vector of indices for variables */
  int nvar; /* number of variables to print */
  int typen; /* index of type variable in varv */
  char *formmem; /* memory for formats */
  char **formstr; /* format string */
  int v; /* index to varlist and to varv */
  int lenstr; /* length of string variable */
  int obn;

  varv = (int *) dap_malloc(sizeof(int) * dap_maxvar, "");
  inset(fname);
  space = ' ';
  if (varlist && varlist[0])
    {
      varlist1 = (char *) dap_malloc(strlen(varlist) + 1, "");
      for (v = 0; varlist[v]; v++)
	{
	  if (varlist[v] == '\t' || varlist[v] == ',')
	    {
	      varlist1[v] = ' ';
	      if (space == ' ')
		space = varlist[v];
	      else if (space != varlist[v])
		{
		  fputs("(print) variable list contains more than one type of separator\n",
			dap_err);
		  exit(1);
		}
	    }
	  else
	    varlist1[v] = varlist[v];
	}
      varlist1[v] = '\0';
      if ((varv[0] = dap_varnum("_type_")) < 0)
	{
	  fputs("(print) Missing _type_ variable.\n", dap_err);
	  exit(1);
	}
      typen = varv[0];
      nvar = 1 + dap_list(varlist1, varv + 1, dap_maxvar - 1);
      if (nvar == 1) /* there were no variables, just the separator */
	{
	  nvar = dap_obs[0].do_nvar;
	  for (v = 0; v < nvar; v++)
	    varv[v] = v;
	}
      dap_free(varlist1, "");
    }
  else
    {
      nvar = dap_obs[0].do_nvar;
      for (v = 0; v < nvar; v++)
	varv[v] = v;
    }
  formmem = dap_malloc(nvar * 10, "");
  formstr = (char **) dap_malloc(sizeof(char *) * nvar, "");
  for (v = 0; v < nvar; v++)
    formstr[v] = formmem + 10 * v;
  for (v = 0; v < nvar; v++)
    {
      if (dap_obs[0].do_len[varv[v]] == INT)
	{
	  lenstr = strlen(dap_obs[0].do_nam[varv[v]]);
	  if (lenstr < 12)
	    lenstr = 12;
	  if (space != ' ')
	    lenstr = 0;
	  sprintf(formstr[v], "%%%dd", lenstr);
	}
      else if (dap_obs[0].do_len[varv[v]] == DBL)
	{
	  lenstr = strlen(dap_obs[0].do_nam[varv[v]]);
	  if (lenstr < 12)
	    lenstr = 12;
	  if (space != ' ')
	    lenstr = 0;
	  sprintf(formstr[v], "%%%dg", lenstr);
	}
      else
	{
	  lenstr = strlen(dap_obs[0].do_nam[varv[v]]);
	  if (lenstr < dap_obs[0].do_len[varv[v]])
	    lenstr = dap_obs[0].do_len[varv[v]];
	  if (space != ' ')
	    lenstr = 0;
	  sprintf(formstr[v], "%%-%ds", lenstr);
	}
    }
  printhead(formstr, space, fname, varv, nvar);
  for (obn = 1; step(); )
    {
      if (space == ' ')
	fprintf(dap_lst, "%5d ", obn);
      for (v = 0; v < nvar; v++)
	{
	  if (space != ' ' && varv[v] == typen)
	    continue;
	  if (dap_obs[0].do_len[varv[v]] == INT)
	    fprintf(dap_lst, formstr[v], dap_obs[0].do_int[varv[v]]);
	  else if (dap_obs[0].do_len[varv[v]] == DBL)
	    fprintf(dap_lst, formstr[v], dap_obs[0].do_dbl[varv[v]]);
	  else
	    fprintf(dap_lst, formstr[v], dap_obs[0].do_str[varv[v]]);
	  if (v < nvar - 1)
	    putc(space, dap_lst);
	}
      putc('\n', dap_lst);
      obn++;
    }
  fflush(dap_lst);
  dap_free(varv, "");
  dap_free(formmem, "");
  dap_free(formstr, "");
}

int dap_mnsparse(char *varlist, char *outlist, int *varv, int *wtvar, int stats[])
{
  int v;
  int i;
  int j;
  int k;
  char *vname;
  char *tmplist;
  int vn;
  int wn;
  int nvar;
  int s;
  int nonly;	/* only requested N, for var that didn't exist */

  if (!varlist)
    {
      fputs("(meansparse) Missing variable list.\n", dap_err);
      exit(1);
    }
  vname = dap_malloc(dap_namelen + 6, "");
  for (v = 0; varlist[v]; v++)
    ;
  for (--v; v >= 0 && varlist[v] == ' '; --v)
    ;
  nvar = 0;
  tmplist = dap_malloc(dap_listlen + 1, "");
  tmplist[0] = '\0';
  wn = -1;
  for (nonly = 0; v >= 0; )
    {
      for (i = v; i >= 0 && varlist[i] != ' ' && varlist[i] != '*'; --i)
	;
      for (j = 0; j < v - i; j++)
	{
	  if (j < dap_namelen)
	    vname[j] = varlist[i + j + 1];
	  else
	    {
	      vname[j] = '\0';
	      fprintf(dap_err, "(meansparse) Variable name too long: %s\n",
		      vname);
	    }
	}
      vname[j] = '\0';
      while (i >= 0 && varlist[i] == ' ')
	--i;
      if ((vn = dap_varnum(vname)) >= 0)
	{
	  if (dap_obs[0].do_len[vn] == DBL)
	    {
	      if (tmplist[0])
		strcat(tmplist, " ");
	      strcat(tmplist, vname);
	    }
	  else
	    {
	      fprintf(dap_err, "(meansparse) Variable must be double: %s\n",
		      vname);
	      exit(1);
	    }
	}
      else
	{
	  for (s = 0; s < NSTATS; s++)
	    {
	      if (s != N && stats[s])
		{
		  fprintf(dap_err,
			  "(meansparse) Statistics other than N requested for unknown variable %s\n",
			  vname);
		  exit(1);
		}
	    }
	  strcpy(tmplist, vname);
	  strcat(vname, " -1");
	  vn = dap_vd(vname, 0);
	  nonly = 1;
	}
      v = i;
      if (v >= 0 && varlist[v] == '*')
	{
	  wn = vn;
	  for (--v; v >= 0 && varlist[v] == ' '; --v)
	    ;
	}
      else
	{
	  wtvar[nvar] = wn;
	  varv[nvar++] = vn;
	}
    }
  for (i = 0; tmplist[i]; i++)
    ;
  for (--i; i >= 0 && tmplist[i] == ' '; --i)
    ;
  for (outlist[0] = '\0'; i >= 0; )
    {
      for (j = i; j > 0 && tmplist[j - 1] != ' '; --j)
	;
      for (k = 0; k <= i - j; k++)
	vname[k] = tmplist[j + k];
      vname[k] = '\0';
      if (outlist[0])
	strcat(outlist, " ");
      strcat(outlist, vname);
      for (i = j - 1; i >= 0 && tmplist[i] == ' '; --i)
	;
    }
  dap_free(vname, "");
  dap_free(tmplist, "");
  if (nonly)
    return -nvar;
  return nvar;
}

/* Keep consistent with list in dap_make.h!  */
char dap_sttnm[NSTATS][STATLEN + 1] =
{
  "N",
  "SUM",
  "SUMWT",
  "MEAN",
  "MIN",
  "MAX",
  "RANGE",
  "STEPXXXX",
  "VAR",
  "VARM",
  "SD",
  "SEM",
  "VARFREQ",
  "VARMFREQ",
  "SDFREQ",
  "SEMFREQ",
  "T",
  "TPROB",
  "QRANGE",
  "SIGN",
  "SPROB",
  "SRANK",
  "SRPROB",
  "NORMAL",
  "NPROB",
  "P1",
  "P5",
  "P10",
  "Q1",
  "MED",
  "Q3",
  "P90",
  "P95",
  "P99",
  "PXXXXX",
  "PXXXXX",
  "PXXXXX"
};

void dap_stats(char *statlist, int *stats)
{
  int s;
  int i;
  char *stat;
  int sn;
  double pctpt;
  int pctptn;

  for (s = 0; s < NSTATS; s++)
    stats[s] = 0;
  if (!statlist)
    return;
  if (!stats)
    {
      fputs("(dap_stats) Missing statistics index list.\n", dap_err);
      exit(1);
    }
  for (s = 0; statlist[s] == ' '; s++)
    ;
  stat = dap_malloc(dap_namelen + 1, "");
  for (pctptn = 0; statlist[s]; )
    {
      for (i = 0; statlist[s + i] && statlist[s + i] != ' '; i++)
	{
	  if (i < dap_namelen)
	    stat[i] = statlist[s + i];
	  else
	    {
	      stat[i] = '\0';
	      fprintf(dap_err, "(dap_stats) Statistic name too long: %s\n", stat);
	      exit(1);
	    }
	}
      stat[i] = '\0';
      if (!strcmp(stat, "STD")) /* kluge to allow variants for SD, SEM, TPROB */
	strcpy(stat, "SD");
      else if (!strcmp(stat, "STDERR"))
	strcpy(stat, "SEM");
      else if (!strcmp(stat, "PRT"))
	strcpy(stat, "TPROB");
      else if (!strcmp(stat, "MEDIAN"))
	strcpy(stat, "MED");
      for (sn = 0; sn < NSTATS - MAXPCTPT + pctptn; sn++)
	{
	  if (!strcmp(stat, dap_sttnm[sn]))
	    {
	      stats[sn] = 1;
	      break;
	    }
	}
      if (sn == NSTATS - MAXPCTPT + pctptn)
	{
	  if (!strncmp(stat, "STEP", 4))
	    {
	      stat[8] = '\0';
	      strcpy(dap_sttnm[STEP], stat);
	      stats[STEP] = 1;
	    }
	  else if (stat[0] == 'P' && sscanf(stat + 1, "%lf", &pctpt) == 1)
	    {
	      if (pctptn++ < MAXPCTPT)
		{
		  stats[sn] = 1;
		  strcpy(dap_sttnm[sn++], stat);
		}
	      else
		{
		  fprintf(dap_err,
			  "(dap_stats) Too many user-defined statistics: %s\n",
			  stat);
		  exit(1);
		}
	    }
	  else
	    {
	      fprintf(dap_err, "(dap_stats) Invalid statistic name: %s\n", stat);
	      exit(1);
	    }
	}
      s += i;
      while (statlist[s] == ' ')
	s++;
    }
  dap_free(stat, "");
}

static void meansout(int varv[], int nvar, int nobs[], double sum[], double sumwt[],
		     double min[], double max[], double ss[], int stats[])
{
  double *dn;
  int typevar;
  int v;
  int nsteps;
  int step;
  double *range;
  double fract;

  dap_swap();
  dn = (double *) dap_malloc(sizeof(double) * nvar, "");
  for (v = 0; v < nvar; v++)
    dn[v] = (double) nobs[v];
  if ((typevar = dap_varnum("_type_")) < 0)
    {
      fprintf(dap_err, "(meansout) Missing _type_ variable\n");
      exit(1);
    }
  if (stats[N])
    {
      strcpy(dap_obs[0].do_str[typevar], "N");
      for (v = 0; v < nvar; v++)
	{
	  if (nobs[v] >= 1)
	    dap_obs[0].do_dbl[varv[v]] = dn[v];
	  else
	    dap_obs[0].do_dbl[varv[v]] = 0.0 / 0.0;
	}
      output();
    }
  if (stats[SUM])
    {
      strcpy(dap_obs[0].do_str[typevar], "SUM");
      for (v = 0; v < nvar; v++)
	{
	  if (nobs[v] >= 1)
	    dap_obs[0].do_dbl[varv[v]] = sum[v];
	  else
	    dap_obs[0].do_dbl[varv[v]] = 0.0 / 0.0;
	}
      output();
    }
  if (stats[SUMWT])
    {
      strcpy(dap_obs[0].do_str[typevar], "SUMWT");
      for (v = 0; v < nvar; v++)
	{
	  if (nobs[v] >= 1)
	    dap_obs[0].do_dbl[varv[v]] = sumwt[v];
	  else
	    dap_obs[0].do_dbl[varv[v]] = 0.0 / 0.0;
	}
      output();
    }
  if (stats[MEAN])
    {
      strcpy(dap_obs[0].do_str[typevar], "MEAN");
      for (v = 0; v < nvar; v++)
	{
	  if (nobs[v] >= 1)
	    dap_obs[0].do_dbl[varv[v]] = sum[v] / sumwt[v];
	  else
	    dap_obs[0].do_dbl[varv[v]] = 0.0 / 0.0;
	}
      output();
    }
  if (stats[MIN])
    {
      strcpy(dap_obs[0].do_str[typevar], "MIN");
      for (v = 0; v < nvar; v++)
	{
	  if (nobs[v] >= 1)
	    dap_obs[0].do_dbl[varv[v]] = min[v];
	  else
	    dap_obs[0].do_dbl[varv[v]] = 0.0 / 0.0;
	}
      output();
    }
  if (stats[MAX])
    {
      strcpy(dap_obs[0].do_str[typevar], "MAX");
      for (v = 0; v < nvar; v++)
	{
	  if (nobs[v] >= 1)
	    dap_obs[0].do_dbl[varv[v]] = max[v];
	  else
	    dap_obs[0].do_dbl[varv[v]] = 0.0 / 0.0;
	}
      output();
    }
  if (stats[RANGE])
    {
      strcpy(dap_obs[0].do_str[typevar], "RANGE");
      for (v = 0; v < nvar; v++)
	{
	  if (nobs[v] >= 1)
	    dap_obs[0].do_dbl[varv[v]] = max[v] - min[v];
	  else
	    dap_obs[0].do_dbl[varv[v]] = 0.0 / 0.0;
	}
      output();
    }
  if (stats[VAR])
    {
      strcpy(dap_obs[0].do_str[typevar], "VAR");
      for (v = 0; v < nvar; v++)
	{
	  if (dn[v] > 1.0)
	    dap_obs[0].do_dbl[varv[v]] = ss[v] / (dn[v] - 1.0);
	  else
	    dap_obs[0].do_dbl[varv[v]] = 0.0 / 0.0;
	}
      output();
    }
  if (stats[SD])
    {
      strcpy(dap_obs[0].do_str[typevar], "SD");
      for (v = 0; v < nvar; v++)
	{
	  if (dn[v] > 1.0)
	    dap_obs[0].do_dbl[varv[v]] =
	      sqrt(ss[v] / (dn[v] - 1.0));
	  else
	    dap_obs[0].do_dbl[varv[v]] = 0.0 / 0.0;
	}
      output();
    }
  if (stats[SEM])
    {
      strcpy(dap_obs[0].do_str[typevar], "SEM");
      for (v = 0; v < nvar; v++)
	{
	  if (dn[v] > 1.0)
	    dap_obs[0].do_dbl[varv[v]] =
	      sqrt(ss[v] / (dn[v] * (dn[v] - 1.0)));
	  else
	    dap_obs[0].do_dbl[varv[v]] = 0.0 / 0.0;
	}
      output();
    }
  if (stats[VARM])
    {
      strcpy(dap_obs[0].do_str[typevar], "VARM");
      for (v = 0; v < nvar; v++)
	{
	  if (dn[v] > 1.0)
	    dap_obs[0].do_dbl[varv[v]] =
	      ss[v] / (dn[v] * (dn[v] - 1.0));
	  else
	    dap_obs[0].do_dbl[varv[v]] = 0.0 / 0.0;
	}
      output();
    }
  if (stats[VARFREQ])
    {
      strcpy(dap_obs[0].do_str[typevar], "VARFREQ");
      for (v = 0; v < nvar; v++)
	{
	  if (sumwt[v] > 1.0)
	    dap_obs[0].do_dbl[varv[v]] =
	      ss[v] / (sumwt[v] - 1.0);
	  else
	    dap_obs[0].do_dbl[varv[v]] = 0.0 / 0.0;
	}
      output();
    }
  if (stats[SDFREQ])
    {
      strcpy(dap_obs[0].do_str[typevar], "SDFREQ");
      for (v = 0; v < nvar; v++)
	{
	  if (sumwt[v] > 1.0)
	    dap_obs[0].do_dbl[varv[v]] =
	      sqrt(ss[v] / (sumwt[v] - 1.0));
	  else
	    dap_obs[0].do_dbl[varv[v]] = 0.0 / 0.0;
	}
      output();
    }
  if (stats[SEMFREQ])
    {
      strcpy(dap_obs[0].do_str[typevar], "SEMFREQ");
      for (v = 0; v < nvar; v++)
	{
	  if (sumwt[v] > 1.0)
	    dap_obs[0].do_dbl[varv[v]] =
	      sqrt(ss[v] / (sumwt[v] * (sumwt[v] - 1.0)));
	  else
	    dap_obs[0].do_dbl[varv[v]] = 0.0 / 0.0;
	}
      output();
    }
  if (stats[VARMFREQ])
    {
      strcpy(dap_obs[0].do_str[typevar], "SEMFREQ");
      for (v = 0; v < nvar; v++)
	{
	  if (sumwt[v] > 1.0)
	    dap_obs[0].do_dbl[varv[v]] =
	      ss[v] / (sumwt[v] * (sumwt[v] - 1.0));
	  else
	    dap_obs[0].do_dbl[varv[v]] = 0.0 / 0.0;
	}
      output();
    }
  if (stats[STEP])
    {
      if (sscanf(dap_sttnm[STEP] + 4, "%d", &nsteps) == 1)
	{
	  range = (double *) dap_malloc(sizeof(double) * nvar, "");
	  strcpy(dap_obs[0].do_str[typevar], "STEP");
	  for (v = 0; v < nvar; v++) 
	    {
	      if (nobs[v] >= 1)
		range[v] = max[v] - min[v];
	      else
		range[v] = 0.0 / 0.0;
	    }
	  for (step = 0; step <= nsteps; step++)
	    {
	      fract = ((double) step) / ((double) nsteps);
	      for (v = 0; v < nvar; v++)
		dap_obs[0].do_dbl[varv[v]] =
		  min[v] + range[v] * fract;
	      output();
	    }
	  dap_free(range, "");
	}
      else
	{
	  fprintf(dap_err, "(meansout) Bad number of steps: %s\n",
		  dap_sttnm[STEP] + 4);
	  exit(1);
	}
    }
  if (stats[T])
    {
      strcpy(dap_obs[0].do_str[typevar], "T");
      for (v = 0; v < nvar; v++)
	{
	  if (sumwt[v] > 0.0 && ss[v] > 0.0)
	    dap_obs[0].do_dbl[varv[v]] = (sum[v] /
					  sumwt[v]) * sqrt(sumwt[v] *
							   (dn[v] - 1.0) / ss[v]);
	  else
	    dap_obs[0].do_dbl[varv[v]] = 0.0 / 0.0;
	}
      output();
    }
  if (stats[TPROB])
    {
      strcpy(dap_obs[0].do_str[typevar], "TPROB");
      for (v = 0; v < nvar; v++)
	{
	  if (sumwt[v] > 0.0 && ss[v] > 0.0)
	    dap_obs[0].do_dbl[varv[v]] =
	      2.0 * probt(fabs((sum[v] /
				sumwt[v]) * sqrt(sumwt[v] *
						 (dn[v] - 1.0) / ss[v])), nobs[v] - 1);
	  else
	    dap_obs[0].do_dbl[varv[v]] = 0.0 / 0.0;
	}
      output();
    }
  dap_swap();
  dap_free(dn, "");
}

int dap_list(char *varlist, int *varv, int maxvars)
{
  int nvars;
  int m;
  int i;
  char *mname;

  if (!varlist)
    return 0;
  if (!varv)
    {
      fputs("(dap_list) Missing variable index list.\n", dap_err);
      exit(1);
    }
  for (m = 0; varlist[m] == ' '; m++)
    ;
  mname = dap_malloc(dap_namelen + 1, "");
  for (nvars = 0; varlist[m]; )
    {
      for (i = 0; varlist[m + i] && varlist[m + i] != ' '; i++)
	{
	  if (i < dap_namelen)
	    mname[i] = varlist[m + i];
	  else
	    {
	      mname[i] = '\0';
	      fprintf(dap_err, "(dap_list) variable name too long: %s\n",
		      mname);
	      exit(1);
	    }
	}
      mname[i] = '\0';
      if (nvars >= maxvars)
	{
	  fprintf(dap_err, "(dap_list) More than %d variables: %s\n", maxvars, varlist);
	  exit(1);
	}
      if ((varv[nvars++] = dap_varnum(mname)) < 0)
	{
	  fprintf(dap_err, "(dap_list) variable unknown: %s\n", mname);
	  exit(1);
	}
      m += i;
      while (varlist[m] == ' ')
	m++;
    }
  dap_free(mname, "");
  return nvars;
}

int dap_newpart(int markv[], int nmark)
{
  int marked;
  int m;

  marked = 0;
  if (dap_prev[0].do_valid)
    {
      if (dap_obs[0].do_valid)
	{
	  for (m = 0; m < nmark; m++)
	    {
	      if (dap_obs[0].do_len[markv[m]] > 0)
		{
		  if (strcmp(dap_prev[0].do_str[markv[m]],
			     dap_obs[0].do_str[markv[m]]))
		    marked = 1;
		}
	      else if (dap_obs[0].do_len[markv[m]] == INT)
		{
		  if (dap_prev[0].do_int[markv[m]] !=
		      dap_obs[0].do_int[markv[m]])
		    marked = 1;
		}
	      else
		{
		  if (dap_prev[0].do_dbl[markv[m]] !=
		      dap_obs[0].do_dbl[markv[m]])
		    marked = 1;
		}
	    }
	}
      else
	marked = 1;
    }
  return marked;
}

void means(char *fname, char *varlist, char *statlist, char *marks)
{
  char *outname;
  int stats[NSTATS];
  int nonly;
  int *varv;
  int *markv;
  int nvar;
  int nmark;
  int *nobs;
  char *outlist;
  int *wtvar;
  double *sum;
  double *sumwt;
  double *ss;
  double *min;
  double *max;
  int v;
  double wt;
  double vtmp;
  double tmp;
  int *nnan;		/* number of NaN's for each variable */
  int more;

  if (!fname)
    {
      fputs("(means) Missing input dataset name.\n", dap_err);
      exit(1);
    }
  outname = dap_malloc(strlen(fname) + 5, "");
  dap_suffix(outname, fname, ".mns");
  varv = (int *) dap_malloc(sizeof(int) * dap_maxvar, "");
  markv = (int *) dap_malloc(sizeof(int) * dap_maxvar, "");
  wtvar = (int *) dap_malloc(sizeof(int) * dap_maxvar, "");
  outlist = dap_malloc(dap_listlen + 1, "");
  inset(fname);
  dap_stats(statlist, stats);
  nvar = dap_mnsparse(varlist, outlist, varv, wtvar, stats);
  if ((nonly = (nvar < 0)))
    nvar = -nvar;
  nobs = (int *) dap_malloc(sizeof(int) * nvar, "");
  nnan = (int *) dap_malloc(sizeof(int) * nvar, "");
  if (marks && marks[0])
    {
      strcat(outlist, " ");
      strcat(outlist, marks);
    }
  outset(outname, outlist);
  nmark = dap_list(marks, markv, dap_maxvar);
  sum = (double *) dap_malloc(sizeof(double) * nvar, "");
  sumwt = (double *) dap_malloc(sizeof(double) * nvar, "");
  ss = (double *) dap_malloc(sizeof(double) * nvar, "");
  min = (double *) dap_malloc(sizeof(double) * nvar, "");
  max = (double *) dap_malloc(sizeof(double) * nvar, "");
  for (v = 0; v < nvar; v++)
    {
      sum[v] = 0.0;
      sumwt[v] = 0.0;
      ss[v] = 0.0;
      nobs[v] = 0;
      nnan[v] = 0;
    }
  for (more = 1; more; )
    {
      more = step();
      if (dap_newpart(markv, nmark))
	{
	  meansout(varv, nvar, nobs, sum, sumwt, min, max, ss, stats);
	  for (v = 0; v < nvar; v++)
	    {
	      if (nnan[v])
		{
		  dap_swap();
		  fprintf(dap_log, "(means) %d NaNs for %s\n",
			  nnan[v], dap_obs[0].do_nam[varv[v]]);
		  dap_swap();
		}
	      sum[v] = 0.0;
	      sumwt[v] = 0.0;
	      ss[v] = 0.0;
	      nobs[v] = 0;
	      nnan[v] = 0;
	    }
	}
      for (v = 0; v < nvar; v++)
	{
	  vtmp = dap_obs[0].do_dbl[varv[v]];
	  if (wtvar[v] >= 0)
	    wt = dap_obs[0].do_dbl[wtvar[v]];
	  else
	    wt = 1.0;
	  if (isfinite(vtmp) && isfinite(wt))
	    {
	      if (!nobs[v])
		{
		  min[v] = vtmp;
		  max[v] = vtmp;
		}
	      else
		{
		  if (vtmp < min[v])
		    min[v] = vtmp;
		  if (vtmp > max[v])
		    max[v] = vtmp;
		  tmp = sum[v] - sumwt[v] * vtmp;
		  ss[v] += tmp * tmp * wt / (sumwt[v] * (sumwt[v] + wt));
		}
	      sumwt[v] += wt;
	      sum[v] += vtmp * wt;
	      nobs[v]++;
	    }
	  else if (nonly)
	    nobs[v]++;
	  else
	    nnan[v]++;
	}
    }
  dap_free(outname, "");
  dap_free(varv, "");
  dap_free(markv, "");
  dap_free(nobs, "");
  dap_free(outlist, "");
  dap_free(wtvar, "");
  dap_free(sum, "");
  dap_free(sumwt, "");
  dap_free(ss, "");
  dap_free(min, "");
  dap_free(max, "");
  dap_free(nnan, "");
}

typedef struct
{
  char *lab;	/* the label */
  int labd;	/* next one down */
  int laba;	/* next one across */
  int labc;	/* column of tableval array */
} labnode;

static char tabform[7];
static char emptyform[5];
static int cellwidth;
static double *tabvalmem;
static double **tableval;
static int *valsetmem;
static int **valset;
static int nrows, ncols;
static labnode *collabel;
static int labroot;
static int nextclab;
static char *rlabmem;
static char **rlptrmem;
static char ***rowlabel;
static int rtitlesp;
static int *rowvar;
static int nrowvar;
static int *colvar;
static int ncolvar;	/* last colvar is analysis variable */
static int colsort;	/* sort column labels? */

static int newlab(char lname[])
{
  if (nextclab == dap_maxclab)
    {
      fprintf(dap_err, "(newlab) too many column labels: %s\n", lname);
      exit(1);
    }
  strcpy(collabel[nextclab].lab, lname);
  collabel[nextclab].labd = -1;
  collabel[nextclab].laba = -1;
  collabel[nextclab].labc = -1;
  return nextclab++;
}

static int nodecnt(int clab)
{
  int across;
  int totalcnt;

  if (collabel[clab].labd < 0)
    return 1;
  for (across = collabel[clab].labd, totalcnt = 0;
       across >= 0; across = collabel[across].laba)
    totalcnt += nodecnt(across);
  return totalcnt;
}

static void labelprint(char name[], int width)
{
  static char *label = NULL;
  int c;

  if (!label)
    label = dap_malloc(dap_strlen + 1, "");
  strcpy(label, name);
  for (c = 0; label[c] && c < width; c++)
    ;
  while (c < width)
    label[c++] = ' ';
  label[c] = '\0';
  fprintf(dap_lst, "%s", label);
}

static void divider(int left, int conn, int sep, int right, int nblank)
{
  int col;
  int c;
  int connect;

  putc(left, dap_lst);
  for (col = 0; col < nrowvar; col++)
    {
      if (col < nblank)
	connect = ' ';
      else
	connect = conn;
      for (c = 0; c < rtitlesp; c++)
	putc(connect, dap_lst);
      if (col < nrowvar - 1)
	{
	  if (col < nblank)
	    putc(left, dap_lst);
	  else
	    putc(sep, dap_lst);
	}
      else
	putc(right, dap_lst);
    }
  for (col = 0; col < ncols; col++)
    {
      for (c = 0; c < cellwidth; c++)
	putc(conn, dap_lst);
      if (col < ncols - 1)
	putc(sep, dap_lst);
      else
	putc(right, dap_lst);
    }
  putc('\n', dap_lst);
}

static void tableline(int start, int depth)
{
  int across;
  int cnt;
  int c;

  for (across = start; across >= 0; across = collabel[across].laba)
    {
      if (!depth)
	{
	  labelprint(collabel[across].lab, cellwidth);
	  cnt = nodecnt(across);
	  for (c = 0; c < (cnt - 1) * (cellwidth + 1); c++)
	    putc(' ', dap_lst);
	  putc('|', dap_lst);
	}
      else
	tableline(collabel[across].labd, depth - 1);
    }
}

static void tablehead()
{
  int row, col;
  int c;

  putc(' ', dap_lst);
  for (col = 0; col < nrowvar; col++)
    {
      for (c = 0; c < rtitlesp + 1; c++)
	putc(' ', dap_lst);
    }
  fputs(dap_obs[0].do_nam[colvar[ncolvar - 1]], dap_lst);
  if (colvar[0] >= 0)
    {
      fputs(" for ", dap_lst);
      for (col = 0; col < ncolvar - 1; col++)
	{
	  fprintf(dap_lst, dap_obs[0].do_nam[colvar[col]]);
	  if (col < ncolvar - 2)
	    fprintf(dap_lst, " / ");
	}
    }
  putc('\n', dap_lst);
  divider('=', '=', '=', '=', 0);
  for (row = 0; row < ncolvar - 1; row++)
    {
      if (row < ncolvar - 2)
	{
	  putc('|', dap_lst);
	  for (col = 0; col < nrowvar; col++)
	    {
	      for (c = 0; c < rtitlesp; c++)
		putc(' ', dap_lst);
	      if (col < nrowvar - 1)
		putc(' ', dap_lst);
	      else
		putc('|', dap_lst);
	    }
	}
      else
	{
	  putc('|', dap_lst);
	  for (col = 0; col < nrowvar; col++)
	    {
	      labelprint(dap_obs[0].do_nam[rowvar[col]], rtitlesp);
	      putc('|', dap_lst);
	    }
	}
      tableline(labroot, row);
      putc('\n', dap_lst);
      if (row < ncolvar - 2)
	divider('|', '-', '+', '|', 0);
    }
  divider('|', '=', '|', '|', 0);
}

static void valprint(int row, int node)
{
  while (node >= 0)
    {
      if (collabel[node].labd >= 0)
	valprint(row, collabel[node].labd);
      else
	{
	  if (valset[row][collabel[node].labc])
	    fprintf(dap_lst, tabform, tableval[row][collabel[node].labc]);
	  else
	    fprintf(dap_lst, emptyform, "");
	  putc('|', dap_lst);
	}
      node = collabel[node].laba;
    }
}

static void tableprint()
{
  int row, col;
  int isblank;
  int nextblank;
  int nblank;
  int nextnblank;

  for (row = 0; row <= nrows; row++)
    {
      putc('|', dap_lst);
      nblank = 0;
      nextnblank = 0;
      for (col = 0, isblank = 1, nextblank = 1;
	   col < nrowvar; col++)
	{
	  if (isblank && rowlabel[row][col][0])
	    {
	      nblank = col;
	      isblank = 0;
	    }
	  if (nextblank && row <= nrows - 1 && rowlabel[row + 1][col][0])
	    {
	      nextnblank = col;
	      nextblank = 0;
	    }
	  labelprint(rowlabel[row][col], rtitlesp);
	  putc('|', dap_lst);
	}
      valprint(row, labroot);
      putc('\n', dap_lst);
      if (nextnblank != nblank)
	nblank = nextnblank;
      if (row <= nrows - 1)
	divider('|', '-', '+', '|', nblank);
      else
	divider('-', '-', '-', '-', 0);
    }
}

static int findcol()
{
  int varn;
  int node, prevnode, nextnode;
  int upnode;
  int cmp;
  char *label;

  nextnode = -1;
  if (colsort && colvar[0] >= 0)
    {
      for (node = labroot, varn = 0, upnode = -1; varn < ncolvar - 1; varn++)
	{
	  if (node >= 0)
	    {
	      for (nextnode = collabel[node].laba;
		   nextnode >= 0 &&
		     strcmp(dap_obs[0].do_str[colvar[varn]],
			    collabel[nextnode].lab) >= 0; )
		{
		  node = nextnode;
		  nextnode = collabel[nextnode].laba;
		}
	      cmp = strcmp(dap_obs[0].do_str[colvar[varn]], collabel[node].lab);
	    }
	  else
	    cmp = -1;
	  if (cmp < 0)	/* only if no node or node is first in horizontal string */
	    {
	      if (upnode >= 0)
		{
		  nextnode = node;
		  node = newlab(dap_obs[0].do_str[colvar[varn]]);
		  collabel[upnode].labd = node;
		  collabel[node].laba = nextnode;
		}
	      else
		{
		  labroot = newlab(dap_obs[0].do_str[colvar[varn]]);
		  collabel[labroot].laba = node;
		  node = labroot;
		}
	    }
	  else if (cmp > 0)
	    {
	      collabel[node].laba = newlab(dap_obs[0].do_str[colvar[varn]]);
	      node = collabel[node].laba;
	      collabel[node].laba = nextnode;
	    }
	  upnode = node;
	  node = collabel[node].labd;
	}
    }
  else
    {
      for (node = labroot, varn = 0, upnode = -1; varn < ncolvar - 1; varn++)
	{
	  if (colvar[0] >= 0)
	    label = dap_obs[0].do_str[colvar[varn]];
	  else
	    label = "";
	  for (prevnode = -1; node >= 0 &&
		 strcmp(label, collabel[node].lab); )
	    {
	      prevnode = node;
	      node = collabel[node].laba;
	    }
	  if (node < 0)
	    {
	      node = newlab(label);
	      if (prevnode >= 0)
		collabel[prevnode].laba = node;
	      else if (upnode >= 0)
		collabel[upnode].labd = node;
	      else
		labroot = node;
	    }
	  upnode = node;
	  node = collabel[node].labd;
	}
    }
  if (collabel[upnode].labc < 0)
    {
      if (ncols >= dap_maxcols)
	{
	  fputs("(findcol) too many columns in table\n", dap_err);
	  exit(1);
	}
      collabel[upnode].labc = ncols++;
    }
  return collabel[upnode].labc;
}

static void tableform(char tform[])
{
  char width[7];
  int w;
  int forg; /* use "f" or "g" format */

  strcpy(width, tform);
  for (w = 0; width[w] && width[w] != '.'; w++)
    ;
  if (width[w] == '.')
    forg = 'f';
  else
    forg = 'g';
  width[w] = '\0';
  cellwidth = atoi(width);
  strcpy(tabform, "%");
  if (forg == 'f')
    {
      strcat(tabform, tform);
      strcat(tabform, "f");
    }
  else
    {
      strcat(tabform, width);
      strcat(tabform, "g");
    }
  sprintf(emptyform, "%%%ds", cellwidth);
}

static void specparse(char rowvars[], char colvars[], char format[])
{
  int t;
  int i;
  int sp;
  char *vname;
  int v;

  vname = dap_malloc(dap_namelen + 1, "");
  nrowvar = 0;
  ncolvar = 0;
  for (t = 0; rowvars[t] == ' '; t++)
    ;
  while (rowvars[t])
    {
      while (rowvars[t] == ' ')
	t++;
      for (i = 0; rowvars[t + i] && rowvars[t + i] != ' '; i++)
	{
	  if (i < dap_namelen)
	    vname[i] = rowvars[t + i];
	  else	
	    {
	      vname[i] = '\0';
	      fprintf(dap_err,
		      "(specparse) Row variable name too long: %s\n",
		      vname);
	      exit(1);
	    }
	}
      vname[i] = '\0';
      if ((v = dap_varnum(vname)) >= 0)
	{
	  if (nrowvar < dap_maxrowv)
	    rowvar[nrowvar++] = v;
	  else
	    {
	      fprintf(dap_err,
		      "(specparse) Too many row variables: %s\n",
		      vname);
	      exit(1);
	    }
	}
      else
	{
	  fprintf(dap_err,
		  "(specparse) Unknown row variable: %s\n",
		  vname);
	  exit(1);
	}
      t += i;
      while (rowvars[t] == ' ')
	t++;
    }
  for (t = 0; colvars[t] == ' '; t++)
    ;
  while (colvars[t])
    {
      for (i = 0; colvars[t + i] && colvars[t + i] != ' '; i++)
	{
	  if (i < dap_namelen)
	    vname[i] = colvars[t + i];
	  else
	    {
	      vname[i] = '\0';
	      fprintf(dap_err,
		      "(specparse) Column variable name too long: %s\n",
		      vname);
	      exit(1);
	    }
	}
      vname[i] = '\0';
      if ((v = dap_varnum(vname)) >= 0)
	{
	  if (ncolvar < dap_maxcolv)
	    colvar[ncolvar++] = v;
	  else
	    {
	      fprintf(dap_err,
		      "(specparse) Too many column variables: %s\n",
		      vname);
	      exit(1);
	    }
	}
      else
	{
	  fprintf(dap_err,
		  "(specparse) Unknown column variable: %s\n",
		  vname);
	  exit(1);
	}
      t += i;
      while (colvars[t] == ' ')
	t++;
    }
  for (t = 0; format[t] == ' '; t++)
    ;
  if (format[t] == 's')
    {
      colsort = 1;
      for (t++; format[t] == ' '; t++)
	;
    }
  else
    colsort = 0;
  /* misuse of vname: initial part of format spec */
  for (i = 0; format[t + i] && format[t + i] != ' '; i++)
    {
      if (i < dap_namelen)
	vname[i] = format[t + i];
      else
	{
	  vname[i] = '\0';
	  fprintf(dap_err,
		  "(specparse) Format too long %s\n", vname);
	  exit(1);
	}
    }
  vname[i] = '\0';
  tableform(vname);
  for (t += i; format[t] == ' '; t++)
    ;
  if (format[t])
    {
      for (sp = 0; '0' <= format[t] && format[t] <= '9'; t++)
	sp = 10 * sp + format[t] - '0';
      if (format[t])
	{
	  fprintf(dap_err,
		  "(specparse) Extra character(s) at end of format: %s\n",
		  format);
	  exit(1);
	}
      rtitlesp = (sp - 1) / nrowvar;
    }
  if (!tabform[0])
    {
      fprintf(dap_err, "(specparse) No format\n");
      exit(1);
    }
  if (!ncolvar)
    {
      fputs("(specparse) No column or analysis variable(s) specified.\n", dap_err);
      exit(1);
    }
  if (ncolvar < 2)
    {
      colvar[1] = colvar[0];
      colvar[0] = -1;
      ncolvar = 2;
    }
  dap_free(vname, "");
}

void table(char *fname, char *rowvars, char *colvars, char *format, char *marks)
{
  static int tabinit = 0;			/* has memory been allocated? */
  static char *prevmem;
  static char **prev;			/* previous value of row variable */
  int r;					/* row number */
  int s;
  int c;					/* column number */
  int v;
  static int *markv;			/* mark vector for grouping */
  int nmark;				/* number of variables for marking groups */
  int more;				/* flag: another line of input read? */
  static char *nstring;			/* temp string for converting numbers to char */

  if (!tabinit)
    {
      tabinit = 1;
      valsetmem = (int *) dap_malloc(dap_maxrows * dap_maxcols * sizeof(int), "");
      valset = (int **) dap_malloc(dap_maxrows * sizeof(int *), "");
      for (r = 0; r < dap_maxrows; r++)
	valset[r] = valsetmem + dap_maxcols * r;
      tabvalmem = (double *) dap_malloc(dap_maxrows * dap_maxcols * sizeof(double), "");
      tableval = (double **) dap_malloc(dap_maxrows * sizeof(double *), "");
      for (r = 0; r < dap_maxrows; r++)
	tableval[r] = tabvalmem + dap_maxcols * r;
      collabel = (labnode *) dap_malloc(dap_maxclab * sizeof(labnode), "");
      for (c = 0; c < dap_maxclab; c++)
	collabel[c].lab = dap_malloc(dap_lablen + 1, "");
      rowvar = (int *) dap_malloc(sizeof(int) * dap_maxvar, "");
      colvar = (int *) dap_malloc(sizeof(int) * dap_maxvar, "");
      rlabmem = dap_malloc(dap_maxrows * dap_maxrowv * (dap_lablen + 1), "");
      rlptrmem = (char **) dap_malloc(sizeof(char *) * dap_maxrows * dap_maxrowv, "");
      rowlabel = (char ***) dap_malloc(sizeof(char **) * dap_maxrows, "");
      for (r = 0; r < dap_maxrows; r++)
	{
	  rowlabel[r] = rlptrmem + r * dap_maxrowv;
	  for (v = 0; v < dap_maxrowv; v++)
	    rowlabel[r][v] = rlabmem +
	      r * (dap_maxrowv * (dap_lablen + 1)) +
	      v * (dap_lablen + 1);
	}
      prevmem = dap_malloc(dap_maxrowv * (dap_lablen + 1), "");
      prev = (char **) dap_malloc(sizeof(char *) * dap_maxrowv, "");
      for (v = 0; v < dap_maxrowv; v++)
	prev[v] = prevmem + v * (dap_lablen + 1);
      markv = (int *) dap_malloc(sizeof(int) * dap_maxvar, "");
      nstring = dap_malloc(dap_strlen + 1, "dap_strlen");
    }
  if (!fname)
    {
      fputs("(table) no dataset name given\n", dap_err);
      exit(1);
    }
  inset(fname);
  tabform[0] = '\0';
  rtitlesp = 8;
  if (!rowvars || !colvars)
    {
      fputs("(table) no row and/or column variables specified\n", dap_err);
      exit(1);
    }
  if (!format)
    {
      fputs("(table) no format given\n", dap_err);
      exit(1);
    }
  /* NOTE: the following has a side-effect to change rtitlesp */
  specparse(rowvars, colvars, format);
  nmark = dap_list(marks, markv, dap_maxvar);
  nextclab = 0;
  labroot = -1;
  ncols = 0;
  for (r = 0; r < nrowvar; r++)
    {
      prev[r][0] = '\0';
      if (dap_obs[0].do_len[rowvar[r]] <= 0)
	{
	  if (dap_obs[0].do_str[rowvar[r]])
	    dap_free(dap_obs[0].do_str[rowvar[r]], "");
	  dap_obs[0].do_str[rowvar[r]] = dap_malloc(rtitlesp + 1, "");
	}
    }
  for (c = 0; c < ncolvar - 1; c++)
    {
      if (dap_obs[0].do_len[colvar[c]] <= 0)
	{
	  if (dap_obs[0].do_str[colvar[c]])
	    dap_free(dap_obs[0].do_str[colvar[c]], "");
	  dap_obs[0].do_str[colvar[c]] = dap_malloc(rtitlesp + 1, "");
	}
    }
  for (r = 0; r < dap_maxrows; r++)
    for (c = 0; c < dap_maxcols; c++)
      valset[r][c] = 0;
  for (nrows = -1, more = 1; more; )
    {
      more = step();
      if (dap_newpart(markv, nmark))
	{
	  dap_swap();
	  dap_head(markv, nmark);
	  tablehead();
	  tableprint();
	  dap_swap();
	  nextclab = 0;
	  labroot = -1;
	  ncols = 0;
	  for (r = 0; r < nrowvar; r++)
	    prev[r][0] = '\0';
	  for (r = 0; r < dap_maxrows; r++)
	    for (c = 0; c < dap_maxcols; c++)
	      valset[r][c] = 0;
	  nrows = -1;
	}
      for (r = 0; r < nrowvar; r++)
	{
	  if (dap_obs[0].do_len[rowvar[r]] == INT)
	    {
	      sprintf(nstring, "%d", dap_obs[0].do_int[rowvar[r]]);
	      strncpy(dap_obs[0].do_str[rowvar[r]], nstring, rtitlesp);
	      dap_obs[0].do_str[rowvar[r]][rtitlesp] = '\0';
	    }
	  else if (dap_obs[0].do_len[rowvar[r]] == DBL)
	    {
	      sprintf(nstring, "%g", dap_obs[0].do_dbl[rowvar[r]]);
	      strncpy(dap_obs[0].do_str[rowvar[r]], nstring, rtitlesp);
	      dap_obs[0].do_str[rowvar[r]][rtitlesp] = '\0';
	    }
	}
      for (r = 0; r < nrowvar; r++)
	{
	  if (strcmp(dap_obs[0].do_str[rowvar[r]], prev[r]))
	    break;
	}
      if (r < nrowvar)
	{
	  nrows++;
	  for (s = 0; s < r; s++)
	    rowlabel[nrows][s][0] = '\0';
	  for ( ; r < nrowvar; r++)
	    {
	      strcpy(prev[r], dap_obs[0].do_str[rowvar[r]]);
	      strcpy(rowlabel[nrows][r],
		     dap_obs[0].do_str[rowvar[r]]);
	    }
	}
      if (nrows < 0)
	{
	  fputs("(table) No rows.\n", dap_err);
	  exit(1);
	}
      for (c = 0; c < ncolvar - 1; c++)
	{
	  if (dap_obs[0].do_len[colvar[c]] == INT)
	    {
	      sprintf(nstring, "%d", dap_obs[0].do_int[colvar[c]]);
	      strncpy(dap_obs[0].do_str[colvar[c]], nstring, rtitlesp);
	      dap_obs[0].do_str[colvar[c]][rtitlesp] = '\0';
	    }
	  else if (dap_obs[0].do_len[colvar[c]] == DBL)
	    {
	      sprintf(nstring, "%g", dap_obs[0].do_dbl[colvar[c]]);
	      strncpy(dap_obs[0].do_str[colvar[c]], nstring, rtitlesp);
	      dap_obs[0].do_str[colvar[c]][rtitlesp] = '\0';
	    }
	}
      c = findcol();
      tableval[nrows][c] = dap_obs[0].do_dbl[colvar[ncolvar - 1]];
      valset[nrows][c] = 1;
    }
}

/* Function to split lines of dataset as documented in the manual
 * fname = name of dataset
 * varlist = list of variables to create separate lines for
 * classvalvars = "class-var value-var"
 */

void split(char *fname, char *varlist, char *classvalvars)
{
  char *skiplist;	/* names of variables not to put in output dataset */
  char *outname;	/* name of output dataset */
  char *classvar;	/* name of classification variable */
  char *valuevar;	/* name of value variable */
  int s, t;	/* indexes to strings */
  char *varname;	/* name of variable in varlist */
  int maxname;	/* maximum length of variable name in varlist */
  int *var;	/* array of indexes to vars in varlist */
  int nv;		/* number of variables in varlist */
  int vv;		/* index to var */
  int vlen;	/* length (type) of variables in varlist */
  int prevlen;	/* for checking constancy of vlen */
  int classv, valuev;	/* indexes of class and value vars */

  /* need space for length specification */
  classvar = dap_malloc(strlen(varlist) + 6, "");	/* should be longer than needed */
  valuevar = dap_malloc(strlen(varlist) + 6, "");	/* should be longer than needed */
  for (s = 0; classvalvars[s] == ' '; s++)	/* skip spaces */
    ;
  /* copy classification variable name */
  for (t = 0; classvalvars[s] && classvalvars[s] != ' '; )
    classvar[t++] = classvalvars[s++];
  classvar[t] = '\0';
  if (!t)
    {
      fputs("(split) No classification variable specified.\n", dap_err);
      exit(1);
    }
  while (classvalvars[s] == ' ')
    s++;	/* skip spaces */
  /* copy value variable name */
  for (t = 0; classvalvars[s] && classvalvars[s] != ' '; )
    valuevar[t++] = classvalvars[s++];
  valuevar[t] = '\0';
  if (!t)
    {
      fprintf(dap_err, "(split) No value variable specified: %s\n", classvalvars);
      exit(1);
    }
  var = (int *) dap_malloc(sizeof(int) * ((strlen(varlist) + 1) / 2), ""); /* more than necessary */
  varname = dap_malloc(strlen(varlist) + 1, "");	/* longest possible name */
  skiplist = dap_malloc(strlen(varlist) + 2, "");	/* prepare to eliminate variables */
  strcpy(skiplist, "!");		/* if outset second parameter starts with '!'... */
  strcat(skiplist, varlist);	/* those variables are dropped */
  outname = dap_malloc(strlen(fname) + 5, ""); /* outname will have ".spl" appended */
  strcpy(outname, fname);
  strcat(outname, ".spl");
  inset(fname);	/* set up input dataset */
  /* now set up variables to split */
  for (s = 0; varlist[s] == ' '; s++)
    ;
  for (nv = 0, prevlen = DBL - 1, maxname = 0; varlist[s]; nv++)
    {
      for (t = 0; varlist[s] && varlist[s] != ' '; )
	varname[t++] = varlist[s++];
      varname[t] = '\0';
      if (t > maxname)
	maxname = t;
      if ((var[nv] = dap_varnum(varname)) < 0)
	{
	  fprintf(dap_err, "(split) Unknown variable: %s\n", varname);
	  exit(1);
	}
      vlen = dap_obs[dap_ono].do_len[var[nv]];
      if (prevlen < DBL)
	prevlen = vlen;
      else if (prevlen != vlen)
	{
	  fprintf(dap_err,
		  "(split) Length of %s (%d) differs from that of previous variables (%d)\n",
		  varname, vlen, prevlen);
	  exit(1);
	}
      while (varlist[s] == ' ')	/* skip to next or end */
	s++;
    }
  sprintf(classvar + strlen(classvar), " %d", maxname);
  classv = dap_vd(classvar, 0);	/* set up variable, 0 = not input from dataset */
  sprintf(valuevar + strlen(valuevar), " %d", vlen);
  valuev = dap_vd(valuevar, 0);	/* set up variable, 0 = not input from dataset */
  outset(outname, skiplist);
  while (step())
    {
      for (vv = 0; vv < nv; vv++)
	{	/* for each variable in varlist */
	  /* copy name to classification variable */
	  strcpy(dap_obs[dap_ono].do_str[classv],
		 dap_obs[dap_ono].do_nam[var[vv]]);
	  /* and value to valuevar */
	  if (vlen == DBL)
	    dap_obs[dap_ono].do_dbl[valuev] =
	      dap_obs[dap_ono].do_dbl[var[vv]];
	  else if (vlen == INT)
	    dap_obs[dap_ono].do_int[valuev] =
	      dap_obs[dap_ono].do_int[var[vv]];
	  else
	    strcpy(dap_obs[dap_ono].do_str[valuev],
		   dap_obs[dap_ono].do_str[var[vv]]);
	  output();	/* and write line to output dataset */
	}
    }
  dap_free(classvar, "");
  dap_free(valuevar, "");
  dap_free(var, "");
  dap_free(skiplist, "");
  dap_free(outname, "");
  dap_free(varname, "");
}




void join(char *fname, char *partvars, char *valuevar)
{
  char *partvars1;	/* all of partvars except last variable */
  int npart;		/* number of these partvars */
  char *classvar;		/* last variable of partvars */
  int s, t;		/* indexes for strings for copying */
  char *outname;		/* name of output dataset */
  char *skiplist;		/* list of variables to exclude from output dataset */
  int cv;			/* index of classvar */
  int vv;			/* index of valuevar */
  int nnew;		/* number of new variables */
  int nv;			/* index to new variable names */
  int vlen;		/* max length needed for new variable name */
  int *partv;		/* index array for partitioning */
  int *newv;		/* array of indexes of new variables */
  int valv;		/* index of valuevar */
  int vallen;		/* length of valuevar, and therefore of new variables */
  char *varspec;		/* for call to dap_vd to allocate new variables */
  int more;		/* for processing dataset: more lines? */
  int np;			/* index to partv */

  outname = dap_malloc(strlen(fname) + 5, "");	/* room for ".joi" */
  strcpy(outname, fname);
  strcat(outname, ".joi");
  newv = (int *) dap_malloc(sizeof(int *) * dap_maxvar, "dap_maxvar");
  partvars1 = dap_malloc(strlen(partvars) + 1, "");	/* partvars1 shorter than partvars */
  /* need to find last variable in partvars */
  for (s = 0; partvars[s] == ' '; s++)
    ;	/* s marks beginning of first variable */
  for (npart = 0; partvars[s]; )	/* while there is a next variable */
    {
      /* skip through variable */
      for (t = s; partvars[t] && partvars[t] != ' '; t++)
	;
      /* continue past spaces following it */
      while (partvars[t] == ' ')
	t++;
      if (partvars[t])	/* found another variable */
	{
	  s = t;		/* mark start */
	  npart++;
	}
      else			/* s marks start of final variable */
	break;
    }
  strncpy(partvars1, partvars, s);
  partvars1[s] = '\0';	/* now we have all but the final variable */
  classvar = dap_malloc(strlen(partvars) - s + 2, "");	/* need extra for null */
  for (t = 0; partvars[s] && partvars[s] != ' '; )
    classvar[t++] = partvars[s++];
  classvar[t] = '\0';	/* get that final variable */
  /* construct list for outset to exclude */
  skiplist = dap_malloc(strlen(classvar) + strlen(valuevar) + 3, "");
  if (strcmp(classvar, "_type_"))	/* always need _type_ */
    sprintf(skiplist, "!%s %s", classvar, valuevar);
  else
    sprintf(skiplist, "!%s", valuevar);
  /* now get new variable names from actual values in the dataset */
  inset(fname);
  if ((cv = dap_varnum(classvar)) < 0)
    {
      fprintf(dap_err, "(join) Unknown variable: %s\n", classvar);
      exit(1);
    }
  if ((valv = dap_varnum(valuevar)) < 0)
    {
      fprintf(dap_err, "(join) Unknown variable: %s\n", valuevar);
      exit(1);
    }
  /* length of valuevar give length of new variables */
  vallen = dap_obs[dap_ono].do_len[valv];
  /* length of string gives length of variable name */
  vlen = dap_obs[dap_ono].do_len[cv];
  varspec = dap_malloc(vlen + 5, "");	/* should be long enough */
  if (vlen <= 0)
    {
      fprintf(dap_err, "(join) Variable %s not string variable (%d)\n", classvar, vlen);
      exit(1);
    }
  dap_mark();	/* after setting all this up, will need to start over */
  partv = (int *) dap_malloc(sizeof(int *) * npart, "");	/* allocate */
  dap_list(partvars1, partv, npart);	/* set up partv index array */
  /* now get new variable names and set them up */
  for (nnew = 0; step(); nnew++)
    {
      if (dap_newpart(partv, npart))	/* complete list must be in first part */
	break;
      /* name of new variable is string value of classvar */
      strcpy(varspec, dap_obs[dap_ono].do_str[cv]);
      /* length (type) comes from valuevar */
      sprintf(varspec + strlen(varspec), " %d", vallen);
      /* set up new variable */
      newv[nnew] = dap_vd(varspec, 0);	/* 0 = not input var */
    }
  dap_rewind();	/* now process the dataset */
  outset(outname, skiplist);
  for (more = 1, nv = 0; more; nv++)
    {
      more = step();
      if (dap_newpart(partv, npart))
	{
	  if (nv < nnew)
	    {
	      fprintf(dap_err, "(join) Too few lines in part:");
	      for (np = 0; np < npart; np++)
		{
		  putc(' ', dap_err);
		  fputs(dap_obs[dap_ono].do_str[partv[np]], dap_err);
		}
	      putc('\n', dap_err);
	      exit(1);
	    }
	  dap_swap();
	  output();
	  dap_swap();
	  nv = 0;
	}
      if (more)
	{
	  if (nv >= nnew)
	    {
	      fprintf(dap_err, "(join) Too many lines at %s\n",
		      dap_obs[dap_ono].do_str[cv]);
	      exit(1);
	    }
	  if (strcmp(dap_obs[dap_ono].do_nam[newv[nv]],
		     dap_obs[dap_ono].do_str[cv]))
	    {
	      fprintf(dap_err, "(join) Missing or extra lines at %s\n",
		      dap_obs[dap_ono].do_str[cv]);
	      exit(1);
	    }
	  if (vallen == DBL)
	    dap_obs[dap_ono].do_dbl[newv[nv]] =
	      dap_obs[dap_ono].do_dbl[valv];
	  else if (vallen == INT)
	    dap_obs[dap_ono].do_int[newv[nv]] =
	      dap_obs[dap_ono].do_int[valv];
	  else
	    strcpy(dap_obs[dap_ono].do_str[newv[nv]],
		   dap_obs[dap_ono].do_str[valv]);
	}
    }
  dap_free(outname, "");
  dap_free(newv, "");
  dap_free(partvars1, "");
  dap_free(classvar, "");
  dap_free(skiplist, "");
  dap_free(varspec, "");
  dap_free(partv, "");
}

/* dsort -- dap dataset sort HERE
 *
 * Usage: sort -f1[d] [-f2[d] ... -fN[d]] [-u] file
 *
 * f1 ... fN are field numbers of keys. First field is number 0.
 * trailing 'd' indicates descending
 * -u indicates delete lines with duplicate keys
 */

/* certain variables are inherited from original call to Unix sort,
 * so must be copied into the variables in this program.
 */
/* variables set by fixheader */
static int *fieldstart; /* starting positions of all the expanded, reordered fields;
			 * fieldstart[nvars] = position after last field
			 */
static int *fieldlen; /* lengths of fields */
static int *unfield; /* inverse operation of field, set by fixheader */
static int linelen; /* length of line with fields expanded to max (no delim or terminator) */
static int keylen; /* length of just the keys */
static int *keyend; /* ends of the keys */
static int *sortord; /* 1 for ascending, 0 for descending */
static int *keymap; /* sortord for each character */
static int nvars; /* number of variables in dataset */

static char *mem1; /* the memories for reordering, sorting, and writing */
static char *mem2;
static int maxlines; /* dap_maxmem / linelen */
static char **line; /* pointers to the beginnings of lines */

static int *field; /* field numbers of keys */
static int nfields; /* number of fields specified */
static int unique; /* -u flag set */

#define TMPLATE "dap_tmp/sortppppppssssss" /* for segment files */
static char tmplate[] = TMPLATE;

static unsigned long int fpos; /* file position at beginning of segment */

static int strtoi(char *s, int *pi, int *ps)
{
  int i;

  for (i = 0; '0' <= *s && *s <= '9'; s++)
    i = 10 * i + *s - '0';
  *pi = i;
  if (*s == 'd')
    {
      *ps = 0;
      s++;
    }
  else
    *ps = 1;
  return !*s;
}

static void cleanup(int nseg)
{
  int s; /* segment number */
  char segname[] = TMPLATE;

  for (s = 0; s < nseg; s++)
    {
      strcpy(segname, tmplate);
      sprintf(segname + 18, "%06d", s);
      unlink(segname);
    }
}

static int linecmp(char **s1, char **s2)
{
  char *t1, *t2;
  char *e1;

  /* run through keys until chars differ or at -- not beyond -- end of keys */
  for (e1 = *s1 + keylen - 1, t1 = *s1, t2 = *s2; t1 < e1 && *t1 == *t2; t1++, t2++)
    ;
  return (keymap[t1 - *s1] ? *t1 - *t2 : *t2 - *t1);
}

/* read in part of orig, sort, and write as segment number s */
static int sortseg(int orig, int s)
{
  char segname[] = TMPLATE;
  ssize_t nread; /* number of bytes read so far */
  int seg; /* file descriptor of segment to write */
  char *m1, *m2; /* for stepping through mem1 and mem2 */
  int nlines; /* the actual number of lines read */
  char *lstart1, *lstart2; /* start of line to be read and written */
  int f; /* index to fields */
  int last; /* last char gotten from line */
  int l; /* for stepping through line */
  char *lp; /* for stepping through fields */
  char *mp; /* for putting characters back into m */
  int newfield; /* starting new field in line? */
  int (*cmp)();

  cmp = &linecmp;
  nread = read(orig, mem1, dap_maxmem); /* read into mem1, reorder fields into mem2 */
  if (!nread) /* nothing to read */
    return 0;
  strcpy(segname, tmplate);
  sprintf(segname + 18, "%06d", s);
  if ((seg = open(segname, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR)) < 0)
    {
      fprintf(dap_err, "(dsort) can't write %s\n", segname);
      exit(1);
    }
  /* lstart1 is start of line we're getting, but may not get all of */
  /* need to reorder fields in accordance with fieldstart */
  for (lstart1 = mem1, lstart2 = mem2, nlines = 0;
       lstart1 < mem1 + nread && lstart2 + linelen < mem2 + dap_maxmem;
       lstart1 = m1, lstart2 += linelen)
    {
      /* do one line */
      if (nlines < maxlines)
	line[nlines++] = lstart2;
      else
	break;
      for (f = 0, m1 = lstart1, last = '\0'; f < nvars; f++) /* for each field */
	{
	  for (m2 = lstart2 + fieldstart[unfield[f]];
	       m1 < mem1 + nread && *m1 != '|' && *m1 != '\n'; )
	    *m2++ = *m1++;
	  last = *m1++;
	  while (m2 < lstart2 + fieldstart[unfield[f] + 1])
	    *m2++ = '\0';
	}
      if (last != '\n') /* didn't finish line */
	break;
    }
  if (last != '\n')
    --nlines;
  nread = lstart1 - mem1; /* last line started but not completed */
  if (!nread)
    {
      fputs("(dsort) line longer than buffer\n", dap_err);
      exit(1);
    }
  fpos += nread;
  qsort(line, nlines, sizeof(char *), cmp);
  for (l = 0; l < nlines; l++)
    memcpy(mem1 + l * linelen, line[l], linelen);
  write(seg, mem1, nlines * linelen);
  close(seg);
  return nread;
}

static char **nextline; /* pointers to next line for each segment */

/* compare the next lines to output of two segments */
static int nextlinecmp(int *s1, int *s2)
{
  return linecmp(nextline + *s1, nextline + *s2);
}

/* read chunks of seg files into mem1, copy merged into mem2 and write out */
static void merge(int nseg, int out)
{
  int s, s1, s2; /* segment number */
  int c;
  int l; /* index to line */
  int f; /* index to fields */
  char *segnamemem;
  char **segname; /* segment names */
  int segfile;
  int chunksize; /* chunk of seg file to read at once */
  int *chunkread; /* amount actually read from segment */
  char *prevline; /* most recent line produced, for checking uniqueness */
  unsigned long int *spos; /* position in segment file */
  int nmore; /* number of segments with more */
  unsigned int outpos; /* position in mem2 */
  int *segord; /* order of next lines in segments */
  int (*scmp)();

  scmp = &nextlinecmp;
  nextline = (char **) dap_malloc(nseg * sizeof(char *), "nextline");
  prevline = NULL; /* mark as not yet set */
  segnamemem = (char *) dap_malloc(nseg * (strlen(TMPLATE) + 1), "segnamemem");
  segname = (char **) dap_malloc(nseg * sizeof(char *), "segname");
  spos = (unsigned long int *) dap_malloc(nseg * sizeof(unsigned long int), "spos");
  segord = (int *) dap_malloc(nseg * sizeof(int), "segord");
  if (!(chunksize = dap_maxmem / (nseg * linelen) * linelen)) /* read in complete lines */
    {
      fputs("(dsort) insufficient memory\n", dap_err);
      exit(1);
    }
  chunkread = (int *) dap_malloc(nseg * sizeof(int), "chunkread");
  /* set up segnames, nextline, spos */
  for (s = 0; s < nseg; s++)
    {
      segname[s] = segnamemem + s * (strlen(TMPLATE) + 1);
      strcpy(segname[s], tmplate);
      sprintf(segname[s] + 18, "%06d", s);
      nextline[s] = mem1 + s * chunksize;
      spos[s] = 0; /* at beginning of segment */
      chunkread[s] = 0; /* nothing yet */
      segord[s] = s;
    }
  /* get initial chunks */
  for (s = 0; s < nseg; s++)
    {
      if ((segfile = open(segname[s], O_RDONLY)) < 0)
	{
	  fprintf(dap_err, "(dsort) can't read %s\n", segname[s]);
	  exit(1);
	}
      if ((chunkread[s] = read(segfile, mem1 + s * chunksize, chunksize)) > 0)
	spos[s] += chunkread[s];
      else
	{
	  fprintf(dap_err, "(dsort) bad initial read of %s\n", segname[s]);
	  exit(1);
	}
      close(segfile);
    }
  /* initial sort of next lines to put out: segord[0] is index of that segment */
  qsort(segord, nseg, sizeof(int), scmp);
  /* now look for first line to copy to mem2 and move on to next line from that file,
   * getting new chunk if necessary
   */
  for (nmore = nseg, outpos = 0; nmore; )
    {
      /* check uniqueness if requested */
      if (unique)
	{
	  if (!prevline)
	    prevline = (char *) dap_malloc(linelen, "prevline");
	}
      /* now need to reformat line */
      if (!unique || (prevline && linecmp(nextline + segord[0], &prevline)))
	{
	  for (f = 0; f < nvars; f++)
	    {
	      for (l = fieldstart[unfield[f]]; l < fieldstart[unfield[f] + 1]; l++)
		{
		  if (outpos == dap_maxmem) /* if there's no room */
		    {
		      write(out, mem2, outpos); /* write it out */
		      outpos = 0; /* ready for more */
		    }
		  if (!(mem2[outpos] = nextline[segord[0]][l]))
		    break;
		  outpos++;
		}
	      if (outpos == dap_maxmem) /* if there's no room */
		{
		  write(out, mem2, outpos); /* write it out */
		  outpos = 0; /* ready for more */
		}
	      if (f < nvars - 1)
		mem2[outpos++] = '|';
	      else
		mem2[outpos++] = '\n';
	    }
	}
      if (unique)
	{
	  if (!prevline)
	    prevline = (char *) dap_malloc(linelen, "prevline");
	  memcpy(prevline, nextline[segord[0]], linelen);
	}
      if ((nextline[segord[0]] += linelen) >=
	  mem1 + segord[0] * chunksize + chunkread[segord[0]])
	{ /* if ran out of data in chunk, read the next chunk */
	  if ((segfile = open(segname[segord[0]], O_RDONLY)) < 0)
	    {
	      fprintf(dap_err, "(dsort) can't read %s\n", segname[segord[0]]);
	      exit(1);
	    }
	  if (lseek(segfile, spos[segord[0]], SEEK_CUR) > 0) /* can get to position */
	    {
	      if ((chunkread[segord[0]] =
		   read(segfile, mem1 + segord[0] * chunksize, chunksize)) > 0)
		{
		  spos[segord[0]] += chunkread[segord[0]];
		  nextline[segord[0]] = mem1 + segord[0] * chunksize;
		}
	      else
		--nmore;
	    }
	  else
	    {
	      chunkread[segord[0]] = 0;
	      --nmore;
	    }
	  close(segfile);
	}
      /* now find next line to output: only segment segord[0] has changed, so we just
       * need to bubble it up as necessary. Number of segments remaining is nmore.
       */
      if (chunkread[segord[0]] <= 0) /* seg gone, just have to shift down the others */
	{
	  for (s = 0; s < nmore; s++)
	    segord[s] = segord[s + 1];
	}
      else /* bubble up as necessary */
	{
	  for (s1 = 1; s1 < nmore; s1++)
	    {
	      if (linecmp(nextline + segord[0], nextline + segord[s1]) <= 0)
		break;
	    }
	  s2 = segord[0];
	  for (s = 0; s < s1 - 1; s++)
	    segord[s] = segord[s + 1];
	  segord[s] = s2;
	}
    }
  if (outpos)
    write(out, mem2, outpos);
  dap_free(nextline, "");
  dap_free(prevline, "");
  dap_free(segnamemem, "");
  dap_free(segname, "");
  dap_free(spos, "");
  dap_free(chunkread, "");
  dap_free(segord, "");
}

/* convert code for field into (max) field length */
static int fieldfix(int code)
{
  switch (code)
    {
    case DBL:
      return 12; /* length of coded double */
    case INT:
      return 6; /* maximum length of coded int */
    default: /* length of string */
      return code;
    }
}

/* reorders header for field comparisons and writes out
 * returns file position after header for resetting pointer
 * sets values of fieldstart and linelen
 */
static int fixheader(char *header, int srt)
{
  int headerlen; /* index to header and length of header */
  int nspaces; /* group variables in header with one internal space */
  int v; /* index to variables */
  int gotsign; /* got sign of field spec */
  int sign; /* sign of field spec */
  int h; /* index to header */
  char *h1; /* pointer to header char */
  int newfield; /* reached end of field, ready for next */
  int fieldlen1; /* length of one field */
  int f, f1, f2; /* indexes to fields */
  int k, k1; /* indexes to keys */
  char **headerfield; /* pointers to start of field names and specs */

  headerfield = (char **) dap_malloc(dap_maxvar * sizeof(char *), "headerfield");
  fieldstart = (int *) dap_malloc((dap_maxvar + 1) * sizeof(int), "fieldstart");
  fieldstart[0] = 0;
  fieldlen = (int *) dap_malloc((dap_maxvar + 1) * sizeof(int), "fieldlen");
  for (headerlen = 0, nspaces = 0, nvars = 0, newfield = 1, linelen = 0;
       headerlen < dap_linelen && header[headerlen] != '\n';
       headerlen++)
    {
      if (newfield) /* get pointer to start of each field */
	{
	  if (nvars)
	    linelen +=
	      (fieldlen[nvars - 1] = fieldfix(sign * fieldlen1));  /* no delimiter */
	  headerfield[nvars++] = header + headerlen;
	  newfield = 0;
	}
      if (header[headerlen] == ' ')
	{
	  if (++nspaces == 1)
	    {
	      fieldlen1 = 0;
	      gotsign = 0; /* not set yet */
	    }
	  else
	    {
	      nspaces = 0;
	      newfield = 1;
	    }
	}
      else if (nspaces == 1 && header[headerlen] != ' ') /* into length spec */
	{
	  if (!gotsign) /* not set yet */
	    {
	      if (header[headerlen] == '-')
		sign = -1;
	      else
		{
		  sign = 1;
		  gotsign = 1;
		}
	    }
	  if (gotsign)
	    fieldlen1 = 10 * fieldlen1 + header[headerlen] - '0';
	  gotsign = 1;
	}
    }
  linelen += (fieldlen[nvars - 1] = fieldfix(sign * fieldlen1)); /* no delimiter */
  /* make map for sort orders */
  maxlines = dap_maxmem / linelen;
  line = (char **) dap_malloc(maxlines * sizeof(char *), "line");
  if (headerlen == dap_linelen)
    {
      header[dap_linelen - 1] = '\0';
      fprintf(dap_err, "(dsort) header line too long %s\n", header);
      exit(1);
    }
  /* now fill in remainder of field array */
  for (f = 0, f2 = nfields; f < nvars; f++)
    {
      for (f1 = 0; f1 < nfields; f1++)
	{
	  if (field[f1] == f)
	    break;
	}
      if (f1 == nfields) /* wasn't there */
	field[f2++] = f;
    }
  /* now invert to create unfield */
  for (f = 0; f < nvars; f++)
    unfield[field[f]] = f;
  /* now set up fieldstarts */
  for (fieldstart[0] = 0, f = 1; f <= nvars; f++)
    fieldstart[f] = fieldstart[f - 1] + fieldlen[field[f - 1]];
  /* now calculate keylen and keyends */
  keyend = (int *) dap_malloc(nfields * sizeof(int), "keyend");
  for (f = 0, keylen = 0; f < nfields; f++)
    {
      keylen += fieldlen[field[f]];
      keyend[f] = keylen;
    }
  keymap = (int *) dap_malloc(keylen * sizeof(int), "keymap");
  for (f = 0, k = 0; f < nfields; f++)
    {
      for (k1 = 0; k1 < fieldlen[field[f]]; k1++)
	keymap[k++] = sortord[f];
    }
  write(srt, header, headerlen + 1);
  dap_free(headerfield, "");
  return headerlen + 1;
}

static void dsort(char *origset, char *sortset, int sortvar[], int nsort,
		  int uniq, char *mod, int nmods)
{
  int f; /* index to field */
  int orig; /* orginal file */
  int nseg; /* number of segments */
  int srt; /* output file */
  char *header; /* dap dataset header */
  int c; /* for skipping and then copying header line */
  struct stat statbuf; /* for seeing if directory exists */

  header = (char *) dap_malloc(dap_linelen, "header");
  field = (int *) dap_malloc(dap_maxvar * sizeof(int), "field");
  unfield = (int *) dap_malloc(dap_maxvar * sizeof(int), "unfield");
  sortord = (int *) dap_malloc(dap_maxvar * sizeof(int), "dsortord");
  nfields = nsort;
  if (!nmods)
    {
      for (f = 0; f < nfields; f++)
	mod[f] = 'i';
    }
  else if (nmods != nfields)
    {
      fprintf(dap_err, "(dsort) nmods (%d) != nfields (%d)\n", nmods, nfields);
      exit(1);
    }
  unique = uniq;
  for (f = 0; f < nfields; f++)
    {
      sortord[f] = (mod[f] == 'i' ? 1 : 0);
      field[f] = sortvar[f];
    }
  if (stat(dap_tmpdir, &statbuf) < 0)
    {
      if (mkdir(dap_tmpdir, (mode_t) 0700) < 0)
	{
	  perror(dap_dapname);
	  exit(1);
	}
    }
  else if (!(statbuf.st_mode & S_IFDIR))
    {
      fprintf(dap_err, "%s: non-directory file exists: %s\n", dap_dapname, dap_tmpdir);
      exit(1);
    }
  /* the memories for reordering, sorting, and writing */
  mem1 = (char *) dap_malloc(2 * dap_maxmem, "mem1");
  mem2 = mem1 + dap_maxmem;
  if (!nfields)
    {
      fputs("(dsort) no fields specified for sorting\n", dap_err);
      exit(1);
    }
  if ((orig = open(origset, O_RDONLY)) < 0)
    {
      fprintf(dap_err, "(dsort) can't read %s\n", origset);
      exit(1);
    }
  if ((srt = open(sortset, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR)) < 0)
    {
      fprintf(dap_err, "(dsort) can't write %s\n", sortset);
      exit(1);
    }
  /* copy header and reorganize for field comparisons */
  if (read(orig, header, dap_linelen) < 0)
    {
      fputs("(dsort) can't read header\n", dap_err);
      exit(1);
    }
  fpos = fixheader(header, srt);
  lseek(orig, fpos, SEEK_SET);
  /* first sort segments of file */
  sprintf(tmplate + 12, "%06d", getpid() % 1000000); /* for creating segment files */
  for (nseg = 0; sortseg(orig, nseg); nseg++)
    lseek(orig, fpos, SEEK_SET);
  /* then merge */
  merge(nseg, srt);
  cleanup(nseg);
  dap_free(header, "");
  dap_free(mem1, "");
  dap_free(fieldstart, "");
  dap_free(line, "");
  dap_free(field, "");
  dap_free(unfield, "");
  dap_free(fieldlen, "");
  dap_free(sortord, "");
  dap_free(keyend, "");
  dap_free(keymap, "");
}

int* bubblesort(int * list,int n, int order){    
  int *returndata=(int *) dap_malloc(n * sizeof(int), "return");
    //copy table
    int i = 0;
    for (i = 0 ;i<n;i++)
    {
      returndata[i]=list[i];
    }
    int swappedcount=0;
    int swapped = 0;
    do {
      swapped = 0;
     
     i = 1;
     for (i = 1 ;i<n;i++)
     {
       if (order>0)
       {
	if (returndata[i-1]>returndata[i])
	{
	  int act=returndata[i];
	  returndata[i]=returndata[i-1];
	  returndata[i-1]=act;
	  swapped = 1;
	  swappedcount++;
	}
       }
       else
       {
	if (returndata[i-1]<returndata[i])
	{
	  int act=returndata[i];
	  returndata[i]=returndata[i-1];
	  returndata[i-1]=act;
	  swapped = 1;
	  swappedcount++;
	}
       }
     }
     }while(swapped);
     printf("nb swapped =%d\n",swappedcount);
     return returndata;
}

void surveyselect(char *fname,char *outname,char *method,int tirage)
{
  inset(fname);	/* set up input dataset */
  //counting nb line
  int nbLines=0;
  while (step())
  {
    nbLines++;
  }
  printf("nblines to read = %d, nb selected = %d\n",nbLines,tirage);
  
  int *list=(int *) dap_malloc(tirage * sizeof(int), "list");
  
  int i=0;
  
  int sysrand=rand()%(nbLines/tirage);
  printf("reload data\n");
  
  printf("create index list based on method\n");
  for (i=0;i<tirage;i++)
  {
    if (strcmp(method,"SRS")==0)
    {
      int notalone=0;
      int choice=0;
      do{
	choice=rand()%nbLines;
	int j=0;
	notalone=0;
	for(j=0;j<i;j++)
	  if(list[j]==choice)
	    notalone=1;
      }while(notalone==1);
      list[i]=choice;
    }else
    if (strcmp(method,"SYS")==0)
    {
      if (i==0)
      {
	list[i]=sysrand;
      }
      else
      {
	list[i]=list[i-1]+nbLines/tirage;
	
      }
      
    }
    
  }
  printf("sort values\n");
  int *listsorted=bubblesort(list,tirage,1);
  int counter=0;
  int index=0;
  printf("set output\n");
  inset(fname);	/* set up input dataset */
  outset(outname, ""); /* set up output dataset */
  while (step())
  {
      int founded=0;
      for(i=0;i<tirage;i++)
      {
	  if(listsorted[i]==counter)
	    founded=1;
      }
      if (founded)
      {

	output();	/* and write line to output dataset */
	index++;
      }
      counter++;
  }
  dap_free(list, "");
  dap_free(listsorted, "");

}
