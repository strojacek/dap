/*  Copyright (C) 2003, 2004, 2005 Free Software Foundation, Inc.
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
#include "sas.h"
#include <stdlib.h>
#include <string.h>

extern char sastmp[TOKENLEN + 1]; /* name of current temp dataset */
extern int saslineno;

void upper(char *str) /* convert string to upper case: for stats */
{
  while (*str)
    {
      if ('a' <= *str && *str <= 'z')
	*str += 'A' - 'a';
      str++;
    }
}

/* Translate call to PRINT. step starts after "proc print" */
void printtrans(char *step, FILE *dapfile)
{
  char filename[TOKENLEN + 1];

  if (!getoption(step, "data", filename, 1))
    strcpy(filename, sastmp);
  fprintf(dapfile, "print(\"%s\", \"", filename);
  /* are there vars? */
  copylist(step, "var", dapfile);
  fputs("\");\n", dapfile);
}

/* Translate call to MEANS. step starts after "proc means" */
void meanstrans(char *step, FILE *dapfile)
{
  int s;
  char setname[TOKENLEN + 1];
  char outname[TOKENLEN + 1];
  int noprint; /* suppress printing? */
  int statsreq; /* other than default stats requested? */
  int vardf; /* specifies denominator in variance computation: use weights? */
  char stat[TOKENLEN + 1]; /* statistics name */

  /* get file name */
  if (!getoption(step, "data", setname, 1))
    strcpy(setname, sastmp);

  fprintf(dapfile, "means(\"%s\", \"", setname);

  /* now get variables and out= */
  copylist(step, "var", dapfile);
  if (findstatement(step, "weight"))
    {
      putc('*', dapfile);
      copylist(step, "weight", dapfile);
    }
  fputs("\", \"", dapfile);

  /* find out which denominator we're to use for variance */
  vardf = 0;
  if (getoption(step, "vardf", stat, 1))
    {
      if (!linecmp(stat, "wdf"))
	vardf = 1;
      else if (linecmp(stat, "df"))
	{
	  fprintf(stderr,
		  "sastrans: before %d: invalid option for vardf in proc means\n",
		  saslineno);
	  exit(1);
	}
    }
  /* now get list of statistics and possibly noprint option */
  for (s = 0, noprint = 0, statsreq = 0; step[s] && step[s] != ';'; s++)
    {
      if (!linecmp(step + s, "noprint"))
	{
	  noprint = 1;
	  s += 7;
	}
      else if (!linecmp(step + s, "data"))
	{ /* skip it */
	  for (s += 7; step[s] && step[s] != '\n'; s++)
	    ;
	}
      else if (!linecmp(step + s, "vardf"))
	{
	  s += 8;
	  if (!linecmp(step + s, "wdf"))
	    s += 3;
	  else /* must be df */
	    s += 2;
	}
      else
	{
	  statsreq = 1;
	  s += linecpy(stat, step + s);
	  upper(stat);
	  if (!linecmp(stat, "STD"))
	    strcpy(stat, "SD");
	  else if (!linecmp(stat, "STDERR"))
	    strcpy(stat, "SEM");
	  if (vardf && (!linecmp(stat, "SD") || !linecmp(stat, "SEM") || !linecmp(stat, "VAR")))
	    strcat(stat, "FREQ");
	  fputs(stat, dapfile);
	  putc(' ', dapfile);
	}
    }
  if (!statsreq)
    {
      if (vardf)
	fputs("N MEAN SDFREQ MIN MAX", dapfile);
      else
	fputs("N MEAN SD MIN MAX", dapfile);
    }
  fputs("\", \"", dapfile);

  /* now do "by" */
  copylist(step, "by", dapfile);
  fputs("\");\n", dapfile);

  if ((s = findstatement(step, "output")))
    {
      if (!getoption(step + s, "out", outname, 1))
	{
	  sprintf(sastmp, "sastmp%02d", ++sastempnum);
	  strcpy(outname, sastmp);
	}
    }
  else
    outname[0] = '\0';

  /* now print unless noprint */
  if (!noprint)
    fprintf(dapfile, "print(\"%s.mns\", \"\");\n", setname);

  if (outname[0])
    {
      fprintf(dapfile, "dataset(\"%s.mns\", \"%s\", \"RENAME\");\n", setname, outname);
      strcpy(sastmp, outname); /* most recently created dataset */
    }
}

/* Translate call to SORT. step starts after "proc sort" */
void sorttrans(char *step, FILE *dapfile)
{
  int s;
  int sin, sout; /* position following data= and out= options */
  char inname[TOKENLEN + 4 + 1]; /* +4 to accomodat .srt */
  char outname[TOKENLEN + 1];
  int optstart; /* index of start of option list */
  int descend; /* any descendings? */

  /* first get file name */
  fputs("sort(\"", dapfile);
  inname[0] = '\0';
  outname[0] = '\0';
  if (!(sin = getoption(step, "data", inname, 1)))
    strcpy(inname, sastmp);
  if (!(sout = getoption(step, "out", outname, 1)))
    strcpy(outname, inname);
  fprintf(dapfile, "%s\", \"", inname);
  optstart = sin; /* hold place for option list */
  if (sout > optstart)
    optstart = sout;

  /* now do "by" */
  descend = 0;
  if ((s = findstatement(step, "by")))
    {
      while (step[s] && step[s] != ';')
	{
	  if (!linecmp(step + s, "descending"))
	    {
	      s += 11;
	      descend = 1;
	    }
	  while (step[s] && step[s] != '\n')
	    {
	      putc(step[s], dapfile);
	      s++;
	    }
	  putc(' ', dapfile);
	  s++;
	}
    }
  else
    {
      fprintf(stderr, "sastrans: before %d: missing by statement in proc sort.\n", saslineno);
      exit(1);
    }
  fputs("\", \"", dapfile);

  /* now do options */
  if (!linecmp(step + optstart, "nodupkey"))
    putc('u', dapfile);
  if (descend)
    {
      s = findstatement(step, "by");
      while (step[s] && step[s] != ';')
	{
	  if (!linecmp(step + s, "descending"))
	    {
	      s += 11;
	      while (step[s] && step[s] != '\n')
		s++;
	      putc('d', dapfile);
	    }
	  else
	    {
	      while (step[s] && step[s] != '\n')
		s++;
	      putc('i', dapfile);
	    }
	  s++;
	}
    }
  fputs("\");\n", dapfile);

  if (!outname[0])
    strcpy(outname, inname);
  strcat(inname, ".srt");
  fprintf(dapfile, "dataset(\"%s\", \"%s\", \"RENAME\");\n", inname, outname);
  strcpy(sastmp, outname); /* most recently created dataset */
}

/* Translate call to DATASETS. step starts after "proc datasets" */
void datasetstrans(char *step, FILE *dapfile)
{
  char oldname[TOKENLEN + 1];
  char newname[TOKENLEN + 1];
  int s; /* index to step */
  int t; /* length of token in step */

  if ((s = findstatement(step, "append")))
    {
      if (getoption(step + s, "base", newname, 1) || getoption(step + s, "out", newname, 1))
	{
	  if (!(getoption(step + s, "data", oldname, 1) ||
		getoption(step + s, "new", oldname, 1)))
	    strcpy(oldname, sastmp);
	  fprintf(dapfile, "dataset(\"%s\", \"%s\", \"APPEND\");\n", oldname, newname);
	}
      else
	{
	  fprintf(stderr,
		  "sastrans: before %d: missing base or out statement in proc datasets.\n",
		  saslineno);
	  exit(1);
	}
    }
  if ((s = findstatement(step, "change")))
    {
      while (step[s] && step[s] != ';')
	{
	  s += linecpy(oldname, step + s) + 1;
	  if (!linecmp(step + s, "="))
	    {
	      s += 2;
	      if ((t = linecpy(newname, step + s)) && linecmp(newname, ";"))
		{
		  fprintf(dapfile, "dataset(\"%s\", \"%s\", \"RENAME\");\n", oldname, newname);
		  s += t + 1;
		}
	      else
		{
		  fprintf(stderr,
			  "sastrans: before %d: missing filename after = in change statement in proc datasets.\n",
			  saslineno);
		  exit(1);
		}
	    }
	  else
	    {
	      fprintf(stderr,
		      "sastrans: before %d: missing = after filename in change statement in proc datasets.\n",
		      saslineno);
	      exit(1);
	    }
	}
    }
  if ((s = findstatement(step, "delete")))
    {
      while (step[s] && step[s] != ';')
	{
	  s += linecpy(oldname, step + s) + 1;
	  fprintf(dapfile, "dataset(\"%s\", \"\", \"REMOVE\");\n", oldname);
	}
    }
}

/* Translate call to FREQ. step starts after "proc freq" */
void freqtrans(char *step, FILE *dapfile)
{
  int s;
  char setname[TOKENLEN + 1];
  char outname[TOKENLEN + 1];
  int tablesstart; /* position of start of variable list in tables statement */
  int optionsstart; /* position of start of table options or 0 if none */
  int nstats; /* number of stats reported */
  char stat[TOKENLEN + 1]; /* stat requested */
  int nofreq; /* has NOFREQ? */
  int nopercent; /* has NOPERCENT? */
  int norow; /* has NOROW? */
  int nocol; /* has NOCOL? */
  int noprint; /* suppress printing? */
  int nvars; /* number of table vars */
  int newvar; /* starting new variable in list */
  int varn; /* number of the variable */

  noprint = 0;

  /* get file name */
  if (!getoption(step, "data", setname, 1))
    strcpy(setname, sastmp);

  fprintf(dapfile, "sort(\"%s\", \"", setname);
  if ((s = findstatement(step, "tables")))
    {
      tablesstart = s;
      copylist(step, "by", dapfile);
      putc(' ', dapfile);
      while (step[s] && step[s] != '/' && step[s] != ';')
	{
	  if (step[s] == '*')
	    {
	      putc(' ', dapfile);
	      s++;
	    }
	  else if (step[s] != '\n')
	    putc(step[s], dapfile);
	  s++;
	}
    }
  else
    {
      fprintf(stderr, "sastrans: before %d: missing tables statement in proc freq.\n",
	      saslineno);
      exit(1);
    }
  fputs("\", \"\");\n", dapfile);

  if (step[s] == '/')
    optionsstart = s + 2;
  else
    optionsstart = 0;

  fprintf(dapfile, "freq(\"%s.srt\", \"", setname);

  /* now copy from tables statement, again */
  for (s = tablesstart, newvar = 1, nvars = 0;
       step[s] && step[s] != '/' && step[s] != ';'; s++)
    {
      if (step[s] == '*')
	{
	  putc(' ', dapfile);
	  s ++;
	  newvar = 1;
	}
      else if (step[s] != '\n')
	{
	  if (newvar)
	    {
	      newvar = 0;
	      nvars++;
	    }
	  putc(step[s], dapfile);
	}
    }
  if (!nvars)
    {
      fprintf(stderr, "sastrans: before %d: no variables in tables statement in proc freq.\n",
	      saslineno);
      exit(1);
    }

  if ((s = findstatement(step, "weight")))
    {
      putc('*', dapfile);
      while (step[s] && step[s] != '\n')
	{
	  putc(step[s], dapfile);
	  s++;
	}
      s++;
      if (step[s] != ';')
	{
	  fprintf(stderr, "sastrans: before %d: only one weight variable allowed in proc freq.\n",
		  saslineno);
	  exit(1);
	}
    }

  fputs("\", \"", dapfile);
 
  outname[0] = '\0';

  nofreq = 0;
  nopercent = 0;
  norow = 0;
  nocol = 0;
  /* now get list of statistics and possibly out option */
  nstats = 4; /* for FREQ, PERCENT, ROWPERC, COLPERC */
  for (s = optionsstart; step[s] && step[s] != ';'; s++)
    {
      if (!linecmp(step + s, "noprint"))
	{
	  noprint = 1;
	  s += 7;
	}
      else if (!linecmp(step + s, "out"))
	{
	  s += 4;
	  if (linecmp(step + s, "="))
	    {
	      fprintf(stderr, "sastrans: before %d: missing = after out option in tables statement in proc freq.\n",
		      saslineno);
	      exit(1);
	    }
	  s += 2;
	  s += linecpy(outname, step + s);
	}
      else
	{
	  s += linecpy(stat, step + s);
	  upper(stat);
	  if (!linecmp(stat, "NOFREQ"))
	    {
	      nofreq = 1;
	      --nstats;
	    }
	  else if (!linecmp(stat, "NOPERCENT"))
	    {
	      nopercent = 1;
	      --nstats;
	    }
	  else if (!linecmp(stat, "NOROW"))
	    {
	      norow = 1;
	      --nstats;
	    }
	  else if (!linecmp(stat, "NOCOL"))
	    {
	      nocol = 1;
	      --nstats;
	    }
	  else
	    {
	      if (!linecmp(stat, "EXPECTED"))
		nstats++;
	      else if (!linecmp(stat, "CHISQ"))
		fputs(" FISHER ", dapfile);
	      else if (!linecmp(stat, "MEASURES"))
		{
		  fputs(" ODDSRAT ", dapfile);
		  strcpy(stat, "ORDINAL");
		}
	      fputs(stat, dapfile);
	    }
	  putc(' ', dapfile);
	}
    }
  if (step[s] != ';')
    {
      fprintf(stderr, "sastrans: before %d: missing ; at end of tables statement in proc freq.\n",
	      saslineno);
      exit(1);
    }
  if (!noprint)
    {
      if (!nofreq)
	fputs(" COUNT", dapfile);
      if (!nopercent)
	fputs(" PERCENT", dapfile);
      if (!norow)
	fputs(" ROWPERC", dapfile);
      if (!nocol)
	fputs(" COLPERC", dapfile);
    }
  fputs("\", \"", dapfile);

  /* now do "by" */
  copylist(step, "by", dapfile);
  fputs("\");\n", dapfile);

  /* now print or table if there's anything to print, unless noprint */
  if (!noprint && nstats > 0)
    {
      if (nvars == 1)
	fprintf(dapfile, "print(\"%s.srt.frq\", \"\");\n", setname);
      else
	{
	  fprintf(dapfile, "sort(\"%s.srt.frq\", \"", setname);
	  copylist(step, "by", dapfile);
	  /* copy up through row variable */
	  for (s = tablesstart, varn = 0; varn < nvars - 1; varn++)
	    {
	      while (step[s] && step[s] != '\n')
		{
		  putc(step[s], dapfile);
		  s++;
		}
	      putc(' ', dapfile);
	      s += 3; /* skip \n and * and \n */
	    }
	  fputs(" _type_ ", dapfile);
	  while (step[s] && step[s] != '\n') /* column variable */
	    {
	      putc(step[s], dapfile);
	      s++;
	    }
	  fputs("\", \"\");\n", dapfile);

	  fprintf(dapfile, "table(\"%s.srt.frq.srt\", \"", setname);
	  for (s = tablesstart, varn = 0; varn < nvars - 2; varn++)
	    {
	      while (step[s] && step[s] != '\n')
		s++;
	      s += 3; /* skip \n and * and \n */
	    }
	  while (step[s] && step[s] != '\n') /* row variable */
	    {
	      putc(step[s], dapfile);
	      s++;
	    }
	  if (nstats > 1)
	    fputs(" _type_", dapfile);
	  fputs("\", \"", dapfile);
	  for (s += 3; step[s] && step[s] != '\n'; s++) /* column variable */
	    putc(step[s], dapfile);
	  fputs(" _cell_\", \"s12\", \"", dapfile);
	  /* now do tables by by and tables variables */
	  copylist(step, "by", dapfile);
	  for (s = tablesstart, varn = 0; varn < nvars - 2; varn++)
	    {
	      while (step[s] && step[s] != '\n')
		{
		  putc(step[s], dapfile);
		  s++;
		}
	      putc(' ', dapfile);
	      s += 3; /* skip \n and * and \n */
	    }
	  fputs("\");\n", dapfile);
	}
    }

  if (outname[0])
    {
      fprintf(dapfile, "dataset(\"%s.srt.frq\", \"%s\", \"RENAME\");\n", setname, outname);
      strcpy(sastmp, outname); /* most recently created dataset */
    }
}

/* Translate call to TABULATE. step starts after "proc tabulate" */
void tabulatetrans(char *step, FILE *dapfile)
{
  int s;
  char setname[TOKENLEN + 1];
  char sortname[TOKENLEN + 4 + 1]; /* +4 to accomodate .srt */
  char format[TOKENLEN + 1]; /* format string */
  int tablestart; /* position following "table" in table statement */

  /* get file name */
  if (!getoption(step, "data", setname, 1))
    strcpy(setname, sastmp);

  strcpy(sortname, setname);
  strcat(sortname, ".srt");

  fprintf(dapfile, "sort(\"%s\", \"", setname);
  copylist(step, "by", dapfile);
  if ((tablestart = findstatement(step, "table")))
    {
      for (s = tablestart; step[s] && step[s] != '*' && step[s] != ';'; s++)
	{
	  if (step[s] == '\n')
	    putc(' ', dapfile);
	  else if (step[s] == ',')
	    s++;
	  else
	    putc(step[s], dapfile);
	}
      if (step[s] != '*')
	{
	  fprintf(stderr,
		  "sastrans: before %d: no analysis variable in table statement in proc tabulate.\n",
		  saslineno);
	  exit(1);
	}
    }
  else
    {
      fprintf(stderr,
	      "sastrans: before %d: no table statement in proc tabulate.\n",
	      saslineno);
      exit(1);
    }
  fputs("\", \"\");\n", dapfile);

  fprintf(dapfile, "table(\"%s\", \"", sortname);
  if (!getoption(step, "format", format, 1))
    strcpy(format, "12");

  /* now get row, column, and cell variables */
  s = tablestart;
  while (step[s] && step[s] != ',' && step[s] != ';')
    {
      if (step[s] == '\n')
	putc(' ', dapfile);
      else
	putc(step[s], dapfile);
      s++;
    }
  if (step[s] != ',')
    {
      fprintf(stderr,
	      "sastrans: before %d: no column variables in table statement in proc tabulate.\n",
	      saslineno);
      exit(1);
    }
  s += 2;
  fputs("\", \"", dapfile);
  while (step[s] && step[s] != '*' && step[s] != ';')
    {
      if (step[s] == '\n')
	putc(' ', dapfile);
      else
	putc(step[s], dapfile);
      s++;
    }
  if (step[s] != '*')
    {
      fprintf(stderr,
	      "sastrans: before %d: no analysis variable in table statement in proc tabulate.\n",
	      saslineno);
      exit(1);
    }
  s += 2;
  while (step[s] && step[s] != '\n')
    {
      putc(step[s], dapfile);
      s++;
    }
  fprintf(dapfile, "\", \"%s ", format);
  s++;
  if (step[s] == '/') /* rts option */
    {
      s += 2;
      if (!linecmp(step + s, "rtspace"))
	s += 8;
      else if (!linecmp(step + s, "rts"))
	s += 4;
      else
	{
	  fprintf(stderr,
		  "sastrans: before %d: bad option in table statement in proc tabulate.\n",
		  saslineno);
	  exit(1);
	}
      if (!linecmp(step + s, "="))
	{
	  s += 2;
	  while (step[s] && step[s] != '\n')
	    {
	      putc(step[s], dapfile);
	      s++;
	    }
	}
      else
	{
	  fprintf(stderr,
		  "sastrans: before %d: bad format for rtspace in table statement in proc tabulate.\n",
		  saslineno);
	  exit(1);
	}
    }
  else if (step[s] != ';')
    {
      fprintf(stderr,
	      "sastrans: before %d: extra characters at end of table statement in proc tabulate.\n",
	      saslineno);
      exit(1);
    }
  fputs("\", \"", dapfile);

  /* now do "by" */
  copylist(step, "by", dapfile);
  fputs("\");\n", dapfile);

}

/* Translate call to CORR. step starts after "proc corr" */
void corrtrans(char *step, FILE *dapfile)
{
  int s;
  char setname[TOKENLEN + 1];
  char outname[TOKENLEN + 1];
  int noprint; /* NOPRINT option present? */

  /* get file name */
  if (!getoption(step, "data", setname, 1))
    strcpy(setname, sastmp);

  fprintf(dapfile, "corr(\"%s\", \"", setname);

  /* now get variables and outp= */
  copylist(step, "var", dapfile);
  fputs("\", \"", dapfile);

  /* now do "by" */
  copylist(step, "by", dapfile);
  fputs("\");\n", dapfile);

  noprint = 0;
  for (s = 0; step[s] && step[s] != ';'; s++)
    {
      if (!linecmp(step + s, "noprint"))
	{
	  noprint++;
	  break;
	}
      else
	{
	  while (step[s] && step[s] != '\n')
	    s++;
	}
    }

  if (!noprint)
    {
      fprintf(dapfile, "sort(\"%s.cor\", \"", setname);
      copylist(step, "by", dapfile);
      fputs(" _var1_ _type_ _var2_\", \"\");\n", dapfile);
      fprintf(dapfile,
	      "table(\"%s.cor.srt\", \"_var1_ _type_\", \"_var2_ _corr_\", \"s12\", \"",
	      setname);
      copylist(step, "by", dapfile);
      fputs("\");\n", dapfile);
    }

  if (getoption(step, "outp", outname, 1))
    {
      fprintf(dapfile, "dataset(\"%s.cor\", \"%s\", \"RENAME\");\n", setname, outname);
      strcpy(sastmp, outname); /* most recently created dataset */
    }
}

/* Translate call to RANK. step starts after "proc rank" */
void ranktrans(char *step, FILE *dapfile)
{
  int s;
  char setname[TOKENLEN + 4 + 1]; /* +4 to accomodat .srt */
  char outname[TOKENLEN + 1];
  char option[TOKENLEN + 1];
  int ngroups; /* number of groups */

  /* get file name */
  if (!getoption(step, "data", setname, 1))
    strcpy(setname, sastmp);

  fprintf(dapfile, "group(\"%s\", \"", setname);

  ngroups = 0;
  if (getoption(step, "groups", option, 1)) /* get number of groups */
    { /* do this first to check for conflicting option "descending" */
      if (sscanf(option, "%d", &ngroups) != 1 || ngroups <= 0)
	{
	  fprintf(stderr,
		  "sastrans: before %d: bad number %s of groups in proc rank\n",
		  saslineno, option);
	  exit(1);
	}
    }
  for (s = 0; step[s] && step[s] != ';'; )
    {
      s += linecpy(option, step + s) + 1;
      if (!linecmp(option, "groups") || !linecmp(option, "data") || !linecmp(option, "out"))
	{
	  s += 2; /* skip = */
	  while (alphanum(step[s]))
	    s++;
	  s++;
	}
      else if (ngroups) /* already chose groups= option */
	{
	  fprintf(stderr,
		  "sastrans: before %d: can't combine %s with groups= in proc rank\n",
		  saslineno, option);
	  exit(1);
	}
      else if (!linecmp(option, "fraction") || !linecmp(option, "f"))
	fputs("/ ", dapfile);
      else if (!linecmp(option, "percent") || !linecmp(option, "p"))
	fputs("% ", dapfile);
      else
	{
	  fprintf(stderr,
		  "sastrans: before %d: invalid option %s for proc rank\n",
		  saslineno, option);
	  exit(1);
	}
    }
  
  /* now get variables */
  if ((s = findstatement(step, "var")))
    {
      while (step[s] && step[s] != ';')
	{
	  if (step[s] == '\n')
	    {
	      if (ngroups)
		fprintf(dapfile, " %d# ", ngroups);
	      else
		putc(' ', dapfile);
	    }
	  else
	    putc(step[s], dapfile);
	  s++;
	}
    }
  else
    {
      fprintf(stderr,
	      "sastrans: before %d: missing var statement in proc rank\n",
	      saslineno, option);
      exit(1);
    }

  fputs("\", \"", dapfile);

  /* now do "by" */
  copylist(step, "by", dapfile);
  fputs("\");\n", dapfile);

  if (!getoption(step, "out", outname, 1))
    {
      sprintf(sastmp, "sastmp%02d", ++sastempnum);
      strcpy(outname, sastmp);
    }

  fprintf(dapfile, "dataset(\"%s.grp\", \"%s\", \"RENAME\");\n", setname, outname);
  strcpy(sastmp, outname); /* most recently created dataset */
}

/* Translate call to UNIVARIATE. step starts after "proc univariate" */
void univariatetrans(char *step, FILE *dapfile)
{
  int s;
  char setname[TOKENLEN + 1];
  char outname[TOKENLEN + 1];
  char varname[TOKENLEN + 1];
  int noprint; /* suppress printing? */
  int normal; /* want to test normality? */
  int plot; /* normal plot requested? */
  int statsreq; /* other than default stats requested? */

  /* get file name */
  if (!getoption(step, "data", setname, 1))
    strcpy(setname, sastmp);

  fprintf(dapfile, "pctiles(\"%s\", \"", setname);

  /* now get variables and out= */
  copylist(step, "var", dapfile);
  if (findstatement(step, "weight"))
    {
      putc('*', dapfile);
      copylist(step, "weight", dapfile);
    }

  fputs("\", \"", dapfile);

  /* now get stats */
  statsreq = 0;
  /* first check validity of out= if present */
  outname[0] = '\0'; /* null unless specified */
  if ((s = findstatement(step, "output")))
    {
      if (!getoption(step + s, "out", outname, 1))
	{
	  fprintf(stderr, "sastrans: before %d: bad option for output in proc univariate.\n",
		  saslineno);
	  exit(1);
	}
      while (step[s] && step[s] != ';')
	{
	  if (!linecmp(step + s, "out"))
	    { /* skip now, get it later */
	      s += 6; /* skip out= */
	      while (step[s] && step[s] != '\n')
		s++;
	    }
	  else if (!linecmp(step + s, "pctlpts"))
	    {
	      statsreq = 1;
	      s += 8;
	      if (linecmp(step + s, "="))
		{
		  fprintf(stderr,
			  "sastrans: before %d: missing = after pctlpts in proc univariate.\n",
			  saslineno);
		  exit(1);
		}
	      s += 2;
	      while (num(step[s]))
		{
		  putc('P', dapfile);
		  while (step[s] && step[s] != '\n')
		    {
		      putc(step[s], dapfile);
		      s++;
		    }
		  putc(' ', dapfile);
		  s++;
		}
	      --s; /* back off from ; or next stat name found */
	    }
	  else
	    {
	      statsreq = 1;
	      while (step[s] && step[s] != '\n')
		{
		  if ('a' <= step[s] && step[s] <= 'z')
		    putc(step[s] + 'A' - 'a', dapfile);
		  else
		    putc(step[s], dapfile);
		  s++;
		}
	      putc(' ', dapfile);
	    }
	  s++;
	}
    }

  if (!statsreq)
    fputs("MAX MED MIN N P1 P5 P10 P90 P95 P99 Q1 Q3 QRANGE RANGE", dapfile);

  fputs("\", \"", dapfile);

  /* now do "by" */
  copylist(step, "by", dapfile);
  fputs("\");\n", dapfile);

  /* now get normal, plot, and noprint options */
  for (s = 0, noprint = 0, normal = 0, plot = 0; step[s] && step[s] != ';'; s++)
    {
      if (!linecmp(step + s, "noprint"))
	{
	  noprint = 1;
	  s += 7;
	}
      else if (!linecmp(step + s, "data"))
	{ /* skip it */
	  for (s += 7; step[s] && step[s] != '\n'; s++)
	    ;
	}
      else if (!linecmp(step + s, "normal"))
	{
	  normal = 1;
	  s += 6;
	}
      else if (!linecmp(step + s, "plot"))
	{
	  plot = 1;
	  s += 4;
	}
      else
	{
	  fprintf(stderr,
		  "sastrans: before %d: invalid option for proc univariate.\n",
		  saslineno);
	  exit(1);
	}
    }

  /* now print unless noprint */
  if (!noprint)
    {
      fprintf(dapfile, "print(\"%s.pct\", \"\");\n", setname);
      /* and to Wilcoxon signed rank for each variable */
      if ((s = findstatement(step, "var")))
	{
	  while (step[s] && step[s] != ';')
	    {
	      fprintf(dapfile, "nonparam(\"%s\", \"", setname);
	      while (step[s] && step[s] != '\n')
		{
		  putc(step[s], dapfile);
		  s++;
		}
	      s++; /* on to next variable */
	      fputs("\", \"", dapfile);
	      copylist(step, "by", dapfile);
	      fputs("\");\n", dapfile);
	    }
	}
    }


  if (outname[0])
    {
      fprintf(dapfile, "dataset(\"%s.pct\", \"%s\", \"RENAME\");\n", setname, outname);
      strcpy(sastmp, outname); /* most recently created dataset */
    }

  /* now if normal, plot requested */
  if (normal)
    {
      if ((s = findstatement(step, "var")))
	{
	  while (step[s] && step[s] != ';')
	    { /* need to run each variable separately */
	      s += linecpy(varname, step + s) + 1;
	      if (plot)
		{
		  if (isby(step) >= 0)
		    countparts(step, setname, dapfile);
		  else
		    fputs("_saspictcnt_[_sasnpicts_] = 1;\n", dapfile);
		  fputs("_saspict_[_sasnpicts_] = ", dapfile);
		}
	      fprintf(dapfile, "normal(\"%s\", \"%s\", \"", setname, varname);
	      copylist(step, "by", dapfile);
	      fprintf(dapfile, "\", %d);\n", (plot ? MAXPICTS : 0));
	      if (plot)
		fputs("_saspictpage_[_sasnpicts_++] = 1;\n", dapfile);
	    }
	}
      else
	{
	  fprintf(stderr,
		  "sastrans: before %d: var statement required for normality testing proc univariate.\n",
		  saslineno);
	  exit(1);
	}
      if (plot)
	sashaspicts = 1;
    }
}

