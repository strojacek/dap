/* ps.h -- definitions for PostScript generator */

/*  Copyright (C) 2001, 2002 Free Software Foundation, Inc.
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

#define PORTRAIT 1
#define LANDSCAPE 2

typedef struct _pict
{
int pict_npts;				/* number of points in pict, if any */
char pict_type[5];			/* "LINE" = connected lines,
					 * "SEGM" = segments from pairs of points,
					 * "IBEA" = I-beams from pairs of points,
					 * "CIRC" = circles,
					 * "SQUA" = squares,
					 * "TRIA" = triangles,
					 * "UTRI" = upside-down triangles,
					 * "DIAM" = diamonds,
					 * "PATT" = pattern
					 */
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
char **pict_pos;			/* text position: 'l', 'c', 'r'; 't' 'm' 'b';
					 * ' ' for blank background box
					 */
double pict_lw;				/* line width */
double pict_r;				/* radius for circles */
double pict_lgray;              	/* gray level for lines */ 
double pict_fgray;              	/* gray level for fill: if >= 0, fill then stroke */
struct _pict *pict_patt;        	/* pict to use for fill or patterned points */
struct _pict *pict_next;        	/* for linking in list */
} pict;

typedef struct
{
double tick_num;		/* numerical value */
char *tick_lab;			/* label */
double tick_len;		/* length of tick mark in points */
} tick;

void pict_init(int orient, int bboxx0, int bboxy0, int bboxx1, int bboxy1, int npages);
void pict_port(int npages);
void pict_land(int npages);
void pict_end();
void pict_page();
void pict_initpict(pict *prev, pict *p);
void pict_clearpict(pict *p);
void pict_text(pict *p, char str[], double x, double y, double tang, char pos[]);
void pict_circle(pict *p, double cx, double cy, double r);
void pict_rectangle(pict *p, double cx, double cy, double sx, double sy);
void pict_hrect(pict *p, double spacing, double xl, double yb, double xside, double yside);
void pict_bhrect(pict *p, double spacing, double xl, double yb, double xside, double yside);
void pict_point(pict *p, double x, double y);
void pict_line(pict *p, double x0, double y0, double x1, double y1);
void pict_curve(pict *p, double (*xf)(double t), double (*yf)(double t),
                double t0, double t1, int nsteps);
void pict_scale(pict *p, double cx, double cy, double sx, double sy);
void pict_rotate(pict *p, double cx, double cy, double angle, int texttoo);
void pict_translate(pict *p, double tx, double ty);
void pict_show(pict *p);

void pict_maketick(tick *t, double num, char label[], double len);
void pict_axes(pict *p, double minx, double maxx, tick xtick[], int nxticks,
		double miny, double maxy, tick ytick[], int nyticks, char style[],
		double bpos, double lpos, double tpos, double rpos);
double pict_autoaxes(pict *p, char xlab[], char ylab[], char axspec[],
		double (*xfunct)(), double (*yfunct)(), char caption[], int autopos);
void nport(pict *p, int nplots, int nperpage);
void nland(pict *p, int nplots, int nperpage);

void pict_save(pict *p, int npicts, char *dataset);
pict *pict_rest(char *dataset);
