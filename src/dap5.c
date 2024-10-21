/* dap5.c -- regression and nonparametric statistics */

/*  Copyright (C) 2001, 2002, 2003, 2004 Free Software Foundation, Inc.
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

#include "dap_make.h"
#include "externs.h"

extern dataobs dap_obs[];
extern FILE *dap_lst;
extern FILE *dap_err;
extern int dap_ono;
extern char *dap_dapname;

static int matchmark(int *markv, int *xmarkv, int nmark, double level)
{
  int i;
  int diff;

  if (xmarkv[0] < 0)
    return !dap_newpart(markv, nmark);
  for (diff = 0, i = 0; !diff && i < nmark; i++)
    {
      if (dap_obs[0].do_len[markv[i]] > 0)
	diff = strcmp(dap_obs[0].do_str[markv[i]], dap_obs[1].do_str[xmarkv[i]]);
      else if (dap_obs[0].do_len[markv[i]] == INT)
	diff = (dap_obs[0].do_int[markv[i]] != dap_obs[1].do_int[xmarkv[i]]);
      else
	diff = (dap_obs[0].do_dbl[markv[i]] != dap_obs[1].do_dbl[xmarkv[i]]);
    }
  return !diff;
}

/* xymat: 0 row contains sum of values for x and y vars except for _intercept_
 * (1 to nx-1) x (1 to nx-1) contains SS for x-variables;
 * (1 to nx-1) x (nx to nvar) contains SS for x-vars with each y-var
 * (nx to nvar-1) x (1 to nx-1) contains SS for x-vars with each y-var
 * (nx, nx) to (nvar-1,nvar-1) diagonal contains SS for each y-var
 */
void linreg1(double **xymat, int *varv,
	     int nx0, int nx, int ny, int nobs, int *xvarv,
	     int *markv, int *xmarkv, int nmark, double level,
	     int respn, int param1n, int param2n, int covn, int partv[])
{
  double *invmem;			/* memory allocated for inverse of SS matrix */
  double **inv;			/* pointers for inverse matrix */
  int r, c;			/* row and column */
  int rr, cc;			/* row and column */
  double pivot;			/* numerical value of pivot element */
  double tmp, tmp2;
  int typen;			/* index of _type_ variable */
  double dnobs;			/* number of observations, as double */
  double *rss0, *rss1, *rss;	/* reduced sums of squares for y vs x0s, y vs x1s, y vs y */
  double *f, *fch;		/* F and F change values */
  int df;				/* degrees of freedom */
  double ddf;			/* degrees of freedom, as double */
  double xi, xj;			/* indexes to x-variables */
  static double tpt;		/* point in t-distribution */
  int yn;				/* index to y variables */
  int i, j;
  double *pred;			/* array of predicted values */
  double *sepred;			/* array of SEs for predictions */
  int v;				/* index to variables */

  dap_swap();	/* it's cleaner to have linreg1 get the previous part's mark variables */
  if ((typen = dap_varnum("_type_")) < 0)
    {
      fprintf(dap_err, "(linreg1) Missing _type_ variable.\n");
      exit(1);
    }
  invmem = (double *) dap_malloc(sizeof(double) * nx * nx, "");
  inv = (double **) dap_malloc(sizeof(double *) * nx, "");
  for (r = 0; r < nx; r++)
    inv[r] = invmem + r * nx;
  rss0 = (double *) dap_malloc(sizeof(double) * ny, "");
  rss1 = (double *) dap_malloc(sizeof(double) * ny, "");
  rss = (double *) dap_malloc(sizeof(double) * ny, "");
  f = (double *) dap_malloc(sizeof(double) * ny, "");
  fch = (double *) dap_malloc(sizeof(double) * ny, "");
  pred = (double *) dap_malloc(sizeof(double) * ny, "");
  sepred = (double *) dap_malloc(sizeof(double) * ny, "");
  dnobs = (double) nobs;
  /* row 0 of xymat will now be the means of the observations */
  for (c = 1; c < nx + ny; c++)
    xymat[0][c] /= dnobs;
  /* initialize the inverse to the identity before performing row ops */
  for (r = 1; r < nx; r++)
    for (c = 1; c < nx; c++)
      {
	if (r == c)
	  inv[r][c] = 1.0;
	else
	  inv[r][c] = 0.0;
      }
  /* now perform row ops for the x-variables, from row 1 to nx-1 */
  for (c = 1; c < nx; c++)
    {
      /* these could have been done before, but can be done here, too */
      if (c == 1)	/* initialize RSS for x0 vars to SSs of the y's */
	{
	  for (cc = 0; cc < ny; cc++)
	    rss0[cc] = xymat[nx + cc][nx + cc];
	}
      if (c == nx0)	/* init RSS for x1 vars to SSs of the y's after reduction of x0 rows */
	{
	  for (cc = 0; cc < ny; cc++)
	    rss1[cc] = xymat[nx + cc][nx + cc];
	}
      pivot = xymat[c][c];	/* default pivot */
      if (pivot != 0.0)	/* OK, trusting the SS matrix not to be weird */
	{		/* should not require pivoting */
	  for (rr = c + 1; rr < nx + ny; rr++)
	    {
	      tmp = xymat[rr][c] / pivot;	/* mult factor for row op */
	      xymat[rr][c] = 0.0;		/* eliminate below (c,c) elt */
	      for (cc = c + 1; cc < nx + ny; cc++)
		{
		  if (rr < nx || cc < nx || rr == cc)
		    {
		      xymat[rr][cc] -= tmp * xymat[c][cc];
		      /* zero out entries below tolerance */
		      if (fabs(xymat[rr][cc]) < dap_tol * pivot)
			xymat[rr][cc] = 0.0;
		    }
		}
	      if (rr < nx)
		{	/* repeat row reduction to get inverse */
		  for (cc = 1; cc < nx; cc++)
		    {
		      inv[rr][cc] -= tmp * inv[c][cc];
		      if (fabs(inv[rr][cc]) < dap_tol * pivot)
			inv[rr][cc] = 0.0;
		    }
		}
	    }
	}
      else
	{
	  fprintf(dap_err, "(linreg1) X'X matrix is singular.\n");
	  exit(1);
	}
    }
  /* now need to do upward row ops to get inverse */
  for (c = nx - 1; c > 0; --c)
    {
      for (r = c - 1; r > 0; --r)
	{
	  tmp = xymat[r][c] / xymat[c][c];
	  for (cc = c + 1; cc < nx + ny; cc++)
	    xymat[r][cc] -= tmp * xymat[c][cc];
	  for (cc = 0; cc < nx; cc++)
	    inv[r][cc] -= tmp * inv[c][cc];
	}
      for (cc = c + 1; cc < nx + ny; cc++)
	xymat[c][cc] /= xymat[c][c];
      for (cc = 0; cc < nx; cc++)
	inv[c][cc] /= xymat[c][c];
    }
  df = nobs - nx;
  ddf = (double) df;
  /* RSS for y-vars are the diagonal entries of xymat
   * and F stats are ratios of differences of SSs to RSS for the y-vars
   */
  for (c = 0; c < ny; c++)
    {
      rss[c] = xymat[nx + c][nx + c];		/* SSs of the y-vars after reduction */
      f[c] = (rss0[c] - rss[c]) / rss[c] * ddf / ((double) nx - 1);
      fch[c] = (rss1[c] - rss[c]) / rss[c] * ddf / ((double) nx - nx0);
    }
  /* now copy inverse of SS of the x-vars back to xymat */
  for (r = 1; r < nx; r++)
    for (c = 1; c < nx; c++)
      xymat[r][c] = inv[r][c];
  /* column 0 will be the minus cross-product of inv SS with the means */
  for (r = 1; r < nx; r++)
    for (c = 1; c < nx; c++)
      xymat[r][0] -= xymat[r][c] * xymat[0][c];
  xymat[0][0] = 1.0 / dnobs;
  for (c = 1; c < nx; c++)
    xymat[0][0] -= xymat[0][c] * xymat[c][0];
  for (c = 0; c < ny; c++)
    for (cc = 1; cc < nx; cc++)
      xymat[0][nx + c] -= xymat[0][cc] * xymat[cc][nx + c];
  for (c = 1; c < nx; c++)
    xymat[0][c] = xymat[c][0];
  /* now print and output estimates and SEs, later output the covariance matrix */
  dap_ono = 2;
  /* set up partvars for covariance matrix dataset */
  for (v = 0; v < nmark; v++)
    {
      if (dap_obs[0].do_len[markv[v]] == DBL)
	dap_obs[dap_ono].do_dbl[partv[v]] = dap_obs[0].do_dbl[markv[v]];
      else if (dap_obs[0].do_len[markv[v]] == INT)
	dap_obs[dap_ono].do_int[partv[v]] = dap_obs[0].do_int[markv[v]];
      else
	strcpy(dap_obs[dap_ono].do_str[partv[v]],
	       dap_obs[0].do_str[markv[v]]);
    }
  fprintf(dap_lst, "Reduced | full model regressors:");
  for (r = 0; r < nx0; r++)
    fprintf(dap_lst, " %s", dap_obs[0].do_nam[varv[r]]);
  fprintf(dap_lst, " |");
  while (r < nx)
    fprintf(dap_lst, " %s", dap_obs[0].do_nam[varv[r++]]);
  putc('\n', dap_lst);
  fprintf(dap_lst, "Number of observations = %d\n", nobs);
  for (c = 0; c < ny; c++)
    {
      fprintf(dap_lst, "\nResponse: %s\n", dap_obs[0].do_nam[varv[nx + c]]);
      fprintf(dap_lst,
	      "   F0(%d, %d) = %.6g, Prob[F > F0] = %.5f\n   R-sq = %.6g, Adj R-sq = %.6g\n",
	      nx - 1, nobs - nx, f[c],
	      0.00001 * ceil(100000.0 * probf(f[c], nx - 1, nobs - nx)),
	      1.0 - rss[c] / rss0[c],
	      1.0 - rss[c] * ((double) (nobs - 1)) / (rss0[c] * ddf));
      if (nx0 > 1)
	fprintf(dap_lst, "   F-change(%d, %d) = %.6g, Prob[F > F-change] = %.5f\n",
		nx - nx0, nobs - nx, fch[c],
		0.00001 * ceil(100000.0 * probf(fch[c], nx - nx0, nobs - nx)));
      fprintf(dap_lst,
	      "\n   Parameter           Estimate    Std Error   T0[%6d]  Prob[|T|>|T0|]\n",
	      nobs - nx);
      for (r = 0; r < nx; r++)
	{
	  /* tmp = sqrt(RSS for y with itself after reduction / deg freedom * inv SS for x-var)
	   * this is the standard error, the denominator for the t-value
	   */
	  tmp = sqrt(rss[c] / ddf * xymat[r][r]);
	  /* tmp2 is the t-value because xymat[r][nx + c] is the estimate */
	  tmp2 = xymat[r][nx + c] / tmp;
	  fprintf(dap_lst, "   %-15s %12.6g %12.6g %12.6g  %14.5f\n",
		  dap_obs[0].do_nam[varv[r]],
		  xymat[r][nx + c], tmp,
		  tmp2,
		  0.00001 * ceil(200000.0 * probt(fabs(tmp2), nobs - nx)));
	  strcpy(dap_obs[dap_ono].do_str[typen], "ESTIMATE");
	  strcpy(dap_obs[dap_ono].do_str[respn], dap_obs[0].do_nam[varv[nx + c]]);
	  strcpy(dap_obs[dap_ono].do_str[param2n], dap_obs[0].do_nam[varv[r]]);
	  strcpy(dap_obs[dap_ono].do_str[param1n], "");
	  dap_obs[dap_ono].do_dbl[covn] = xymat[r][nx + c];
	  output();
	}
    }
  /* now we write out the covariance matrix */
  strcpy(dap_obs[dap_ono].do_str[typen], "COVAR");
  for (yn = 0; yn < ny; yn++)
    {
      strcpy(dap_obs[dap_ono].do_str[respn], dap_obs[0].do_nam[varv[nx + yn]]);
      tmp = rss[yn] / ddf;
      /* "rows" are indexed by r */
      for (r = 0; r < nx; r++)
	{
	  strcpy(dap_obs[dap_ono].do_str[param1n], dap_obs[0].do_nam[varv[r]]);
	  /* "columns" are indexed by c */
	  for (c = 0; c < nx; c++)
	    {
	      strcpy(dap_obs[dap_ono].do_str[param2n], dap_obs[0].do_nam[varv[c]]);
	      dap_obs[dap_ono].do_dbl[covn] = tmp * xymat[r][c];
	      output();
	    }
	}
    }
  /* now back to .reg output */
  dap_ono = 0;
  /* now we write out the OBS, PRED, LOWER, and UPPER values for the xname values */
  if (level < 1.0)
    tpt = tpoint(0.5 * (1.0 - level), nobs - nx);
  else
    tpt = 0.0;
  dap_obs[0].do_dbl[varv[0]] = 1.0;
  if (xvarv[0] < 0)
    {
      dap_rewind();
      step();
    }
  while (matchmark(markv, xmarkv, nmark, level))
    {
      dap_ono = 0;
      if (xvarv[0] >= 0)	/* if dataset for x-values specified */
	{		/* there are no observed values */
	  for (i = 1; i < nx; i++)
	    dap_obs[0].do_dbl[varv[i]] = dap_obs[1].do_dbl[xvarv[i - 1]];
	}
      else
	{
	  strcpy(dap_obs[0].do_str[typen], "OBS");
	  output();
	}
      for (yn = 0; yn < ny; yn++)
	{
	  for (pred[yn] = 0.0, i = 0; i < nx; i++)
	    pred[yn] += xymat[i][nx + yn] * dap_obs[0].do_dbl[varv[i]];
	  for (sepred[yn] = 0.0, i = 0; i < nx; i++)
	    {
	      xi = dap_obs[0].do_dbl[varv[i]];
	      for (j = 0; j < nx; j++)
		{
		  xj = dap_obs[0].do_dbl[varv[j]];
		  sepred[yn] += xi * rss[yn] / ddf * xymat[i][j] * xj;
		}
	    }
	}
      strcpy(dap_obs[0].do_str[typen], "PRED");
      for (yn = 0; yn < ny; yn++)
	dap_obs[0].do_dbl[varv[nx + yn]] = pred[yn];
      output();
      if (tpt != 0.0)
	{
	  strcpy(dap_obs[0].do_str[typen], "LOWER");
	  for (yn = 0; yn < ny; yn++)
	    dap_obs[0].do_dbl[varv[nx + yn]] = pred[yn] - tpt * sqrt(sepred[yn]);
	  output();
	  strcpy(dap_obs[0].do_str[typen], "UPPER");
	  for (yn = 0; yn < ny; yn++)
	    dap_obs[0].do_dbl[varv[nx + yn]] = pred[yn] + tpt * sqrt(sepred[yn]);
	  output();
	}
      if (xvarv[0] >= 0)
	dap_ono = 1;
      dap_mark();
      if (!step())
	break;
    }
  dap_ono = 0;
  if (xvarv[0] >= 0)
    dap_swap();
  dap_free(invmem, "");
  dap_free(inv, "");
  dap_free(rss0, "");
  dap_free(rss1, "");
  dap_free(rss, "");
  dap_free(f, "");
  dap_free(fch, "");
  dap_free(pred, "");
  dap_free(sepred, "");
}

/* xname is dataset of x-values at which to write out OBS,PRED,LOWER, and UPPER values */
void linreg(char *fname, char *ylist, char *x0list, char *x1list,
	    char *marks, char *xname, double level)
{
  char *regname;	/* name of .reg dataset for writing out OBS,PRED,LOWER, and UPPER values */
  int *varv;	/* indexes of all variables */
  int *xvarv;	/* indexes of x-variables in dataset xname */
  int ny;		/* number of y-variables */
  int nx0, nx1;	/* num of x-vars in reduced (includes _intercept_), full-reduced models */
  int nx;		/* number of x-variables: nx0 + nx1 */
  int nvar;	/* number of x- and y-variables: nx + ny */
  int nxx;	/* number of x-variables not including _intercept_ */
  int *markv;	/* indexes of mark variables for partitioning the dataset */
  int *xmarkv;	/* if xname is given, indexes of mark variables in dataset xname */
  int nmark;	/* number of mark variables (must be equal for fname and xname datasets) */
  int v, w;	/* indexes to index vectors */
  double tmp;
  int nobs;	/* number of observations in the dataset fname */
  double dnobs;	/* nobs converted to double */
  double *xymem;	/* memory allocated for SS matrix */
  double **xymat;	/* SS matrix for the nvar = nx + ny x- and y-variables */
  int more;	/* for stepping through parts of the dataset */
  char *covset;   /* name of dataset for covariance matrix */
  int param1n, param2n, respn, covn;     /* indices to covset variables */
  int paramlen1, paramlen;        /* length and maximum length of parameter name */
  char paramstr[14];      /* string for declaring variable name variables */
  char *partstr;  /* for declaring part variables in covset */
  int *partv;    /* indexes of part variables for covset */

  if (!fname)
    {
      fputs("(linreg) No dataset name given.\n", dap_err);
      exit(1);
    }
  varv = (int *) dap_malloc(sizeof(int) * dap_maxvar, "dap_maxvar");
  xvarv = (int *) dap_malloc(sizeof(int) * dap_maxvar, "dap_maxvar");
  markv = (int *) dap_malloc(sizeof(int) * dap_maxvar, "dap_maxvar");
  xmarkv = (int *) dap_malloc(sizeof(int) * dap_maxvar, "dap_maxvar");
  partv = (int *) dap_malloc(sizeof(int) * dap_maxvar, "dap_maxvar");
  regname = dap_malloc(strlen(fname) + 5, "");
  dap_suffix(regname, fname, ".reg");
  inset(fname);
  dap_vd("_intercept_ -1", 0);	/* allocate _intercept_ variable */
  nx0 = dap_list("_intercept_", varv, dap_maxvar);	/* and put in varv */
  nx0 += dap_list(x0list, varv + 1, dap_maxvar);	/* now put in x0 vars */
  nx1 = dap_list(x1list, varv + nx0, dap_maxvar);	/* now put in x1 vars */
  nx = nx0 + nx1;
  ny = dap_list(ylist, varv + nx, dap_maxvar);	/* now put in y vars */
  nvar = nx + ny;
  nmark = dap_list(marks, markv, dap_maxvar);	/* get mark variable indexes */
  /* do some bookkeeping for covariance dataset */
  covset = dap_malloc(strlen(fname) + 5, "");
  strcpy(covset, fname);
  strcat(covset, ".cov");
  /* find maximum length of variable names */
  for (v = 1, paramlen = strlen("_intercept_"); v < nvar; v++)
    {
      paramlen1 = strlen(dap_obs[dap_ono].do_nam[varv[v]]);
      if (paramlen1 > paramlen)
	paramlen = paramlen1;
    }
  /* now set up variables for covariance dataset */
  dap_ono = 2;
  dap_clearobs((char *) NULL);    /* set up dap_obs, make _type_ variable */
  /* this will bomb if a variable name is more than 99 characters long */
  sprintf(paramstr, "_response_ %d", paramlen);
  respn = dap_vd(paramstr, 0);
  sprintf(paramstr, "_param1_ %d", paramlen);
  param1n = dap_vd(paramstr, 0);
  sprintf(paramstr, "_param2_ %d", paramlen);
  param2n = dap_vd(paramstr, 0);
  covn = dap_vd("_cov_ -1", 0);
  partstr = dap_malloc(strlen(marks) + 1, "");
  for (v = 0; v < nmark; v++)
    {
      strcpy(partstr, dap_obs[0].do_nam[markv[v]]);
      sprintf(partstr + strlen(partstr), " %d", dap_obs[0].do_len[markv[v]]);
      partv[v] = dap_vd(partstr, 1);
    }
  outset(covset, "");
  /* now back to fname */
  dap_ono = 0;
  /* allocate memory for SS matrix and set up pointers for matrix entries */
  xymem = (double *) dap_malloc(sizeof(double) * nvar * nvar, "");
  xymat = (double **) dap_malloc(sizeof(double *) * nvar, "");
  for (v = 0; v < nvar; v++)
    xymat[v] = xymem + v * nvar;
  dap_ono = 1;		/* now going to work with dataset xname of x-values */
  if (xname && xname[0])	/* if xname is specified */
    {
      inset(xname);
      nxx = dap_list(x0list, xvarv, dap_maxvar);	/* get indexes of x-vars in xname */
      nxx += dap_list(x1list, xvarv + nxx, dap_maxvar);
      if (nxx != nx - 1)	/* this had better match, except for _intercept_ */
	{
	  fprintf(dap_err,
		  "(linreg) %s and %s have different numbers (%d and %d) of x-variables.\n",
		  fname, xname, nx - 1, nxx);
	  exit(1);
	}
      if (nmark)	/* if the datasets are partitioned */
	{	/* check that fname and xname have same mark vars */
	  for (v = 0; v < nmark; v++)
	    {
	      if ((xmarkv[v] = dap_varnum(dap_obs[0].do_nam[markv[v]])) < 0)
		{
		  fprintf(dap_err,
			  "(linreg) Mark variable %s in %s not in %s.\n",
			  dap_obs[0].do_nam[markv[v]], fname, xname);
		  exit(1);
		}
	    }
	}
      if (!step())
	{
	  fprintf(dap_err, "(linreg) No data in %s.\n", xname);
	  exit(1);
	}
    }
  else		/* indicate lack of xname dataset */
    {
      xvarv[0] = -1;
      xmarkv[0] = -1;
    }
  dap_ono = 0;	/* now back to dataset fname of observations */
  for (w = 0; w < nvar; w++)	/* check type of variables */
    {
      if (dap_obs[0].do_len[varv[w]] != DBL)
	{
	  fprintf(dap_err, "(linreg) Variable %s not double.\n",
		  dap_obs[0].do_nam[varv[w]]);
	  exit(1);
	}
      for (v = 0; v < nvar; v++)	/* and zero out entire xymat */
	xymat[v][w] = 0.0;
    }
  outset(regname, "");	/* prepare writing of OBS,PRED,LOWER and UPPER values */
  /* now we read in the data and create the SS matrix */
  for (nobs = 0, dap_mark(), more = 1; more; nobs++)
    {
      more = step();
      if (dap_newpart(markv, nmark))
	{
	  dap_swap();
	  dap_head(markv, nmark);
	  dap_swap();
	  linreg1(xymat, varv, nx0, nx, ny, nobs, xvarv, markv, xmarkv, nmark, level,
		  respn, param1n, param2n, covn, partv);
	  for (w = 0; w < nvar; w++)
	    {
	      for (v = 0; v < nvar; v++)
		xymat[v][w] = 0.0;
	    }
	  nobs = 0;
	}
      /* use standard updating algorithm for computing the SS's on the run for accuracy */
      /* xymat: 0 row contains sum of values for x and y vars except for _intercept_
       * (1 to nx-1) x (1 to nx-1) contains SS for x-variables;
       * (1 to nx-1) x (nx to nvar) contains SS for x-vars with each y-var
       * (nx to nvar-1) x (1 to nx-1) contains SS for x-vars with each y-var
       * (nx, nx) to (nvar-1,nvar-1) diagonal contains SS for each y-var
       */
      if (nobs)
	{	/* we do this starting on the second observation */
	  dnobs = (double) nobs;
	  for (v = 1; v < nvar; v++)
	    {
	      tmp = xymat[0][v] -
		dnobs * dap_obs[0].do_dbl[varv[v]];
	      for (w = 1; w < nvar; w++)
		{
		  if (v < nx || w < nx || v == w)
		    xymat[v][w] += tmp *
		      (xymat[0][w] - dnobs *
		       dap_obs[0].do_dbl[varv[w]]) /
		      (dnobs * (dnobs + 1.0));
		}
	    }
	}
      for (w = 1; w < nvar; w++)	/* zero row is sum of values except for _intercept_ */
	xymat[0][w] += dap_obs[0].do_dbl[varv[w]];
    }
  dap_free(regname, "");
  dap_free(varv, "");
  dap_free(xvarv, "");
  dap_free(markv, "");
  dap_free(xmarkv, "");
  dap_free(xymem, "");
  dap_free(xymat, "");
  dap_free(covset, "");
  dap_free(partstr, "");
  dap_free(partv, "");
}

/* parse response specs for logistic regression */
void dap_parsey(char *yspec, int *varv)
{
  int l;
  int i;
  char *vname;
  int vn;
  int ntrials;

  vname = dap_malloc(dap_namelen + 1, "dap_namelen");
  for (l = 0; yspec[l] == ' '; l++) /* skip leading blanks */
    ;
  for (i = 0; yspec[l + i] && yspec[l + i] != ' ' && yspec[l + i] != '/'; i++)
    {
      if (i < dap_namelen)
	vname[i] = yspec[l + i];
      else
	{
	  fprintf(dap_err, "(parsey) Variable name too long: %s\n", yspec + l);
	  exit(1);
	}
    }
  vname[i] = '\0'; /* response variable */
  l += i; /* now at space or / */
  if ((vn = dap_varnum(vname)) < 0)
    {
      fprintf(dap_err, "(parsey) Unknown variable: %s\n", vname);
      exit(1);
    }
  if (dap_obs[dap_ono].do_len[vn] != DBL)
    {
      fprintf(dap_err, "(parsey) Events variable not double: %s\n", vname);
      exit(1);
    }
  varv[0] = vn;
  while (yspec[l] == ' ')
    l++;
  if (yspec[l] == '/')
    {
      for (l++; yspec[l] == ' '; l++) /* skip spaces */
	;
      for (i = 0; yspec[l + i] && yspec[l + i] != ' '; i++)
	{
	  if (i < dap_namelen)
	    vname[i] = yspec[l + i];
	  else
	    {
	      fprintf(dap_err, "(parsey) Variable name too long: %s\n", yspec + l);
	      exit(1);
	    }
	}
      vname[i] = '\0';
      for (i = 0, ntrials = 0; '0' <= vname[i] && vname[i] <= '9'; i++)
	ntrials = 10 * ntrials + vname[i] - '0';
      if (i)
	{
	  if (vname[i])
	    {
	      fprintf(dap_err, "(parsey) Invalid number of trials: %s\n", vname);
	      exit(1);
	    }
	  varv[1] = -ntrials;
	}
      else
	{
	  if ((vn = dap_varnum(vname)) < 0)
	    {
	      fprintf(dap_err, "(parsey) Unknown variable: %s\n", vname);
	      exit(1);
	    }
	  if (dap_obs[dap_ono].do_len[vn] != DBL)
	    {
	      fprintf(dap_err, "(parsey) Trials variable not double: %s\n", vname);
	      exit(1);
	    }
	  varv[1] = vn;
	}
    }
  else
    {
      fprintf(dap_err, "(parsey) Expected / in yspec at: %s\n", yspec + l);
      exit(1);
    }
  dap_free(vname, "");
}

static double vlen(double *v, int nv)
{
  int i;
  double len;

  for (len = 0.0, i = 0; i < nv; i++)
    len += v[i] * v[i];
  return sqrt(len);
}

static double vdiff(double *v0, double *v1, int nv)
{
  int i;
  double tmp;
  double diff;

  for (diff = 0.0, i = 0; i < nv; i++)
    {
      tmp = v0[i] - v1[i];
      diff += tmp * tmp;
    }
  return sqrt(diff);
}

int dap_invert(double **a, int nrc)
{
  double *invmem;
  double **inv;
  int r, c;
  int cc;
  double tmp;
  double mult;

  invmem = (double *) dap_malloc(sizeof(double) * nrc * nrc, "");
  inv = (double **) dap_malloc(sizeof(double *) * nrc, "");
  for (r = 0; r < nrc; r++)
    {
      inv[r] = invmem + r * nrc;
      for (c = 0; c < nrc; c++)
	{
	  if (r == c)
	    inv[r][c] = 1.0;
	  else
	    inv[r][c] = 0.0;
	}
    }
  for (c = 0; c < nrc; c++)
    {
      if (a[c][c] != 0.0)
	{
	  tmp = a[c][c];
	  for (r = c + 1; r < nrc; r++)
	    {
	      mult = a[r][c] / tmp;
	      a[r][c] = 0.0;
	      for (cc = c + 1; cc < nrc; cc++)
		{
		  a[r][cc] -= mult * a[c][cc];
		  if (fabs(a[r][cc]) < dap_tol * tmp)
		    a[r][cc] = 0.0;
		}
	      for (cc = 0; cc < nrc; cc++)
		{
		  inv[r][cc] -= mult * inv[c][cc];
		  if (fabs(inv[r][cc]) < dap_tol * tmp)
		    inv[r][cc] = 0.0;
		}
	    }
	}
      else
	return 0;
    }
  for (c = nrc - 1; c >= 0; --c)
    {
      tmp = a[c][c];
      for (cc = c + 1; cc < nrc; cc++)
	a[c][cc] /= tmp;
      for (cc = 0; cc < nrc; cc++)
	inv[c][cc] /= tmp;
      for (r = c - 1; r >= 0; --r)
	{
	  tmp = a[r][c];
	  for (cc = c; cc < nrc; cc++)
	    a[r][cc] -= tmp * a[c][cc];
	  for (cc = 0; cc < nrc; cc++)
	    inv[r][cc] -= tmp * inv[c][cc];
	}
    }
  for (r = 0; r < nrc; r++)
    for (c = 0; c < nrc; c++)
      a[r][c] = inv[r][c];
  dap_free(invmem, "");
  dap_free(inv, "");
  return 1;
}

/* Iterative reweighted least squares
 * (Agresti, Categorical Data Analysis, 1990, pp. 116-117)
 */
static double irls(
		   double **x,	/* array of explanatory x-variable values */
		   double **y,	/* array of response y-variable, number-of-cases variable values */
		   double *pr,	/* array of predicted probability values for x-variable values */
		   double *beta0,	/* parameter vector, allocated by and returned to caller */
		   double **cov,	/* covariance matrix, allocated by caller */
		   int nx,		/* number of explanatory x-variable values */
		   int nobs	/* number of observations */
		   )
{
  int i, j;
  int n;
  double *beta1;			/* next value of parameter vector */
  double *v;			/* the X'(y - m(i)) term of equation (4.32) on p. 116 */
  double *step;			/* amount to change beta parameter vector by */
  double loglike0, loglike1;	/* current and next log likelihood values */
  int niter;			/* number of iterations completed */
  double maxv;			/* max entry in X'(y - m(i)) */
  double maxcov;
  double tmp;

  /* allocate array for next value of parameter vector */
  beta1 = (double *) dap_malloc(sizeof(double) * nx, "");
  /* what's this? */
  v = (double *) dap_malloc(sizeof(double) * nx, "");
  /* allocate array for beta change vector */
  step = (double *) dap_malloc(sizeof(double) * nx, "");
  /* initialize parameter values all to zero: null model */
  for (i = 0; i < nx; i++)
    beta1[i] = 0.0;
  /* initialize all probability values to 0.5 (null model) and
   * compute corresponding log likelihood
   */
  for (loglike1 = 0.0, n = 0; n < nobs; n++)
    {
      pr[n] = 0.5;
      loglike1 += y[1][n];
    }
  loglike1 *= log(0.5);
  /* starting iterations */
  niter = 0;
  do	{
    /* copy new parameter vector, log likelihood into old for next iteration */
    for (i = 0; i < nx; i++)
      beta0[i] = beta1[i];
    loglike0 = loglike1;
    /* compute terms of equation (4.32) on page 116 */
    for (i = 0, maxv = 0.0, maxcov = 0.0; i < nx; i++)
      {
	/* compute the X'(y - m(i)) term */
	for (v[i] = 0.0, n = 0; n < nobs; n++)
	  v[i] += x[i][n] * (y[0][n] - y[1][n] * pr[n]);
	/* and the maximum entry in that vector */
	if ((tmp = fabs(v[i])) > maxv)
	  maxv = tmp;
	/* now compute X'Diag[ni pi(i)(1 - pi(i)]X; temporarily put in cov */
	for (j = 0; j < nx; j++)
	  {
	    cov[i][j] = 0.0;
	    for (n = 0; n < nobs; n++)
	      cov[i][j] += y[1][n] * pr[n] * (1.0 - pr[n]) *
		x[i][n] * x[j][n];
	    /* and get the maximum entry in that matrix */
	    if ((tmp = fabs(cov[i][j])) > maxcov)
	      maxcov = tmp;
	  }
      }
    /* to deal with near-zero results from rounding */
    for (i = 0; i < nx; i++)
      {
	if (fabs(v[i]) < dap_ctol * maxv)
	  v[i] = 0.0;
	for (j = 0; j < nx; j++)
	  {
	    if (fabs(cov[i][j]) < dap_ctol * maxcov)
	      cov[i][j] = 0.0;
	  }
      }
    if (!dap_invert(cov, nx))
      {
	fputs("(irls) X'DX matrix is singular\n", dap_err);
	exit(1);
      }
    /* compute change in the beta parameter array */
    for (i = 0; i < nx; i++)
      {
	step[i] = 0.0;
	for (j = 0; j < nx; j++)
	  step[i] += cov[i][j] * v[j];
      }
    for ( ; niter <= dap_maxiter; niter++)
      {
	/* get tentative new beta parameter array */
	for (i = 0; i < nx; i++)
	  beta1[i] = beta0[i] + step[i];
	/* compute corresponding new log likelihood */
	for (n = 0, loglike1 = 0.0; n < nobs; n++)
	  {
	    for (pr[n] = 0.0, i = 0; i < nx; i++)
	      pr[n] += x[i][n] * beta1[i];
	    pr[n] = 1.0 / (1.0 + exp(-pr[n]));
	    loglike1 += y[0][n] * log(pr[n]) +
	      (y[1][n] - y[0][n]) * log(1.0 - pr[n]);
	  }
	if (loglike1 >= loglike0)	/* if it's at least as good, quit */
	  break;
	else		/* else halve the step size and try again */
	  {
	    for (i = 0; i < nx; i++)
	      step[i] *= 0.5;
	  }
      }
  } while (++niter <= dap_maxiter && vdiff(beta1, beta0, nx) > dap_ctol * vlen(beta0, nx));
  if (niter > dap_maxiter)
    fprintf(dap_lst, "Failed to converge after %d iterations.\n", dap_maxiter);
  dap_free(beta1, "");
  dap_free(v, "");
  dap_free(step, "");
  return loglike0;
}

/* Run logistic regression on one part of the data */
void logreg1(
	     double **y,	/* the response and number-of-cases variables */
	     double **x,	/* array of x-vectors of data */
	     int nx0,	/* number of explanatory x-variables in reduced model */
	     int nx,		/* number of explanatory x-variables in full model */
	     int nobs,	/* number of observations */
	     int *varv,	/* array of variable indices for main dataset */
	     int *xvarv,	/* array of variable indices for xname dataset */
	     int *markv,	/* array of indices of partitioning variables in main dataset */
	     int *xmarkv,	/* array of indices of partitioning variables in xname dataset */
	     int nmark,	/* number of partitioning variables */
	     double level,	/* confidence level for probabilities */
	     int param1n,	/* for covariance dataset, index of parameter for "row" label */
	     int param2n,	/* for covariance dataset, index of parameter for "column" label */
	     int covn,	/* for covariance dataset, index of parameter for numerical value */
	     int partv[]	/* array of indexes of partioning variables in covset */
	     )
{
  int typen;			/* index of _type_ variable */
  double *covmem;			/* memory for covariance matrix */
  double **cov;			/* covariance matrix */
  double *pr;			/* array of estimated probabilities for data points */
  double *beta;			/* parameter vector */
  int i, j;
  double tmp, tmp2;
  double loglike0, loglike1;	/* current and next log likelihood values */
  static double npt;
  double xi, xj;
  double logit;
  double selogit;
  int ntrials;
  int v;

  /* allocate memory for covariance matrix */
  covmem = (double *) dap_malloc(sizeof(double) * dap_maxvar * dap_maxvar, "");
  /* allocate and assign pointers for covariance matrix */
  cov = (double **) dap_malloc(sizeof(double *) * dap_maxvar, "");
  for (i = 0; i < dap_maxvar; i++)
    cov[i] = covmem + i * dap_maxvar;
  /* allocate parameter vector */
  beta = (double *) dap_malloc(sizeof(double) * nx, "");
  /* get back to the part of the dataset we're working on */
  dap_swap();
  /* get index of _type_ variable */
  if ((typen = dap_varnum("_type_")) < 0)
    {
      fprintf(dap_err, "(logreg1) Missing _type_ variable.\n");
      exit(1);
    }
  /* allocate probability array */
  pr = (double *) dap_malloc(nobs * sizeof(double), "");
  /* print out information on model */
  fprintf(dap_lst, "Reduced | full model regressors:");
  for (i = 0; i < nx0; i++)
    fprintf(dap_lst, " %s", dap_obs[0].do_nam[varv[i]]);
  fprintf(dap_lst, " |");
  while (i < nx)
    fprintf(dap_lst, " %s", dap_obs[0].do_nam[varv[i++]]);
  putc('\n', dap_lst);
  fprintf(dap_lst, "Number of observations = %d\n", nobs);
  for (i =  0, ntrials = 0; i < nobs; i++)
    ntrials += (int) rint(y[1][i]);
  fprintf(dap_lst, "Number of trials = %d\n", ntrials);
  if (varv[nx + 1] >= 0)
    fprintf(dap_lst, "Events / Trials: %s / %s\n",
	    dap_obs[0].do_nam[varv[nx]],
	    dap_obs[0].do_nam[varv[nx + 1]]);
  else
    fprintf(dap_lst, "Events / Trials: %s / %d\n",
	    dap_obs[0].do_nam[varv[nx]], -varv[nx + 1]);
  /* run iterative reweighted least squares on reduced model */
  loglike0 = irls(x, y, pr, beta, cov, nx0, nobs);
  /* run iterative reweighted least squares on full model */
  loglike1 = irls(x, y, pr, beta, cov, nx, nobs);
  /* don't need probability array any more */
  dap_free(pr, "");
  /* now print results and output estimates and SEs, later output the covariance matrix */
  dap_ono = 2;
  /* set up partvars for covariance matrix dataset */
  for (v = 0; v < nmark; v++)
    {
      if (dap_obs[0].do_len[markv[v]] == DBL)
	dap_obs[dap_ono].do_dbl[partv[v]] = dap_obs[0].do_dbl[markv[v]];
      else if (dap_obs[0].do_len[markv[v]] == INT)
	dap_obs[dap_ono].do_int[partv[v]] = dap_obs[0].do_int[markv[v]];
      else
	strcpy(dap_obs[dap_ono].do_str[partv[v]],
	       dap_obs[0].do_str[markv[v]]);
    }
  fprintf(dap_lst, "-2 (Lred - Lfull) = %.6g = ChiSq0[%d]\n",
	  tmp = -2.0 * (loglike0 - loglike1), nx - nx0);
  fprintf(dap_lst, "Prob[ChiSq > ChiSq0] = %.5f\n\n",
	  0.00001 * ceil(100000.0 * probchisq(fabs(tmp), nx - nx0)));
  fputs(
	"  Parameter           Estimate    Std Error   Wald ChiSq  Prob[ChiSq>Wald ChiSq]\n",
	dap_lst);
  for (i = 0; i < nx; i++)
    {
      tmp = sqrt(cov[i][i]);
      tmp2 = beta[i] * beta[i] / cov[i][i];
      fprintf(dap_lst, "  %-15s %12.6g %12.6g %12.6g  %14.5f\n",
	      dap_obs[0].do_nam[varv[i]],
	      beta[i], tmp, tmp2,
	      0.00001 * ceil(100000.0 * probchisq(fabs(tmp2), 1)));
      strcpy(dap_obs[dap_ono].do_str[typen], "ESTIMATE");
      strcpy(dap_obs[dap_ono].do_str[param2n], dap_obs[0].do_nam[varv[i]]);
      strcpy(dap_obs[dap_ono].do_str[param1n], "");
      dap_obs[dap_ono].do_dbl[covn] = beta[i];
      output();
    }
  /* now we write out the covariance matrix */
  strcpy(dap_obs[dap_ono].do_str[typen], "COVAR");
  /* "rows" are indexed by i */
  for (i = 0; i < nx; i++)
    {
      strcpy(dap_obs[dap_ono].do_str[param1n], dap_obs[0].do_nam[varv[i]]);
      /* "columns" are indexed by j */
      for (j = 0; j < nx; j++)
	{
	  strcpy(dap_obs[dap_ono].do_str[param2n], dap_obs[0].do_nam[varv[j]]);
	  dap_obs[dap_ono].do_dbl[covn] = cov[i][j];
	  output();
	}
    }
  /* now back to .lgr output */
  dap_ono = 0;
  if (fabs(level) < 1.0)
    npt = -zpoint(0.5 * (1.0 - level));
  else
    npt = 0.0;
  dap_obs[0].do_dbl[varv[0]] = 1.0;
  /* now compute predicted values */
  if (xvarv[0] < 0)
    {
      dap_rewind();
      step();
    }
  while (matchmark(markv, xmarkv, nmark, level))
    {
      dap_ono = 0;
      if (xvarv[0] >= 0)
	{
	  for (i = 1; i < nx; i++)
	    dap_obs[0].do_dbl[varv[i]] = dap_obs[1].do_dbl[xvarv[i - 1]];
	}
      for (logit = 0.0, i = 0; i < nx; i++)
	logit += beta[i] * dap_obs[0].do_dbl[varv[i]];
      for (selogit = 0.0, i = 0; i < nx; i++)
	{
	  xi = dap_obs[0].do_dbl[varv[i]];
	  for (j = 0; j < nx; j++)
	    {
	      xj = dap_obs[0].do_dbl[varv[j]];
	      selogit += xi * cov[i][j] * xj;
	    }
	}
      selogit = sqrt(selogit);
      strcpy(dap_obs[0].do_str[typen], "PRED");
      dap_obs[0].do_dbl[varv[nx]] = 1.0 / (1.0 + exp(-logit));
      output();
      if (npt != 0.0)
	{
	  strcpy(dap_obs[0].do_str[typen], "LOWER");
	  dap_obs[0].do_dbl[varv[nx]] =
	    1.0 / (1.0 + exp(-logit + npt * selogit));
	  output();
	  strcpy(dap_obs[0].do_str[typen], "UPPER");
	  dap_obs[0].do_dbl[varv[nx]] =
	    1.0 / (1.0 + exp(-logit - npt * selogit));
	  output();
	}
      if (xvarv[0] >= 0)
	dap_ono = 1;
      dap_mark();
      if (!step())
	break;
    }
  dap_ono = 0;
  if (xvarv[0] >= 0)
    dap_swap();
  /* free allocated memory */
  dap_free(covmem, "");
  dap_free(cov, "");
  dap_free(beta, "");
}

/* Run logistic regression on a dataset */
void logreg(
	    char *fname,	/* name of dataset */
	    char *yspec,	/* specification of response */
	    char *x0list,	/* list of explanatory x-variables in reduced model */
	    char *x1list,	/* list of explanatory x-variables in rest of model */
	    char *marks,	/* variables for partitioning the dataset */
	    char *xname,	/* name of dataset containing x-values for reporting results */
	    double level	/* level for confidence region */
	    )
{
  char *regname;
  int *varv;		/* array of variable indices */
  int *xvarv;		/* array of x-variable indices */
  int nx0, nx1;		/* number of explanatory x-variables in reduced, rest of model;
			 * note that x0 always contains intercept
			 */
  int nx;			/* number of all x-variables, including intercept */
  int nxx;		/* number of all x-variables in xname dataset */
  int *markv;		/* partitioning array for dataset */
  int *xmarkv;		/* partitioning array for xname dataset */
  int nmark;		/* number of partitioning variables */
  double *xmem;		/* memory for x-matrix */
  double **x;		/* the array of x-vectors */
  double *ymem;		/* memory for the array of corresponding y-values */
  double *y[2];		/* the array of corresponding y-values */
  int v;			/* index to array of variable indices */
  int nobs;		/* number of observations */
  int more;		/* more data to be read from dataset? (for partitioning) */
  char *covset;		/* name of dataset for covariance matrix */
  int param1n, param2n, covn;	/* indices to covset variables */
  int paramlen1, paramlen;	/* length and maximum length of parameter name */
  char paramstr[14];	/* string for declaring variable name variables */
  char *partstr;		/* for declaring part variables in covset */
  int *partv;		/* indexes of part variables for covset */

  if (!fname)
    {
      fputs("(logreg) No dataset name given.\n", dap_err);
      exit(1);
    }
  /* allocate arrays */
  varv = (int *) dap_malloc(sizeof(int) * dap_maxvar, "dap_maxvar");
  xvarv = (int *) dap_malloc(sizeof(int) * dap_maxvar, "dap_maxvar");
  markv = (int *) dap_malloc(sizeof(int) * dap_maxvar, "dap_maxvar");
  xmarkv = (int *) dap_malloc(sizeof(int) * dap_maxvar, "dap_maxvar");
  partv = (int *) dap_malloc(sizeof(int) * dap_maxvar, "dap_maxvar");
  /* allocate string for name of output dataset, 5 for ".reg" with null */
  regname = dap_malloc(strlen(fname) + 5, "");
  /* and assign name */
  dap_suffix(regname, fname, ".lgr");
  /* set of arrays of variables indices */
  inset(fname);
  /* allocate intercept variable */
  dap_vd("_intercept_ -1", 0);
  /* find numbers of variables and assign indices to arrays */
  nx0 = dap_list("_intercept_", varv, dap_maxvar);
  nx0 += dap_list(x0list, varv + 1, dap_maxvar);
  nx1 = dap_list(x1list, varv + nx0, dap_maxvar);
  /* total number of x-variables, including intercept */
  nx = nx0 + nx1;
  /* parse the y-specifications and assign their variable indices */
  dap_parsey(yspec, varv + nx);
  /* allocate memory of array of explanatory x-vectors */
  xmem = (double *) dap_malloc(sizeof(double) * nx * dap_maxval, "dap_maxval");
  /* and allocate and assign pointers */
  x = (double **) dap_malloc(sizeof(double *) * nx, "");
  for (v = 0; v < nx; v++)
    x[v] = xmem + v * dap_maxval;
  /* allocate array for response variable values */
  ymem = (double *) dap_malloc(sizeof(double) * 2 * dap_maxval, "dap_maxval");
  /* and assign pointers: y[0] for response variable, y[1] for number of cases */
  y[0] = ymem;
  y[1] = ymem + dap_maxval;
  /* set up partitioning for main dataset */
  nmark = dap_list(marks, markv, dap_maxvar);
  /* do some bookkeeping for covariance dataset */
  covset = dap_malloc(strlen(fname) + 5, "");
  strcpy(covset, fname);
  strcat(covset, ".cov");
  /* find maximum length of variable names */
  for (v = 1, paramlen = strlen("_intercept_"); v < nx; v++)
    {
      paramlen1 = strlen(dap_obs[dap_ono].do_nam[varv[v]]);
      if (paramlen1 > paramlen)
	paramlen = paramlen1;
    }
  /* now set up variables for covariance dataset */
  dap_ono = 2;
  dap_clearobs((char *) NULL);    /* set up dap_obs, make _type_ variable */
  /* this will bomb if a variable name is more than 99 characters long */
  sprintf(paramstr, "_param1_ %d", paramlen);
  param1n = dap_vd(paramstr, 0);
  sprintf(paramstr, "_param2_ %d", paramlen);
  param2n = dap_vd(paramstr, 0);
  covn = dap_vd("_cov_ -1", 0);
  partstr = dap_malloc(strlen(marks) + 1, "");
  for (v = 0; v < nmark; v++)
    {
      strcpy(partstr, dap_obs[0].do_nam[markv[v]]);
      sprintf(partstr + strlen(partstr), " %d", dap_obs[0].do_len[markv[v]]);
      partv[v] = dap_vd(partstr, 1);
    }
  outset(covset, "");
  /* now switch to xname dataset */
  dap_ono = 1;
  if (xname && xname[0])	/* if caller wants predicted values */
    {
      inset(xname);
      /* find numbers of explanatory x-variables */
      nxx = dap_list(x0list, xvarv, dap_maxvar);
      nxx += dap_list(x1list, xvarv + nxx, dap_maxvar);
      /* which had better match those of the main dataset */
      if (nxx != nx - 1)
	{
	  fprintf(dap_err,
		  "(logreg) %s and %s have different numbers (%d and %d) of x-variables.\n",
		  fname, xname, nx - 1, nxx);
	  exit(1);
	}
      if (nmark)	/* cross-check partitioning of main and xname datasets */
	{
	  for (v = 0; v < nmark; v++)
	    {
	      if ((xmarkv[v] = dap_varnum(dap_obs[0].do_nam[markv[v]])) < 0)
		{
		  fprintf(dap_err,
			  "(logreg) Mark variable %s in %s not in %s.\n",
			  dap_obs[0].do_nam[markv[v]], fname, xname);
		  exit(1);
		}
	    }
	}
      if (!step())
	{
	  fprintf(dap_err, "(logreg) No data in %s.\n",
		  (xname[0] ? xname : fname));
	  exit(1);
	}
    }
  else		/* caller doesn't want predicted values */
    {
      xvarv[0] = -1;
      xmarkv[0] = -1;
    }
  /* back to main dataset */
  dap_ono = 0;
  outset(regname, "");
  /* for each observation; use dap_mark for backing up in dataset */
  for (nobs = 0, dap_mark(), more = 1; more; nobs++)
    {
      more = step();	/* read line, if any */
      if (dap_newpart(markv, nmark))	/* if new part or end reached */
	{
	  dap_swap();	/* print head for this part */
	  dap_head(markv, nmark);
	  dap_swap();
	  /* and run logistic regression on it */
	  logreg1(y, x, nx0, nx, nobs, varv, xvarv, markv, xmarkv, nmark, level,
		  param1n, param2n, covn, partv);
	  nobs = 0;	/* clean slate for next part */
	}
      if (nobs < dap_maxval)	/* if room for more data... */
	{
	  x[0][nobs] = 1.0;	/* this is the intercept, gets 1 in X matrix */
	  for (v = 1; v < nx; v++)	/* read in x-values */
	    x[v][nobs] = dap_obs[dap_ono].do_dbl[varv[v]];
	  y[0][nobs] = dap_obs[dap_ono].do_dbl[varv[nx]];	/* and y-values */
	  if (varv[nx + 1] >= 0)	/* if number-of-cases variable exists, read it */
	    y[1][nobs] = dap_obs[dap_ono].do_dbl[varv[nx + 1]];
	  else			/* else assign from constant give by parsey */
	    y[1][nobs] = -(double) varv[nx + 1];
	}
      else		/* ... or not */
	{
	  fputs("(logreg) Too many data.\n", dap_err);
	  exit(1);
	}
    }
  /* release all allocated memory */
  dap_free(regname, "");
  dap_free(varv, "");
  dap_free(xvarv, "");
  dap_free(markv, "");
  dap_free(xmarkv, "");
  dap_free(xmem, "");
  dap_free(x, "");
  dap_free(ymem, "");
  dap_free(covset, "");
  dap_free(partstr, "");
  dap_free(partv, "");
}

typedef struct {
  int val_class;
  double val_val;
} value;

static int valcmp1(value *v1, value *v2)
{
  if (v1->val_val < v2->val_val)
    return -1;
  if (v1->val_val > v2->val_val)
    return 1;
  return 0;
}

static double probkol(double d, double n)
{
  double lambda;
  double l;
  double k;
  double term;
  int sign;

  if (d == 0.0)
    return 0.0;
  lambda = d * sqrt(n);
  lambda *= -2.0 * lambda;
  for (k = 1.0, l = 0.0, sign = 1;
       (term = exp(k * k * lambda)) > dap_ktol; k += 1.0, sign = -sign)
    l += (sign > 0 ? term : -term);
  return 2.0 * l;
}

static int (*pvalcmp1)() = &valcmp1;

static void nonpar1(value *val, int nval, char **level,
		    int nlevels, int *varv, int nvar)
{
  int rank, ntied, tied;
  int tottied;
  double tiecorr;
  double drank;
  double dn;
  double stat0, stat;
  double prob;
  int *levnobs;
  int minnobs;
  int *rank1;
  int r;
  int levn;
  double *sumr;
  double tmp, tmp1;
  double kold;
  int kolr;
  double kolval;
  double f[2];

  tmp = 0.0;
  tmp1 = 0.0;
  kolr = 0;
  kolval = 0.0;
  dap_swap();
  levnobs = (int *) dap_malloc(sizeof(int) * nlevels, "");
  sumr = (double *) dap_malloc(sizeof(double) * nlevels, "");
  rank1 = (int *) dap_malloc(sizeof(int) * dap_maxex2, "dap_maxex2");
  dn = (double) nval;
  if (nvar == 2)
    {
      qsort(val, nval, sizeof(value), pvalcmp1);
      for (levn = 0; levn < nlevels; levn++)
	levnobs[levn] = 0;
      for (rank = 0; rank < nval; rank++)
	levnobs[val[rank].val_class]++;
      if (nlevels == 2)
	{
	  for (rank = 0, stat0 = 0.0, stat = 0.0, tottied = 0,
		 tiecorr = 0.0, f[0] = 0.0, f[1] = 0.0,
		 kold = 0.0; rank < nval; )
	    {
	      for (ntied = 1; rank + ntied < nval &&
		     fabs(val[rank + ntied].val_val - val[rank].val_val) <
		     dap_tol * (fabs(val[rank + ntied].val_val) + fabs(val[rank].val_val));
		   ntied++)
		;
	      drank = ((double) (2 * rank + ntied + 1)) / 2.0; 
	      if (ntied > 1)
		{
		  tottied += ntied;
		  tiecorr += (double) (ntied * (ntied + 1) * (ntied - 1));
		}
	      for (tied = 0; tied < ntied; tied++, rank++)
		{
		  if (val[rank].val_class)
		    {
		      stat0 += drank;
		      f[1] += 1.0;
		    }
		  else
		    {
		      stat += drank;
		      f[0] += 1.0;
		    }
		  tmp1 = val[rank].val_val;
		  val[rank].val_val = drank;
		}
	      tmp = fabs(f[1] / ((double) levnobs[1]) - f[0] / ((double) levnobs[0]));
	      if (tmp > kold)
		{
		  kold = tmp;
		  kolr = rank;
		  kolval = tmp1;
		}
	    }
	  fprintf(dap_lst, "\nResponse: %s\n", dap_obs[0].do_nam[varv[0]]);
	  fprintf(dap_lst, "Classified by %s:", dap_obs[0].do_nam[varv[1]]);
	  for (r = 0; r < nlevels; r++)
	    fprintf(dap_lst, " %s (%d)", level[r], levnobs[r]);
	  putc('\n', dap_lst);
	  fprintf(dap_lst, "Number of tied observations = %d\n", tottied);
	  if (levnobs[0] < levnobs[1])
	    {
	      levn = 0;
	      stat0 = stat;
	    }
	  else
	    levn = 1;
	  fprintf(dap_lst, "\nWilcoxon rank sum statistic S0 (%s) = %g\n",
		  level[0], stat0);
	  fprintf(dap_lst, "Expected under H0 = %g\n",
		  ((double) levnobs[levn]) * (dn + 1.0) / 2.0);
	  stat0 = fabs(stat0 - ((double) levnobs[levn]) * (dn + 1.0) / 2.0);
	  if (nval < dap_maxex2)
	    {
	      for (r = 0; r < levnobs[levn]; r++)
		rank1[r] = r;
	      rank1[r] = nval;
	      for (prob = 0.0; ; )
		{
		  for (r = 0, stat = -((double) levnobs[levn]) * (dn + 1.0) / 2.0;
		       r < levnobs[levn]; r++)
		    stat += val[rank1[r]].val_val;
		  if (fabs(stat) >= stat0)
		    prob += 1.0;
		  for (r = levnobs[levn] - 1;
		       r >= 0 && rank1[r] + 1 == rank1[r + 1]; --r)
		    ;
		  if (r >= 0)
		    {
		      rank1[r]++;
		      for (r++; r < levnobs[levn]; r++)
			rank1[r] = rank1[r - 1] + 1;
		    }
		  else
		    break;
		}
	      fprintf(dap_lst, "Prob[|S - E(S)| >= |S0 - E(S)|] = %.4g (exact)\n",
		      prob / dap_bincoeff(dn, (double) levnobs[levn]));
	    }
	  else
	    {
	      if (stat0 >= 0.5)
		stat0 -= 0.5;
	      prob = 2.0 * (1.0 - probz(stat0 /
					sqrt(((double) (levnobs[0] * levnobs[1])) *
					     ((dn + 1.0) - tiecorr /
					      (dn * (dn - 1.0))) / 12.0)));
	      fprintf(dap_lst, "Prob[|S - E(S)| >= |S0 - E(S)|] = %.4g\n", prob);
	      fputs("(normal approximation, with continuity correction)\n", dap_lst);
	    }
	  fprintf(dap_lst, "\nKolmogorov statistic D0 = %g\n", kold);
	  fprintf(dap_lst, "Maximum deviation at %g for level %s\n",
		  kolval, level[val[kolr].val_class]);
	  fprintf(dap_lst, "Prob[D >= D0] = %.4g\n",
		  probkol(kold, ((double) (levnobs[0] * levnobs[1])) / dn));
	}
      else if (nlevels > 2)
	{
	  for (levn = 0; levn < nlevels; levn++)
	    sumr[levn] = 0.0;
	  for (rank = 0, tottied = 0, tiecorr = 0.0; rank < nval; )
	    {
	      for (ntied = 1; rank + ntied < nval &&
		     fabs(val[rank + ntied].val_val - val[rank].val_val) <
		     dap_tol * (fabs(val[rank + ntied].val_val) + fabs(val[rank].val_val));
		   ntied++)
		;
	      drank = ((double) (2 * rank + ntied + 1)) / 2.0; 
	      if (ntied > 1)
		{
		  tottied += ntied;
		  tiecorr += (double) (ntied * (ntied + 1) * (ntied - 1));
		}
	      for (tied = 0; tied < ntied; tied++, rank++)
		{
		  sumr[val[rank].val_class] += drank;
		  val[rank].val_val = drank;
		}
	    }
	  for (stat0 = 0.0, levn = 0; levn < nlevels; levn++)
	    {
	      tmp = sumr[levn] / ((double) levnobs[levn]) - 0.5 * (dn + 1.0);
	      stat0 += tmp * tmp * (double) levnobs[levn];
	    }
	  stat0 *= 12.0 / (dn * (dn + 1.0) - tiecorr / (dn - 1.0));
	  fprintf(dap_lst, "\nResponse: %s\n", dap_obs[0].do_nam[varv[0]]);
	  fprintf(dap_lst, "Classified by %s:", dap_obs[0].do_nam[varv[1]]);
	  for (levn = 0, minnobs = levnobs[0]; levn < nlevels; levn++)
	    {
	      fprintf(dap_lst, " %s (%d)", level[levn], levnobs[levn]);
	      if (levnobs[levn] < minnobs)
		minnobs = levnobs[levn];
	    }
	  putc('\n', dap_lst);
	  fprintf(dap_lst, "Number of tied observations = %d\n", tottied);
	  fprintf(dap_lst, "Kruskal-Wallis statistic T0 = %g\n", stat0);
	  prob = probchisq(stat0, nlevels - 1);
	  fprintf(dap_lst,
		  "Prob[T >= T0] = %g (chi-squared approximation, df = %d)\n",
		  prob, nlevels - 1);
	  if ((nlevels == 3 && minnobs < 6) || minnobs < 5)
	    fputs(
		  "Warning: sample may be too small for this approximation.\n",
		  dap_lst);
	}
    }
  else
    {
      fprintf(dap_lst, "\nResponse: %s\n", dap_obs[0].do_nam[varv[0]]);
      fprintf(dap_lst, "Number of non-zero observations = %d\n", nval);
      qsort(val, nval, sizeof(value), pvalcmp1);
      for (rank = 0, stat0 = 0.0, tottied = 0, tiecorr = 0, levnobs[0] = 0; rank < nval; )
	{
	  for (ntied = 1; rank + ntied < nval &&
		 fabs(val[rank + ntied].val_val - val[rank].val_val) <
		 dap_tol * (fabs(val[rank + ntied].val_val) + fabs(val[rank].val_val));
	       ntied++)
	    ;
	  drank = ((double) (2 * rank + ntied + 1)) / 2.0; 
	  if (ntied > 1)
	    {
	      tottied += ntied;
	      tiecorr += ((double) (ntied * (ntied + 1) * (ntied - 1))) / 2.0;
	    }
	  for (tied = 0; tied < ntied; tied++, rank++)
	    {
	      if (val[rank].val_class)
		{
		  stat0 += drank;
		  levnobs[0]++;
		}
	      val[rank].val_val = drank;
	    }
	}
      fprintf(dap_lst, "Number of tied observations = %d\n", tottied);
      fprintf(dap_lst, "Number of positive observations = %d\n", levnobs[0]);
      fprintf(dap_lst, "\nWilcoxon signed rank statistic W0 = %g\n", stat0);
      fprintf(dap_lst, "Expected under H0 = %g\n", (dn * (dn + 1.0)) / 4.0);
      stat0 = fabs(stat0 - (dn * (dn + 1.0)) / 4.0);
      if (nval <= dap_maxex1)
	{
	  for (rank = 0; rank < nval; rank++)
	    val[rank].val_class = 0;
	  prob = 0.0;
	  do	{
	    for (rank = 0, stat = -(dn * (dn + 1.0)) / 4.0;
		 rank < nval; rank++)
	      {
		if (val[rank].val_class)
		  stat += val[rank].val_val;
	      }
	    if (fabs(stat) >= stat0)
	      prob += 1.0;
	    for (rank = 0; rank < nval; rank++)
	      {
		if (!val[rank].val_class)
		  {
		    val[rank].val_class = 1;
		    break;
		  }
		else
		  val[rank].val_class = 0;
	      }
	  } while (rank < nval);
	  for (rank = 0; rank < nval; rank++)
	    prob /= 2.0;
	  fprintf(dap_lst, "Prob[|W - E(W)| >= |W0 - E(W)|] = %.4g (exact)\n", prob);
	}
      else
	{
	  prob = 2.0 *
	    probt(stat0 * sqrt((dn - 1.0) /
			       (dn * (dn * (dn + 1.0) * (2.0 * dn + 1.0) - tiecorr) /
				24.0 - stat0 * stat0)), nval - 1);
	  fprintf(dap_lst, "Prob[|W - E(W)| >= |W0 - E(W)|] = %.4g\n", prob);
	  fprintf(dap_lst, "(t-approximation, df = %d, with continuity correction)\n",
		  nval - 1);
	}
    }
  dap_free(levnobs, "");
  dap_free(rank1, "");
  dap_free(sumr, "");
  dap_swap();
}

static int findlev(char *levname, char **level, int *nlevels)
{
  int l;

  for (l = 0; l < *nlevels; l++)
    {
      if (!strcmp(levname, level[l]))
	return l;
    }
  if (*nlevels < dap_maxlev)
    {
      strcpy(level[*nlevels], levname);
      return (*nlevels)++;
    }
  else
    {
      fprintf(dap_err, "(findlev) Too many levels (%s)\n", levname);
      exit(1);
    }
}

void nonparam(char *fname, char *variables, char *marks)
{
  int varv[2];
  int nvar;
  int *markv;
  int nmark;
  value *val;
  int nval;
  int nobs;
  char *levmem;
  char **level;
  int nlevels;
  int more;

  if (!fname)
    {
      fputs("(nonparam) No dataset name given.\n", dap_err);
      exit(1);
    }
  markv = (int *) dap_malloc(sizeof(int) * dap_maxvar, "dap_maxvar");
  levmem = dap_malloc(dap_maxlev * (dap_strlen + 1), "dap_maxlev, dap_strlen");
  level = (char **) dap_malloc(sizeof(char *) * dap_maxlev, "dap_maxlev");
  for (nlevels = 0; nlevels < dap_maxlev; nlevels++)
    level[nlevels] = levmem + nlevels * (dap_strlen + 1);
  inset(fname);
  nvar = dap_list(variables, varv, dap_maxvar);
  if (!nvar)
    {
      fputs("(nonparam) No variables specified.\n", dap_err);
      exit(1);
    }
  if (nvar > 2)
    {
      fputs("(nonparam) At most one response and one class variable allowed\n", dap_err);
      exit(1);
    }
  if (dap_obs[0].do_len[varv[0]] != DBL)
    {
      fprintf(dap_err, "(nonparam) Variable must be dap_double: %s\n",
	      dap_obs[0].do_nam[varv[0]]);
      exit(1);
    }
  if (nvar == 2 && dap_obs[0].do_len[varv[1]] <= 0)
    {
      fprintf(dap_err, "(nonparam) Classification variable must be dap_char: %s\n",
	      dap_obs[0].do_nam[varv[1]]);
      exit(1);
    }
  nmark = dap_list(marks, markv, dap_maxvar);
  val = (value *) dap_malloc(sizeof(value) * dap_maxval, "dap_maxval");
  for (more = 1, nlevels = 0, nval = 0, nobs = 0; more; nobs++)
    {
      more = step();
      if (dap_newpart(markv, nmark))
	{
	  dap_swap();
	  dap_head(markv, nmark);
	  dap_swap();
	  fprintf(dap_lst, "Number of observations = %d\n", nobs);
	  nonpar1(val, nval, level, nlevels, varv, nvar);
	  if (!more)
	    break;
	  nval = 0;
	  nobs = 0;
	  nlevels = 0;
	}
      if (nval >= dap_maxval)
	{
	  fputs("(nonparam) Too many values.\n", dap_err);
	  exit(1);
	}
      if (nvar == 2)
	{
	  val[nval].val_class =
	    findlev(dap_obs[0].do_str[varv[1]], level, &nlevels);
	  val[nval].val_val = dap_obs[0].do_dbl[varv[0]];
	  nval++;
	}
      else
	{
	  if (dap_obs[0].do_dbl[varv[0]] != 0.0)
	    {
	      val[nval].val_class = (dap_obs[0].do_dbl[varv[0]] > 0.0);
	      val[nval].val_val = fabs(dap_obs[0].do_dbl[varv[0]]);
	      nval++;
	    }
	}
    }
  dap_free(val, "");
  dap_free(markv, "");
  dap_free(levmem, "");
  dap_free(level, "");
}


