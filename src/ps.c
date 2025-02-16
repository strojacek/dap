/* ps.c -- PostScript(tm) generator */

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
#include <string.h>
#include <time.h>
#include <math.h>
#include "dap_make.h"
#include "externs.h"
#include "ps.h"

#define SCRIPTF 0.7	/* fraction to reduce font-size for super/sub-scripts */
#define SCRIPTH 0.4	/* fraction of font-size to raise/lower super/sub-scripts */
#define TBOXF 1.3	/* text-box factor for blanking out space around text */

#define TWOOVERSQRT3 1.15470053837925153
#define ONEOVERSQRT3 0.57735026918962576

extern FILE *dap_err;

static int orient;
static int bboxx0, bboxy0, bboxx1, bboxy1;
static FILE *pict_out = NULL;
static int pageno;

static double **ptbuf;
static int ptnext = 0;
static char *charbuf;
static int charnext = 0;

extern char *dap_psname;

void dap_initpict()
{
  double *ptmem;
  int p;

  ptmem = (double *) dap_malloc(sizeof(double) * 2 * dap_maxpts, "dap_maxpts");
  ptbuf = (double **) dap_malloc(sizeof(double *) * dap_maxpts, "dap_maxpts");
  for (p = 0; p < dap_maxpts; p++)
    ptbuf[p] = ptmem + p * 2;
  charbuf = dap_malloc(dap_maxchar + 1, "dap_maxchar");
}

static double (*pict_newpoint(double x, double y))[2]
{
  double (*pt)[2];

  if (ptnext < dap_maxpts)
    {
      ptbuf[ptnext][0] = x;
      ptbuf[ptnext][1] = y;
      pt = (double (*)[2]) ptbuf[ptnext];
      ptnext++;
    }
  else
    {
      fputs("(pict_newpoint) Too many points.\n", dap_err);
      exit(1);
    }
  return pt;
}

char *pict_newstr(char *str)
{
  int s;
  char *s0;

  s0 = charbuf + charnext;
  if (str)
    {
      for (s = 0; str[s]; s++)
	{
	  if (charnext < dap_maxchar)
	    charbuf[charnext++] = str[s];
	  else
	    {
	      fputs("(pict_newstr) Too many characters.\n", dap_err);
	      exit(1);
	    }
	}
    }
  charbuf[charnext++] = '\0';
  return s0;
}

void pict_init(int or, int bbx0, int bby0, int bbx1, int bby1, int npages)
{
  time_t t;

  if (!pict_out)
    {
      if (!(pict_out = fopen(dap_psname, "w")))
	{
	  fprintf(dap_err, "(pict_init) Can't create .ps file: %s\n", dap_psname);
	  exit(1);
	}
    }
  orient = or;
  bboxx0 = bbx0;
  bboxy0 = bby0;
  bboxx1 = bbx1;
  bboxy1 = bby1;
  fputs("%!PS-Adobe-2.0\n", pict_out);
  fprintf(pict_out, "%%Title: %s\n", dap_psname);
  fputs("%%Creator: ps.c\n", pict_out);
  fputs("%%CreationDate: ", pict_out);
  time(&t);
  fputs(ctime(&t), pict_out);
  fputs("%%For: bassein@localhost.localdomain (,,,,)\n", pict_out);
  fprintf(pict_out, "%s %s\n", "%%Orientation:", ((orient == 'p') ? "Portrait" : "Landscape"));
  fprintf(pict_out, "%s %d %d %d %d\n", "%%BoundingBox:", bboxx0, bboxy0, bboxx1, bboxy1);
  fprintf(pict_out, "%s %d\n", "%%Pages:", npages);
  fputs("%%BeginSetup\n", pict_out);
  fputs("%%IncludeFeature: *PageSize Letter\n", pict_out);
  fputs("%%EndSetup\n", pict_out);
  fputs("%%Magnification: 1.0000\n", pict_out);
  fputs("%%EndComments\n", pict_out);
  fputs("/cp {closepath} bind def /gr {grestore} bind def /gs {gsave} bind def\n", pict_out);
  fputs("/sa {save} bind def /rs {restore} bind def /l {lineto} bind def\n", pict_out);
  fputs("/rl {rlineto} bind def /ar {arc} bind def\n", pict_out);
  fputs("/m {moveto} bind def /rm {rmoveto} bind def /n {newpath} bind def\n", pict_out);
  fputs("/f {fill} bind def /s {stroke} bind def /sh {show} bind def\n", pict_out);
  fputs("/slw {setlinewidth} bind def /sg {setgray} bind def /rot {rotate} bind def\n", pict_out);
  fputs("/sc {scale} bind def /sd {setdash} bind def /ff {findfont} bind def\n", pict_out);
  fputs("/sf {setfont} bind def /scf {scalefont} bind def /sw {stringwidth} bind def\n", pict_out);
  fputs("/tr {translate} bind def\n", pict_out);
  fputs("%%EndProlog\n", pict_out);
  pageno = 0;
}

void pict_port(int npages)
{
  pict_init('p', 0, 0, 612, 792, npages);
}

void pict_land(int npages)
{
  pict_init('l', 0, 0, 612, 792, npages);
}

void pict_end()
{
  fputs("gr\n", pict_out);
  fputs("showpage\n", pict_out);
  fputs("%%Trailer\n", pict_out);
  fflush(pict_out);
}

void pict_page()
{
  if (pageno)
    {
      fputs("gr\n", pict_out);
      fputs("showpage\n", pict_out);
    }
  pageno++;
  fprintf(pict_out, "%%%%Page: %d %d\n", pageno, pageno);
  fputs("gs\n", pict_out);
  if (orient == 'l')
    fprintf(pict_out, "%d %d tr 90 rot %d %d tr\n", bboxy0 + bboxx1, bboxy0, -bboxx0, -bboxy0);
}

void pict_clearpict(pict *p)
{
  dap_free(p->pict_txt, "");
  p->pict_txt = NULL;
  dap_free(p->pict_font, "");
  p->pict_font = NULL;
  dap_free(p->pict_tpt[0], "");
  dap_free(p->pict_tang, "");
  p->pict_tang = NULL;
  dap_free(p->pict_pos[0], "");
}

void pict_initpict(pict *prev, pict *p)
{
  double *dblmem;
  char *charmem;
  int t;

  p->pict_npts = 0;
  p->pict_ntxt = 0;
  p->pict_txt = (char **) dap_malloc(sizeof(char *) * dap_maxntxt, "dap_maxntxt");
  strcpy(p->pict_type, "LINE");
  p->pict_dash = 0.0;
  p->pict_font = dap_malloc(dap_maxfont + 1, "dap_maxfont");
  strcpy(p->pict_font, "Helvetica-Bold");
  dblmem = (double *) dap_malloc(sizeof(double) * 2 * dap_maxntxt, "dap_maxntxt");
  p->pict_tpt = (double **) dap_malloc(sizeof(double *) * dap_maxntxt, "dap_maxntxt");
  for (t = 0; t < dap_maxntxt; t++)
    p->pict_tpt[t] = dblmem + 2 * t;
  p->pict_tang = (double *) dap_malloc(sizeof(double) * dap_maxntxt, "dap_maxntxt");
  charmem = dap_malloc(3 * dap_maxntxt, "dap_maxntxt");
  p->pict_pos = (char **) dap_malloc(sizeof(char *) * dap_maxntxt, "dap_maxntxt");
  for (t = 0; t < dap_maxntxt; t++)
    p->pict_pos[t] = charmem + 3 * t;
  p->pict_fs = 12.0;
  p->pict_lw = 0.4;
  p->pict_lgray = 0.0;
  p->pict_fgray = -1.0;
  p->pict_patt = NULL;
  p->pict_next = NULL;
  if (prev)
    prev->pict_next = p;
}

void pict_text(pict *p, char *str, double x, double y, double tang, char pos[])
{
  if (!str)
    return;
  if (p->pict_ntxt < dap_maxntxt - 1)
    {
      p->pict_txt[p->pict_ntxt] = pict_newstr(str);
      p->pict_tpt[p->pict_ntxt][0] = x;
      p->pict_tpt[p->pict_ntxt][1] = y;
      if (strlen(pos) <= 3)
	{
	  strcpy(p->pict_pos[p->pict_ntxt], pos);
	  if ((pos[0] != 'l' && pos[0] != 'c' && pos[0] != 'r') ||
	      (pos[1] != 't' && pos[1] != 'm' && pos[1] != 'b'))
	    {
	      fprintf(dap_err, "(pict_text) Invalid position string: %s\n", pos);
	      exit(1);
	    }
	}
      else
	{
	  fprintf(dap_err, "(pict_text) Position string too long: %s\n", pos);
	  exit(1);
	}
      p->pict_tang[p->pict_ntxt] = tang;
      p->pict_ntxt++;
    }
  else
    {
      fprintf(dap_err, "(pict_text) Too many texts in pict\n");
      exit(1);
    }
}

void pict_circle(pict *p, double cx, double cy, double r)
{
  p->pict_npts = 1;
  strcpy(p->pict_type, "CIRC");
  p->pict_pt = pict_newpoint(cx, cy);
  p->pict_r = r;
}

void pict_rectangle(pict *p, double llx, double lly, double sx, double sy)
{
  strcpy(p->pict_type, "LINE");
  pict_point(p, llx, lly);
  pict_point(p, llx + sx, lly);
  pict_point(p, llx + sx, lly + sy);
  pict_point(p, llx, lly + sy);
  pict_point(p, llx, lly);
}

void pict_hrect(pict *p, double spacing, double x0, double y0, double xside, double yside)
{
  int vlines, hlines;
  int linen;
  int ptn;
  double xl, xr, yb, yt;
  int even;

  vlines = (int) floor(yside / spacing);
  hlines = (int) floor(xside / spacing);
  pict_point(p, x0, y0 + yside);
  pict_point(p, x0, y0);
  pict_point(p, x0 + xside, y0);
  pict_point(p, x0 + xside, y0 + yside);
  pict_point(p, x0, y0 + yside);
  for (linen = -vlines, ptn = 0, even = 0; linen <= hlines;
       linen++, ptn += 2, even = 1 - even)
    {
      xl = x0 + ((double) linen) * spacing;
      yb = y0;
      xr = xl + yside;
      yt = y0 + yside;
      if (xl < x0)
	{
	  yb += x0 - xl;
	  xl = x0;
	}
      if (xr > x0 + xside)
	{
	  if (!even && xr < x0 + xside + spacing)
	    pict_point(p, x0 + xside, y0 + yside);
	  yt -= xr - x0 - xside;
	  xr = x0 + xside;
	}
      if (even)
	{
	  pict_point(p, xl, yb);
	  pict_point(p, xr, yt);
	}
      else
	{
	  pict_point(p, xr, yt);
	  pict_point(p, xl, yb);
	}
    }
}

void pict_bhrect(pict *p, double spacing, double x0, double y0, double xside, double yside)
{
  int vlines, hlines;
  int linen;
  int ptn;
  double xl, xr, yb, yt;
  int even;

  vlines = (int) floor(yside / spacing);
  hlines = (int) floor(xside / spacing);
  pict_point(p, x0, y0);
  pict_point(p, x0 + xside, y0);
  pict_point(p, x0 + xside, y0 + yside);
  pict_point(p, x0, y0 + yside);
  pict_point(p, x0, y0);
  for (linen = -vlines, ptn = 0, even = 0; linen <= hlines;
       linen++, ptn += 2, even = 1 - even)
    {
      xl = x0 + ((double) linen) * spacing;
      yt = y0 + yside;
      xr = xl + yside;
      yb = y0;
      if (xl < x0)
	{
	  yt -= x0 - xl;
	  xl = x0;
	}
      if (xr > x0 + xside)
	{
	  if (!even && xr < x0 + xside + spacing)
	    pict_point(p, x0 + xside, y0);
	  yb += xr - x0 - xside;
	  xr = x0 + xside;
	}
      if (even)
	{
	  pict_point(p, xl, yt);
	  pict_point(p, xr, yb);
	}
      else
	{
	  pict_point(p, xr, yb);
	  pict_point(p, xl, yt);
	}
    }
}

void pict_point(pict *p, double x, double y)
{
  if (!p->pict_npts)
    {
      p->pict_minx = x;
      p->pict_maxx = x;
      p->pict_miny = y;
      p->pict_maxy = y;
      p->pict_pt = pict_newpoint(x, y);
    }
  else
    {
      if (x < p->pict_minx)
	p->pict_minx = x;
      if (x > p->pict_maxx)
	p->pict_maxx = x;
      if (y < p->pict_miny)
	p->pict_miny = y;
      if (y > p->pict_maxy)
	p->pict_maxy = y;
      pict_newpoint(x, y);
    }
  p->pict_npts++;
}

void pict_line(pict *p, double x0, double y0, double x1, double y1)
{
  pict_point(p, x0, y0);
  pict_point(p, x1, y1);
}

void pict_curve(pict *p, double (*xf)(double t), double (*yf)(double t),
		double t0, double t1, int nsteps)
{
  int step;
  double h;
  double t;

  h = (t1 - t0) / ((double) nsteps);
  for (step = 0; step <= nsteps; step++)
    {
      t = t0 + ((double) step) * h;
      if (xf)
	pict_point(p, (*xf)(t), (*yf)(t));
      else
	pict_point(p, t, (*yf)(t));
    }
}

void pict_scale(pict *p, double cx, double cy, double sx, double sy)
{
  int ptn;
  int t;

  while (p)
    {
      if (sx >= sy)
	p->pict_r *= sy;
      else
	p->pict_r *= sx;
      for (t = 0; t < p->pict_ntxt; t++)
	{
	  p->pict_tpt[t][0] = cx + sx * (p->pict_tpt[t][0] - cx);
	  p->pict_tpt[t][1] = cy + sy * (p->pict_tpt[t][1] - cy);
	}
      for (ptn = 0; ptn < p->pict_npts; ptn++)
	{
	  p->pict_pt[ptn][0] = cx + sx * (p->pict_pt[ptn][0] - cx);
	  p->pict_pt[ptn][1] = cy + sy * (p->pict_pt[ptn][1] - cy);
	}
      p->pict_minx = cx + sx * (p->pict_minx - cx);
      p->pict_maxx = cx + sx * (p->pict_maxx - cx);
      p->pict_miny = cx + sx * (p->pict_miny - cx);
      p->pict_maxy = cx + sx * (p->pict_maxy - cx);
      p = p->pict_next;
    }
}

void pict_rotate(pict *p, double cx, double cy, double deg, int texttoo)
{
  double c, s;
  int ptn;
  double tmpx, tmpy;
  double angle;
  int t;

  angle = 3.14159265358979323846 / 180.0 * deg;
  c = cos(angle);
  s = sin(angle);
  while (p)
    {
      for (t = 0; t < p->pict_ntxt; t++)
	{
	  tmpx = p->pict_tpt[t][0] - cx;
	  tmpy = p->pict_tpt[t][1] - cy;
	  p->pict_tpt[t][0] = cx + c * tmpx - s * tmpy;
	  p->pict_tpt[t][1] = cy + s * tmpx + c * tmpy;
	  p->pict_tang[t] += deg;
	}
      for (ptn = 0; ptn < p->pict_npts; ptn++)
	{
	  tmpx = p->pict_pt[ptn][0] - cx;
	  tmpy = p->pict_pt[ptn][1] - cy;
	  p->pict_pt[ptn][0] = cx + c * tmpx - s * tmpy;
	  p->pict_pt[ptn][1] = cy + s * tmpx + c * tmpy;
	  if (!ptn)
	    {
	      p->pict_minx = p->pict_pt[ptn][0];
	      p->pict_maxx = p->pict_pt[ptn][0];
	      p->pict_miny = p->pict_pt[ptn][1];
	      p->pict_maxy = p->pict_pt[ptn][1];
	    }
	  else
	    {
	      if (p->pict_pt[ptn][0] < p->pict_minx)
		p->pict_minx = p->pict_pt[ptn][0];
	      if (p->pict_pt[ptn][0] > p->pict_maxx)
		p->pict_maxx = p->pict_pt[ptn][0];
	      if (p->pict_pt[ptn][1] < p->pict_miny)
		p->pict_miny = p->pict_pt[ptn][1];
	      if (p->pict_pt[ptn][1] > p->pict_maxy)
		p->pict_maxy = p->pict_pt[ptn][1];
	    }
	}
      p = p->pict_next;
    }
}

void pict_translate(pict *p, double tx, double ty)
{
  int ptn;
  int t;

  while (p)
    {
      for (t = 0; t < p->pict_ntxt; t++)
	{
	  p->pict_tpt[t][0] += tx;
	  p->pict_tpt[t][1] += ty;
	}
      for (ptn = 0; ptn < p->pict_npts; ptn++)
	{
	  p->pict_pt[ptn][0] += tx;
	  p->pict_pt[ptn][1] += ty;
	}
      p->pict_minx += tx;
      p->pict_maxx += tx;
      p->pict_miny += ty;
      p->pict_maxy += ty;
      p = p->pict_next;
    }
}
 
/* Place graphical command in graphical output file */
static void putmode(int mode)
{
  switch (mode)
    {
    case 's':	/* s = stroke */
      fputs("s\n", pict_out);
      break;
    case 'f':	/* f = fill */
      fputs("f\n", pict_out);
      break;
    case 'p':	/* p = clip */
      fputs("clip\n", pict_out);
      break;
    }
}

#define LINE 0
#define SEGM 1
#define IBEA 2
#define CIRC 4
#define SQUA 5
#define TRIA 6
#define UTRI 7
#define DIAM 8
#define PATT 9

/* Convert 4-character text string to numerical code */
static int picttype(char type[])
{
  if (!strcmp(type, "LINE")) return LINE;
  else if (!strcmp(type, "SEGM")) return SEGM;
  else if (!strcmp(type, "IBEA")) return IBEA;
  else if (!strcmp(type, "CIRC")) return CIRC;
  else if (!strcmp(type, "SQUA")) return SQUA;
  else if (!strcmp(type, "TRIA")) return TRIA;
  else if (!strcmp(type, "UTRI")) return UTRI;
  else if (!strcmp(type, "DIAM")) return DIAM;
  else if (!strcmp(type, "PATT")) return PATT;
  else
    {
      fprintf(dap_err, "bad pict type: %s\n", type);
      exit(1);
    }
}

/* Place one graphical element in graphical output file */
static void show0(pict *p, int mode)
{
  int ptn;	/* index to point array */

  switch (picttype(p->pict_type))
    {
    case SEGM:	/* show a segment, not connected to other lines */
      if (p->pict_npts % 2)	/* need pairs of points */
	{
	  fputs("(show0) Requested SEGM with odd number of points.\n", dap_err);
	  exit(1);
	}
      for (ptn = 0; ptn < p->pict_npts; ptn += 2)
	{	/* place lines in graphical output file */
	  fprintf(pict_out, "n %.6f %.6f m %.6f %.6f l\n",
		  p->pict_pt[ptn][0], p->pict_pt[ptn][1],
		  p->pict_pt[ptn + 1][0], p->pict_pt[ptn + 1][1]);
	  putmode(mode);	/* and stroke or fill */
	}
      break;
    case IBEA:	/* show I-beam, not connect to other lines */
      if (p->pict_npts % 2)	/* need pairs of points */
	{
	  fputs("(show0) Requested IBEA with odd number of points.\n", dap_err);
	  exit(1);
	}
      for (ptn = 0; ptn < p->pict_npts; ptn += 2)
	{
	  if (p->pict_pt[ptn][0] == p->pict_pt[ptn + 1][0])
	    {	/* if x-coordinates are equal */
	      /* first cross piece of I-beam */
	      fprintf(pict_out, "n %.6f %.6f m %.6f %.6f l\n",
		      p->pict_pt[ptn][0] - p->pict_r, p->pict_pt[ptn][1],
		      p->pict_pt[ptn][0] + p->pict_r, p->pict_pt[ptn][1]);
	      putmode(mode);
	      /* bar */
	      fprintf(pict_out, "n %.6f %.6f m %.6f %.6f l\n",
		      p->pict_pt[ptn][0], p->pict_pt[ptn][1],
		      p->pict_pt[ptn + 1][0], p->pict_pt[ptn + 1][1]);
	      putmode(mode);
	      /* other cross piece of I-beam */
	      fprintf(pict_out, "n %.6f %.6f m %.6f %.6f l\n",
		      p->pict_pt[ptn + 1][0] - p->pict_r, p->pict_pt[ptn + 1][1],
		      p->pict_pt[ptn + 1][0] + p->pict_r, p->pict_pt[ptn + 1][1]);
	      putmode(mode);
	    }
	  else if (p->pict_pt[ptn][1] == p->pict_pt[ptn + 1][1])
	    {	/* y-coordinate equal */
	      /* first cross piece of I-beam */
	      fprintf(pict_out, "n %.6f %.6f m %.6f %.6f l\n",
		      p->pict_pt[ptn][0], p->pict_pt[ptn][1] - p->pict_r,
		      p->pict_pt[ptn][0], p->pict_pt[ptn][1] + p->pict_r);
	      putmode(mode);
	      /* bar */
	      fprintf(pict_out, "n %.6f %.6f m %.6f %.6f l\n",
		      p->pict_pt[ptn][0], p->pict_pt[ptn][1],
		      p->pict_pt[ptn + 1][0], p->pict_pt[ptn + 1][1]);
	      putmode(mode);
	      /* other cross piece of I-beam */
	      fprintf(pict_out, "n %.6f %.6f m %.6f %.6f l\n",
		      p->pict_pt[ptn + 1][0], p->pict_pt[ptn + 1][1] - p->pict_r,
		      p->pict_pt[ptn + 1][0], p->pict_pt[ptn + 1][1] + p->pict_r);
	      putmode(mode);
	    }
	  else
	    {
	      fprintf(dap_err,
		      "(show0) IBEA requested but neither x nor y coordinates match: (%g, %g), (%g, %g)\n",
		      p->pict_pt[ptn][0], p->pict_pt[ptn][1],
		      p->pict_pt[ptn + 1][0], p->pict_pt[ptn + 1][1]);
	      exit(1);
	    }
	}
      break;
    case UTRI:	/* upside-down triangle */
      for (ptn = 0; ptn < p->pict_npts; ptn++)
	{	/* run around the triangle */
	  fprintf(pict_out,
		  "n %.6f %.6f m %.6f %.6f l %.6f %.6f l %.6f %.6f l\n",
		  p->pict_pt[ptn][0] - p->pict_r,
		  p->pict_pt[ptn][1] + ONEOVERSQRT3 * p->pict_r,
		  p->pict_pt[ptn][0] + p->pict_r,
		  p->pict_pt[ptn][1] + ONEOVERSQRT3 * p->pict_r,
		  p->pict_pt[ptn][0],
		  p->pict_pt[ptn][1] - TWOOVERSQRT3 * p->pict_r,
		  p->pict_pt[ptn][0] - p->pict_r,
		  p->pict_pt[ptn][1] + ONEOVERSQRT3 * p->pict_r);
	  putmode(mode);
	}
      break;
    case DIAM:	/* diamond */
      for (ptn = 0; ptn < p->pict_npts; ptn++)
	{	/* run around the diamond */
	  fprintf(pict_out,
		  "n %.6f %.6f m %.6f %.6f l %.6f %.6f l %.6f %.6f l %.6f %.6f l\n",
		  p->pict_pt[ptn][0], p->pict_pt[ptn][1] - p->pict_r,
		  p->pict_pt[ptn][0] + p->pict_r, p->pict_pt[ptn][1],
		  p->pict_pt[ptn][0], p->pict_pt[ptn][1] + p->pict_r,
		  p->pict_pt[ptn][0] - p->pict_r, p->pict_pt[ptn][1],
		  p->pict_pt[ptn][0], p->pict_pt[ptn][1] - p->pict_r);
	  putmode(mode);
	}
      break;
    case LINE:	/* connected lines */
      fprintf(pict_out, "n %.6f %.6f m\n", p->pict_pt[0][0], p->pict_pt[0][1]);
      for (ptn = 1; ptn < p->pict_npts; ptn++)
	fprintf(pict_out, "%.6f %.6f l\n", p->pict_pt[ptn][0], p->pict_pt[ptn][1]);
      putmode(mode);
      break;
    case CIRC:	/* circle */
      for (ptn = 0; ptn < p->pict_npts; ptn++)
	{
	  fprintf(pict_out, "n %.6f %.6f %.3f 0 360 ar\n",
		  p->pict_pt[ptn][0], p->pict_pt[ptn][1], p->pict_r);
	  putmode(mode);
	}
      break;
    case SQUA:	/* square */
      for (ptn = 0; ptn < p->pict_npts; ptn++)
	{	/* run around the square */
	  fprintf(pict_out,
		  "n %.6f %.6f m %.6f %.6f l %.6f %.6f l %.6f %.6f l %.6f %.6f l\n",
		  p->pict_pt[ptn][0] - p->pict_r, p->pict_pt[ptn][1] - p->pict_r,
		  p->pict_pt[ptn][0] + p->pict_r, p->pict_pt[ptn][1] - p->pict_r,
		  p->pict_pt[ptn][0] + p->pict_r, p->pict_pt[ptn][1] + p->pict_r,
		  p->pict_pt[ptn][0] - p->pict_r, p->pict_pt[ptn][1] + p->pict_r,
		  p->pict_pt[ptn][0] - p->pict_r, p->pict_pt[ptn][1] - p->pict_r);
	  putmode(mode);
	}
      break;
    case TRIA:	/* triangle */
      for (ptn = 0; ptn < p->pict_npts; ptn++)
	{	/* run around the triangle */
	  fprintf(pict_out,
		  "n %.6f %.6f m %.6f %.6f l %.6f %.6f l %.6f %.6f l\n",
		  p->pict_pt[ptn][0] - p->pict_r,
		  p->pict_pt[ptn][1] - ONEOVERSQRT3 * p->pict_r,
		  p->pict_pt[ptn][0] + p->pict_r,
		  p->pict_pt[ptn][1] - ONEOVERSQRT3 * p->pict_r,
		  p->pict_pt[ptn][0],
		  p->pict_pt[ptn][1] + TWOOVERSQRT3 * p->pict_r,
		  p->pict_pt[ptn][0] - p->pict_r,
		  p->pict_pt[ptn][1] - ONEOVERSQRT3 * p->pict_r);
	  putmode(mode);
	}
      break;
    case PATT:	/* display pict linked to this pict */
      for (ptn = 0; ptn < p->pict_npts; ptn++)
	{	/* first do a gsave */
	  /* need to translate linked pict to this point */
	  fprintf(pict_out,
		  "gs n %.6f %.6f tr\n", p->pict_pt[ptn][0], p->pict_pt[ptn][1]);
	  pict_show(p->pict_patt);	/* then display */
	  fputs("gr\n", pict_out);	/* end with grestore */
	}
      break;
    }
}

/* Place one picture in linked list into graphics file */
static pict *show1(pict *p)
{
  static int show1init = 0;	/* initial bookkeeping done? */
  int t;		/* index to text strings */
  double yoff;	/* offset for positioning text relative to point */
  int tc;		/* index to one text string */
  double nfull;	/* number of full-sized characters */
  double nscript;	/* number of super/sub-script-sized characters */
  double nchange;	/* number of super/sub-script sub-strings */
  int inscript;	/* stepping though text: in super/sub-script? */
  double lfact;	/* length factor: true length over character-counting length */
  int i;		/* index to baret */
  static char *tpart;	/* part of text between super/sub-script changes */
  static char *baret;	/* bare text, no super/sub-script escapes */
  double hside;	/* width of box for blanking around text: less than perfect */
  double efffs;	/* effective font-size for blanking to account for super/sub-scripts */
  int nlines;	/* number of lines specified by text string */
  int toff;	/* offset into text string */
  double linespace;	/* factor to multiply font size by to get line spacing */

  linespace = 1.4;
  yoff = 0.0;		/* default is lower left of first character on the point */
  if (!show1init)		/* if initial bookkeeping not done yet */
    {
      show1init = 1;
      tpart = dap_malloc(dap_maxtxt + 1, "dap_maxtxt");
      baret = dap_malloc(dap_maxtxt + 1, "dap_maxtxt");
    }
  if (p->pict_npts > 0)	/* if there are points, not just text, to display */
    {
      if (p->pict_fgray >= 0.0)
	{	/* non-negative value requested by caller */
	  fprintf(pict_out, "%.2f sg\n", p->pict_fgray);
	  show0(p, 'f');	/* stroke with fill */
	}
      if (p->pict_lw >= 0.0)
	{	/* non-negative value requested by caller */
	  fprintf(pict_out, "%.2f slw %.2f sg\n", p->pict_lw, p->pict_lgray);
	  if (p->pict_dash > 0.0)	/* positive value requested by caller */
	    fprintf(pict_out, "[%.3f] 0 sd\n", p->pict_dash);
	  show0(p, 's');	/* stroke, no fill */
	  if (p->pict_dash > 0.0)	/* reset dashing to null */
	    fputs("[] 0 sd\n", pict_out);
	}
      if (p->pict_patt && strcmp(p->pict_type, "PATT"))
	show0(p, 'p');
    }
  /* now on to text */
  for (t = 0; t < p->pict_ntxt; t++)	/* show one string and follow link */
    {
      /* tc = 0: start at beginning of string
       * i = 0: index to baret, start at beginning
       * inscript = 0: not in super/sub-scripts at start
       * nfull = 0.0: number of full-sized characters
       * nscript = 0.0: number of super/sub-script-sized characters
       * nchange = 0.0: number of super/sub-script sub-strings
       */
      /* first get number of lines requested */
      for (nlines = 1, tc = 0; p->pict_txt[t][tc]; tc++)
	{
	  if (p->pict_txt[t][tc] == '\n')
	    nlines++;
	}
      switch (p->pict_pos[t][1])	/* position text relative to point */
	{
	case 't':	/* point is at top of text */
	  yoff = -p->pict_fs;
	  break;
	case 'm':	/* point is at middle (vertical) of text */
	  yoff = -0.2 * p->pict_fs + 0.5 * linespace * p->pict_fs * (double) (nlines - 1);
	  break;
	case 'b':	/* point is at bottom of text */
	  yoff = linespace * p->pict_fs * (double) (nlines - 1);
	  break;
	}
      for (toff = 0; p->pict_txt[t][toff]; )
	{
	  for (tc = toff, i = 0, inscript = 0, nfull = 0.0, nscript = 0.0, nchange = 0.0;
	       p->pict_txt[t][tc] && p->pict_txt[t][tc] != '\n'; tc++)
	    {	/* step though one text string */
	      if (p->pict_txt[t][tc] == '^' || p->pict_txt[t][tc] == '|')
		{	/* entering or leaving super/sub-script portion */
		  inscript = !inscript;
		  nchange += 1.0;	/* record number of changes */
		}
	      else		/* not entering or leaving */
		{
		  if (inscript)	/* count super/sub-scripted character */
		    nscript += 1.0;
		  else		/* count full-sized character */
		    nfull += 1.0;
		  /* copy bare text, no super/sub-script marks, into baret */
		  /* except if ( ), need to escape! */
		  if (i < dap_maxtxt)
		    {
		      if (p->pict_txt[t][tc] == '(' || p->pict_txt[t][tc] == ')')
			{ /* parens need escape */
			  baret[i++] = '\\';
			  if (i == dap_maxtxt)
			    {
			      fprintf(dap_err, "(show1) Text too long: %s\n",
				      p->pict_txt[t]);
			      exit(1);
			    }
			}
		      baret[i++] = p->pict_txt[t][tc];
		    }
		  else
		    {
		      fprintf(dap_err, "(show1) Text too long: %s\n",
			      p->pict_txt[t]);
		      exit(1);
		    }
		}
	    }
	  baret[i] = '\0';
	  if (!i)		/* if nothing to show for all this */
	    continue;	/* just skip it */
	  /* length factor: true length as fraction of character count */
	  lfact = (nfull + SCRIPTF * nscript) / (nfull + nscript + nchange);
	  if (p->pict_pos[t][2] == ' ')	/* trailing space for blanking around text */
	    {
	      efffs = p->pict_fs;
	      if (nchange > 0.0)
		efffs *= 1.4;
	      /* This computation assumes with of character is 0.9 * height.
	       * That is simply untrue, but to do any better would require
	       * this program to read font tables... some other lifetime, folks.
	       */
	      hside = ((double) strlen(baret)) * lfact * p->pict_fs * 0.9;
	      /* gsave so we can translate to save trouble */
	      fputs("gs n 1 sg\n", pict_out);
	      fprintf(pict_out, "%.6f %.6f tr %.3f rot\n",
		      p->pict_tpt[t][0], p->pict_tpt[t][1], p->pict_tang[t]);
	      switch (p->pict_pos[t][0])
		{
		case 'l':	/* string begins at point */
		  fprintf(pict_out, "%.3f %.3f tr\n",
			  -(TBOXF - 1.0) * p->pict_fs, yoff - 0.5 * efffs);
		  break;
		case 'c':	/* center of string at point */
		  fprintf(pict_out, "%.3f %.3f tr\n",
			  -0.5 * hside, yoff - 0.5 * efffs);
		  break;
		case 'r':	/* string ends at point */
		  fprintf(pict_out, "%.3f %.3f tr\n",
			  -hside + (TBOXF - 1.0) * p->pict_fs, yoff - 0.5 * efffs);
		  break;
		}
	      fprintf(pict_out, " 0 0 m %.3f 0 rl 0 %.3f rl %.3f 0 rl cp f\n",
		      hside, TBOXF * efffs, -hside);
	      fputs("gr\n", pict_out);	/* grestore */
	    }
	  /* gsave for convenience */
	  fputs("gs\n", pict_out);
	  /* set gray level */
	  fprintf(pict_out, "n %.2f sg\n", p->pict_lgray);
	  /* set and scale the font */
	  fprintf(pict_out, "/%s ff %.3f scf sf\n", p->pict_font, p->pict_fs);
	  /* place text and rotate if necessary */
	  fprintf(pict_out, "%.6f %.6f tr %.3f rot\n",
		  p->pict_tpt[t][0], p->pict_tpt[t][1], p->pict_tang[t]);
	  /* if left/right text position, not just show, requested */
	  if (p->pict_pos[t][0] == 'c' || p->pict_pos[t][0] == 'r')
	    {
	      /* first get string width: slightly wrong if it has super/sub-scripts */
	      fprintf(pict_out, "0 %.3f m (%s) sw pop %.3f mul ", yoff, baret, lfact);
	      /* go half-way back */
	      if (p->pict_pos[t][0] == 'c')
		fputs("-2 div 0 rm\n", pict_out);
	      /* go all the way back */
	      else
		fputs("neg 0 rm\n", pict_out);
	    }
	  else	/* or position is just fine */
	    fprintf(pict_out, "0 %.3f m ", yoff);
	  /* show the string, with all its super/sub-scripts, if any */
	  for (tc = toff, inscript = 0;
	       p->pict_txt[t][tc] && p->pict_txt[t][tc] != '\n'; )
	    {
	      /* copy part of string up to next super/sub-script mark */
	      for (i = 0; p->pict_txt[t][tc] && p->pict_txt[t][tc] != '^' &&
		     p->pict_txt[t][tc] != '|' && p->pict_txt[t][tc] != '\n';
		   i++, tc++)
		{
		  if (i < dap_maxtxt)
		    {
		      if (p->pict_txt[t][tc] == '(' || p->pict_txt[t][tc] == ')')
			{ /* parens need escape */
			  tpart[i++] = '\\';
			  if (i == dap_maxtxt)
			    {
			      fprintf(dap_err, "(show1) Text too long: %s\n",
				      p->pict_txt[t]);
			      exit(1);
			    }
			}
		      tpart[i] = p->pict_txt[t][tc];
		    }
		  else
		    {
		      fprintf(dap_err, "(show1) Text too long: %s\n",
			      p->pict_txt[t]);
		      exit(1);
		    }
		}
	      tpart[i] = '\0';
	      fprintf(pict_out, "(%s) sh ", tpart);	/* and show it */
	      /* if we found a super/sub-script mark, need to prepare for next chars */
	      if (p->pict_txt[t][tc] == '^' || p->pict_txt[t][tc] == '|')
		{
		  if (inscript)
		    {	/* leaving scripted part */
		      /* re-adjust font */
		      fprintf(pict_out, "/%s ff %.3f scf sf\n",
			      p->pict_font, p->pict_fs);
		      /* re-adjust position */
		      if (p->pict_txt[t][tc] == '^')
			fprintf(pict_out, "0 %.3f rm ",
				-SCRIPTH * p->pict_fs);
		      else
			fprintf(pict_out, "0 %.3f rm ",
				SCRIPTH * p->pict_fs);
		      inscript = 0;
		    }
		  else	/* entering scripted part */
		    {
		      /* adjust font */
		      fprintf(pict_out, "/%s ff %.3f scf sf\n",
			      p->pict_font, SCRIPTF * p->pict_fs);
		      /* adjust position */
		      if (p->pict_txt[t][tc] == '^')
			fprintf(pict_out, "0 %.3f rm ",
				SCRIPTH * p->pict_fs);
		      else
			fprintf(pict_out, "0 %.3f rm ",
				-SCRIPTH * p->pict_fs);
		      inscript = 1;
		    }
		  tc++;
		}
	    }
	  fputs("\ngr\n", pict_out);	/* grestore */
	  toff = tc;
	  while (p->pict_txt[t][toff] == '\n')
	    {
	      toff++;
	      yoff -= linespace * p->pict_fs;
	    }
	}
    }
  return p->pict_next;	/* return link to next pict */
}

/* "User" calls this to place a picture in the graphical output file */
void pict_show(pict *p)
{
  while (p)		/* show each pict and follow the link */
    p = show1(p);
}

void nport(pict *p, int nplots, int nperpage)
{
  int pn;

  if (nplots % nperpage)
    {
      fprintf(dap_err,
	      "(nport) Number of plots %d not a multiple of number per page %d\n",
	      nplots, nperpage);
      exit(1);
    }
  pict_port(nplots / nperpage);
  for (pn = 0; pn < nplots; pn += nperpage)
    {
      pict_page();
      pict_show(p + pn);
    }
  pict_end();
}

void nland(pict *p, int nplots, int nperpage)
{
  int pn;

  if (nplots % nperpage)
    {
      fprintf(dap_err,
	      "(pict_nlandscape) Number of plots %d not a multiple of number per page %d\n",
	      nplots, nperpage);
      exit(1);
    }
  pict_land(nplots / nperpage);
  for (pn = 0; pn < nplots; pn += nperpage)
    {
      pict_page();
      pict_show(p + pn);
    }
  pict_end();
}
