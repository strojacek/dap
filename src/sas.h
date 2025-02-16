/* sas.h -- header file for sas.c */

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

#define TOKENLEN 127 /* max length of token */
#define STATELEN 4095 /* max length of statement */
#define STEPLEN 65535 /* max length of step */
#define MAXVARS 512 /* max number of variables */
#define MAXPICTS 256 /* max number of pict arrays allocated by graphics procs */

/* variable types ("lengths") */
#define DBL (-1)
#define INT 0

extern int sastempnum;
extern int sashaspicts;
extern int newline;		/* flag: was most recent character a newline? */
extern int pound;		/* flag: got # as first char in line? */
extern int incomment;		/* flag: inside comment? */
extern int inquote1;
extern int inquote2;
extern int escape;

int import(char* fname, const char* fileToLoad, char * format,char  delimiter, int replace);

int dgetc(FILE *dotc, FILE *dapc, int out);

int linecpy(char *l1, char *l2);
int linecmp(char *l1, char *l2);
void upper(char *str);
int lower(int c);
int putlines(char *line, FILE *file, int term);

int isby(char *step);
int getoption(char *step, char *key, char *setname, int equals);
int copylist(char *step, char *key, FILE *dapfile);
int findstatement(char *step, char *key);
void countparts(char *step, char *setname, FILE *dapfile);

int white(int c);
int alpha(int c);
int num(int c);
int alphanum(int c);

void printtrans(char *step, FILE *dapfile);
void meanstrans(char *step, FILE *dapfile);
void sorttrans(char *step, FILE *dapfile);
void charttrans(char *step, FILE *dapfile);
void datasetstrans(char *step, FILE *dapfile);
void freqtrans(char *step, FILE *dapfile);
void tabulatetrans(char *step, FILE *dapfile);
void corrtrans(char *step, FILE *dapfile);
void plottrans(char *step, FILE *dapfile);
void ranktrans(char *step, FILE *dapfile);
void univariatetrans(char *step, FILE *dapfile);
void catmodtrans(char *step, FILE *dapfile);
void glmtrans(char *step, FILE *dapfile);
void logistictrans(char *step, FILE *dapfile);
void npar1waytrans(char *step, FILE *dapfile);
void regtrans(char *step, FILE *dapfile);
void daptrans(char *step, FILE *dapfile);
