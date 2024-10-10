/* dap.h -- dap parameter definitions */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

/********************************************************
 * The following parameters control the operation of Dap.
 * To set their values, use a #define BEFORE the #include for
 * <dap.h>; for example to set the value of dap_maxvar to 512,
 * use
 *
 * #define DAP_MAXVAR 512
 *
 * BEFORE
 * 
 * #include <dap.h>
 **************************************************************
 ***** IT IS SAFER TO CHANGE THESE VALUES USING A #DEFINE *****
 ** THAN TO CHANGE THESE DEFAULT VALUES AT YOUR OWN RISK!!   **
 **************************************************************/

/* Parameters for variables */
#ifdef DAP_MAXVAR
int dap_maxvar = DAP_MAXVAR;
#else
int dap_maxvar = 256;		/* max number of variables in a dataset */
				/* if changed to >= 10,000, change dimstr in dap0.c */
#endif
#ifdef DAP_NAMELEN
int dap_namelen = DAP_NAMELEN;
#else
int dap_namelen = 15;		/* max length of variable names (+1 for null) */
#endif
#ifdef DAP_INTLEN
int dap_intlen = DAP_INTLEN;
#else
int dap_intlen = 20;		/* max number of char in char representation of int */
#endif
#ifdef DAP_LISTLEN
int dap_listlen = DAP_LISTLEN
#else
#ifdef DAP_MAXVAR
#ifdef DAP_NAMELEN
int dap_listlen = (DAP_MAXVAR * (DAP_NAMELEN + 7));
				/* max length of list of variables: dap_maxvar *
				 * (max var name length + room for bracketed index)
				 * This may not be entirely safe! (but most likely is)
				 */
#else
int dap_listlen = (DAP_MAXVAR * (15 + 7));
				/* max length of list of variables: dap_maxvar *
				 * (max var name length + room for bracketed index)
				 * This may not be entirely safe! (but most likely is)
				 */
#endif
#else
int dap_listlen = (256 * (15 + 7));
				/* max length of list of variables: dap_maxvar *
				 * (max var name length + room for bracketed index)
				 * This may not be entirely safe! (but most likely is)
				 */
#endif
#endif
#ifdef DAP_TOOLONG
int dap_toolong = DAP_TOOLONG;
#else
int dap_toolong = 10;		/* max # times to print "string too long" message */
#endif

#ifdef DAP_STRLEN
int dap_strlen = DAP_STRLEN;
#else
int dap_strlen = 63;		/* max length of some string values */
#endif

/* Parameters for tables */
#ifdef DAP_MAXROWS
int dap_maxrows = DAP_MAXROWS;
#else
int dap_maxrows = 1024;		/* max rows for table() */
#endif
#ifdef DAP_MAXCOLS
int dap_maxcols = DAP_MAXCOLS;
#else
int dap_maxcols = 64;		/* max columns for table() */
#endif
#ifdef DAP_MAXCLAB
int dap_maxclab = DAP_MAXCLAB;
#else
int dap_maxclab = 128;		/* max number of column labels */
#endif
#ifdef DAP_MAXROWV
int dap_maxrowv = DAP_MAXROWV;
#else
int dap_maxrowv = 8;		/* max number of row variables */
#endif
#ifdef DAP_MAXCOLV
int dap_maxcolv = DAP_MAXCOLV;
#else
int dap_maxcolv = 8;		/* max number of column variables */
#endif
#ifdef DAP_LABLEN
int dap_lablen = DAP_LABLEN;
#else
int dap_lablen = 63;		/* max number of non-null char in column label */
#endif

/* parameters for datasets */
#ifdef DAP_SETDIR
char *dap_setdir = DAP_SETDIR;
#else
char *dap_setdir = "dap_sets";	/* where datasets are stored */
#endif
#ifdef DAP_MAXVAL
int dap_maxval = DAP_MAXVAL;
#else
int dap_maxval = 32768;		/* max number of values for some stat functions*/
#endif
#ifdef DAP_MAXCELL
int dap_maxcell = DAP_MAXCELL;
#else
int dap_maxcell = 512;          /* max number of cells in some internal tables */
#endif
#ifdef DAP_MAXTREAT
int dap_maxtreat = DAP_MAXTREAT;
#else
int dap_maxtreat = 9;           /* max number of factors for ANOVA */
#endif

/* parameters for grouping */
#ifdef DAP_MAXBARS
int dap_maxbars = DAP_MAXBARS;
#else
int dap_maxbars = 128;          /* max number of bars for histograms, grouping */
#endif
#ifdef DAP_MAXLEV
int dap_maxlev = DAP_MAXLEV;
#else
int dap_maxlev = 96;            /* max number of levels of a variable */
#endif

/* Parameters for I/O */
#ifdef DAP_LINELEN
int dap_linelen = DAP_LINELEN;
#else
int dap_linelen = 2047;         /* max number of char for input line (+1 for null) */
#endif
#ifdef DAP_OUTREPORT
int dap_outreport = DAP_OUTREPORT;
#else
int dap_outreport = 100000;     /* report multiples of this number of lines written */
#endif

/* Parameters for graphics */
#ifdef DAP_MAXPTS
int dap_maxpts = DAP_MAXPTS;
#else
int dap_maxpts = 16384;         /* max number of points in a pict */
#endif
#ifdef DAP_MAXCHAR
int dap_maxchar = DAP_MAXCHAR;
#else
int dap_maxchar = 65536;        /* max number of text chars in a pict */
#endif
#ifdef DAP_MAXNTXT
int dap_maxntxt = DAP_MAXNTXT;
#else
int dap_maxntxt = 128;
#endif
#ifdef DAP_MAXTXT
int dap_maxtxt = DAP_MAXTXT;
#else
int dap_maxtxt = 127;
#endif
#ifdef DAP_MAXFONT
int dap_maxfont = DAP_MAXFONT;
#else
int dap_maxfont = 63;
#endif

/* Parameters for numerical algorithms */
#ifdef DAP_REDTOL
double dap_redtol = DAP_REDTOL;
#else
double dap_redtol = 1e-9;
#endif
#ifdef DAP_ORTHTOL
double dap_orthtol = DAP_ORTHTOL;
#else
double dap_orthtol = 1e-9;
#endif
#ifdef DAP_ZEROTOL
double dap_zerotol = DAP_ZEROTOL;
#else
double dap_zerotol = 1e-6;
#endif
#ifdef DAP_TOL
double dap_tol = DAP_TOL;
#else
double dap_tol = 1e-8;
#endif
#ifdef DAP_CTOL
double dap_ctol = DAP_CTOL;
#else
double dap_ctol = 1e-6;
#endif
#ifdef DAP_KTOL
double dap_ktol = DAP_KTOL;
#else
double dap_ktol = 1e-6;
#endif
#ifdef DAP_PRTOL
double dap_prtol = DAP_PRTOL;
#else
double dap_prtol = 1e-6;
#endif
#ifdef DAP_ADDTOZERO
double dap_addtozero = DAP_ADDTOZERO;
#else
double dap_addtozero = 1e-8;    /* for contingency tables */
#endif
#ifdef DAP_MAXITER
int dap_maxiter = DAP_MAXITER;
#else
int dap_maxiter = 500;         /* max number of iterations */
#endif
#ifdef DAP_MAXEX1
int dap_maxex1 = DAP_MAXEX1;
#else
int dap_maxex1 = 20;          /* max number of values for exact test */
#endif
#ifdef DAP_MAXEX2
int dap_maxex2 = DAP_MAXEX2;
#else
int dap_maxex2 = 20;          /* max number of values for exact test */
#endif
#ifdef DAP_CATTOL
double dap_cattol = DAP_CATTOL;
#else
double dap_cattol = 0.0000005; /* tolerance for convergence in categ() */
#endif

/* Parameters for memory files */
#ifdef DAP_NRFILES
int dap_nrfiles = DAP_NRFILES;
#else
int dap_nrfiles = 128;          /* number of files stored in memory */
#endif
#ifdef DAP_RFILESIZE
int dap_rfilesize = DAP_RFILESIZE;
#else
int dap_rfilesize = 16384;      /* max number of bytes in a memory file */
#endif
#ifdef DAP_MAXLINES
int dap_maxlines = DAP_MAXLINES;
#else
int dap_maxlines = 2048;        /* max number of lines in memory file:
                                 * keep at dap_rfilesize / 8
                                 */
#endif

#ifdef DAP_MAXMEM
int dap_maxmem = DAP_MAXMEM;
#else
int dap_maxmem = 1048576; /* memory buffer size for sorting */
#endif
#ifdef DAP_TMPDIR
char *dap_tmpdir = DAP_TMPDIR;
#else
char *dap_tmpdir = "dap_tmp";	/* where datasets are stored */
#endif

/* Memory allocation tracing */
#ifdef DAP_MEMTRACE
char *dap_memtrace = DAP_MEMTRACE;
#else
char *dap_memtrace = NULL;      /* if non-NULL, print trace of malloc and free
                                 * and if address = dap_memtrace, then...
                                 */
#endif
#ifdef DAP_MABORT
int dap_mabort = DAP_MABORT;
#else
int dap_mabort = 0;          /* abort on malloc */
#endif
#ifdef DAP_FABORT
int dap_fabort = DAP_FABORT;
#else
int dap_fabort = 0;          /* abort on free */
#endif

#include <dap1.h>
