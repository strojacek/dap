/* dap2.c -- statistics */

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
#include "externs.h"
#include "dap_make.h"

extern dataobs dap_obs[];
extern FILE *dap_lst;
extern FILE *dap_log;
extern FILE *dap_err;
extern char *dap_dapname;

extern char dap_sttnm[NSTATS][STATLEN + 1];

static int dblcmp(double *x, double *y)
{
  if (*x < *y)
    return -1;
  if (*x > *y)
    return 1;
  return 0;
}

static int ddblcmp(double **x, double **y)
{
  if (**x < **y)
    return -1;
  if (**x > **y)
    return 1;
  return 0;
}

static int (*cmp)() = &dblcmp;
static int (*dcmp)() = &ddblcmp;

/* Convert double percentile point to integer index, excess.  */
static void pctpttest(double wtpt, double cumwt, double nextcum,
		      int *pctpt, int n, int *excess)
{
  if (cumwt <= wtpt && wtpt < nextcum)
    {
      *pctpt = n;
      if (wtpt > cumwt)
	*excess = 1;
    }
}

/* Weighted percentiles */
static void pctile2(double ***val, int nobs,
		    int nvar, int *varv, int *wtvar, int *stats)
{
  int v;
  int *pctptmem;
  int **pctpt;
  int *excessmem;
  int **excess;
  int pn;				/* number of user-specified percentiles */
  int pi;				/* index to user-specified percentiles */
  double pct;
  static double sumwt;		/* total sum of weights for specified variable */
  static double cumwt;		/* cumulative sum of wts for specified var */
  static double nextcum;		/* cumwt + next wt to be added in */
  static double wtpt;		/* fraction of sumwt for specified percentile */
  double upct[MAXPCTPT];		/* percent values for user-specified percentiles */
  int n;
  int ptindex;
  int s;
  double q1, q3;
  int typen;

  dap_swap();
  if ((typen = dap_varnum("_type_")) < 0)
    {
      fprintf(dap_err, "(pctile2) missing _type_ variable\n");
      exit(1);
    }
  pctptmem = (int *) dap_malloc(sizeof(int) * nvar * (9 + MAXPCTPT), "");
  pctpt = (int **) dap_malloc(sizeof(int *) * nvar, "");
  excessmem = (int *) dap_malloc(sizeof(int) * nvar * (9 + MAXPCTPT), "");
  excess = (int **) dap_malloc(sizeof(int *) * nvar, "");
  for (pn = 0; pn < MAXPCTPT && stats[NSTATS - MAXPCTPT + pn]; pn++)
    {
      if (sscanf(dap_sttnm[NSTATS - MAXPCTPT + pn] + 1,
		 "%lf", &upct[pn]) != 1)
	{
	  fprintf(dap_err, "(pctile2) invalid percentile: %s\n",
		  dap_sttnm[NSTATS - MAXPCTPT + pn]);
	  exit(1);
	}
    }
  for (v = 0; v < nvar; v++)
    {
      pctpt[v] = pctptmem + v * (9 + MAXPCTPT);
      excess[v] = excessmem + v * (9 + MAXPCTPT);
      qsort((void *) val[v], (size_t) nobs, (size_t) (sizeof(double *)), dcmp);
      for (n = 0, sumwt = 0.0; n < nobs; n++)
	sumwt += val[v][n][1];
      for (s = 0; s < 9 + pn; s++)
	{
	  excess[v][s] = 0;
	  pctpt[v][s] = nobs - 1;
	}
      for (n = 0, cumwt = 0.0; n < nobs; n++, cumwt = nextcum)
	{
	  nextcum = cumwt + val[v][n][1];
	  pctpttest(sumwt / 100.0, cumwt, nextcum, pctpt[v], n, excess[v]);
	  pctpttest(sumwt / 20.0, cumwt, nextcum, pctpt[v] + 1, n, excess[v] + 1);
	  pctpttest(sumwt / 10.0, cumwt, nextcum, pctpt[v] + 2, n, excess[v] + 2);
	  pctpttest(sumwt / 4.0, cumwt, nextcum, pctpt[v] + 3, n, excess[v] + 3);
	  pctpttest(sumwt / 2.0, cumwt, nextcum, pctpt[v] + 4, n, excess[v] + 4);
	  pctpttest(3.0 * sumwt / 4.0, cumwt, nextcum, pctpt[v] + 5, n, excess[v] + 5);
	  pctpttest(9.0 * sumwt / 10.0, cumwt, nextcum, pctpt[v] + 6, n, excess[v] + 6);
	  pctpttest(95.0 * sumwt / 100.0, cumwt, nextcum, pctpt[v] + 7, n, excess[v] + 7);
	  pctpttest(99.0 * sumwt / 100.0, cumwt, nextcum, pctpt[v] + 8, n, excess[v] + 8);
	  for (pi = 0; pi < pn; pi++)
	    {
	      pctpttest(upct[pi] * sumwt / 100.0,
			cumwt, nextcum, pctpt[v] + 9 + pi,
			n, excess[v] + 9 + pi);
	    }
	}
    }
  for (s = 0; s < 9 + pn; s++)
    {
      if (stats[P1 + s])
	{
	  for (v = 0; v < nvar; v++)
	    {
	      ptindex = pctpt[v][s] - 1;
	      if (ptindex < 0)
		ptindex = 0;
	      if (excess[v][s])
		dap_obs[0].do_dbl[varv[v]] = val[v][pctpt[v][s]][0];
	      else
		dap_obs[0].do_dbl[varv[v]] =
		  0.5 * (val[v][pctpt[v][s]][0] + val[v][ptindex][0]);
	    }
	  strcpy(dap_obs[0].do_str[typen], dap_sttnm[P1 + s]);
	  output();
	}
    }
  if (stats[N])
    {
      for (v = 0; v < nvar; v++)
	dap_obs[0].do_dbl[varv[v]] = (double) nobs;
      strcpy(dap_obs[0].do_str[typen], "N");
      output();
    }
  if (stats[MIN])
    {
      for (v = 0; v < nvar; v++)
	dap_obs[0].do_dbl[varv[v]] = val[v][0][0];
      strcpy(dap_obs[0].do_str[typen], "MIN");
      output();
    }
  if (stats[MAX])
    {
      for (v = 0; v < nvar; v++)
	dap_obs[0].do_dbl[varv[v]] = val[v][nobs - 1][0];
      strcpy(dap_obs[0].do_str[typen], "MAX");
      output();
    }
  if (stats[QRANGE])
    {
      for (v = 0; v < nvar; v++)
	{
	  ptindex = pctpt[v][3] - 1;
	  if (ptindex < 0)
	    ptindex = 0;
	  if (excess[v][3])
	    q1 = val[v][pctpt[v][3]][0];
	  else
	    q1 = 0.5 * (val[v][pctpt[v][3]][0] + val[v][ptindex][0]);
	  ptindex = pctpt[v][5] - 1;
	  if (ptindex < 0)
	    ptindex = 0;
	  if (excess[v][5])
	    q3 = val[v][pctpt[v][5]][0];
	  else
	    q3 = 0.5 * (val[v][pctpt[v][5]][0] + val[v][ptindex][0]);
	  dap_obs[0].do_dbl[varv[v]] = q3 - q1;
	}
      strcpy(dap_obs[0].do_str[typen], "QRANGE");
      output();
    }
  dap_swap();
  dap_free(pctptmem, "");
  dap_free(pctpt, "");
  dap_free(excessmem, "");
  dap_free(excess, "");
}

static void pctile1(double ***val, int nobs, int nvar, int *varv, int *stats)
{
  int v;
  double dnobs;
  static int pctpt[9 + MAXPCTPT];
  int pn;
  double pct;
  static int excess[9 + MAXPCTPT];
  int ptindex;
  int s;
  double q1, q3;
  int typen;

  dap_swap();
  if ((typen = dap_varnum("_type_")) < 0)
    {
      fprintf(dap_err, "(pctile1) missing _type_ variable\n");
      exit(1);
    }
  dnobs = (double) nobs;
  pctpt[0] = (int) floor(dnobs / 100.0);
  excess[0] = ((dnobs / 100.0) > floor(dnobs / 100.0));
  pctpt[1] = (int) floor(dnobs / 20.0);
  excess[1] = ((dnobs / 20.0) > floor(dnobs / 20.0));
  pctpt[2] = (int) floor(dnobs / 10.0);
  excess[2] = ((dnobs / 10.0) > floor(dnobs / 10.0));
  pctpt[3] = (int) floor(dnobs / 4.0);
  excess[3] = ((dnobs / 4.0) > floor(dnobs / 4.0));
  pctpt[4] = (int) floor(dnobs / 2.0);
  excess[4] = ((dnobs / 2.0) > floor(dnobs / 2.0));
  pctpt[5] = (int) floor(3.0 * dnobs / 4.0);
  excess[5] = ((3.0 * dnobs / 4.0) > floor(3.0 * dnobs / 4.0));
  pctpt[6] = (int) floor(9.0 * dnobs / 10.0);
  excess[6] = ((9.0 * dnobs / 10.0) > floor(9.0 * dnobs / 10.0));
  pctpt[7] = (int) floor(95.0 * dnobs / 100.0);
  excess[7] = ((95.0 * dnobs / 100.0) > floor(95.0 * dnobs / 100.0));
  pctpt[8] = (int) floor(99.0 * dnobs / 100.0);
  excess[8] = ((99.0 * dnobs / 100.0) > floor(99.0 * dnobs / 100.0));
  for (pn = 0; pn < MAXPCTPT && stats[NSTATS - MAXPCTPT + pn]; pn++)
    {
      sscanf(dap_sttnm[NSTATS - MAXPCTPT + pn] + 1, "%lf", &pct);
      pctpt[9 + pn] = (int) floor(pct * dnobs / 100.0);
      excess[9 + pn] = ((pct * dnobs / 100.0) > floor(pct * dnobs / 100.0));
    }
  for (v = 0; v < nvar; v++)
    qsort((void *) val[v], (size_t) nobs, (size_t) sizeof(double *), dcmp);
  for (s = 0; s < 9 + pn; s++)
    {
      if (stats[P1 + s])
	{
	  for (v = 0; v < nvar; v++)
	    {
	      ptindex = pctpt[s] - 1;
	      if (ptindex < 0)
		ptindex = 0;
	      if (excess[s])
		dap_obs[0].do_dbl[varv[v]] = val[v][pctpt[s]][0];
	      else
		dap_obs[0].do_dbl[varv[v]] =
		  0.5 * (val[v][pctpt[s]][0] + val[v][ptindex][0]);
	    }
	  strcpy(dap_obs[0].do_str[typen], dap_sttnm[P1 + s]);
	  output();
	}
    }
  if (stats[N])
    {
      for (v = 0; v < nvar; v++)
	dap_obs[0].do_dbl[varv[v]] = dnobs;
      strcpy(dap_obs[0].do_str[typen], "N");
      output();
    }
  if (stats[MIN])
    {
      for (v = 0; v < nvar; v++)
	dap_obs[0].do_dbl[varv[v]] = val[v][0][0];
      strcpy(dap_obs[0].do_str[typen], "MIN");
      output();
    }
  if (stats[MAX])
    {
      for (v = 0; v < nvar; v++)
	dap_obs[0].do_dbl[varv[v]] = val[v][nobs - 1][0];
      strcpy(dap_obs[0].do_str[typen], "MAX");
      output();
    }
  if (stats[RANGE])
    {
      for (v = 0; v < nvar; v++)
	dap_obs[0].do_dbl[varv[v]] = val[v][nobs - 1][0] - val[v][0][0];
      strcpy(dap_obs[0].do_str[typen], "RANGE");
      output();
    }
  if (stats[QRANGE])
    {
      for (v = 0; v < nvar; v++)
	{
	  ptindex = pctpt[3] - 1;
	  if (ptindex < 0)
	    ptindex = 0;
	  if (excess[3])
	    q1 = val[v][pctpt[3]][0];
	  else
	    q1 = 0.5 * (val[v][pctpt[3]][0] + val[v][ptindex][0]);
	  ptindex = pctpt[5] - 1;
	  if (ptindex < 0)
	    ptindex = 0;
	  if (excess[5])
	    q3 = val[v][pctpt[5]][0];
	  else
	    q3 = 0.5 * (val[v][pctpt[5]][0] + val[v][ptindex][0]);
	  dap_obs[0].do_dbl[varv[v]] = q3 - q1;
	}
      strcpy(dap_obs[0].do_str[typen], "QRANGE");
      output();
    }
  dap_swap();
}

void pctiles(char *fname, char *varlist, char *statlist, char *marks)
{
  char *outname;
  int stats[NSTATS];
  int *varv;
  int *markv;
  int nvar;
  int nmark;
  int nobs;
  char *outlist;
  int *wtvar;
  int v;
  double *valmem;
  double **valpair;
  double ***val;
  int weighted;
  int more;

  if (!fname)
    {
      fputs("(pctiles) No dataset name given.\n", dap_err);
      exit(1);
    }
  outname = dap_malloc(strlen(fname) + 5, "");
  dap_suffix(outname, fname, ".pct");
  varv = (int *) dap_malloc(sizeof(int) * dap_maxvar, "");
  markv = (int *) dap_malloc(sizeof(int) * dap_maxvar, "");
  wtvar = (int *) dap_malloc(sizeof(int) * dap_maxvar, "");
  /* outlist = dap_malloc(strlen(varlist) + strlen(marks) + 2, ""); ?? */
  outlist = dap_malloc(dap_listlen + 1, "");
  inset(fname);
  dap_stats(statlist, stats);
  nvar = dap_mnsparse(varlist, outlist, varv, wtvar, stats);
  if (marks && marks[0])
    {
      strcat(outlist, " ");
      strcat(outlist, marks);
    }
  outset(outname, outlist);
  nmark = dap_list(marks, markv, dap_maxvar);
  valmem = (double *) dap_malloc(sizeof(double) * nvar * 2 * dap_maxval, "");
  valpair = (double **) dap_malloc(sizeof(double *) * nvar * dap_maxval, "");
  val = (double ***) dap_malloc(sizeof(double *) * nvar, "");
  for (v = 0, weighted = 0; v < nvar; v++)
    {
      if (wtvar[v] >= 0)
	weighted = 1;
    }
  for (nobs = 0, more = 1; more; nobs++)
    {
      more = step();
      if (dap_newpart(markv, nmark))
	{
	  if (weighted)
	    pctile2(val, nobs, nvar, varv,  wtvar, stats);
	  else
	    pctile1(val, nobs, nvar, varv, stats);
	  nobs = 0;
	}
      if (more)
	{
	  if (nobs < dap_maxval)
	    {
	      for (v = 0; v < nvar; v++)
		{
		  valpair[dap_maxval * v + nobs] =
		    valmem + 2 * (dap_maxval * v + nobs);
		  val[v] = valpair + v * dap_maxval;
		  val[v][nobs][0] = dap_obs[0].do_dbl[varv[v]];
		  if (wtvar[v] >= 0)
		    val[v][nobs][1] = dap_obs[0].do_dbl[wtvar[v]];
		  else
		    val[v][nobs][1] = 1.0;
		  if (!isfinite(val[v][nobs][0]) || !isfinite(val[v][nobs][1]))
		    {
		      fprintf(dap_err,
			      "(pctiles) NaN value %d for %s\n",
			      nobs, dap_obs[0].do_nam[varv[v]]);
		      exit(1);
		    }
		}
	    }
	  else
	    {
	      fputs("(pctiles) Too many data.\n", dap_err);
	      exit(1);
	    }
	}
    }
  dap_free(outname, "");
  dap_free(varv, "");
  dap_free(markv, "");
  dap_free(wtvar, "");
  dap_free(outlist, "");
  dap_free(valmem, "");
  dap_free(valpair, "");
  dap_free(val, "");
}

static void corr1(int *varv, int nvar, double **cormat, double ss[], int nobs)
{
  int varn[3];
  int typen;
  double nf;
  int v, w;
  double r;

  if (nobs < 2)
    return;
  dap_swap();
  nf = sqrt((double) (nobs - 2));
  varn[0] = dap_varnum("_var1_");
  varn[1] = dap_varnum("_var2_");
  varn[2] = dap_varnum("_corr_");
  typen = dap_varnum("_type_");
  for (v = 0; v < nvar; v++)
    for (w = 0; w < v; w++)
      cormat[v][w] = cormat[w][v];
  strcpy(dap_obs[0].do_str[typen], "N");
  for (v = 0; v < nvar; v++)
    {
      strcpy(dap_obs[0].do_str[varn[0]], dap_obs[0].do_nam[varv[v]]);
      for (w = 0; w < nvar; w++)
	{
	  strcpy(dap_obs[0].do_str[varn[1]],
		 dap_obs[0].do_nam[varv[w]]);
	  dap_obs[0].do_dbl[varn[2]] = (double) nobs;
	  output();
	}
    }
  strcpy(dap_obs[0].do_str[typen], "CORR");
  for (v = 0; v < nvar; v++)
    {
      strcpy(dap_obs[0].do_str[varn[0]], dap_obs[0].do_nam[varv[v]]);
      for (w = 0; w < nvar; w++)
	{
	  strcpy(dap_obs[0].do_str[varn[1]],
		 dap_obs[0].do_nam[varv[w]]);
	  if (w == v)
	    cormat[v][w] = 1.0;
	  else
	    cormat[v][w] /= sqrt(ss[v] * ss[w]);
	  dap_obs[0].do_dbl[varn[2]] = cormat[v][w];
	  output();
	}
    }
  strcpy(dap_obs[0].do_str[typen], "PCORR");
  for (v = 0; v < nvar; v++)
    {
      strcpy(dap_obs[0].do_str[varn[0]], dap_obs[0].do_nam[varv[v]]);
      for (w = 0; w < nvar; w++)
	{
	  strcpy(dap_obs[0].do_str[varn[1]],
		 dap_obs[0].do_nam[varv[w]]);
	  r = fabs(cormat[v][w]);
	  if (r == 1.0)
	    dap_obs[0].do_dbl[varn[2]] = 0.0;
	  else
	    dap_obs[0].do_dbl[varn[2]] =
	      2.0 * probt(nf * r / sqrt(1.0 - r * r),
			  nobs - 2);
	  output();
	}
    }
  dap_swap();
}

void corr(char *fname, char *varlist, char *marks)
{
  char *outname;
  char varstr[11];
  char *outlist;
  int *markv;
  int nmark;
  int *varv;
  int nvar;
  int nobs;
  double *cormem;
  double **cormat;
  int v, w;
  double *sum;
  double *ss;
  double vtmp;
  double tmp;
  double dn;
  int more;

  if (!fname)
    {
      fputs("(corr) No dataset name given.\n", dap_err);
      exit(1);
    }
  markv = (int *) dap_malloc(sizeof(int) * dap_maxvar, "");
  varv = (int *) dap_malloc(sizeof(int) * dap_maxvar, "");
  outname = dap_malloc(strlen(fname) + 5, "");
  dap_suffix(outname, fname, ".cor");
  outlist = dap_malloc(strlen(marks) + 22, "");
  inset(fname);
  nvar = dap_list(varlist, varv, dap_maxvar);
  cormem = (double *) dap_malloc(sizeof(double) * nvar * nvar, "");
  cormat = (double **) dap_malloc(sizeof(double *) * nvar, "");
  for (v = 0; v < nvar; v++)
    cormat[v] = cormem + v * nvar;
  sum = (double *) dap_malloc(sizeof(double) * nvar, "");
  ss = (double *) dap_malloc(sizeof(double) * nvar, "");
  strcpy(outlist, marks);
  for (v = 0; v < nvar; v++)
    {
      if (dap_obs[0].do_len[varv[v]] >= 0)
	{
	  fprintf(dap_err, "(corr) Variable not of type dap_double: %s\n",
		  dap_obs[0].do_nam[varv[v]]);
	  exit(1);
	}
    }
  sprintf(varstr, "_var1_ %d", dap_namelen);
  dap_vd(varstr, 0);
  sprintf(varstr, "_var2_ %d", dap_namelen);
  dap_vd(varstr, 0);
  sprintf(varstr, "_corr_ %d", DBL);
  dap_vd(varstr, 0);
  strcat(outlist, " _var1_ _var2_ _corr_");
  outset(outname, outlist);
  nmark = dap_list(marks, markv, dap_maxvar);
  for (v = 0; v < nvar; v++)
    {
      if (dap_obs[0].do_len[varv[v]] != DBL)
	{
	  fprintf(dap_err, "(corr) variables must be of type double: %s\n",
		  dap_obs[0].do_nam[varv[v]]);
	  exit(1);
	}
      for (w = v + 1; w < nvar; w++)
	cormat[v][w] = 0.0;
      sum[v] = 0.0;
      ss[v] = 0.0;
    }
  for (nobs = 0, more = 1; more; nobs++)
    {
      more = step();
      if (dap_newpart(markv, nmark))
	{
	  corr1(varv, nvar, cormat, ss, nobs);
	  for (v = 0; v < nvar; v++)
	    {
	      for (w = v + 1; w < nvar; w++)
		cormat[v][w] = 0.0;
	      sum[v] = 0.0;
	      ss[v] = 0.0;
	    }
	  nobs = 0;
	}
      if (more)
	{
	  dn = (double) nobs;
	  for (v = 0; v < nvar; v++)
	    {
	      vtmp = dap_obs[0].do_dbl[varv[v]];
	      if (!isfinite(vtmp))
		{
		  fprintf(dap_err,
			  "(corr) NaN value %d for %s\n",
			  nobs, dap_obs[0].do_nam[varv[v]]);
		  exit(1);
		}
	      if (nobs)
		{
		  tmp = sum[v] - dn * vtmp;
		  for (w = v + 1; w < nvar; w++)
		    {
		      cormat[v][w] += tmp * (sum[w] - dn *
					     dap_obs[0].do_dbl[varv[w]]) /
			(dn * (dn + 1.0));
		    }
		  ss[v] += tmp * tmp / (dn * (dn + 1.0));
		}
	      sum[v] += vtmp;
	    }
	}
    }
  dap_free(markv, "");
  dap_free(varv, "");
  dap_free(outname, "");
  dap_free(outlist, "");
  dap_free(cormem, "");
  dap_free(cormat, "");
  dap_free(sum, "");
  dap_free(ss, "");
}

/* codes for type of grouping */
#define GRPNUMBER (-1)
#define GRPFRACTION (-2)
#define GRPPERCENT (-3)

/* bits for coding descending or not, starting at 0 or not */
#define GRPDESC 0x1
#define GRP0 0x2

/* Construct vector of variable ids (varv) and grouping types:
 * if simply getting count, fraction, or percent, classtype constructed from
 * ORing of GRPDESC and GRP0, otherwise
 * classtype > 0 for number of equal count groups, < 0 for equal width groups.
 * Return number of variables found, but if simply getting count, fraction, or
 * percent, negate with this info tucked into low order bits.
 */
static int groupparse(char *varspec, int varv[], int classtype[])
{
  int s;
  int i;
  int v;
  char *varname; /* variable name or other token from varspec */
  int n;
  int nvar;
  int number; /* Are we going to simply get observation number, fraction, or percent,
	       * (indicated by number == 0) or do grouping (indicated by number == 1?)?
	       * This is specified by first character in varspec.
	       */

  if (!varspec)
    return 0;
  varname = dap_malloc(dap_namelen + 1, "");
  for (s = 0; varspec[s] == ' '; s++) /* skip leading blanks */
    ;
  for (nvar = 0, number = 0; varspec[s]; )
    {
      classtype[nvar] = 0; /* initialize to innocent */
      for (i = 0; varspec[s + i] && varspec[s + i] != ' '; i++)
	{ /* copy variable name or leading character in varspec only */
	  if (i < dap_namelen)
	    varname[i] = varspec[s + i];
	  else
	    {
	      varname[i] = '\0';
	      fprintf(dap_err, "(groupparse) variable name too long: %s\n",
		      varname);
	      exit(1);
	    }
	}
      varname[i] = '\0';
      s += i; /* get past variable name or leading character */
      /* if it's a variable, get its id */
      if ((v = dap_varnum(varname)) >= 0)
	{ /* OK, it's a variable */
	  varv[nvar] = v; /* and place in vector */
	  while (varspec[s] == ' ') /* skip blanks to get to grouping type or next variable */
	    s++;
	  if (number) /* if we got leading character in varspec to specifying grouping */
	    {
	      if (dap_obs[0].do_len[v] != DBL)
		{
		  fprintf(dap_err,
			  "(groupparse) grouping variable must be of type double: %s\n",
			  varname);
		  exit(1);
		}
	    }
	  else /* else we have to get the grouping type */
	    {
	      if ('0' <= varspec[s] && varspec[s] <= '9')
		{ /* first there has to be a number */
		  if (dap_obs[0].do_len[v] == DBL)
		    { /* we're only going to group numbers of type double */
		      for (n = 0, i = 0;
			   '0' <= varspec[s + i] && varspec[s + i] <= '9';
			   i++)
			n = 10 * n + varspec[s + i] - '0';
		      if (!n || (varspec[s + i] != '#' &&
				 varspec[s + i] != '^'))
			{ /* OK, we either didn't get a number or it wasn't followed
			   * by either # (equal count groups) or ^ (equal width groups)
			   */
			  fprintf(dap_err,
				  "(groupparse) invalid number of groups: %s\n",
				  varspec + s);
			  exit(1);
			}
		      switch (varspec[s + i])
			{
			case '^':
			  classtype[nvar] = -n; /* < 0 indicates equal width */
			  break;
			case '#':
			  classtype[nvar] = n; /* > 0 indicates equal count */
			  break;
			default:
			  fprintf(dap_err,
				  "(groupparse) invalid class type: %s\n",
				  varspec + s + i);
			  exit(1);
			}
		      s += i + 1;
		      while (varspec[s] == ' ') /* on to next variable */
			s++;
		      if (n > dap_maxbars)
			{
			  fprintf(dap_err,
				  "(groupparse) too many classes: %d\n", n);
			  exit(1);
			}
		    }
		  else /* guess it wasn't a double... */
		    {
		      fprintf(dap_err,
			      "(groupparse) grouping variable must be of type double: %s\n",
			      varname);
		      exit(1);
		    }
		}
	      else /* guess there wasn't a number... */
		{
		  fprintf(dap_err,
			  "(groupparse) missing number of groups for %s\n",
			  varname);
		  exit(1);
		}
	    }
	  nvar++;
	}
      else if (number < 0)
	{ /* then varname was really a variable name, because we already found
	   * a #, /, or % at the beginning of varspec
	   */
	  if (varname[0] == '-') /* descending */
	    classtype[0] |= GRPDESC;
	  if (varname[1] == '0') /* lowest group is numbered 0 */
	    classtype[0] |= GRP0;
	}
      else if (!nvar)
	{ /* at the beginning of varspec: want count, fraction, or percent? */
	  if (!strcmp(varname, "#"))
	    number = GRPNUMBER;
	  else if (!strcmp(varname, "/"))
	    number = GRPFRACTION;
	  else if (!strcmp(varname, "%"))
	    number = GRPPERCENT;
	  classtype[0] = 0;
	  nvar++;
	}
      else /* OK, look: we're not at the beginning and it's not a variable. What gives? */
	{
	  fprintf(dap_err, "(groupparse) unknown variable: %s\n", varname);
	  exit(1);
	}
      while (varspec[s] == ' ') /* on to next */
	s++;
    }
  dap_free(varname, "");
  if (number < 0) /* if were just finding count, fraction, or percent */
    return -4 * nvar + number;
  return nvar;
}

/* get the grouping points for each variable */
static void getpoints(double **numval, int nonum,
		      int *ctype, int nobs, double **point)
{
  int v;
  double width;
  int p;
  int index;
  double excess;

  for (v = 0; v < nonum; v++)
    {
      qsort((void *) numval[v], (size_t) nobs, /* sort values for each variable separately */
	    (size_t) sizeof(double), cmp);
      if (ctype[v] < 0)
	{
	  width = (numval[v][nobs - 1] - numval[v][0]) /
	    ((double) -ctype[v]);
	  for (p = 0; p < -ctype[v]; p++)
	    point[v][p] = numval[v][0] +
	      ((double) p) * width;
	  point[v][p] = numval[v][nobs - 1];
	}
      else if (ctype[v] > 0)
	{
	  for (p = 0; p < ctype[v]; p++)
	    {
	      index = (int) floor(((double) (p * nobs)) /
				  ((double) ctype[v]));
	      excess = ((double) (p * nobs)) / ((double) ctype[v]) -
		(double) index;
	      if (excess > 0.0 && index < nobs - 1)
		point[v][p] = 0.5 *
		  (numval[v][index] + numval[v][index + 1]);
	      else
		point[v][p] =
		  numval[v][(int) rint(((double) (p * nobs)) /
				       ((double) ctype[v]))];
	    }
	  point[v][p] = numval[v][nobs - 1];
	}
    }
}

void group(char *fname, char *varspec, char *marks)
{
  char *outname;
  int *markv; /* vector of ids of partitioning variables */
  int nmark; /* and number of those */
  int *varv; /* vector of ids of variables */
  int *ctype; /* grouping type; see groupparse above for details */
  double *nummem;
  double **numval;
  int nvar;
  int number;
  int v;
  char *grpname; /* to hold name of group variables */
  int *grpv; /* vector of ids of grouping variables */
  int nobs;
  int nnan;
  int allgood;		/* all vars selected are finite */
  double *ptmem;
  double **point;
  double dnobs;
  double count;
  double countinc;
  int p;
  int more; /* to see if another dataset line was read */

  if (!fname)
    {
      fputs("(group) No dataset name given.\n", dap_err);
      exit(1);
    }
  outname = dap_malloc(strlen(fname) + 5, "");
  dap_suffix(outname, fname, ".grp");
  grpname = dap_malloc(dap_namelen + 3, ""); /* +3 for two '_' and null */
  markv = (int *) dap_malloc(sizeof(int) * dap_maxvar, "");
  varv = (int *) dap_malloc(sizeof(int) * dap_maxvar, "");
  ctype = (int *) dap_malloc(sizeof(int) * dap_maxvar, "");
  inset(fname);
  nmark = dap_list(marks, markv, dap_maxvar);
  /* construct vector of variable ids (varv) and grouping types (ctype) */
  nvar = groupparse(varspec, varv, ctype);
  if (nvar < 0) /* means we're simply getting count, fraction, or percent */
    {
      number = -((-nvar) % 4); /* recover codes for descending or not, start from 0 or not */
      nvar = -(nvar - number) / 4; /* and get true number of variables */
    }
  else
    number = 0; /* indicates true grouping */
  grpv = (int *) dap_malloc(sizeof(int) * (number ? 1 : nvar), "");
  if (!number) /* true grouping requires: */
    {
      strcpy(grpname, "_"); /* variable names for group variables */
      for (v = 0; v < nvar; v++)
	{
	  strcpy(grpname + 1, dap_obs[0].do_nam[varv[v]]);
	  grpname[dap_namelen] = '\0';
	  strcat(grpname, " -1");
	  grpv[v] = dap_vd(grpname, 0);
	}
    }
  else /* counting, etc., simply requires one new variable */
    {
      grpv[0] = dap_vd("_N_ -1", 0);
      varv[0] = grpv[0];
    }
  outset(outname, "");
  nummem = NULL;
  numval = NULL;
  if (!number) /* if true grouping, need some memory to sort and manipulate the numbers */
    {
      nummem = (double *) dap_malloc(sizeof(double) * nvar * dap_maxval, "dap_maxval");
      numval = (double **) dap_malloc(nvar * dap_maxval * sizeof(double *), "dap_maxval");
      ptmem = (double *) dap_malloc(sizeof(double) * nvar * (dap_maxbars + 1), "dap_maxbars");
      point = (double **) dap_malloc(sizeof(double *) * nvar, "");
      for (v = 0; v < nvar; v++) /* set up pointers for array referencing */
	{
	  numval[v] = nummem + v * dap_maxval;
	  point[v] = ptmem + v * (dap_maxbars + 1);
	}
    }
  for (dap_mark(), nobs = 0, nnan = 0, more = 1; more; )
    {
      more = step();
      if (dap_newpart(markv, nmark)) /* reached a new part of dataset, time to do stuff */
	{
	  if (!number) /* if true grouping, need... */
	    getpoints(numval, nvar, ctype, nobs, point); /* to get grouping points */
	  dnobs = (double) nobs;
	  dap_rewind(); /* have to pass through this part again */
	  count = 1.0;
	  countinc = 1.0;
	  if (nnan > 0)
	    fprintf(dap_log, "(group) %d NaNs\n", nnan);
	  if (number)
	    {
	      if (ctype[0] & GRP0)
		count = 0.0;
	      if (ctype[0] & GRPDESC)
		{
		  countinc = -1.0;
		  count = dnobs - 1.0 + count;
		}
	    }
	  for ( ; step() && !dap_newpart(markv, nmark); )
	    {
	      if (number)
		{
		  for (v = 1, allgood = 1; v < nvar; v++)
		    {
		      if (!isfinite(dap_obs[0].do_dbl[varv[v]]))
			{
			  allgood = 0;
			  break;
			}
		    }
		  if (allgood)
		    {
		      switch (number)
			{
			case GRPNUMBER:
			  dap_obs[0].do_dbl[grpv[0]] = count;
			  break;
			case GRPFRACTION:
			  dap_obs[0].do_dbl[grpv[0]] = count / dnobs;
			  break;
			case GRPPERCENT:
			  dap_obs[0].do_dbl[grpv[0]] = 100.0 * count / dnobs;
			  break;
			}
		      count += countinc;
		    }
		  else
		    dap_obs[0].do_dbl[grpv[0]] = 0.0 / 0.0;
		}
	      else
		{
		  for (v = 0, allgood = 1; v < nvar; v++)
		    {
		      if (!isfinite(dap_obs[0].do_dbl[varv[v]]))
			{
			  allgood = 0;
			  break;
			}
		    }
		  if (allgood)
		    {
		      for (v = 0; v < nvar; v++)
			{
			  for (p = 1;
			       dap_obs[0].do_dbl[varv[v]] >
				 point[v][p]; p++)
			    ;
			  dap_obs[0].do_dbl[grpv[v]] = (double) p;
			}
		    }
		  else
		    for (v = 0; v < nvar; v++)
		      dap_obs[0].do_dbl[grpv[v]] = 0.0 / 0.0;
		}
	      output();
	      dap_mark();
	    }
	  nobs = 0;
	  nnan = 0;
	}
      if (number)
	{
	  for (v = 1, allgood = 1; v < nvar; v++)
	    {
	      if (!isfinite(dap_obs[0].do_dbl[varv[v]]))
		{
		  allgood = 0;
		  break;
		}
	    }
	  if (allgood)
	    nobs++;
	  else
	    nnan++;
	}
      else
	{
	  if (nobs < dap_maxval)
	    {
	      for (v = 0, allgood = 1; v < nvar; v++)
		{
		  if (!isfinite(dap_obs[0].do_dbl[varv[v]]))
		    {
		      allgood = 0;
		      break;
		    }
		  numval[v][nobs] = dap_obs[0].do_dbl[varv[v]];
		}
	      if (allgood)
		nobs++;
	      else
		nnan++;
	    }
	  else
	    {
	      fputs("(group) too many data.\n", dap_err);
	      exit(1);
	    }
	}
    }
  if (!number)
    {
      dap_free(nummem, "");
      dap_free(numval, "");
      dap_free(ptmem, "");
      dap_free(point, "");
    }
  dap_free(outname, "");
  dap_free(grpname, "");
  dap_free(grpv, "");
  dap_free(markv, "");
  dap_free(varv, "");
  dap_free(ctype, "");
}

#define NFREQSTAT 13
#define FREQCNT 0
#define FREQPCT 1
#define FREQFRA 2
#define FREQEXP 3
#define FREQCHISQ 4
#define FREQODDRAT 5
#define FREQORD 6
#define FREQFISHER 7
#define FREQCMH 8
#define FREQROW 9
#define FREQCOL 10
#define FREQPAIR 11
#define FREQNOM 12

static void freq1(int *varv, int nvar, double count, double sumcount, int *statv,
		  int typen, int celln)
{
  dap_swap();
  if (statv[FREQCNT])
    {
      strcpy(dap_obs[0].do_str[typen], "COUNT");
      dap_obs[0].do_dbl[celln] = count;
      output();
    }
  if (statv[FREQPCT])
    {
      strcpy(dap_obs[0].do_str[typen], "PERCENT");
      dap_obs[0].do_dbl[celln] = 100.0 * count / sumcount;
      output();
    }
  if (statv[FREQFRA])
    {
      strcpy(dap_obs[0].do_str[typen], "FRACTION");
      dap_obs[0].do_dbl[celln] = count / sumcount;
      output();
    }
  dap_swap();
}

static void statparse(char *stats, int *statv)
{
  int s;
  int i;
  char *stat;

  stat = dap_malloc(dap_namelen + 1, "");
  for (s = 0; s < NFREQSTAT; s++)
    statv[s] = 0;
  for (s = 0; stats[s] == ' '; s++)
    ;
  while (stats[s])
    {
      for (i = 0; stats[s + i] && stats[s + i] != ' '; i++)
	{
	  if (i < dap_namelen)
	    stat[i] = stats[s + i];
	  else
	    {
	      stat[i] = '\0';
	      fprintf(dap_err, "(statparse) Statistic name too long: %s\n", stat);
	      exit(1);
	    }
	}
      stat[i] = '\0';
      s += i;
      if (!strcmp(stat, "COUNT"))
	statv[FREQCNT] = 1;
      else if (!strcmp(stat, "PERCENT"))
	statv[FREQPCT] = 1;
      else if (!strcmp(stat, "ROWPERC"))
	statv[FREQROW] = 1;
      else if (!strcmp(stat, "COLPERC"))
	statv[FREQCOL] = 1;
      else if (!strcmp(stat, "FRACTION"))
	statv[FREQFRA] = 1;
      else if (!strcmp(stat, "EXPECTED"))
	statv[FREQEXP] = 1;
      else if (!strcmp(stat, "CHISQ"))
	statv[FREQCHISQ] = 1;
      else if (!strcmp(stat, "ODDSRAT"))
	statv[FREQODDRAT] = 1;
      else if (!strcmp(stat, "ORDINAL"))
	statv[FREQORD] = 1;
      else if (!strcmp(stat, "FISHER"))
	statv[FREQFISHER] = 1;
      else if (!strcmp(stat, "CMH"))
	statv[FREQCMH] = 1;
      else if (!strcmp(stat, "PAIR"))
	statv[FREQPAIR] = 1;
      else if (!strcmp(stat, "NOMINAL"))
	statv[FREQNOM] = 1;
      else
	{
	  fprintf(dap_err, "(statparse) Invalid statistic name: %s\n", stat);
	  exit(1);
	}
      while (stats[s] == ' ')
	s++;
    }
  dap_free(stat, "");
}

static int findlev(int v, char **level, int *nlevels)
{
  int l;
  static char *str = NULL;
  char *s;

  if (!str)
    str = dap_malloc(21, "");
  if (dap_obs[0].do_len[v] > 0)
    s = dap_obs[0].do_str[v];
  else
    {
      s = str;
      if (dap_obs[0].do_len[v] == INT)
	sprintf(str, "%d", dap_obs[0].do_int[v]);
      else
	sprintf(str, "%g", dap_obs[0].do_dbl[v]);
    }
  for (l = 0; l < *nlevels; l++)
    {
      if (!strcmp(s, level[l]))
	return l;
    }
  if (*nlevels < dap_maxlev)
    {
      strcpy(level[l], s);
      (*nlevels)++;
      return l;
    }
  else
    {
      fprintf(dap_err, "(findlev) Too many levels at: %s\n", s);
      exit(1);
    }
}

static void tabentry(int *varv, double **tab,
		     char **level[2], int nlevels[2], double count)
{
  dap_swap();
  tab[findlev(varv[0], level[0], nlevels)][findlev(varv[1], level[1], nlevels + 1)] = count;
  dap_swap();
}

static void valcpy(int v, char *val)
{
  if (dap_obs[0].do_len[v] > 0)
    strcpy(dap_obs[0].do_str[v], val);
  else if (dap_obs[0].do_len[v] == INT)
    dap_obs[0].do_int[v] = atoi(val);
  else
    dap_obs[0].do_dbl[v] = atof(val);
}

static void freq2(double **tab, char **level[2],
		  int nlevels[2], int *statv, int *markv, int nmark, int *varv,
		  int typen, int celln)
{
  int v;
  int l;
  double *expmem;
  double **expect;
  double *rowsum;
  double *colsum;
  double sum;
  double *amem;
  double **a;
  double *dmem;
  double **d;
  double p, q;
  double tmp1, tmp2, tmp3, tmp4;
  double w;
  double t;
  double var;
  int r, c;
  double diff;
  double chisq;
  int rr, cc;
  double upleft, dnleft;
  double denom, prob, oneprob, othprob;
  double hx, hy, hxy;
  double uv;

  sum = 0.0;
  oneprob = 0.0;
  expmem = (double *) dap_malloc(sizeof(double) * dap_maxlev * dap_maxlev, "");
  expect = (double **) dap_malloc(sizeof(double *) * dap_maxlev, "");
  for (l = 0; l < dap_maxlev; l++)
    expect[l] = expmem + l * dap_maxlev;
  rowsum = (double *) dap_malloc(sizeof(double) * dap_maxlev, "");
  colsum = (double *) dap_malloc(sizeof(double) * dap_maxlev, "");
  amem = (double *) dap_malloc(sizeof(double) * dap_maxlev * dap_maxlev, "");
  dmem = (double *) dap_malloc(sizeof(double) * dap_maxlev * dap_maxlev, "");
  a = (double **) dap_malloc(sizeof(double *) * dap_maxlev, "");
  d = (double **) dap_malloc(sizeof(double *) * dap_maxlev, "");
  for (l = 0; l < dap_maxlev; l++)
    {
      a[l] = amem + l * dap_maxlev;
      d[l] = dmem + l * dap_maxlev;
    }
  dap_swap();
  if (statv[FREQCHISQ] || statv[FREQODDRAT] || statv[FREQORD] ||
      statv[FREQFISHER] || statv[FREQPAIR] || statv[FREQNOM])
    {
      dap_head(markv, nmark);
      fputs("Variable: Levels\n", dap_lst);
      fputs("----------------\n", dap_lst);
      for (v = 0; v < 2; v++)
	{
	  fprintf(dap_lst, "%s:", dap_obs[0].do_nam[varv[v]]);
	  for (l = 0; l < nlevels[v]; l++)
	    fprintf(dap_lst, " %s", level[v][l]);
	  putc('\n', dap_lst);
	}
      putc('\n', dap_lst);
    }
  if (statv[FREQEXP] || statv[FREQCHISQ] || statv[FREQORD] || statv[FREQFISHER] ||
      statv[FREQROW] || statv[FREQCOL] || statv[FREQPAIR] || statv[FREQNOM])
    {
      for (r = 0, sum = 0.0; r < nlevels[0]; r++)
	{
	  rowsum[r] = 0.0;
	  for (c = 0; c < nlevels[1]; c++)
	    rowsum[r] += tab[r][c];
	  sum += rowsum[r];
	}
      for (c = 0; c < nlevels[1]; c++)
	{
	  colsum[c] = 0.0;
	  for (r = 0; r < nlevels[0]; r++)
	    colsum[c] += tab[r][c];
	}
      for (r = 0; r < nlevels[0]; r++)
	for (c = 0; c < nlevels[1]; c++)
	  expect[r][c] = rowsum[r] * colsum[c] / sum;
    }
  if (statv[FREQEXP])
    {
      strcpy(dap_obs[0].do_str[typen], "EXPECTED");
      for (r = 0; r < nlevels[0]; r++)
	{
	  valcpy(varv[0], level[0][r]);
	  for (c = 0; c < nlevels[1]; c++)
	    {
	      valcpy(varv[1], level[1][c]);
	      dap_obs[0].do_dbl[celln] = expect[r][c];
	      output();
	    }
	}
    }
  if (statv[FREQROW])
    {
      strcpy(dap_obs[0].do_str[typen], "ROWPERC");
      for (r = 0; r < nlevels[0]; r++)
	{
	  valcpy(varv[0], level[0][r]);
	  for (c = 0; c < nlevels[1]; c++)
	    {
	      valcpy(varv[1], level[1][c]);
	      dap_obs[0].do_dbl[celln] = 100.0 * tab[r][c] / rowsum[r];
	      output();
	    }
	}
    }
  if (statv[FREQCOL])
    {
      strcpy(dap_obs[0].do_str[typen], "COLPERC");
      for (r = 0; r < nlevels[0]; r++)
	{
	  valcpy(varv[0], level[0][r]);
	  for (c = 0; c < nlevels[1]; c++)
	    {
	      valcpy(varv[1], level[1][c]);
	      dap_obs[0].do_dbl[celln] = 100.0 * tab[r][c] / colsum[c];
	      output();
	    }
	}
    }
  if (statv[FREQCHISQ])
    {
      for (r = 0, chisq = 0.0; r < nlevels[0]; r++)
	for (c = 0; c < nlevels[1]; c++)
	  {
	    diff = tab[r][c] - expect[r][c];
	    chisq += diff * diff / expect[r][c];
	  }
      fprintf(dap_lst, "Chisq0[%d] = %g, Prob[Chisq > Chisq0] = %.5f\n",
	      (nlevels[0] - 1) * (nlevels[1] - 1), chisq,
	      ceil(100000.0 *
		   probchisq(chisq, (nlevels[0] - 1) * (nlevels[1] - 1))) /
	      100000.0);
    }
  if (statv[FREQODDRAT])
    {
      if (nlevels[0] == 2 && nlevels[1] == 2)
	{
	  tmp1 = (tab[0][0] + 0.5) * (tab[1][1] + 0.5) /
	    ((tab[0][1] + 0.5) * (tab[1][0] + 0.5));
	  fprintf(dap_lst,
		  "Odds ratio = %g\nlog(Odds ratio) = %g, ASE = %g\n",
		  tmp1, log(tmp1),
		  sqrt(1.0 / (tab[0][0] + 0.5) + 1.0 / (tab[1][0] + 0.5) +
		       1.0 / (tab[0][1] + 0.5) + 1.0 / (tab[1][1] + 0.5)));
	}
      else
	fputs("(freq2) Odds ratio computed for 2 x 2 tables only.\n", dap_log);
    }
  if (statv[FREQFISHER])
    {
      if (nlevels[0] == 2 && nlevels[1] == 2) /* only do for 2x2 tables */
	{
	  if (tab[0][0] >= expect[0][0]) /* right-tail test: assoc stronger than expected */
	    {
	      denom = dap_bincoeff(sum, colsum[0]); /* number of tables given column sums */
	      for (upleft = tab[0][0], dnleft = tab[1][0], prob = 0.0;
		   upleft <= rowsum[0] && upleft <= colsum[0];
		   upleft += 1.0, dnleft -= 1.0)
		{
		  if (prob == 0.0)
		    {
		      oneprob = dap_bincoeff(rowsum[0], upleft) *
			dap_bincoeff(rowsum[1], dnleft);
		      prob = oneprob;
		    }
		  else
		    prob += dap_bincoeff(rowsum[0], upleft) *
		      dap_bincoeff(rowsum[1], dnleft);
		}
	      fprintf(dap_lst, "Fisher's exact test: right     %g\n",
		      prob / denom);
	      for (upleft = ceil(expect[1][0]), dnleft = colsum[0] - upleft;
		   upleft <= rowsum[1] && upleft <= colsum[0];
		   upleft += 1.0, dnleft -= 1.0)
		{
		  othprob = dap_bincoeff(rowsum[1], upleft) *
		    dap_bincoeff(rowsum[0], dnleft);
		  if (othprob <= oneprob)
		    prob += othprob;
		}
	      if (tab[0][0] == expect[0][0])
		/* this is a kluge for tables satisfying independence */
		prob = 1.0;
	      fprintf(dap_lst, "                     2-tailed  %g\n",
		      prob / denom);
	    }
	  if (tab[0][0] <= expect[0][0])
	    {
	      denom = dap_bincoeff(sum, colsum[1]);
	      for (upleft = tab[1][0], dnleft = tab[0][0], prob = 0.0;
		   upleft <= rowsum[1] && upleft <= colsum[0];
		   upleft += 1.0, dnleft -= 1.0)
		{
		  if (prob == 0.0)
		    {
		      oneprob = dap_bincoeff(rowsum[1], upleft) *
			dap_bincoeff(rowsum[0], dnleft);
		      prob = oneprob;
		    }
		  else
		    prob += dap_bincoeff(rowsum[1], upleft) *
		      dap_bincoeff(rowsum[0], dnleft);
		}
	      fprintf(dap_lst, "Fisher's exact test: left      %g\n",
		      prob / denom);
	      for (upleft = ceil(expect[0][0]), dnleft = colsum[0] - upleft;
		   upleft <= rowsum[0] && upleft <= colsum[0];
		   upleft += 1.0, dnleft -= 1.0)
		{
		  othprob = dap_bincoeff(rowsum[0], upleft) *
		    dap_bincoeff(rowsum[1], dnleft);
		  if (othprob <= oneprob)
		    prob += othprob;
		}
	      if (tab[0][0] == expect[0][0])
		/* this is a kluge for tables satisfying independence */
		prob = 1.0;
	      fprintf(dap_lst, "                     2-tailed  %g\n",
		      prob / denom);
	    }
	}
      else
	fputs("(freq2) Fisher's exact test computed for 2 x 2 tables only.\n", dap_log);
    }
  if (statv[FREQORD])
    {
      for (r = 0; r < nlevels[0]; r++)
	for (c = 0; c < nlevels[1]; c++)
	  {
	    a[r][c] = 0.0;
	    d[r][c] = 0.0;
	    for (rr = 0; rr < nlevels[0]; rr++)
	      for (cc = 0; cc < nlevels[1]; cc++)
		{
		  if ((rr < r && cc < c) || (rr > r && cc > c))
		    a[r][c] += tab[rr][cc];
		  else if ((rr < r && cc > c) || (rr > r && cc < c))
		    d[r][c] += tab[rr][cc];
		}
	  }
      for (r = 0, p = 0.0, q = 0.0; r < nlevels[0]; r++)
	for (c = 0; c < nlevels[1]; c++)
	  {
	    p += tab[r][c] * a[r][c];
	    q += tab[r][c] * d[r][c];
	  }
      fprintf(dap_lst, "Statistic          Value   ASE\n");
      for (r = 0, var = 0.0; r < nlevels[0]; r++)
	for (c = 0; c < nlevels[1]; c++)
	  {
	    tmp1 = q * a[r][c] - p * d[r][c];
	    var += tab[r][c] * tmp1 * tmp1;
	  }
      tmp2 = p + q;
      tmp2 *= tmp2;
      tmp2 *= tmp2;
      var *= 16.0 / tmp2;
      fprintf(dap_lst, "Gamma             %6.3f  %5.3f\n",
	      (p - q) / (p + q), sqrt(var));
      for (r = 0, tmp1 = sum * sum; r < nlevels[0]; r++)
	tmp1 -= rowsum[r] * rowsum[r];
      for (c = 0, tmp2 = sum * sum; c < nlevels[1]; c++)
	tmp2 -= colsum[c] * colsum[c];
      w = sqrt(tmp1 * tmp2);
      t = (p - q) / w;
      for (r = 0, var = 0.0; r < nlevels[0]; r++)
	for (c = 0; c < nlevels[1]; c++)
	  {
	    tmp3 = 2.0 * w * (a[r][c] - d[r][c]) +
	      t * (rowsum[r] * tmp2 + colsum[c] * tmp1);
	    var += tab[r][c] * tmp3 * tmp3;
	  }
      tmp4 = tmp1 + tmp2;
      var = (var - sum * sum * sum * t * t * tmp4 * tmp4) / (w * w * w * w);
      fprintf(dap_lst, "Kendall's Tau-b   %6.3f  %5.3f\n", t, sqrt(var));
      for (r = 0, var = 0.0; r < nlevels[0]; r++)
	for (c = 0; c < nlevels[1]; c++)
	  {
	    tmp3 = tmp1 * (a[r][c] - d[r][c]) - (p - q) * (sum - rowsum[r]);
	    var += tab[r][c] * tmp3 * tmp3;
	  }
      var *= 4.0 / (tmp1 * tmp1 * tmp1 * tmp1);
      fprintf(dap_lst, "Somers' D C|R     %6.3f  %5.3f\n", (p - q) / tmp1, sqrt(var));
      for (r = 0, var = 0.0; r < nlevels[0]; r++)
	for (c = 0; c < nlevels[1]; c++)
	  {
	    tmp3 = tmp2 * (a[r][c] - d[r][c]) - (p - q) * (sum - colsum[c]);
	    var += tab[r][c] * tmp3 * tmp3;
	  }
      var *= 4.0 / (tmp2 * tmp2 * tmp2 * tmp2);
      fprintf(dap_lst, "Somers' D R|C     %6.3f  %5.3f\n", (p - q) / tmp2, sqrt(var));
    }
  if (statv[FREQPAIR])
    {
      if (nlevels[0] != nlevels[1])
	{
	  fprintf(dap_err, "(freq2) PAIR requires square table, table is %d x %d.\n",
		  nlevels[0], nlevels[1]);
	  exit(1);
	}
      for (r = 0, p = 0.0, q = 0.0, tmp1 = 0.0, tmp2 = 0.0; r < nlevels[0]; r++)
	{
	  p += tab[r][r];			/* Po */
	  q += expect[r][r];		/* Pe */
	  tmp1 += tab[r][r] * (rowsum[r] + colsum[r]);
	  for (c = 0; c < nlevels[0]; c++)
	    {
	      tmp3 = (rowsum[c] + colsum[r]);
	      tmp2 += tab[r][c] * tmp3 * tmp3;
	    }
	}
      p /= sum;
      q /= sum;
      tmp1 /= sum * sum;
      tmp2 /= sum * sum * sum;
      tmp3 = 1.0 - p;
      tmp4 = 1.0 - q;
      fprintf(dap_lst, "Statistic          Value   ASE\n");
      fprintf(dap_lst, "Kappa             %6.3f  %5.3f\n",
	      (p - q) / tmp4,
	      sqrt((p * tmp3 / (tmp4 * tmp4) +
		    2.0 * tmp3 * (2.0 * p * q - tmp1) / (tmp4 * tmp4 * tmp4) +
		    tmp3 * tmp3 * (tmp2 - 4.0 * q * q) / (tmp4 * tmp4 * tmp4 * tmp4)) /
		   sum));
    }
  if (statv[FREQNOM])
    {
      for (hx = 0.0, r = 0; r < nlevels[0]; r++)
	hx -= rowsum[r] * log(rowsum[r] / sum);
      hx /= sum;
      for (hy = 0.0, c = 0; c < nlevels[1]; c++)
	hy -= colsum[c] * log(colsum[c] / sum);
      hy /= sum;
      for (hxy = 0.0, r = 0; r < nlevels[0]; r++)
	for (c = 0; c < nlevels[1]; c++)
	  hxy -= tab[r][c] * log(tab[r][c] / sum);
      hxy /= sum;
      uv = hx + hy - hxy;
      fprintf(dap_lst, "Statistic              Value   ASE\n");
      for (var = 0.0, r = 0; r < nlevels[0]; r++)
	for (c = 0; c < nlevels[1]; c++)
	  {
	    tmp1 = hy * log(tab[r][c] / rowsum[r]) +
	      (hx - hxy) * log(colsum[c] / sum);
	    var += tab[r][c] * tmp1 * tmp1;
	  }
      var = sqrt(var) / (sum * hy * hy);
      fprintf(dap_lst, "Uncertainty C|R       %6.3f  %5.3f\n",
	      uv / hy, var);
      for (var = 0.0, r = 0; r < nlevels[0]; r++)
	for (c = 0; c < nlevels[1]; c++)
	  {
	    tmp1 = hx * log(tab[r][c] / colsum[c]) +
	      (hy - hxy) * log(rowsum[r] / sum);
	    var += tab[r][c] * tmp1 * tmp1;
	  }
      var = sqrt(var) / (sum * hx * hx);
      fprintf(dap_lst, "Uncertainty R|C       %6.3f  %5.3f\n",
	      uv / hx, var);
      for (var = 0.0, r = 0; r < nlevels[0]; r++)
	for (c = 0; c < nlevels[1]; c++)
	  {
	    tmp1 = hxy * log(rowsum[r] * colsum[c] / (sum * sum)) -
	      (hx + hy) * log(tab[r][c] / sum);
	    var += tab[r][c] * tmp1 * tmp1;
	  }
      tmp2 = hx + hy;
      var = 2.0 * sqrt(var) / (sum * tmp2 * tmp2);
      fprintf(dap_lst, "Uncertainty Symmetric %6.3f  %5.3f\n",
	      2.0 * uv / (hx + hy), var);
    }
  dap_swap();
  dap_free(expmem, "");
  dap_free(expect, "");
  dap_free(rowsum, "");
  dap_free(colsum, "");
  dap_free(amem, "");
  dap_free(a, "");
  dap_free(dmem, "");
  dap_free(d, "");
}

static int freqparse(char *varlist, int *varv, int *wt)
{
  int nvars;
  int m;
  int i;
  char *mname;
  int wtvar;

  wt[0] = -1;
  if (!varlist)
    return 0;
  mname = dap_malloc(dap_namelen + 1, "");
  for (m = 0; varlist[m] == ' '; m++)
    ;
  for (nvars = 0, wtvar = 0; varlist[m]; )
    {
      if (varlist[m] == '*')
	{
	  if (wtvar)
	    {
	      fprintf(dap_err,
		      "(freqparse) Only one weight variable allowed: %s\n",
		      varlist);
	      exit(1);
	    }
	  wtvar = 1;
	  for (m++; varlist[m] == ' '; m++)
	    ;
	}
      for (i = 0; varlist[m + i] && varlist[m + i] != ' ' && varlist[m + i] != '*'; i++)
	{
	  if (i < dap_namelen)
	    mname[i] = varlist[m + i];
	  else
	    {
	      mname[i] = '\0';
	      fprintf(dap_err, "(dap_list) Variable name too long: %s\n",
		      mname);
	      exit(1);
	    }
	}
      mname[i] = '\0';
      if (wtvar)
	{
	  if ((wt[0] = dap_varnum(mname)) < 0)
	    {
	      fprintf(dap_err, "(dap_list) Weight variable unknown: %s\n", mname);
	      exit(1);
	    }
	}
      else if ((varv[nvars++] = dap_varnum(mname)) < 0)
	{
	  fprintf(dap_err, "(dap_list) Variable unknown: %s\n", mname);
	  exit(1);
	}
      m += i;
      while (varlist[m] == ' ')
	m++;
    }
  dap_free(mname, "");
  return nvars;
}

static void cmh1(double **tab, double *cmh, double *cmhvar)
{
  double rowsum[2];
  double colsum[2];
  double tabsum;

  rowsum[0] = tab[0][0] + tab[0][1];
  rowsum[1] = tab[1][0] + tab[1][1];
  colsum[0] = tab[0][0] + tab[1][0];
  colsum[1] = tab[0][1] + tab[1][1];
  tabsum = rowsum[0] + rowsum[1];
  *cmh += tab[0][0] -
    rowsum[0] * colsum[0] / tabsum;
  *cmhvar += rowsum[0] * rowsum[1] * colsum[0] * colsum[1] /
    (tabsum * tabsum * (tabsum - 1.0));
}

static void printcmh(double cmh, double cmhvar,
		     int *varv, int nvar, int *markv, int nmark)
{
  int v;

  dap_swap();
  dap_head(markv, nmark);
  cmh = fabs(cmh) - 0.5;
  cmh *= cmh / cmhvar;
  fprintf(dap_lst,
	  "Cochran-Mantel-Haenszel test for %s x %s, stratified by",
	  dap_obs[0].do_nam[varv[1]], dap_obs[0].do_nam[varv[2]]); 
  for (v = 0; v < nvar - 2; v++)
    fprintf(dap_lst, " %s", dap_obs[0].do_nam[varv[v]]);
  putc('\n', dap_lst);
  fprintf(dap_lst, "M0-squared = %g, Prob[M-squared > M0-squared] = %g\n",
	  cmh, rint(10000.0 * probchisq(cmh, 1)) / 10000.0);
  dap_swap();
}

void freq(char *fname, char *varlist, char *stats, char *marks)
{
  char *outname;
  int statv[NFREQSTAT];
  int typen;
  int celln;
  int *markv;
  int nmark;
  int *varv;
  int nvar;
  int v;
  int wt;
  char *outlist;
  double count;
  double sumcount;
  double *tabmem;
  double **tab;
  char *levmem;
  char **level[2];
  int nlevels[2];
  int l1, l2;
  double cmh, cmhvar;
  int more, moremore;
  int (*strc)();

  strc = &strcmp;
  if (!fname)
    {
      fputs("(freq) No dataset name given.\n", dap_err);
      exit(1);
    }
  outname = dap_malloc(strlen(fname) + 5, "");
  dap_suffix(outname, fname, ".frq");
  outlist = dap_malloc(dap_listlen + 1, "");
  markv = (int *) dap_malloc(sizeof(int) * dap_maxvar, "");
  varv = (int *) dap_malloc(sizeof(int) * dap_maxvar, "");
  tabmem = (double *) dap_malloc(sizeof(double) * dap_maxlev * dap_maxlev, "");
  tab = (double **) dap_malloc(sizeof(double *) * dap_maxlev, "");
  for (l1 = 0; l1 < dap_maxlev; l1++)
    tab[l1] = tabmem + l1 * dap_maxlev;
  levmem = dap_malloc(2 * dap_maxlev * (dap_strlen + 1), "");
  level[0] = (char **) dap_malloc(sizeof(char *) * dap_maxlev, "");
  level[1] = (char **) dap_malloc(sizeof(char *) * dap_maxlev, "");
  for (l1 = 0; l1 < dap_maxlev; l1++)
    {
      level[0][l1] = levmem + l1 * (dap_strlen + 1);
      level[1][l1] = level[0][l1] + dap_maxlev * (dap_strlen + 1);
    }
  statparse(stats, statv);
  inset(fname);
  if ((typen = dap_varnum("_type_")) < 0)
    {
      fputs("(freq) Missing _type_ variable.\n", dap_err);
      exit(1);
    }
  nmark = dap_list(marks, markv, dap_maxvar);
  nvar = freqparse(varlist, varv, &wt);
  if (statv[FREQCMH] && nvar < 3)
    {
      fputs(
	    "(freq) Cochran-Mantel-Haenszel test performed only for tables with dimension >= 3.\n",
	    dap_err);
      exit(1);
    }
  celln = dap_vd("_cell_ -1", 0);
  for (v = 0; v < nvar; v++)
    {
      if (!v)
	strcpy(outlist, dap_obs[0].do_nam[varv[v]]);
      else
	{
	  strcat(outlist, " ");
	  strcat(outlist, dap_obs[0].do_nam[varv[v]]);
	}
    }
  strcat(outlist, " _cell_ ");
  strcat(outlist, marks);
  outset(outname, outlist);
  nlevels[0] = 0;
  nlevels[1] = 0;
  for (l1 = 0; l1 < dap_maxlev; l1++)
    for (l2 = 0; l2 < dap_maxlev; l2++)
      tab[l1][l2] = 0.0;
  for (dap_mark(), sumcount = 0.0, more = 1; more; )
    {
      more = step();
      if (dap_newpart(markv, nmark))
	{
	  dap_rewind();
	  if (nvar == 2)
	    {
	      qsort(level[0][0], nlevels[0], dap_strlen + 1, strc);
	      qsort(level[1][0], nlevels[1], dap_strlen + 1, strc);
	    }
	  for (count = 0.0, cmh = 0.0, cmhvar = 0.0, moremore = 1; moremore; )
	    {
	      dap_mark();
	      moremore = (step() && !dap_newpart(markv, nmark));
	      if (dap_newpart(varv, nvar) || dap_newpart(markv, nmark))
		{
		  freq1(varv, nvar, count, sumcount, statv, typen, celln);
		  if (nvar == 2)
		    tabentry(varv, tab, level, nlevels, count); 
		  else if (statv[FREQCMH])
		    {
		      tabentry(varv + nvar - 2, tab, level, nlevels, count); 
		      if (dap_newpart(varv, nvar - 2))
			cmh1(tab, &cmh, &cmhvar);
		    }
		  count = 0.0;
		}
	      if (wt >= 0)
		count += dap_obs[0].do_dbl[wt];
	      else
		count += 1.0;
	    }
	  if (nvar == 2)
	    freq2(tab, level, nlevels, statv, markv, nmark, varv, typen, celln);
	  else if (statv[FREQCMH])
	    printcmh(cmh, cmhvar, varv, nvar, markv, nmark);
	  for (l1 = 0; l1 < dap_maxlev; l1++)
	    for (l2 = 0; l2 < dap_maxlev; l2++)
	      tab[l1][l2] = 0.0;
	  sumcount = 0.0;
	  nlevels[0] = 0;
	  nlevels[1] = 0;
	}
      if (nvar == 2)
	{
	  findlev(varv[0], level[0], nlevels);
	  findlev(varv[1], level[1], nlevels + 1);
	}
      if (wt >= 0)
	sumcount += dap_obs[0].do_dbl[wt];
      else
	sumcount += 1.0;
    }
  dap_free(outname, "");
  dap_free(outlist, "");
  dap_free(markv, "");
  dap_free(varv, "");
  dap_free(tabmem, "");
  dap_free(tab, "");
  dap_free(levmem, "");
  dap_free(level[0], "");
  dap_free(level[1], "");
}

static void trim1(double *vpct, int nvar, double **val,
		  int nobs, double *vmin, double *vmax)
{
  int v;
  int trimcnt;

  for (v = 0; v < nvar; v++)
    {
      trimcnt = (int) rint(vpct[v] / 100.0 * ((double) nobs));
      qsort((void *) val[v], (size_t) nobs, (size_t) sizeof(double), cmp);
      vmin[v] = val[v][trimcnt];
      vmax[v] = val[v][nobs - trimcnt - 1];
    }
}

static int trimparse(char *trimspec, int *varv, double *vpct)
{
  int n;
  int i;
  char *varname;
  int v;
  double div;
  int digits;
  int nvar;

  if (!trimspec)
    return 0;
  varname = dap_malloc(dap_namelen + 1, "");
  for (n = 0; trimspec[n] == ' '; n++)
    ;
  for (nvar = 0; trimspec[n]; )
    {
      for (i = 0; trimspec[n + i] && trimspec[n + i] != ' '; i++)
	{
	  if (i < dap_namelen)
	    varname[i] = trimspec[n + i];
	  else
	    {
	      varname[i] = '\0';
	      fprintf(dap_err, "(trimparse) trim variable name too long: %s\n",
		      varname);
	      exit(1);
	    }
	}
      varname[i] = '\0';
      n += i;
      if ((v = dap_varnum(varname)) >= 0)
	{
	  varv[nvar] = v;
	  while (trimspec[n] == ' ')
	    n++;
	  for (digits = 0, div = 0.0;
	       ('0' <= trimspec[n] && trimspec[n] <= '9') || trimspec[n] == '.';
	       n++)
	    {
	      if (trimspec[n] == '.')
		{
		  if (div >= 1.0)
		    {
		      fprintf(dap_err,
			      "(trimparse) multiple decimal points in percent for %s\n",
			      varname);
		      exit(1);
		    }
		  div = 1.0;
		}
	      else
		{
		  digits = 10 * digits + trimspec[n] - '0';
		  if (div >= 1.0)
		    div *= 10.0;
		}
	    }
	  vpct[nvar] = (double) digits;
	  if (div >= 1.0)
	    vpct[nvar] /= div;
	  if (vpct[nvar] > 0.0)
	    {
	      if (dap_obs[0].do_len[v] == DBL)
		nvar++;
	      else
		{
		  fprintf(dap_err,
			  "(trimparse) trim variable not double: %s\n",
			  varname);
		  exit(1);
		}
	    }
	  else
	    {
	      fprintf(dap_err,
		      "(trimparse) no percent for trim variable: %s\n",
		      varname);
	      exit(1);
	    }
	}
      else
	{
	  fprintf(dap_err, "(trimparse) unknown trim variable: %s\n", varname);
	  exit(1);
	}
      while (trimspec[n] == ' ')
	n++;
    }
  dap_free(varname, "");
  return nvar;
}

void trim(char *fname, char *trimspec, char *marks)
{
  char *outname;
  int *markv;
  int nmark;
  int *varv;
  double *vpct;
  int nvar;
  double *valmem;
  double **val;
  int v;
  int nobs;
  double *vmin;
  double *vmax;
  int more;

  if (!fname)
    {
      fputs("(trim) No dataset name given.\n", dap_err);
      exit(1);
    }
  outname = dap_malloc(strlen(fname) + 5, "");
  dap_suffix(outname, fname, ".trm");
  markv = (int *) dap_malloc(sizeof(int) * dap_maxvar, "");
  varv = (int *) dap_malloc(sizeof(int) * dap_maxvar, "");
  vpct = (double *) dap_malloc(sizeof(double) * dap_maxvar, "");
  vmin = (double *) dap_malloc(sizeof(double) * dap_maxvar, "");
  vmax = (double *) dap_malloc(sizeof(double) * dap_maxvar, "");
  inset(fname);
  nmark = dap_list(marks, markv, dap_maxvar);
  nvar = trimparse(trimspec, varv, vpct);
  outset(outname, "");
  valmem = (double *) dap_malloc(sizeof(double) * nvar * dap_maxval, "");
  val = (double **) dap_malloc(sizeof(double *) * nvar, "");
  for (v = 0; v <= nvar; v++)
    val[v] = valmem + v * dap_maxval;
  for (dap_mark(), nobs = 0, more = 1; more; nobs++)
    {
      more = step();
      if (dap_newpart(markv, nmark))
	{
	  trim1(vpct, nvar, val, nobs, vmin, vmax);
	  dap_rewind();
	  while (step() && !dap_newpart(markv, nmark))
	    {
	      for (v = 0; v < nvar; v++)
		{
		  if (dap_obs[0].do_dbl[varv[v]] < vmin[v] ||
		      dap_obs[0].do_dbl[varv[v]] > vmax[v])
		    break;
		}
	      if (v == nvar)
		output();
	      dap_mark();
	    }
	  nobs = 0;
	}
      if (nobs < dap_maxval)
	{
	  for (v = 0; v < nvar; v++)
	    {
	      if (isfinite(dap_obs[0].do_dbl[varv[v]]))
		val[v][nobs] = dap_obs[0].do_dbl[varv[v]];
	      else
		{
		  fprintf(dap_err,
			  "(trim) NaN value %d for %s\n",
			  nobs, dap_obs[0].do_nam[varv[v]]);
		  exit(1);
		}
	    }
	}
      else
	{
	  fputs("(group) Too many data.\n", dap_err);
	  exit(1);
	}
    }
  dap_free(outname, "");
  dap_free(markv, "");
  dap_free(varv, "");
  dap_free(vpct, "");
  dap_free(valmem, "");
  dap_free(val, "");
  dap_free(vmin, "");
  dap_free(vmax, "");
}
