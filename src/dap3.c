/* dap3.c -- plotting routines */

/*  Copyright (C) 2001, 2002, 2003, 2005 Free Software Foundation, Inc.
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
#include "ps.h"
#include "dap_make.h"

extern dataobs dap_obs[];
extern FILE *dap_lst;
extern FILE *dap_log;
extern FILE *dap_err;
extern char *dap_title;
extern char *dap_dapname;

static void plot1(double x[], double y[], int nobs,
		  char xvar[], char yvar[], int markv[], int nmark,
		  pict p[], pict a[], int pn, char style[],
		  double (*xfunct)(), double (*yfunct)(), int doaxes)
{
  int titlelen;
  static char *title0 = NULL;
  char *title1;
  int overlay;
  int n;
  int v;
  int s;
  char *axspec;
  int t;
  double pictr;

  dap_swap();
  if (dap_title)
    titlelen = strlen(dap_title) + 1;
  else
    titlelen = 0;
  if (!title0)
    {
      title0 = dap_malloc(dap_linelen + titlelen + 1, "dap_linelen");
      if (dap_title)
	strcpy(title0, dap_title);
    }
  title1 = dap_malloc(dap_linelen + titlelen + 1, "dap_linelen");
  for (s = 0; style[s] == ' '; s++)
    ;
  overlay = 0;
  if (style[s] == 'o')
    {
      for (s++; style[s] == ' '; s++)
	;
      for ( ; '0' <= style[s] && style[s] <= '9'; s++)
	overlay = 10 * overlay + style[s] - '0';
      if (!overlay)
	overlay = -1;
    }
  while (style[s] == ' ')
    s++;
  axspec = dap_malloc(3 + strlen(style), "");
  strcpy(axspec, style + s);
  if (overlay == -1)
    {
      if (pn)
	pict_initpict(p + pn - 1, p + pn);
      else
	pict_initpict(NULL, p + pn);
      pict_initpict(p + pn, a);
    }
  else if (overlay)
    {
      if (pn % overlay)
	pict_initpict(p + pn - 1, p + pn);
      else
	pict_initpict(NULL, p + pn);
      pict_initpict(p + pn, a + (pn / overlay));
    }
  else
    {
      pict_initpict(NULL, p + pn);
      pict_initpict(p + pn, a + pn);
    }
  for (n = 0; n < nobs; n++)
    pict_point(p + pn, x[n], y[n]);
  strcpy(p[pn].pict_type, "CIRC");
  title1[0] = '\0';
  if (dap_title)
    strcpy(title1, dap_title);
  if (overlay >= 0 && nmark)
    {
      if (dap_title)
	strcat(title1, "\n");
      for (v = 0; v < nmark; v++)
	{
	  if (v)
	    strcat(title1, " ");
	  if (dap_obs[0].do_len[markv[v]] == DBL)
	    sprintf(title1 + strlen(title1), "%g",
		    dap_obs[0].do_dbl[markv[v]]);
	  else if (dap_obs[0].do_len[markv[v]] == INT)
	    sprintf(title1 + strlen(title1), "%d",
		    dap_obs[0].do_int[markv[v]]);
	  else
	    strcat(title1, dap_obs[0].do_str[markv[v]]);
	}
      if (overlay > 0)
	{
	  if (!(pn % overlay))
	    strcpy(title0, title1);
	  else
	    {
	      for (t = 0; title0[t] && title0[t] == title1[t]; t++)
		;
	      title1[t] = '\0';
	    }
	}
    }
  if (doaxes)
    {
      if (overlay == -1)
	{
	  pictr =
	    0.05 * pict_autoaxes(p, xvar, yvar, axspec, xfunct, yfunct, title1, PORTRAIT);
	  while (pn >= 0)
	    p[pn--].pict_r = pictr;
	}
      else if (overlay)
	{
	  pictr = 0.05 * pict_autoaxes(p + (pn / overlay) * overlay,
				       xvar, yvar, axspec, xfunct, yfunct, title1, PORTRAIT);
	  while (pn >= (pn / overlay) * overlay)
	    p[pn--].pict_r = pictr;
	}
      else
	p[pn].pict_r = 0.05 * pict_autoaxes(p + pn, xvar, yvar,
					    axspec, xfunct, yfunct, title1, PORTRAIT);
    }
  dap_swap();
  if (doaxes)
    {
      dap_free(title0, "");
      title0 = NULL;
    }
  dap_free(title1, "");
  dap_free(axspec, "");
}

/* Parse variable names with optional axis renaming
 * xyvar = original variable names with optional axis renaming
 * xyname = variable names together without optional axis renaming
 * xname, yname = final axis names, yname optionally NULL
 */
static void plotparse(char *xyvar, char *xyname, char *xname, char *yname)
{
  int n;		/* index to xyvar */
  int xyn;	/* index to xyname */
  int xn, yn;	/* indexes to xname, yname */
  int ystart;	/* starting position of y variable name in xyvar */

  for (n = 0; xyvar[n] == ' '; n++)	/* skip spaces */
    ;
  /* first copy actual x variable name to xyname */
  for (xyn = 0; xyvar[n] && xyvar[n] != ' ' && xyvar[n] != '`'; n++)
    {
      if (xyn < dap_namelen)
	xyname[xyn++] = xyvar[n];
      else
	{
	  fprintf(dap_err, "(plotparse) X-variable name too long: %s\n", xyvar);
	  exit(1);
	}
    }
  strncpy(xname, xyvar, n);	/* and copy that to xname */
  xname[n] = '\0';
  xyname[xyn++] = ' ';		/* leave a space before y variable name */
  while (xyvar[n] == ' ')		/* skip unnecessary spaces */
    n++;
  if (xyvar[n] == '`')		/* if axis renaming specified */
    {
      for (n++; xyvar[n] == ' '; n++)
	;
      /* replace xname with that */
      for (xn = 0; xyvar[n] && xyvar[n] != '`'; n++)
	{
	  if (xn < dap_linelen)
	    xname[xn++] = xyvar[n];
	  else
	    {
	      fprintf(dap_err, "(plotparse) X-axis label too long: %s\n", xyvar);
	      exit(1);
	    }
	}
      while (xyvar[n] == ' ')
	n++;
      if (xyvar[n] == '`')
	{
	  for (n++; xyvar[n] == ' '; n++)
	    ;
	}
      else
	{
	  fprintf(dap_err, "(plotparse) Expected ` after x-axis label: %s\n", xyvar);
	  exit(1);
	}
      xname[xn] = '\0';
    }
  ystart = n;	/* mark start of y variable name */
  /* and copy y variable name to xyname */
  for ( ; xyvar[n] && xyvar[n] != ' ' && xyvar[n] != '`'; n++)
    {
      if (xyn < 2 * (dap_namelen + 1))
	xyname[xyn++] = xyvar[n];
      else
	{
	  fprintf(dap_err, "(plotparse) Y-variable name too long: %s\n", xyvar);
	  exit(1);
	}
    }
  xyname[xyn] = '\0';
  if (yname)		/* if y variable name requested, too */
    {
      strncpy(yname, xyvar + ystart, n);	/* start with variable name */
      yname[n - ystart] = '\0';
      xyname[xyn++] = ' ';
      while (xyvar[n] == ' ')
	n++;
      if (xyvar[n] == '`')	/* but if renaming, rename */
	{
	  for (n++; xyvar[n] == ' '; n++)
	    ;
	  for (yn = 0; xyvar[n] && xyvar[n] != '`'; n++)
	    {
	      if (yn < dap_linelen)
		yname[yn++] = xyvar[n];
	      else
		{
		  fprintf(dap_err, "(plotparse) Y-axis label too long: %s\n", xyvar);
		  exit(1);
		}
	    }
	  yname[yn] = '\0';
	}
    }
  xyname[xyn] = '\0';
}

pict *plot(char *fname, char *xyvar, char *marks,
	   char *style, double (*xfunct)(), double (*yfunct)(), int nplots)
{
  pict *p;
  pict *a;
  int *markv;
  int nmark;
  int nobs;
  int nnan;
  static double *x, *y;
  int pn;
  int xyv[2];
  char *xyname;
  char *xname;
  char *yname;
  int s;
  int overlay;
  int more;

  markv = (int *) dap_malloc(sizeof(int) * dap_maxvar, "");
  p = (pict *) dap_malloc(2 * nplots * sizeof(pict), "");
  a = p + nplots;
  x = (double *) dap_malloc(dap_maxval * sizeof(double), "");
  y = (double *) dap_malloc(dap_maxval * sizeof(double), "");
  if (!fname)
    {
      fputs("(plot) No dataset name given.\n", dap_err);
      exit(1);
    }
  inset(fname);
  if (!xyvar)
    {
      fputs("(plot) No x and y variable list given.\n", dap_err);
      exit(1);
    }
  xyname = dap_malloc(2 * (dap_namelen + 1), "");
  xname = dap_malloc(dap_linelen + 1, "");
  yname = dap_malloc(dap_linelen + 1, "");
  plotparse(xyvar, xyname, xname, yname);
  nmark = dap_list(marks, markv, dap_maxvar);
  if (dap_list(xyname, xyv, dap_maxvar) != 2)
    {
      fprintf(dap_err, "(plot) Invalid x and y variable list: %s\n", xyvar);
      exit(1);
    }
  if (dap_obs[0].do_len[xyv[0]] != DBL)
    {
      fprintf(dap_err, "(plot) x-variable is not double variable: %s\n",
	      dap_obs[0].do_nam[xyv[0]]);
      exit(1);
    }
  if (dap_obs[0].do_len[xyv[1]] != DBL)
    {
      fprintf(dap_err, "(plot) y-variable is not double variable: %s\n",
	      dap_obs[0].do_nam[xyv[1]]);
      exit(1);
    }
  for (s = 0; style[s] == ' '; s++)
    ;
  overlay = 0;
  if (style && style[s] == 'o')
    {
      for (s++; style[s] == ' '; s++)
	;
      for ( ; '0' <= style[s] && style[s] <= '9'; s++)
	overlay = 10 * overlay + style[s] - '0';
      if (!overlay)
	overlay = -1;
    }
  for (nobs = 0, nnan = 0, pn = 0, more = 1; more; )
    {
      more = step();
      if (dap_newpart(markv, nmark))
	{
	  if (pn < nplots)
	    {
	      plot1(x, y, nobs, xname, yname,
		    markv, nmark, p, a, pn, style, xfunct, yfunct,
		    (!more || !overlay || (overlay > 0 && !((pn + 1) % overlay))));
	      pn++;
	      if (nnan > 0)
		fprintf(dap_log, "(plot) %d NaNs\n", nnan);
	    }
	  else
	    {
	      fprintf(dap_err,
		      "(plot) More plots than specified by nplots (%d)\n",
		      nplots);
	      exit(1);
	    }
	  nobs = 0;
	  nnan = 0;
	}
      if (nobs < dap_maxval)
	{
	  x[nobs] = dap_obs[0].do_dbl[xyv[0]];
	  y[nobs] = dap_obs[0].do_dbl[xyv[1]];
	  if (isfinite(x[nobs]) && isfinite(y[nobs]))
	    nobs++;
	  else
	    nnan++;
	}
      else
	{
	  fprintf(dap_err, "(plot) Too many points\n");
	  exit(1);
	}
    }
  dap_free(x, "");
  dap_free(y, "");
  dap_free(markv, "");
  dap_free(xyname, "");
  dap_free(xname, "");
  dap_free(yname, "");
  return p;
}

static int dblcmp(double *x, double *y)
{
  if (*x < *y)
    return -1;
  if (*x > *y)
    return 1;
  return 0;
}

#define SQRTHALF 0.707106781186547524401
#define INVSQ2PI 0.398942280401432677940
#define INVSQRTPI 0.56418958354775628
#define TWOOSQRTPI 1.12837916709551257
#define SQRTPI 1.77245385090551602729
#define SIXOVERPI 1.90985931710274381

static double comb(int n, int k) /* n combination k */
{
  double dn, dk;
  double c;

  for (c = 1.0, dn = (double) n, dk = (double) k; dk >= 1.0;
       dn -= 1.0, dk -= 1.0)
    c *= dn / dk;
  return c;
}

static double dnmk;
static double dkm1;

/* To be able to integrate on a finite range -1 to 1,
 * we obtain a normal variate x as t / sqrt(1 - t * t), where -1 < t < 1.
 * Then orderf(t) is x times the prob density of the order statistic of x,
 * except for the combinatorial coefficient, but in terms of t, so that
 * we can integrate to find the expected value.
 */
static double orderf(double t)
{
  double x;
  double tmp1, tmp2;

  if (t == -1.0 || t == 1.0)
    return 0.0;
  tmp1 = 1.0 - t * t;
  x = t / sqrt(tmp1);
  tmp2 = dkm1 * log(probz(x)) + dnmk * log(probz(-x)) - 0.5 * x * x;
  if (isfinite(tmp2))
    return exp(tmp2) * t / (tmp1 * tmp1);
  return 0.0;
}

#define NSTEPS 512

static void geta(double a[], int n) /* get (negative of) Shaprio-Wilk "a" array */
{
  int k; /* index to "a" array */
  double dn; /* number of points, as double */
  double c;

  if (n < 7) /* get "exact" values for "a" array */
    {
      switch (n)
	{
	case 3:
	  a[0] = 0.707107;
	  break;
	case 4:
	  a[0] = 0.687155;
	  a[1] = 0.166787;
	  break;
	case 5:
	  a[0] = 0.664647;
	  a[1] = 0.241337;
	  break;
	case 6:
	  a[0] = 0.643105;
	  a[1] = 0.280635;
	  a[2] = 0.0875196;
	  break;
	}
      return;
    }
  /* Here we use the approximations on page 117 of
   * Royston, Appl. Statist. (1982), 31, No. 2, pp. 115-124
   */
  for (k = 0; k < n / 2; k++)
    { /* first get the expected values of the order statistics of n normal variates */
      dnmk = (double) (n - k - 1);
      dkm1 = (double) k;
      a[k] = ((double) k + 1) * comb(n, k + 1) * INVSQ2PI *
	dap_simp(&orderf, -1.0, 1.0, NSTEPS);
    }
  dn = (double) n;
  if (n <= 20)
    {
      for (a[0] = SQRTHALF; dn > 2.0; dn -= 2.0)
	a[0] *= (dn - 2.0) / (dn - 1.0);
      if (dn == 2.0)
	a[0] *= TWOOSQRTPI;
      else
	a[0] *= SQRTPI;
    }
  else
    {
      for (a[0] = SQRTHALF; dn > 1.0; dn -= 2.0)
	a[0] *= (dn - 1.0) / dn;
      if (dn == 1.0)
	a[0] *= TWOOSQRTPI;
      else
	a[0] *= SQRTPI;
    }
  for (c = 0.0, k = 1; k < n / 2; k++)
    c += a[k] * a[k];
  c = sqrt((1.0 - 2.0 * a[0]) / (2.0 * c));
  a[0] = -sqrt(a[0]);
  for (k = 1; k < n / 2; k++)
    a[k] *= c;
}

/* Approximate the probability that W <= w0:
 * For n = 3: direct calculation;
 * For 4 <= n <= 6: transformation to n = 3, then direct calculation;
 * For 7 <= n: normalizing transformation
 */

static double clambda1[3] =
{ 0.118898, 0.133414, 0.327907 };
static double clambda2[6] =
{ 0.480385, 0.318828, 0.0, -0.0241665, 0.00879701, 0.002989646 };
static double clogmu1[4] =
{ -0.37542, -0.492145, -1.124332, -0.199422 };
static double clogmu2[6] =
{ -1.91487, -1.37888, -0.04183209, 0.1066339, -0.03513666, -0.01504614 };
static double clogsigma1[4] =
{ -3.15805, 0.729399, 3.01855, 1.558776 };
static double clogsigma2[7] =
{ -3.73538, -1.015807, -0.331885, 0.1773538, -0.01638782, -0.03215018, 0.003852646 };

static double au[3][2][5] =
{ { { -1.26233, 1.87969, 0.0649583, -0.0475604, -0.0139682 },
    { -0.287696, 1.78953, -0.180114, 0.0, 0.0 } },
  { { -2.28135, 2.26186, 0.0, 0.0, -0.00865763 },
    { -1.63638, 5.60924, -3.63738, 1.08439, 0.0 } },
  { { -3.30623, 2.76287, -0.83484, 1.20857, -0.507590 },
    { -5.991908, 21.04575, -24.58061, 13.78661, -2.835295 } }
};

static double lowhigh[3][2] =
{ { -3.8, 8.6 }, { -3.0, 5.8 }, { -4.0, 5.4 } };

/* evaluate a polynomial of degree n */
static double poly(double c[], double x, int n)
{
  double p;

  for (p = c[n]; --n >= 0; )
    p = p * x + c[n];
  return p;
}

static double probw(int n, double w0, double a1)
{
  double u; /* transformed from w0 */
  double d, lambda, logmu, logsigma;
  double y;
  double eps;
  int r; /* range index */

  if (n == 3)
    return SIXOVERPI * (asin(sqrt(w0)) - asin(sqrt(0.75)));
  if (n >= 7)
    {
      if (n <= 20)
	d = 3.0;
      else
	d = 5.0;
      d = log((double) n) - d;
      if (n <= 20)
	{
	  lambda = poly(clambda1, d, 2);
	  logmu = poly(clogmu1, d, 3);
	  logsigma = poly(clogsigma1, d, 3);
	}
      else
	{
	  lambda = poly(clambda2, d, 5);
	  logmu = poly(clogmu2, d, 5);
	  logsigma = poly(clogsigma2, d, 6);
	}
      y = pow(1.0 - w0, lambda);
      return probz(-(y - exp(logmu)) / exp(logsigma));
    }
  else
    {
      if (w0 >= 1.0)
	return 1.0;
      eps = a1 * a1 * (1.0 + 1.0 / ((double) (n - 1)));
      if (w0 <= eps)
	return 0.0;
      u = log((w0 - eps) / (1.0 - w0));
      if (w0 < lowhigh[n - 4][0] || w0 > lowhigh[n - 4][1])
	return 0.0 / 0.0;
      if (u < 1.4)
	r = 0;
      else
	{
	  r = 1;
	  u = log(u);
	  if (!isfinite(u))
	    return 0.0 / 0.0;
	}
      u = poly(au[n - 4][r], u, 4);
      if (r)
	u = exp(u);
      u = exp(u);
      return SIXOVERPI * (asin(sqrt((u + 0.75) / (1.0 + u))) - asin(sqrt(0.75)));
    }
}

/* Display, if requested, q-q plot, and perform the Shapiro-Wilk
 * test for normality, which is reported in the lst file.
 */
static void normal1(double x[], double y[], int nobs,
		    char varname[], char varlabel[], int markv[], int nmark,
		    pict *p, pict *l, pict *a, int pn)
{
  int titlelen; /* length of title string, +1, for caption */
  int r; /* index to sorted values (of y), i.e., rank */
  double dr; /* r converted to double */
  double dnobsp25; /* number of obs + 1/4, as double, for denom for computing x */
  double sum; /* for incremental computation of corrected sum of squares */
  double ss; /* corrected sum of squares */
  double vtmp; /* temp for incremental computation of corrected sum of squares */
  double tmp; /* temp for incremental computation of corrected sum of squares */
  double sd; /* standard deviation: needed for slope of line in q-q plot */
  double minx, maxx; /* min and max values of x, for q-q plot */
  double *swa; /* array of Shapiro-Wilk "a" coefficients */
  int k; /* index of "a" array */
  double w; /* Shapiro-Wilk statistic */
  double prob; /* probability that W <= computed Shapiro-Wilk statistic */
  int v;
  char *caption;
  int (*cmp)(); /* address of function for comparing doubles through pointers */

  dap_swap(); /* get back to part of file we want to work on */
  cmp = &dblcmp;
  if (dap_title)
    titlelen = strlen(dap_title) + 1;
  else
    titlelen = 0;
  if (p) /* if q-q plot requested, we have pointer to linked list of picts
	  * and we need to allocate caption string: 47??
          */
    caption = dap_malloc(dap_linelen + titlelen + 47, "dap_linelen");
  qsort((void *) y, (size_t) nobs, (size_t) sizeof(double), cmp);
  /* q-q plot has denominator n + 1/4, numerator rank - 3/8 */
  dnobsp25 = ((double) nobs) + 0.25;
  for (r = 0, sum = 0.0, ss = 0.0, minx = 0.0, maxx = 0.0; r < nobs; r++)
    { /* for each y, compute an x for plotting: inv std norm(numerator/denominator) */
      dr = (double) r;
      x[r] = -zpoint((dr + 0.625) / dnobsp25);
      if (x[r] < minx)
	minx = x[r];
      if (x[r] > maxx)
	maxx = x[r];
      vtmp = y[r];
      if (r)
	{ /* incremental method for computing corrected sum of squares */
	  tmp = sum - dr * vtmp;
	  ss += tmp * tmp / (dr * (dr + 1.0));
	}
      sum += vtmp;
    }
  sd = sqrt(ss / ((double) (nobs - 1))); /* need sd to plot line for q-q plot */
  if (sd == 0.0)
    {
      fprintf(dap_err, "(normal1) Zero standard deviation for %s\n", varname);
      exit(1);
    }
  if (3 <= nobs && nobs <= 2000)
    {
      swa = (double *) dap_malloc(nobs / 2 * sizeof(double), "");
      geta(swa, nobs); /* compute Shapiro-Wilk "a" coefficients */
      for (w = 0.0, k = 0; k < nobs / 2; k++) /* compute W */
	w += swa[k] * (y[k] - y[nobs - 1 - k]);
      w *= w / ss;
      if ((prob = probw(nobs, w, swa[0])) < 0.001)
	prob = 0.001;
      dap_free(swa, "");
      if (p)	/* if q-q plot requested */
	sprintf(caption, "q-q plot: W|0| = %.4f, P[W < W|0|] = %.3f", w, prob);
      dap_head(markv, nmark);
      fprintf(dap_lst,
	      "Shapiro-Wilk test for %s:\nW0 = %.4f, P[W < W0] = %.3f\n",
	      varname, w, prob);
    }
  else if (p)	/* if q-q plot requested */
    strcpy(caption, "q-q plot");
  if (p && dap_title)	/* if q-q plot requested and title given */
    {
      strcat(caption, "\n");
      strcat(caption, dap_title);
    }
  if (p && nmark)	/* if q-q plot requested and dataset is partitioned */
    {
      for (v = 0; v < nmark; v++)
	{
	  strcat(caption, "\n");
	  if (dap_obs[0].do_len[markv[v]] == DBL)
	    sprintf(caption + strlen(caption), "%g",
		    dap_obs[0].do_dbl[markv[v]]);
	  else if (dap_obs[0].do_len[markv[v]] == INT)
	    sprintf(caption + strlen(caption), "%d",
		    dap_obs[0].do_int[markv[v]]);
	  else
	    strcat(caption, dap_obs[0].do_str[markv[v]]);
	}
    }
  if (p)	/* if q-q plot requested */
    {
      pict_initpict(NULL, p + pn);
      pict_initpict(p + pn, l + pn);
      pict_initpict(l + pn, a + pn);
      for (r = 0; r < nobs; r++)
	pict_point(p + pn, x[r], y[r]);
      strcpy(p[pn].pict_type, "CIRC");
      sum /= (double) nobs;
      strcpy(l[pn].pict_type, "LINE");
      pict_line(l + pn, minx, sd * minx + sum, maxx, sd * maxx + sum);
      p[pn].pict_r = 0.05 *
	pict_autoaxes(p + pn, "z", varlabel, "-0 NXDIGITS3", NULL, NULL, caption, PORTRAIT);
      free(caption);
    }
  dap_swap();
}

/* Display, if requested, a q-q plot and perform a Shapiro-Wilk
 * test for normality, which is reported in the lst file.
 */
pict *normal(char *fname, char *variable, char *marks, int nplots)
{
  char *varname;
  char *varlabel;
  int s, t;
  pict *p;	/* the picts for the q-q plots */
  pict *l;	/* the picts for the straight lines in the q-q plots */
  pict *a;	/* the picts for the axes for the q-q plots */
  int *markv;
  int nmark;
  int nobs;
  int nnan;
  double *x, *y;
  int pn;
  int vy;
  int more;

  varname = dap_malloc(dap_namelen + 1, "");
  varlabel = dap_malloc(dap_linelen + 1, "");
  markv = (int *) dap_malloc(sizeof(int) * dap_maxvar, "");
  if (nplots)
    {
      p = (pict *) dap_malloc(3 * nplots * sizeof(pict), "");
      l = p + nplots;
      a = p + 2 * nplots;
    }
  else
    p = (pict *) NULL;
  x = (double *) dap_malloc(dap_maxval * sizeof(double), "");
  y = (double *) dap_malloc(dap_maxval * sizeof(double), "");
  if (!variable)
    {
      fputs("(normal) No variable specified.\n", dap_err);
      exit(1);
    }
  for (t = 0; variable[t] == ' '; t++)
    ;
  for (s = 0; variable[t] && variable[t] != ' ' && variable[t] != '`'; t++)
    {
      if (s < dap_namelen)
	varname[s++] = variable[t];
      else
	{
	  fprintf(dap_err, "(normal) Variable name too long: %s\n", variable);
	  exit(1);
	}
    }
  varname[s] = '\0';
  while (variable[t] == ' ')
    t++;
  s = 0;
  if (variable[t] == '`')
    {
      for (t++ ; variable[t] && variable[t] != ' ' && variable[t] != '`'; t++)
	{
	  if (s < dap_linelen)
	    varlabel[s++] = variable[t];
	  else
	    {
	      fprintf(dap_err, "(normal) Variable label too long: %s\n", variable);
	      exit(1);
	    }
	}
      varlabel[s] = '\0';
    }
  else
    strcpy(varlabel, varname);
  if (!fname)
    {
      fputs("(normal) No dataset name given.\n", dap_err);
      exit(1);
    }
  inset(fname);
  nmark = dap_list(marks, markv, dap_maxvar);
  if ((vy = dap_varnum(varname)) < 0)
    {
      fprintf(dap_err, "(normal) Variable unknown: %s\n", varname);
      exit(1);
    }
  if (dap_obs[0].do_len[vy] != DBL)
    {
      fprintf(dap_err, "(normal) Variable is not double variable: %s\n", varname);
      exit(1);
    }
  for (nobs = 0, nnan = 0, pn = 0, more = 1; more; )
    {
      more = step();
      if (dap_newpart(markv, nmark))
	{
	  if (!nplots || pn < nplots)
	    {
	      normal1(x, y, nobs, varname, varlabel, markv, nmark,
		      p, l, a, pn++);
	      if (nnan > 0)
		fprintf(dap_log, "(normal) %d NaNs\n", nnan);
	    }
	  else
	    {
	      fprintf(dap_err,
		      "(normal) More plots than specified by nplots (%d)\n",
		      nplots);
	      exit(1);
	    }
	  nobs = 0;
	  nnan = 0;
	}
      if (nobs < dap_maxval)
	{
	  y[nobs] = dap_obs[0].do_dbl[vy];
	  if (isfinite(y[nobs]))
	    nobs++;
	  else
	    nnan++;
	}
      else
	{
	  fprintf(dap_err, "(normal) Too many points\n");
	  exit(1);
	}
    }
  dap_free(x, "");
  dap_free(y, "");
  dap_free(varname, "");
  dap_free(varlabel, "");
  dap_free(markv, "");
  return p;
}

static double arint(double x)
{
  double i;
        
  if (fabs(i = rint(x)) == 0.0)
    return 0.0; 
  else    
    return i;
}

#define COUNT 0
#define PERCENT 1
#define FRACTION 2
#define UNSPEC 3

static void histo1(double x[], double xw[][2], int nobs, int varv[], int nbars,
		   char xname[], char *style, double (*xfunct)(),
		   int markv[], int nmark, pict *p, pict *a, int pn)
{
  int titlelen;
  char *caption;
  int s;
  int w; /* index to word */
  char *word;
  char *axspec; /* specification for axes for pict_autoaxes, inherited from style */
  double *h;
  double *part;
  int equal;
  int height;
  int whole;
  double min, max;
  double xlen, xspace;
  static char htitle[19];
  double width;
  double dnobs;
  double dnbars;
  int b; /* index for bars */
  int xn;
  int xnm1;
  int v;
  double maxy;
  int (*cmp)();

  cmp = &dblcmp;
  if (dap_title)
    titlelen = strlen(dap_title) + 1;
  else
    titlelen = 0;
  /* this could bomb, but probably won't */
  caption = dap_malloc(titlelen + dap_linelen + 1, "");
  axspec = dap_malloc(strlen(style) + 1, "");
  word = dap_malloc(dap_namelen + 1, "");
  h = (double *) dap_malloc(sizeof(double) * dap_maxbars, "");
  part = (double *) dap_malloc(sizeof(double) * (dap_maxbars + 1), "");
  if (!nbars)
    {
      fputs("(histo1) Number of bars is zero.\n", dap_err);
      exit(1);
    }
  equal = 1;
  height = UNSPEC;
  whole = 0;
  htitle[0] = '\0';
  if (x)
    {
      qsort((void *) x, (size_t) nobs, (size_t) sizeof(double), cmp);
      part[0] = x[0];
      part[nbars] = x[nobs - 1];
    }
  else
    {
      qsort((void *) xw, (size_t) nobs, (size_t) (2 * sizeof(double)), cmp);
      part[0] = xw[0][0];
      part[nbars] = xw[nobs - 1][0];
    }
  maxy = 0.0;	/* mark as not used */
  axspec[0] = '\0';
  if (style)
    {
      for (s = 0; style[s] == ' '; s++)
	;
      while (style[s])
	{
	  for (w = 0; style[s] && style[s] != ' '; )
	    {
	      if (w < dap_namelen)
		word[w++] = style[s++];
	      else
		{
		  word[w] = '\0';
		  fprintf(dap_err, "(histo1) Style word too long: %s\n", word);
		  exit(1);
		}
	    }
	  word[w] = '\0';
	  if (!strcmp(word, "EQUAL"))
	    equal = 1;
	  else if (!strcmp(word, "VARIABLE"))
	    equal = 0;
	  else if (!strcmp(word, "COUNT"))
	    height = COUNT;
	  else if (!strcmp(word, "PERCENT"))
	    height = PERCENT;
	  else if (!strcmp(word, "FRACTION"))
	    height = FRACTION;
	  else if (!strcmp(word, "ROUND"))
	    whole = 1;
	  else /* info for histo1, but also passed as part of axspec */
	    {
	      strcat(axspec, word);
	      strcat(axspec, " ");
	      if (!strncmp(word, "MINX", 4))
		{
		  if (sscanf(word + 4, "%lf", &part[0]) != 1)
		    {
		      fprintf(dap_err,
			      "(histo1) bad MINX specification: %s\n",
			      word);
		      exit(1);
		    }
		}
	      else if (!strncmp(word, "MAXX", 4))
		{
		  if (sscanf(word + 4, "%lf", &part[nbars]) != 1)
		    {
		      fprintf(dap_err,
			      "(histo1) bad MAXX specification: %s\n",
			      word);
		      exit(1);
		    }
		}
	    }
	  while (style[s] == ' ')
	    s++;
	}
    }
  if (equal)
    {
      switch (height)
	{
	case UNSPEC:
	case COUNT:
	  strcpy(htitle, "Count");
	  break;
	case PERCENT:
	  strcpy(htitle, "Percent");
	  break;
	case FRACTION:
	  strcpy(htitle, "Fraction");
	  break;
	}
    }
  else
    {
      switch (height)
	{
	case COUNT:
	  fputs("(histo1) Can't use count with variable width bars.\n",
		dap_err);
	  exit(1);
	case PERCENT:
	  strcpy(htitle, "Density (Percent)");
	  break;
	case UNSPEC:
	case FRACTION:
	  strcpy(htitle, "Density (Fraction)");
	  break;
	}
    }
  dnobs = (double) nobs;
  dnbars = (double) nbars;
  if (whole)
    {
      xlen = 1e5 / (part[nbars] - part[0]);
      xlen = (arint(xlen * part[nbars]) - arint(xlen * part[0])) / xlen;
      if (xlen >= 1.0)
	{
	  for (xspace = 1.0; dnbars * xspace < xlen; xspace *= dnbars)
	    ;
	  xspace *= ceil(xlen / xspace) / dnbars;
	}
      else
	{
	  for (xspace = 0.1; xspace / nbars > xlen; xspace /= nbars)
	    ;
	  xspace *= ceil(xlen / xspace) / dnbars;
	}
      part[0] = floor(part[0] / xspace) * xspace;
      part[nbars] = ceil(part[nbars] / xspace) * xspace;
    }
  if (equal)
    {
      width = (part[nbars] - part[0]) / dnbars;
      for (b = 1; b < nbars; b++)
	part[b] = part[0] + width * ((double) b);
      for (b = 0; b < nbars; b++)
	h[b] = 0.0;
      for (xn = 0, b = 0; xn < nobs; xn++)
	{
	  if (x)
	    {
	      while (b < nbars && x[xn] > part[b + 1])
		b++;
	      h[b] += 1.0;
	    }
	  else
	    {
	      while (b < nbars && xw[xn][0] > part[b + 1])
		b++;
	      h[b] += xw[xn][1];
	    }
	}
      for (b = 0; b < nbars; b++)
	{
	  switch (height)
	    {
	    case PERCENT:
	      h[b] *= 100.0;
	    case FRACTION:
	      h[b] /= dnobs;
	      break;
	    default:
	      break;
	    }
	}
    }
  else
    {
      for (b = 1, xnm1 = 0; b < nbars; b++)
	{
	  xn = (int) rint(dnobs * ((double) b) / dnbars);
	  if (x)
	    part[b] = x[xn];
	  else
	    part[b] = xw[xn][0];
	  if (part[b] > part[b - 1])
	    h[b] = ((double) (xn - xnm1)) / ((part[b] - part[b - 1]) * dnobs);
	  else
	    h[b] = 0.0;
	  if (height == PERCENT)
	    h[b] *= 100.0;
	  xnm1 = xn;
	}
    }
  pict_initpict(NULL, p + pn);
  pict_initpict(p + pn, a + pn);
  for (b = 0; b < nbars; b++)
    pict_rectangle(p + pn, part[b], 0.0, part[b + 1] - part[b], h[b]);
  caption[0] = '\0';
  if (dap_title)
    strcpy(caption, dap_title);
  if (nmark)
    {
      if (dap_title)
	strcat(caption, "\n");
      for (v = 0; v < nmark; v++)
	{
	  if (v)
	    strcat(caption, " ");
	  if (dap_obs[0].do_len[markv[v]] == DBL)
	    sprintf(caption + strlen(caption), "%g",
		    dap_obs[0].do_dbl[markv[v]]);
	  else if (dap_obs[0].do_len[markv[v]] == INT)
	    sprintf(caption + strlen(caption), "%d",
		    dap_obs[0].do_int[markv[v]]);
	  else
	    strcat(caption, dap_obs[0].do_str[markv[v]]);
	}
    }
  pict_autoaxes(p + pn, xname, htitle, axspec, xfunct, NULL, caption, PORTRAIT);
  dap_free(caption, "");
  dap_free(axspec, "");
  dap_free(word, "");
  dap_free(h, "");
  dap_free(part, "");
}

/* Display histogram */
pict *histogram(char *fname, char *vars, char *marks, int nbars,
		char *style, double (*xfunct)(), int nplots)
{
  pict *p;
  pict *a;
  int *markv;
  int nmark;
  int varv[2];
  int nvar;
  int nobs;
  double *x;
  double (*xw)[2];
  char *xwname;
  char *xname;
  int pn;
  int v;
  int mv;
  int nnan;
  int more;

  markv = (int *) dap_malloc(sizeof(int) * dap_maxvar, "");
  xwname = dap_malloc(2 * (dap_namelen + 1), "");
  xname = dap_malloc(dap_linelen + 1, "");
  p = (pict *) dap_malloc(2 * nplots * sizeof(pict), "");
  a = p + nplots;
  if (!fname)
    {
      fputs("(histogram) No dataset name given.\n", dap_err);
      exit(1);
    }
  inset(fname);
  nmark = dap_list(marks, markv, dap_maxvar);
  if (!vars)
    {
      fputs("(histogram) No variable given.\n", dap_err);
      exit(1);
    }
  plotparse(vars, xwname, xname, NULL);
  nvar = dap_list(xwname, varv, dap_maxvar);
  for (v = 0; v < nvar; v++)
    {
      if (dap_obs[0].do_len[varv[v]] != DBL)
	{
	  fprintf(dap_err, "(histogram) Variable is not double variable: %s\n",
		  dap_obs[0].do_nam[varv[v]]);
	  exit(1);
	}
    }
  if (nvar == 1)
    {
      x = (double *) dap_malloc(dap_maxval * sizeof(double), "");
      xw = (double (*)[2]) NULL;
    }
  else if (nvar == 2)
    {
      xw = (double (*)[2]) dap_malloc(dap_maxval * 2 * sizeof(double), "");
      x = (double *) NULL;
    }
  else
    {
      fprintf(dap_err,
	      "(histogram) Variable list contains more than two variables: %s\n", vars);
      exit(1);
    }
  for (nobs = 0, nnan = 0, pn = 0, more = 1; more; )
    {
      more = step();
      if (dap_newpart(markv, nmark))
	{
	  dap_swap();
	  if (nnan)
	    {
	      fprintf(dap_log, "(histogram) %d missing values for:", nnan);
	      for (mv = 0; mv < nmark; mv++)
		{
		  putc(' ', dap_log);
		  if (dap_obs[0].do_len[markv[mv]] == DBL)
		    fprintf(dap_log, "%g",
			    dap_obs[0].do_dbl[markv[mv]]);
		  else if (dap_obs[0].do_len[markv[mv]] == INT)
		    fprintf(dap_log, "%d",
			    dap_obs[0].do_int[markv[mv]]);
		  else
		    fputs(dap_obs[0].do_str[markv[mv]], dap_log);
		}
	      putc('\n', dap_log);
	    }
	  if (nobs)
	    {
	      if (pn < nplots)
		histo1(x, xw, nobs, varv, nbars, xname,
		       style, xfunct, markv, nmark, p, a, pn++);
	      else
		{
		  fprintf(dap_err,
			  "(histogram) More plots than specified by nplots (%d)\n",
			  nplots);
		  exit(1);
		}
	    }
	  dap_swap();
	  nobs = 0;
	  nnan = 0;
	}
      if (nobs < dap_maxval)
	{
	  if (nvar == 1)
	    {
	      x[nobs] = dap_obs[0].do_dbl[varv[0]];
	      if (isfinite(x[nobs]))
		nobs++;
	      else
		nnan++;
	    }
	  else
	    {
	      xw[nobs][0] = dap_obs[0].do_dbl[varv[0]];
	      xw[nobs][1] = dap_obs[0].do_dbl[varv[1]];
	      if (isfinite(xw[nobs][0]) && isfinite(xw[nobs][1]))
		nobs++;
	      else
		nnan++;
	    }
	}
      else
	{
	  fprintf(dap_err, "(histogram) Too many points\n");
	  exit(1);
	}
    }
  if (nvar == 1)
    dap_free(x, "");
  else
    dap_free(xw, "");
  dap_free(markv, "");
  dap_free(xwname, "");
  dap_free(xname, "");
  return p;
}

/* Compute linear regression with one dependent and one independent
 * variable and plot points, regression line, and confidence region
 * for regression line.
 */
pict *plotlinreg(char *fname, char *ylist0, char *x1list0, char *style,
		 char *marks, int nmarks, double level)
{
  char *ylist;	/* copy of ylist0 without axis renaming, if any */
  char *x1list;	/* copy of x1list0 without axis renaming, if any */
  int l;		/* index to strings */
  int varv[1];
  int typen;	/* index of type variable */
  int sortord[4];	/* sort order for types for plot: 0 = LOWER, 1 = OBS,
			 * 2 = PRED, 3 = UPPER
			 */
  int s;		/* index to sortord */
  char *mnsname;	/* name of dataset for output of means() */
  char *regname;	/* name of dataset for output of linreg() */
  char *srtarg;	/* arguments to sort() */
  char *srtname;	/* name of dataset for output of sort() */
  char *plotvars;	/* variable names to pass to plot */
  char *plotmarks;
  pict *p;
  int pn;
  char *plotstyle;

  ylist = dap_malloc(strlen(ylist0) + 1, "");
  x1list = dap_malloc(strlen(x1list0) + 1, "");
  for (l = 0; ylist0[l] && ylist0[l] != '`'; l++)
    ylist[l] = ylist0[l];
  ylist[l] = '\0';
  for (l = 0; x1list0[l] && x1list0[l] != '`'; l++)
    x1list[l] = x1list0[l];
  x1list[l] = '\0';
  inset(fname);
  if ((typen = dap_varnum("_type_")) < 0)
    {
      fprintf(dap_err, "(plotlinreg) missing type variable in %s\n", fname);
      exit(1);
    }
  step();
  for (s = 0; s < 4; s++)
    sortord[s] = s;
  if (strcmp(dap_obs[0].do_str[typen], "LOWER") < 0)
    {	/* the 'OBS' value will appear first */
      sortord[0] = 1;
      sortord[1] = 0;
    }
  else if (strcmp(dap_obs[0].do_str[typen], "PRED") < 0)
    ;
  else if (strcmp(dap_obs[0].do_str[typen], "UPPER") < 0)
    {	/* the 'OBS' value will appear between 'PRED' and 'UPPER' */
      sortord[1] = 2;
      sortord[2] = 1;
    }
  else
    {
      sortord[1] = 3;
      sortord[2] = 1;
      sortord[3] = 2;
    }
  dap_list(ylist, varv, 1);	/* check that it's only 1 variable */
  dap_list(x1list, varv, 1);	/* check that it's only 1 variable */
  mnsname = dap_malloc(strlen(fname) + 5, "");
  strcpy(mnsname, fname);
  strcat(mnsname, ".mns");
  regname = dap_malloc(strlen(fname) + 5, "");
  strcpy(regname, fname);
  strcat(regname, ".reg");
  srtname = dap_malloc(strlen(regname) + 5, "");
  strcpy(srtname, regname);
  strcat(srtname, ".srt");
  means(fname, x1list, "STEP100", marks);
  linreg(fname, ylist, "", x1list, marks, mnsname, level);
  dataset(fname, regname, "APPEND");
  srtarg = dap_malloc(strlen(marks) + strlen(x1list) + 9, "");
  strcpy(srtarg, marks);
  strcat(srtarg, " _type_ ");
  strcat(srtarg, x1list);
  sort(regname, srtarg, "");
  plotvars = dap_malloc(strlen(x1list0) + strlen(ylist0) + 2, "");
  strcpy(plotvars, x1list0);
  strcat(plotvars, " ");
  strcat(plotvars, ylist0);
  plotmarks = dap_malloc(strlen(marks) + strlen("_type_") + 2, "");
  strcpy(plotmarks, marks);
  strcat(plotmarks, " _type_");
  plotstyle = dap_malloc(strlen(style) + 4, "");
  strcpy(plotstyle, "o4 ");
  strcat(plotstyle, style);
  p = plot(srtname, plotvars, plotmarks, plotstyle, NULL, NULL, 4 * nmarks);
  for (pn = 0; pn < nmarks; pn++)
    {
      strcpy(p[4 * pn + sortord[0]].pict_type, "LINE");
      strcpy(p[4 * pn + sortord[2]].pict_type, "LINE");
      strcpy(p[4 * pn + sortord[3]].pict_type, "LINE");
      p[4 * pn + sortord[0]].pict_dash = 4.0;
      p[4 * pn + sortord[3]].pict_dash = 4.0;
    }
  dap_free(ylist, "");
  dap_free(x1list, "");
  dap_free(mnsname, "");
  dap_free(regname, "");
  dap_free(srtarg, "");
  dap_free(srtname, "");
  dap_free(plotvars, "");
  dap_free(plotmarks, "");
  dap_free(plotstyle, "");
  return p;
}

/* Display results of logistic regression
 */
pict *plotlogreg(char *fname, char *yspec0, char *x1list0, char *style,
		 int ngroups, char *marks, int nmarks,  double level)
{
  char *yspec;	/* yspec0 with axis labeling removed */
  char *x1list;	/* x1list0 with axis labeling removed */
  int varv[3];
  char *trlname;
  int trialsn;
  char varspec[12];
  char *grpname;
  char *grparg;
  char *grpvar;
  char *mnsarg;
  char *mnsname;
  char *lgrname;
  char *srtarg;
  char *srtname;
  char *plotvars;
  char *plotmarks;
  char *casevar;		/* the number of cases */
  char *casevar0;		/* the number of cases, with option axis label */
  int c;
  int cs;
  pict *p;
  int pn;
  char *plotstyle;
  int l0, l;		/* index to variable name strings */

  yspec = dap_malloc(strlen(yspec0) + 1, "");
  x1list = dap_malloc(strlen(x1list0) + 1, "");
  for (l0 = 0, l = 0; yspec0[l0] && yspec0[l0] != '`'; )
    yspec[l++] = yspec0[l0++];
  if (yspec0[l0] == '`')
    {
      for (l0++; yspec0[l0] && yspec0[l0] != '`'; l0++)
	;
      for (l0++; yspec0[l0]; )
	yspec[l++] = yspec0[l0++];
    }
  yspec[l] = '\0';
  for (l = 0; x1list0[l] && x1list0[l] != '`'; l++)
    x1list[l] = x1list0[l];
  x1list[l] = '\0';
  trlname = dap_malloc(strlen(fname) + 5, "");
  strcpy(trlname, fname);
  strcat(trlname, ".trl");
  grpname = dap_malloc(strlen(trlname) + 5, "");
  strcpy(grpname, trlname);
  strcat(grpname, ".grp");
  srtname = dap_malloc(strlen(grpname) + 5, "");
  strcpy(srtname, grpname);
  strcat(srtname, ".srt");
  mnsname = dap_malloc(strlen(srtname) + 5, "");
  strcpy(mnsname, srtname);
  strcat(mnsname, ".mns");
  lgrname = dap_malloc(strlen(fname) + 5, "");
  strcpy(lgrname, fname);
  strcat(lgrname, ".lgr");
  grparg = dap_malloc(strlen(x1list) + 14, "");
  grpvar = dap_malloc(strlen(marks) + strlen(x1list) + 3, "");
  casevar = dap_malloc(strlen(yspec) + 1, "");
  casevar0 = dap_malloc(strlen(yspec0) + 1, "");
  mnsarg = dap_malloc(strlen(yspec) + 12 + strlen(x1list), "");
  srtarg = dap_malloc(strlen(marks) + strlen(x1list) + 9, "");
  plotvars = dap_malloc(strlen(x1list0) + strlen(yspec0) + 2, "");
  plotmarks = dap_malloc(strlen(marks) + strlen("_type_") + 2, "");
  inset(fname);
  dap_list(x1list, varv, 1);	/* check that it's only 1 variable */
  strcpy(grpvar, marks);
  strcat(grpvar, " _");
  strcat(grpvar, x1list);
  strcpy(casevar, yspec);
  for (cs = 0; casevar[cs] == ' '; cs++)
    ;
  for (c = 0; casevar[cs] && casevar[cs] != ' ' && casevar[cs] != '/'; )
    casevar[c++] = casevar[cs++];
  casevar[c] = '\0';
  strcpy(casevar0, yspec0);
  for (cs = 0; casevar0[cs] == ' '; cs++)
    ;
  for (c = 0; casevar0[cs] && casevar0[cs] != '/'; )
    casevar0[c++] = casevar0[cs++];
  casevar0[c] = '\0';

  inset(fname);
  sprintf(varspec, "_ntrials %d", DBL);
  trialsn = dap_vd(varspec, 0);
  outset(trlname, "");
  dap_parsey(yspec, varv);
  while (step())
    {
      if (varv[1] >= 0)	/* number of trials variable */
	dap_obs[0].do_dbl[trialsn] = dap_obs[0].do_dbl[varv[1]];
      else
	dap_obs[0].do_dbl[trialsn] = -varv[1];
      output();
    }

  strcpy(grparg, x1list);
  sprintf(grparg + strlen(grparg), " %d#", ngroups);

  group(trlname, grparg, marks);

  sort(grpname, grpvar, "");

  strcpy(mnsarg, casevar);
  strcat(mnsarg, " _ntrials ");
  strcat(mnsarg, x1list);
  means(srtname, mnsarg, "MEAN", grpvar);

  inset(mnsname);
  outset(grpname, "");
  trialsn = dap_varnum("_ntrials");
  dap_list(casevar, varv, 1);
  while (step())
    {
      dap_obs[0].do_dbl[varv[0]] /= dap_obs[0].do_dbl[trialsn];
      output();
    }

  means(fname, x1list, "STEP100", marks);

  strcpy(mnsname, fname);
  strcat(mnsname, ".mns");

  logreg(fname, yspec, "", x1list, marks, mnsname, level);

  dataset(grpname, lgrname, "APPEND");

  strcpy(srtarg, marks);
  strcat(srtarg, " _type_ ");
  strcat(srtarg, x1list);

  sort(lgrname, srtarg, "");

  strcpy(srtname, lgrname);
  strcat(srtname, ".srt");

  strcpy(plotvars, x1list0);
  strcat(plotvars, " ");
  strcat(plotvars, casevar0);

  strcpy(plotmarks, marks);
  strcat(plotmarks, " _type_");

  plotstyle = dap_malloc(strlen(style) + 4, "");
  strcpy(plotstyle, "o4 ");
  strcat(plotstyle, style);

  p = plot(srtname, plotvars, plotmarks, plotstyle, NULL, NULL, 4 * nmarks);
  for (pn = 0; pn < nmarks; pn ++)
    {
      strcpy(p[4 * pn + 0].pict_type, "LINE");
      strcpy(p[4 * pn + 2].pict_type, "LINE");
      strcpy(p[4 * pn + 3].pict_type, "LINE");
      p[4 * pn + 0].pict_dash = 4.0;
      p[4 * pn + 3].pict_dash = 4.0;
    }
  dap_free(yspec, "");
  dap_free(x1list, "");
  dap_free(trlname, "");
  dap_free(grpname, "");
  dap_free(grparg, "");
  dap_free(grpvar, "");
  dap_free(mnsarg, "");
  dap_free(mnsname, "");
  dap_free(lgrname, "");
  dap_free(srtarg, "");
  dap_free(srtname, "");
  dap_free(plotvars, "");
  dap_free(plotmarks, "");
  dap_free(casevar, "");
  dap_free(casevar0, "");
  dap_free(plotstyle, "");
  return p;
}

/* Construct a pict of means and error bars
 * meanvar0 = name of variable to plot means of, optionally with renaming spec for axis
 * varlist0 = name of variable to classify groups of meanvar0
 * errbar = specifies what error bars represent (SD, SEM, etc.)
 * style = plotting style
 * partvars for partitioned dataset
 * noverlay = ??
 */
pict *plotmeans(char *dataset, char *meanvar0, char *varlist0, char *errbar,
		char *style, char *partvars, int noverlay)
{
  int meanv[1];
  int *partv;
  int npartv;
  char *meanvar;	/* user's meanvar0, truncating any `name spec` */
  char *varlist;	/* user's varlist0, truncating any `name spec` */
  int l;
  char *mnslist;
  char *mnsname;
  char *errname;
  char *srtname;
  char *ebar;
  char *overstr;
  int e;			/* index to ebar */
  double scale;
  int typen;
  double mean;
  double err;
  int n;
  char *srtarg;
  char *plotvars;
  char *plotparts;
  pict *p;
  int more;
  int nparts;
  int pn;

  partv = NULL;
  mean = 0.0;
  err = 0.0;
  meanvar = dap_malloc(strlen(meanvar0) + 1, "");	/* copy meanvar0, truncate `name-spec` */
  strcpy(meanvar, meanvar0);
  for (l = 0; meanvar[l] && meanvar[l] != '`'; l++)
    ;
  meanvar[l] = '\0';
  varlist = dap_malloc(strlen(varlist0) + 1, "");	/* copy varlist0, truncate `name-spec` */
  strcpy(varlist, varlist0);
  for (l = 0; varlist[l] && varlist[l] != '`'; l++)
    ;
  varlist[l] = '\0';
  if (partvars && partvars[0])
    {
      partv = (int *) dap_malloc(sizeof(int) * dap_maxvar, "");
      mnslist = dap_malloc(strlen(varlist) + strlen(partvars) + 2, "");
      strcpy(mnslist, partvars);
      strcat(mnslist, " ");
      strcat(mnslist, varlist);
      plotparts = dap_malloc(strlen(partvars) + 8, "");
      strcpy(plotparts, partvars);
      strcat(plotparts, " _type_");
    }
  else
    {
      mnslist = varlist;
      plotparts = "_type_";
    }
  mnsname = dap_malloc(strlen(dataset) + 5, "");
  strcpy(mnsname, dataset);
  strcat(mnsname, ".mns");
  errname = dap_malloc(strlen(dataset) + 5, "");
  strcpy(errname, dataset);
  strcat(errname, ".err");
  srtname = dap_malloc(strlen(errname) + 5, "");
  strcpy(srtname, errname);
  strcat(srtname, ".srt");
  ebar = dap_malloc(strlen(errbar) + 6, "");
  strcpy(ebar, "MEAN ");
  strcat(ebar, errbar);
  overstr = dap_malloc(8 + strlen(style), "");
  if (noverlay < 1)
    noverlay = 1;
  sprintf(overstr, "o%d %s", 2 * noverlay, style);
  srtarg = dap_malloc(strlen(mnslist) + 8, "");
  if (partvars && partvars[0])
    {
      strcpy(srtarg, partvars);
      strcat(srtarg, " ");
    }
  else
    srtarg[0] = '\0';
  strcat(srtarg, "_type_ ");
  strcat(srtarg, varlist);
  plotvars = dap_malloc(strlen(meanvar0) + strlen(varlist0) + 2, "");
  strcpy(plotvars, varlist0);
  strcat(plotvars, " ");
  strcat(plotvars, meanvar0);
  for (e = 0; errbar[e] == ' '; e++)
    ;
  while (errbar[e] && errbar[e] != ' ')
    e++;
  ebar[e + 5] = '\0';
  while (errbar[e] == ' ')
    e++;
  if (errbar[e])
    {
      if (sscanf(errbar + e, "%lf", &scale) != 1)
	{
	  fprintf(stderr, "%s: bad scale in call to plotmeans: %s\n",
		  dap_dapname, errbar + e);
	  exit(1);
	}
    }
  else
    scale = 1.0;
  means(dataset, meanvar, ebar, mnslist);
  inset(mnsname);
  outset(errname, "");
  dap_list(varlist, meanv, 1);	/* check that there's only one */
  dap_list(meanvar, meanv, 1);
  if (partvars && partvars[0])
    npartv = dap_list(partvars, partv, dap_maxvar);
  else
    npartv = 0;
  if ((typen = dap_varnum("_type_")) < 0)
    {
      fprintf(stderr, "%s: missing _type_ variable for plotmeans\n", dap_dapname);
      exit(1);
    }
  for (n = 0, nparts = 0, more = 1; more; )
    {
      more = step();
      if (more)
	{
	  if (!strcmp(dap_obs[0].do_str[typen], "MEAN"))
	    mean = dap_obs[0].do_dbl[meanv[0]];
	  else
	    err = dap_obs[0].do_dbl[meanv[0]];
	  if (++n == 2)
	    {
	      strcpy(dap_obs[0].do_str[typen], "MEAN");
	      dap_obs[0].do_dbl[meanv[0]] = mean;
	      output();
	      strcpy(dap_obs[0].do_str[typen], "BAR");
	      dap_obs[0].do_dbl[meanv[0]] = mean - err * scale;
	      output();
	      dap_obs[0].do_dbl[meanv[0]] = mean + err * scale;
	      output();
	      n = 0;
	    }
	}
      if (dap_newpart(partv, npartv))
	nparts++;
    }
  sort(errname, srtarg, "");
  p = plot(srtname, plotvars, plotparts, overstr, NULL, NULL, 2 * nparts);
  for (pn = 0; pn < nparts; pn++)
    strcpy(p[2 * pn].pict_type, "IBEA");
  if (partvars && partvars[0])
    {
      dap_free(partv, "");
      dap_free(mnslist, "");
      dap_free(plotparts, "");
    }
  dap_free(mnsname, "");
  dap_free(errname, "");
  dap_free(srtname, "");
  dap_free(ebar, "");
  dap_free(overstr, "");
  dap_free(srtarg, "");
  dap_free(plotvars, "");
  return p;
}
