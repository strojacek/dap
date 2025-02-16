/* dap6.c -- categorical models */

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
#include "dap_make.h"
#include "externs.h"

extern dataobs dap_obs[];
extern int dap_ono;
extern FILE *dap_lst;
extern FILE *dap_err;
extern char *dap_dapname;

#define MAXCLASS 32

static double *allparam;
static char *sel;
static char *selred;
static double (*ex)();
static double **tab;
static int nc;


static double loglike(double *selparam)
{
  int s;
  int p;
  double expected;
  double ll;
  int c;

  for (s = 0, p = 0; sel[s]; s++)
    {
      if (sel[s] != '!')
	allparam[s] = selparam[p++];
      else
	allparam[s] = 0.0;
    }
  for (ll = 0.0, c = 0; c < nc; c++)
    {
      expected = ex(allparam, tab[c] + 1);	/* skip cell count */
      ll += tab[c][0] * log(expected) - expected;
    }
  return ll;
}

/* parses parameter list as names into codes */
static int selparse(char *names, char *codes)
{
  int n;	/* index to names */
  int c;	/* index to codes */

  for (n = 0; names[n] == ' '; n++)
    ;
  for (c = 0; names[n]; c++)
    {
      if (names[n] == '!' || names[n] == '?')
	{
	  codes[c] = names[n];
	  for (++n; names[n] == ' '; n++)
	    ;
	}
      else
	codes[c] = '1';
      while (names[n] && names[n] != ' ')
	n++;
      while (names[n] == ' ')
	n++;
    }
  codes[c] = '\0';
  return c;
}

static void categ1(double **tab, int ncell, int *varv, int nvar,
		   double (*expect)(), double *param,
		   char *select, char *selcodes,
		   int param1n, int param2n, int covn,
		   int partv[], int partv2[], int npart, char *trace)
{
  int typen;	/* index of _type_ variable */
  int sparam;	/* number of selected parameters */
  int sparamr;	/* number of selected parameters in reduced model */
  int nparam;	/* number of parameters */
  int c, c1, c0;	/* indexes to selection string */
  double *x;
  double *xch;
  int p;
  double step, tol;
  double tmp;
  int v;
  double likerat;
  double likered;
  double pearson;
  double *infomem;	/* memory for information matrix */
  double **info;		/* information matrix */
  int p1, p2;
  double lpp, lpm, lmp, lmm;
  double h, halfh;
  int s, s1;	/* indexes to info and covariance matrices */
  int nonsing;	/* info matrix non-singular? */

  if ((typen = dap_varnum("_type_")) < 0)
    {
      fputs("(categ1) missing _type_ variable\n", dap_err);
      exit(1);
    }
  sparamr = 0;
  likered = 0.0;
  nc = ncell;
  ex = expect;
  x = (double *) dap_malloc(sizeof(double) * strlen(sel), "");
  xch = (double *) dap_malloc(sizeof(double) * strlen(sel), "");
  if (selred)
    {
      sel = selred;
      for (nparam = 0, sparamr = 0; sel[nparam]; nparam++)
	{
	  if (sel[nparam] != '!')
	    {
	      allparam[nparam] = param[nparam];
	      sparamr++;
	    }
	  else
	    allparam[nparam] = 0.0;
	}
      for (p = 0, nparam = 0; sel[nparam]; nparam++)
	{
	  if (sel[nparam] != '!')
	    x[p++] = param[nparam];
	}
      for (step = 0.0, p = 0; p < sparamr; p++)
	{
	  tmp = x[p];
	  step += tmp * tmp;
	}
      if (step > 0.0)
	step = 0.1 * sqrt(step);
      else
	step = 0.01;
      tol = dap_cattol * step;
      dap_maximize(&loglike, sparamr, x, step, tol, trace);
      for (c = 0, likerat = 0.0; c < ncell; c++)
	likered += (tab[c][0] + dap_addtozero) *
	  log((tab[c][0] + dap_addtozero) / expect(allparam, tab[c] + 1));
      likered *= 2.0;
    }
  sel = selcodes;
  for (nparam = 0, sparam = 0; sel[nparam]; nparam++)
    {
      if (sel[nparam] != '!')
	{
	  allparam[nparam] = param[nparam];
	  sparam++;
	}
      else
	allparam[nparam] = 0.0;
    }
  for (p = 0, nparam = 0; sel[nparam]; nparam++)
    {
      if (sel[nparam] != '!')
	x[p++] = param[nparam];
    }
  for (step = 0.0, p = 0; p < sparam; p++)
    {
      tmp = x[p];
      step += tmp * tmp;
    }
  if (step > 0.0)
    step = 0.1 * sqrt(step);
  else
    step = 0.01;
  tol = dap_cattol * step;
  dap_maximize(&loglike, sparam, x, step, tol, trace);
  for (c = 0, likerat = 0.0, pearson = 0.0; c < ncell; c++)
    {
      for (v = 0; v < nvar; v++)
	dap_obs[0].do_dbl[varv[v]] = tab[c][v];
      strcpy(dap_obs[0].do_str[typen], "OBS");
      output();
      strcpy(dap_obs[0].do_str[typen], "FIT");
      dap_obs[0].do_dbl[varv[0]] = expect(allparam, tab[c] + 1);
      likerat += (tab[c][0] + dap_addtozero) *
	log((tab[c][0] + dap_addtozero) / dap_obs[0].do_dbl[varv[0]]);
      tmp = dap_obs[0].do_dbl[varv[0]] - tab[c][0];
      pearson += tmp * tmp / dap_obs[0].do_dbl[varv[0]];
      output();
    }
  likerat *= 2.0;
  infomem = (double *) dap_malloc(sizeof(double) * sparam * sparam, "");
  info = (double **) dap_malloc(sizeof(double *) * sparam, "");
  for (p = 0; p < sparam; p++)
    info[p] = infomem + p * sparam;
  h = 0.0001;
  halfh = h / 2.0;
  for (p1 = 0; p1 < sparam; p1++)
    {
      for (p = 0; p < sparam; p++)
	xch[p] = x[p];
      lpm = loglike(xch);
      xch[p1] += h;
      lpp = loglike(xch);
      xch[p1] = x[p1] - h;
      lmm = loglike(xch);
      info[p1][p1] = -(lpp - 2.0 * lpm + lmm) / (h * h);
    }
  for (p1 = 0; p1 < sparam; p1++)
    for (p2 = 0; p2 < p1; p2++)
      {
	for (p = 0; p < sparam; p++)
	  xch[p] = x[p];
	xch[p1] += halfh;
	xch[p2] += halfh;
	lpp = loglike(xch);
	xch[p1] = x[p1] - halfh;
	lmp = loglike(xch);
	xch[p2] = x[p2] - halfh;
	lmm = loglike(xch);
	xch[p1] = x[p1] + halfh;
	lpm = loglike(xch);
	info[p1][p2] = -(lpp - lpm - lmp + lmm) / (h * h);
	info[p2][p1] = info[p1][p2];
      }
  if (!(nonsing = dap_invert(info, sparam)))
    fputs("(categ1) covariance matrix is singular\n", dap_err);
  /* now print and output estimates and SEs, later output the covariance matrix */
  dap_ono = 1;
  if ((typen = dap_varnum("_type_")) < 0)
    {
      fprintf(dap_err, "(categ1) output dataset has no _type_ variable\n");
      exit(1);
    }
  for (v = 0; v < npart; v++)
    {
      if (dap_obs[0].do_len[partv[v]] == DBL)
	dap_obs[dap_ono].do_dbl[partv2[v]] = dap_obs[0].do_dbl[partv[v]];
      else if (dap_obs[0].do_len[partv[v]] == INT)
	dap_obs[dap_ono].do_int[partv2[v]] = dap_obs[0].do_int[partv[v]];
      else
	strcpy(dap_obs[dap_ono].do_str[partv2[v]],
	       dap_obs[0].do_str[partv[v]]);
    }
  fputs("Maximum likelihood estimation\n\n", dap_lst);
  fprintf(dap_lst, "Cell count: %s\n", dap_obs[0].do_nam[varv[0]]);
  fputs("Class and aux variables:", dap_lst);
  for (v = 1; v < nvar; v++)
    fprintf(dap_lst, " %s", dap_obs[0].do_nam[varv[v]]);
  putc('\n', dap_lst);
  fputs("\nStatistic              df      Prob\n", dap_lst);
  fprintf(dap_lst, "G2[Model]   = %6.2f  %3d    %.4f\n",
	  likerat, ncell - sparam,
	  ((ncell > sparam) ?
	   (ceil(10000.0 * probchisq(likerat, ncell - sparam)) / 10000.0) :
	   1.0));
  if (selred)
    {
      fprintf(dap_lst, "G2[Reduced] = %6.2f  %3d    %.4f\n",
	      likered, ncell - sparamr,
	      ceil(10000.0 * probchisq(likered, ncell - sparamr)) / 10000.0);
      fprintf(dap_lst, "G2[Diff]    = %6.2f  %3d    %.4f\n",
	      likered - likerat, sparam - sparamr,
	      ceil(10000.0 * probchisq(likered - likerat, sparam - sparamr)) / 10000.0);
    }
  fprintf(dap_lst, "X2[Model]   = %6.2f  %3d    %.4f\n",
	  pearson, ncell - sparam,
	  ((ncell > sparam) ?
	   (ceil(10000.0 * probchisq(pearson, ncell - sparam)) / 10000.0) :
	   1.0));
  putc('\n', dap_lst);
  fputs("    Estimate          ASE  Model  Parameter\n", dap_lst);
  for (c = 0; select[c] == ' '; c++)
    ;
  for (p = 0, s = 0; p < nparam; p++)
    {
      fprintf(dap_lst, "%12g ", allparam[p]);
      if (sel[p] == '!')
	fputs("              ", dap_lst);
      else
	{
	  if (nonsing)
	    fprintf(dap_lst, "%12g  ", sqrt(info[s][s]));
	  else
	    fputs("           ?  ", dap_lst);
	}
      switch (selcodes[p])
	{
	case '1':
	  fprintf(dap_lst, "  *    ");
	  break;
	case '?':
	  fprintf(dap_lst, "  ?    ");
	  for (++c; select[c] == ' '; c++)
	    ;
	  break;
	default:
	  fprintf(dap_lst, "       ");
	  for (++c; select[c] == ' '; c++)
	    ;
	  break;
	}
      for (p2 = 0; select[c] && select[c] != ' '; c++, p2++)
	{
	  putc(select[c], dap_lst);
	  dap_obs[dap_ono].do_str[param2n][p2] = select[c];
	}
      dap_obs[dap_ono].do_str[param2n][p2] = '\0';
      while (select[c] == ' ')
	c++;
      if (sel[p] != '!')
	{
	  strcpy(dap_obs[dap_ono].do_str[typen], "ESTIMATE");
	  strcpy(dap_obs[dap_ono].do_str[param1n], "");
	  dap_obs[dap_ono].do_dbl[covn] = allparam[p];
	  output();
	  s++;
	}
      putc('\n', dap_lst);
    }
  putc('\n', dap_lst);
  /* now output covariance matrix into dataset */
  strcpy(dap_obs[dap_ono].do_str[typen], "COVAR");
  for (c = 0; select[c] == ' '; c++)
    ;
  for (p = 0, s = 0; p < nparam; p++)
    {
      if (selcodes[p] != '1')
	{
	  for (++c; select[c] == ' '; c++)
	    ;
	}
      while (select[c] == ' ')
	c++;
      for (c1 = 0; select[c1] == ' '; c1++)
	;
      for (p1 = 0, s1 = 0; p1 < nparam; p1++)
	{
	  if (sel[p] != '!' && sel[p1] != '!')
	    dap_obs[dap_ono].do_dbl[covn] = info[s][s1];
	  if (sel[p1] != '!')
	    s1++;
	  if (selcodes[p1] != '1')
	    {
	      for (++c1; select[c1] == ' '; c1++)
		;
	    }
	  if (sel[p] != '!' && sel[p1] != '!')
	    {
	      for (p2 = 0; select[c1] && select[c1] != ' '; c1++, p2++)
		dap_obs[dap_ono].do_str[param2n][p2] = select[c1];
	      dap_obs[dap_ono].do_str[param2n][p2] = '\0';
	      c0 = c;
	      if (select[c0] == '?')
		{
		  for (c0++; select[c0] == ' '; c0++)
		    ;
		}
	      for (p2 = 0; select[c0] && select[c0] != ' '; c0++, p2++)
		dap_obs[dap_ono].do_str[param1n][p2] = select[c0];
	      dap_obs[dap_ono].do_str[param1n][p2] = '\0';
	      output();
	    }
	  while (select[c1] == ' ')
	    c1++;
	}
      while (select[c] && select[c] != ' ')
	c++;
      if (sel[p] != '!')
	s++;
    }
  dap_ono = 0;
  dap_free(x, "");
  dap_free(xch, "");
  dap_free(infomem, "");
  dap_free(info, "");
}

void categ(char *dname, char *varlist, char *auxvarlist, double (*expect)(),
	   double *param, char *select, char *part, char *trace)
{
  int p;
  char *filset;	/* name of dataset with no missing cells */
  char *filarg;	/* argument for dataset for FILL */
  char *catset;	/* name of dataset for tables of observed and fitted values */
  char *covset;	/* name of dataset for covariance matrix */
  int param1n, param2n, covn;	/* indices to covset variables */
  int paramlen1, paramlen;	/* length and maximum length of parameter name */
  char paramstr[12];	/* string for declaring parameter name variables */
  char *partstr;	/* for declaring part variables in covset */
  int *varv;
  int *partv, *partv2;	/* indexes of part variables for catset and covset */
  int ncvar; /* number of classification variables */
  int navar; /* number of auxiliary variables */
  int nvar; /* ncvar + navar */
  int npart;
  int more;
  int nparam;	/* number of parameters identified in select */
  char *selcodes;	/* string to hold '1', '!', '?' codes */
  double *tabmem;
  int v;
  int ncell;
  int s;

  varv = (int *) dap_malloc(sizeof(int) * dap_maxvar, "dap_maxvar");
  partv = (int *) dap_malloc(sizeof(int) * dap_maxvar, "dap_maxvar");
  partv2 = (int *) dap_malloc(sizeof(int) * dap_maxvar, "dap_maxvar");
  filarg = dap_malloc(strlen(varlist) + strlen(part) + 8, "");
  strcpy(filarg, "FILL ");
  for (s = 0; varlist[s] == ' '; s++)
    ;	/* skip leading blanks before count arg */
  for (v = 5; varlist[s] && varlist[s] != ' '; )
    filarg[v++] = varlist[s++];	/* copy in count arg */
  filarg[v++] = ':';
  strcpy(filarg + v, part);	/* part vars need to come first */
  strcat(filarg, " ");
  strcat(filarg, varlist + s);
  filset = dap_malloc(strlen(dname) + 5, "");
  strcpy(filset, dname);
  strcat(filset, ".fil");
  dataset(dname, filset, filarg);
  catset = dap_malloc(strlen(dname) + 5, "");
  strcpy(catset, dname);
  strcat(catset, ".cat");
  covset = dap_malloc(strlen(dname) + 5, "");
  strcpy(covset, dname);
  strcat(covset, ".cov");
  /* find maximum length of parameter names */
  for (s = 0, paramlen = 0; select[s]; )
    {
      while (select[s] == ' ' || select[s] == '?' || select[s] == '!')
	s++;
      for (paramlen1 = 0; select[s] && select[s] != ' '; s++)
	paramlen1++;
      if (paramlen1 > paramlen)
	paramlen = paramlen1;
    }
  dap_ono = 0;
  inset(filset);
  ncvar = dap_list(varlist, varv, dap_maxvar);
  navar = dap_list(auxvarlist, varv + ncvar, dap_maxvar - ncvar);
  nvar = ncvar + navar;
  for (v = 1; v < nvar; v++)
    {
      if (dap_obs[0].do_len[varv[v]] != DBL)
	{
	  fprintf(dap_err, "(categ) classification or auxiliary variable not of type double: %s\n",
		  dap_obs[0].do_nam[varv[v]]);
	  exit(1);
	}
    }
  npart = dap_list(part, partv, dap_maxvar);
  /* now set up variables for covariance dataset */
  dap_ono = 1;
  dap_clearobs((char *) NULL);	/* set up dap_obs, make _type_ variable */
  /* this will bomb if a parameter name is more than 99 characters long */
  sprintf(paramstr, "_param1_ %d", paramlen);
  param1n = dap_vd(paramstr, 0);
  sprintf(paramstr, "_param2_ %d", paramlen);
  param2n = dap_vd(paramstr, 0);
  covn = dap_vd("_cov_ -1", 0);
  partstr = dap_malloc(strlen(part) + 1, "");
  for (v = 0; v < npart; v++)
    {
      strcpy(partstr, dap_obs[0].do_nam[partv[v]]);
      sprintf(partstr + strlen(partstr), " %d", dap_obs[0].do_len[partv[v]]);
      partv2[v] = dap_vd(partstr, 1);
    }
  outset(covset, "");
  /* now back to catset */
  dap_ono = 0;
  outset(catset, "");
  tabmem = (double *) dap_malloc(sizeof(double) * nvar * dap_maxcell, "");
  tab = (double **) dap_malloc (sizeof(double *) * dap_maxcell, "");
  for (ncell = 0; ncell < dap_maxcell; ncell++)
    tab[ncell] = tabmem + ncell * nvar;
  selcodes = dap_malloc(strlen(select) + 1, "");
  nparam = selparse(select, selcodes);
  allparam = (double *) dap_malloc(sizeof(double) * nparam, "");
  sel = selcodes;
  if (index(selcodes, '?'))
    {
      selred = dap_malloc(nparam + 1, "");
      for (s = 0; selcodes[s]; s++)
	{
	  if (selcodes[s] == '?')
	    selred[s] = '!';
	  else
	    selred[s] = selcodes[s];
	}
      selred[s] = '\0';
    }
  else
    selred = NULL;
  for (p = 0; p < nparam; p++)
    allparam[p] = param[p];
  for (ncell = 0, more = 1; more; )
    {
      more = step();
      if (dap_newpart(partv, npart))
	{
	  dap_swap();
	  dap_head(partv, npart);
	  categ1(tab, ncell, varv, nvar, expect, param, select, selcodes,
		 param1n, param2n, covn, partv, partv2, npart, trace);
	  dap_swap();
	  ncell = 0;
	  for (p = 0; p < nparam; p++)
	    allparam[p] = param[p];
	}
      if (more)
	{
	  if (ncell < dap_maxcell)
	    {
	      for (v = 0; v < nvar; v++)
		tab[ncell][v] = dap_obs[0].do_dbl[varv[v]];
	      ncell++;
	    }
	  else
	    {
	      fputs("(categ) too many cells\n", dap_err);
	      exit(1);
	    }
	}
    }
  if (selred)
    {
      dap_free(selred, "");
      selred = NULL;
    }
  dap_free(filarg, "");
  dap_free(varv, "");
  dap_free(partv, "");
  dap_free(partv2, "");
  dap_free(filset, "");
  dap_free(catset, "");
  dap_free(covset, "");
  dap_free(partstr, "");
  dap_free(tabmem, "");
  dap_free(tab, "");
  dap_free(allparam, "");
  dap_free(selcodes, "");
}

/* compute expected cell counts from the parameters and the
 * values of the class vars, which specify the cell
 */

/* this is the coded list of parameters for llexpect to use,
 * set up by loglin:
 * paramlist[p][c] = level of class var c in param p
 *                   range is 0 to maxval[c], -1 indicates absent
 * maxval[c] = highest level of class var c (note: levels are type double)
 */
static int **paramlist;
static double *maxval;
static int numparam;
static int nclass;

static double llexpect(double *param, double *class)
{
  int p;		/* parameter number for paramlist */
  int c;		/* class number for paramlist */
  int neg[MAXCLASS];	/* to take care of constraints/absence: neg[c] is 0 or 1
			 * depending on whether class[c] == maxval[c], for constraints
			 */
  double sign;	/* sign of term = 1.0 if even number of negs in term, -1.0 if odd */
  int match;	/* if class[c] not maxed out, did value of class[c] match term? */
  double logc;	/* log of expected count in cell */

  /* incorporate constraints */
  for (c = 0; c < nclass; c++)
    neg[c] = (class[c] == maxval[c]);
  /* param[0] is always mu */
  for (logc = param[0], p = 1; p < numparam; p++)
    {
      for (sign = 1.0, match = 1, c = 0; c < nclass; c++)
	{
	  if (paramlist[p][c] >= 0)	/* if class c in the term */
	    {
	      if (neg[c])
		sign *= -1.0;
	      else
		match &= (paramlist[p][c] == (int) class[c]);
	    }
	}
      if (match)
	logc += sign * param[p];
    }
  return exp(logc);
}

static int findclass(char *cname, char **class)
{
  int c;	/* index to class */

  for (c = 0; c < nclass; c++)
    {
      if (!strcmp(cname, class[c]))
	return c;
    }
  return -1;
}

/* llparse parses the models and indicates the terms in the models:
 * term[i] = 0, 1, 2 if the term whose bit pattern given by i is
 * in neither model, model1 only, model1 and model0.
 * Returns highest numbered term that actually appears.
 */
static int llparse(char **class, int nterm, unsigned int *pattern,
		   char *model0, char *model1, int *term)
{
  int classlen1;	/* length of one class var name */
  int classlen;	/* max length of one class var name */
  int nt;		/* index to term */
  int c;		/* index to class */
  int l;		/* index to class list */
  int cm;		/* index to classmem */
  char *oneclass;	/* class var extracted from model */
  int oneterm;	/* bit pattern from term in model */
  int m;		/* index to model */
  int t, t1;	/* indexes to term */
  int firstclass;	/* for putting *'s in error message: first class found? */

  for (c = 0, classlen = 0; c < nclass; c++)
    {
      if ((classlen1 = strlen(class[c])) > classlen)
	classlen = classlen1;
    }
  oneclass = dap_malloc(classlen + 1, "");
  /* now process terms in model1 */
  for (t = 0; t < nterm; t++)
    term[t] = 0;
  nterm = 0;	/* innocent until proven... */
  for (m = 0; model1[m] == ' '; m++)
    ;
  for (oneterm = 0; model1[m]; )
    {
      for (c = 0; model1[m] && model1[m] != '*' && model1[m] != ' '; m++)
	oneclass[c++] = model1[m];
      oneclass[c] = '\0';
      while (model1[m] == ' ')
	m++;
      c = findclass(oneclass, class);
      if (c < 0)
	{
	  fprintf(dap_err,
		  "(llparse) Unknown class variable %s in model %s\n",
		  oneclass, model1);
	  exit(1);
	}
      oneterm |= pattern[c];
      if (model1[m] != '*')	/* finished a term, record it */
	{
	  term[oneterm] = 1;
	  if (oneterm > nterm)
	    nterm = oneterm;
	  oneterm = 0;
	}
      else
	m++;
      while (model1[m] == ' ')
	m++;
    }
  /* now fill in the implicit terms for model1 */
  /* now this could be seen as wasteful, but we are wasting so little... */
  for (t1 = 0; t1 <= nterm; t1++)
    {
      if (term[t1])
	{
	  for (t = 0; t < nterm; t++)
	    {
	      if (!(t & ~t1))
		term[t] = 1;
	    }
	}
    }
  /* now let's see who's in model0 also */
  for (m = 0; model0[m] == ' '; m++)
    ;
  for (oneterm = 0; model0[m]; )
    {
      for (c = 0; model0[m] && model0[m] != '*' && model0[m] != ' '; m++)
	oneclass[c++] = model0[m];
      oneclass[c] = '\0';
      while (model0[m] == ' ')
	m++;
      c = findclass(oneclass, class);
      if (c < 0)
	{
	  fprintf(dap_err,
		  "(llparse) Unknown class variable %s in model %s\n",
		  oneclass, model0);
	  exit(1);
	}
      oneterm |= pattern[c];
      if (model0[m] != '*')	/* finished a term, record it */
	{
	  if (!term[oneterm])
	    {
	      fputs("(llparse) Term in model0 (", dap_err);
	      for (c = 0, firstclass = 1; c < nclass; c++)
		{
		  if (!(pattern[c] & ~oneterm))
		    {
		      if (firstclass)
			firstclass = 0;
		      else
			fputs("*", dap_err);
		      fprintf(dap_err, "%s", class[c]);
		    }
		}
	      fprintf(dap_err, ") not in in model1 (%s)\n", model1);
	      exit(1);
	    }
	  term[oneterm] = 2;
	  oneterm = 0;
	}
      else
	m++;
      while (model0[m] == ' ')
	m++;
    }
  /* now fill in the implicit terms for model0 */
  /* now this could be seen as wasteful, but we are wasting so little... */
  for (t1 = 0; t1 <= nterm; t1++)
    {
      if (term[t1] == 2)
	{
	  for (t = 0; t < nterm; t++)
	    {
	      if (!(t & ~t1))
		term[t] = 2;
	    }
	}
    }
  dap_free(oneclass, "");
  return nterm;
}

typedef struct node	/* for linked list of class var values */
{
  char *value;	/* the string */
  struct node *next;
} valnode;

/* Loglinear models
 * varlist = count classvar1 ...
 * model0, model1 = space separated terms, factors in terms separated by *
 * part = partitioning vars
 */
void loglin(char *fname, char *varlist, char *model0, char *model1, char *part)
{
  char *fnamefil;		/* copy of fname with empty cells filled */
  char *filarg;		/* variable names for FILL */
  char *fname1;		/* copy of fname to use for categ, which requires doubles
			 * instead of strings for classification variables
			 */
  char *catname;		/* name of output file of categ, to copy back to fname1
				 * to put strings back in for doubles
				 */
  char *varlist1;		/* copy of varlist, with each name, except that of count var,
				 * preceded by a '_'
				 */
  char *outlist;		/* varlist for fname1 */
  char *vardef;		/* for calling dap_vd to declare varlist1 variables */
  int nvar;		/* number of vars in varlist */
  int l, l1;		/* indexes to varlist, varlist1 */
  int vd;			/* index to vardef */
  int *classv;		/* indexes of part and class vars in varlist and varlist1 */
  int npart;		/* number of part vars */
  int c, cc;		/* indexes to class arrays */
  int nv;			/* for stepping through class var list */
  int coff;		/* offset to class vars in varlist */
  double *maxval1;	/* to check that (external) maxval doesn't change between parts! */
  int maxmaxval;		/* max of maxvals */
  int nvl;		/* index to maxval1 and extern maxval */
  int firstpart;		/* flag: first part? */
  int more;		/* for stepping through dataset */
  double oneval;		/* temporary for convenience */
  int *term;		/* terms present in model0 and model1, either explicitly or
			 * by default
			 */
  int nterm;		/* number of terms in model1 */
  double *param;		/* parameters for model */
  int termparam;		/* number of params for one term */
  int nparam0;		/* tentative number of parameters, (external) numparam is actual */
  char *classmem;		/* memory for class array */
  char **class;		/* the names of the class variables */
  int cm;			/* index to classmem */
  char *select;		/* selection string for param */
  int sellen;		/* length of selection string */
  int termlen;		/* length of term in selection string */
  char *selterm;		/* one term of select */
  int s;			/* index to select */
  int *sub;		/* subscript */
  unsigned int *pattern;	/* list of bit patterns for class vars */
  int t;			/* index to terms */
  int *paramlistmem;	/* memory for (external) paramlist */
  int p;			/* index to (external) paramlist */
  valnode **classval;	/* linked lists of class values */
  valnode **endcv;	/* point to end of classval */
  int *maxlen;		/* max length of any class value */
  int onelen;		/* length of one class value */
  char formstr[8];	/* "  %-xxs" + '\0' */
  valnode *nodeptr;	/* for stepping through node list */

  fnamefil = dap_malloc(strlen(fname) + 5, "");
  strcpy(fnamefil, fname);
  strcat(fnamefil, ".fil");
  filarg = dap_malloc(strlen(varlist) + strlen(part) + 8, "");
  strcpy(filarg, "FILL ");
  for (s = 0; varlist[s] == ' '; s++)
    ;	/* skip leading blanks before count arg */
  for (l = 5; varlist[s] && varlist[s] != ' '; )
    filarg[l++] = varlist[s++];	/* copy in count arg */
  filarg[l++] = ':';
  strcpy(filarg + l, part);	/* part vars need to come first */
  strcat(filarg, " ");
  strcat(filarg, varlist + s);
  dataset(fname, fnamefil, filarg);
  fname1 = dap_malloc(strlen(fname) + 5, "");
  strcpy(fname1, fname);
  strcat(fname1, ".llm");
  catname = dap_malloc(strlen(fname1) + 5, "");
  strcpy(catname, fname1);
  strcat(catname, ".cat");

  /* count the vars so that we know how long to make varlist1 */
  for (l = 0, nvar = 0; varlist[l]; )
    {
      while (varlist[l] == ' ')
	l++;
      if (varlist[l])
	{
	  nvar++;
	  while (varlist[l] && varlist[l] != ' ')
	    l++;
	}
    }
  /* nclass is external */
  nclass = nvar - 1;
  /* don't need a +1 for varlist1 or outlist because first variable,
   * the counts, doesn't need a '_'
   */
  varlist1 = dap_malloc(strlen(varlist) + nvar + 2, "");
  outlist = dap_malloc(strlen(varlist) + nvar + strlen(part) + 2, "");
  /* don't even need this much for vardef because we're going to
   * declare one variable at a time with " -1", but definitely safe
   */
  vardef = dap_malloc(strlen(varlist) + 4, "");
  classv = (int *) dap_malloc(sizeof(int) * dap_maxvar, "dap_maxvar");
  /* classval[c] = pointer to first node in list of values for class var c */
  classval = (valnode **) dap_malloc(sizeof(valnode *) * nclass, "");
  endcv = (valnode **) dap_malloc(sizeof(valnode *) * nclass, "");
  /* and maxlen[c] = max length of value for class var c */
  maxlen = (int *) dap_malloc(sizeof(int) * nclass, "");

  inset(fnamefil);

  /* part vars go in outlist, not in varlist1 */
  npart = dap_list(part, classv, dap_maxvar);
  /* here comes the count variable */
  for (l = 0; varlist[l] == ' '; l++)
    ;
  for (l1 = 0; varlist[l] && varlist[l] != ' '; )
    {
      varlist1[l1] = varlist[l];
      outlist[l1++] = varlist[l++];
    }
  coff = l;
  /* use varlist + coff to skip count var */
  dap_list(varlist + coff, classv + npart, dap_maxvar - npart);
  if (nclass > MAXCLASS)
    {
      fprintf(dap_err, "(loglin) Number of classification variables (%d) exceeds %d.\n",
	      nclass, MAXCLASS);
      exit(1);
    }
  /* check that count variable is of type double */
  varlist1[l1] = '\0';	/* this is temporary */
  if ((c = dap_varnum(varlist1)) < 0)
    {
      fprintf(dap_err, "(loglin) Count variable %s unknown.\n", varlist1);
      exit(1);
    }
  if (dap_obs[0].do_len[c] >= 0)
    {
      fprintf(dap_err, "(loglin) Count variable %s not of type double.\n", varlist1);
      exit(1);
    }
  /* check that class vars are all strings */
  for (c = 0; c < nclass; c++)
    {
      if (dap_obs[0].do_len[classv[npart + c]] <= 0)
	{
	  fprintf(dap_err, "(loglin) Classification variable %s not a string.\n",
		  dap_obs[0].do_nam[classv[npart + c]]);
	  exit(1);
	}
    }
  /* now the rest, leave space in classv for old class vars */

  /* going to need class variable names as array */
  classmem = dap_malloc(strlen(varlist + coff) + 1, "");
  /* this is a bit wasteful of space, price for saving would be time */
  class = (char **) dap_malloc(sizeof(char *) * nclass, "");

  for (c = 0, cm = 0; varlist[l]; )
    {
      while (varlist[l] == ' ')
	l++;
      if (varlist[l])
	{
	  varlist1[l1] = ' ';
	  outlist[l1++] = ' ';
	  varlist1[l1] = '_';
	  outlist[l1++] = '_';
	  vardef[0] = '_';
	  class[c] = classmem + cm;
	  for (vd = 1; varlist[l] && varlist[l] != ' '; l++)
	    {
	      classmem[cm++] = varlist[l];
	      vardef[vd++] = varlist[l];
	      varlist1[l1] = varlist[l];
	      outlist[l1++] = varlist[l];
	    }
	  vardef[vd] = '\0';
	  classmem[cm++] = '\0';
	  strcat(vardef, " -1");
	  classv[npart + nclass + c++] = dap_vd(vardef, 0);
	}
    }
  varlist1[l1] = '\0';
  outlist[l1] = '\0';
  strcat(outlist, " ");
  strcat(outlist, part);

  outset(fname1, outlist);

  maxval = (double *) dap_malloc(sizeof(double) * nclass, "");
  maxval1 = (double *) dap_malloc(sizeof(double) * nclass, "");
  for (nvl = 0; nvl < nclass; nvl++)
    maxval1[nvl] = 0.0;
  /* have to convert string classification into double for categ
   * and later print out a translation table for the class var values, too.
   */
  for (c = 0; c < nclass; c++)
    {
      dap_obs[0].do_dbl[classv[npart + nclass + c]] = 0.0;
      maxlen[c] = 0;
      classval[c] = NULL;
    }
  for (firstpart = 1, more = 1; more; )
    {
      more = step();
      /* first check if maxval changes between parts */
      if (dap_newpart(classv, npart))	/* new part */
	{
	  /* record maxval for first part */
	  if (firstpart)
	    {
	      for (nvl = 0; nvl < nclass; nvl++)
		maxval[nvl] = maxval1[nvl];
	      firstpart = 0;
	    }
	  else	/* else check for changes */
	    {
	      for (nvl = 0; nvl < nclass; nvl++)
		{
		  if (maxval[nvl] != maxval1[nvl])
		    {
		      fprintf(dap_err,
			      "(loglin) Variable %s has different numbers of levels in different parts of dataset %s\n",
			      dap_obs[0].do_nam[classv[npart + nvl]],
			      fname);
		      exit(1);
		    }
		}
	    }
	  for (nvl = 0; nvl < nclass; nvl++)
	    {
	      maxval1[nvl] = 0.0;
	      dap_obs[0].do_dbl[classv[npart + nclass + nvl]] = 0.0;
	    }
	}
      /* now update number of values; nv is the number of variables, not the index */
      if (more)
	{
	  if (dap_newpart(classv, npart))	/* first record of new part */
	    nv = nclass + 1;	/* fake it by setting nv */
	  else
	    {
	      for (nv = 1; nv <= nclass; nv++)
		{
				/* partition on part vars and old class vars */
		  if (dap_newpart(classv, npart + nv))
		    break;
		}
	    }
	  /* at this point, nv - 1 is the index of the one that has new value,
	   * except if nv - 1 == nclass, it's first record of dataset
	   */
	  if (nv <= nclass)	/* not first record of dataset */
	    {
	      /* increment new class vars */
	      dap_obs[0].do_dbl[classv[npart + nclass + nv - 1]] += 1.0;
	      oneval = dap_obs[0].do_dbl[classv[npart + nclass + nv - 1]];
	      if (oneval > 99.0)
		{
		  fprintf(dap_err, "(loglin) Number of levels (%g) for %s exceeds maximum (100)\n",
			  oneval + 1.0,
			  dap_obs[0].do_nam[classv[npart + nclass + nv - 1]]);
		  exit(1);
		}
	      if (oneval > maxval1[nv - 1])	/* got a new one */
		{
		  maxval1[nv - 1] = oneval;
		  onelen = strlen(dap_obs[0].do_str[classv[npart + nv - 1]]);
		  if (onelen > maxlen[nv - 1])
		    maxlen[nv - 1] = onelen;
		  if (firstpart)
		    {	/* already got first nodes */
		      endcv[nv - 1]->next = (valnode *)
			dap_malloc(sizeof(valnode), "");
		      endcv[nv - 1] = endcv[nv - 1]->next;
		      endcv[nv - 1]->value = dap_malloc(onelen + 1, "");
		      endcv[nv - 1]->next = NULL;
		      strcpy(endcv[nv - 1]->value,
			     dap_obs[0].do_str[classv[npart + nv - 1]]);
		    }
		}
	    }
	  else if (firstpart)		/* is first record */
	    {
	      for (nvl = 0; nvl < nclass; nvl++)
		{
		  classval[nvl] = (valnode *) dap_malloc(sizeof(valnode), "");
		  endcv[nvl] = classval[nvl];
		  onelen = strlen(dap_obs[0].do_str[classv[npart + nvl]]);
		  if (onelen > maxlen[nvl])
		    maxlen[nvl] = onelen;
		  endcv[nvl]->value = dap_malloc(onelen + 1, "");
		  endcv[nvl]->next = NULL;
		  strcpy(endcv[nvl]->value,
			 dap_obs[0].do_str[classv[npart + nvl]]);
		}
	    }
	  for (c = nv; c < nclass; c++)
	    {
	      if (dap_obs[0].do_dbl[classv[npart + nclass + c]] !=
		  maxval1[c])
		{
		  fprintf(dap_err,
			  "(loglin) Variable %s has different numbers of levels\n",
			  dap_obs[0].do_nam[classv[npart + c]]);
		  exit(1);
		}
	      dap_obs[0].do_dbl[classv[npart + nclass + c]] = 0.0;
	    }
	  output();
	}
    }

  /* now show numerical values of class var values */
  dap_head(NULL, 0);
  fputs("Loglinear model:\nnumerical indexes of classification variables\n\n", dap_lst);
  fputs("Number", dap_lst);
  for (maxmaxval = 0, c = 0; c < nclass; c++)
    {
      onelen = strlen(class[c]);
      if (maxlen[c] < onelen)
	maxlen[c] = onelen;
      sprintf(formstr, "  %%-%ds", maxlen[c]);
      fprintf(dap_lst, formstr, class[c]);
      if (((int) maxval[c]) > maxmaxval)
	maxmaxval = ((int) maxval[c]);
    }
  putc('\n', dap_lst);
  fputs("------", dap_lst);
  for (c = 0; c < nclass; c++)
    {
      putc(' ', dap_lst);
      putc(' ', dap_lst);
      for (cc = 0; cc < maxlen[c]; cc++)
	putc('-', dap_lst);
      /* this is so we can preserve classval for later */
      endcv[c] = classval[c];
    }
  putc('\n', dap_lst);
  for (cc = 0; cc <= maxmaxval; cc++)
    {
      fprintf(dap_lst, "%6d", cc + 1);
      for (c = 0; c < nclass; c++)
	{
	  if (endcv[c])
	    {
	      sprintf(formstr, "  %%-%ds", maxlen[c]);
	      fprintf(dap_lst, formstr, endcv[c]->value);
	      endcv[c] = endcv[c]->next;
	    }
	  else
	    {
	      sprintf(formstr, "  %%%ds", maxlen[c]);
	      fprintf(dap_lst, formstr, "");
	    }
	}
      putc('\n', dap_lst);
    }
  putc('\n', dap_lst);

  for (nterm = 1, nv = 0; nv < nclass; nv++)
    nterm *= 2;
  term = (int *) dap_malloc(sizeof(int) * nterm, "");
  pattern = (int *) dap_malloc(sizeof(int) * nclass, "");
  for (c = 1, pattern[0] = 1; c < nclass; c++)
    pattern[c] = 2 * pattern[c - 1];
  nterm = llparse(class, nterm, pattern, model0, model1, term);
  /* Start with _mu, which is why sellen starts at 5: "_mu " and for final '\0'. */
  for (nparam0 = 1, sellen = 5, t = 1; t <= nterm; t++)
    {
      if (term[t])
	{
	  for (termparam = 1, c = 0, termlen = 0; c < nclass; c++)
	    {
	      if (!(pattern[c] & ~t))
		{
		  termparam *= (int) maxval[c];
				/* + 4 for ':' and '*' and 2 digits */
		  termlen += strlen(class[c]) + 4;
		}
	    }
	  nparam0 += termparam;
	  /* + 2 allows for space, and possible '?'
	   */
	  sellen += termparam * (termlen + 2);
	}
    }
  param = (double *) dap_malloc(sizeof(double) * nparam0, "");
  paramlistmem = (int *) dap_malloc(sizeof(int) * nparam0 * nclass, "");
  /* paramlist is external */
  paramlist = (int **) dap_malloc(sizeof(int *) * nparam0, "");
  for (p = 0; p < nparam0; p++)
    paramlist[p] = paramlistmem + p * nclass;
  select = dap_malloc(sellen, "");
  selterm = dap_malloc(sellen, "");	/* overkill, but so what? */
  /* now go back and create select string */
  sub = (int *) dap_malloc(sizeof(int) * nclass, "");
  /* param[0] is always mu; start numparam at 0 because we increment when
   * we find a term, not afterward
   */
  for (t = 1, strcpy(select, "_mu"), numparam = 0; t <= nterm; t++)
    {
      selterm[0] = ' ';
      selterm[1] = ' ';
      if (term[t])
	{
	  if (term[t] == 2 || !model0[0])
	    selterm[1] = ' ';
	  else
	    selterm[1] = '?';
	  selterm[2] = '\0';
	  for (c = 0; c < nclass; c++)
	    {
	      if (!(pattern[c] & ~t))
		{
		  if (!selterm[2])
		    strcat(selterm, class[c]);
		  else
		    {
		      strcat(selterm, "*");
		      strcat(selterm, class[c]);
		    }
		}
	    }
	  /* now we got the term, need subscripts */
	  for (c = 0; c < nclass; c++)
	    sub[c] = 1;
	  do	{
	    numparam++;
	    strcat(select, selterm);
	    for (cc = 0; cc < nclass; cc++)
	      {
		if (!(pattern[cc] & ~t))
		  {
		    strcat(select, ":");
		    sprintf(select + strlen(select), "%d", sub[cc]);
		    paramlist[numparam][cc] = sub[cc] - 1;
		  }
		else
		  paramlist[numparam][cc] = -1;
	      }
	    for (c = nclass - 1; c >= 0; c--)
	      {
		if (!(pattern[c] & ~t) && sub[c] < (int) maxval[c])
		  {
		    sub[c]++;
		    for (cc = c + 1; cc < nclass; cc++)
		      sub[cc] = 1;
		    break;
		  }
	      }
	  } while (c >= 0);
	}
    }
  numparam++;	/* to give count instead of highest number */
  param[0] = 1.0;
  for (p = 1; p < numparam; p++)
    param[p] = 0.0;

  categ(fname1, varlist1, "", &llexpect, param, select, part, "");

  /* tables are now in catname, going to copy back to fname1 and
   * translate the numerical values back to strings.
   */

  inset(catname);
  /* first need to declare the class vars without the leading '_' */
  /* OK, so maxlen may be larger than necessary at this point because
   * it was possibly increased to accomodate class var name for table.
   */
  for (c = 0; c < nclass; c++)
    {
      strcpy(vardef, class[c]);
      sprintf(vardef + strlen(vardef), " %d", maxlen[c]);
      classv[c] = dap_vd(vardef, 0);
    }

  outset(fname1, "");

  /* need to get indices of numerical class vars; classv has dap_maxvar slots */
  /* +1 because I'm too lazy to skip the count variable */
  dap_list(varlist1, classv + nclass, nclass + 1);

  while (step())
    {
      for (c = 0; c < nclass; c++)
	{
	  for (nodeptr = classval[c], nvl = 0;
	       nvl < (int) dap_obs[0].do_dbl[classv[nclass + 1 + c]];
	       nvl++)
	    nodeptr = nodeptr->next;
	  strcpy(dap_obs[0].do_str[classv[c]], nodeptr->value);
	}
      output();
    }

  dap_free(fnamefil, "");
  dap_free(filarg, "");
  dap_free(fname1, "");
  dap_free(catname, "");
  dap_free(varlist1, "");
  dap_free(outlist, "");
  dap_free(vardef, "");
  dap_free(classv, "");
  dap_free(maxval, "");
  dap_free(maxval1, "");
  dap_free(term, "");
  dap_free(param, "");
  dap_free(select, "");
  dap_free(selterm, "");
  dap_free(sub, "");
  dap_free(classmem, "");
  dap_free(class, "");
  dap_free(pattern, "");
  dap_free(paramlistmem, "");
  dap_free(paramlist, "");
  for (c = 0; c < nclass; c++)
    {
      while (classval[c])
	{
	  dap_free(classval[c]->value, "");
	  endcv[c] = classval[c]->next;
	  dap_free(classval[c], "");
	  classval[c] = endcv[c];
	}
    }
  dap_free(classval, "");
  dap_free(endcv, "");
  dap_free(maxlen, "");
}

/* estimate: use a estimate and covariance matrix dataset such as that
 * produced by categ() to define and test parameters
 */

static int findparam(char *pname, char *param[], int nparam)
{
  int p;

  for (p = 0; p < nparam; p++)
    {
      if (!strcmp(pname, param[p]))
	return p;
    }
  return -1;
}

void estimate(char *fname, char *parameters, char *definitions, char *part)
{
  char *parammem;       /* memory to hold parameter names */
  char **param;		/* pointers to parameter names */
  int start, end;	/* for stepping through 'definitions' */
  int nparam;		/* number of parameters */
  int p, p1;		/* index to parameter arrays */
  int defstate;		/* 0 = new def, 1 = got '=' */
  double *defmem;	/* memory for def */
  double **def;		/* definition for each parameter: each entry contains the
                         * coefficient for the parameter in the def or 0 if not in the def
			 */
  double coeff;		/* coefficient of def entry */
  double sign;		/* sign of the coefficient */
  double place;		/* for conversion from string to double */
  int pnum1, pnum2, pnum3;	/* parameter numbers */
  int defnum;		/* number of parameter being defined */
  int ninput;		/* number of parameters to read in */
  double *estimate;	/* vector of estimates */
  double *covmem;	/* memory for covariance matrix */
  double **cov;		/* covariance matrix */
  int typen, param1n, param2n, covn;	/* indices of input variables */
  int more;		/* for checking if there are more data lines to read in */
  int *partv;		/* indices of the partitioning variables */
  int npart;		/* number of partitioning variables */

  parammem = dap_malloc(strlen(parameters) + strlen(definitions) + 1, "");
  /* divide by 2 because params are separated; almost always still too many */
  /* this is just (an overestimate of) the max, not the real nparam */
  nparam = (strlen(parameters) + strlen(definitions)) / 2;
  param = (char **) dap_malloc(sizeof(char *) * nparam, "");
  defmem = (double *) dap_malloc(sizeof(double) * nparam * nparam, "");
  def = (double **) dap_malloc(sizeof(double *) * nparam, "");
  for (p = 0; p < nparam; p++)
    {
      def[p] = defmem + p * nparam;
      for (p1 = 0; p1 < nparam; p1++)
	def[p][p1] = 0.0;	/* clear them all to start */
    }
  /* get parameter names from 'parameters' */
  for (start = 0; parameters[start] == ' '; start++)
    ;
  for (nparam = 0, p = 0; parameters[start]; start = end)
    {
      /* tentatively copy param from 'parameters' to param list */
      param[nparam++] = parammem + p;
      for (end = start; parameters[end] && parameters[end] != ' '; )
	parammem[p++] = parameters[end++];
      parammem[p++] = '\0';
      while (parameters[end] == ' ')
	end++;
    }
  ninput = nparam;
  /* now get parameter names from 'definitions' */
  for (start = 0; definitions[start] == ' '; start++)
    ;	/* get to first parameter */
  for (defstate = 0; definitions[start]; start = end)
    {
      /* tentatively copy param from definition to param list */
      param[nparam] = parammem + p;
      if (definitions[start] == '+' || definitions[start] == '-')
	{
	  sign = 2.0 * ((double) (definitions[start] == '+')) - 1.0;
	  for (start++; definitions[start] == ' '; start++)
	    ;
	}
      if (definitions[start] == '.' ||
	  ('0' <= definitions[start] && definitions[start] <= '9'))
	{
	  for (coeff = 0.0, place = 0.0;
	       definitions[start] == '.' ||
		 ('0' <= definitions[start] && definitions[start] <= '9');
	       start++)
	    {
	      if (definitions[start] == '.')
		{
		  if (place > 0.0)
		    {
		      fprintf(dap_err,
			      "(estimate) bad coefficient in definition: %s\n",
			      definitions + start);
		      exit(1);
		    }
		  else
		    place = 1.0;
		}
	      else
		{
		  coeff = 10.0 * coeff + (double) (definitions[start] - '0');
		  if (place > 0.0)
		    place *= 10.0;
		}
	    }
	  coeff *= sign;
	  if (place > 0.0)
	    coeff /= place;
	  while (definitions[start] == ' ')
	    start++;
	}
      else
	coeff = sign;
      for (end = start;
	   definitions[end] && definitions[end] != ' ' &&
	     definitions[end] != '=' && definitions[end] != '+' &&
	     definitions[end] != '-'; )
	parammem[p++] = definitions[end++];
      parammem[p++] = '\0';
      if ((pnum1 = findparam(param[nparam], param, nparam)) < 0)	/* it's new */
	nparam++;	/* count it */
      else
	p = param[nparam] - parammem;	/* reset p */
      while (definitions[end] == ' ')
	end++;
      switch (defstate)
	{
	case 0:		/* new definition */
	  if (definitions[end] == '=')
	    {
	      defstate = 1;
	      for (end++; definitions[end] == ' '; end++)
		;
	    }
	  else
	    {
	      fprintf(dap_err,
		      "(estimate) definition starting at %s missing an =\n",
		      definitions + start);
	      exit(1);
	    }
	  defnum = nparam - 1;
	  sign = 1.0;	/* default for first parameter in definition */
	  break;
	case 1:
	  if (pnum1 < 0)
	    {
	      fprintf(dap_err,
		      "(estimate) undefined parameter %s in definition\n",
		      param[nparam - 1]);
	      exit(1);
	    }
	  if (sign == 0.0)
	    {
	      fprintf(dap_err,
		      "(estimate) missing sign or coefficient for parameter %s in definition\n",
		      param[nparam - 1]);
	      exit(1);
	    }
	  def[defnum][pnum1] = coeff;
	  if (definitions[end] != '+' && definitions[end] != '-')
	    /* end of definition */
	    defstate = 0;
	  sign = 0.0;
	  break;
	}
    }
  estimate = (double *) dap_malloc(sizeof(double) * nparam, "");
  covmem = (double *) dap_malloc(sizeof(double) * nparam * nparam, "");
  cov = (double **) dap_malloc(sizeof(double *) * nparam, "");
  for (p = 0; p < nparam; p++)
    cov[p] = covmem + nparam * p;
  inset(fname);
  if ((typen = dap_varnum("_type_")) < 0)
    {
      fprintf(dap_err, "(estimate) missing _type_ variable in dataset %s\n", fname);
      exit(1);
    }
  if ((param1n = dap_varnum("_param1_")) < 0)
    {
      fprintf(dap_err, "(estimate) missing _param1_ variable in dataset %s\n", fname);
      exit(1);
    }
  if ((param2n = dap_varnum("_param2_")) < 0)
    {
      fprintf(dap_err, "(estimate) missing _param2_ variable in dataset %s\n", fname);
      exit(1);
    }
  if ((covn = dap_varnum("_cov_")) < 0)
    {
      fprintf(dap_err, "(estimate) missing _cov_ variable in dataset %s\n", fname);
      exit(1);
    }
  partv = (int *) dap_malloc(sizeof(int) * dap_maxvar, "");
  npart = dap_list(part, partv, dap_maxvar);
  for (pnum1 = 0; pnum1 < nparam; pnum1++)
    {
      estimate[pnum1] = 0.0 / 0.0;
      for (pnum2 = 0; pnum2 < nparam; pnum2++)
	cov[pnum1][pnum2] = 0.0 / 0.0;
    }
  for (more = 1; more; )
    {
      more = step();
      if (dap_newpart(partv, npart))
	{
	  dap_swap();
	  dap_head(partv, npart);
	  fputs("    Estimate           SE  Parameter\n", dap_lst);
	  for (pnum1 = ninput; pnum1 < nparam; pnum1++)
	    {
	      /* compute estimate of defined parameter */
	      estimate[pnum1] = 0.0;
	      for (pnum2 = 0; pnum2 < pnum1; pnum2++)
		{
		  if (def[pnum1][pnum2] && !isfinite(estimate[pnum2]))
		    {
		      fprintf(dap_err,
			      "(estimate) estimate for parameter %s not in dataset %s\n",
			      param[pnum2], fname);
		      exit(1);
		    }
		  estimate[pnum1] += def[pnum1][pnum2] * estimate[pnum2];
		}
	      /* compute variance of defined parameter */
	      cov[pnum1][pnum1] = 0.0;
	      for (pnum2 = 0; pnum2 < pnum1; pnum2++)
		{
		  for (pnum3 = 0; pnum3 < pnum1; pnum3++)
		    {
		      coeff = def[pnum1][pnum2] * def[pnum1][pnum3];
		      cov[pnum1][pnum1] += coeff * cov[pnum2][pnum3];
		    }
		}
	      /* compute covariance of def. param. with others */
	      for (pnum2 = 0; pnum2 < pnum1; pnum2++)
		{
		  cov[pnum1][pnum2] = 0.0;
		  for (pnum3 = 0; pnum3 < pnum1; pnum3++)
		    {
		      coeff = def[pnum1][pnum2];
		      cov[pnum1][pnum2] += coeff * cov[pnum2][pnum3];
		    }
		  cov[pnum2][pnum1] = cov[pnum1][pnum2];
		}
	    }
	  for (pnum1 = ninput; pnum1 < nparam; pnum1++)
	    {
	      fprintf(dap_lst, "%12g %12g  %s =",
		      estimate[pnum1], sqrt(cov[pnum1][pnum1]), param[pnum1]);
	      for (pnum2 = 0; pnum2 < nparam; pnum2++)
		{
		  if (def[pnum1][pnum2] != 0.0)
		    {
		      putc(' ', dap_lst);
		      if (def[pnum1][pnum2] > 0.0)
			putc('+', dap_lst);
		      if (def[pnum1][pnum2] == 1.0)
			fprintf(dap_lst, "%s", param[pnum2]);
		      else if (def[pnum1][pnum2] == -1.0)
			fprintf(dap_lst, " -%s", param[pnum2]);
		      else
			fprintf(dap_lst, "%g%s",
				def[pnum1][pnum2], param[pnum2]);
		    }
		}
	      putc('\n', dap_lst);
	    }
	  dap_swap();
	  for (pnum1 = 0; pnum1 < nparam; pnum1++)
	    {
	      estimate[pnum1] = 0.0 / 0.0;
	      for (pnum2 = 0; pnum2 < nparam; pnum2++)
		cov[pnum1][pnum2] = 0.0 / 0.0;
	    }
	}
      if (more)
	{
	  if (!strcmp(dap_obs[dap_ono].do_str[typen], "ESTIMATE"))
	    {
	      if ((pnum2 = findparam(dap_obs[dap_ono].do_str[param2n],
				     param, ninput)) >= 0)
		estimate[pnum2] = dap_obs[dap_ono].do_dbl[covn];
	    }
	  else if (!strcmp(dap_obs[dap_ono].do_str[typen], "COVAR"))
	    {
	      if ((pnum1 = findparam(dap_obs[dap_ono].do_str[param1n],
				     param, ninput)) >= 0 &&
		  (pnum2 = findparam(dap_obs[dap_ono].do_str[param2n],
				     param, ninput)) >= 0)
		cov[pnum1][pnum2] = dap_obs[dap_ono].do_dbl[covn];
	    }
	}
    }
  dap_free(parammem, "");
  dap_free(param, "");
  dap_free(defmem, "");
  dap_free(def, "");
  dap_free(estimate, "");
  dap_free(covmem, "");
  dap_free(cov, "");
  dap_free(partv, "");
}
