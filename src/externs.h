/* externs.h -- external parameters defined in dap.h */

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

/* Parameters for variables */
extern int dap_maxvar;		/* max number of variables in a dataset */
				/* if changed to >= 10,000, change dimstr in dap0.c */
extern int dap_namelen;		/* max length of variable names (+1 for null) */
extern int dap_intlen;		/* max number of char in char representation of int */
extern int dap_listlen;	        /* max length of list of variables */
extern int dap_strlen;		/* max length of some string values */

/* parameters for datasets */
extern char *dap_setdir;	/* where datasets are stored */
extern int dap_maxval;		/* max number of data values for some stat functions */
extern int dap_maxcell;		/* max number of cells for some internal tables */
extern int dap_maxtreat;        /* max number of treatments for ANOVA */

/* parameters for grouping */
extern int dap_maxbars;		/* max number of bars for histograms, grouping */
extern int dap_maxlev;		/* max number of levels of a variable */

/* parameters for graphics */
extern int dap_maxpts;		/* max number of points in a pict */
extern int dap_maxchar;		/* max number of chars in pict text */
extern int dap_maxntxt;
extern int dap_maxtxt;
extern int dap_maxfont;

/* Parameters for I/O */
extern int dap_toolong;         /* number of times to allow printing of "string too long"
				 * warning on input */
extern int dap_linelen;		/* max number of char for input line (+1 for null) */
extern int dap_outreport;	/* report multiples of this number of lines written */

/* Parameters for numerical algorithms */
extern double dap_redtol;
extern double dap_orthtol;
extern double dap_zerotol;
extern double dap_tol;
extern double dap_ctol;
extern double dap_ktol;
extern double dap_prtol;
extern double dap_addtozero;    /* for contingency tables */
extern int dap_maxiter;         /* max number of iterations */
extern int dap_maxex1;          /* max number of values for exact test */
extern int dap_maxex2;          /* max number of values for exact test */
extern double dap_cattol;	/* tolerance for categ() convergence */

/* Parameters for memory files */
extern int dap_nrfiles;		/* number of files stored in memory */
extern int dap_rfilesize;	/* max number of bytes in a memory file */
extern int dap_maxlines;	/* max number of lines in memory file:
				 * keep at dap_rfilesize / 8
				 */
extern int dap_maxmem; /* memory for sorting */
extern char *dap_tmpdir; /* temp dir for sorting */

/* Parameters for tables */
extern int dap_maxrows;		/* max rows for table() */
extern int dap_maxcols;		/* max columns for table() */
extern int dap_maxclab;		/* max number of column labels */
extern int dap_maxrowv;
extern int dap_maxcolv;
extern int dap_lablen;		/* max number of non-null char in column label */

/* Memory allocation racing flag */
extern char *dap_memtrace;	/* if non-NULL, print trace of malloc and free
                                 * and if address = dap_memtrace, then...
                                 */
extern int dap_mabort;		/* abort on malloc */
extern int dap_fabort;		/* abort on free */
