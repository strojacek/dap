/*  Copyright (C) 2003 Free Software Foundation, Inc.
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

/* This file contains all the graphics procs */

#include <stdio.h>
#include "sas.h"
#include <stdlib.h>
#include <string.h>

extern char sastmp[TOKENLEN + 1]; /* name of current temp dataset */
extern int saslineno;

int sashaspicts; /* number of picts allocated */

/* Translate call to CHART (histogram). step starts after "proc chart" */
void charttrans(char *step, FILE *dapfile)
{
  int s;
  int sincr; /* increment for s */
  char setname[TOKENLEN + 1];
  char varname[TOKENLEN + 1 + 1]; /* +1 to accomodate + or - */

  if (!(s = getoption(step, "data", setname, 1)))
    strcpy(setname, sastmp);
  if (isby(step) >= 0)
    countparts(step, setname, dapfile);
  else
    fputs("_saspictcnt_[_sasnpicts_] = 1;\n", dapfile);
  fprintf(dapfile, "_saspict_[_sasnpicts_] = histogram(\"%s\", \"", setname);
  if ((s = findstatement(step, "vbar")))
    {
      s += linecpy(varname, step + s) + 1;
      fprintf(dapfile, "%s ", varname);
      if ((s = getoption(step + s, "freq", varname, 0))) /* weight or freq variable */
	fputs(varname, dapfile);
      fputs("\", \"", dapfile);
    }
  else
    {
      fprintf(stderr, "sastrans: before %d: missing vbar statement in proc chart.\n",
	      saslineno);
      exit(1);
    }
  copylist(step, "by", dapfile);
  fputs("\", ", dapfile);
  s = findstatement(step, "vbar");
  if (getoption(step + s, "levels", varname, 1)) /* shouldn't really use varname... */
    fputs(varname, dapfile);
  else
    fputs("10", dapfile);
  fputs(", \"", dapfile);
  /* STYLE, XFUNCT, NPLOTS) */
  fputs("== ", dapfile);
  if (getoption(step + s, "type", varname, 1)) /* shouldn't really use varname... */
    {
      if (!linecmp(varname, "freq"))
	strcpy(varname, "COUNT");
      else if (!linecmp(varname, "percent") || !linecmp(varname, "pct"))
	strcpy(varname, "PERCENT");
      else
	{
	  fprintf(stderr,
		  "sastrans: before %d: bad option %s in vbar statement in proc chart.\n",
		  saslineno, varname);
	  exit(1);
	}
      fputs(varname, dapfile);
    }
  if ((sincr = getoption(step + s, "axis", varname, 1))) /* min if another, else max */
    {
      if (!linecmp(varname, "+") || !linecmp(varname, "-"))
	{ /* '+', '-' are tokens, but need to attach to number */
	  s += sincr;
	  s += linecpy(varname + 1, step + s) + 1;
	}
      else
	s += sincr;
      if ('0' <= step[s] && step[s] <= '9' ||
	  step[s] == '.' || step[s] == '-' || step[s] == '+') /* varname was min, after all */
	{
	  fprintf(dapfile, " MINX%s", varname);
	  if (step[s] == '-' || step[s] == '-')
	    { /* '-' is token, but need to attach to number */
	      s += linecpy(varname, step + s) + 1;
	      linecpy(varname + 1, step + s);
	    }
	  else
	    linecpy(varname, step + s);
	}
      fprintf(dapfile, " MAXX%s", varname);      
    }

  fprintf(dapfile, "\", NULL, %d);\n", MAXPICTS);
  fputs("_saspictpage_[_sasnpicts_++] = 1;\n", dapfile);
  
  sashaspicts = 1;
}

/* Translate call to PLOT. step starts after "proc plot" */
void plottrans(char *step, FILE *dapfile)
{
  int s; /* index to step */
  int sincr; /* increment for s */
  int by; /* are there "by" variables? */
  char setname[TOKENLEN + 1];
  char xname[TOKENLEN + 1]; /* name of x-variable */
  char yname[TOKENLEN + 1]; /* name of y-variable */

  if (!(s = getoption(step, "data", setname, 1)))
    strcpy(setname, sastmp);

  by = isby(step); /* so we don't have to do this over and over */

  for (s = 0; (sincr = findstatement(step + s, "plot")); s += 2)
    {
      if (by >= 0)
	countparts(step, setname, dapfile);
      else
	fputs("_saspictcnt_[_sasnpicts_] = 1;\n", dapfile);
      s += sincr;
      fprintf(dapfile, "_saspict_[_sasnpicts_] = plot(\"%s\", \"", setname);
      s += linecpy(yname, step + s) + 1;
      if (!alpha(yname[0]))
	{
	  fprintf(stderr,
		  "sastrans: before %d: bad vertical variable name in plot statement in proc plot.\n",
		  saslineno, yname);
	  exit(1);
	}
      if (linecmp(step + s, "*"))
	{
	  fprintf(stderr,
		  "sastrans: before %d: missing * after vertical variable name in plot statement in proc plot.\n",
		  saslineno, yname);
	  exit(1);
	}
      s += 2;
      s += linecpy(xname, step + s) + 1;
      if (!alpha(xname[0]))
	{
	  fprintf(stderr,
		  "sastrans: before %d: bad horizontal variable name in plot statement in proc plot.\n",
		  saslineno, xname);
	  exit(1);
	}
      fprintf(dapfile, "%s %s\", \"", xname, yname);

      copylist(step, "by", dapfile);
      fputs("\", \"", dapfile);

      /* STYLE, XFUNCT, YFUNCT, NPLOTS) */
      if (step[s] == '/')
	{
	  s += 2;
	  while (step[s] && step[s] != ';')
	    {
	      s += linecpy(xname, step + s) + 1; /* using xname, should have optname instead */
	      if (!linecmp(xname, "box"))
		fputs("== ", dapfile);
	      else
		{
		  fprintf(stderr,
			  "sastrans: before %d: bad option %s in plot statement in proc plot.\n",
			  saslineno, xname);
		  exit(1);
		}
	    }
	}
      fprintf(dapfile, "\", NULL, NULL, %d);\n", MAXPICTS);
      fputs("_saspictpage_[_sasnpicts_++] = 1;\n", dapfile);
  
      sashaspicts = 1;
    }

  if (!s)
    {
      fprintf(stderr, "sastrans: before %d: missing plot statement in proc plot.\n",
	      saslineno);
      exit(1);
    }
}
