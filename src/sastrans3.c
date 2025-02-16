/*  Copyright (C) 2003, 2004 Free Software Foundation, Inc.
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

/* Translate call to GLM. step starts after "proc glm" */
void glmtrans(char *step, FILE *dapfile)
{
  int s; /* index to step */
  int sincr; /* increment for s */
  static char setname[TOKENLEN + 1];
  int modelstart; /* starting position of model */
  static char response[TOKENLEN + 1]; /* name of response variable */
  int resplen; /* length of response variable name */
  int e; /* index to step, for stepping through effects of the model */
  int lsmeans; /* 0 = no lsmeans statement, > 0 is start of lsmeans statement. */
  static char test[TOKENLEN + 1]; /* dunnett, tukey, or lsd */
  static char level[TOKENLEN + 1]; /* alpha requested for lsmeans */
  int term; /* starting position of term in numerator of ftest */
  int nomatch; /* lsmeans term doesn't match ftest term */
  int classstart; /* start of class variable list */
  int nbyvars; /* number of by vars: need to know this for contrasts */
  int classvar; /* index of class var in contrast */
  int c; /* index to class vars */
  static char classname[TOKENLEN + 1]; /* name of class var in contrast */
  unsigned int contrastterm; /* value for _term_ variable for contrasts */
  int *coeff; /* coefficients for the effect */
  int ncoeff; /* number of coefficients for contrast */
  int minus; /* coeff has minus sign? (read as separate token) */
  int coeffsum; /* sum of coefficients for contrast */

  if (!getoption(step, "data", setname, 1))
    strcpy(setname, sastmp);

  if ((modelstart = findstatement(step, "model")))
    resplen = linecpy(response, step + modelstart);
  else
    {
      fprintf(stderr,
	      "sastrans: before %d: missing model statement in proc glm\n",
	      saslineno);
      exit(1);
    }

  if (!(classstart = findstatement(step, "class")))
    {
      fprintf(stderr,
	      "sastrans: before %d: missing class statement in proc glm\n",
	      saslineno);
      exit(1);
    }

  if ((s = findstatement(step, "by")))
    {
      for (nbyvars = 0; step[s] && step[s] != ';'; nbyvars++)
	s += linecpy((char *) NULL, step + s) + 1;
    }
  else
    nbyvars = 0;

  /* we have to sort by the class vars and to get means, etc. */
  fprintf(dapfile, "sort(\"%s\", \"", setname);
  copylist(step, "by", dapfile);
  copylist(step, "class", dapfile);
  fputs("\", \"\");\n", dapfile);

  /* we have to get means and vars */
  fprintf(dapfile, "means(\"%s.srt\", \"%s\", \"N MEAN VAR\", \"", setname, response);
  copylist(step, "by", dapfile);
  copylist(step, "class", dapfile);
  fputs("\");\n", dapfile);

  /* now we can start the ANOVA and test the whole model */
  fprintf(dapfile, "effects(\"%s.srt.mns\", \"%s ", setname, response);
  copylist(step, "class", dapfile);
  fputs("\", \"", dapfile);
  s = modelstart + resplen + 1;
  if (step[s] != '=')
    {
      fprintf(stderr,
	      "sastrans: before %d: missing = in model statement in proc glm\n",
	      saslineno);
      exit(1);
    }
  for (s += 2; step[s] && step[s] != '/' && step[s] != ';'; s++)
    {
      if (step[s] == '\n')
	putc(' ', dapfile);
      else
	putc(step[s], dapfile);
    }
  fputs("\", \"", dapfile);
  copylist(step, "by", dapfile);
  fputs("\");\n", dapfile);

  /* now we've run the model, it's time to test each effect in it */
  /* we need a separate call to ftest for each effect and check for lsmeans statements
   */

  /* first get the first lsmeans statement */
  if ((lsmeans = findstatement(step, "lsmeans")))
    { /* see if it specifies an error term */
      if (getoption(step + lsmeans, "e", (char *) NULL, 1))
	lsmeans = 0; /* not going to use it */
      else /* need to get test name, alpha */
	{
	  for (s = lsmeans; step[s] && step[s] != '/' && step[s] != ';'; s++)
	    ; /* get to options */
	  test[0] = '\0'; /* haven't found one yet... */
	  if (step[s] == '/')
	    {
	      for (s += 2; step[s] && step[s] != ';'; )
		{
		  s += linecpy(test, step + s) + 1;
		  upper(test);
		  if (strcmp(test, "DUNNETT") && strcmp(test, "TUKEY") && strcmp(test, "LSD"))
		    test[0] = '\0'; /* wasn't, after all */
		}
	    }
	  if (!test[0])
	    {
	      fprintf(stderr,
		      "sastrans: before %d: no test specified in lsmeans statement in proc glm\n",
		      saslineno);
	      exit(1);
	    }
	  if (!getoption(step + lsmeans, "alpha", level, 1))
	    strcpy(level, "0.05");
	}
    }

  /* now we're ready to test the terms in the model, one-by-one */

  e = modelstart + resplen + 3;
  while (step[e] && step[e] != '/' && step[e] != ';')
    {
      fprintf(dapfile, "ftest(\"%s.srt.mns.con\", \"%s ", setname, response);
      copylist(step, "class", dapfile);
      fputs("\", \"", dapfile);
      /* here comes the numerator */
      term = e; /* mark this place for lsmeans */
      while (step[e] && step[e] != '\n')
	{
	  putc(step[e], dapfile);
	  e++;
	  /* now see if it's a crossed or nested effect */
	  if (step[e] == '\n' && step[e + 1] == '*') /* then need to keep copying */
	    {
	      putc('*', dapfile);
	      e += 3; /* get to next variable */
	      term = 0; /* mark as crossed: lsmeans can't handle these yet */
	    }
	}
      fputs("\", \"\", \"", dapfile); /* null denominator */
      copylist(step, "by", dapfile);
      fputs("\");\n", dapfile);
      e++; /* position at next term */

      if (lsmeans && term) /* term is position of numerator in ftest just run */
	{
	  for (s = lsmeans; step[s] && step[s] != '/' && step[s] != ';' &&
		 (nomatch = linecmp(step + s, step + term));
	       s += linecpy((char *) NULL, step + s) + 1)
	    ; /* search for ftest effect in lsmeans statement */
	  if (!nomatch)
	    {
	      fprintf(dapfile,
		      "lsmeans(\"%s.srt.mns.tst\", \"%s\", %s, \"%s ",
		      setname, test, level, response);
	      copylist(step, "class", dapfile);
	      fputs("\", \"", dapfile);
	      for (s = term; step[s] && step[s] != '\n'; s++)
		putc(step[s], dapfile);
	      fputs("\", \"", dapfile);
	      copylist(step, "by", dapfile);
	      fputs("\", \"s12\");\n", dapfile);
	    }
	}
    }

  /* now do specific test request */
  for (s = 0; (sincr = findstatement(step + s, "test")); )
    {
      s += sincr;
      fprintf(dapfile, "ftest(\"%s.srt.mns.con\", \"%s ", setname, response);
      copylist(step, "class", dapfile);
      fputs("\", \"", dapfile);
      if (!step[s] || linecmp(step + s, "h") || linecmp(step + s + 2, "="))
	{
	  fprintf(stderr,
		  "sastrans: before %d: missing h= in test statement in proc glm\n",
		  saslineno);
	  exit(1);
	}
      for (s += 4; step[s] &&
	     (linecmp(step + s, "e") || (step[s + 2] && linecmp(step + s + 2, "="))); s++)
	s += putlines(step + s, dapfile, '\n'); /* putlines puts a space */
      if (!step[s] || linecmp(step + s, "e") || linecmp(step + s + 2, "="))
	{
	  fprintf(stderr,
		  "sastrans: before %d: missing e= in test statement in proc glm\n",
		  saslineno);
	  exit(1);
	}
      fputs("\", \"", dapfile);
      s += 4;
      s += putlines(step + s, dapfile, ';');
      if (step[s] != ';')
	{
	  fprintf(stderr,
		  "sastrans: before %d: extra characters after e=<effect> in test statement in proc glm\n",
		  saslineno);
	  exit(1);
	}
      fputs("\", \"", dapfile);
      copylist(step, "by", dapfile);
      fputs("\");\n", dapfile);
    }

  /* Now do contrasts: each contrast statement runs a separate ftest */
  /* First set up array for coefficient values: this is an overestimate; so? */
  /* And it's unncessary if there's no contrast statement */
  coeff = (int *) malloc(sizeof(int) * strlen(step) / 2);
  /* First set up array for coefficient values: this is an overestimate; so? */
  for (s = 0; (sincr = findstatement(step + s, "contrast")); )
    {
      s += sincr;
      if (step[s] != '"')
	{
	  fprintf(stderr,
		  "sastrans: before %d: missing \"LABEL\" in contrast statement in proc glm\n",
		  saslineno);
	  exit(1);
	}
      fputs("title(\"", dapfile);
      for (s++; step[s] && step[s] != '"'; s++)
	/* can't use putlines because we want the newlines */
	putc(step[s], dapfile);
      if (step[s] != '"')
	{
	  fprintf(stderr,
		  "sastrans: before %d: no terminating \" in contrast statement label in proc glm\n",
		  saslineno);
	  exit(1);
	}
      fputs("\");\n", dapfile);
      s += 2; /* on to effect and values */
      /* We need to revise the .con file "by hand" for ftest */
      /* We need to set up _term_ for the class variable specified in the contrast. */
      /* Find class variable referenced */
      for (contrastterm = 0x1, e = classstart, classvar = 0; step[e] && step[e] != ';';
	   contrastterm = (contrastterm << 1), classvar++)
	{
	  if (!linecmp(step + s, step + e))
	    break;
	  else
	    e += linecpy((char *) NULL, step + e) + 1;
	}
      classvar++; /* now is 1, 2, ..., 3 */
      s += linecpy(classname, step + s) + 1;
      /* should have coefficients now */
      for (ncoeff = 0, coeffsum = 0; num(step[s]) || step[s] == '+' || step[s] == '-';
	   ncoeff++)
	{
	  if (step[s] == '+' || step[s] == '-')
	    {
	      minus = (step[s] == '-');
	      s += 2;
	    }
	  else
	    minus = 0;
	  if (sscanf(step + s, "%d", coeff + ncoeff) != 1)
	    {
	      fprintf(stderr,
		      "sastrans: before %d: invalid coefficient in contrast statement in proc glm\n",
		      saslineno);
	      exit(1);
	    }
	  if (minus)
	    coeff[ncoeff] = -coeff[ncoeff];
	  coeffsum += coeff[ncoeff];
	  s += linecpy((char *) NULL, step + s) + 1;
	}
      if (coeffsum)
	{
	  fprintf(stderr,
		  "sastrans: before %d: coefficients sum to nonzero in contrast statement in proc glm\n",
		  saslineno);
	  exit(1);
	}
      if (step[s] == '/') /* on to e=, if any */
	s += 2;
      /* We'll start with the file that effects created */
      fprintf(dapfile, "inset(\"%s.srt.mns.con\")\n{\n", setname);
      fprintf(dapfile, "char _type_[9];\ndouble %s;\nint _n_, _term_;\n", response);
      fprintf(dapfile, "int _partv_[%d];\n", nbyvars + classvar);
      fprintf(dapfile, "int _c_, _more_, _contr1_;\ndouble _coeff_[%d];\n", ncoeff);
      fprintf(dapfile, "outset(\"%s.srt.mns.con.con\", \"\");\n", setname);
      fputs("dap_list(\"", dapfile);
      copylist(step, "by", dapfile);
      for (e = classstart, c = 0; c < classvar; c++)
	e += putlines(step + e, dapfile, '\n') + 1;
      fprintf(dapfile, "\", _partv_, %d);\n", nbyvars + classvar);
      /* now we need to set the coefficient array values */
      for (c = 0; c < ncoeff; c++)
	fprintf(dapfile, "_coeff_[%d] = %d.0;\n", c, coeff[c]);
      /* first write out N, MEAN, VAR */
      fputs("for (_c_ = 0, _contr1_ = 1, _more_ = step(); _more_; )\n{\n", dapfile);
      fprintf(dapfile, "if (dap_newpart(_partv_, %d))\n_c_ = 0;\n", nbyvars + classvar - 1);
      fprintf(dapfile, "else if (dap_newpart(_partv_, %d))\n_c_++;\n", nbyvars + classvar);
      fputs("output();\nstep();\noutput();\nstep();\noutput();\n", dapfile);
      /* need to include ERROR lines, but skip CONTR lines for specified effect */
      fputs("while ((_more_ = step()))\n{\n", dapfile);
      fputs("if (!strcmp(_type_, \"ERROR\"))\noutput();\n", dapfile);
      fputs("else if (!strcmp(_type_, \"CONTR\"))\n{\n", dapfile);
      fprintf(dapfile, "if (_term_ == %d)\n{\n", contrastterm); /* if 1st, change to contrast */
      fprintf(dapfile, "if (_contr1_)\n{\n_contr1_ = 0;\n_term_ = %d;\n", contrastterm);
      fprintf(dapfile, "if (_c_ < %d)\n", ncoeff);
      fprintf(dapfile, "%s = _coeff_[_c_];\nelse\n%s = 0.0;\n", response, response);
      fputs("output();\n}\n}\n", dapfile);
      fputs("else\noutput();\n}\n", dapfile);
      fputs("else if (!strcmp(_type_, \"LSMEAN\"))\noutput();\n", dapfile);
      fputs("else\n\{\n_contr1_ = 1;\nbreak;\n}\n}\n}\n}\n", dapfile); /* at another cell */
      fprintf(dapfile, "ftest(\"%s.srt.mns.con.con\", \"%s ", setname, response);
      copylist(step, "class", dapfile);
      fprintf(dapfile, "\", \"%s\", \"", classname);
      if ((sincr = getoption(step + s, "e", (char *) NULL, 1)))
	{
	  s += sincr;
	  s += putlines(step + s, dapfile, ';');
	}
      if (!linecmp(step + s, ";"))
	s += 2;
      else
	{
	  fprintf(stderr,
		  "sastrans: before %d: missing ; at end of contrast statement in proc glm\n",
		  saslineno);
	  exit(1);
	}
      fputs("\", \"", dapfile);
      copylist(step, "by", dapfile);
      fputs("\");\ntitle(NULL);\n", dapfile);
    }
  free(coeff);

  /* now do lsmeans statement(s) that we haven't done yet, if any */

  while ((s = findstatement(step + lsmeans, "lsmeans"))) /* find next lsmeans statement */
    {
      lsmeans += s;
      /* first get position of denominator, if any */
      e = lsmeans + getoption(step + lsmeans, "e", (char *) NULL, 1);
      if (!getoption(step + lsmeans, "alpha", level, 1))
	strcpy(level, "0.05");
      /* get test type */
      test[0] = '\0'; /* in case we never find one */
      for (s = lsmeans; step[s] && step[s] != '/' && step[s] != ';'; s++)
	;
      if (step[s] == '/')
	{
	  for (s += 2; step[s] && step[s] != ';'; )
	    {
	      s += linecpy(test, step + s) + 1;
	      upper(test);
	      if (strcmp(test, "DUNNETT") && strcmp(test, "TUKEY") && strcmp(test, "LSD"))
		test[0] = '\0'; /* wasn't, after all */
	    }
	}
      if (!test[0])
	{
	  fprintf(stderr,
		  "sastrans: before %d: no test specified in lsmeans statement in proc glm\n",
		  saslineno);
	  exit(1);
	}
      upper(test);
      for (s = lsmeans; step[s] && step[s] != '/' && step[s] != ';'; s++)
	{ /* one term at a time */
	  fprintf(dapfile, "ftest(\"%s.srt.mns.con\", \"%s ", setname, response);
	  copylist(step, "class", dapfile);
	  fputs("\", \"", dapfile);
	  /* here comes the numerator */
	  term = s; /* mark this place for call to lsmeans */
	  s += putlines(step + s, dapfile, '\n');
	  fputs("\", \"", dapfile);
	  if (e > lsmeans) /* put denominator */
	    {
	      for (s = e; step[s] && step[s] != ';' && linecmp(step + s, "alpha") &&
		     linecmp(step + s, "dunnett") && linecmp(step + s, "tukey") &&
		     linecmp(step + s, "lsd"); s += putlines(step + s, dapfile, '\n') + 1)
		;
	    }
	  fputs("\", \"", dapfile);
	  copylist(step, "by", dapfile);
	  fputs("\");\n", dapfile);

	  /* now the lsmeans statement */

	  fprintf(dapfile, "lsmeans(\"%s.srt.mns.tst\", \"%s\", %s, \"%s ",
		  setname, test, level, response);
	  copylist(step, "class", dapfile);
	  fputs("\", \"", dapfile);
	  s = term + putlines(step + term, dapfile, '\n');
	  fputs("\", \"", dapfile);
	  copylist(step, "by", dapfile);
	  fputs("\", \"s12\");\n", dapfile);
	}
    }
}

/* Translate call to LOGISTIC. step starts after "proc logistic" */
void logistictrans(char *step, FILE *dapfile)
{
  int s; /* index to step */
  char setname[TOKENLEN + 1];
  char outname[TOKENLEN + 1];

  if (!getoption(step, "data", setname, 1))
    strcpy(setname, sastmp);

  fprintf(dapfile, "logreg(\"%s\", \"", setname);
  if ((s = findstatement(step, "model")))
    {
      /* response variable */
      s += putlines(step + s, dapfile, '\n') + 1; /* only one response variable allowed */
      putc('/', dapfile); /* both forms use / in Dap */
      if (step[s] == '/') /* we have the events / trials form */
	{
	  s += 2;
	  s += putlines(step + s, dapfile, '\n') + 1;
	}
      else
	putc('1', dapfile); /* binary response */
      if (step[s] == '=')
	{
	  fputs("\", \"\", \"", dapfile); /* x0-var-list is empty */
	  s += 2;
	  s += putlines(step + s, dapfile, ';');
	  fputs("\", \"", dapfile); /* closes the x1 variable list */
	  copylist(step, "by", dapfile);
	  fputs("\", NULL, 0.95);\n", dapfile);
	}
      else
	{
	  fprintf(stderr,
		  "sastrans: before %d: missing = in model statement in proc logistic.\n",
		  saslineno);
	  exit(1);
	}
    }
  else
    {
      fprintf(stderr, "sastrans: before %d: missing model statement in proc logistic.\n",
	      saslineno);
      exit(1);
    }
  if (getoption(step, "outest", outname, 1))
    {
      fprintf(dapfile, "dataset(\"%s.cov\", \"%s\", \"RENAME\");\n", setname, outname);
      strcpy(sastmp, outname);
    }
}

/* Translate call to NPAR1WAY. step starts after "proc npar1way" */
void npar1waytrans(char *step, FILE *dapfile)
{
  int s; /* index to step */
  char setname[TOKENLEN + 1];
  char classname[TOKENLEN + 1]; /* name of class variable */

  if (!getoption(step, "data", setname, 1))
    strcpy(setname, sastmp);

  if ((s = findstatement(step, "class")))
    linecpy(classname, step + s);
  else
    {
      fprintf(stderr, "sastrans: before %d: missing class statement in proc npar1way.\n",
	      saslineno);
      exit(1);
    }

  if ((s = findstatement(step, "var")))
    {
      while (step[s] && step[s] != ';') /* if there are multiple variables, then... */
	{ /* need to run nonparam for each */
	  fprintf(dapfile, "nonparam(\"%s\", \"", setname);
	  while (step[s] && step[s] != '\n')
	    {
	      putc(step[s], dapfile);
	      s++;
	    }
	  fprintf(dapfile, " %s\", \"", classname);
	  copylist(step, "by", dapfile);
	  fputs("\");\n", dapfile);
	  s++;
	}
      if (step[s] != ';')
	{
	  fprintf(stderr, "sastrans: before %d: missing ; at end of proc npar1way.\n",
		  saslineno);
	  exit(1);
	}
    }
  else
    {
      fprintf(stderr, "sastrans: before %d: missing var statement in proc npar1way.\n",
	      saslineno);
      exit(1);
    }
}

/* Translate call to REG. step starts after "proc reg" */
void regtrans(char *step, FILE *dapfile)
{
  int s; /* index to step */
  char setname[TOKENLEN + 1];
  char outname[TOKENLEN + 1];
  int isadd; /* is there an add statement? */

  if (!getoption(step, "data", setname, 1))
    strcpy(setname, sastmp);

  if (findstatement(step, "plot")) /* we're going to call plotlinreg */
    {
      if (isby(step) >= 0)
	countparts(step, setname, dapfile);
      else
	fputs("_saspictcnt_[_sasnpicts_] = 1;\n", dapfile);
      fprintf(dapfile, "_saspict_[_sasnpicts_] = plotlinreg(\"%s\", \"", setname);
      if ((s = findstatement(step, "model")))
	{
	  /* response variable: must be only 1 */
	  while (step[s] && step[s] != '\n')
	    {
	      putc(step[s], dapfile);
	      s++;
	    }
	  s++;
	  if (step[s] == '=')
	    {
	      fputs("\", \"", dapfile);
	      for (s += 2; step[s] && step[s] != '\n'; s++)
		putc(step[s], dapfile);
	      if (step[s + 1] != ';')
		{
		  fprintf(stderr,
			  "sastrans: before %d: only one explanatory variable allowed in model statement in proc reg with plotting\n",
			  saslineno);
		  exit(1);
		}
	      fputs("\", \"==\", \"", dapfile);
	      copylist(step, "by", dapfile);
	      fputs("\", _saspictcnt_[_sasnpicts_], 0.95);\n", dapfile);
	      fputs("_saspictpage_[_sasnpicts_++] = 4;\n", dapfile);
	      sashaspicts = 1;
	    }
	  else
	    {
	      fprintf(stderr,
		      "sastrans: before %d: only one response variable allowed in model statement in proc reg with plotting\n",
		      saslineno);
	      exit(1);
	    }
	}
      else
	{
	  fprintf(stderr, "sastrans: before %d: missing model statement in proc reg.\n",
		  saslineno);
	  exit(1);
	}
    }
  else /* just use linreg */
    {
      fprintf(dapfile, "linreg(\"%s\", \"", setname);
      if ((s = findstatement(step, "model")))
	{
	  /* response variables */
	  s += putlines(step + s, dapfile, '=');
	  if (step[s] == '=')
	    {
	      fputs("\", \"", dapfile);
	      if (!(isadd = findstatement(step, "add"))) /* reduced model is intercept only */
		fputs("\", \"", dapfile); /* close x0-variables list */
	      s += 2;
	      s += putlines(step + s, dapfile, ';');
	      fputs("\", \"", dapfile); /* either closes the x0 or x1 variable list */
	      if (isadd) /* put in the x1-variables */
		{
		  copylist(step, "add", dapfile);
		  fputs("\", \"", dapfile); /* closes the x1 variable list */
		}
	      copylist(step, "by", dapfile);
	      fputs("\", NULL, 0.95);\n", dapfile);
	    }
	  else
	    {
	      fprintf(stderr,
		      "sastrans: before %d: missing = in model statement in proc reg.\n",
		      saslineno);
	      exit(1);
	    }
	}
      else
	{
	  fprintf(stderr, "sastrans: before %d: missing model statement in proc reg.\n",
		  saslineno);
	  exit(1);
	}
    }
  if (getoption(step, "outest", outname, 1))
    {
      fprintf(dapfile, "dataset(\"%s.cov\", \"%s\", \"RENAME\");\n", setname, outname);
      strcpy(sastmp, outname);
    }
}

/* Translate call to DAP. step starts after "proc dap" */
void daptrans(char *step, FILE *dapfile)
{
  int s; /* index to step */
  int brace; /* level of braces nesting */

  s = 0;
  if (step[s] != ';')
    {
      fprintf(stderr, "sastrans: before %d: no options allowed for proc dap\n", saslineno);
      exit(1);
    }
  s += 2;
  if (step[s] == '{')
    {
      fputs("{\n", dapfile);
      for (s += 2, brace = 1; brace && step[s]; s++)
	{
	  if (step[s] == '\n')
	    putc(' ', dapfile);
	  else
	    putc(step[s], dapfile);
	  if (step[s] == ';' || step[s] == '{' || step[s] == '}')
	    putc('\n', dapfile);
	  if (step[s] == '{')
	    brace++;
	  else if (step[s] == '}')
	    --brace;
	}
      if (brace)
	{
	  fprintf(stderr, "sastrans: before %d: missing } in proc dap\n", saslineno);
	  exit(1);
	}
      putc('\n', dapfile);
    }
  else
    {
      s += putlines(step + s, dapfile, ';');
      if (step[s] != ';')
	{
	  fprintf(stderr, "sastrans: before %d: missing ; in proc dap\n", saslineno);
	  exit(1);
	}
      fputs(";\n", dapfile);
    }
}


/* import call to DAP. step starts after "proc import" */
void importtrans(char *step, FILE *dapfile)
{
  int s; /* index to step */
  int brace; /* level of braces nesting */
  int start; /* starting position */
  int resplen; /* length of response variable name */
  int replace=0;
  static char delimiter[TOKENLEN + 1];
  static char setname[TOKENLEN + 1];
  static char datafile[TOKENLEN + 1];
  static char dbms[TOKENLEN + 1];
  static char strreplace[TOKENLEN + 1];
  static char getnames[4];
	
  if (!getoption(step, "out", setname, 1))
    strcpy(setname, sastmp);
  if (!getoption(step, "datafile", datafile, 1))
    strcpy(datafile, sastmp);
  if (!getoption(step, "dbms", dbms, 1))
    strcpy(dbms, sastmp);
  if (!getoption(step, "delimiter", delimiter, 1))
    strcpy(delimiter, "");
  else{
	if(delimiter[0]=='\'')
		delimiter[0]='"';
	if(delimiter[strlen(delimiter)-1]=='\'')
		delimiter[strlen(delimiter)-1]='"';
}
   
   if ((s = findstatement(step, "getnames")))
   {
	int i=8;
	while(step[s+i]!='n'&&step[s+i]!='y'&&step[s+i]!=';'&&step[s+i]!='\0')
		i++;
	if (step[s+i]=='n'||step[s+i]=='N')
		strcpy(getnames, "no");
	else
		strcpy(getnames, "yes");
   }

  int getnam=1;
  if(strcmp(getnames,"no")==0)
	  getnam=0;
  if (!getoption(step, "replace", strreplace, 0))
    replace=1;
  /* we have to sort by the class vars and to get means, etc. */
  fprintf(dapfile, "import(\"%s\", %s , \"%s\",%s, %i,%i);\n", setname,datafile,dbms,delimiter,replace,getnam);
  
}


/* import call to DAP. step starts after "proc import" */
void surveyselecttrans(char *step, FILE *dapfile)
{
  int s; /* index to step */
  int brace; /* level of braces nesting */
  int start; /* starting position */
  int resplen; /* length of response variable name */
  int replace=0;
  static char nbtirage[TOKENLEN + 1];
  static char setname[TOKENLEN + 1];
  static char datafile[TOKENLEN + 1];
  static char method[TOKENLEN + 1];
  static char strreplace[TOKENLEN + 1];
  static char getnames[4];
	//data =tPres2007 method=SRS  n = 220  reps= 50  seed= 1213   out=sasPres2007 stats
  if (!getoption(step, "out", setname, 1))
    strcpy(setname, sastmp);
  if (!getoption(step, "data", datafile, 1))
    strcpy(datafile, sastmp);
  if (!getoption(step, "method", method, 1))
    strcpy(method, sastmp);
  if (!getoption(step, "n", nbtirage, 1))
    strcpy(nbtirage, "1");
 

   
  
  /* we have to sort by the class vars and to get means, etc. */
  // surveyselect(char *fname,char *outname,char *method,int tirage);
  fprintf(dapfile, " surveyselect(\"%s\", \"%s\" , \"%s\",%s);\n", datafile,setname,method,nbtirage);
  
}
