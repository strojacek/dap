/* prob.c -- probability and miscellaneous functions for dap
 *
 * Some of these are pretty crude, but they work well enough:
 * some other time, folks.
 */

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

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "externs.h"

extern FILE *dap_err;

#define PI 3.14159265358979323846
#define HALFPI 1.57079632679489661923
#define SQRTPI 1.772453850905516027297
#define SQRTHALF 0.707106781186547524401
#define INVSQ2PI 0.398942280401432677940
#define INVSQRTE 0.60653065971263343973
#define E 2.7182818284590450908
#define INVE 0.36787944117144234115

double dap_simp(double (*f)(), double a, double b, int n)
{
  double h;
  double val;
  int i;

  h = (b - a) / ((double) n);
  val = 0.0;
  for (i = 1; i <= n - 1; i += 2)
    val += 4.0 * (*f)(a + ((double) i) * h);
  for (i = 2; i <= n - 2; i += 2)
    val += 2.0 * (*f)(a + ((double) i) * h);
  val += (*f)(a) + (*f)(b);
  return val * h / 3.0;
}

static double dddi;

static double Tfun(double x)
{
  if (dddi == 0.0)
    return 1.0;
  return pow(cos(x), dddi - 1.0);
}

double probt(double t1, int di)
{
  double c;
  double ddi;

  if (!isfinite(t1))
    return 0.0 / 0.0;
  ddi = (double) di;
  dddi = ddi;
  for (c = 1.0; ddi > 2.0; ddi -= 2.0)
    c *= (ddi - 1.0) / (ddi - 2.0);
  if (ddi == 2.0)
    c *= 0.5;
  else
    c /= PI;
  return c * dap_simp(&Tfun, atan(t1 / sqrt(dddi)), HALFPI, 1024);
}

double zpoint(double p)
{
  static double a[4] = { 2.5066282, -18.6150006, 41.3911977, -25.4410605 };
  static double b[4] = { -8.4735109, 23.0833674, -21.0622410, 3.1308291 };
  static double c[4] = { -2.7871893, -2.2979648, 4.8501413, 2.3212128 };
  static double d[2] = { 3.5438892, 1.6370678 };
  double q, r, x, x0;

  q = p - 0.5;
  if (fabs(q) > 0.42)
    {
      r = p;
      if (q > 0.0)
	r = 1.0 - p;
      if (r <= 0.0)
	{
	  fputs("(zpoint) input not between 0 and 1\n", dap_err);
	  exit(1);
	}
      r = sqrt(-log(r));
      x = ((c[3] * r + c[2]) * r + c[1]) * r + c[0];
      x0 = x / ((d[1] * r + d[0]) * r + 1.0);
      if (q < 0.0)
	x0 = -x0;
    }
  else
    {
      r = q * q;
      x = q * (((a[3] * r + a[2]) * r + a[1]) * r + a[0]);
      x0 = x / ((((b[3] * r + b[2]) * r + b[1]) * r + b[0]) * r + 1.0);
    }
  return -x0;
}

double tpoint(double p, int df)
{
  double pt0, pr0;
  double pt1, pr1;
  double pt2, pr2;

  pt2 = 0.0;	/* make compiler happy */
  pt0 = zpoint(p);
  pr0 = probt(pt0, df);
  pt1 = 2.0 * pt0;
  pr2 = pr0;
  while (fabs(pr2 - p) > dap_prtol)
    {
      pr1 = probt(pt1, df);
      pt2 = pt0 + (pt1 - pt0) * (p - pr0) / (pr1 - pr0);
      if (pt2 < 0.0)
	{
	  if (pt0 < pt1)
	    pt2 = 0.5 * pt0;
	  else
	    pt2 = 0.5 * pt1;
	}
      pr2 = probt(pt2, df);
      if (fabs(pr2 - pr0) < fabs(pr2 - pr1))
	{
	  pr1 = pr2;
	  pt1 = pt2;
	}
      else
	{
	  pr0 = pr2;
	  pt0 = pt2;
	}
    }
  return pt2;
}

static double dmpln, drat, dnm1;

static double Ffun(double x)
{
  if (dnm1 > 0.0)
    return pow(x, dnm1) / pow(1.0 + drat * x, dmpln);
  else
    return 1.0 / pow(1.0 + drat * x, dmpln);
}

double probf(double f0, int numdf, int dendf)
{
  double c;
  double dm, dn, dmpn;
  double ddn;
  double b;
  double s, s0, s1, s2;

  if (!isfinite(f0))
    return 0.0 / 0.0;
  if (numdf == 1)
    return 2.0 * probt(sqrt(f0), dendf);
  dn = 0.5 * (double) numdf;
  dm = 0.5 * (double) dendf;
  dmpn = dn + dm;
  dmpln = dm + dn;
  dnm1 = dn - 1.0;
  drat = dn / dm;
  ddn = dn;
  for (c = 1.0; dmpn >= 0.5; )
    {
      dm -= 1.0;
      dn -= 1.0;
      dmpn -= 1.0;
      if (dm > 0.0)
	c /= dm;
      else if (dm == -0.5)
	c /= SQRTPI;
      if (dn > 0.0)
	c /= dn;
      else if (dn == -0.5)
	c /= SQRTPI;
      if (dmpn > 0.0)
	c *= dmpn;
      else if (dmpn == -0.5)
	c *= SQRTPI;
    }
  c *= pow(drat, ddn);
  for (b = 1.0; f0 >= b; b *= 2.0)
    ;
  s = dap_simp(&Ffun, f0, b, 1024);
  s0 = dap_simp(&Ffun, b, 2.0 * b, 1024);
  b *= 2.0;
  s1 = dap_simp(&Ffun, b, 2.0 * b, 1024);
  b *= 2.0;
  s2 = dap_simp(&Ffun, b, 2.0 * b, 1024);
  s += s0 + s1 + s2;
  while (s2 < s1 && (s2 * s2 / (s1 - s2) > 5.0e-11 / c))
    {
      b *= 2.0;
      s0 = s1;
      s1 = s2;
      s2 = dap_simp(&Ffun, b, 2.0 * b, 1024);
      s += s2;
    }
  return c * s;
}

double fpoint(double p, int numdf, int dendf)
{
  double pt0, pr0;
  double pt1, pr1;
  double pt2, pr2;

  pt2 = 0.0;	/* make compiler happy */
  pt0 = ((double) numdf) / ((double) dendf);
  pr0 = probf(pt0, numdf, dendf);
  pt1 = 2.0 * pt0;
  pr2 = 1.0;
  while (fabs(pr2 - p) > dap_prtol)
    {
      pr1 = probf(pt1, numdf, dendf);
      pt2 = pt0 + (pt1 - pt0) * (p - pr0) / (pr1 - pr0);
      if (pt2 < 0.0)
	{
	  if (pt0 < pt1)
	    pt2 = 0.5 * pt0;
	  else
	    pt2 = 0.5 * pt1;
	}
      pr2 = probf(pt2, numdf, dendf);
      if (fabs(pr2 - pr0) < fabs(pr2 - pr1))
	{
	  pr1 = pr2;
	  pt1 = pt2;
	}
      else
	{
	  pr0 = pr2;
	  pt0 = pt2;
	}
    }
  return pt2;
}

static double randmax = 2147483647.0;

double varnorm()
{
  double u1, u2, v1, v2, w;

  do      {
    u1 = 2.0 * ((double) random()) / randmax - 1.0;
    v1 = u1 * u1;
    u2 = 2.0 * ((double) random()) / randmax - 1.0;
    v2 = u2 * u2;
  } while ((w = v1 + v2) > 1.0);
  w = sqrt(-2.0 * log(w) / w);
  return u1 * w;
}

double varunif()
{
  return ((double) random()) / randmax;
}

double probz(double z)
{
  if (!isfinite(z))
    return 0.0 / 0.0;
  z *= SQRTHALF;
  if (z < -0.58)
    return 0.5 * erfc(-z);
  if (z < 0.0)
    return 0.5 * (1.0 - erf(-z));
  if (z < 0.58)
    return 0.5 * (1.0 + erf(z));
  return 1.0 - 0.5 * erfc(z);
}

double probchisq(double c, int df)
{
  double ddf;
  double tmp;

  if (df < 0)
    {
      fprintf(dap_err, "(probchisq) non-positive df = %d\n", df);
      exit(1);
    }
  if (!isfinite(c))
    return 0.0 / 0.0;
  switch (df)
    {
    case 1:
      return 2.0 * probz(-sqrt(c));
    case 2:
      return exp(-0.5 * c);
    default:
      ddf = (double) df;
      tmp = (0.5 * ddf - 1.0) * log(0.5 * c) - 0.5 * c -
	lgamma(0.5 * ddf);
      if (isfinite(tmp))
	return exp(tmp) + probchisq(c, df - 2);
      return 0.0;
      /* Orginal code:
	 return exp((0.5 * ddf - 1.0) * log(0.5 * c) - 0.5 * c -
	 lgamma(0.5 * ddf)) + probchisq(c, df - 2);
      */
      break;
    }
}

double chisqpoint(double p, int df)
{
  double pt0, pr0;
  double pt1, pr1;
  double pt2, pr2;

  pt2 = 0.0;	/* make compiler happy */
  pt0 = (double) df;
  pr0 = probchisq(pt0, df);
  pt1 = 2.0 * pt0;
  pr2 = 1.0;
  while (fabs(pr2 - p) > dap_prtol)
    {
      pr1 = probchisq(pt1, df);
      pt2 = pt0 + (pt1 - pt0) * (p - pr0) / (pr1 - pr0);
      if (pt2 < 0.0)
	{
	  if (pt0 < pt1)
	    pt2 = 0.5 * pt0;
	  else
	    pt2 = 0.5 * pt1;
	}
      pr2 = probchisq(pt2, df);
      if (fabs(pr2 - pr0) < fabs(pr2 - pr1))
	{
	  pr1 = pr2;
	  pt1 = pt2;
	}
      else
	{
	  pr0 = pr2;
	  pt0 = pt2;
	}
    }
  return pt2;
}

static double w;
static double numdfm1, dendfm1;
static double dnumdf, ddendf;
static double pt;

double rangef1(double x0)
{
  double diff;
  double x, x1, x2;
  double tmp;

  if (x0 == -1.0)
    return 0.0;
  x1 = 1.0 + x0;
  x = x0 / x1;
  x2 = x1 * x1;
  diff = probz(x + w) - probz(x);
  if (diff / x2 < 1.0e-16)
    return 0.0;
  tmp = -0.5 * x * x + numdfm1 * log(diff);
  if (isfinite(tmp))
    return exp(tmp) / (x1 * x1);
  return 0.0;
  /* Original code:
     return exp(-0.5 * x * x + numdfm1 * log(diff)) / (x1 * x1);
  */
}

double rangef2(double x0)
{
  double diff;
  double x, x1, x2;
  double tmp;

  if (x0 == 1.0)
    return 0.0;
  x1 = 1.0 - x0;
  x = x0 / x1;
  x2 = x1 * x1;
  diff = probz(x + w) - probz(x);
  if (diff / x2 < 1.0e-16)
    return 0.0;
  tmp = -0.5 * x * x + numdfm1 * log(diff);
  if (isfinite(tmp))
    return exp(tmp) / (x1 * x1);
  return 0.0;
  /* Original code:
     return exp(-0.5 * x * x + numdfm1 * log(diff)) / (x1 * x1);
  */
}


static double range(double w0)
{
  w = w0;
  return 1.0 - dnumdf * INVSQ2PI *
    (dap_simp(&rangef1, -1.0, 0.0, 32) + dap_simp(&rangef2, 0.0, 1.0, 32));
}

static double sturf(double s0)
{
  double s;
  double s1;
  double tmp;

  if (s0 == 1.0)
    return 0.0;
  s1 = 1.0 - s0;
  s = s0 / s1;
  if (dendfm1 == 0.0)
    return exp(-0.5 * s * s / E) * range(pt * s * INVSQRTE) / (s1 * s1);
  tmp = dendfm1 * log(s) - 0.5 * ddendf * s * s / E;
  if (isfinite(tmp))
    return exp(tmp) * range(pt * s * INVSQRTE) / (s1 * s1);
  return 0.0;
  /* Original code:
     return exp(dendfm1 * log(s) - 0.5 * ddendf * s * s / E) *
     range(pt * s * INVSQRTE) / (s1 * s1);
  */
}

double dap_sr(int numdf, int dendf, double pt0)	/* studentized range */
{
  double c;
  double dn, dn1;

  pt = pt0;
  dnumdf = (double) numdf;
  numdfm1 = (double) (dnumdf - 1);
  ddendf = (double) dendf;
  dendfm1 = (double) (dendf - 1);
  for (dn = 0.5 * ddendf, dn1 = dn * INVE, c = 2.0; dn > 1.0; dn -= 1.0)
    c *= dn1 / (dn - 1.0);
  if (dn == 0.5)
    c *= sqrt(dn1) / SQRTPI;
  else
    c *= dn1;
  return c * dap_simp(&sturf, 0.0, 1.0, 64);
}

double dap_srpt(int numdf, int dendf, double pt0, double pr0, double alpha)
{
  double pt1, pr1;
  double pt2, pr2;

  pt2 = 0.0;	/* make compiler happy */
  if (alpha < pr0)
    pt1 = 2.0 * pt0;
  else
    pt1 = 0.5 * pt0;
  pr2 = 1.0;
  while (fabs(pr2 - alpha) > dap_prtol)
    {
      pr1 = dap_sr(numdf, dendf, pt1);
      pt2 = pt0 + (pt1 - pt0) * (alpha - pr0) / (pr1 - pr0);
      if (pt2 < 0.0)
	{
	  if (pt0 < pt1)
	    pt2 = 0.5 * pt0;
	  else
	    pt2 = 0.5 * pt1;
	}
      pr2 = dap_sr(numdf, dendf, pt2);
      if (fabs(pr2 - pr0) < fabs(pr2 - pr1))
	{
	  pr1 = pr2;
	  pt1 = pt2;
	}
      else
	{
	  pr0 = pr2;
	  pt0 = pt2;
	}
    }
  return pt2;
}

double maxdf1(double x0)
{
  double diff;
  double x, x1, x2;

  if (x0 == -1.0)
    return 0.0;
  x1 = 1.0 + x0;
  x = x0 / x1;
  x2 = x1 * x1;
  diff = probz(x + w) - probz(x - w);
  if (diff / x2 < 1.0e-16)
    return 0.0;
  return exp(-0.5 * x * x + dnumdf * log(diff)) / (x1 * x1);
}

double maxdf2(double x0)
{
  double diff;
  double x, x1, x2;

  if (x0 == 1.0)
    return 0.0;
  x1 = 1.0 - x0;
  x = x0 / x1;
  x2 = x1 * x1;
  diff = probz(x + w) - probz(x - w);
  if (diff / x2 < 1.0e-16)
    return 0.0;
  return exp(-0.5 * x * x + dnumdf * log(diff)) / (x1 * x1);
}

static double maxdf(double w0)
{
  w = w0;
  return 1.0 - INVSQ2PI *
    (dap_simp(&maxdf1, -1.0, 0.0, 32) + dap_simp(&maxdf2, 0.0, 1.0, 32));
}

static double maxdiff(double s0)
{
  double s;
  double s1;

  if (s0 == 1.0)
    return 0.0;
  s1 = 1.0 - s0;
  s = s0 / s1;
  if (dendfm1 == 0.0)
    return exp(-0.5 * s * s / E) * maxdf(pt * s * INVSQRTE) / (s1 * s1);
  return exp(dendfm1 * log(s) - 0.5 * ddendf * s * s / E) *
    maxdf(pt * s * INVSQRTE) / (s1 * s1);
}

double dap_md(int numdf, int dendf, double pt0)	/* maximum difference */
{
  double c;
  double dn, dn1;

  pt = pt0;
  dnumdf = (double) numdf;
  numdfm1 = (double) (dnumdf - 1);
  ddendf = (double) dendf;
  dendfm1 = (double) (dendf - 1);
  for (dn = 0.5 * ddendf, dn1 = dn * INVE, c = 2.0; dn > 1.0; dn -= 1.0)
    c *= dn1 / (dn - 1.0);
  if (dn == 0.5)
    c *= sqrt(dn1) / SQRTPI;
  else
    c *= dn1;
  return c * dap_simp(&maxdiff, 0.0, 1.0, 256);
}

double dap_mdpt(int numdf, int dendf, double pt0, double pr0, double alpha)
{
  double pt1, pr1;
  double pt2, pr2;

  pt2 = 0.0;	/* make compiler happy */
  if (alpha < pr0)
    pt1 = 2.0 * pt0;
  else
    pt1 = 0.5 * pt0;
  pr2 = 1.0;
  while (fabs(pr2 - alpha) > dap_prtol)
    {
      pr1 = dap_md(numdf, dendf, pt1);
      pt2 = pt0 + (pt1 - pt0) * (alpha - pr0) / (pr1 - pr0);
      if (pt2 < 0.0)
	{
	  if (pt0 < pt1)
	    pt2 = 0.5 * pt0;
	  else
	    pt2 = 0.5 * pt1;
	}

      pr2 = dap_md(numdf, dendf, pt2);
      if (fabs(pr2 - pr0) < fabs(pr2 - pr1))
	{
	  pr1 = pr2;
	  pt1 = pt2;
	}
      else
	{
	  pr0 = pr2;
	  pt0 = pt2;
	}
    }
  return pt2;
}
