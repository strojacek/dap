/* dap4.c -- multivariate statistics */

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
extern char *dap_sttnm[NSTATS];

#define TUKEY 0
#define LSD 1
#define DUNNETT 2

static double gettwo(double x)
{
  double t;

  for (t = 1.0, x = fabs(x); t > x; t /= 2.0)
    ;
  while (t < x)
    t *= 2.0;
  return t;
}

/* Forward elimination on the coeff matrix in the columns for which
 * nobs = 0, using rows from 0 to row1 to eliminate in rows 0 through row2.
 * If nonz != NULL, then indicate non-zero rows. If byterm != 0, then
 * eliminate on all rows from 0 through row1, but only within terms on
 * rows row1 + 1 through row2 and also do backward elimination on these groups.
 */

static int rowred(double **coeff, int rterm[], int byterm,
		  int ncells, double nobs[], int row1, int row2, int *nonz)
{
  int *misscol;
  int celln;
  int ncols;
  int col, subcol;
  int row, subrow;
  int maxrow;
  double colmax;
  double rowmax;
  double tmp, tmp1, tmp2;
  int itmp;
  double mult1, mult2;
  int nterms;
  int *term;
  int t;
  int elimrow;

  nterms = 0;
  elimrow = 0;
  misscol = (int *) dap_malloc(sizeof(int) * ncells, "");
  term = (int *) dap_malloc(sizeof(int) * ncells, "");
  if (byterm)
    {
      nterms = 0;
      term[nterms++] = 0;
      for (row = row1 + 1; row <= row2; row++)
	{
	  for (t = 1; t < nterms; t++)
	    {
	      if (rterm[row] == term[t])
		break;
	    }
	  if (t == nterms)
	    term[nterms++] = rterm[row];
	}
    }
  for (celln = 0, ncols = 0; celln < ncells; celln++)
    {
      if (nobs[celln] == 0.0)
	misscol[ncols++] = celln;
    }
  for (t = 0; (byterm && t < nterms) || t < 1; t++)
    {
      for (row = (t ? row1 + 1 : 0); row <= (t ? row2 : row1); row++)
	{
	  if (!byterm || row <= row1 || rterm[row] == term[t])
	    break;
	}
      for (col = 0; col < ncols; col++)
	{
	  while (byterm && row > row1 && rterm[row] != term[t] &&
		 row < (t ? row2 : row1))
	    row++;
	  for (colmax = 0.0, maxrow = row, subrow = row;
	       subrow <= (t ? row2 : row1); subrow++)
	    {
	      if (byterm && subrow > row1 && rterm[subrow] != term[t])
		continue;
	      if ((tmp = fabs(coeff[subrow][misscol[col]])) > colmax)
		{
		  colmax = tmp;
		  maxrow = subrow;
		}
	    }
	  if (colmax > dap_redtol)
	    {
	      if (maxrow != row)
		{
		  for (subcol = 0; subcol < ncells; subcol++)
		    {
		      tmp = coeff[row][subcol];
		      coeff[row][subcol] = coeff[maxrow][subcol];
		      coeff[maxrow][subcol] = tmp;
		      itmp = rterm[row];
		      rterm[row] = rterm[maxrow];
		      rterm[maxrow] = itmp;
		    }
		}
	      for (subrow = row + 1; subrow <= row2; subrow++)
		{
		  if (byterm && subrow > row1 && rterm[subrow] != term[t])
		    continue;
		  mult1 = coeff[subrow][misscol[col]];
		  mult2 = coeff[row][misscol[col]];
		  if (fabs(mult1) > dap_redtol * fabs(mult2))
		    {
		      for (subcol = 0, rowmax = 0.0; subcol < ncells; subcol++)
			{
			  tmp = mult2 * coeff[subrow][subcol];
			  tmp1 = mult1 * coeff[row][subcol];
			  coeff[subrow][subcol] = tmp - tmp1;
			  tmp2 = fabs(coeff[subrow][subcol]);
			  if (tmp2 < dap_redtol * (fabs(tmp) + fabs(tmp1)))
			    coeff[subrow][subcol] = 0.0;
			  else if (tmp2 > rowmax)
			    rowmax = tmp2;
			}
		      tmp = gettwo(rowmax);
		      for (subcol = 0; subcol < ncells; subcol++)
			{
			  coeff[subrow][subcol] /= tmp;
			  if (fabs(coeff[subrow][subcol]) < dap_redtol)
			    coeff[subrow][subcol] = 0.0;
			}
		    }
		}
	      row++;
	    }
	}
      if (!t)
	elimrow = row;
    }
  if (byterm)
    {
      for (t = 0; t < nterms; t++)
	{
	  for (row = (t ? row2 : row1); row > (t ? row1 + 1 : 0); --row)
	    {
	      if (row <= row1 || rterm[row] == term[t])
		break;
	    }
	  for ( ; row > (t ? row1 + 1 : 0); --row)
	    {
	      if (row > row1 && rterm[row] != term[t])
		continue;
	      for (col = 0; col < ncols; col++)
		{
		  if (fabs(coeff[row][misscol[col]]) > dap_redtol)
		    break;
		}
	      if (col < ncols)
		{
		  for (subrow = row - 1; subrow >= (t ? row1 + 1: 0); --subrow)
		    {
		      if (subrow > row1 && rterm[subrow] != term[t])
			continue;
		      mult1 = coeff[subrow][misscol[col]];
		      mult2 = coeff[row][misscol[col]];
		      if (fabs(mult1) > dap_redtol * fabs(mult2))
			{
			  for (col = 0, rowmax = 0.0; col < ncells; col++)
			    {
			      tmp = mult2 * coeff[subrow][col];
			      tmp1 = mult1 * coeff[row][col];
			      coeff[subrow][col] = tmp - tmp1;
			      if (fabs(coeff[subrow][col]) <
				  dap_redtol * (fabs(tmp) + fabs(tmp1)))
				coeff[subrow][col] = 0.0;
			      else if (fabs(coeff[subrow][col]) > rowmax)
				rowmax = fabs(coeff[subrow][col]);
			    }
			  tmp = gettwo(rowmax);
			  for (col = 0; col < ncells; col++)
			    {
			      coeff[subrow][col] /= tmp;
			      if (fabs(coeff[subrow][col]) < dap_redtol)
				coeff[subrow][col] = 0.0;
			    }
			}
		    }
		}
	    }
	}
    }
  if (nonz)
    {
      for (row = 0; row <= row2; row++)
	{
	  nonz[row] = 0;
	  for (col = 0; col < ncells; col++)
	    {
	      if (fabs(coeff[row][col]) > dap_zerotol)
		{
		  if (nobs[col] > 0.0)
		    {
		      nonz[row] = 1;
		      break;
		    }
		}
	    }
	}
    }
  dap_free(misscol, "");
  dap_free(term, "");
  if (elimrow == ncols)
    return elimrow;
  fputs("error terms insufficient to impute missing cells\n", dap_err);
  exit(1);
}

static double lcm(double x, double y)
{
  int ix, iy;
  int q, r;
  int lcmxy;

  ix = (int) x;
  iy = (int) y;
  lcmxy = ix * iy;
  for ( ; ; )
    {
      q = iy / ix;
      r = iy - q * ix;
      if (r)
	{
	  iy = ix;
	  ix = r;
	}
      else
	break;
    }
  return (double) (lcmxy / ix);
}

/* Using modified Gram-Schmidt using row0 up (or down) through * row1
 * to orthogonalize rows0 through row2 with respect to rows row0 through
 * row1. Return number of independent rows.
 */

static int orthog(double **coeff, int row0, int row1, int row2,
		  int ncells, double *nobs, int *indep, int *rterm)
{
  double lcmnobs;
  int updown;
  int *term;
  int nterms;
  int t;
  int cr;
  int cc;
  int crr;
  double lensq;
  double dot;
  double tmp, tmp1;
  double mult1, mult2;
  double rowmax;
  int df;

  nterms = 0;
  term = (int *) dap_malloc(sizeof(int) * ncells, "");
  if (row2 >= row0)
    updown = 1;
  else
    updown = -1;
  df = 0;
  if (rterm)
    {
      for (cr = row0, nterms = 0; cr != row2 + updown; cr += updown)
	{
	  for (t = 0; t < nterms; t++)
	    {
	      if (rterm[cr] == term[t])
		break;
	    }
	  if (t == nterms)
	    term[nterms++] = rterm[cr];
	}
    }
  for (cc = 0, lcmnobs = 1.0; cc < ncells; cc++)
    {
      if (nobs[cc] != 0.0)
	lcmnobs = lcm(lcmnobs, nobs[cc]);
    }
  lcmnobs /= gettwo(lcmnobs);
  for (t = 0; (rterm && t < nterms) || t < 1; t++)
    {
      for (cr = row0; cr != row1 + updown; cr += updown)
	{
	  if (rterm && rterm[cr] != term[t])
	    continue;
	  for (cc = 0; cc < ncells; cc++)
	    {
	      if (fabs(coeff[cr][cc]) > dap_orthtol)
		break;
	    }
	  if (cc < ncells)
	    break;
	}
      for ( ; cr != row1 + updown; cr += updown)
	{
	  if (rterm && rterm[cr] != term[t])
	    continue;
	  for (lensq = 0.0, cc = 0; cc < ncells; cc++)
	    {
	      if (nobs[cc] > 0.0)
		{
		  tmp = coeff[cr][cc];
		  lensq += tmp * tmp * (lcmnobs / nobs[cc]);
		}
	    }
	  if (lensq > dap_orthtol)
	    {
	      indep[cr] = 1;
	      df++;
	      for (crr = cr + updown; crr != row2 + updown; crr += updown)
		{
		  if (rterm && rterm[crr] != term[t])
		    continue;
		  for (dot = 0.0, cc = 0; cc < ncells; cc++)
		    {
		      if (nobs[cc] > 0.0)
			dot += coeff[cr][cc] * coeff[crr][cc] *
			  (lcmnobs / nobs[cc]);
		    }
		  if (fabs(dot) > dap_orthtol * lensq)
		    {
		      mult1 = dot;
		      mult2 = lensq;
		      for (cc = 0, rowmax = 0.0; cc < ncells; cc++)
			{
			  tmp = mult2 * coeff[crr][cc];
			  tmp1 = mult1 * coeff[cr][cc];
			  coeff[crr][cc] = tmp - tmp1;
			  if (fabs(coeff[crr][cc]) <
			      dap_orthtol *
			      (fabs(tmp) + fabs(tmp1)))
			    coeff[crr][cc] = 0.0;
			  else if (fabs(coeff[crr][cc]) > rowmax)
			    rowmax = fabs(coeff[crr][cc]);
			}
		      tmp = gettwo(rowmax);
		      for (cc = 0; cc < ncells; cc++)
			{
			  coeff[crr][cc] /= tmp;
			  if (fabs(coeff[crr][cc]) < dap_orthtol)
			    coeff[crr][cc] = 0.0;
			}
		    }
		}
	    }
	  else
	    {
	      for (cc = 0; cc < ncells; cc++)
		coeff[cr][cc] = 0.0;
	    }
	}
      while (cr != row2 + updown)
	{
	  if (!rterm || rterm[cr] == term[t])
	    {
	      for (lensq = 0.0, cc = 0; cc < ncells; cc++)
		{
		  if (nobs[cc] > 0.0)
		    {
		      tmp = coeff[cr][cc];
		      lensq += tmp * tmp * (lcmnobs / nobs[cc]);
		    }
		}
	      if (lensq > dap_orthtol)
		{
		  indep[cr] = 1;
		  df++;
		}
	    }
	  cr += updown;
	}
    }
  dap_free(term, "");
  return df;
}

/* Check that rows for error terms sum to zero in coeff matrix */

static void sumcheck(char caller[], double **coeff,
		     int ncells, int nerrors, int ncontrasts, int *rterm)
{
  int r, c;
  double elt;
  double rowsum;
  double rowmax;

  for (r = 0; r < nerrors + ncontrasts; r++)
    {
      for (c = 0, rowsum = 0.0, rowmax = 0.0; c < ncells; c++)
	{
	  elt = coeff[r][c];
	  rowsum += elt;
	  elt = fabs(elt);
	  if (elt > rowmax)
	    rowmax = elt;
	}
      if (fabs(rowsum) > dap_zerotol * rowmax)
	{
	  fprintf(dap_err, "(sumcheck:%s) Unable to fit model:\n", caller);
	  if (r < nerrors)
	    fprintf(dap_err, "Error %d sums to %g:\n", r, rowsum);
	  else
	    fprintf(dap_err, "Contrast %d sums to %g:\n", r - nerrors, rowsum);
	  fprintf(dap_err, "%s%d (%x) ",
		  ((r < nerrors) ? "E" : "C"),
		  ((r < nerrors) ? r : r - nerrors),
		  (rterm ? rterm[r] : 0));
	  for (c = 0; c < ncells; c++)
	    fprintf(dap_err, " %g", coeff[r][c]);
	  putc('\n', dap_err);
	  exit(1);
	}
    }
}

/* Testparse allows for up to dap_maxtreat variables in the model, although such
 * a large number would be impractical. Each member of the termv[]
 * array corresponds to one effect in the test. Each bit of the index
 * of that member indicates whether the variable with the corresponding 
 * index in varv[] is in the term and the value of the member is 'c' for
 * contrast, 'n' for nested effect (not assigned here), 'e' for error. Returns total
 * number of terms in model and residual.
 */

static int testparse(char *test, char *termv, int *varv, int nvars)
{
  int nterms;	/* total number of terms in model and residual */
  int tv;	/* index to termv: bits of tv indicate variables in the term */
  char *vname;  /* variable name */
  int t;      	/* index to char *test */
  int n;	/* index to vname[] */
  int bit;	/* bit to set for presence of variable in term */
  int term;	/* bits for entire term */
  int vv;	/* index to varv */
  int v;	/* index of variable dap_obs */
  int firstv;	/* first variable in term */

  term = 0;
  vname = dap_malloc(dap_namelen + 1, "");
  if (!test || !test[0])
    return 0;
  /* compute the maximum possible number of terms for nvars variables with crossing */
  for (nterms = 1, tv = 1; tv < nvars; tv++)
    nterms *= 2;
  nterms--; /* but the empty term isn't interesting */
  for (tv = 1; tv <= nterms; tv++) /* all terms are error terms until proved to be contrasts */
    termv[tv] = 'e';
  for (t = 0; test[t] == ' '; t++) /* skip leading blanks of test string */
    ;
  for (firstv = 1; test[t]; )
    {
      if (firstv)
	term = 0;
      firstv = 0;
      for (n = 0; test[t] && test[t] != ' ' && test[t] != '*'; )
	{ /* copy variable name from test string */
	  if (n < dap_namelen)
	    vname[n++] = test[t++];
	  else
	    {
	      vname[n] = '\0';
	      fprintf(dap_err, "(testparse) name too long: %s\n", vname);
	      exit(1);
	    }
	}
      vname[n] = '\0';
      if ((v = dap_varnum(vname)) < 0)
	{
	  fprintf(dap_err, "(testparse) unknown variable: %s\n", vname);
	  exit(1);
	}
      for (bit = 0x1, vv = 1; vv < nvars; vv++, bit = (bit << 1))
	{
	  if (varv[vv] == v)
	    break;
	}
      if (vv == nvars)
	{
	  fprintf(dap_err, "(testparse) variable in test not in model: %s\n", vname);
	  exit(1);
	}
      term |= bit;
      while (test[t] == ' ')
	t++;
      if (test[t] == '*')
	{
	  for (t++; test[t] == ' '; t++)
	    ;
	}
      else
	{
	  termv[term] = 'c';
	  firstv = 1;
	}
    }
  dap_free(vname, "");
  return nterms;
}

static int levn(char *levstr, char **levval, int *nlevels)
{
  int l;

  for (l = 0; l < *nlevels && levval[l][0]; l++)
    {
      if (!strcmp(levstr, levval[l]))
	return l;
    }
  if (l < dap_maxlev - 1)
    {
      strcpy(levval[l], levstr);
      if (l < *nlevels)
	return *nlevels;
      else
	return (*nlevels)++;
    }
  else
    {
      fprintf(dap_err, "(levn) too many levels: %s\n", levstr);
      exit(1);
    }
}

static void putrand(int bits, double coeff, int varv[])
{
  int v;
  int termn;

  if (coeff != 0.0)
    fprintf(dap_lst, "\n    %g Var(", coeff);
  for (v = 1, termn = 1; bits; bits = (bits >> 1), v++)
    {
      if (bits & 0x1)
	{
	  if (termn > 1)
	    putc('*', dap_lst);
	  fputs(dap_obs[0].do_nam[varv[v]], dap_lst);
	  termn++;
	}
    }
  if (coeff != 0.0)
    putc(')', dap_lst);
}

/* Compute expected mean squares.
 * Returns value of "factor".
 */
static int ems(double **coeff, int **level, int ncells,
	       int *rterm, int *indep, int nrows, double *nobs,
	       int *varv, char *termv, int nterm, double **emscoeff)
{
  int r;		/* row in coefficient matrix */
  int t;		/* term bits for effect to be decomposed */
  int u;		/* term bits for factors */
  int c;		/* column in coefficient matrix */
  double *cum;
  double df;	/* denominator degrees of freedom */
  int *effrow;
  int neffrows;
  int *factlev;
  int nfactlevs;
  int bits;
  double *emsc;
  double *lensq;	/* squared length of coeff matrix row */
  int basecell;
  int nextcell;
  int *used;
  int s;
  int same;
  double tmp;
  int factor; /* ?? */

  cum = (double *) dap_malloc(sizeof(double) * ncells, "");
  emsc = (double *) dap_malloc(sizeof(double) * ncells, "");
  lensq = (double *) dap_malloc(sizeof(double) * ncells, "");
  effrow = (int *) dap_malloc(sizeof(int) * ncells, "");
  factlev = (int *) dap_malloc(sizeof(int) * ncells, "");
  used = (int *) dap_malloc(sizeof(int) * ncells, "");
  for (r = 0; r < nrows; r++)
    emsc[r] = 0.0;
  emscoeff++;		/* room for error */
  for (t = 1, factor = 0; t <= nterm; t++)
    {
      if (termv[t] == 'c' || termv[t] == 'n')
	{
	  if (varv)
	    {
	      fputs("EMS(", dap_lst);
	      putrand(t, 0.0, varv);
	      fputs(") =", dap_lst);
	    }
	  emscoeff[factor][0] = 1.0;	/* space for EMS(Error) */
	  for (r = 0, neffrows = 0; r < nrows; r++)
	    {
	      if (indep[r] && rterm[r] == t)
		effrow[neffrows++] = r;
	    }
	  for (u = 1; u <= nterm; u++)
	    {
	      for (r = 0; r < nrows; r++)
		{
		  if (indep[r] && rterm[r] == u)
		    break;
		}
	      if ((u & t) == t && r < nrows)
		{
		  for (bits = u, nfactlevs = 0, r = 1; bits; bits = (bits >> 1), r++)
		    {
		      if (bits & 0x1)
			factlev[nfactlevs++] = r;
		    }
		  for (r = 0; r < neffrows; r++)
		    {
		      if (indep[r])
			{
			  lensq[r] = 0.0;
			  emsc[r] = 0.0;
			}
		    }
		  for (c = 0; c < ncells; c++)
		    used[c] = 0;
		  for (basecell = 0, nextcell = 0; basecell < ncells; basecell = nextcell)
		    {
		      for (r = 0; r < neffrows; r++)
			cum[r] = 0.0;
		      for (c = basecell; c < ncells; )
			{
			  for (r = 0; r < neffrows; r++)
			    {
			      if (indep[r])
				{
				  tmp = coeff[effrow[r]][c];
				  cum[r] += tmp;
				  lensq[r] += tmp * tmp / nobs[c];
				}
			    }
			  used[c] = 1;
			  for (c++; c < ncells; c++)
			    {
			      for (s = 0, same = 1; s < nfactlevs; s++)
				{
				  if (level[factlev[s]][basecell] !=
				      level[factlev[s]][c])
				    {
				      if (nextcell == basecell &&
					  !used[c])
					nextcell = c;
				      same = 0;
				      break;
				    }
				}
			      if (same)
				break;
			    }
			}
		      for (r = 0; r < neffrows; r++)
			{
			  if (indep[r])
			    {
			      cum[r] *= cum[r];
			      emsc[r] += cum[r];
			    }
			}
		      if (nextcell == basecell)
			break;
		    }
		  for (r = 0; r < neffrows; r++)
		    {
		      if (indep[r])
			emsc[r] /= lensq[r];
		    }
		  for (r = 0, emscoeff[factor][u] = 0.0, df = 0.0; r < neffrows; r++)
		    {
		      if (indep[r])
			{
			  emscoeff[factor][u] += emsc[r];
			  df += 1.0;
			}
		    }
		  if (df > 0.0)
		    {
		      emscoeff[factor][u] /= df;
		      if (varv)
			putrand(u, emscoeff[factor][u], varv);
		    }
		  else
		    emscoeff[factor][u] = 0.0;
		}
	      else
		emscoeff[factor][u] = 0.0;
	    }
	  if (varv)
	    fputs("\n    1 Var(Error)\n", dap_lst);
	  factor++;
	}
    }
  dap_free(cum, "");
  dap_free(effrow, "");
  dap_free(factlev, "");
  dap_free(emsc, "");
  dap_free(lensq, "");
  dap_free(used, "");
  return factor;
}

static void putms(int bits, double coeff, int *varv)
{
  int v;
  int termn;

  if (coeff != 0.0)
    fprintf(dap_lst, "\n    %g MS(", coeff);
  if (bits)
    {
      for (v = 1, termn = 1; bits; bits = (bits >> 1), v++)
	{
	  if (bits & 0x1)
	    {
	      if (termn > 1)
		putc('*', dap_lst);
	      fputs(dap_obs[0].do_nam[varv[v]], dap_lst);
	      termn++;
	    }
	}
    }
  else if (coeff != 0.0)
    fputs("Error", dap_lst);
  if (coeff != 0.0)
    putc(')', dap_lst);
}

static int emssolve(double **emscoeff, int nterms, int nfactors,
		    int *varv, int *termv)
{
  int r, c;
  int maxr;
  int subr;
  int subc;
  double rowmax;
  double colmax;
  double maxmax;
  double tmp;
  int itmp;
  double mult;

  emscoeff[0][0] = 1.0;	/* for error */
  termv[0] = 0;
  for (r = 1; r <= nterms; r++)
    {
      emscoeff[0][r] = 0.0;
      termv[r] = r;
    }
  for (c = 1, r = 1; c <= nfactors; c++)
    {
      for (colmax = 0.0, maxmax = 0.0, maxr = r, subr = r; subr <= nterms; subr++)
	{
	  for (subc = c, rowmax = 0.0; subc <= nfactors; subc++)
	    {
	      if ((tmp = fabs(emscoeff[subc][subr])) > rowmax)
		rowmax = tmp;
	    }
	  if ((tmp = fabs(emscoeff[c][subr] / rowmax)) > colmax)
	    {
	      maxmax = rowmax;
	      colmax = tmp;
	      maxr = subr;
	    }
	}
      if (colmax > dap_redtol * maxmax)
	{
	  if (maxr != r)
	    {
	      for (subc = 0; subc <= nfactors + 1; subc++)
		{
		  tmp = emscoeff[subc][r];
		  emscoeff[subc][r] = emscoeff[subc][maxr];
		  emscoeff[subc][maxr] = tmp;
		}
	      itmp = termv[r];
	      termv[r] = termv[maxr];
	      termv[maxr] = itmp;
	    }
	  for (subr = 0; subr <= nterms; subr++)
	    {
	      if (subr == r)
		{
		  mult = emscoeff[c][subr];
		  for (subc = c; subc <= nfactors + 1; subc++)
		    emscoeff[subc][subr] /= mult;
		}
	      else
		{
		  mult = emscoeff[c][subr] / emscoeff[c][r];
		  if (fabs(mult) > dap_redtol * maxmax)
		    {
		      for (subc = c; subc <= nfactors + 1; subc++)
			{
			  tmp = fabs(emscoeff[subc][subr]);
			  emscoeff[subc][subr] -= mult * emscoeff[subc][r];
			  if (fabs(emscoeff[subc][subr]) < dap_redtol * tmp)
			    emscoeff[subc][subr] = 0.0;
			}
		    }
		}
	    }
	  r++;
	}
    }
  return r;
}

static void ftest1(double **coeff, int **level, int ncells,
		   int *rterm, int ncontrasts, int nerrors,
		   double *mean, double *vari, double *nobs, int *varv,
		   char *numv, int nnum, char *denv, int nden, int typen)
{
  int corow;
  int cc;
  int cr;
  double numer;
  double sq;
  double varnce;
  double tmp;
  double denom;
  double modelss;
  double n;
  int cdfi;
  int edfi;
  double dedfi;
  int *indep;
  double sse;
  int dfe;
  double *emsmem;
  double **emscoeff;
  int nfactors;
  int *termv;
  int ndenterm;
  int t;
  double ss, ms;
  double df;
  double dfdown, dfup;
  double fdown, fup;

  dedfi = 0.0;
  emsmem = NULL;
  emscoeff = NULL;
  ndenterm = 0;
  ss = 0.0;
  df = 0.0;
  sumcheck("ftest1", coeff, ncells, nerrors, ncontrasts, rterm);
  indep = (int *) dap_malloc(sizeof(int) * (nerrors + ncontrasts), "");
  if (nden)
    {
      emsmem = (double *) dap_malloc(sizeof(double) * 2 * ncells * ncells, "");
      emscoeff = (double **) dap_malloc(sizeof(double *) * 2 * ncells, "");
      for (cr = 0; cr < 2 * ncells; cr++)
	emscoeff[cr] = emsmem + cr * ncells;
    }
  termv = (int *) dap_malloc(sizeof(int) * ncells, "");
  denom = 0.0;
  for (cr = 0; cr < nerrors + ncontrasts; cr++)
    indep[cr] = 0;
  nfactors = 0;
  if (nerrors)
    {
      if (nden)
	{
	  edfi = orthog(coeff, 0, nerrors - 1, nerrors - 1,
			ncells, nobs, indep, rterm);
	  nfactors = ems(coeff, level, ncells, rterm, indep,
			 nerrors + ncontrasts,
			 nobs, varv, denv, nden, emscoeff);
	}
      else
	{
	  edfi = nerrors;
	  for (cr = 0; cr < nerrors; cr++)
	    {
	      for (cc = 0, sq = 0.0, varnce = 0.0; cc < ncells; cc++)
		{
		  tmp = coeff[cr][cc];
		  sq += tmp * mean[cc];
		  varnce += tmp * tmp / nobs[cc];
		}
	      denom += sq * sq / varnce;
	    }
	}
    }
  else
    edfi = 0;
  corow = nerrors + ncontrasts - 1;
  for (cc = 0, n = 0.0, sse = 0.0; cc < ncells; cc++)
    {
      if (nobs[cc] > 0.0)
	{
	  sse += (nobs[cc] - 1.0) * vari[cc];
	  n += nobs[cc];
	}
    }
  dfe = ((int) n) - ncells;
  if (nden)
    {
      orthog(coeff, nerrors, nerrors, corow, ncells, nobs, indep, NULL);
      cdfi = orthog(coeff, nerrors, corow, corow, ncells, nobs, indep, rterm);
      if (ems(coeff, level, ncells, rterm, indep, nerrors + ncontrasts,
	      nobs, varv, numv, nnum, emscoeff + nfactors) != 1)
	{
	  fputs("(ftest1) Only one one term allowed in numerator of F-test with denominator\n",
		dap_lst);
	  exit(1);
	}
      ndenterm = emssolve(emscoeff, nden, nfactors, varv, termv);
      fputs("Error for ", dap_lst);
      putms(rterm[nerrors], 0.0, varv);
      fputs(" =", dap_lst);
      for (t = 0, denom = 0.0, dedfi = 0.0; t < ndenterm; t++)
	{
	  if (termv[t] != rterm[nerrors] && emscoeff[nfactors + 1][t])
	    {
	      putms(termv[t], emscoeff[nfactors + 1][t], varv);
	      if (termv[t])
		{
		  for (cr = 0, ss = 0.0, df = 0.0;
		       cr < nerrors + ncontrasts; cr++)
		    {
		      if (rterm[cr] == termv[t] && indep[cr])
			{
			  for (cc = 0, sq = 0.0, varnce = 0.0;
			       cc < ncells; cc++)
			    {
			      tmp = coeff[cr][cc];
			      sq += tmp * mean[cc];
			      varnce += tmp * tmp / nobs[cc];
			    }
			  ss += sq * sq / varnce;
			  df += 1.0;
			}
		    }
		}
	      else
		{
		  ss = sse;
		  df = (double) dfe;
		}
	      if (ndenterm > 1)
		{
		  ms = ss / df;
		  tmp = emscoeff[nfactors + 1][t] * ms;
		  denom += tmp;
		  dedfi += tmp * tmp / df;
		}
	    }
	}
      putc('\n', dap_lst);
      if (ndenterm > 1)
	dedfi = denom * denom / dedfi;
      else
	{
	  denom = emscoeff[nfactors][t] * ss;
	  edfi = (int) df;
	}
    }
  else
    {
      denom += sse;
      cdfi = orthog(coeff, 0, corow, corow, ncells, nobs, indep, NULL) - edfi;
      edfi += dfe;
    }
  for (cr = nerrors, numer = 0.0; cr <= corow; cr++)
    {
      if (indep[cr])
	{
	  for (cc = 0, sq = 0.0, varnce = 0.0; cc < ncells; cc++)
	    {
	      tmp = coeff[cr][cc];
	      sq += tmp * mean[cc];
	      varnce += tmp * tmp / nobs[cc];
	    }
	  numer += sq * sq / varnce;
	}
    }
  fprintf(dap_lst, "Number of observations = %d\n", (int) n);
  fprintf(dap_lst, "H0 SS = %g, df = %d, MS = %g\n", numer, cdfi, numer / ((double) cdfi));
  modelss = numer;
  numer /= (double) cdfi;
  if (nerrors)
    fputs("Residual ", dap_lst);
  else
    fputs("Error ", dap_lst);
  if (nden && ndenterm > 1)
    {
      fprintf(dap_lst, "df = %g, MS = %g\n", dedfi, denom);
      numer /= denom;
      fprintf(dap_lst, "F0 = %g\n", numer);
      dfdown = floor(dedfi);
      dfup = ceil(dedfi);
      if (dfup == dfdown)
	fprintf(dap_lst, "Prob[F > F0] = %.5f\n",
		0.00001 * (ceil(100000.0 * probf(numer, cdfi, (int) dedfi))));
      else
	{
	  fdown = probf(numer, cdfi, (int) dfdown);
	  fup = probf(numer, cdfi, (int) dfup);
	  fprintf(dap_lst, "Prob[F > F0] = %.5f\n",
		  0.00001 * (ceil(100000.0 *
				  (fdown + (dedfi - dfdown) / (dfup - dfdown) *
				   (fup - fdown)))));
	}
    }
  else
    {
      dedfi = (double) edfi;
      fprintf(dap_lst, "SS = %g, df = %d, MS = %g\n", denom, edfi, denom / dedfi);
      if (ncontrasts + nerrors == ncells - 1)
	fprintf(dap_lst, "R-sq = %g\n", modelss / (modelss + denom));
      denom /= dedfi;
      numer /= denom;
      fprintf(dap_lst, "F0 = %g\nProb[F > F0] = %.5f\n",
	      numer, 0.00001 * (ceil(100000.0 * probf(numer, cdfi, edfi))));
    }
  strcpy(dap_obs[0].do_str[typen], "MSERROR");
  dap_obs[0].do_dbl[varv[0]] = denom;
  output();
  strcpy(dap_obs[0].do_str[typen], "ERRORDF");
  dap_obs[0].do_dbl[varv[0]] = dedfi;
  output();
  if (nden)
    {
      dap_free(emsmem, "");
      dap_free(emscoeff, "");
    }
  dap_free(indep, "");
  dap_free(termv, "");
}

static void puttest(char *testv, int ntest, int *varv, int nvars)
{
  int t;
  int v;
  int bits;
  int first;

  for (t = 1; t <= ntest; t++)
    {
      if (testv[t] == 'c' || testv[t] == 'n')
	{
	  for (bits = t, v = 1, first = 1; v < nvars; bits = (bits >> 1), v++)
	    {
	      if (bits & 0x1)
		{
		  if (first)
		    {
		      putc(' ', dap_lst);
		      first = 0;
		    }
		  else
		    putc('*', dap_lst);
		  fprintf(dap_lst, "%s", dap_obs[0].do_nam[varv[v]]);
		}
	    }
	}
    }
  putc('\n', dap_lst);
}

void ftest(char *fname, char *variables, char *numerator, char *denominator, char *marks)
{
  char *tstname; /* fname with .tst appended */
  int typen; /* index of _type_ variable */
  int termn; /* index of _term_ variable */
  int *varv; /* vector of indices of variables */
  int nvars; /* number of variables */
  int *markv; /* vector of indices of partitioning variables */
  int nmark; /* number of partitioning variables */
  int *rterm;
  int nnum;
  int nden;
  char *numv; /* numerator term vector */
  char *denv; /* denominator term vector */
  int num;
  int den;
  int t;
  int morecells;
  int more; /* for stepping through dataset: got one more line? */
  int statn;
  int gotm, gotn, gotv; /* got mean? got n? got variance? */
  char *levmem; /* memory for level names */
  char **levptr; /* pointers for setting up array */
  char ***levval; /* array of level values */
  int *nlevels;
  int *levelmem; /* memory for storing treatment level numbers */
  int **level; /* array of treatment level numbers */
  int v;
  int l;
  double *comem;
  double **coeff;
  double *mean;
  double *nobs;
  double *vari;
  int ncells;
  int ncontrasts;
  int nerrors;
  int err;
  int con;

  varv = (int *) dap_malloc(sizeof(int) * (dap_maxtreat + 1), "");
  markv = (int *) dap_malloc(sizeof(int) * dap_maxvar, "");
  rterm = (int *) dap_malloc(sizeof(int) * (dap_maxcell - 1), "");
  numv = dap_malloc(dap_maxcell, "");
  denv = dap_malloc(dap_maxcell, "");
  levmem = dap_malloc((dap_maxtreat + 1) * dap_maxlev * (dap_strlen + 1), "");
  levptr = (char **) dap_malloc(sizeof(char *) * (dap_maxtreat + 1) * dap_maxlev, "");
  levval = (char ***) dap_malloc(sizeof(char **) * (dap_maxtreat + 1), "");
  for (v = 0; v < dap_maxtreat + 1; v++)
    {
      levval[v] = levptr + v * dap_maxlev;
      for (l = 0; l < dap_maxlev; l++)
	levval[v][l] = levmem + v * dap_maxlev * (dap_strlen + 1) +
	  l * (dap_strlen + 1);
    }
  nlevels = (int *) dap_malloc(sizeof(int) * (dap_maxtreat + 1), "");
  levelmem = (int *) dap_malloc(sizeof(int) * (dap_maxtreat + 1) * dap_maxcell, "");
  level = (int **) dap_malloc(sizeof(int *) * (dap_maxtreat + 1), "");
  for (v = 0; v < dap_maxtreat + 1; v++)
    level[v] = levelmem + v * dap_maxcell;
  comem = (double *) dap_malloc(sizeof(double) * dap_maxcell * dap_maxcell, "dap_maxcell");
  coeff = (double **) dap_malloc(sizeof(double *) * dap_maxcell, "dap_maxcell");
  for (ncells = 0; ncells < dap_maxcell; ncells++)
    coeff[ncells] = comem + ncells * dap_maxcell;
  mean = (double *) dap_malloc(sizeof(double) * dap_maxcell, "dap_maxcell");
  nobs = (double *) dap_malloc(sizeof(double) * dap_maxcell, "dap_maxcell");
  vari = (double *) dap_malloc(sizeof(double) * dap_maxcell, "dap_maxcell");
  if (!fname)
    {
      fputs("(ftest) No dataset name given.\n", dap_err);
      exit(1);
    }
  tstname = dap_malloc(strlen(fname) + 5, "");
  dap_suffix(tstname, fname, "<tst");
  inset(fname);
  if ((typen = dap_varnum("_type_")) < 0)
    {
      fprintf(dap_err, "(ftest) no _type_ variable\n");
      exit(1);
    }
  if ((termn = dap_varnum("_term_")) < 0)
    {
      fprintf(dap_err, "(ftest) no _term_ variable\n");
      exit(1);
    }
  if (!variables || !variables[0])
    {
      fputs("(ftest) No variables given.\n", dap_err);
      exit(1);
    }
  nvars = dap_list(variables, varv, dap_maxtreat + 1);
  if (dap_obs[0].do_len[varv[0]] != DBL)
    {
      fprintf(dap_err, "(ftest) response variable %s must be of type double\n",
	      dap_obs[0].do_nam[varv[0]]);
      exit(1);
    }
  for (v = 1; v < nvars; v++)
    {
      if (dap_obs[0].do_len[varv[v]] <= 0)
	{
	  fprintf(dap_err, "(ftest) classification variable %s must be string\n",
		  dap_obs[0].do_nam[varv[v]]);
	  exit(1);
	}
    }
  outset(tstname, "");
  if (numerator && numerator[0])
    {
      nnum = testparse(numerator, numv, varv, nvars);
      num = 1;
    }
  else
    {
      num = 0;
      nnum = 0;
      for (t = 1; t < dap_maxcell; t++)
	numv[t] = 'e';
    }
  if (denominator && denominator[0])
    {
      nden = testparse(denominator, denv, varv, nvars);
      /* take numerator terms out of denominator */
      for (t = 1; t <= nnum; t++)
	{
	  if (numv[t] == 'c')
	    denv[t] = 'e';
	}
      for (t = 1; t <= nden; t++)
	{
	  if (denv[t] != 'e')
	    {
	      den = 1;
	      break;
	    }
	}
      if (t > nden)
	{
	  den = 0;
	  nden = 0;
	  while (t < dap_maxcell)
	    denv[t++] = 'e';
	}
    }
  else
    {
      den = 0;
      nden = 0;
      for (t = 1; t < dap_maxcell; t++)
	denv[t] = 'e';
    }
  for (v = 1; v < nvars; v++)
    {
      nlevels[v] = 0;
      for (l = 0; l < dap_maxlev; l++)
	levval[v][l][0] = '\0';
    }
  nmark = dap_list(marks, markv, dap_maxvar);
  for (ncells = 0, ncontrasts = 0, nerrors = 0,
	 more = step(), morecells = 1; morecells; ncells++)
    {
      gotn = 0;
      gotm = 0;
      gotv = 0;
      morecells = more;
      if (dap_newpart(markv, nmark))
	{
	  dap_swap();
	  dap_head(markv, nmark);
	  if (num)
	    fprintf(dap_lst, "Testing Ho: %s\n", numerator);
	  else if (nnum > 0)
	    {
	      fputs("Testing Ho:", dap_lst);
	      puttest(numv, nnum, varv, nvars);
	    }
	  if (den)
	    fprintf(dap_lst, "Denominator: %s\n", denominator);
	  else if (nden > 0)
	    {
	      fputs("Denominator:", dap_lst);
	      puttest(denv, nden, varv, nvars);
	    }
	  ftest1(coeff, level, ncells, rterm, ncontrasts, nerrors,
		 mean, vari, nobs, varv, numv, num * nnum, denv, den * nden, typen);
	  dap_swap();
	  for (v = 1; v < nvars; v++)
	    {
	      nlevels[v] = 0;
	      for (l = 0; l < dap_maxlev; l++)
		levval[v][l][0] = '\0';
	    }
	  ncells = 0;
	  ncontrasts = 0;
	  nerrors = 0;
	}
      for (statn = 0; more; )
	{
	  if (!strcmp(dap_obs[0].do_str[typen], "N"))
	    {
	      nobs[ncells] = dap_obs[0].do_dbl[varv[0]];
	      gotn = 1;
	      output();
	    }
	  else if (!strcmp(dap_obs[0].do_str[typen], "MEAN"))
	    {
	      mean[ncells] = dap_obs[0].do_dbl[varv[0]];
	      gotm = 1;
	      output();
	    }
	  else if (!strcmp(dap_obs[0].do_str[typen], "VAR"))
	    {
	      vari[ncells] = dap_obs[0].do_dbl[varv[0]];
	      gotv = 1;
	      output();
	    }
	  else
	    {
	      fprintf(dap_err, "(ftest) Bad cell statistic: %s\n",
		      dap_obs[0].do_str[typen]);
	      exit(1);
	    }
	  if (++statn < 3)
	    more = step();
	  else
	    {
	      if (nobs[ncells] == 1.0)
		vari[ncells] = 0.0;
	      break;
	    }
	}
      if (more)
	{
	  if (!gotm)
	    {
	      fputs("(ftest) Missing MEAN.\n", dap_err);
	      exit(1);
	    }
	  if (!gotn)
	    {
	      fputs("(ftest) Missing N.\n", dap_err);
	      exit(1);
	    }
	  if (!gotv)
	    {
	      fputs("(ftest) Missing VAR.\n", dap_err);
	      exit(1);
	    }
	  for (v = 1; v < nvars; v++)
	    level[v][ncells] = levn(dap_obs[0].do_str[varv[v]], levval[v], &nlevels[v]);
	}
      for (dap_mark(), nerrors = 0; more; )
	{
	  more = step();
	  err = !strcmp(dap_obs[0].do_str[typen], "ERROR");
	  con = !strcmp(dap_obs[0].do_str[typen], "CONTR");
	  if (den && err)
	    dap_mark();
	  if (err || (den && con))
	    {
	      t = dap_obs[0].do_int[termn];
	      rterm[nerrors] = t;
	      if (!den)
		{
		  denv[t] = 'c';
		  if (nden < t)
		    nden = t;
		}
	      if (denv[t] == 'c' || denv[t] == 'n')
		{
		  coeff[nerrors][ncells] = dap_obs[0].do_dbl[varv[0]];
		  nerrors++;
		  output();
		}
	    }
	  else
	    {
	      if (den)
		{
		  dap_rewind();
		  more = step();
		}
	      break;
	    }
	}
      for (ncontrasts = 0; more; more = step())
	{
	  if (!strcmp(dap_obs[0].do_str[typen], "CONTR"))
	    {
	      t = dap_obs[0].do_int[termn];
	      rterm[nerrors + ncontrasts] = t;
	      if (!num)
		{
		  numv[t] = 'c';
		  if (nnum < t)
		    nnum = t;
		}
	      if (numv[t] == 'c' || numv[t] == 'n')
		{
		  coeff[nerrors + ncontrasts][ncells] =
		    dap_obs[0].do_dbl[varv[0]];
		  ncontrasts++;
		}
	    }
	  else
	    break;
	}
      while (more)
	{
	  if (!strcmp(dap_obs[0].do_str[typen], "LSMEAN"))
	    {
	      t = dap_obs[0].do_int[termn];
	      if (t <= nnum && (numv[t] == 'c' || numv[t] == 'n'))
		output();
	    }
	  else
	    break;
	  more = step();
	}
    }
  dap_free(comem, "");
  dap_free(coeff, "");
  dap_free(tstname, "");
  dap_free(varv, "");
  dap_free(markv, "");
  dap_free(rterm, "");
  dap_free(numv, "");
  dap_free(denv, "");
  dap_free(levmem, "");
  dap_free(levptr, "");
  dap_free(levval, "");
  dap_free(nlevels, "");
  dap_free(levelmem, "");
  dap_free(level, "");
  dap_free(mean, "");
  dap_free(nobs, "");
  dap_free(vari, "");
}

static void putlev(int *nlevels, int *varv, int nvars, char ***levval)
{
  int v;
  int l;

  fprintf(dap_lst, "Response variable: %s\n\n", dap_obs[0].do_nam[varv[0]]);
  fprintf(dap_lst, "%-15s Levels\n", "Treatment");
  fprintf(dap_lst, "%-15s ------\n", "--------");
  for (v = 1; v < nvars; v++)
    {
      fprintf(dap_lst, "%-15s", dap_obs[0].do_nam[varv[v]]);
      for (l = 0; l < nlevels[v]; l++)
	fprintf(dap_lst, " %s", levval[v][l]);
      putc('\n', dap_lst);
    }
  putc('\n', dap_lst);
}

static void maketerm(int nterm, char *termv, int nvars, int *varv,
		     int *nlevels, double **coeff, int ncells, double *nobs,
		     int *rterm, int *nrows, int **clevel)
{
  char termtype[4] = "ecc";
  int tt;
  int tn;
  int *nest;
  int reset;	/* = 1 for error and contrasts, 0 for lsmeans */
  int r, c;
  int row;
  int *iv;
  int ivn;
  int ntreat;
  int *rlevel;
  int bits;
  double prod;
  int vn;
  int nextr;
  int *change;
  int nbits;

  row = 0;
  nest = (int *) dap_malloc(sizeof(int) * ncells, "");
  iv = (int *) dap_malloc(sizeof(int) * (dap_maxtreat + 1), "dap_maxtreat");
  rlevel = (int *) dap_malloc(sizeof(int) * (dap_maxtreat + 1), "dap_maxtreat");
  change = (int *) dap_malloc(sizeof(int) * (dap_maxtreat + 1), "dap_maxtreat");
  for (tn = 1; tn <= nterm; tn++)
    nest[tn] = tn;
  for (tn = 0x1; tn <= nterm; tn = (tn << 1))
    {
      if (termv[tn] == 'e')
	{
	  for (tt = 1, bits = 0; tt <= nterm; tt++)
	    {
	      if (tt != tn && (tt & tn) == tn && termv[tt] == 'c')
		{
		  if (bits)
		    bits &= tt;
		  else
		    bits = tt;
		}
	    }
	  if (bits && bits != tn)
	    {
	      for (tt = 1; tt <= nterm; tt++)
		{
		  if ((tt & tn) == tn)
		    {
		      if (termv[tt] == 'e')
			{
			  nbits = (tt | bits);
			  termv[tt] = 'n';
			  nest[tt] = nbits;
			}
		    }
		}
	    }
	}
    }
  for (vn = 1, c = 0; vn < nvars; vn++)
    clevel[vn][c] = 0;
  for (c++; c < ncells; c++)
    {
      for (vn = 1; vn < nvars; vn++)
	clevel[vn][c] = clevel[vn][c - 1];
      for (vn = nvars - 1; vn >= 0; --vn)
	{
	  if (++clevel[vn][c] == nlevels[vn])
	    clevel[vn][c] = 0;
	  else
	    break;
	}
    }
  for (tt = 0, r = 0; tt < 3; tt++)
    {
      reset = (tt < 2);
      for (tn = 1, nrows[tt] = 0; tn <= nterm; tn++)
	{
	  if (termv[tn] == termtype[tt] ||
	      (termv[tn] == 'n' && termtype[tt] == 'c'))
	    {
	      bits = tn;
	      for (ntreat = 0, vn = 1; vn < nvars; vn++, bits = (bits >> 1))
		{
		  if (bits & 0x1)
		    iv[ntreat++] = vn;
		}
	      for (c = 0, vn = nvars - 1; vn > 0; )
		{
		  for (ivn = 0; ivn < ntreat; ivn++)
		    rlevel[ivn] = reset;
		  for (row = 0, ivn = 0; ivn < ntreat; )
		    {
		      if (tt < 2)
			{
			  for (ivn = 0, prod = 1.0; ivn < ntreat;
			       ivn++)
			    {
			      if (clevel[iv[ivn]][c] == 0)
				;
			      else if (clevel[iv[ivn]][c] ==
				       rlevel[ivn])
				prod = -prod;
			      else
				{
				  prod = 0.0;
				  break;
				}
			    }
			  coeff[r + row][c] = prod;
			  row++;
			}
		      else if (ntreat == 1)
			{
			  if (clevel[iv[ivn]][c] ==
			      rlevel[ivn])
			    coeff[r + row][c] = 1.0;
			  else
			    coeff[r + row][c] = 0.0;
			  row++;
			}
		      for (ivn = 0; ivn < ntreat; ivn++)
			{
			  if (++rlevel[ivn] == nlevels[iv[ivn]])
			    rlevel[ivn] = reset;
			  else
			    break;
			}
		    }
		  if (++c == ncells)
		    break;
		}
	      for (nextr = r + row; r < nextr; r++, nrows[tt]++)
		rterm[r] = nest[tn];
	    }
	}
    }
  dap_free(nest, "");
  dap_free(iv, "");
  dap_free(rlevel, "");
  dap_free(change, "");
}

static int cmpstr(char **s1, char **s2)
{
  return strcmp(*s1, *s2);
}

static void eff1(int incells, char ***levval, int *nlevels,
		 int *varv, int nvars, char *termv, int nterm, int typen, int termn)
{
  double *comem;
  double **coeff;
  int v;
  int ncells;
  int celli;
  int *level;
  int *clevmem;
  int **clevel;
  int statn;
  double nobs1;
  double mean1;
  double vari1;
  int gotn, gotm, gotv;
  double *nobs;
  double *mean;
  double *vari;
  int celln;
  int sumlev;
  int miss;
  int *rterm;
  int *indep;
  int *nonz;
  int nrows[3];	/* nrows[0] = nerrors, nrows[1] = ncontrasts, nrows[2] = lsmeans */
  int r;
  int errow;
  int corow;
  int cr;
  double max;
  double tmp;
  int (*scmp)();

  nobs1 = 0.0;
  mean1 = 0.0;
  vari1 = 0.0;
  scmp = &cmpstr;
  level = (int *) dap_malloc(sizeof(int) * (dap_maxtreat + 1), "dap_maxtreat");
  for (v = 1; v < nvars; v++)
    qsort(levval[v], nlevels[v], sizeof(char *), scmp);
  for (v = 1, ncells = 1, sumlev = 0; v < nvars; v++)
    {
      ncells *= nlevels[v];
      sumlev += nlevels[v];
      level[v] = 0;
    }
  clevmem = (int *) dap_malloc(sizeof(int) * nvars * ncells, "");
  clevel = (int **) dap_malloc(sizeof(int *) * nvars, "");
  for (v = 0; v < nvars; v++)
    clevel[v] = clevmem + v * ncells;
  nobs = (double *) dap_malloc(sizeof(double) * ncells, "");
  mean = (double *) dap_malloc(sizeof(double) * ncells, "");
  vari = (double *) dap_malloc(sizeof(double) * ncells, "");
  rterm = (int *) dap_malloc(sizeof(int) * (ncells + sumlev - 1), "");
  indep = (int *) dap_malloc(sizeof(int) * (ncells + sumlev - 1), "");
  nonz = (int *) dap_malloc(sizeof(int) * (ncells + sumlev - 1), "");
  comem = (double *) dap_malloc(sizeof(double) * (ncells + sumlev) * ncells, "");
  coeff = (double **) dap_malloc(sizeof(double *) * (ncells + sumlev), "");
  for (r = 0; r < ncells + sumlev; r++)
    coeff[r] = comem + r * ncells;
  for (celli = 0, celln = 0; celli < incells; celli++, celln++)
    {
      gotn = 0;
      gotm = 0;
      gotv = 0;
      for (statn = 0; statn < 3; statn++)
	{
	  step();
	  if (!strcmp(dap_obs[0].do_str[typen], "N"))
	    {
	      nobs1 = dap_obs[0].do_dbl[varv[0]];
	      gotn = 1;
	    }
	  else if (!strcmp(dap_obs[0].do_str[typen], "MEAN"))
	    {
	      mean1 = dap_obs[0].do_dbl[varv[0]];
	      gotm = 1;
	    }
	  else if (!strcmp(dap_obs[0].do_str[typen], "VAR"))
	    {
	      vari1 = dap_obs[0].do_dbl[varv[0]];
	      gotv = 1;
	    }
	  else
	    {
	      fprintf(dap_err, "(eff1) Bad cell statistic: %s\n",
		      dap_obs[0].do_str[typen]);
	      exit(1);
	    }
	}
      if (!gotn)
	{
	  fputs("(eff1) Missing N.\n", dap_err);
	  exit(1);
	}
      if (!gotm)
	{
	  fputs("(eff1) Missing MEAN.\n", dap_err);
	  exit(1);
	}
      if (!gotv)
	{
	  fputs("(eff1) Missing VAR.\n", dap_err);
	  exit(1);
	}
      do	{
	for (v = 1, miss = 0; v < nvars; v++)
	  {
	    if (strcmp(dap_obs[0].do_str[varv[v]],
		       levval[v][level[v]]))
	      {
		miss = 1;
		break;
	      }
	  }
	if (miss)
	  {
	    nobs[celln] = 0.0;
	    mean[celln] = 0.0;
	    vari[celln] = 0.0;
	    celln++;
	    for (v = nvars - 1; v > 0; --v)
	      {
		if (++level[v] == nlevels[v])
		  level[v] = 0;
		else
		  break;
	      }
	  }
      } while (miss);
      nobs[celln] = nobs1;
      mean[celln] = mean1;
      if (nobs1 > 1.0)
	vari[celln] = vari1;
      else
	vari[celln] = 0.0;
      for (v = nvars - 1; v > 0; --v)
	{
	  if (++level[v] == nlevels[v])
	    level[v] = 0;
	  else
	    break;
	}
    }
  while (celln < ncells)
    {
      nobs[celln] = 0.0;
      mean[celln] = 0.0;
      vari[celln] = 0.0;
      celln++;
    }
  maketerm(nterm, termv, nvars, varv, nlevels, coeff, ncells, nobs, rterm, nrows, clevel);
  for (cr = 0; cr < nrows[0] + nrows[1] + nrows[2]; cr++)
    indep[cr] = 0;
  if (nrows[0])
    {
      errow = rowred(coeff, rterm, 0, ncells, nobs,
		     nrows[0] - 1, nrows[0] - 1, NULL);
      if (errow < nrows[0])
	orthog(coeff, nrows[0] - 1, errow, 0, ncells, nobs, indep, NULL);
      corow = rowred(coeff, rterm, 0, ncells, nobs,
		     nrows[0] - 1, nrows[0] + nrows[1] + nrows[2] - 1, nonz);
      if (corow < nrows[0])
	corow = nrows[0];
    }
  else
    {
      errow = 0;
      corow = nrows[0];
    }
  for (v = 1; v < nvars; v++)
    level[v] = 0;
  for (r = 0, max = 0.0; r < nrows[0] + nrows[1] + nrows[2]; r++)
    for (celln = 0; celln < ncells; celln++)
      {
	if ((tmp = fabs(coeff[r][celln])) > max)
	  max = tmp;
      }
  for (r = 0; r < nrows[0] + nrows[1] + nrows[2]; r++)
    for (celln = 0; celln < ncells; celln++)
      {
	if (fabs(coeff[r][celln]) < dap_zerotol * max)
	  coeff[r][celln] = 0.0;
      }
  for (celln = 0; celln < ncells; celln++)
    {
      if (nobs[celln])
	{
	  dap_obs[0].do_int[termn] = 0;
	  for (v = 1; v < nvars; v++)
	    strcpy(dap_obs[0].do_str[varv[v]], levval[v][level[v]]);
	  strcpy(dap_obs[0].do_str[typen], "N");
	  dap_obs[0].do_dbl[varv[0]] = nobs[celln];
	  output();
	  strcpy(dap_obs[0].do_str[typen], "MEAN");
	  dap_obs[0].do_dbl[varv[0]] = mean[celln];
	  output();
	  strcpy(dap_obs[0].do_str[typen], "VAR");
	  dap_obs[0].do_dbl[varv[0]] = vari[celln];
	  output();
	  for (r = errow; r < nrows[0]; r++)
	    {
	      if (indep[r])
		{
		  dap_obs[0].do_dbl[varv[0]] = coeff[r][celln];
		  strcpy(dap_obs[0].do_str[typen], "ERROR");
		  dap_obs[0].do_int[termn] = rterm[r];
		  output();
		}
	    }
	  for (r = corow; r < nrows[0] + nrows[1]; r++)
	    {
	      if (!nrows[0] || nonz[r])
		{
		  dap_obs[0].do_dbl[varv[0]] = coeff[r][celln];
		  strcpy(dap_obs[0].do_str[typen], "CONTR");
		  dap_obs[0].do_int[termn] = rterm[r];
		  output();
		}
	    }
	  strcpy(dap_obs[0].do_str[typen], "LSMEAN");
	  while (r < nrows[0] + nrows[1] + nrows[2])
	    {
	      dap_obs[0].do_int[termn] = rterm[r];
	      dap_obs[0].do_dbl[varv[0]] = coeff[r][celln];
	      output();
	      r++;
	    }
	}
      for (v = nvars - 1; v > 0; --v)
	{
	  if (++level[v] == nlevels[v])
	    level[v] = 0;
	  else
	    break;
	}
    }
  dap_free(comem, "");
  dap_free(coeff, "");
  dap_free(level, "");
  dap_free(clevmem, "");
  dap_free(clevel, "");
  dap_free(nobs, "");
  dap_free(mean, "");
  dap_free(vari, "");
  dap_free(rterm, "");
  dap_free(indep, "");
  dap_free(nonz, "");
}

void effects(char *fname, char *varlist, char *model, char *marks)
{
  char *conname;
  char *outlist;
  int *varv;
  int nvars;
  int *markv;
  int nmark;
  int typen;
  int termn;
  char *termv;
  int nterm;
  char *levmem;
  char **levptr;
  char ***levval;
  int *nlevels;
  int incells;
  int v;
  int l;
  int more;

  conname = dap_malloc(strlen(fname) + 5, fname);
  outlist = dap_malloc(strlen(varlist) + strlen(marks) + 9, "");
  varv = (int *) dap_malloc(sizeof(int) * (dap_maxtreat + 1), "dap_maxtreat");
  markv = (int *) dap_malloc(sizeof(int) * dap_maxvar, "dap_maxvar");
  termv = dap_malloc(dap_maxcell, "dap_maxcell");
  levmem = dap_malloc((dap_maxtreat + 1) * dap_maxlev * (dap_strlen + 1),
		      "dap_maxtreat, dap_maxlev, dap_strlen");
  levptr = (char **) dap_malloc(sizeof(char *) * (dap_maxtreat + 1) * dap_maxlev,
				"dap_maxtreat, dap_maxlev");
  levval = (char ***) dap_malloc(sizeof(char **) * (dap_maxtreat + 1),
				 "dap_maxtreat");
  for (v = 0; v < dap_maxtreat + 1; v++)
    {
      levval[v] = levptr + v * dap_maxlev;
      for (l = 0; l < dap_maxlev; l++)
	levval[v][l] = levmem + v * dap_maxlev * (dap_strlen + 1) +
	  l * (dap_strlen + 1);
    }
  nlevels = (int *) dap_malloc(sizeof(int) * (dap_maxtreat + 1), "dap_maxtreat");
  if (!fname)
    {
      fputs("(effects) No dataset name given.\n", dap_err);
      exit(1);
    }
  dap_suffix(conname, fname, ".con");
  inset(fname);
  if ((typen = dap_varnum("_type_")) < 0)
    {
      fputs("(effects) no _type_ variable\n", dap_err);
      exit(1);
    }
  termn = dap_vd("_term_ 0", 0);
  nvars = dap_list(varlist, varv, dap_maxtreat + 1);
  if (nvars > dap_maxtreat + 1)
    {
      fprintf(dap_err, "(effects) too many variables in model: %s\n", model);
      exit(1);
    }
  if (dap_obs[0].do_len[varv[0]] != DBL)
    {
      fprintf(dap_err, "(effects) response variable %s must be of type double\n",
	      dap_obs[0].do_nam[varv[0]]);
      exit(1);
    }
  for (v = 1; v < nvars; v++)
    {
      if (dap_obs[0].do_len[varv[v]] <= 0)
	{
	  fprintf(dap_err, "(effects) classification variable %s must be string\n",
		  dap_obs[0].do_nam[varv[v]]);
	  exit(1);
	}
    }
  nterm = testparse(model, termv, varv, nvars);
  nmark = dap_list(marks, markv, dap_maxvar);
  strcpy(outlist, varlist);
  strcat(outlist, " _term_");
  if (nmark)
    {
      strcat(outlist, " ");
      strcat(outlist, marks);
    }
  outset(conname, outlist);
  for (v = 1; v < nvars; v++)
    {
      nlevels[v] = 0;
      for (l = 0; l < dap_maxlev; l++)
	levval[v][l][0] = '\0';
    }
  dap_mark();
  for (more = 1, incells = 0; more; incells++)
    {
      more = step();
      if (dap_newpart(markv, nmark))
	{
	  dap_swap();
	  dap_head(markv, nmark);
	  dap_swap();
	  dap_rewind();
	  putlev(nlevels, varv, nvars, levval);
	  eff1(incells, levval, nlevels, varv, nvars, termv, nterm, typen, termn);
	  for (v = 1; v < nvars; v++)
	    {
	      nlevels[v] = 0;
	      for (l = 0; l < dap_maxlev; l++)
		levval[v][l][0] = '\0';
	    }
	  incells = 0;
	  dap_mark();
	  more = step();
	}
      if (more)
	{
	  for (v = 1; v < nvars; v++)
	    levn(dap_obs[0].do_str[varv[v]], levval[v], &nlevels[v]);
	  if (!step() || !step())
	    {
	      fprintf(dap_err, "(effects) Incomplete cell statistics for: ");
	      for (v = 1; v < nvars; v++)
		{
		  fprintf(dap_err, "%s (%s) ",
			  dap_obs[0].do_nam[varv[v]], dap_obs[0].do_str[varv[v]]);
		}
	      putc('\n', dap_err);
	      exit(1);
	    }
	}
    }
  if (model && model[0])
    ftest(conname, varlist, "", "", marks);
  dap_free(conname, "");
  dap_free(outlist, "");
  dap_free(varv, "");
  dap_free(markv, "");
  dap_free(termv, "");
  dap_free(levval, "");
  dap_free(nlevels, "");
  dap_free(levmem, "");
  dap_free(levptr, "");
}

/* Compute LS means, differences, and probabilities for treatment comparisons */

static void lsmeans1(
		     int methn,	/* method: TUKEY=0, LSD=1, DUNNETT=2 */
		     double alpha,	/* p-value at which to compare LS means */
		     double **coeff,	/* matrix of coefficients (?) */
		     int ncells,	/* number of cells = number of columns of coeff matrix */
		     double err,	/* ms error (?) */
		     double dedfi,	/* error degrees of freedom (?), as double */
		     int nerrors,	/* number of error lines (?) in coeff matrix */
		     int nlsmeans,	/* number of LS means lines (?) in coeff matrix */
		     double *mean,	/* array of means for cells */
		     double *vari,	/* array of variances for cells */
		     double *nobs,	/* array of numbers of observations for cells */
		     int nlevels,	/* number of levels of treatment */
		     char **levval,	/* strings for levels of treatment */
		     int respn,	/* index of response variable in dataobs array */
		     int treatn,	/* index of treatment variable in dataobs array */
		     int resp2n,	/* index of copy of response variable in dataobs array */
		     int treat2n,	/* index of copy of treatment variable in dataobs array */
		     int typen,	/* index of _type_ variable in dataobs array */
		     int statn,	/* index of statistic in dataobs array */
		     int lsm1,	/* index of LS means row variable in dataobs array */
		     int lsm2	/* index of LS means col variable in dataobs array */
		     )
{
  int l1, l2;	/* indices to arrays for levels */
  int lsrow;
  double tmp;
  double n;
  int cr, cc;	/* row and column of coeff matrix */
  int *indep;	/* flags for linearly independent rows */
  double sumwt;
  double *lsmean;	/* array of LS means */
  double *effinvn;
  double effin;
  double *diffmem;	/* memory allocation for diff array */
  double **diff;	/* array of differences between LS means for levels */
  double *probmem;	/* memory allocation for prob array */
  double **prob;	/* array of probability values for LS means comparisons */
  double pt, pr;	/* for computing probability points: pt = point, pr = probability */
  int edfi;	/* error degrees of freedom, as integer */
  double dfdown, dfup;	/* round down (resp. up) of degrees of freedom */
  double pdown, pup;	/* round down (resp. up) of probability values */

  pt = 0.0;
  dap_swap();	/* get back to part just ended */
  /* array allocations and pointer setup */
  indep = (int *) dap_malloc(sizeof(int) * ncells, "");
  lsmean = (double *) dap_malloc(sizeof(double) * nlevels, "");
  effinvn = (double *) dap_malloc(sizeof(double) * nlevels, "");
  diffmem = (double *) dap_malloc(sizeof(double) * nlevels * nlevels, "");
  probmem = (double *) dap_malloc(sizeof(double) * nlevels * nlevels, "");
  diff = (double **) dap_malloc(sizeof(double *) * nlevels, "");
  prob = (double **) dap_malloc(sizeof(double *) * nlevels, "");
  for (l1 = 0; l1 < nlevels; l1++)
    {
      diff[l1] = diffmem + l1 * nlevels;
      prob[l1] = probmem + l1 * nlevels;
    }
  /* end array allocations and pointer setup */

  /* check that row sums for error terms in coeff array are zero */
  sumcheck("lsmeans1", coeff, ncells, nerrors, 0, NULL);
  for (cr = 0; cr < nerrors + nlsmeans; cr++)
    indep[cr] = 0;

  /* orthogonalize the coefficient matrix, return number of independent rows */
  lsrow = orthog(coeff, 0, nerrors + nlevels - 1, nerrors + nlevels - 1,
		 ncells, nobs, indep, NULL);
  if (lsrow - nerrors != nlevels)
    {
      fprintf(dap_err,
	      "(lsmeans1) Number of independent LS means %d differs from number of levels %d\n",
	      lsrow - nerrors, nlevels);
      exit(1);
    }

  /* compute total number of observations */
  for (cc = 0, n = 0.0; cc < ncells; cc++)
    n += nobs[cc];

  /* compute LS means and effective reciprocal of number of observations for each level */
  for (l1 = 0, effin = 0.0; l1 < nlevels; l1++)
    {
      for (cc = 0, lsmean[l1] = 0.0, effinvn[l1] = 0.0, sumwt = 0.0; cc < ncells; cc++)
	{
	  tmp = coeff[nerrors + l1][cc];
	  lsmean[l1] += tmp * mean[cc];
	  sumwt += tmp;
	  effinvn[l1] += tmp * tmp / nobs[cc];
	}
      lsmean[l1] /= sumwt;
      effinvn[l1] /= (sumwt * sumwt);
      effin += effinvn[l1];
    }
  effin /= (double) nlevels;
  /* end compute LS means and effective reciprocal of number of observations */

  /* output LS means to file */
  putc('\n', dap_lst);
  /* shouldn't need this now
   * strcpy(dap_obs[0].do_str[typen], "LSMEAN");
   * for (l1 = 0; l1 < nlevels; l1++)
   * 	{
   * 	strcpy(dap_obs[0].do_str[treatn], levval[l1]);
   * 	dap_obs[0].do_str[treat2n][0] = '\0';
   * 	dap_obs[0].do_dbl[respn] = lsmean[l1];
   * 	dap_obs[0].do_dbl[resp2n] = lsmean[l1];
   * 	dap_obs[0].do_dbl[statn] = lsmean[l1];
   * 	dap_obs[0].do_dbl[lsm1] = lsmean[l1];
   * 	dap_obs[0].do_dbl[lsm2] = 0.0;
   * 	output();
   * 	}
   */

  /* output effective numbers of observations to file */
  strcpy(dap_obs[0].do_str[typen], "EFFN");
  for (l1 = 0; l1 < nlevels; l1++)
    {
      strcpy(dap_obs[0].do_str[treatn], levval[l1]);
      dap_obs[0].do_dbl[respn] = 1.0 / effinvn[l1];
      dap_obs[0].do_dbl[resp2n] = 1.0 / effinvn[l1];
      dap_obs[0].do_dbl[statn] = 1.0 / effinvn[l1];
      dap_obs[0].do_dbl[lsm1] = lsmean[l1];
      dap_obs[0].do_dbl[lsm2] = 0.0;
      output();
    }

  dfdown = floor(dedfi);
  dfup = ceil(dedfi);
  edfi = (int) dfdown;
  if (methn == TUKEY || methn == LSD)
    {
      pr = -1.0;
      for (l1 = 0; l1 < nlevels; l1++)
	{
	  for (l2 = 0; l2 < nlevels; l2++)
	    {
	      if (l2 == l1)
		{
		  diff[l1][l2] = 0.0;
		  prob[l1][l2] = 1.0;
		}
	      else if (methn == TUKEY)
		{
		  diff[l1][l2] = (lsmean[l1] - lsmean[l2]) /
		    sqrt(err * 0.5 * (effinvn[l1] + effinvn[l2]));
		  diff[l2][l1] = -diff[l1][l2];
		  if (dfdown == dfup)
		    prob[l1][l2] =
		      dap_sr(nlevels, edfi, fabs(diff[l1][l2]));
		  else
		    {
		      pdown = dap_sr(nlevels, edfi, fabs(diff[l1][l2]));
		      pup = dap_sr(nlevels, (int) dfup, fabs(diff[l1][l2]));
		      prob[l1][l2] = pdown +
			(dedfi - dfdown) / (dfup - dfdown) *
			(pup - pdown);
		    }
		  prob[l2][l1] = prob[l1][l2];
		}
	      else
		{
		  diff[l1][l2] = (lsmean[l1] - lsmean[l2]) /
		    sqrt(err * (effinvn[l1] + effinvn[l2]));
		  diff[l2][l1] = -diff[l1][l2];
		  if (dfdown == dfup)
		    prob[l1][l2] = 2.0 * probt(fabs(diff[l1][l2]), edfi);
		  else
		    {
		      pdown = probt(fabs(diff[l1][l2]), edfi);
		      pup = probt(fabs(diff[l1][l2]), (int) dfup);
		      prob[l1][l2] = 2.0 * (pdown +
					    (dedfi - dfdown) / (dfup - dfdown) *
					    (pup - pdown));
		    }
		  prob[l2][l1] = prob[l1][l2];
		}
	      if (pr < 0.0 || fabs(prob[l1][l2] - alpha) < fabs(pr - alpha))
		{
		  pt = fabs(diff[l1][l2]);
		  pr = prob[l1][l2];
		}
	    }
	}
      for (l1 = 0; l1 < nlevels; l1++)
	{
	  strcpy(dap_obs[0].do_str[treatn], levval[l1]);
	  dap_obs[0].do_dbl[respn] = lsmean[l1];
	  for (l2 = 0; l2 < nlevels; l2++)
	    {
	      if (l2 == l1)
		continue;
	      strcpy(dap_obs[0].do_str[treat2n], levval[l2]);
	      dap_obs[0].do_dbl[resp2n] = lsmean[l2];
	      strcpy(dap_obs[0].do_str[typen], "LSMDIFF");
	      dap_obs[0].do_dbl[statn] = lsmean[l1] - lsmean[l2];
	      dap_obs[0].do_dbl[lsm1] = lsmean[l1];
	      dap_obs[0].do_dbl[lsm2] = lsmean[l2];
	      output();
	      if (methn == TUKEY)
		{
		  dap_obs[0].do_dbl[resp2n] = lsmean[l2];
		  strcpy(dap_obs[0].do_str[typen], "MINDIFF");
		  if (dfdown == dfup)
		    dap_obs[0].do_dbl[statn] =
		      dap_srpt(nlevels, edfi, pt, pr, alpha) *
		      sqrt(err * 0.5 * (effinvn[l1] + effinvn[l2]));
		  else
		    {
		      pdown = dap_srpt(nlevels, edfi, pt, pr, alpha);
		      pup = dap_srpt(nlevels, (int) dfup, pt, pr, alpha);
		      dap_obs[0].do_dbl[statn] =
			(pdown +
			 (dedfi - dfdown) / (dfup - dfdown) *
			 (pup - pdown)) *
			sqrt(err * 0.5 * (effinvn[l1] + effinvn[l2]));
		    }
		  output();
		}
	      else
		{
		  dap_obs[0].do_dbl[resp2n] = lsmean[l2];
		  strcpy(dap_obs[0].do_str[typen], "MINDIFF");
		  if (dfdown == dfup)
		    dap_obs[0].do_dbl[statn] =
		      tpoint(alpha / 2.0, edfi) *
		      sqrt(err * (effinvn[l1] + effinvn[l2]));
		  else
		    {
		      pdown = tpoint(alpha / 2.0, edfi);
		      pup = tpoint(alpha / 2.0, (int) dfup);
		      dap_obs[0].do_dbl[statn] =
			(pdown +
			 (dedfi - dfdown) / (dfup - dfdown) *
			 (pup - pdown)) *
			sqrt(err * (effinvn[l1] + effinvn[l2]));
		    }
		  output();
		}
	      strcpy(dap_obs[0].do_str[typen], "PROB");
	      dap_obs[0].do_dbl[statn] = prob[l1][l2];
	      output();
	    }
	}
    }
  else		/* DUNNETT */
    {
      pr = -1.0;
      for (l2 = 1; l2 < nlevels; l2++)
	{
	  diff[0][l2] = (lsmean[l2] - lsmean[0]) /
	    sqrt(err * effin);
	  if (dfdown == dfup)
	    prob[0][l2] = dap_md(nlevels - 1, edfi, fabs(diff[0][l2]));
	  else
	    {
	      pdown = dap_md(nlevels - 1, edfi, fabs(diff[0][l2]));
	      pup = dap_md(nlevels - 1, (int) dfup, fabs(diff[0][l2]));
	      prob[l1][l2] = pdown +
		(dedfi - dfdown) / (dfup - dfdown) *
		(pup - pdown);
	    }
	  if (pr < 0.0 || fabs(prob[0][l2] - alpha) < fabs(pr - alpha))
	    {
	      pt = fabs(diff[0][l2]);
	      pr = prob[0][l2];
	    }
	  strcpy(dap_obs[0].do_str[treat2n], levval[0]);
	  strcpy(dap_obs[0].do_str[treatn], levval[l2]);
	  dap_obs[0].do_dbl[respn] = lsmean[l2];
	  strcpy(dap_obs[0].do_str[typen], "LSMDIFF");
	  dap_obs[0].do_dbl[statn] = lsmean[l2] - lsmean[0];
	  dap_obs[0].do_dbl[lsm1] = lsmean[l2];
	  dap_obs[0].do_dbl[lsm2] = lsmean[0];
	  output();
	  strcpy(dap_obs[0].do_str[typen], "PROB");
	  dap_obs[0].do_dbl[statn] = prob[0][l2];
	  output();
	}
    }
  switch (methn)
    {
    case TUKEY:
      fputs("Tukey method\n\n", dap_lst);
      fprintf(dap_lst, "Minimum significant differences are for level %.5f\n",
	      alpha);
      break;
    case LSD:
      fputs("LSD  method\n", dap_lst);
      fprintf(dap_lst, "Minimum significant differences are for level %.5f\n",
	      alpha);
      break;
    case DUNNETT:
      pt = dap_mdpt(nlevels, edfi, pt, pr, alpha) * sqrt(err * effin);
      fputs("Dunnett method\n", dap_lst);
      fprintf(dap_lst,
	      "At level %.5f, minimum significant difference = %.6g\n",
	      alpha, pt);
      break;
    }
  dap_free(indep, "");
  dap_free(lsmean, "");
  dap_free(effinvn, "");
  dap_free(diffmem, "");
  dap_free(diff, "");
  dap_free(probmem, "");
  dap_free(prob, "");
  dap_swap();
}

void lsmeans(char *fname, char *method, double alpha, char *varlist, char *treat,
	     char *marks, char *format)
{
  int typen;
  int *varv;
  int *markv;
  int nmark;
  int r;
  char *lsmname;
  char *lsmsrt;
  char *varstr;
  char *treat2;	/* rename of treatment variable for columns */
  char *args1;
  char *args2;
  int treatn;
  int treat2n;
  int resp2n;
  int statn;	/* index of _stat_ variable */
  int methn;	/* code for method: TUKEY=0, LSD=1, DUNNETT=2 */
  char *levmem;
  char **levval;
  int l;
  static int nlevels;
  double *comem;
  double **coeff;
  int gotm, gotn, gotv;
  double *mean;
  double *nobs;
  double *vari;
  int s;
  int ncells;
  int nerrors;
  int nlsmeans;
  int morecells;
  int more;
  int err;
  int con;
  double mse;
  double edf;
  int lsm1, lsm2;	/* index to LS mean row and col variables for sorting table */

  mse = 0.0;
  edf = 0.0;
  if (!fname || !fname[0])
    {
      fputs("(lsmeans) no dataset name given.\n", dap_err);
      exit(1);
    }
  lsmname = dap_malloc(strlen(fname) + 5, fname);
  dap_suffix(lsmname, fname, ".lsm");
  lsmsrt = dap_malloc(strlen(lsmname) + 5, lsmname);
  dap_suffix(lsmsrt, lsmname, ".srt");
  varv = (int *) dap_malloc(sizeof(int) * (dap_maxtreat + 1), "dap_maxtreat");
  markv = (int *) dap_malloc(sizeof(int) * dap_maxvar, "dap_maxvar");
  levmem = dap_malloc(dap_maxlev * (dap_strlen + 1), "dap_maxlev, dap_strlen");
  levval = (char **) dap_malloc(sizeof(char *) * dap_maxlev, "dap_maxlev");
  for (l = 0; l < dap_maxlev; l++)
    levval[l] = levmem + l * (dap_strlen + 1);
  comem = (double *) dap_malloc(sizeof(double) * dap_maxcell * dap_maxcell, "dap_maxcell");
  coeff = (double **) dap_malloc(sizeof(double *) * dap_maxcell, "dap_maxcell");
  for (ncells = 0; ncells < dap_maxcell; ncells++)
    coeff[ncells] = comem + ncells * dap_maxcell;
  mean = (double *) dap_malloc(sizeof(double) * dap_maxcell, "dap_maxcell");
  nobs = (double *) dap_malloc(sizeof(double) * dap_maxcell, "dap_maxcell");
  vari = (double *) dap_malloc(sizeof(double) * dap_maxcell, "dap_maxcell");
  inset(fname);
  if (!varlist || !varlist[0])
    {
      fputs("(lsmeans) no variable list given.\n", dap_err);
      exit(1);
    }
  dap_list(varlist, varv, dap_maxtreat + 1);
  if (!treat || !treat[0])
    {
      fputs("(lsmeans) no treatments specified.\n", dap_err);
      exit(1);
    }
  if ((treatn = dap_varnum(treat)) < 0)
    {
      fprintf(dap_err, "(lsmeans) Treatment variable unknown: %s\n", treat);
      exit(1);
    }
  treat2 = dap_malloc(strlen(treat) + 2, treat); /* +2 for '_' and '\0' */
  strcpy(treat2, "_");
  strcat(treat2, treat);
  /* + 10 is to make sure that later use for dap_vd is OK */
  varstr = dap_malloc(strlen(treat2) + strlen(dap_obs[0].do_nam[varv[0]]) + 10, "");
  sprintf(varstr, "%s %d", treat2, dap_obs[0].do_len[treatn]);
  treat2n = dap_vd(varstr, 0);
  lsm1 = dap_vd("_lsm_ -1", 0);
  lsm2 = dap_vd("_LSMEAN_ -1", 0);
  for(r = 0, varstr[0] = '_'; dap_obs[0].do_nam[varv[0]][r]; r++)
    {
      if (r < dap_namelen - 1)
	varstr[r + 1] = dap_obs[0].do_nam[varv[0]][r];
    }
  sprintf(varstr + r + 1, " %d", DBL);
  resp2n = dap_vd(varstr, 0);
  sprintf(varstr, "_stat_ %d", DBL);
  statn = dap_vd(varstr, 0);
  if ((typen = dap_varnum("_type_")) < 0)
    {
      fprintf(dap_err, "(lsmeans) no _type_ variable\n");
      exit(1);
    }
  if (dap_varnum("_term_") < 0)
    {
      fprintf(dap_err, "(lsmeans) no _term_ variable\n");
      exit(1);
    }
  outset(lsmname, "");
  if (!method || !method[0])
    {
      fputs("(lsmeans) no method specified.\n", dap_err);
      exit(1);
    }
  if (!strcmp(method, "TUKEY"))
    methn = TUKEY;
  else if (!strcmp(method, "LSD"))
    methn = LSD;
  else if (!strcmp(method, "DUNNETT"))
    methn = DUNNETT;
  else
    {
      fprintf(dap_err, "(lsmeans) unknown method: %s\n", method);
      exit(1);
    }
  nmark = dap_list(marks, markv, dap_maxvar);
  for (l = 0; l < dap_maxlev; l++)
    levval[l][0] = '\0';
  for (ncells = 0, nlevels = 0, nlsmeans = 0, nerrors = 0, more = step(), morecells = 1;
       morecells; ncells++)
    {
      gotn = 0;
      gotm = 0;
      gotv = 0;
      morecells = more;
      if (dap_newpart(markv, nmark))
	{
	  dap_swap();
	  dap_head(markv, nmark);
	  dap_swap();
	  fprintf(dap_lst, "Least-squares means for: %s\n", treat);
	  lsmeans1(methn, alpha, coeff, ncells, mse, edf,
		   nerrors, nlsmeans, mean, vari, nobs, nlevels, levval,
		   varv[0], treatn,  resp2n, treat2n, typen, statn, lsm1, lsm2);
	  ncells = 0;
	  nlsmeans = 0;
	  nerrors = 0;
	  nlevels = 0;
	  for (l = 0; l < dap_maxlev; l++)
	    levval[l][0] = '\0';
	}
      for (s = 0; more; )
	{
	  if (!strcmp(dap_obs[0].do_str[typen], "N"))
	    {
	      nobs[ncells] = dap_obs[0].do_dbl[varv[0]];
	      gotn = 1;
	    }
	  else if (!strcmp(dap_obs[0].do_str[typen], "MEAN"))
	    {
	      mean[ncells] = dap_obs[0].do_dbl[varv[0]];
	      gotm = 1;
	    }
	  else if (!strcmp(dap_obs[0].do_str[typen], "VAR"))
	    {
	      vari[ncells] = dap_obs[0].do_dbl[varv[0]];
	      gotv = 1;
	    }
	  else
	    {
	      fprintf(dap_err, "(lsmeans) Bad cell statistic: %s\n",
		      dap_obs[0].do_str[typen]);
	      exit(1);
	    }
	  if (++s < 3)
	    more = step();
	  else
	    {
	      if (nobs[ncells] == 1.0)
		vari[ncells] = 0.0;
	      break;
	    }
	}
      if (more)
	{
	  if (!gotm)
	    {
	      fputs("(lsmeans) Missing MEAN.\n", dap_err);
	      exit(1);
	    }
	  if (!gotn)
	    {
	      fputs("(lsmeans) Missing N.\n", dap_err);
	      exit(1);
	    }
	  if (!gotv)
	    {
	      fputs("(lsmeans) Missing VAR.\n", dap_err);
	      exit(1);
	    }
	  levn(dap_obs[0].do_str[treatn], levval, &nlevels);
	}
      for (nerrors = 0; more; )
	{
	  more = step();
	  err = !strcmp(dap_obs[0].do_str[typen], "ERROR");
	  con = !strcmp(dap_obs[0].do_str[typen], "CONTR");
	  if (err || con)
	    {
	      coeff[nerrors][ncells] = dap_obs[0].do_dbl[varv[0]];
	      nerrors++;
	    }
	  else
	    break;
	}
      for (nlsmeans = 0; more; )
	{
	  if (!strcmp(dap_obs[0].do_str[typen], "LSMEAN"))
	    {
	      coeff[nerrors + nlsmeans][ncells] =
		dap_obs[0].do_dbl[varv[0]];
	      nlsmeans++;
	    }
	  else
	    break;
	  more = step();
	}
      if (!strcmp(dap_obs[0].do_str[typen], "MSERROR"))
	{
	  mse = dap_obs[0].do_dbl[varv[0]];
	  if (more && (more = step()) &&
	      !strcmp(dap_obs[0].do_str[typen], "ERRORDF"))
	    {
	      edf = dap_obs[0].do_dbl[varv[0]];
	      if (more)
		more = step();
	    }
	  else
	    {
	      fprintf(dap_err, "(lsmeans1) Expected ERRORDF: %s\n",
		      dap_obs[0].do_str[typen]);
	      exit(1);
	    }
	}
    }
  args1 = dap_malloc(strlen(marks) + strlen(treat2) + strlen(treat) + 10 + 15, "");
  sprintf(args1, "%s _type_ _LSMEAN_ %s _lsm_ %s", marks, treat2, treat);
  sort(lsmname, args1, "");
  sprintf(args1, "_type_ _LSMEAN_ %s", treat2);
  args2 = dap_malloc(strlen(treat) + 8 + 6, treat);
  sprintf(args2, "_lsm_ %s _stat_", treat);
  while (*format == ' ')	/* here we want to deny user sorting */
    format++;
  if (*format == 's')
    format++;
  table(lsmsrt, args1, args2, format, marks);
  dap_free(varv, "");
  dap_free(markv, "");
  dap_free(lsmname, "");
  dap_free(lsmsrt, "");
  dap_free(varstr, "");
  dap_free(treat2, "");
  dap_free(args1, "");
  dap_free(args2, "");
  dap_free(levmem, "");
  dap_free(levval, "");
  dap_free(comem, "");
  dap_free(coeff, "");
  dap_free(mean, "");
  dap_free(nobs, "");
  dap_free(vari, "");
}
