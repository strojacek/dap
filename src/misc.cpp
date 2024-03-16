/* misc.c -- miscellaneous functions for dap */

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
#include <stdlib.h>
#include <math.h>
#include "dap_make.h"
#include "externs.h"

extern FILE *dap_err;
extern FILE *dap_log;

static int mdays[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int dap_numdate(char date[])        /* number of days since 12/31/1751 */
{
  int d; /* index to date */
  int dday; /* start of day */
  int dyr; /* start of year */
  int mon;
  int day;
  int yr;
  int m;
  int y;
  int ndays;

  for (d = 0, mon = 0; d < 2 && '0' <= date[d] && date[d] <= '9'; d++)
    mon = 10 * mon + date[d] - '0';
  if (date[d] == '/')
    d++;
  for (dday = d, day = 0; d < dday + 2 && '0' <= date[d] && date[d] <= '9'; d++)
    day = 10 * day + date[d] - '0';
  if (date[d] == '/')
    d++;
  for (dyr = d, yr = 0; d < dyr + 4 && '0' <= date[d] && date[d] <= '9'; d++)
    yr = 10 * yr + date[d] - '0';
  if (d < dyr + 4)
    return -1;
  for (m = 1, ndays = day; m < mon; m++)
    ndays += mdays[m];
  if ((mon > 2) && !(yr % 4) && (yr % 100))
    ndays++;
  if (yr < 1752)
    return -1;
  for (y = 1752; y < yr; y++)
    {
      ndays += 365;
      if (!(y % 4) && ((y % 100) || !(y % 400)))
	ndays++;
    }
  return ndays;
}

void dap_datenum(int n, char *d)
{
  int mon;
  int day;
  int yr;
  int ndays;

  if (n <= 0)
    {
      strcpy(d, "?");
      return;
    }
  yr = 1752;
  sprintf(d, "0101%4d", yr);
  ndays = dap_numdate(d);
  while (ndays <= n)
    {
      if (yr < 10000)
	{
	  sprintf(d, "0101%4d", ++yr);
	  ndays = dap_numdate(d);
	}
      else
	{
	  strcpy(d, "?");
	  return;
	}
    }
  --yr;
  mon = 1;
  sprintf(d, "%02d01%4d", mon, yr);
  ndays = dap_numdate(d);
  while (ndays <= n)
    {
      sprintf(d, "%02d01%4d", ++mon, yr);
      if (mon <= 12)
	ndays = dap_numdate(d);
      else
	break;
    }
  --mon;
  day = 1;
  sprintf(d, "%02d%02d%4d", mon, day,  yr);
  ndays = dap_numdate(d);
  while (ndays < n)
    {
      sprintf(d, "%02d%02d%4d", mon, ++day, yr);
      if (day <= mdays[mon])
	ndays = dap_numdate(d);
      else
	exit(1);
    }
}

double dap_bincoeff(double n, double r)
{
  double b;

  for (b = 1.0; r > 0.0; r -= 1.0, n -= 1.0)
    b *= n / r;
  return rint(b);
}

static void takestep(double *x, double *y, double *d, int n, double step)
{
  int i;

  for (i = 0; i < n; i++)
    x[i] = y[i] + d[i] * step;
}

static void vcopy(double *x, double *y, int n)
{
  int i;

  for (i = 0; i < n; i++)
    x[i] = y[i];
}

static void vsub(double *x, double *y, int n)
{
  int i;

  for (i = 0; i < n; i++)
    x[i] -= y[i];
}

static double vlen(double *x, int nx)
{
  double len;
  int n;

  for (n = 0, len = 0.0; n < nx; n++)
    len += x[n] * x[n];
  return sqrt(len);
}

static double dirstep(double (*f)(double xx[]), int nx,
		      double x[], double x1[], double f0, double step, double tol)
{
  int n;
  static double f1, f2, f3;
  double dstep;

  for (n = 0; n < nx; n++)
    x1[n] = x[n];
  for (n = 0; n < nx; n++)
    {
      x1[n] = x[n] - step;
      f1 = (*f)(x1);
      x1[n] = x[n] + step;
      f2 = (*f)(x1);
      dstep = step * (f1 - f2) / (f1 - 2.0 * f0 + f2) / 2.0;
      if (isfinite(dstep) && fabs(dstep) > tol && ((f1 < f0 && f0 < f2) ||
						 (f1 > f0 && f0 > f2)))
	{
	  x1[n] = x[n] + dstep;
	  f3 = (*f)(x1);
	  if (isfinite(f3) && f3 > f1 && f3 > f2)
	    f0 = f3;
	  else if (f1 > f0)
	    {
	      f0 = f1;
	      x1[n] = x[n] - step;
	    }
	  else
	    {
	      f0 = f2;
	      x1[n] = x[n] + step;
	    }
	}
      else
	x1[n] = x[n];
    }
  return f0;
}

double dap_maximize(double (*f)(double xx[]), int nx, double x[],
		    double step, double tol, char *trace)
{
  int tr;
  int ntries;
  double *x1, *x2;
  static double f0;
  static double f1, f2;
  double *dir;
  double dirlen;
  double dstep;
  int n;
  int d;
  int traceout;	/* number of trace steps per output */
  int t;
  int nsteps;

  x1 = (double *) dap_malloc(sizeof(double) * nx, "");
  x2 = (double *) dap_malloc(sizeof(double) * nx, "");
  dir = (double *) dap_malloc(sizeof(double) * nx, "");
  tr = 0;
  if (trace && trace[0])
    {
      if (!strncmp(trace, "TRACE", 5) || !strncmp(trace, "PAUSE", 5))
	{
	  if (trace[0] == 'T')
	    tr = 1;
	  else
	    tr = 2;
	  for (t = 5; trace[t] == ' '; t++)
	    ;
	  for (traceout = 0; '0' <= trace[t] && trace[t] <= '9'; t++)
	    traceout = 10 * traceout + trace[t] - '0';
	  while (trace[t] == ' ')
	    t++;
	  if (trace[t])
	    {
	      fprintf(dap_err, "(dap_maximize) bad trace interval: %s\n",
		      trace);
	      exit(1);
	    }
	}
      else
	{
	  fprintf(dap_err, "(dap_maximize) bad tracing option: %s\n", trace);
	  exit(1);
	}
    }
  else
    tr = 0;
  for (f0 = (*f)(x), nsteps = 0; ; nsteps++)
    {
      if (nsteps > dap_maxiter)
	{
	  fprintf(dap_err,
		  "(dap_maximize) stepsize = %g failed to reach tolerance = %g after %d iterations\n",
		  step, tol, nsteps);
	  break;
	}
      f1 = dirstep(f, nx, x, x1, f0, step, tol);
      if (f1 > f0)
	{
	  vcopy(dir, x1, nx);
	  vsub(dir, x, nx);
	  dirlen = vlen(dir, nx);
	  vcopy(x2, x, nx);
	  vsub(x2, dir, nx);
	  f2 = (*f)(x2);
	  dstep = (f2 - f1) / (f1 - 2.0 * f0 + f2) / 2.0;
	  if (isfinite(dstep) && dstep > tol / step)
	    {
	      takestep(x2, x, dir, nx, dstep);
	      f2 = (*f)(x2);
	      if (isfinite(f2) && f2 > f1)
		{
		  vcopy(x1, x2, nx);
		  f1 = f2;
		}
	    }
	}
      if (tr && (!traceout || !(nsteps % traceout)))
	{
	  fprintf(dap_log,
		  "(dap_maximize) nsteps = %d, f0 = %.16g, f1 = %.16g, step = %g\ndir = ",
		  nsteps, f0, f1, step);
	  fprintf(stderr,
		  "(dap_maximize) nsteps = %d, f0 = %.16g, f1 = %.16g, step = %g\ndir = ",
		  nsteps, f0, f1, step);
	  for (n = 0; n < nx; n++)
	    {
	      fprintf(dap_log, " %g", dir[n]);
	      fprintf(stderr, " %g", dir[n]);
	    }
	  fputs("\nx =", dap_log);
	  fputs("\nx =", stderr);
	  for (n = 0; n < nx; n++)
	    {
	      fprintf(dap_log, " %g", x[n]);
	      fprintf(stderr, " %g", x[n]);
	    }
	  putc('\n', dap_log);
	  putc('\n', stderr);
	  fflush(stderr);
	  if (tr == 2)
	    getchar();
	}
      if (f1 <= f0)
	{
	  step /= 2.0;
	  if (step < tol)
	    break;
	}
      else
	{
	  f0 = f1;
	  vcopy(x, x1, nx);
	}
    }
  dap_free(x1, "");
  dap_free(x2, "");
  dap_free(dir, "");
  return f0;
}
