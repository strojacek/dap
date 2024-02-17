/* ps1.c -- higher level functions */

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
#include <math.h>
#include "dap_make.h"
#include "externs.h"
#include "ps.h"

#define LEFT 144.0
#define BOTTOM 144.0
#define PORTWIDTH 324.0
#define PORTHEIGHT 324.0
#define LANDWIDTH 324.0
#define LANDHEIGHT 324.0

extern dataobs dap_obs[];
extern FILE *dap_err;
extern void dap_dl(char varname[], double *dbl);
extern void dap_il(char varname[], int *i);
extern void dap_sl(char varname[], char *s);
extern char *pict_newstr(char *str);

void pict_maketick(tick *t, double num, char *label, double len)
{
  t->tick_num = num;
  t->tick_lab = pict_newstr(label);
  t->tick_len = len;
}

/* Add an y-axis to the picture pointed to by p.
 * ytick is the array of ticks to use, nyticks is the number, not counting
 *	the axis label, which is the highest numbered "tick"
 * ypos is the y-coordinate of the y-axis, xpos is the y-coordinate of
 *	the x-axis: drawing ends at (ypos, xpos)
 * side = 1.0 for ticks extending to the right from the axis, -1.0 for left
 * marks indicates whether tick marks should be used
 */
static void yaxis(pict *p, double miny, double maxy, tick ytick[], int nyticks,
		  double xpos, double ypos, double side, int marks)
{
  int ny;		/* index to ytick[] */
  char tpos[4];	/* text positioning string for axis label */
  char npos[3];	/* text positioning string for numerical values */
  double xlaboff;	/* x offset for label */
  double txtang;	/* for rotating the label if it lies along the axis */
  int lab1len;	/* string length of one label */
  int labslen;	/* maximum string length of labels */

  strcpy(tpos, "cb ");	/* coordinates give center, bottom point of axis label */
  if (side > 0.0)		/* if ticks extend to right */
    strcpy(npos, "rm");	/* coordinates give right, middle point of number */
  else			/* if ticks extend to left */
    strcpy(npos, "lm");	/* coordinates give left, middle point of number */
  for (labslen = 0, ny = 0; ny < nyticks; ny++)
    {		/* find maximum string length of numerical labels */
      lab1len = strlen(ytick[ny].tick_lab);
      if (lab1len > labslen)
	labslen = lab1len;
    }
  txtang = 0.0;	/* used if label is at the top of the y-axis */
  /* check to see if axes label "tick" is between bottom and top "real" ticks,
   * so that axis label is along side the axis
   */
  if (miny <= ytick[nyticks].tick_num && ytick[nyticks].tick_num <= maxy)
    {
      /* have to increase distance for label to leave room for
       * numerical labels
       */
      strcpy(tpos, "cb ");	/* coordinates give center, bottom point of axis label */
      xlaboff = 0.25 * p->pict_fs * ((double) (labslen + 6)) * fabs(ytick[nyticks].tick_len);
      txtang = side * 90.0;
    }
  else if (ytick[nyticks].tick_num < miny)	/* label at bottom */
    {
      strcpy(tpos, "ct ");	/* coordinates give center, top point of axis label */
      xlaboff = 0.0;
    }
  else							/* label at top */
    {
      strcpy(tpos, "cb ");	/* coordinates give center, bottom point of axis label */
      xlaboff = 0.0;
    }
  /* for ticks extending to right or if extending to left and using marks */
  if (side > 0.0 || marks)
    pict_text(p, ytick[nyticks].tick_lab, ypos - side * xlaboff,
	      ytick[nyticks].tick_num, txtang, tpos);
  pict_point(p, ypos, maxy);
  while (--nyticks >= 0)
    {
      pict_point(p, ypos, ytick[nyticks].tick_num);
      pict_point(p, ypos + side * ytick[nyticks].tick_len, ytick[nyticks].tick_num);
      pict_point(p, ypos, ytick[nyticks].tick_num);
      if (side > 0.0 || marks)
	pict_text(p, ytick[nyticks].tick_lab,
		  ypos - (4.5 * side - 0.5) * fabs(ytick[nyticks].tick_len),
		  ytick[nyticks].tick_num, 0.0, npos);
    }
  pict_point(p, ypos, miny);
  pict_point(p, ypos, xpos);
}

/* Add an x-axis to the picture pointed to by p.
 * xtick is the array of ticks to use, nxticks is the number, not counting
 *	the axis label, which is the highest numbered "tick"
 * xpos is the y-coordinate of the x-axis, ypos is the x-coordinate of
 *	the y-axis: drawing ends at (ypos, xpos)
 * side = 1.0 for ticks extending up from the axis, -1.0 for down
 * marks indicates whether tick marks should be placed on the axis
 */
static void xaxis(pict *p, double minx, double maxx, tick xtick[], int nxticks,
		  double xpos, double ypos, double side, int marks)
{
  int nx;		/* index to xtick array */
  char tpos[4];	/* position string for axis label for pict_text */
  char npos[3];	/* position string for numerical labels for pict_text */
  double ylaboff;	/* y offset for label */
  int lab1len;	/* length of one numerical label */
  int labslen;	/* max length of numerical labels */

  strcpy(tpos, "lt ");	/* default for axis label is left, top of label at tick */
  strcpy(npos, "ct");	/* default for tick label is centered, top of label at tick */
  for (labslen = 0, nx = 0; nx < nxticks; nx++)
    {		/* find maximum string length of numerical labels */
      lab1len = strlen(xtick[nx].tick_lab);
      if (lab1len > labslen)
	labslen = lab1len;
    }
  if (minx <= xtick[nxticks].tick_num && xtick[nxticks].tick_num <= maxx)
    {	/* if the axis label is going on the side, not the end */
      tpos[0] = 'c';	/* center the text */
      if (side < 0.0)
	{
	  tpos[1] = 'b';
	  npos[1] = 'b';
	}
      ylaboff = fabs(p->pict_fs * xtick[nxticks].tick_len); /* make room for label */
    }
  else if (xtick[nxticks].tick_num < minx)	/* axis label at left end */
    {
      strcpy(tpos, "rm ");
      ylaboff = 0.0;
    }
  else							/* axis label at right end */
    {
      strcpy(tpos, "lm ");
      ylaboff = 0.0;
    }
  if (side > 0.0 || marks)	/* this is the axis label, but only label if ticking */
    pict_text(p, xtick[nxticks].tick_lab, xtick[nxticks].tick_num,
	      xpos - side * ylaboff, 0.0, tpos);
  pict_point(p, maxx, xpos);
  while (--nxticks >= 0)	/* for the real ticks */
    {
      pict_point(p, xtick[nxticks].tick_num, xpos);
      if (side > 0.0 || marks)
	pict_point(p, xtick[nxticks].tick_num, xpos + side * xtick[nxticks].tick_len);
      pict_point(p, xtick[nxticks].tick_num, xpos);
      if (side > 0.0 || marks)
	pict_text(p, xtick[nxticks].tick_lab, xtick[nxticks].tick_num,
		  xpos - 2.0 * side * fabs(xtick[nxticks].tick_len), 0.0, npos);
    }
  pict_point(p, minx, xpos);
  pict_point(p, ypos, xpos);	/* end up at ypos, xpos */
}

/* Make axes for the picture *p:
 * xtick[], nxticks, ytick[], nyticks are arrays and counts of ticks
 *  counts in
 * style indicates which axes should appear and where
 * bpos is position of lower end of y-axis
 * lpos is position of left end of x-axis
 * tpos is position of top end of y-axis
 * rpos is position of right end of x-axis
 */
void pict_axes(pict *p, double minx, double maxx, tick xtick[], int nxticks,
	       double miny, double maxy, tick ytick[], int nyticks,
	       char style[], double bpos, double lpos, double tpos, double rpos)
{
  double xpos, ypos;	/* y-coordinate of x-axis, x-coordinate of y-axis */
  int rmarks, tmarks;	/* put tick marks on right, top? */

  xpos = 0.0;	/* default is x-axis at 0 on y-axis */
  ypos = 0.0;	/* default is y-axis at 0 on x-axis */
  rmarks = 0;	/* default is no ticks on right axis */
  tmarks = 0;	/* default is no ticks on top axis */
  if (style[0] == '+' || style[0] == '#')	/* ticked axis at top */
    tmarks = 1;
  if (style[1] == '+' || style[1] == '#')	/* ticked axis at right */
    rmarks = 1;
  if (style[0] != '=' && style[1] != '=' &&
      style[0] != '#' && style[1] != '#')
    {			/* at most one of each axis */
      switch (style[0])
	{
	case '-':
	  xpos = bpos;
	  break;
	case '+':
	  xpos = tpos;
	  break;
	case '0':
	case 'n':
	  xpos = 0.0;
	  break;
	}
      switch (style[1])
	{
	case '-':
	  ypos = lpos;
	  break;
	case '+':
	  ypos = rpos;
	  break;
	case '0':
	case 'n':
	  ypos = 0.0;
	  break;
	}
      switch (style[0])
	{
	case '-':
	case '0':
	  xaxis(p, minx, maxx, xtick, nxticks, xpos, ypos, 1.0, tmarks);
	  break;
	case '+':
	  xaxis(p, minx, maxx, xtick, nxticks, xpos, ypos, -1.0, tmarks);
	  break;
	case 'n':
	  break;
	}
      switch (style[1])
	{
	case '-':
	case '0':
	  yaxis(p, miny, maxy, ytick, nyticks, xpos, ypos, 1.0, rmarks);
	  break;
	case '+':
	  yaxis(p, miny, maxy, ytick, nyticks, xpos, ypos, -1.0, rmarks);
	  break;
	case 'n':
	  break;
	}
    }
  else if (style[0] != '=' && style[0] != '#')
    {	/* y-axis on left and right, but only one x-axis */
      switch (style[0])
	{
	case '-':
	  xpos = bpos;
	case '0':
	  yaxis(p, miny, maxy, ytick, nyticks, xpos, lpos, 1.0, rmarks);
	  xaxis(p, minx, maxx, xtick, nxticks, xpos, lpos, 1.0, tmarks);
	  xaxis(p, minx, maxx, xtick, nxticks, xpos, rpos, 1.0, tmarks);
	  yaxis(p, miny, maxy, ytick, nyticks, xpos, rpos, -1.0, rmarks);
	  break;
	case '+':
	  yaxis(p, miny, maxy, ytick, nyticks, tpos, lpos, 1.0, rmarks);
	  xaxis(p, minx, maxx, xtick, nxticks, tpos, lpos, -1.0, tmarks);
	  xaxis(p, minx, maxx, xtick, nxticks, tpos, rpos, -1.0, tmarks);
	  yaxis(p, miny, maxy, ytick, nyticks, tpos, rpos, -1.0, rmarks);
	  break;
	case 'n':
	  fputs("(axes) Can't have double y-axes and no x-axis.\n", dap_err);
	  exit(1);
	}
    }
  else if (style[1] != '=' && style[1] != '#')
    {	/* x-axis on top and bottom, but only one y-axis */
      switch (style[1])
	{
	case '-':
	  ypos = lpos;
	case '0':
	  xaxis(p, minx, maxx, xtick, nxticks, bpos, ypos, 1.0, tmarks);
	  yaxis(p, miny, maxy, ytick, nyticks, bpos, ypos, 1.0, rmarks);
	  yaxis(p, miny, maxy, ytick, nyticks, tpos, ypos, 1.0, rmarks);
	  xaxis(p, minx, maxx, xtick, nxticks, tpos, ypos, -1.0, tmarks);
	  break;
	case '+':
	  xaxis(p, minx, maxx, xtick, nxticks, bpos, rpos, 1.0, tmarks);
	  yaxis(p, miny, maxy, ytick, nyticks, bpos, rpos, -1.0, rmarks);
	  yaxis(p, miny, maxy, ytick, nyticks, tpos, rpos, -1.0, rmarks);
	  xaxis(p, minx, maxx, xtick, nxticks, tpos, rpos, -1.0, tmarks);
	  break;
	case 'n':
	  fputs("(axes) Can't have double x-axes and no y-axis.\n", dap_err);
	  exit(1);
	}
    }
  else
    {	/* totally boxed */
      yaxis(p, miny, maxy, ytick, nyticks, bpos, lpos, 1.0, rmarks);
      xaxis(p, minx, maxx, xtick, nxticks, bpos, rpos, 1.0, tmarks);
      yaxis(p, miny, maxy, ytick, nyticks, tpos, rpos, -1.0, rmarks);
      xaxis(p, minx, maxx, xtick, nxticks, tpos, lpos, -1.0, tmarks);
    }
}

#define AXISMARGIN 0.05
#define RADIUSFACTOR 100.0

/* make label; OK this can crash the eventual sprintf if you have some really,
 * really big number with more than dap_maxtxt-1 digits, but then your picture
 * wouldn't look so good either.
 */
static void makeform(char form[], double max, int ndigs)
{
  int ndec;	/* number of decimal places */
  double scale;	/* power of 10 to compare max to */

  if (ndigs > 9)
    ndigs = 9;
  max = fabs(max);
  strcpy(form, "%.0f");
  if (max == 0.0)		/* this really shouldn't happen */
    sprintf(form, "%%.%dg", ndigs);
  else
    {
      for (scale = 1.0; ndigs > 1; ndigs--)
	scale *= 10.0;
      for (ndec = 0; max < scale; max *= 10.0)
	ndec++;
      if (ndec > 9)
	ndec = 9;
      form[2] += ndec;
    }
}

/* Make array of ticks */
static void ticks(
		  tick ticks[],		/* array of ticks to make, allocated by caller */
		  double min,		/* coordinate of lowest valued tick */
		  double max,		/* coordinate of highest valued tick */
		  int ndigs,		/* number of digits for tick label */
		  double ticklen,	/* length of tick line */
		  int nticks,		/* number of ticks requested not including axis label */
		  double labpos,		/* position of axis label */
		  char *alab,		/* axis label */
		  double (*tfunct)()	/* function for adjusting printed values at ticks */
		  )
{
  int n;
  static char *lab;
  double coord;
  double space;
  double tcoord;		/* coord or transformed coord */
  char form[5];		/* format string */
  double tmin, tmax;	/* (possibly) transformed min, max */

  if (!lab)
    lab = dap_malloc(dap_maxtxt + 1, "dap_maxtxt");
  if (nticks > 1)
    space = (max - min) / (double) (nticks - 1);
  else
    space = 0;
  if (tfunct)
    tmin = tfunct(min);
  else
    tmin = min;
  tmin = fabs(tmin);
  if (tfunct)
    tmax = tfunct(max);
  else
    tmax = max;
  tmax = fabs(tmax);
  if (tmin > tmax)
    tmax = tmin;
  makeform(form, tmax, ndigs);
  for (n = 0; n < nticks; n++)
    {
      if (nticks > 1)
	coord = min + space * (double) n;
      else
	coord = (min + max) / 2.0;
      if (tfunct)
	tcoord = (*tfunct)(coord);
      else
	tcoord = coord;
      sprintf(lab, form, tcoord);
      pict_maketick(ticks + n, coord, lab, ticklen);
    }
  pict_maketick(ticks + n, labpos, alab, ticklen);
}

/* set up axes automatically, using ranges of x, y in picts
 * xlab, ylab are labels for axes
 * axspec is string specifying where axes are
 * xfunct, yfunct are applied to numerical tick values to get labels
 * caption is caption underneath whole picture
 * autopos indicates whether or not to scale and translate into a
 *	standard size and position
 */
double pict_autoaxes(pict *p, char *xlab, char *ylab, char *axspec,
		     double (*xfunct)(), double (*yfunct)(), char *caption, int autopos)
{
  pict *pp;				/* for stepping through array of picts */
  int totpts;				/* total number of points */
  double minx, maxx, miny, maxy;		/* min, max values of x, y in picts */
  double minxt, maxxt, minyt, maxyt;	/* min, max tick values */
  int nxticks, nyticks;			/* number of ticks, for x, y */
  tick *xticks;				/* tick array for x */
  tick *yticks;				/* tick array for y */
  double xticklen;			/* length of tick mark for x */
  double yticklen;			/* length of tick mark for y */
  char as[3];				/* axis specifications, from axspec */
  double lpos, rpos, bpos, tpos;		/* axis positions: left, right ends of x-axis,
						 * bottom, top ends of y-axis
						 */
  double xlabpos, ylabpos;	/* coordinates of position of x, y axis labels */
  double captoff;			/* offset into caption */
  double width, height;		/* width, height of graph in points */
  double specxmax, specxmin;	/* specified min, max for x */
  double specymax, specymin;	/* specified min, max for y */
  int specxticks, specyticks;	/* specified number of ticks, for x, y */
  int nxdigs, nydigs;		/* number of digits for tick labels, for x, y */
  int a, w;			/* indexs to axspec, word */
  char *word;			/* word extracted from axspec */
  double digs, places, sign;	/* for computing max, min numbers */
  int nt;				/* number of ticks */
  double xscale, yscale;		/* to compensate for scaling in label positions */
  int xlablines;			/* number lines in xlabel */

  /* start out with centered around 0.0 */
  minx = 0.0;
  maxx = 0.0;
  miny = 0.0;
  maxy = 0.0;
  lpos = 0.0;
  rpos = 0.0;
  bpos = 0.0;
  tpos = 0.0;
  xlabpos = 0.0;
  ylabpos = 0.0;
  /* no scaling yet */
  xscale = 1.0;
  yscale = 1.0;
  captoff = 0.0;
  /* allocate tick arrays */
  xticks = (tick *) dap_malloc(sizeof(tick) * dap_maxntxt, "dap_maxntxt");
  yticks = (tick *) dap_malloc(sizeof(tick) * dap_maxntxt, "dap_maxntxt");
  /* default is nothing specified: make NaNs, -1 */
  specxmin = 0.0 / 0.0;
  specxmax = 0.0 / 0.0;
  specymin = 0.0 / 0.0;
  specymax = 0.0 / 0.0;
  specxticks = -1;
  specyticks = -1;
  nxdigs = 3;
  nydigs = 3;
  /* allocate word */
  word = dap_malloc(dap_namelen + 1, "");
  /* now parse the axis specifications, if present */
  if (axspec && axspec[0])
    {
      /* first skip blanks */
      for (a = 0; axspec[a] == ' '; a++)
	;
      /* if there are axis formats */
      if (axspec[a] == '-' || axspec[a] == '+' || axspec[a] == '0' ||
	  axspec[a] == 'n' || axspec[a] == '=' ||
	  axspec[a] == '#')
	{
	  /* copy to as */
	  as[0] = axspec[a++];
	  if (axspec[a] == '-' || axspec[a] == '+' || axspec[a] == '0' ||
	      axspec[a] == 'n' || axspec[a] == '=' ||
	      axspec[a] == '#')
	    as[1] = axspec[a++];
	  else	/* no second char, make '0' as default */
	    as[1] = '0';
	}
      else	/* otherwise, use default */
	strcpy(as, "00");
      as[2] = '\0';
      /* now look for other words */
      while (axspec[a] == ' ')
	a++;
      while (axspec[a])
	{
	  /* extract one word */
	  for (w = 0; axspec[a] && axspec[a] != ' '; )
	    {
	      if (w < dap_namelen)
		word[w++] = axspec[a++];
	      else
		{
		  word[w] = '\0';
		  fprintf(dap_err,
			  "(pict_autoaxes) word in axspec too long: %s\n",
			  word);
		  exit(1);
		}
	    }
	  word[w] = '\0';
	  if (!strncmp(word, "MAXX", 4) || !strncmp(word, "MINX", 4) ||
	      !strncmp(word, "MAXY", 4) || !strncmp(word, "MINY", 4))
	    {
	      /* for max, min spec, position at next char for number */
	      w = 4;
	      /* default is positive, see if negative */
	      sign = 1.0;
	      if (word[w] == '-')
		{
		  sign = -1.0;
		  w++;
		}
	      /* standard decimal conversion, allowing for dec pt */
	      for (digs = 0.0, places = 0.0;
		   ('0' <= word[w] && word[w] <= '9') ||
		     word[w] == '.'; w++)
		{
		  if (word[w] == '.')
		    {
		      if (places > 0.0)
			{
			  fprintf(dap_err,
				  "(pict_autoaxes) bad number for MIN or MAX: %s\n",
				  word + 4);
			  exit(1);
			}
		      places = 1.0;
		    }
		  else
		    {
		      if (places > 0.0)
			places *= 10.0;
		      digs = 10.0 * digs +
			(double) (word[w] - '0');
		    }
		}
	      digs *= sign;
	      if (places > 0.0)
		digs /= places;
	      /* should be space after number */
	      if (word[w] && word[w] != ' ')
		{
		  fprintf(dap_err,
			  "(pict_autoaxes) bad number for MIN or MAX: %s\n",
			  word + 3);
		  exit(1);
		}
	      /* mAx or mIn, m.X or m.Y */
	      if (word[1] == 'A')
		{
		  if (word[3] == 'X')
		    specxmax = digs;
		  else
		    specymax = digs;
		}
	      else
		{
		  if (word[3] == 'X')
		    specxmin = digs;
		  else
		    specymin = digs;
		}
	    }
	  /* now if was tick spec instead */
	  else if (!strncmp(word, "NXTICKS", 7) ||
		   !strncmp(word, "NYTICKS", 7))
	    {
	      /* integer conversion */
	      for (nt = 0, w = 7; '0' <= word[w] && word[w] <= '9'; w++)
		nt = 10 * nt + word[w] - '0';
	      /* should have number, should end in space */
	      if (word[w] && word[w] != ' ')
		{
		  fprintf(dap_err,
			  "(pict_autoaxes) bad number of ticks: %s\n",
			  word + 7);
		  exit(1);
		}
	      /* nXticks or nYticks */
	      if (word[1] == 'X')
		specxticks = nt;
	      else
		specyticks = nt;
	    }
	  /* now if specifying label precision */
	  else if (!strncmp(word, "NXDIGITS", 8) ||
		   !strncmp(word, "NYDIGITS", 8))
	    {
	      /* integer conversion */
	      for (nt = 0, w = 8; '0' <= word[w] && word[w] <= '9'; w++)
		nt = 10 * nt + word[w] - '0';
	      /* should have number, should end in space */
	      if (word[w] && word[w] != ' ')
		{
		  fprintf(dap_err,
			  "(pict_autoaxes) bad number of digits: %s\n",
			  word + 8);
		  exit(1);
		}
	      /* nXdigits or nYdigits */
	      if (word[1] == 'X')
		nxdigs = nt;
	      else
		nydigs = nt;
	    }
	  else	/* tried to match and failed */
	    {
	      fprintf(dap_err,
		      "(pict_autoaxes) bad axes specification: %s\n",
		      word);
	      exit(1);
	    }
	  /* and on to the next */
	  while (axspec[a] == ' ')
	    a++;
	}
    }
  else	/* the default */
    strcpy(as, "00");
  /* now we find the min, max for x, y for all the points in the pict
   * and check that there are indeed points
   */
  for (pp = p, totpts = 0; pp && pp->pict_next; pp = pp->pict_next)
    {	/* step through linked list of picts */
      if (pp->pict_npts)
	{
	  if (pp == p || minx > pp->pict_minx)
	    minx = pp->pict_minx;
	  if (pp == p || miny > pp->pict_miny)
	    miny = pp->pict_miny;
	  if (pp == p || maxx < pp->pict_maxx)
	    maxx = pp->pict_maxx;
	  if (pp == p || maxy < pp->pict_maxy)
	    maxy = pp->pict_maxy;
	  totpts += pp->pict_npts;
	}
    }
  if (!totpts)
    {
      fputs("(pict_autoaxes) no points.\n", dap_err);
      exit(1);
    }
  /* the specs were set to NaNs, so if finite, they were present */
  if (isfinite(specxmin))
    minx = specxmin;
  else	/* we like to make minx leave a little extra room and be a nice decimal;
	 * note that we are not dealing with xfunct and yfunct, because we have
	 * no inverse functions for them: the caller will just have to deal with those.
	 */
    {
      /* first make sure it includes 0 */
      if (minx > 0.0)
	minx = 0.0;
    }
  if (isfinite(specxmax))
    maxx = specxmax;
  else
    {
      if (maxx < 0.0)
	maxx = 0.0;
    }
  minxt = minx;
  minx -= AXISMARGIN * (maxx - minx);
  maxxt = maxx;
  maxx += AXISMARGIN * (maxx - minx);
  if (isfinite(specymin))
    miny = specymin;
  else
    {
      if (miny > 0.0)
	miny = 0.0;
    }
  if (isfinite(specymax))
    maxy = specymax;
  else
    {
      if (maxy < 0.0)
	maxy = 0.0;
    }
  minyt = miny;
  if (miny != 0.0)
    miny -= AXISMARGIN * (maxy - miny);
  maxyt = maxy;
  maxy += AXISMARGIN * (maxy - miny);
  if (specxticks >= 0)
    nxticks = specxticks;
  else
    nxticks = 11;
  if (nxticks > dap_maxntxt)
    {
      fprintf(dap_err, "(pict_autoaxes) Too many x-ticks (%d)\n", nxticks);
      exit(1);
    }
  if (specyticks >= 0)
    nyticks = specyticks;
  else
    nyticks = 11;
  if (nyticks > dap_maxntxt)
    {
      fprintf(dap_err, "(pict_autoaxes) Too many y-ticks (%d)\n", nyticks);
      exit(1);
    }
  xticklen = -2.0;
  yticklen = -2.0;
  if (autopos)
    {
      if (autopos == PORTRAIT)
	{
	  width = PORTWIDTH;
	  height = PORTHEIGHT;
	}
      else
	{
	  width = LANDWIDTH;
	  height = LANDHEIGHT;
	}
      xscale = width / (maxx - minx);
      yscale = height / (maxy - miny);
    }
  if (as[0] == '=' || as[0] == '#')	/* if x-axis is bottom and top */
    {
      bpos = miny;
      tpos = maxy;
      xlabpos = 0.5 * (minx + maxx);
      captoff = 4.0 * p->pict_fs / yscale;
    }
  else if (as[0] != 'n')		/* else if there is to be an x-axis at all */
    {
      switch (as[0])
	{
	case '-':
	  bpos = miny;
	  xlabpos = 0.5 * (minx + maxx);
	  captoff = 4.0 * p->pict_fs / yscale;
	  break;
	case '+':
	  tpos = maxy;
	  xlabpos = 0.5 * (minx + maxx);
	  captoff = 4.0 * p->pict_fs / yscale;
	  break;
	case '0':
	  bpos = 0.0;
	  if (as[1] == '+')
	    xlabpos = minx - 0.05 * (maxx - minx);
	  else
	    xlabpos = maxx + 0.05 * (maxx - minx);
	  captoff = 2.0 * p->pict_fs / yscale;
	  break;
	default:
	  fprintf(dap_err, "(pict_autoaxes) Bad axis specification: %s\n", axspec);
	  exit(1);
	}
    }
  if (as[1] == '=' || as[1] == '#')	/* if y-axis is bottom and top */
    {
      lpos = minx;
      rpos = maxx;
      ylabpos = 0.5 * (miny + maxy);
    }
  else if (as[1] != 'n')
    {
      switch (as[1])
	{
	case '-':
	  lpos = minx;
	  ylabpos = 0.5 * (miny + maxy);
	  break;
	case '+':
	  rpos = maxx;
	  ylabpos = 0.5 * (miny + maxy);
	  break;
	case '0':
	  lpos = 0.0;
	  if (as[0] == '+')
	    ylabpos = miny - 0.05 * (maxy - miny);
	  else
	    ylabpos = maxy + 0.05 * (maxy - miny);
	  break;
	default:
	  fprintf(dap_err, "(autoaxes) Bad axis specification: %s\n", axspec);
	  exit(1);
	}
    }
  for (w = 0, xlablines = 0; xlab[w]; w++)
    {
      if (xlab[w] == '\n')
	xlablines++;
    }
  captoff += 1.4 * xlablines * p->pict_fs / yscale;
  ticks(xticks, minxt, maxxt, nxdigs, xticklen / yscale,
	nxticks, xlabpos, xlab, xfunct);
  ticks(yticks, minyt, maxyt, nydigs, yticklen / xscale,
	nyticks, ylabpos, ylab, yfunct);
  pict_axes(pp, minx, maxx, xticks, nxticks,
	    miny, maxy, yticks, nyticks, as, bpos, lpos, tpos, rpos);
  pict_text(pp, caption, 0.5 * (minx + maxx), miny - captoff, 0.0, "ct ");
  if (autopos)
    {
      pict_scale(p, 0.5 * (minx + maxx), 0.5 * (miny + maxy), xscale, yscale);
      pict_translate(p, LEFT + 0.5 * (width - (minx + maxx)),
		     BOTTOM + 0.5 * (height - (miny + maxy)));
    }
  dap_free(xticks, "");
  dap_free(yticks, "");
  dap_free(word, "");
  return sqrt((width * width + height * height) / RADIUSFACTOR);
}

/* this stuff is just for reference */
#if 0
int pict_npts;				/* number of points in pict, if any */
char pict_type[5];			/* "LINE" = connected lines */
double pict_dash;			/* dash length for lines if > 0.0 */
double (*pict_pt)[2];			/* the points */
double pict_minx, pict_maxx;		/* bounds */
double pict_miny, pict_maxy;		/* bounds */
int pict_ntxt;				/* number of texts */
char **pict_txt;			/* text to display */ 
char *pict_font;			/* font for displayed text, if any */
double pict_fs;				/* font size */
double **pict_tpt;			/* location of text */
double *pict_tang;			/* angle for text */
char **pict_pos;			/* text position */
double pict_lw;				/* line width */
double pict_r;				/* radius for circles */
double pict_lgray;              	/* gray level for lines */ 
double pict_fgray;              	/* gray level for fill: if >= 0, fill then stroke */
struct _pict *pict_patt;        	/* pict to use for fill or patterned points */
struct _pict *pict_next;        	/* for linking in list */
#endif

#define MAXPICTSAVE 1000

void pict_save(pict *p, int npicts, char *dataset)
{
  pict *firstp;	/* start of pict list */
  int pn;		/* picture number */
  char strspec[15];
  int len;
  int maxlen;
  int pict_npts;				/* number of points in pict, if any */
  char pict_type[5];			/* "LINE" = connected lines */
  double pict_dash;			/* dash length for lines if > 0.0 */
  double pict_minx, pict_maxx;		/* bounds */
  double pict_miny, pict_maxy;		/* bounds */
  int pict_ntxt;				/* number of texts */
  char *pict_font;			/* font for displayed text, if any */
  double pict_fs;				/* font size */
  double pict_lw;				/* line width */
  double pict_r;				/* radius for circles */
  double pict_lgray;              	/* gray level for lines */ 
  double pict_fgray;              	/* gray level for fill: if >= 0, fill then stroke */
  int pict_next;				/* next pict in list */
  double pict_pt[2];			/* the points */
  int ptn;
  char *pict_txt;
  double pict_tpt[2];			/* location of text */
  double pict_tang;			/* angle for text */
  char pict_pos[4];			/* text position */
  char *outname;
  int pict_patt;				/* pattern number */

  firstp = p;

  for (p = firstp, maxlen = 0; p; )
    {
      len = strlen(p->pict_font);
      if (len > maxlen)
	maxlen = len;
      for (ptn = 0; ptn < p->pict_ntxt; ptn++)
	{
	  len = strlen(p->pict_txt[ptn]);
	  if (len > maxlen)
	    maxlen = len;
	}
      if (npicts)
	{
	  if (++p >= firstp + npicts)
	    break;
	}
      else
	p = p->pict_next;
    }
  if (maxlen > 9998)
    {
      fprintf(dap_err, "(pict_save) maximum string length too long: %d\n", maxlen);
      exit(1);
    }
  pict_font = dap_malloc(maxlen + 1, "");
  pict_txt = dap_malloc(maxlen + 1, "");

  /* first write out basic structure */
  infile(NULL, NULL);
  dap_vd("pict_npts 0", 0); dap_il("pict_npts", &pict_npts);
  dap_vd("pict_type 5", 0); dap_sl("pict_type", pict_type);
  dap_vd("pict_dash -1", 0); dap_dl("pict_dash", &pict_dash);
  dap_vd("pict_minx -1", 0); dap_dl("pict_minx", &pict_minx);
  dap_vd("pict_maxx -1", 0); dap_dl("pict_maxx", &pict_maxx);
  dap_vd("pict_miny -1", 0); dap_dl("pict_miny", &pict_miny);
  dap_vd("pict_maxy -1", 0); dap_dl("pict_maxy", &pict_maxy);
  dap_vd("pict_ntxt 0", 0); dap_il("pict_ntxt", &pict_ntxt);
  sprintf(strspec, "pict_font %d", maxlen);
  dap_vd(strspec, 0); dap_sl("pict_font", pict_font);
  dap_vd("pict_fs -1", 0); dap_dl("pict_fs", &pict_fs);
  dap_vd("pict_lw -1", 0); dap_dl("pict_lw", &pict_lw);
  dap_vd("pict_r -1", 0); dap_dl("pict_r", &pict_r);
  dap_vd("pict_lgray -1", 0); dap_dl("pict_lgray", &pict_lgray);
  dap_vd("pict_fgray -1", 0); dap_dl("pict_fgray", &pict_fgray);
  dap_vd("pict_next 0", 0); dap_il("pict_next", &pict_next);
  dap_vd("pict_patt 0", 0); dap_il("pict_patt", &pict_patt);
  outname = dap_malloc(strlen(dataset) + 9, ""); /* max 10000 picts */
  for (pn = 0, p = firstp; p; pn++)
    {
      if (pn < MAXPICTSAVE)
	{
	  sprintf(outname, "%s.pic%04d", dataset, pn);
	  outset(outname, "");
	  pict_npts = p->pict_npts;
	  strcpy(pict_type, p->pict_type);
	  pict_dash = p->pict_dash;
	  pict_minx = p->pict_minx;
	  pict_maxx = p->pict_maxx;
	  pict_miny = p->pict_miny;
	  pict_maxy = p->pict_maxy;
	  pict_ntxt = p->pict_ntxt;
	  strcpy(pict_font, p->pict_font);
	  pict_fs = p->pict_fs;
	  pict_lw = p->pict_lw;
	  pict_r = p->pict_r;
	  pict_lgray = p->pict_lgray;
	  pict_fgray = p->pict_fgray;
	  if (npicts)
	    {
	      if (pn < npicts - 1)
		{
		  if (p->pict_next)
		    pict_next = -(p->pict_next - firstp);
		  else
		    pict_next = -pn;
		}
	      else
		pict_next = 0;
	    }
	  else
	    {
	      if (p->pict_next)
		pict_next = pn + 1;
	      else
		pict_next = 0;
	    }
	  if (p->pict_patt)
	    pict_patt = 1;
	  else
	    pict_patt = 0;
	  output();
	}
      else
	{
	  fputs("(pict_save) too many picts.\n", dap_err);
	  exit(1);
	}
      if (npicts)
	{
	  if (++p >= firstp + npicts)
	    break;
	}
      else
	p = p->pict_next;
    }
  infile(NULL, NULL);
  dap_vd("pict_pt[0] -1 pict_pt[1] - 1", 0);
  dap_dl("pict_pt", pict_pt);
  for (pn = 0, p = firstp; p; pn++)
    {
      sprintf(outname, "%s.pts%04d", dataset, pn);
      outset(outname, "");
      for (ptn = 0; ptn < p->pict_npts; ptn++)
	{
	  pict_pt[0] = p->pict_pt[ptn][0];
	  pict_pt[1] = p->pict_pt[ptn][1];
	  output();
	}
      if (npicts)
	{
	  if (++p >= firstp + npicts)
	    break;
	}
      else
	p = p->pict_next;
    }
  infile(NULL, NULL);
  sprintf(strspec, "pict_txt %d", maxlen);
  dap_vd(strspec, 0); dap_sl("pict_txt", pict_txt);
  dap_vd("pict_tpt[0] -1 pict_tpt[1] -1", 0);
  dap_dl("pict_tpt", pict_tpt);
  dap_vd("pict_tang -1", 0); dap_dl("pict_tang", &pict_tang);
  dap_vd("pict_pos 3", 0); dap_sl("pict_pos", pict_pos);
  for (pn = 0, p = firstp; p; pn++)
    {
      sprintf(outname, "%s.txt%04d", dataset, pn);
      outset(outname, "");
      for (ptn = 0; ptn < p->pict_ntxt; ptn++)
	{
	  strcpy(pict_txt, p->pict_txt[ptn]);
	  pict_tpt[0] = p->pict_tpt[ptn][0];
	  pict_tpt[1] = p->pict_tpt[ptn][1];
	  pict_tang = p->pict_tang[ptn];
	  strcpy(pict_pos, p->pict_pos[ptn]);
	  output();
	}
      if (npicts)
	{
	  if (++p >= firstp + npicts)
	    break;
	}
      else
	p = p->pict_next;
    }
  for (pn = 0, p = firstp; p; pn++)
    {
      if (p->pict_patt)
	{
	  sprintf(outname, "%s.pat%04d", dataset, pn++);
	  pict_save(p->pict_patt, 0, outname);
	}
      if (npicts)
	{
	  if (++p >= firstp + npicts)
	    break;
	}
      else
	p = p->pict_next;
    }
  dap_free(outname, "");
  dap_free(pict_font, "");
  dap_free(pict_txt, "");
}

pict *pict_rest(char *dataset)
{
  int npict;	/* total number of picts, including patterns */
  pict *p;
  char *inname;
  int pn;
  int ptn;
  int pnext;
  int npicts;
  /* all these are indices to variables */
  int pict_npts;				/* number of points in pict, if any */
  int pict_type;				/* "LINE" = connected lines */
  int pict_dash;				/* dash length for lines if > 0.0 */
  int pict_minx, pict_maxx;		/* bounds */
  int pict_miny, pict_maxy;		/* bounds */
  int pict_ntxt;				/* number of texts */
  int pict_font;				/* font for displayed text, if any */
  int pict_fs;				/* font size */
  int pict_lw;				/* line width */
  int pict_r;				/* radius for circles */
  int pict_lgray;              		/* gray level for lines */ 
  int pict_fgray;              		/* gray level for fill: if >= 0, fill then stroke */
  int pict_pt;				/* the points */
  int pict_txt;
  int pict_tpt;				/* location of text */
  int pict_tang;				/* angle for text */
  int pict_pos;				/* text position */
  int pict_next;				/* link to next */
  int pict_patt;				/* pattern number */
  int dim;
  int npts;
  double *dblmem;
  char *charmem;

  inname = dap_malloc(strlen(dataset) + 9, "");
  for (pn = 0, npicts = 0; ; npicts++)
    {
      sprintf(inname, "%s.pic%04d", dataset, pn);
      inset(inname);
      step();
      if ((pict_next = dap_varnum("pict_next")) < 0)
	{
	  fprintf(dap_err, "(pict_rest) no pict_next in %s\n", inname);
	  exit(1);
	}
      pnext = dap_obs[0].do_int[pict_next];
      if (!pnext)
	break;
      if (pnext > 0)
	pn = pnext;
      else if (pnext < 0)
	++pn;
    }
  npicts++;
  p = (pict *) dap_malloc(sizeof(pict) * npicts, "");
  for (pn = 0; pn < npicts; pn++)
    {
      sprintf(inname, "%s.pic%04d", dataset, pn);
      inset(inname);
      step();
      if ((pict_npts = dap_varnum("pict_npts")) < 0)
	{
	  fputs("(pict_rest) missing pict_npts\n", dap_err);
	  exit(1);
	}
      p[pn].pict_npts = dap_obs[0].do_int[pict_npts];
      if ((pict_type = dap_varnum("pict_type")) < 0)
	{
	  fputs("(pict_rest) missing pict_type\n", dap_err);
	  exit(1);
	}
      strcpy(p[pn].pict_type, dap_obs[0].do_str[pict_type]);
      if ((pict_dash = dap_varnum("pict_dash")) < 0)
	{
	  fputs("(pict_rest) missing pict_dash\n", dap_err);
	  exit(1);
	}
      p[pn].pict_dash = dap_obs[0].do_dbl[pict_dash];
      if ((pict_minx = dap_varnum("pict_minx")) < 0)
	{
	  fputs("(pict_rest) missing pict_minx\n", dap_err);
	  exit(1);
	}
      p[pn].pict_minx = dap_obs[0].do_dbl[pict_minx];
      if ((pict_maxx = dap_varnum("pict_maxx")) < 0)
	{
	  fputs("(pict_rest) missing pict_maxx\n", dap_err);
	  exit(1);
	}
      p[pn].pict_maxx = dap_obs[0].do_dbl[pict_maxx];
      if ((pict_miny = dap_varnum("pict_miny")) < 0)
	{
	  fputs("(pict_rest) missing pict_miny\n", dap_err);
	  exit(1);
	}
      p[pn].pict_miny = dap_obs[0].do_dbl[pict_miny];
      if ((pict_maxy = dap_varnum("pict_maxy")) < 0)
	{
	  fputs("(pict_rest) missing pict_maxy\n", dap_err);
	  exit(1);
	}
      p[pn].pict_maxy = dap_obs[0].do_dbl[pict_maxy];
      if ((pict_ntxt = dap_varnum("pict_ntxt")) < 0)
	{
	  fputs("(pict_rest) missing pict_ntxt\n", dap_err);
	  exit(1);
	}
      p[pn].pict_ntxt = dap_obs[0].do_int[pict_ntxt];
      if ((pict_font = dap_varnum("pict_font")) < 0)
	{
	  fputs("(pict_rest) missing pict_font\n", dap_err);
	  exit(1);
	}
      p[pn].pict_font = dap_malloc(strlen(dap_obs[0].do_str[pict_font]) + 1, "");
      strcpy(p[pn].pict_font, dap_obs[0].do_str[pict_font]);
      if ((pict_fs = dap_varnum("pict_fs")) < 0)
	{
	  fputs("(pict_rest) missing pict_fs\n", dap_err);
	  exit(1);
	}
      p[pn].pict_fs = dap_obs[0].do_dbl[pict_fs];
      if ((pict_lw = dap_varnum("pict_lw")) < 0)
	{
	  fputs("(pict_rest) missing pict_lw\n", dap_err);
	  exit(1);
	}
      p[pn].pict_lw = dap_obs[0].do_dbl[pict_lw];
      if ((pict_r = dap_varnum("pict_r")) < 0)
	{
	  fputs("(pict_rest) missing pict_r\n", dap_err);
	  exit(1);
	}
      p[pn].pict_r = dap_obs[0].do_dbl[pict_r];
      if ((pict_lgray = dap_varnum("pict_lgray")) < 0)
	{
	  fputs("(pict_rest) missing pict_lgray\n", dap_err);
	  exit(1);
	}
      p[pn].pict_lgray = dap_obs[0].do_dbl[pict_lgray];
      if ((pict_fgray = dap_varnum("pict_fgray")) < 0)
	{
	  fputs("(pict_rest) missing pict_fgray\n", dap_err);
	  exit(1);
	}
      p[pn].pict_fgray = dap_obs[0].do_dbl[pict_fgray];
      if ((pict_next = dap_varnum("pict_next")) < 0)
	{
	  fputs("(pict_rest) missing pict_next\n", dap_err);
	  exit(1);
	}
      pnext = dap_obs[0].do_int[pict_next];
      if (pnext < 0)
	{
	  if (pnext == -pn)
	    p[pn].pict_next = NULL;
	  else
	    p[pn].pict_next = p - pnext;
	}
      else if (pnext)
	p[pn].pict_next = p + pn + 1;
      else
	p[pn].pict_next = NULL;
      if ((pict_patt = dap_varnum("pict_patt")) < 0)
	{
	  fputs("(pict_rest) missing pict_patt\n", dap_err);
	  exit(1);
	}
      if (dap_obs[0].do_int[pict_patt])
	{
	  sprintf(inname, "%s.pat%04d", dataset, pn);
	  p[pn].pict_patt = pict_rest(inname);
	}
      else
	p[pn].pict_patt = NULL;
    }
  for (pn = 0; pn < npicts; pn++)
    {
      sprintf(inname, "%s.pts%04d", dataset, pn);
      inset(inname);
      if ((pict_pt = dap_arrnum("pict_pt", &dim)) < 0)
	{
	  fputs("(pict_rest) missing pict_pt\n", dap_err);
	  exit(1);
	}
      if (dim != 2)
	{
	  fprintf(dap_err, "(pict_rest) bad dimension for pict_pt: %d\n", dim);
	  exit(1);
	}
      npts = p[pn].pict_npts;
      for (ptn = 0, p[pn].pict_npts = 0; ptn < npts; ptn++)
	{
	  step();
	  pict_point(p + pn, dap_obs[0].do_dbl[pict_pt],
		     dap_obs[0].do_dbl[pict_pt + 1]);
	}
    }
  for (pn = 0; pn < npicts; pn++)
    {
      sprintf(inname, "%s.txt%04d", dataset, pn);
      inset(inname);
      npts = p[pn].pict_ntxt;
      p[pn].pict_txt =
	(char **) dap_malloc(sizeof(char *) * dap_maxntxt, "dap_maxntxt");
      dblmem =
	(double *) dap_malloc(sizeof(double) * 2 * dap_maxntxt, "dap_maxntxt");
      p[pn].pict_tpt =
	(double **) dap_malloc(sizeof(double *) * dap_maxntxt, "dap_maxntxt");
      for (ptn = 0; ptn < dap_maxntxt; ptn++)
	p[pn].pict_tpt[ptn] = dblmem + 2 * ptn;
      p[pn].pict_tang =
	(double *) dap_malloc(sizeof(double) * dap_maxntxt, "dap_maxntxt");
      charmem = dap_malloc(3 * dap_maxntxt, "dap_maxntxt"); 
      p[pn].pict_pos =
	(char **) dap_malloc(sizeof(char *) * dap_maxntxt, "dap_maxntxt");
      for (ptn = 0; ptn < dap_maxntxt; ptn++)
	p[pn].pict_pos[ptn] = charmem + 3 * ptn;
      if ((pict_txt = dap_varnum("pict_txt")) < 0)
	{
	  fputs("(pict_rest) missing pict_txt\n", dap_err);
	  exit(1);
	}
      if ((pict_tpt = dap_arrnum("pict_tpt", &dim)) < 0)
	{
	  fputs("(pict_rest) missing pict_tpt\n", dap_err);
	  exit(1);
	}
      if (dim != 2)
	{
	  fprintf(dap_err, "(pict_rest) bad dimension for pict_tpt: %d\n", dim);
	  exit(1);
	}
      if ((pict_tang = dap_varnum("pict_tang")) < 0)
	{
	  fputs("(pict_rest) missing pict_tang\n", dap_err);
	  exit(1);
	}
      if ((pict_pos = dap_varnum("pict_pos")) < 0)
	{
	  fputs("(pict_rest) missing pict_pos\n", dap_err);
	  exit(1);
	}
      for (ptn = 0, p[pn].pict_ntxt = 0; ptn < npts; ptn++)
	{
	  step();
	  pict_text(p + pn, dap_obs[0].do_str[pict_txt],
		    dap_obs[0].do_dbl[pict_tpt], dap_obs[0].do_dbl[pict_tpt + 1],
		    dap_obs[0].do_dbl[pict_tang], dap_obs[0].do_str[pict_pos]);
	}
    }
  dap_free(inname, "");
  return p;
}
