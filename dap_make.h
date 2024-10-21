/* dap_make.h -- dap definitions and functions for making dap */

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



#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <math.h>

#define SETDELIM '|'		/* the delimiter used in datasets */

#define INT 0			/* code for int variables */
#define DBL (-1)		/* code for double variables */
		/* character strings have positive code equal to length */

#define STATLEN 8
#define MAXPCTPT 9
#define N 0
#define SUM (N+1)
#define SUMWT (SUM+1)
#define MEAN (SUMWT+1)
#define MIN (MEAN+1)
#define MAX (MIN+1)
#define RANGE (MAX+1)
#define STEP (RANGE+1)
#define VAR (STEP+1)
#define VARM (VAR+1)
#define SD (VARM+1)
#define SEM (SD+1)
#define VARFREQ (SEM+1)
#define VARMFREQ (VARFREQ+1)
#define SDFREQ (VARMFREQ+1)
#define SEMFREQ (SDFREQ+1)
#define T (SEMFREQ+1)
#define TPROB (T+1)
#define QRANGE (TPROB+1)
#define SIGN (QRANGE+1)
#define SPROB (SIGN+1)
#define SRANK (SPROB+1)
#define SRPROB (SRANK+1)
#define NORMAL (SRPROB+1)
#define NPROB (NORMAL+1)
#define P1 (NPROB+1)
#define P5 (P1+1)
#define P10 (P5+1)
#define Q1 (P10+1)
#define MED (Q1+1)
#define Q3 (MED+1)
#define P90 (Q3+1)
#define P95 (P90+1)
#define P99 (P95+1)
#define PXXXX1 (P99+1)
#define PXXXX2 (PXXXX1+1)
#define PXXXX3 (PXXXX2+1)
#define PXXXX4 (PXXXX3+1)
#define PXXXX5 (PXXXX4+1)
#define PXXXX6 (PXXXX5+1)
#define PXXXX7 (PXXXX6+1)
#define PXXXX8 (PXXXX7+1)
#define PXXXX9 (PXXXX8+1)

#define NSTATS (PXXXX9+1)

typedef struct
{
int *do_int;		/* integer variable values */
int **do_il;		/* links to integer variables, for user program */
double *do_dbl;         /* double precision variable values */
double **do_dl;		/* links to double precision variables, for user program */
char **do_str;		/* string variable values */
int *do_sl;		/* string linked to user program */
char **do_nam;		/* variable names */
int *do_len;            /* variable lengths (INT, DBL, or > 0 for string) */
int *do_in;		/* input variables */
int *do_out;            /* output variables */
int do_ivar;            /* number of input variables */
int do_ovar;            /* number of output variables */
int do_nvar;            /* number of variables */
int do_valid;		/* valid data flag */
} dataobs;

typedef struct {
char *rfile_str;
char *rfile_pos;
char *rfile_end;
} RFILE;

typedef struct {
char *dfile_name;
FILE *dfile_disk;
RFILE *dfile_ram;
} DFILE;

long dap_ftell(DFILE *fp);
void dap_putc(int c, DFILE *fp);
void title(char *text);
double *dap_d(char vname[]);
double *dap_pd(char vname[]);
int *dap_i(char vname[]);
int *dap_pi(char vname[]);
char *dap_s(char vname[]);
int dap_blank(char str[]);
void infile(char fname[], char delim[]);
void input(char varlist[]);
int step();
void inset(char fname[]);
void outset(char fname[], char varlist[]);
void output();

void sort(char fname[], char varlist[], char modifiers[]);
void print(char fname[], char *varlist);
void means(char fname[], char varlist[], char statlist[], char marks[]);
void table(char fname[], char rowvars[], char colvars[], char format[],
		char marks[]);

void dap_suffix(char dst[], char src[], char suff[]);
int dap_vd(char varspec[], int invar);
void dap_swap();
void dap_save();
void dap_rest();
void dap_mark();
void dap_rewind();
int dap_varnum(char vname[]);
int dap_arrnum(char vname[], int *dim);
void dap_setref();
void dap_head(int markv[], int nmark);
int dap_list(char varlist[], int varv[], int maxvars);
void dap_stats(char statlist[], int stats[]);
int dap_newpart(int partv[], int npartv);
void dap_name(char dname[], char fname[]);
void dap_parsey(char yspec[], int varv[]);	/* for logreg */

int dap_invert(double **mat, int nrc);
double varnorm();
double varunif();
double probt(double t1, int di);
double chisqpoint(double p, int df);
double fpoint(double p, int numdf, int dendf);
double zpoint(double p);
double tpoint(double p, int in);
double probz(double z1);
double probf(double f2, int id1, int id2);
double probchisq(double x2, int df);
double dap_sr(int numdf, int dendf, double pt);
double dap_srpt(int numdf, int dendf, double pt, double pr, double alpha);
double dap_md(int numdf, int dendf, double pt);
double dap_mdpt(int numdf, int dendf, double pt, double pr, double alpha);

double dap_simp(double (*f)(), double a, double b, int n);
double dap_bincoeff(double n, double r);
double dap_maximize(double (*f)(double x[]), int nx, double x[],
                                        double step, double tol, char *trace);

void dataset(char oldname[], char newname[], char *action);
void group(char fname[], char varspec[], char marks[]);
void linreg(char fname[], char ylist[], char x0list[], char x1list[],
                                char marks[], char xname[], double level);
void logreg(char fname[], char ylist[], char x0list[], char x1list[],
                                char marks[], char xname[], double level);

char *dap_malloc(int nbytes, char *mesg);
void dap_free(void *ptr, char *mesg);

void dap_initpict();
void dap_putdouble(DFILE *dfp);
void dap_getdouble(char code[]);
void dap_putint(int i, DFILE *dfp);
int dap_getint(char code[]);
int dap_mnsparse(char *varlist, char *outlist, int *varv, int *wtvar, int stats[]);
int dap_clearobs(char *varspec);
