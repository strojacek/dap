/* dap1.h -- dap function definitions */

#include <stdio.h>
#include <math.h>

/*  Copyright (C) 2001, 2002, 2005 Free Software Foundation, Inc.
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

/* First, definitions for picture structure and functions */
#include <ps.h>

extern FILE *dap_lst;
extern FILE *dap_log;
extern FILE *dap_err;

int dap_newpart(int partv[], int npartv);
int dap_list(char *list, int listv[], int maxvars);
void dap_swap();
void dap_save();
void dap_rest();
void dap_backup();
void dap_rewind();
void dap_mark();
void dap_head(int markv[], int nmark);
void input(char varlist[]);
void infile(char fname[], char delim[]);
int dap_vd(char varspec[], int invar);
void dap_dl(char varname[], double *dbl);
void dap_il(char varname[], int *i);
void dap_sl(char varname[], char *s);
int step();
int skip(int nlines);
void inset(char fname[]);
void outset(char fname[], char varlist[]);
void output();
void title(char *text);
void merge(char fname1[], char vars1[], char fname2[], char vars2[],
		char marks[], char outname[]);
void surveyselect(char *fname,char *outname,char *method,int tirage);
void dataset(char oldname[], char newname[], char *action);
void sort(char fname[], char varlist[], char modifiers[]);
void print(char fname[], char *varlist);
void means(char fname[], char varlist[], char statlist[], char marks[]);
pict *plotmeans(char *dataset, char *meanvar, char *varlist, char *errbar,
				char *style, char *partvars, int noverlay);
void table(char fname[], char rowvars[], char colvars[], char format[], char marks[]);
void split(char fname[], char varlist[], char classvalvars[]);
void join(char fname[], char partvars[], char valuevar[]);
pict *plot(char fname[], char xyvar[], char marks[],
		char style[], double (*xfunct)(), double (*yfunct)(), int nplots);
pict *normal(char fname[], char variable[], char marks[], int nplots);
pict *histogram(char fname[], char variable[], char marks[], int nbars,
		char style[], double (*xfunct)(), int nplots);

void pctiles(char fname[], char varlist[], char statlist[], char marks[]);
void group(char fname[], char varspec[], char marks[]);
void freq(char fname[], char varlist[], char stats[], char marks[]);
void trim(char fname[], char trimspec[], char marks[]);
void corr(char fname[], char varlist[], char marks[]);
void ftest(char fname[], char response[], char numerator[], char denominator[],
						 char marks[]);
void effects(char fname[], char varlist[], char model[], char marks[]);
void lsmeans(char fname[], char method[], double alpha, char varlist[], char treat[],
                char marks[], char format[]);
void linreg(char fname[], char ylist[], char x0list[], char x1list[],
				char marks[], char xname[], double level);
pict *plotlinreg(char *fname, char *ylist, char *x1list, char *style,
		char *marks, int nmarks, double level);
void logreg(char fname[], char yspec[], char x0list[], char x1list[],
				char marks[], char xname[], double level);
pict *plotlogreg(char *fname, char *yspec, char *x1list, char *style, int ngroups,
			char *marks, int nmarks, double level);
void nonparam(char fname[], char variables[], char marks[]);
void categ(char *dataset, char *varlist, char *auxvarlist, double (*prob)(),
		double param[], char *select, char *partvars, char *trace);
void loglin(char *fname, char *varlist, char *model0, char *model1, char *part);
void estimate(char *fname, char *parameters, char *definitions, char *part);

double varnorm();
double varunif();
double probt(double t1, int di);
double probz(double z);
double chisqpoint(double p, int df);
double fpoint(double p, int numdf, int dendf);
double zpoint(double p);
double tpoint(double p, int in);
double probf(double f2, int id1, int id2);
double probchisq(double c, int df);
int dap_numdate(char date[]);
void dap_datenum(int n, char *d);
double dap_bincoeff(double n, double r);
double dap_maximize(double (*f)(double x[]), int nx, double x[],
					double step, double tol, char *trace);
int dap_invert(double *mat[], int rowscols);

