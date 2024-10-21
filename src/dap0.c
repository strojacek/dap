/* Contains the basic I/O and setup routines.  */

/*  Copyright (C) 2001, 2002, 2003, 2004 Free Software Foundation, Inc.
 *
 *  Dap is a GNU program.
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


#include <sys/types.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "dap_make.h"
#include "externs.h"



/* dataobs structures contain the names and values of the variables.  
 * Also contain number of variables, etc.: see dap_make.h.  
 */

/* The values read from the current input line.  */
dataobs dap_obs[3];	/* normally use 0 for in and out; select by dap_ono */

/* The values read from the previous input line.  */
dataobs dap_prev[2];	/* only use 0 or 1 for input */

/* For saving values read from current input line.  */
static dataobs dosave;

static RFILE *rfile;		/* the array of ram files (see dap_make.h) */

/* A DFILE can be either a disk file or a ramfile: 0, 1, 2 are used for disk
 * files, > 2 for ramfiles.  
 */

#define NDFILES 4	/* number of actual disk files */

static DFILE *dfile;

DFILE *dap_in[3];	/* input files */
DFILE *dap_out[3];	/* output files */
FILE *dap_lst;		/* .lst file */
FILE *dap_log;		/* .log file, for lines read, written */
FILE *dap_err;		/* .err file, for errors */
int dap_ono;		/* specifies which set of variable values (dataobs) to use */
int dap_delim;		/* delimiter for reading data files (not datasets) */
static int *fieldwd;	/* width of fixed width input data fields */
static int nfields;		/* number of fixed width input data fields */
static int lineno[2];		/* line number for up to 2 input datasets */
static int outline;		/* number of lines written */
static int pageno;		/* output page number */
static int eof[2];		/* flags: has EOF been reached on input file(s)? */
static long filepos[2];		/* file positions of input file(s) */

/* These are the types of input data files (not datasets) recognized.  */
#define TEXT 0		/* ordinary text, fields either fixed width or delimited */
#define DBASE 1		/* dBase */
#define DSET 2		/* dap dataset */

static int intype;	/* type of input file */
static int inlen;	/* line length for files with dBase files */
static int toolong;	/* count: string data longer than specified encountered? */

char *dap_title = NULL;	/* title for .lst pages, caption for .ps pages */

char *dap_dapname;	/* name of program running */
char *dap_psname;	/* name of the .ps file */

extern int dap_dblhigh;	/* for coding doubles */
extern int dap_dbllow;	/* for coding doubles */
extern double dap_double;	/* to get around weird returns; see machdep.c */

static int nmallocs = 0;
static int nfrees = 0;
extern int dap_main(int argc, char **argv);
char *dap_malloc(int nbytes, char *mesg)
{
  char *m;

  nmallocs++;
  if (!(m = malloc(nbytes)))
    {
      perror(dap_dapname);
      exit(1);
    }
  if (dap_memtrace)
    {
      fprintf(dap_log, "malloc %x %s\n", (unsigned int) m, mesg);
      fflush(dap_log);
      if (dap_mabort && m == dap_memtrace)
	abort();
    }
  return m;
}

void dap_free(void *ptr, char *mesg)
{
  nfrees++;
  if (dap_memtrace)
    {
      fprintf(dap_log, "free %x %s\n", (unsigned int) ptr, mesg);
      fflush(dap_log);
      if (dap_fabort && ptr == dap_memtrace)
	abort();
    }
  free(ptr);
}

static void initdo(dataobs *dato)
{
  int d;

  dato->do_int = (int *) dap_malloc(sizeof(int) * dap_maxvar, "initdo: dato->do_int");
  dato->do_il = (int **) dap_malloc(sizeof(int *) * dap_maxvar, "initdo: dato->do_il");
  dato->do_dbl = (double *) dap_malloc(sizeof(double) * dap_maxvar, "initdo: dato->do_dbl");
  dato->do_dl = (double **) dap_malloc(sizeof(double *) * dap_maxvar, "initdo: dato->do_dl");
  dato->do_str = (char **) dap_malloc(sizeof(char *) * dap_maxvar, "initdo: dato->do_str");
  dato->do_sl = (int *) dap_malloc(sizeof(int) * dap_maxvar, "initdo: dato->do_sl");
  dato->do_nam = (char **) dap_malloc(sizeof(char *) * dap_maxvar, "initdo: dato->do_nam");
  dato->do_len = (int *) dap_malloc(sizeof(int) * dap_maxvar, "initdo: dato->do_len");
  dato->do_in = (int *) dap_malloc(sizeof(int) * dap_maxvar, "initdo: dato->do_in");
  dato->do_out = (int *) dap_malloc(sizeof(int) * dap_maxvar, "initdo: dato->do_out");
  for (d = 0; d < dap_maxvar; d++)
    {
      dato->do_str[d] = NULL;
      dato->do_nam[d] = NULL;
    }
}

/* the following variables are for determining endianness */
static double testd; /* a double, half of whose contents will be converted to an... */
static unsigned int *ptesti; /* unsigned int to see if they are
			      /* zero (mantissa) or not (exponent and sign
			       */

int main(int argc, char **argv)
{
  char *lstname;		/* name of .lst file */
  char *logname;		/* name of .log file */
  char *errname;		/* name of .err file */
  int len;		/* length of lstname, logname, errname */
  int v;			/* index to variables */

  dap_dapname = argv[0];
  len = strlen(argv[0]);
  lstname = malloc(len + 5);	/* room for suffix */
  strcpy(lstname, argv[0]);
  if (len >= 4 && !strcmp(lstname + len - 4, ".dap"))
    strcpy(lstname + len - 3, "lst");
  else
    {
      strcat(lstname, ".lst");
      len += 4;
    }
  if (!(dap_lst = fopen(lstname, "a")))
    {
      perror(dap_dapname);
      exit(1);
    }
  logname = malloc(len + 1);
  strcpy(logname, lstname);
  strcpy(logname + len - 3, "log");
  if (!(dap_log = fopen(logname, "w")))
    {
      perror(dap_dapname);
      exit(1);
    }
  errname = malloc(len + 1);
  strcpy(errname, lstname);
  strcpy(errname + len - 3, "err");
  if (!(dap_err = fopen(errname, "w")))
    {
      perror(dap_dapname);
      exit(1);
    }
  initdo(dap_obs);
  initdo(dap_obs + 1);
  initdo(dap_obs + 2);
  initdo(dap_prev);
  initdo(dap_prev + 1);
  initdo(&dosave);
  rfile = (RFILE *) dap_malloc(sizeof(RFILE) * dap_nrfiles, "main: rfile");
  dfile = (DFILE *) dap_malloc(sizeof(DFILE) * (dap_nrfiles + NDFILES), "main: dfile");
  pageno = 1;
  dap_psname = dap_malloc(len + 1, "main: dap_psname");
  strcpy(dap_psname, lstname);
  strcpy(dap_psname + len - 3, "ps");
  dap_initpict();
  for (v = 0; v < dap_maxvar; v++)
    {
      for (dap_ono = 0; dap_ono < 3; dap_ono++)
	{
	  dap_obs[dap_ono].do_nam[v] = NULL;
	  dap_obs[dap_ono].do_dl[v] = NULL;
	  dap_obs[dap_ono].do_il[v] = NULL;
	  dap_obs[dap_ono].do_str[v] = NULL;
	  dap_obs[dap_ono].do_sl[v] = 0;
	  if (dap_ono < 2)
	    dap_prev[dap_ono].do_str[v] = NULL;
	}
      dosave.do_str[v] = NULL;
    }
  dap_ono = 0;
  testd = -2.0; /* this should have the sign bit set and non-zero exponent, but
		   /* zero mantissa
		    */
  ptesti = (int *) &testd; /* *ptesti is the low order word of testd */
  if (!(*ptesti))
    { /* if that's zero, then the sign and exponent are in the high-order word */
      dap_dbllow = 0;
      dap_dblhigh = 1;
    }
  else
    { /* else they're in the low-order word */
      dap_dbllow = 1;
      dap_dblhigh = 0;
    }
  for (v = 0; v < 3; v++)
    {
      dap_in[v] = (DFILE *) NULL;
      dap_out[v] = (DFILE *) NULL;
    }
  dap_main(argc, argv);
  return 0;
}

/* Open a disk file dataset */
static FILE *dopen(char fname[], char mode[])
{
  char *dname;
  FILE *f;

  dname = dap_malloc(strlen(fname) + strlen(dap_setdir) + 2, "dopen: dname");
  dap_name(dname, fname);
  f = fopen(dname, mode);
  dap_free(dname, "dopen: dname");
  return f;
}

/* if mode[1] == 'f', it's a file, not a dataset, so don't prepend directory */
static DFILE *dfopen(char *fname, char *mode)
{
  static int rfileinit = 0;	/* flag: has the ramfile array been initialized? */
  int f;
  char truemode[2];

  if (!rfileinit)
    {
      rfileinit = 1;
      for (f = 0; f < dap_nrfiles; f++)
	{
	  dfile[NDFILES + f].dfile_name = NULL;
	  dfile[NDFILES + f].dfile_ram = rfile + f;
	  dfile[NDFILES + f].dfile_disk = NULL;
	  rfile[f].rfile_str = NULL;
	}
      for (f = 0; f < NDFILES; f++)
	{
	  dfile[f].dfile_disk = NULL;
	  dfile[f].dfile_ram = NULL;
	}
    }
  if (!fname)
    {
      fputs("(dfopen) no file name given\n", dap_err);
      exit(1);
    }
  if (fname[0] == '<')
    {
      if (!strcmp(mode, "r"))
	{
	  for (f = 0; f < dap_nrfiles; f++)
	    {
	      if (dfile[NDFILES + f].dfile_name &&
		  !strcmp(dfile[NDFILES + f].dfile_name, fname + 1))
		{
		  rfile[f].rfile_pos = rfile[f].rfile_str;
		  return dfile + NDFILES + f;
		}
	    }
	  return NULL;
	}
      else if (!strcmp(mode, "w"))
	{
	  for (f = 0; f < dap_nrfiles; f++)
	    {
	      if (dfile[NDFILES + f].dfile_name &&
		  !strcmp(dfile[NDFILES + f].dfile_name, fname + 1))
		{
		  rfile[f].rfile_end = rfile[f].rfile_str;
		  rfile[f].rfile_pos = rfile[f].rfile_str;
		  return dfile + NDFILES + f;
		}
	    }
	  for (f = 0; f < dap_nrfiles; f++)
	    {
	      if (!dfile[NDFILES + f].dfile_name)
		{
		  rfile[f].rfile_str = dap_malloc(dap_rfilesize,
						  "dfopen: rfile[f].rfile_str");
		  dfile[NDFILES + f].dfile_name =
		    dap_malloc(strlen(fname), "dfopen: dfile[NDFILES + f].dfile_name");
		  strcpy(dfile[NDFILES + f].dfile_name, fname + 1);
		  rfile[f].rfile_end = rfile[f].rfile_str;
		  rfile[f].rfile_pos = rfile[f].rfile_str;
		  return dfile + NDFILES + f;
		}
	    }
	  return NULL;
	}
      else if (!strcmp(mode, "a"))
	{
	  for (f = 0; f < dap_nrfiles; f++)
	    {
	      if (!strcmp(dfile[NDFILES + f].dfile_name, fname + 1))
		{
		  rfile[f].rfile_pos = rfile[f].rfile_end;
		  return dfile + NDFILES + f;
		}
	    }
	  return NULL;
	}
      else
	{
	  fprintf(dap_err, "(dfopen) bad mode: %s\n", mode);
	  exit(1);
	}
    }
  for (f = 0; f < NDFILES; f++)
    {
      if (!dfile[f].dfile_disk)
	{
	  if (mode[1] == 'f')
	    {
	      truemode[0] = mode[0];
	      truemode[1] = '\0';
	      dfile[f].dfile_disk = fopen(fname, truemode);
	    }
	  else
	    dfile[f].dfile_disk = dopen(fname, mode);
	  if (dfile[f].dfile_disk)
	    {
	      dfile[f].dfile_name =
		dap_malloc(strlen(fname) + 1, "dfopen: dfile[f].dfile_name");
	      strcpy(dfile[f].dfile_name, fname);
	      return dfile + f;
	    }
	  else
	    return NULL;
	}
    }
  return NULL;
}

static void dfclose(DFILE *fp)
{
  if (fp->dfile_disk)
    {
      fclose(fp->dfile_disk);
      fp->dfile_disk = NULL;
    }
  else
    fp->dfile_ram->rfile_pos = fp->dfile_ram->rfile_str;
}

static int dgetc(DFILE *fp)
{
  int c;

  if (fp->dfile_disk)
    c = getc(fp->dfile_disk);
  else if (fp->dfile_ram->rfile_pos < fp->dfile_ram->rfile_end)
    c = *fp->dfile_ram->rfile_pos++;
  else
    c = EOF;
  return c;
}

static void undgetc(int c, DFILE *fp)
{
  if (fp->dfile_disk)
    ungetc(c, fp->dfile_disk);
  else if (fp->dfile_ram->rfile_pos > fp->dfile_ram->rfile_str)
    {
      --fp->dfile_ram->rfile_pos;
      *fp->dfile_ram->rfile_pos = c;
    }
  else
    {
      fprintf(dap_err, "(undgetc) can't unget past beginning of file %s\n",
	      fp->dfile_name);
      exit(1);
    }
}

void dap_putc(int c, DFILE *fp)
{
  if (fp->dfile_disk)
    putc(c, fp->dfile_disk);
  else if (fp->dfile_ram->rfile_pos < fp->dfile_ram->rfile_str + dap_rfilesize)
    {
      *fp->dfile_ram->rfile_pos++ = c;
      fp->dfile_ram->rfile_end++;
    }
  else
    {
      fprintf(dap_err, "(dap_putc) too many characters: %s\n",
	      fp->dfile_name);
      exit(1);
    }
}

static void dputs(char *s, char *suff, DFILE *fp)
{
  if (fp->dfile_disk)
    {
      fputs(s, fp->dfile_disk);
      fputs(suff, fp->dfile_disk);
    }
  else
    {
      while (*s)
	dap_putc(*s++, fp);
      while (*suff)
	dap_putc(*suff++, fp);
    }
}

static void dputi(int i, DFILE *fp)
{
  static char *istr = NULL;
  int s;

  if (!istr)
    istr = dap_malloc(dap_intlen + 1, "dputi: istr");
  if (fp->dfile_disk)
    fprintf(fp->dfile_disk, "%d", i);
  else
    {
      sprintf(istr, "%d", i);
      for (s = 0; s < strlen(istr); s++)
	dap_putc(istr[s], fp);
    }
}

static void dflush(DFILE *fp)
{
  fflush(fp->dfile_disk);
}

/* Append or replace suffix. If suff[0] == '<', then suff replaces
 * characters following last '.', otherwise is appended
 */
void dap_suffix(char dst[], char src[], char suff[])
{
  int n, s;

  for (n = 0; src[n]; n++)
    dst[n] = src[n];
  if (suff[0] == '<')
    {
      while (--n >= 0)
	{
	  if (dst[n] == '.')
	    break;
	}
      if (n < 0)
	{
	  fprintf(dap_err, "(dap_suffix) source name has no '.': %s\n", src);
	  exit(1);
	}
      n++;
      s = 1;
    }
  else
    s = 0;
  for ( ; suff[s]; s++)
    dst[n++] = suff[s];
  dst[n] = '\0';
}

/* get the index of a variable */
int dap_varnum(char *vname)
{
  int v;
  int nonblank; /* number of non-blank characters in vname */

  while (*vname == ' ')
    vname++;
  for (nonblank = 0; vname[nonblank] && vname[nonblank] != ' '; nonblank++)
    ;
  if (vname)
    {
      for (v = 0; v < dap_obs[dap_ono].do_nvar; v++)
	{
	  if (!strncmp(vname, dap_obs[dap_ono].do_nam[v], nonblank) &&
	      !dap_obs[dap_ono].do_nam[v][nonblank])
	    return v;
	}
    }
  return -1;
}

int dap_arrnum(char vname[], int *dim)
{
  int v;
  int n;
  int d;

  for (v = 0; v < dap_obs[dap_ono].do_nvar; v++)
    {
      for (n = 0; vname[n] && vname[n] == dap_obs[dap_ono].do_nam[v][n]; n++)
	;
      if (!vname[n] && dap_obs[dap_ono].do_nam[v][n] == '[')
	{
	  for (d = 1; v + d < dap_obs[dap_ono].do_nvar; d++)
	    {
	      for (n = 0; vname[n] &&
		     vname[n] == dap_obs[dap_ono].do_nam[v + d][n]; n++)
		;
	      if (vname[n] || dap_obs[dap_ono].do_nam[v + d][n] != '[')
		break;
	    }
	  *dim = d;
	  return v;
	}
    }
  return -1;
}


static int dap_getline(DFILE *fp, char *line)
{
  int l;
  int c;
  int cc;

  c = EOF;
  switch (intype)
    {
    case TEXT:
    case DSET:
      for (l = 0; (c = dgetc(fp)) != EOF; )
	{
	  if (c == '\n')
	    break;
	  else if (c == '\r')
	    {
	      if ((cc = dgetc(fp)) != '\n')
		undgetc(cc, fp);
	      break;
	    }
	  if (l < dap_linelen)
	    line[l++] = c;
	  else
	    {
	      line[l] = '\0';
	      fprintf(dap_err, "(dap_getline) line too long:\n%s\n", line);
	      exit(1);
	    }
	}
      line[l] = '\0';
      break;
    case DBASE:
      dgetc(fp);      /* dump space */
      for (l = 0; l < inlen; l++)
	{
	  if ((c = dgetc(fp)) == EOF)
	    break;
	  else
	    line[l] = c;
	}
      if (l < inlen)
	l = 0;
      line[l] = '\0';
      break;
    default:
      fprintf(dap_err, "(dap_getline) bad infile type: %d\n", intype);
      exit(1);
    }
  if (!l && c == EOF)
    return -1;
  return l;
}

void dap_swap()
{
  int iv;		/* index of input variable */
  double dbltmp;	/* temp for swapping doubles */
  int inttmp;	/* temp for swapping int */
  char strtmp;	/* temp char for swapping strings */
  int s;		/* index to strings */
  char *so, *sp;	/* pointers to strings for obs, prev */

  for (iv = 0; iv < dap_obs[dap_ono].do_ivar; iv++)
    {
      switch (dap_obs[dap_ono].do_len[dap_obs[dap_ono].do_in[iv]])
	{
	case DBL:
	  dbltmp = dap_obs[dap_ono].do_dbl[dap_obs[dap_ono].do_in[iv]];
	  dap_obs[dap_ono].do_dbl[dap_obs[dap_ono].do_in[iv]] =
	    dap_prev[dap_ono].do_dbl[dap_obs[dap_ono].do_in[iv]];
	  dap_prev[dap_ono].do_dbl[dap_obs[dap_ono].do_in[iv]] = dbltmp;
	  if (dap_obs[dap_ono].do_dl[dap_obs[dap_ono].do_in[iv]])
	    *dap_obs[dap_ono].do_dl[dap_obs[dap_ono].do_in[iv]] =
	      dap_obs[dap_ono].do_dbl[dap_obs[dap_ono].do_in[iv]];
	  break;
	case INT:
	  inttmp = dap_obs[dap_ono].do_int[dap_obs[dap_ono].do_in[iv]];
	  dap_obs[dap_ono].do_int[dap_obs[dap_ono].do_in[iv]] =
	    dap_prev[dap_ono].do_int[dap_obs[dap_ono].do_in[iv]];
	  dap_prev[dap_ono].do_int[dap_obs[dap_ono].do_in[iv]] = inttmp;
	  if (dap_obs[dap_ono].do_il[dap_obs[dap_ono].do_in[iv]])
	    *dap_obs[dap_ono].do_il[dap_obs[dap_ono].do_in[iv]] =
	      dap_obs[dap_ono].do_int[dap_obs[dap_ono].do_in[iv]];
	  break;
	default:
	  so = dap_obs[dap_ono].do_str[dap_obs[dap_ono].do_in[iv]];
	  sp = dap_prev[dap_ono].do_str[dap_obs[dap_ono].do_in[iv]];
	  for (s = 0; s < dap_obs[dap_ono].do_len[dap_obs[dap_ono].do_in[iv]]; s++)
	    {
	      strtmp = so[s];
	      so[s] = sp[s];
	      sp[s] = strtmp;
	    }
	  break;
	}
    }
}

void dap_save()
{
  int iv;

  for (iv = 0; iv < dap_obs[dap_ono].do_ivar; iv++)
    {
      switch (dap_obs[dap_ono].do_len[dap_obs[dap_ono].do_in[iv]])
	{
	case DBL:
	  dosave.do_dbl[dap_obs[dap_ono].do_in[iv]] =
	    dap_obs[dap_ono].do_dbl[dap_obs[dap_ono].do_in[iv]];
	  break;
	case INT:
	  dosave.do_int[dap_obs[dap_ono].do_in[iv]] =
	    dap_obs[dap_ono].do_int[dap_obs[dap_ono].do_in[iv]];
	  break;
	default:
	  if (dosave.do_str[dap_obs[dap_ono].do_in[iv]])
	    dap_free(dosave.do_str[dap_obs[dap_ono].do_in[iv]],
		     "dap_save: dosave.do_str[dap_obs[dap_ono].do_in[iv]]");
	  dosave.do_str[dap_obs[dap_ono].do_in[iv]] =
	    dap_malloc(dap_obs[dap_ono].do_len[dap_obs[dap_ono].do_in[iv]] + 1,
		       "dap_save: dap_obs[dap_ono].do_nam[dap_obs[dap_ono].do_in[iv]]");
	  strncpy(dosave.do_str[dap_obs[dap_ono].do_in[iv]],
		  dap_obs[dap_ono].do_str[dap_obs[dap_ono].do_in[iv]],
		  dap_obs[dap_ono].do_len[dap_obs[dap_ono].do_in[iv]] + 1);
	  break;
	}
    }
}

void dap_rest()
{
  int iv;

  for (iv = 0; iv < dap_obs[dap_ono].do_ivar; iv++)
    {
      switch (dap_obs[dap_ono].do_len[dap_obs[dap_ono].do_in[iv]])
	{
	case DBL:
	  dap_obs[dap_ono].do_dbl[dap_obs[dap_ono].do_in[iv]] =
	    dosave.do_dbl[dap_obs[dap_ono].do_in[iv]];
	  if (dap_obs[dap_ono].do_dl[dap_obs[dap_ono].do_in[iv]])
	    *dap_obs[dap_ono].do_dl[dap_obs[dap_ono].do_in[iv]] =
	      dap_obs[dap_ono].do_dbl[dap_obs[dap_ono].do_in[iv]];
	  break;
	case INT:
	  dap_obs[dap_ono].do_int[dap_obs[dap_ono].do_in[iv]] =
	    dosave.do_int[dap_obs[dap_ono].do_in[iv]];
	  if (dap_obs[dap_ono].do_il[dap_obs[dap_ono].do_in[iv]])
	    *dap_obs[dap_ono].do_il[dap_obs[dap_ono].do_in[iv]] =
	      dap_obs[dap_ono].do_int[dap_obs[dap_ono].do_in[iv]];
	  break;
	default:
	  strncpy(dap_obs[dap_ono].do_str[dap_obs[dap_ono].do_in[iv]],
		  dosave.do_str[dap_obs[dap_ono].do_in[iv]],
		  dap_obs[dap_ono].do_len[dap_obs[dap_ono].do_in[iv]] + 1);
	  break;
	}
    }
}

long dap_ftell(DFILE *fp)
{
  if (fp->dfile_disk)
    return ftell(fp->dfile_disk);
  return fp->dfile_ram->rfile_pos - fp->dfile_ram->rfile_str;
}

void dap_mark()
{
  filepos[dap_ono] = dap_ftell(dap_in[dap_ono]);
}

static void dfseek(DFILE *fp, long pos, int mode)
{
  if (fp->dfile_disk)
    fseek(fp->dfile_disk, pos, mode);
  else
    {
      if (fp->dfile_ram->rfile_str + pos < fp->dfile_ram->rfile_end)
	fp->dfile_ram->rfile_pos = fp->dfile_ram->rfile_str + pos;
      else
	{
	  fprintf(dap_err, "(dfseek) seek past end of ramfile %s\n",
		  fp->dfile_name);
	  exit(1);
	}
    }
}

void dap_rewind()
{
  if (dap_in[dap_ono])
    {
      if (filepos[dap_ono] < dap_ftell(dap_in[dap_ono]))
	eof[dap_ono] = 0;
      dfseek(dap_in[dap_ono], filepos[dap_ono], SEEK_SET);
      dap_obs[dap_ono].do_valid = 0;
    }
  else
    {
      fprintf(dap_err, "(dap_rewind) file (%d) is closed.\n", dap_ono);
      exit(1);
    }
}

int dap_blank(char str[])
{
  int b;

  for (b = 0; str[b] == ' '; b++)
    ;
  if (str[b])
    return 0;
  return 1;
}

void skip(int nlines)
{
  char *line;

  line = dap_malloc(dap_linelen + 1, "skip: line");
  while (--nlines >= 0)
    {
      if (!dap_in[dap_ono] || eof[dap_ono])
	{
	  fprintf(dap_err, "(skip) tried to read past end of file (%d).\n",
		  dap_ono);
	  exit(1);
	}
      if (dap_getline(dap_in[dap_ono], line) < 0)
	eof[dap_ono] = 1;
      lineno[dap_ono]++;
    }
  dap_free(line, "skip: line");
}

int step()
{
  static int stepinit = 0; /* need to initialize "line" and "value" */
  static char *line = NULL; /* line read */
  static char *value = NULL;
  int v;				/* index to variables */
  int l;
  int i;
  int iv;
  int nread;	/* number of chars read by dap_getline */

  if (!stepinit)
    {
      stepinit = 1;
      line = dap_malloc(dap_linelen + 1, "step: line");
      value = dap_malloc(dap_linelen + 1, "step: value");
    }
  if (!dap_in[dap_ono] || eof[dap_ono])
    {
      fprintf(dap_err, "(step) ERROR: tried to read past end of file (%s).\n",
	      (dap_in[dap_ono] ? dap_in[dap_ono]->dfile_name : "?"));
      exit(1);
    }
  /* copy most recently read line to prev */
  for (iv = 0; iv < dap_obs[dap_ono].do_ivar; iv++)
    {
      switch (dap_obs[dap_ono].do_len[dap_obs[dap_ono].do_in[iv]])
	{
	case DBL:
	  dap_prev[dap_ono].do_dbl[dap_obs[dap_ono].do_in[iv]] =
	    dap_obs[dap_ono].do_dbl[dap_obs[dap_ono].do_in[iv]];
	  break;
	case INT:
	  dap_prev[dap_ono].do_int[dap_obs[dap_ono].do_in[iv]] =
	    dap_obs[dap_ono].do_int[dap_obs[dap_ono].do_in[iv]];
	  break;
	default:
	  strncpy(dap_prev[dap_ono].do_str[dap_obs[dap_ono].do_in[iv]],
		  dap_obs[dap_ono].do_str[dap_obs[dap_ono].do_in[iv]],
		  dap_obs[dap_ono].do_len[dap_obs[dap_ono].do_in[iv]] + 1);
	}
    }
  dap_prev[dap_ono].do_valid = dap_obs[dap_ono].do_valid;
  if ((nread = dap_getline(dap_in[dap_ono], line)) <= 0)
    {
      eof[dap_ono] = 1;
      dap_obs[dap_ono].do_valid = 0;
      fprintf(stderr, "(step) %d lines read from %s\n",
	      lineno[dap_ono] - 1, dap_in[dap_ono]->dfile_name);
      if (!nread)
	fputs("(step) WARNING: terminated on null line\n", stderr);
      fflush(stderr);
      fprintf(dap_log, "(step) %d lines read from  %s\n",
	      lineno[dap_ono] - 1, dap_in[dap_ono]->dfile_name);
      if (!nread)
	fputs("(step) WARNING: terminated on null line\n", dap_log);
      return 0;
    }
  if (nfields && dap_obs[dap_ono].do_ivar != nfields)
    {
      fprintf(dap_err,
	      "(step) ERROR: number of input variables %d different from number of fields specified %d for %s.\n",
	      dap_obs[dap_ono].do_ivar, nfields, dap_in[dap_ono]->dfile_name);
      exit(1);
    }
  /* convert input variables */
  for (v = 0, l = 0; v < dap_obs[dap_ono].do_ivar; v++)
    {
      if (nfields)
	{
	  for (i = 0; line[l + i] && i < fieldwd[v]; i++)
	    value[i] = line[l + i];
	  value[i] = '\0';
	  if (i < fieldwd[v])
	    {
	      fprintf(dap_log,
		      "(step (%s:%d)) ERROR: got %d of %d characters for fixed length field for %s: %s\n",
		      dap_in[dap_ono]->dfile_name,
		      lineno[dap_ono], i, fieldwd[v],
		      dap_obs[dap_ono].do_nam[dap_obs[dap_ono].do_in[v]],
		      value);
	      fprintf(dap_err,
		      "(step (%s:%d)) ERROR: got %d of %d characters for fixed length field for %s: %s\n",
		      dap_in[dap_ono]->dfile_name,
		      lineno[dap_ono], i, fieldwd[v],
		      dap_obs[dap_ono].do_nam[dap_obs[dap_ono].do_in[v]],
		      value);
	      exit(1);
	    }
	}
      else
	{
	  for (i = 0; line[l + i] && line[l + i] != dap_delim; i++)
	    value[i] = line[l + i];
	  value[i] = '\0';
	}
      if (dap_obs[dap_ono].do_len[dap_obs[dap_ono].do_in[v]] == INT)
	{
	  if (intype == DSET)
	    dap_obs[dap_ono].do_int[dap_obs[dap_ono].do_in[v]] = dap_getint(value);
	  else if (sscanf(value, " %d",
			  dap_obs[dap_ono].do_int + dap_obs[dap_ono].do_in[v]) != 1)
	    {
	      if (dap_blank(value))
		dap_obs[dap_ono].do_int[dap_obs[dap_ono].do_in[v]] = 0;
	      else
		{
		  fprintf(dap_err,
			  "(step (%s:%d)) ERROR: invalid integer data for %s: %s\n",
			  dap_in[dap_ono]->dfile_name,
			  lineno[dap_ono],
			  dap_obs[dap_ono].do_nam[dap_obs[dap_ono].do_in[v]],
			  value);
		  exit(1);
		}
	    }
	  /* if we're in an infile statement, may need to update the value
	   * from the value in the user's program
	   */
	  if (!dap_ono && dap_obs[dap_ono].do_il[dap_obs[0].do_in[v]])
	    *dap_obs[dap_ono].do_il[dap_obs[0].do_in[v]] =
	      dap_obs[0].do_int[dap_obs[0].do_in[v]];
	}
      else if (dap_obs[dap_ono].do_len[dap_obs[dap_ono].do_in[v]] == DBL)
	{
	  if (intype == DSET)
	    {
	      dap_getdouble(value);
	      dap_obs[dap_ono].do_dbl[dap_obs[dap_ono].do_in[v]] = dap_double;
	    }
	  else
	    {
	      if (!i || (nfields && dap_blank(value)) || !strcmp(value, "."))
		dap_obs[dap_ono].do_dbl[dap_obs[dap_ono].do_in[v]] = 0.0 / 0.0;
	      else if (sscanf(value, " %lf",
			      dap_obs[dap_ono].do_dbl + dap_obs[dap_ono].do_in[v]) != 1)
		{
		  fprintf(dap_err,
			  "(step (%s:%d)) ERROR: invalid double data for %s: %s\n",
			  dap_in[dap_ono]->dfile_name,
			  lineno[dap_ono],
			  dap_obs[dap_ono].do_nam[dap_obs[dap_ono].do_in[v]],
			  value);
		  exit(1);
		}
	    }
	  /* if we're in an infile statement, may need to update the value
	   * from the value in the user's program
	   */
	  if (!dap_ono && dap_obs[dap_ono].do_dl[dap_obs[0].do_in[v]])
	    *dap_obs[dap_ono].do_dl[dap_obs[0].do_in[v]] =
	      dap_obs[0].do_dbl[dap_obs[0].do_in[v]];
	}
      else
	{
	  if (i <= dap_obs[dap_ono].do_len[dap_obs[dap_ono].do_in[v]])
	    strcpy(dap_obs[dap_ono].do_str[dap_obs[dap_ono].do_in[v]], value);
	  else
	    {
	      strncpy(dap_obs[dap_ono].do_str[dap_obs[dap_ono].do_in[v]],
		      value, dap_obs[dap_ono].do_len[dap_obs[dap_ono].do_in[v]]);
	      dap_obs[dap_ono].do_str[dap_obs[dap_ono].do_in[v]]
		[dap_obs[dap_ono].do_len[dap_obs[dap_ono].do_in[v]]] = '\0';
	      if (toolong < dap_toolong)
		{
		  fprintf(dap_log,
			  "(step (%s:%d)) WARNING: string data too long (%d) for %s (%d): %s\n",
			  dap_in[dap_ono]->dfile_name,
			  lineno[dap_ono], i,
			  dap_obs[dap_ono].do_nam[dap_obs[dap_ono].do_in[v]],
			  dap_obs[dap_ono].do_len[dap_obs[dap_ono].do_in[v]],
			  value);
		  toolong++;
		}
	    }
	}
      l += i;
      if (!nfields && line[l] == dap_delim)
	l++;
    }
  dap_obs[dap_ono].do_valid = 1;
  lineno[dap_ono]++;
  return 1;
}

/* create new variable in dataobs
 * varspec = "name length" (may be repeated),
 *	where length = -1 for double, 0 for int, otherwise length of string
 * invar = is variable to be read from input dataset?
 */
int dap_vd(char *varspec, int invar)
{
  int s;		/* base index to varspec */
  int i;		/* supplemental index to varspec */
  char *varnam;	/* name of variable, extracted from varspec */
  int sign;	/* for getting negative number */
  int v;		/* index of variable */
  int vlen;	/* length parameter for variable */
  int redeclare;	/* is variable being redeclared? */

  v = -1;		/* non-existent until proven otherwise */
  varnam = dap_malloc(strlen(varspec), "dap_vd: varnam");	/* allocate string for names */
  for (s = 0; varspec[s] == ' '; )	/* skip leading spaces */
    s++;
  while (varspec[s])	/* while more specs to process */
    {
      if (dap_obs[dap_ono].do_nvar < dap_maxvar)
	{		/* is there room for another variable? */
	  /***** seems as though a redeclare shouldn't have to check this, not really
	   ***** a problem, but could waste some space
	   *****/
	  for (i = 0; varspec[s + i] && varspec[s + i] != ' '; i++)
	    varnam[i] = varspec[s + i];
	  varnam[i] = '\0';	/* name copied, i = length */
	  if ((v = dap_varnum(varnam)) < 0)
	    {	/* if it doesn't already exist */
	      redeclare = 0;	/* not being redeclared */
	      v = dap_obs[dap_ono].do_nvar;	/* its index is current nvar */
	      /* variable with that index is not being used, but entry may
	       * still have a name from before, so clear it
	       */
	      if (dap_obs[dap_ono].do_nam[v])
		dap_free(dap_obs[dap_ono].do_nam[v],
			 "dap_vd: dap_obs[dap_ono].do_nam[v]");
	      /* allocate space for new name */
	      dap_obs[dap_ono].do_nam[v] =
		dap_malloc(i + 1,
			   "dap_vd: dap_obs[dap_ono].do_nam[v]");
	      /* and enter the name */
	      strcpy(dap_obs[dap_ono].do_nam[v], varnam);
	      /* if it's going to be read from file, indicate in the
	       * do_in array and count
	       */
	      if (invar)
		dap_obs[dap_ono].do_in[dap_obs[dap_ono].do_ivar++] = v;
	    }
	  else
	    redeclare = 1;	/* variable already exists */
	  /* now get the length specification; first skip spaces, if any */
	  while (varspec[s + i] && varspec[s + i] == ' ')
	    i++;
	  if (!varspec[s + i])
	    {	/* ooops, nothing there */
	      fprintf(dap_err, "(dap_vd) missing variable length: %s\n",
		      varspec + s);
	      exit(1);
	    }
	  s += i;
	  if (varspec[s] == '-')
	    {	/* negative value */
	      sign = -1;
	      for (s++; varspec[s] == ' '; s++)
		;	/* skip spaces, if any */
	    }
	  else
	    sign = 1;	/* positive value */
	  /* now convert character string to integer */
	  for (i = 0, vlen = 0; '0' <= varspec[s + i] && varspec[s + i] <= '9'; i++)
	    vlen = 10 * vlen + varspec[s + i] - '0';
	  vlen *= sign;	/* and incorporate sign */
	  if (redeclare)
	    {	/* check that redeclaration doesn't change length */
	      if (dap_obs[dap_ono].do_len[v] != vlen)
		{
		  if (vlen > 0 && dap_obs[dap_ono].do_len[v] > 0)
		    fprintf(dap_err,
			    "(dap_vd) respecification of length of %s from %d to %d\n",
			    varnam, dap_obs[dap_ono].do_len[v] + 1, vlen + 1);
		  else
		    fprintf(dap_err,
			    "(dap_vd) respecification of type of %s\n",
			    varnam);
		  exit(1);
		}
	    }
	  else	/* for new declaration, use specified length */
	    dap_obs[dap_ono].do_len[v] = vlen;
	  if (varspec[s + i] && varspec[s + i] != ' ')
	    {	/* nothing should follow length but a space */
	      fprintf(dap_err,
		      "(dap_vd) invalid variable length for %s: %s\n",
		      varnam, varspec + s);
	      exit(1);
	    }
	  if (!redeclare && vlen > 0)
	    {	/* bookkeeping for setting up new string variable */
	      /* if it's not linked to "user" program name and there's
	       * a left-over string from previous use, free it
	       */
	      if (!dap_obs[dap_ono].do_sl[v] && dap_obs[dap_ono].do_str[v])
		dap_free(dap_obs[dap_ono].do_str[v],
			 "dap_vd: dap_obs[dap_ono].do_str[v]");
	      /* if need to free string from previous line dataobs, do it */
	      if (dap_ono < 2 && dap_prev[dap_ono].do_str[v])
		dap_free(dap_prev[dap_ono].do_str[v],
			 "dap_vd: dap_prev[dap_ono].do_str[v]");
	      /* allocate space for new string variable */
	      dap_obs[dap_ono].do_str[v] =
		dap_malloc(vlen + 1,
			   "dap_vd: dap_obs[dap_ono].do_str[v]");
	      /* indicate not linked to "user" program variable */
	      dap_obs[dap_ono].do_sl[v] = 0;
	      /* allocate space in previous line dataobs */
	      if (dap_ono < 2)
		dap_prev[dap_ono].do_str[v] =
		  dap_malloc(vlen + 1,
			     "dap_vd: dap_prev[dap_ono].do_str[v]");
	    }
	  if (vlen == DBL)	/* initialize doubles to NaN */
	    dap_obs[dap_ono].do_dbl[v] = 0.0 / 0.0;
	  else if (vlen == INT)	/* initialize ints to 0 */
	    dap_obs[dap_ono].do_int[v] = 0;
	  else			/* initialize strings to null */
	    dap_obs[dap_ono].do_str[v][0] = '\0';
	  s += i;		/* advance to next spec, if any */
	  while (varspec[s] == ' ')	/* and skip spaces */
	    s++;
	}
      else		/* no room for another variable */
	{
	  fprintf(dap_err, "(dap_vd) too many variables: %s\n", varspec + s);
	  exit(1);
	}
      if (!redeclare)		/* if not just redeclaration of one already there */
	dap_obs[dap_ono].do_nvar++;	/* update number of variables */
    }
  dap_free(varnam, "dap_vd: varnam");	/* free memory allocation */
  return v;		/* and return index of last (or only) variable */
}

/* link a double from a dataobs to "user" variable */
void dap_dl(char varname[], double *dbl)
{
  int v;
  int dim;
  int d;

  if ((v = dap_varnum(varname)) >= 0)
    {
      dap_obs[dap_ono].do_dl[v] = dbl;
      *dbl = 0.0 / 0.0;
    }
  else
    {
      if ((v = dap_arrnum(varname, &dim)) > 0)
	{
	  for (d = 0; d < dim; d++)
	    {
	      dap_obs[dap_ono].do_dl[v + d] = dbl + d;
	      dbl[d] = 0.0 / 0.0;
	    }
	}
      else
	{
	  fprintf(dap_err, "(dap_dl) unknown variable %s\n", varname);
	  exit(1);
	}
    }
}

/* link an int from a dataobs to "user" variable */
void dap_il(char varname[], int *i)
{
  int v;
  int dim;
  int d;

  if ((v = dap_varnum(varname)) > 0)
    {
      dap_obs[dap_ono].do_il[v] = i;
      *i = 0;
    }
  else
    {
      if ((v = dap_arrnum(varname, &dim)) > 0)
	{
	  for (d = 0; d < dim; d++)
	    {
	      dap_obs[dap_ono].do_il[v + d] = i + d;
	      i[d] = 0;
	    }
	}
      else
	{
	  fprintf(dap_err, "(dap_il) unknown variable %s\n", varname);
	  exit(1);
	}
    }
}

/* link a string from a dataobs to "user" variable */
void dap_sl(char varname[], char *s)
{
  int v;

  if ((v = dap_varnum(varname)) >= 0)
    {
      dap_free(dap_obs[dap_ono].do_str[v], "dap_sl: dap_obs[dap_ono].do_str[v]");
      dap_obs[dap_ono].do_str[v] = s;
      dap_obs[dap_ono].do_sl[v] = 1;
      s[0] = '\0';
    }
  else
    {
      fprintf(dap_err, "(dap_sl) unknown variable %s\n", varname);
      exit(1);
    }
}

void dap_name(char dname[], char *fname)
{
  struct stat statbuf;

  if (!fname || !fname[0])
    {
      strcpy(dname, "/dev/null");
      return;
    }
  strcpy(dname, dap_setdir);
  if (stat(dname, &statbuf) < 0)
    {
      if (mkdir(dname, (mode_t) 0700) < 0)
	{
	  perror(dap_dapname);
	  exit(1);
	}
    }
  else if (!(statbuf.st_mode & S_IFDIR))
    {
      fprintf(dap_err, "%s: non-directory file exists: %s\n", dap_dapname, dname);
      exit(1);
    }
  strcat(dname, "/");
  strcat(dname, fname);
}

static int dblcmp(double *d1, double *d2)
{
  if (*d1 < *d2)
    return -1;
  else if (*d1 > *d2)
    return 1;
  return 0;
}

static int intcmp(int *i1, int *i2)
{
  if (*i1 < *i2)
    return -1;
  else if (*i1 > *i2)
    return 1;
  return 0;
}

static int stcmp(char **s1, char **s2)
{
  return strcmp(*s1, *s2);
}

static int findlev(int class, double dlevel[], int ilevel[], char *slevel[], int nlevels)
{
  int v;

  if (dap_obs[dap_ono].do_len[class] == DBL)
    {
      for (v = 0; v < nlevels; v++)
	{	/* search for level */
	  if (dap_obs[dap_ono].do_dbl[class] ==
	      dlevel[v])
	    break;
	}
    }
  else if (dap_obs[dap_ono].do_len[class] == INT)
    {
      for (v = 0; v < nlevels; v++)
	{	/* search for level */
	  if (dap_obs[dap_ono].do_int[class] ==
	      ilevel[v])
	    break;
	}
    }
  else
    {
      for (v = 0; v < nlevels; v++)
	{	/* search for level */
	  if (!strcmp(dap_obs[dap_ono].do_str[class],
		      slevel[v]))
	    break;
	}
    }
  if (v < nlevels)
    return v;
  return -1;
}

int inclev(int lev[], int nlevels[], int nclass)
{
  int c;

  for (c = nclass - 1; c >= 0; --c)
    {
      if (lev[c] < nlevels[c] - 1)	/* not maxed out */
	break;
    }
  if (c < 0)	/* all maxed out */
    return 0;
  lev[c]++;
  while (++c < nclass)
    lev[c] = 0;
  return 1;
}

/* This grab-bag function is way too big, should be broken up
 * into functions that perform each action
 */
void dataset(char oldname[], char newname[], char action[])
{
  static int datsetinit = 0;	/* need to initialize 'baseobs' on first call */
  char *dold, *dnew;		/* oldname, newname with directory prepended */
  int fold, fnew;			/* file numbers for memory files */
  DFILE *doldf, *dnewf;
  int c;				/* index for various purposes (ouch!) */
  int v;				/* index for various purposes (ouch!) */
  int onum;
  int maxnamlen;			/* max length of variable name in dataset */
  static dataobs baseobs;		/* dataobs for append */
  char *varspec;
  char *oldvmem;
  char *newvmem;
  char **oldvar;
  char **newvar;
  int nvar;		/* number of variables in action for COPY */
  int ncell, nclass;	/* number of cell, class variables for FILL */
  char *celllist;		/* list of cell, class variables for FILL */
  int *cellv, *classv;	/* indices of variables for FILL */
  char **slevelmem;	/* for storing ptrs to names of the levels of the string class vars */
  char ***slevel;		/* pointers to the level names */
  double *dlevelmem;	/* for storing values of the levels of the double class vars */
  double **dlevel;	/* pointers to the double level values */
  int *ilevelmem;		/* for storing values of the levels of the int class vars */
  int **ilevel;		/* pointers to the int level values */
  int *inlev;		/* current level read in for each class var */
  int *outlev;		/* current level written out for each class var */
  int *nlevels;		/* number of levels for each class var */
  int (*dcmp)() = &dblcmp;	/* to trick the compiler? */
  int (*icmp)() = &intcmp;	/* to trick the compiler? */
  int (*scmp)() = &stcmp;		/* to trick the compiler? */
  int vn, nv;
  int dim, ndim;
  char *outlist;
  static char dimstr[7];	/* depends on dap_maxvar <= 10,000 */
  int *clearvar;		/* indices of variables to clear in APPEND */
  int nclear;		/* number of variables to clear */

  if (!datsetinit)	/* need to allocate and initiate baseobs? */
    {
      datsetinit = 1;
      initdo(&baseobs);
    }
  if (dap_in[0])		/* if input file left hanging... */
    {		/* ... finish it up */
      dfclose(dap_in[0]);
      dap_in[0] = (DFILE *) NULL;
    }
  if (dap_out[0])		/* if output file left hanging... */
    {		/* ... finish it up */
      dfclose(dap_out[0]);
      dap_out[0] = (DFILE *) NULL;
    }
  celllist = (char *) NULL;	/* to prevent freeing if not assigned */
  slevelmem = (char **) NULL;	/* to prevent freeing if not assigned */
  cellv = (int *) NULL;		/* to prevent freeing if not assigned */
  classv = (int *) NULL;		/* to prevent freeing if not assigned */
  outlist = dap_malloc(dap_listlen, "dataset: outlist");
  oldvmem = dap_malloc(dap_maxvar * (dap_namelen + 1), "dataset: oldvmem");
  oldvar = (char **) dap_malloc(sizeof(char *) * dap_maxvar, "dataset: oldvar");
  for (v = 0; v < dap_maxvar; v++)
    oldvar[v] = oldvmem + v * (dap_namelen + 1);
  newvmem = dap_malloc(dap_maxvar * (dap_namelen + 1), "dataset: newvmem");
  newvar = (char **) dap_malloc(sizeof(char *) * dap_maxvar, "dataset: newvar");
  for (v = 0; v < dap_maxvar; v++)
    newvar[v] = newvmem + v * (dap_namelen + 1);
  dold = dap_malloc(strlen(oldname) + strlen(dap_setdir) + 2, "dataset: dold");
  dnew = dap_malloc(strlen(newname) + strlen(dap_setdir) + 2, "dataset: dnew");
  dap_name(dold, oldname);	/* set up dataset names */
  dap_name(dnew, newname);
  clearvar = NULL;
  if (!strcmp(action, "RENAME"))
    {
      if (oldname[0] == '<')
	{
	  if (newname[0] == '<')
	    {
	      for (fold = 0; fold < dap_nrfiles; fold++)
		{
		  if (!strcmp(dfile[NDFILES + fold].dfile_name, oldname + 1))
		    break;
		}
	      if (fold < dap_nrfiles)
		{
		  for (fnew = 0; fnew < dap_nrfiles; fnew++)
		    {
		      if (!strcmp(dfile[NDFILES + fnew].dfile_name,
				  newname + 1))
			break;
		    }
		  if (fnew < dap_nrfiles)
		    dfile[NDFILES + fnew].dfile_name[0] = '\0';
		  strcpy(dfile[NDFILES + fold].dfile_name, newname + 1);
		}
	      else
		{
		  fprintf(dap_err,
			  "(dataset) can't find ramfile %s\n", oldname);
		  exit(1);
		}
	    }
	  else
	    {
	      fprintf(dap_err,
		      "(dataset) can't rename ramfile %s to disk file %s\n",
		      oldname, newname);
	      exit(1);
	    }
	}
      else if (newname[0] == '<')
	{
	  fprintf(dap_err, "(dataset) can't rename disk file %s to ramfile %s\n",
		  oldname, newname);
	  exit(1);
	}
      else
	rename(dold, dnew);
    }
  else if (!strncmp(action, "COPY", 4))
    {
      for (v = 4; action[v] == ' '; v++)	/* get past COPY */
	;
      for (nvar = 0; action[v]; nvar++)
	{
	  for (c = 0; action[v] && action[v] != ' ' && action[v] != '>'; )
	    {
	      if (c < dap_namelen)
		oldvar[nvar][c++] = action[v++];
	      else
		{
		  fprintf(dap_err, "(dataset) variable name too long: %s\n",
			  action);
		  exit(1);
		}
	    }
	  oldvar[nvar][c] = '\0';		/* now oldvar[nvar] is named variable */
	  while (action[v] == ' ')
	    v++;
	  if (action[v] == '>')		/* if changing name */
	    {
	      for (v++; action[v] == ' '; v++)
		;
	      for (c = 0; action[v] && action[v] != ' '; )
		{
		  if (c < dap_namelen)
		    newvar[nvar][c++] = action[v++];
		  else
		    {
		      fprintf(dap_err,
			      "(dataset) new variable name too long: %s\n",
			      action);
		      exit(1);
		    }
		}
	      newvar[nvar][c] = '\0';	/* now newvar[nvar] is new name */
	      while (action[v] == ' ')
		v++;
	    }
	  else
	    strcpy(newvar[nvar], oldvar[nvar]);
	}
      if (nvar)		/* if there are variables to copy */
	{
	  inset(oldname);
	  for (v = 0, outlist[0] = '\0'; v < nvar; v++)
	    {
	      if (v)
		strcat(outlist, " ");
	      strcat(outlist, newvar[v]);	/* output list has newvars */
	      if (strcmp(oldvar[v], newvar[v]))	/* if changing name */
		{
		  if ((vn = dap_varnum(oldvar[v])) >= 0)
		    {
				/* if newvar exists in oldname, zap its first char to '0' */
		      if ((nv = dap_varnum(newvar[v])) >= 0)
			dap_obs[0].do_nam[nv][0] = '0';
				/* and change the name of oldvar to newvar */
		      dap_free(dap_obs[0].do_nam[vn],
			       "dataset: dap_obs[0].do_nam[vn]");
		      dap_obs[0].do_nam[vn] =
			dap_malloc(strlen(newvar[v]) + 1,
				   "dataset: dap_obs[0].do_nam[vn]");
		      strcpy(dap_obs[0].do_nam[vn], newvar[v]);
		    }
		  else if ((vn = dap_arrnum(oldvar[v], &dim)) >= 0)
		    {
				/* do the same for arrays */
		      if ((nv = dap_arrnum(newvar[v], &ndim)) >= 0)
			{
			  for (c = 0; c < ndim; c++)
			    {
			      dap_obs[0].do_nam[nv + c][0] = '0';
			      sprintf(dimstr, "[%d]", c);
			      strcat(dap_obs[0].do_nam[vn + c], dimstr);
			    }
			}
		      for (c = 0; c < dim; c++)
			{
			  sprintf(dimstr, "[%d]", c);
			  dap_free(dap_obs[0].do_nam[vn + c],
				   "dataset: dap_obs[0].do_nam[vn + c]");
			  dap_obs[0].do_nam[vn + c] =
			    dap_malloc(strlen(newvar[v]) +
				       strlen(dimstr) + 1,
				       "dataset: dap_obs[0].do_nam[vn + c]");
			  strcpy(dap_obs[0].do_nam[vn + c], newvar[v]);
			  strcat(dap_obs[0].do_nam[vn + c], dimstr);
			}
		    }
		  else
		    {
		      fprintf(dap_err, "(dataset) unknown variable %s\n",
			      oldvar[v]);
		      exit(1);
		    }
		}
	    }
	  outset(newname, outlist);
	  while (step())
	    output();
	}
      else
	{
	  if (!(doldf = dfopen(oldname, "r")))
	    {
	      fprintf(dap_err, "(dataset) can't read %s for copy.\n",
		      oldname);
	      exit(1);
	    }
	  if (!(dnewf = dfopen(newname, "w")))
	    {
	      fprintf(dap_err, "(dataset) can't write %s for copy.\n",
		      newname);
	      exit(1);
	    }
	  while ((c = dgetc(doldf)) != EOF)
	    dap_putc(c, dnewf);
	  dfclose(dnewf);
	  dfclose(doldf);
	}
    }
  else if (!strncmp(action, "FILL", 4))
    {
      inset(oldname);
      /* make copy of cell variable names for dap_list */
      celllist = dap_malloc(strlen(action), "dataset: celllist");
      for (v = 4, c = 0; action[v] && action[v] != ':'; )	/* get to : */
	celllist[c++] = action[v++];
      celllist[c] = '\0';
      if (!action[v])
	{
	  fprintf(dap_err,
		  "(dataset) missing ':' between variable lists in %s\n", action);
	  exit(1);
	}
      ncell = c / 2;	/* tentative, overestimate */
      cellv = (int *) dap_malloc(sizeof(int) * ncell, "dataset: cellv");
      ncell = dap_list(celllist, cellv, ncell);
      nclass = (strlen(action) - v) / 2;	/* tentative, overestimate */
      classv = (int *) dap_malloc(sizeof(int) * nclass, "dataset: classv");
      nclass = dap_list(action + v + 1, classv, nclass);
      inlev = (int *) dap_malloc(sizeof(int) * nclass, "dataset: inlev");
      outlev = (int *) dap_malloc(sizeof(int) * nclass, "dataset: outlev");
      slevelmem = (char **) dap_malloc(sizeof(char *) * nclass * dap_maxlev,
				       "dataset: slevelmem");
      slevel = (char ***) dap_malloc(sizeof(char **) * nclass, "dataset: slevel");
      dlevelmem = (double *) dap_malloc(sizeof(double) * nclass * dap_maxlev,
					"dataset: dlevelmem");
      dlevel = (double **) dap_malloc(sizeof(double *) * nclass,
				      "dataset: dlevel");
      ilevelmem = (int *) dap_malloc(sizeof(int) * nclass * dap_maxlev,
				     "dataset: ilevelmem");
      ilevel = (int **) dap_malloc(sizeof(int *) * nclass, "dataset: ilevel");
      nlevels = (int *) dap_malloc(sizeof(int) * nclass, "dataset: nlevels");
      for (c = 0; c < nclass; c++)
	{
	  slevel[c] = slevelmem + c * dap_maxlev;
	  dlevel[c] = dlevelmem + c * dap_maxlev;
	  ilevel[c] = ilevelmem + c * dap_maxlev;
	}
      outset(newname, "");
      for (c = 0; c < nclass; c++)	/* start with empty level lists */
	nlevels[c] = 0;
      for (dap_mark(); step(); )
	{
	  for (c = 0; c < nclass; c++)
	    {
	      if ((v = findlev(classv[c],
			       dlevel[c], ilevel[c], slevel[c], nlevels[c])) < 0)
		{	/* if not found */
		  if (nlevels[c] < dap_maxlev)
		    {
		      if (dap_obs[dap_ono].do_len[classv[c]] == DBL)
			{
			  dlevel[c][nlevels[c]++] =
			    dap_obs[dap_ono].do_dbl[classv[c]];
			}
		      else if (dap_obs[dap_ono].do_len[classv[c]] == INT)
			{
			  ilevel[c][nlevels[c]++] =
			    dap_obs[dap_ono].do_int[classv[c]];
			}
		      else
			{
			  slevel[c][nlevels[c]] =
			    dap_malloc(strlen(dap_obs[dap_ono].do_str[classv[c]]) + 1,
				       "dataset: slevel[c][nlevels[c]]");
			  strcpy(slevel[c][nlevels[c]++],
				 dap_obs[dap_ono].do_str[classv[c]]);
			}
		    }
		  else
		    {
		      fprintf(dap_err,
			      "(dataset) too many levels for \%s\n",
			      dap_obs[dap_ono].do_nam[classv[c]]);
		      exit(1);
		    }
		}
	    }
	}
      for (c = 0; c < nclass; c++)
	{
	  if (dap_obs[dap_ono].do_len[classv[c]] == DBL)
	    qsort(dlevel[c], nlevels[c], sizeof(double), dcmp);
	  else if (dap_obs[dap_ono].do_len[classv[c]] == INT)
	    qsort(ilevel[c], nlevels[c], sizeof(int), icmp);
	  else
	    qsort(slevel[c], nlevels[c], sizeof(char *), scmp);
	  outlev[c] = 0;
	}
      dap_rewind();	/* go back to beginning of part */
      while (step())
	{
	  for (c = 0; c < nclass; c++)
	    {
	      inlev[c] = findlev(classv[c], dlevel[c], ilevel[c], slevel[c],
				 nlevels[c]);
	    }
	  for (c = 0; c < nclass; c++)
	    {
	      if (outlev[c] < inlev[c])
		break;
	    }
	  if (c < nclass)	/* skipped values for class c */
	    {
	      dap_save();
	      for (v = 0; v < ncell; v++)	/* set cell vals */
		{	/* set values to 0.0, 0, or "" */
		  if (dap_obs[dap_ono].do_len[cellv[v]] == DBL)
		    dap_obs[dap_ono].do_dbl[cellv[v]] = 0.0;
		  else if (dap_obs[dap_ono].do_len[cellv[v]] == INT)
		    dap_obs[dap_ono].do_int[cellv[v]] = 0;
		  else
		    dap_obs[dap_ono].do_str[cellv[v]][0] = '\0';
		}
	      do	{
		for (c = 0; c < nclass; c++)
		  {
		    if (outlev[c] < inlev[c])
		      break;
		  }
		if (c == nclass)	/* caught up */
		  break;
		for (v = c; v < nclass; v++)
		  {
		    if (dap_obs[dap_ono].do_len[classv[v]] == DBL)
		      dap_obs[dap_ono].do_dbl[classv[v]] =
			dlevel[v][outlev[v]];
		    else if (dap_obs[dap_ono].do_len[classv[v]] == INT)
		      dap_obs[dap_ono].do_int[classv[v]] =
			ilevel[v][outlev[v]];
		    else
		      strcpy(dap_obs[dap_ono].do_str[classv[v]],
			     slevel[v][outlev[v]]);
		  }
		output();
	      } while (inclev(outlev, nlevels, nclass));
	      dap_rest();
	    }
	  output();
	  inclev(outlev, nlevels, nclass);
	}
      for (c = 0; c < nclass; c++)	/* empty the level lists */
	{
	  for (v = 0; v < nlevels[c]; v++)
	    {
	      if (dap_obs[dap_ono].do_len[classv[c]] > 0)
		dap_free(slevel[c][v], "dataset: slevel[c][v]");
	    }
	  nlevels[c] = 0;
	}
    }
  else if (!strcmp(action, "REMOVE"))
    {
      if (oldname[0] == '<')
	{
	  for (fold = 0; fold < dap_nrfiles; fold++)
	    {
	      if (!strcmp(dfile[NDFILES + fold].dfile_name, oldname + 1))
		{
		  dap_free(dfile[NDFILES + fold].dfile_name,
			   "dataset: dfile[NDFILES + fold].dfile_name");
		  dfile[NDFILES + fold].dfile_name = NULL;
		  dap_free(rfile[fold].rfile_str,
			   "dataset: rfile[fold].rfile_str");
		  break;
		}
	    }
	}
      else
	unlink(dold);
    }
  else if (!strcmp(action, "APPEND"))
    {
      if (!(dap_out[0] = dfopen(newname, "r")))	/* no dataset to append to... */
	{				/* ...so just copy. */
	  if (!(dap_out[0] = dfopen(newname, "w")))
	    {
	      fprintf(dap_err,
		      "(dataset) Can't create new data set for append: %s\n",
		      newname);
	      exit(1);
	    }
	  if (!(dap_in[0] = dfopen(oldname, "r")))
	    {
	      fprintf(dap_err,
		      "(dataset) can't read old data set for append: %s\n",
		      oldname);
	      exit(1);
	    }
	  while ((c = dgetc(dap_in[0])) != EOF)
	    dap_putc(c, dap_out[0]);
	  dfclose(dap_in[0]);
	  dap_in[0] = (DFILE *) NULL;
	  dfclose(dap_out[0]);
	  dap_out[0] = (DFILE *) NULL;
	  return;
	}
      else				/* really append */
	{
	  inset(newname);			/* to get variable list */
	  outset("dap_null", "");		/* so don't output anywhere */
	  baseobs.do_nvar = dap_obs[0].do_nvar;	/* save newname's nvar */
	  for (v = 0; v < baseobs.do_nvar; v++)
	    {			/* copy names, lens from newname */
	      baseobs.do_len[v] = dap_obs[0].do_len[v];
	      baseobs.do_nam[v] = dap_malloc(strlen(dap_obs[0].do_nam[v]) + 1,
					     "dataset: baseobs.do_nam[v]");
	      strcpy(baseobs.do_nam[v], dap_obs[0].do_nam[v]);
	    }
	  dfclose(dap_out[0]);
	  dap_out[0] = (DFILE *) NULL;
	  inset(oldname);		/* open "old" dataset to append to newname */
	  dap_obs[0].do_ovar = 0;
	  for (v = 0, maxnamlen = 0; v < baseobs.do_nvar; v++)
	    {		/* find longest name length in newname */
	      if (maxnamlen < strlen(baseobs.do_nam[v]))
		maxnamlen = strlen(baseobs.do_nam[v]);
	    }
	  /* set up for specification for declaration of those variables in
	   * newname that are not in oldname
	   */
	  varspec = dap_malloc(maxnamlen + dap_intlen + 2,
			       "dataset: varspec");
	  clearvar = (int *) dap_malloc(sizeof(int) * baseobs.do_nvar,
					"dataset: clearvar");
	  for (v = 0, nclear = 0; v < baseobs.do_nvar; v++)
	    {
	      if ((onum = dap_varnum(baseobs.do_nam[v])) < 0)
		{	/* get index in oldname */
				/* if none give it newname's specs for it */
		  sprintf(varspec, "%s %d", baseobs.do_nam[v],
			  baseobs.do_len[v]);
		  onum = dap_vd(varspec, 0);
				/* mark for setting to "", 0, and 0.0 */
		  clearvar[nclear++] = onum;
		}
	      else		/* if it's there, check type, len */
		{
		  if (dap_obs[0].do_len[onum] != baseobs.do_len[v])
		    {
		      fprintf(stderr,
			      "(dataset) variable %s has different lengths (%d appended to %d) in datasets\n",
			      baseobs.do_nam[v], dap_obs[0].do_len[onum],
			      baseobs.do_len[v]);
		      exit(1);
		    }
		}
	      dap_obs[0].do_out[dap_obs[0].do_ovar++] = onum;
	    }
	  if (!(dap_out[0] = dfopen(newname, "a")))
	    {
	      fprintf(dap_err, "(dataset) can't append to new data set: %s\n",
		      newname);
	      exit(1);
	    }
	  while (step())
	    {
	      /* and set to "", 0, and 0.0 */
	      for (v = 0; v < nclear; v++)
		{
		  if (dap_obs[0].do_str[clearvar[v]])
		    dap_obs[0].do_str[clearvar[v]][0] = '\0';
		  dap_obs[0].do_sl[clearvar[v]] = 0;
		  dap_obs[0].do_int[clearvar[v]] = 0;
		  dap_obs[0].do_dbl[clearvar[v]] = 0.0;
		}
	      output();
	    }
	  for (v = 0; v < baseobs.do_nvar; v++)
	    {
	      dap_free(baseobs.do_nam[v], "dataset: baseobs.do_nam[v]");
	      baseobs.do_nam[v] = NULL;
	    }
	  dap_free(varspec, "dataset: varspec");
	}
    }
  else
    {
      fprintf(dap_err, "(dataset) unknown action: %s\n", action);
      exit(1);
    }
  dap_free(dold, "dataset: dold");
  dap_free(dnew, "dataset: dnew");
  dap_free(oldvmem, "dataset: oldvmem");
  dap_free(oldvar, "dataset: oldvar");
  dap_free(newvmem, "dataset: newvmem");
  dap_free(newvar, "dataset: newvar");
  dap_free(outlist, "dataset: outlist");
  if (clearvar)
    dap_free(clearvar, "dataset: clearvar");
  if (celllist)
    dap_free(celllist, "dataset: celllist");
  if (cellv)
    dap_free(cellv, "dataset: cellv");
  if (classv)
    dap_free(classv, "dataset: classv");
  if (slevelmem)	/* all of these allocated for FILL */
    {
      dap_free(slevelmem, "dataset: slevelmem");
      dap_free(slevel, "dataset: slevel");
      dap_free(dlevelmem, "dataset: dlevelmem");
      dap_free(dlevel, "dataset: dlevel");
      dap_free(ilevelmem, "dataset: ilevelmem");
      dap_free(ilevel, "dataset: ilevel");
      dap_free(inlev, "dataset: inlev");
      dap_free(outlev, "dataset: outlev");
      dap_free(nlevels, "dataset: nlevels");
    }
}

#define BLOCKLEN 32

static int getblock(DFILE *fp)
{
  char block[BLOCKLEN];
  int b;

  if ((block[0] = dgetc(fp)) == '\r')
    return 0;
  for (b = 1; b < BLOCKLEN; b++)
    block[b] = dgetc(fp);
  return (block[16] & 0xff);
}

int dap_clearobs(char *varspec)
{
  int v;

  if (dap_ono < 2)
    {
      dap_prev[dap_ono].do_ivar = 0;
      eof[dap_ono] = 0;
      for (v = 0; v < dap_maxvar; v++)
	{
	  if (dap_prev[dap_ono].do_str[v])
	    dap_free(dap_prev[dap_ono].do_str[v],
		     "clearobs: dap_prev[dap_ono].do_str[v]");
	  dap_prev[dap_ono].do_str[v] = NULL;
	}
    }
  dap_obs[dap_ono].do_ivar = 0;
  dap_obs[dap_ono].do_ovar = 0;
  dap_obs[dap_ono].do_nvar = 0;
  dap_obs[dap_ono].do_valid = 0;
  for (v = 0; v < dap_maxvar; v++)
    {
      if (dap_obs[dap_ono].do_nam[v])
	dap_free(dap_obs[dap_ono].do_nam[v],
		 "clearobs: dap_obs[dap_ono].do_nam[v]");
      dap_obs[dap_ono].do_nam[v] = NULL;
      dap_obs[dap_ono].do_dl[v] = NULL;
      dap_obs[dap_ono].do_il[v] = NULL;
      if (!dap_obs[dap_ono].do_sl[v] && dap_obs[dap_ono].do_str[v])
	dap_free(dap_obs[dap_ono].do_str[v],
		 "clearobs: dap_obs[dap_ono].do_str[v]");
      dap_obs[dap_ono].do_str[v] = NULL;
      dap_obs[dap_ono].do_sl[v] = 0;
    }
  if (varspec)
    dap_vd(varspec, 1);
  else
    dap_vd("_type_ 8", 0);
  if ((v = dap_varnum("_type_")) < 0)
    {
      fputs("(clearobs) missing _type_ variable\n", dap_err);
      exit(1);
    }
  dap_obs[dap_ono].do_out[dap_obs[dap_ono].do_ovar++] = v;
  return v;
}

void infile(char *ifname, char *idelim)
{
  static int infinit = 0;
  int v;
  int d;
  int infldlen;
  char *fname;
  static char *delim;
  static int delimlen;
  
  if (!infinit)
    {
      infinit = 1;
      delimlen = (dap_linelen + 1) / 8 - 1;
      delim = dap_malloc(delimlen + 1, "infile: delim");
      fieldwd = (int *) dap_malloc(sizeof(int) * dap_maxvar, "infile: fieldwd");
    }
    
  if (dap_in[dap_ono])
    {
      dfclose(dap_in[dap_ono]);
      dap_in[dap_ono] = (DFILE *) NULL;
    }
  if (dap_out[dap_ono])
    {
      dfclose(dap_out[dap_ono]);
      dap_out[dap_ono] = (DFILE *) NULL;
    }
  if (!ifname || !ifname[0])
    {
      fname = "/dev/null";
      strcpy(delim, "|");
    }
  else
    {
      fname = ifname;
      if (!idelim || !idelim[0])
	{
	  fprintf(dap_err,
		  "(infile) Delimiter string must be at least one character: %s\n",
		  delim);
	  exit(1);
	}
      else if (strlen(idelim) <= delimlen)
	strcpy(delim, idelim);
      else
	{
	  fprintf(dap_err,
		  "(infile) Delimiter string too long: %s\n", idelim);
	  exit(1);
	}
    }
    
  /* the 'f' says that it's not a dataset, so don't need to prepend directory */
  if (!(dap_in[dap_ono] = dfopen(fname, "rf")))
    {
      fprintf(dap_err, "(infile) can't read data file: %s\n", fname);
      exit(1);
    }
  intype = TEXT;
  if (!strcmp(fname + strlen(fname) - 4, ".dbf"))
    {
      intype = DBASE;
      getblock(dap_in[dap_ono]);     /* dump header */
      for (inlen = 0; (infldlen = getblock(dap_in[dap_ono])); inlen += infldlen)
	;
    }
  dap_delim = delim[0];
    
  for (nfields = 0, d = 1; delim[d]; nfields++)
    {
	    
      if (nfields < dap_maxvar)
	{
	  for (fieldwd[nfields] = 0; delim[d] && delim[d] != dap_delim; )
	  {
	    fieldwd[nfields] = 10 * fieldwd[nfields] + delim[d++] - '0';
	  }
	  if (delim[d])
	    d++;
	}
      else
	{
	  fputs("(infile) too many field width specifiers.\n", dap_err);
	  exit(1);
	}
    }
    
  v = dap_clearobs((char *) NULL);
  strcpy(dap_obs[dap_ono].do_str[v], "OBS");
  lineno[dap_ono] = 1;
  toolong = 0;
    
}

void input(char varlist[])
{
  int v;
  int l;
  int i;
  static char *vname = NULL;
  int dim;
  int d;

  if (!vname)
    vname = dap_malloc(dap_namelen + 1, "input: vname");
  for (l = 0; varlist[l] == ' '; l++)
    ;
  while (varlist[l])
    {
      for (i = 0; varlist[l + i] && varlist[l + i] != ' '; i++)
	{
	  if (i < dap_namelen)
	    vname[i] = varlist[l + i];
	  else
	    {
	      vname[i] = '\0';
	      fprintf(dap_err, "(input) variable name too long: %s\n", vname);
	      exit(1);
	    }
	}
      vname[i] = '\0';
      if ((v = dap_varnum(vname)) >= 0)
	dap_obs[dap_ono].do_in[dap_obs[dap_ono].do_ivar++] = v;
      else if ((v = dap_arrnum(vname, &dim)) >= 0)
	{
	  for (d = 0; d < dim; d++)
	    dap_obs[dap_ono].do_in[dap_obs[dap_ono].do_ivar++] = v + d;
	}
      else
	{
	  fprintf(dap_err, "(input) unknown variable: %s\n", vname);
	  exit(1);
	}
      l += i;
      while (varlist[l] == ' ')
	l++;
    }
}

/* open an input dataset named fname; if fname is NULL, just close the open input dataset */
void inset(char *fname)
{
  int v;
  static char *varspec = NULL;
  double testd;

  if (!varspec)
    varspec = dap_malloc(dap_linelen + 1, "inset: varspec");
  if (dap_in[dap_ono])
    {
      dfclose(dap_in[dap_ono]);
      dap_in[dap_ono] = (DFILE *) NULL;
    }
  if (dap_out[dap_ono])
    {
      dfclose(dap_out[dap_ono]);
      dap_out[dap_ono] = (DFILE *) NULL;
    }
  if (!fname)
    return;
  if (!(dap_in[dap_ono] = dfopen(fname, "r")))
    {
      fprintf(dap_err, "(inset) can't read data set: %s\n", fname);
      exit(1);
    }
  intype = DSET;
  dap_delim = '\0';
  if (dap_getline(dap_in[dap_ono], varspec) < 0)
    {
      fprintf(dap_err, "(inset) data set empty: %s\n", fname);
      exit(1);
    }
  nfields = 0;
  dap_clearobs(varspec);
  dap_delim = SETDELIM;
  lineno[dap_ono] = 1;
}

/* Remove bracketed indices from explicit entry references
 * but do not create duplications of variable names
 */
static void fixlist(char *varl, char *varlist)
{
  static int fixinit = 0;
  int l;			/* index to var lists */
  int f;
  int inbrack;
  static char *vname;
  int dim;
  static int *outv;
  int l0;
  int l1;
  int f1;
  int nv;
  int v;
  int vn;

  if (!fixinit)
    {
      fixinit = 1;
      vname = dap_malloc(dap_namelen + 1, "fixlist: vname");
      outv = (int *) dap_malloc(sizeof(int) * dap_maxvar, "fixlist: outv");
    }
  if (!varl)
    {
      fputs("(fixlist) missing variable list.\n", dap_err);
      exit(1);
    }
  if (!varlist)
    {
      fputs("(fixlist) missing string for fixed variable list.\n", dap_err);
      exit(1);
    }
  /* First copy varl to varlist, eliminating bracketed indices */
  for (inbrack = 0, l = 0, f = 0; varl[l]; l++)
    {
      if (inbrack)
	{
	  if (varl[l] == ']')
	    inbrack = 0;
	}
      else if (varl[l] == '[')
	inbrack = 1;
      else
	varlist[f++] = varl[l];
    }
  varlist[f] = '\0';
  for (l = 0; varlist[l] == ' '; l++)
    ;
  l0 = 0;
  if (varlist[l] == '!')
    {
      for (l++; varlist[l] == ' '; l++)
	;
      varlist[l0++] = '!';
    }
  for (nv = 0, l1 = l0; varlist[l]; )
    {
      for (f = 0; varlist[l + f] && varlist[l + f] != ' '; f++)
	{
	  if (f < dap_namelen)
	    vname[f] = varlist[l + f];
	  else
	    {
	      vname[f] = '\0';
	      fprintf(dap_err, "(fixlist) variable name too long: %s\n", vname);
	      exit(1);
	    }
	}
      vname[f] = '\0';
      if (((v = dap_varnum(vname)) < 0) && ((v = dap_arrnum(vname, &dim)) < 0))
	{
	  fprintf(dap_err, "(fixlist) unknown variable: %s\n", vname);
	  exit(1);
	}
      for (vn = 0; vn < nv; vn++)	/* see if variable already appeared */
	{
	  if (outv[vn] == v)
	    break;
	}
      if (vn == nv)				/* if not */
	{
	  outv[nv++] = v;			/* enter it in list of indices */
	  if (l1 > l0)
	    varlist[l1++] = ' ';
	  for (f1 = 0; f1 < f; f1++)	/* copy name from varlist to varlist */
	    varlist[l1++] = varlist[l++];
	}
      else
	l += f;
      while (varlist[l] == ' ')
	l++;
    }
  varlist[l1] = '\0';
}

/* Set name and variables of output dataset
 * varl = list of variables to include except that if it has '!' before
 *	the variable names, then the variables are to be excluded instead
 */
void outset(char *fname, char *varl)
{
  static int outinit = 0;	/* initialized data for outset? */
  int l;
  int i;
  static char *varlist;
  static char *vname;
  int v;
  int w;
  int first;
  int dim;
  int d;
  double testd;

  if (dap_out[dap_ono])
    {
      dfclose(dap_out[dap_ono]);
      dap_out[dap_ono] = (DFILE *) NULL;
    }
  if (!fname)
    {
      fputs("(outset) no dataset name.\n", dap_err);
      exit(1);
    }
  if (!outinit)
    {
      outinit = 1;
      varlist = dap_malloc(dap_listlen, "outset: varlist");
      vname = dap_malloc(dap_listlen, "outset: vname");
    }
  if (!(dap_out[dap_ono] = dfopen(fname, "w")))
    {
      fprintf(dap_err, "(outset) Can't write data set: %s\n", fname);
      exit(1);
    }
  if (!varl)
    {
      fprintf(dap_err, "(outset (%s)) Missing variable list.\n", fname);
      exit(1);
    }
  fixlist(varl, varlist);
  if (varlist[0])
    {
      for (l = 0; varlist[l] == ' '; l++)
	;
      if (varlist[l] == '!')	/* listing variables NOT to include */
	{		/* first put them all in */
	  for (l++; varlist[l] == ' '; l++)
	    ;
	  dap_obs[dap_ono].do_ovar = dap_obs[dap_ono].do_nvar;
	  for (v = 0; v < dap_obs[dap_ono].do_nvar; v++)
	    dap_obs[dap_ono].do_out[v] = v;
	  while (varlist[l])	/* then take them out */
	    {
	      for (i = 0; varlist[l + i] && varlist[l + i] != ' '; i++)
		vname[i] = varlist[l + i];
	      vname[i] = '\0';
	      if ((w = dap_varnum(vname)) >= 0)
		{
		  for (v = 0; v < dap_obs[dap_ono].do_ovar; v++)
		    {
		      if (dap_obs[dap_ono].do_out[v] == w)
			break;
		    }
		  if (v == dap_obs[dap_ono].do_ovar)
		    {
		      fprintf(dap_err,
			      "(outset (%s)) variable not in list of variables to exclude: %s\n",
			      fname, vname);
		      exit(1);
		    }
		  while (v < dap_obs[dap_ono].do_ovar - 1)
		    {
		      dap_obs[dap_ono].do_out[v] =
			dap_obs[dap_ono].do_out[v + 1];
		      v++;
		    }
		  dap_obs[dap_ono].do_ovar--;
		}
	      else if ((w = dap_arrnum(vname, &dim)) >= 0)
		{
		  for (v = 0; v < dap_obs[dap_ono].do_ovar; v++)
		    {
		      if (dap_obs[dap_ono].do_out[v] == w)
			break;
		    }
		  while (v < dap_obs[dap_ono].do_ovar - dim)
		    {
		      dap_obs[dap_ono].do_out[v] =
			dap_obs[dap_ono].do_out[v + dim];
		      v++;
		    }
		  dap_obs[dap_ono].do_ovar -= dim;
		}
	      else
		{
		  fprintf(dap_err, "(outset(%s)) unknown variable: %s\n",
			  fname, vname);
		  exit(1);
		}
	      l += i;
	      while (varlist[l] == ' ')
		l++;
	    }
	}
      else
	{
	  while (varlist[l])
	    {
	      for (i = 0; varlist[l + i] && varlist[l + i] != ' '; i++)
		vname[i] = varlist[l + i];
	      vname[i] = '\0';
	      if ((v = dap_varnum(vname)) >= 0)
		dap_obs[dap_ono].do_out[dap_obs[dap_ono].do_ovar++] = v;
	      else if ((v = dap_arrnum(vname, &dim)) >= 0)
		{
		  for (d = 0; d < dim; d++)
		    dap_obs[dap_ono].do_out[dap_obs[dap_ono].do_ovar++] = v + d;
		}
	      else
		{
		  fprintf(dap_err, "(outset(%s)) unknown variable: %s\n",
			  fname, vname);
		  exit(1);
		}
	      l += i;
	      while (varlist[l] == ' ')
		l++;
	    }
	}
    }
  else
    {
      dap_obs[dap_ono].do_ovar = dap_obs[dap_ono].do_nvar;
      for (v = 0; v < dap_obs[dap_ono].do_nvar; v++)
	dap_obs[dap_ono].do_out[v] = v;
    }
  if (dap_varnum("_type_") < 0)
    {
      fprintf(dap_err, "(outset (%s)) missing _type_ variable\n", fname);
      exit(1);
    }
  for (v = 0; v < dap_obs[dap_ono].do_ovar; v++)
    {
      for (w = v + 1; w < dap_obs[dap_ono].do_ovar; w++)
	{
	  if (dap_obs[dap_ono].do_out[v] == dap_obs[dap_ono].do_out[w])
	    {
	      fprintf(dap_err,
		      "(outset (%s)) duplicate variable in output list: %s\n",
		      fname, dap_obs[dap_ono].do_nam[dap_obs[dap_ono].do_out[w]]);
	      exit(1);
	    }
	}
    }
  for (v = 0, first = 1; v < dap_obs[dap_ono].do_ovar; v++)
    {
      if (!first)
	dap_putc(' ', dap_out[dap_ono]);
      dputs(dap_obs[dap_ono].do_nam[dap_obs[dap_ono].do_out[v]], " ", dap_out[dap_ono]);
      dputi(dap_obs[dap_ono].do_len[dap_obs[dap_ono].do_out[v]], dap_out[dap_ono]);
      first = 0;
    }
  dap_putc('\n', dap_out[dap_ono]);
  dflush(dap_out[dap_ono]);
  outline = 0;
}

/* write a line to the output dataset */
void output()
{
  int v;
  int first;

  if ((v = dap_varnum("_type_")) < 0)
    {
      fprintf(dap_err, "(output) missing _type_ variable\n");
      exit(1);
    }
  for (v = 0, first = 1; v < dap_obs[dap_ono].do_ovar; v++)
    {
      if (!first)
	dap_putc(SETDELIM, dap_out[dap_ono]);
      if (dap_obs[dap_ono].do_len[dap_obs[dap_ono].do_out[v]] == INT)
	{
	  /* if we're in an infile statement, may need to update the value
	   * from the value in the user's program
	   */
	  if (!dap_ono && dap_obs[dap_ono].do_il[dap_obs[0].do_out[v]])
	    dap_obs[0].do_int[dap_obs[0].do_out[v]] =
	      *dap_obs[dap_ono].do_il[dap_obs[0].do_out[v]];
	  dap_putint(dap_obs[dap_ono].do_int[dap_obs[dap_ono].do_out[v]],
		     dap_out[dap_ono]);
	}
      else if (dap_obs[dap_ono].do_len[dap_obs[dap_ono].do_out[v]] == DBL)
	{
	  /* if we're in an infile statement, may need to update the value
	   * from the value in the user's program
	   */
	  if (!dap_ono && dap_obs[dap_ono].do_dl[dap_obs[0].do_out[v]])
	    dap_obs[0].do_dbl[dap_obs[0].do_out[v]] =
	      *dap_obs[dap_ono].do_dl[dap_obs[0].do_out[v]];
	  dap_double = dap_obs[dap_ono].do_dbl[dap_obs[dap_ono].do_out[v]];
	  dap_putdouble(dap_out[dap_ono]);
	}
      else
	{
	  dputs(dap_obs[dap_ono].do_str[dap_obs[dap_ono].do_out[v]], "",
		dap_out[dap_ono]);
	}
      first = 0;
    }
  dap_putc('\n', dap_out[dap_ono]);
  dflush(dap_out[dap_ono]);
  if (dap_outreport && !(++outline % dap_outreport))
    {
      fprintf(stderr, "(output) %d lines written to %s...\n",
	      outline, dap_out[dap_ono]->dfile_name);
      fflush(stderr);
    }
}

/* Expands array variables in varlist and records their indexes in varv
 * Returns number of variables for inclusion or negative number of variables
 * for exclusion.
 */
static int expand(char *varlist, int *varv, int maxvars)
{
  int nvars;
  int m;
  int i;
  char *mname;
  char *newname;
  int arrn;		/* var index of array's first element */
  int dim;		/* array dimension */
  int d;			/* index to array */
  int include;		/* variables to be included? (rather than excluded) */

  if (!varlist)
    return 0;
  if (!varv)
    {
      fputs("(expand) Missing variable index list.\n", dap_err);
      exit(1);
    }
  mname = dap_malloc(strlen(varlist) + 1, "expand: mname");
  newname = dap_malloc(strlen(varlist) + 1, "expand: newname");
  include = 1;
  for (m = 0; varlist[m] == ' '; m++)
    ;
  if (varlist[m] == '!')	/* indicates variables to exclude, not include */
    {
      for (m++; varlist[m] == ' '; m++)
	;
      include = -1;
    }
  for (nvars = 0; varlist[m]; )
    {
      for (i = 0; varlist[m + i] && varlist[m + i] != ' ' && varlist[m + i] != '>'; i++)
	mname[i] = varlist[m + i];
      mname[i] = '\0';
      m += i;
      while (varlist[m] == ' ')
	m++;
      newname[0] = '\0';
      if (varlist[m] == '>')
	{
	  if (include < 0)
	    {
	      fputs("(expand) Can't rename variables being excluded\n", dap_err);
	      exit(1);
	    }
	  for (m++; varlist[m] == ' '; m++)
	    ;
	  for (i = 0; varlist[m + i] && varlist[m + i] != ' ' && varlist[m + i] != '>';
	       i++)
	    newname[i] = varlist[m + i];
	  newname[i] = '\0';
	  m += i;
	  while (varlist[m] == ' ')
	    m++;
	}
      if (nvars >= maxvars)
	{
	  fprintf(dap_err, "(expand) More than %d variables: %s\n", maxvars, varlist);
	  exit(1);
	}
      if ((arrn = dap_arrnum(mname, &dim)) >= 0)
	{
	  for (d = 0; d < dim; d++)
	    {
	      if (newname[0])
		{
		  dap_free(dap_obs[dap_ono].do_nam[arrn],
			   "expand: dap_obs[dap_ono].do_nam[arrn]");
		  dap_obs[dap_ono].do_nam[arrn] =
		    dap_malloc(strlen(newname) + 6,
			       "expand: dap_obs[dap_ono].do_nam[arrn]");
		  sprintf(dap_obs[dap_ono].do_nam[arrn],
			  "%s[%d]", newname, d);
		}
	      varv[nvars++] = arrn++;
	    }
	}
      else if ((varv[nvars] = dap_varnum(mname)) > 0)
	{
	  if (newname[0])
	    {
	      dap_free(dap_obs[dap_ono].do_nam[varv[nvars]],
		       "expand: dap_obs[dap_ono].do_nam[varv[nvars]]");
	      dap_obs[dap_ono].do_nam[varv[nvars]] =
		dap_malloc(strlen(newname) + 1,
			   "expand: dap_obs[dap_ono].do_nam[varv[nvars]]");
	      strcpy(dap_obs[dap_ono].do_nam[varv[nvars]], newname);
	    }
	  nvars++;
	}
      else
	{
	  fprintf(dap_err, "(expand) Variable unknown: %s\n", mname);
	  exit(1);
	}
    }
  dap_free(mname, "expand: mname");
  dap_free(newname, "expand: newname");
  return include * nvars;
}

static void varcat(char *to, char *from)
{
  int t, f, ff;

  for (f = 0; from[f] == ' '; f++)
    ;
  for (t = 0; to[t]; t++)
    ;
  while (from[f])
    {
      for (ff = f; from[ff] && from[ff] != ' ' && from[ff] != '>'; ff++)
	;
      while (from[ff] == ' ')
	ff++;
      if (from[ff] == '>')
	{
	  for (f = ff + 1; from[f] == ' '; f++)
	    ;
	}
      while (from[f] && from[f] != ' ')
	to[t++] = from[f++];
      to[t++] = ' ';
      while (from[f] == ' ')
	f++;
    }
  to[t] = '\0';
}

/* One-to-one or many-to-one merge of dataset lines
 * fname1, fname2 = datasets to merge
 * vars1, vars2 = lists of variables to include from each dataset
 * marks = partitioning variables to coordinate merge
 * outname = output dataset
 */
void merge(char *fname1, char *vars1, char *fname2, char *vars2,
	   char *marks, char *outname)
{
  int *varv1, *varv2;	/* indexes of variables listed in vars1, vars2 */
  int *ovarv1, *ovarv2;	/* indexes of variables to use from fname1, fname2 */
  int nvar1, nvar2;	/* number of vars in vars1, vars2 except if excluding,
			 * it's the negative
			 */
  int *markv1;		/* indexes of partitioning variables in fname1 */
  int *markv2;		/* indexes of partitioning variables in fname2 */
  int nmark;		/* number of partitioning variables */
  int v1, v2;		/* indexes to variable index lists */
  int vv1, vv2;		/* more indexes to variable index lists */
  char *outlist;		/* list of variables to appear in final output */
  char *outlist1;		/* list of variables to use from fname1 */
  char *outlist2;		/* list of variables to use from fname2 */
  int goon1;
  double ddiff;
  int isdiff;
  int vars1null, vars2null;	/* vars1, vars2 = NULL? */
  char *vars1a, *vars2a;	/* OK, awful patch: if vars1 and/or vars2 are exclusions
				 * with '!', then have to create lists artificially of
				 * variables that are not to be excluded.
				 */
  int exclude1, exclude2;	/* vars1, vars2 exclusion lists? */
  int nvar1a, nvar2a;	/* variable counts in case of exclusion */
  int *varv1a, *varv2a;	/* index lists for variables to include */

  if (!fname1 || !fname2 || !outname)
    {
      fputs("(merge) Missing dataset name.\n", dap_err);
      exit(1);
    }
  if (vars1 && index(vars1, '['))
    {
      fprintf(dap_err,
	      "(merge) Variable lists may not contain individual array elements: %s\n",
	      vars1);
      exit(1);
    }
  if (vars2 && index(vars2, '['))
    {
      fprintf(dap_err,
	      "(merge) Variable lists may not contain individual array elements: %s\n",
	      vars2);
      exit(1);
    }
  vars1null = 0;	/* non-NULL until proven NULL */
  vars2null = 0;
  outlist = dap_malloc(dap_listlen, "merge: outlist");
  outlist1 = dap_malloc(dap_listlen, "merge: outlist1");
  outlist2 = dap_malloc(dap_listlen, "merge:outlist2");
  varv1 = (int *) dap_malloc(sizeof(int) * dap_maxvar, "merge: varv1");
  varv2 = (int *) dap_malloc(sizeof(int) * dap_maxvar, "merge: varv2");
  ovarv1 = (int *) dap_malloc(sizeof(int) * dap_maxvar, "merge: ovarv1");
  ovarv2 = (int *) dap_malloc(sizeof(int) * dap_maxvar, "merge: ovarv2");
  markv1 = (int *) dap_malloc(sizeof(int) * dap_maxvar, "merge: markv1");
  markv2 = (int *) dap_malloc(sizeof(int) * dap_maxvar, "merge: markv2");
  dap_ono = 0;	/* take no chances! */
  inset(fname1);	/* set up input from dataset 1 */
  if (vars1 && !vars1[0])		/* vars1 null string: use all variables */
    {
      vars1null = 1;
      /* in this case, need to make our own vars1 list */
      vars1 = dap_malloc(dap_listlen, "merge: vars1");
      vars1[0] = '\0';
      for (v1 = 0; v1 < dap_obs[dap_ono].do_nvar; v1++)
	{		/* copy all vars except _type_ */
	  if (strcmp(dap_obs[dap_ono].do_nam[v1], "_type_"))
	    {
	      strcat(vars1, " ");
	      strcat(vars1, dap_obs[dap_ono].do_nam[v1]);
	    }
	}
    }
  nvar1 = expand(vars1, varv1, dap_maxvar);
  exclude1 = 0;
  if (nvar1 < 0)	/* OK, here we go: variables listed for exclusion */
    {
      exclude1 = 1;
      nvar1 = -nvar1;
      vars1a = dap_malloc(dap_listlen, "merge: vars1a");
      vars1a[0] = '\0';
      varv1a = (int *) dap_malloc(dap_maxvar, "merge: varv1a");
      for (v1 = 0, nvar1a = 0; v1 < dap_obs[dap_ono].do_nvar; v1++)
	{	/* copy all vars except _type_ and excluded vars */
	  if (!strcmp(dap_obs[dap_ono].do_nam[v1], "_type_"))
	    continue;
	  for (vv1 = 0; vv1 < nvar1; vv1++)
	    {	/* look to see if excluded */
	      if (varv1[vv1] == v1)
		break;
	    }
	  if (vv1 == nvar1)	/* not found, include it */
	    {
	      strcat(vars1a, " ");
	      strcat(vars1a, dap_obs[dap_ono].do_nam[v1]);
	      varv1a[nvar1a++] = v1;
	    }
	}
      if (vars1null)
	dap_free(vars1, "merge: vars1");
      vars1 = vars1a;	/* reassign list; this won't happen if vars1 was NULL */
      nvar1 = nvar1a;
      dap_free(varv1, "merge: varv1");
      varv1 = varv1a;
    }
  if (marks)
    nmark = dap_list(marks, markv1, dap_maxvar);
  else
    nmark = 0;
  dap_ono = 1;
  inset(fname2);	/* set up input from dataset 2 */
  if (vars2 && !vars2[0])		/* vars2 null string: use all variables */
    {
      vars2null = 1;
      /* in this case, need to make our own vars2 list */
      vars2 = dap_malloc(dap_listlen, "merge: vars2");
      vars2[0] = '\0';
      for (v2 = 0; v2 < dap_obs[dap_ono].do_nvar; v2++)
	{
	  if (strcmp(dap_obs[dap_ono].do_nam[v2], "_type_"))
	    {	/* copy all vars except _type_ */
	      strcat(vars2, " ");
	      strcat(vars2, dap_obs[dap_ono].do_nam[v2]);
	    }
	}
    }
  nvar2 = expand(vars2, varv2, dap_maxvar);
  exclude2 = 0;
  if (nvar2 < 0)	/* OK, here we go: variables listed for exclusion */
    {
      exclude2 = 1;
      nvar2 = -nvar2;
      vars2a = dap_malloc(dap_listlen, "merge: vars2a");
      vars2a[0] = '\0';
      varv2a = (int *) dap_malloc(dap_maxvar, "merge: varv2a");
      for (v2 = 0, nvar2a = 0; v2 < dap_obs[dap_ono].do_nvar; v2++)
	{	/* copy all vars except _type_ and excluded vars */
	  if (!strcmp(dap_obs[dap_ono].do_nam[v2], "_type_"))
	    continue;
	  for (vv2 = 0; vv2 < nvar2; vv2++)
	    {	/* look to see if excluded */
	      if (varv2[vv2] == v2)
		break;
	    }
	  if (vv2 == nvar2)	/* not found, include it */
	    {
	      strcat(vars2a, " ");
	      strcat(vars2a, dap_obs[dap_ono].do_nam[v2]);
	      varv2a[nvar2a++] = v2;
	    }
	}
      if (vars2null)
	dap_free(vars2, "merge: vars2");
      vars2 = vars2a;	/* reassign list; this won't happen if vars2 was NULL */
      nvar2 = nvar2a;
      dap_free(varv2, "merge: varv2");
      varv2 = varv2a;
    }
  dap_list(marks, markv2, dap_maxvar);
  for (v1 = 0; v1 < nmark; v1++)	/* check types of part vars across datasets */
    {
      if (dap_obs[0].do_len[markv1[v1]] != dap_obs[1].do_len[markv2[v1]])
	{
	  fprintf(dap_err,
		  "(merge) Part variables of different types: %s (%d) and %s (%d)\n",
		  dap_obs[0].do_nam[markv1[v1]], dap_obs[0].do_len[markv1[v1]],
		  dap_obs[1].do_nam[markv2[v1]], dap_obs[1].do_len[markv2[v1]]);
	  exit(1);
	}
    }
  /* Start assembling list of output variables. */
  outlist[0] = '\0';
  if (vars2 && nvar2 > 0)
    varcat(outlist, vars2);
  outlist2[0] = '\0';
  if (vars2 && nvar2 > 0)
    varcat(outlist2, vars2);
  dap_ono = 2;		/* the output dataset */
  dap_obs[2].do_nvar = 0;	/* start with nothing */
  dap_obs[2].do_ovar = 0;	/* except _type_ */
  dap_obs[2].do_out[dap_obs[2].do_ovar++] = dap_vd("_type_ 8", 0);
  for (v2 = 0; v2 < nvar2; v2++)
    {
      if (dap_obs[2].do_nam[dap_obs[2].do_nvar])
	dap_free(dap_obs[2].do_nam[dap_obs[2].do_nvar],
		 "merge: dap_obs[2].do_nam[dap_obs[2].do_nvar]");
      dap_obs[2].do_nam[dap_obs[2].do_nvar] =
	dap_malloc(strlen(dap_obs[1].do_nam[varv2[v2]]) + 1,
		   "merge: dap_obs[1].do_nam[varv2[v2]]");
      strcpy(dap_obs[2].do_nam[dap_obs[2].do_nvar],
	     dap_obs[1].do_nam[varv2[v2]]);
      dap_obs[2].do_len[dap_obs[2].do_nvar] = dap_obs[1].do_len[varv2[v2]];
      dap_obs[2].do_nvar++;
    }
  outlist1[0] = '\0';
  if (vars1 && nvar1 > 0)
    {
      strcat(outlist, " ");
      varcat(outlist, vars1);
      varcat(outlist1, vars1);
    }
  for (v1 = 0; v1 < nvar1; v1++)
    {
      for (v2 = 0; v2 < nvar2; v2++)
	{
	  if (!strcmp(dap_obs[0].do_nam[varv1[v1]], dap_obs[1].do_nam[varv2[v2]]))
	    break;
	}
      if (v2 < nvar2)
	{
	  fprintf(dap_err, "(merge) variable appears in lists for both %s and %s: %s\n",
		  fname1, fname2, dap_obs[0].do_nam[varv1[v1]]);
	  exit(1);
	}
      else
	{
	  if (dap_obs[2].do_nam[dap_obs[2].do_nvar])
	    dap_free(dap_obs[2].do_nam[dap_obs[2].do_nvar],
		     "merge: dap_obs[2].do_nam[dap_obs[2].do_nvar]");
	  dap_obs[2].do_nam[dap_obs[2].do_nvar] =
	    dap_malloc(strlen(dap_obs[0].do_nam[varv1[v1]]) + 1,
		       "merge: dap_obs[0].do_nam[varv1[v1]]");
	  strcpy(dap_obs[2].do_nam[dap_obs[2].do_nvar],
		 dap_obs[0].do_nam[varv1[v1]]);
	  dap_obs[2].do_len[dap_obs[2].do_nvar] = dap_obs[0].do_len[varv1[v1]];
	  dap_obs[2].do_nvar++;
	}
    }
  outset(outname, outlist);
  strcpy(dap_obs[2].do_str[dap_varnum("_type_")], "OBS");
  expand(outlist1, ovarv1, dap_maxvar);
  expand(outlist2, ovarv2, dap_maxvar);
  dap_ono = 0; /* for reading first dataset */
  goon1 = step(); /* try to read one line */
  for ( ; ; )
    {
      dap_ono = 1; /* prepare to read second dataset */
      if (step()) /* if there's anything left of second dataset */
	{
	  while (goon1) /* while there's anything left of first dataset */
	    {
	      /* see if mark values variables currently match for both datasets */
	      isdiff = 0;
	      if (nmark) /* only check if there are mark variables */
		{
		  for (v1 = 0; v1 < nmark; v1++)
		    {
		      if (dap_obs[0].do_len[markv1[v1]] == DBL)
			{
			  ddiff = dap_obs[0].do_dbl[markv1[v1]] -
			    dap_obs[1].do_dbl[markv2[v1]];
			  if (ddiff < 0.0)
			    isdiff = -1;
			  else if (ddiff > 0.0)
			    isdiff = 1;
			  else
			    isdiff = 0;
			  if (isdiff)
			    break;
			}
		      else if (dap_obs[0].do_len[markv1[v1]] == INT)
			{
			  isdiff = dap_obs[0].do_int[markv1[v1]] -
			    dap_obs[1].do_int[markv2[v1]];
			  if (isdiff)
			    break;
			}
		      else if ((isdiff = strcmp(dap_obs[0].do_str[markv1[v1]],
						dap_obs[1].do_str[markv2[v1]])))
			break;
		    }
		}
	      if (isdiff < 0) /* dataset1 not up to where dataset2 is */
		{
		  dap_ono = 0; /* read another line of dataset1 */
		  goon1 = step();
		}
	      else if (isdiff > 0) /* dataset1 passed where dataset2 is */
		break;
	      else /* or else we're on the same page: merge */
		{
		  for (v1 = 0; v1 < nvar1; v1++)
		    {
		      if (dap_obs[0].do_len[varv1[v1]] == DBL)
			dap_obs[2].do_dbl[ovarv1[v1]] =
			  dap_obs[0].do_dbl[varv1[v1]];
		      else if (dap_obs[0].do_len[varv1[v1]] == INT)
			dap_obs[2].do_int[ovarv1[v1]] =
			  dap_obs[0].do_int[varv1[v1]];
		      else
			{
			  if (dap_obs[2].do_str[ovarv1[v1]])
			    dap_free(dap_obs[2].do_str[ovarv1[v1]],
				     "merge: dap_obs[2].do_str[ovarv1[v1]]");
			  dap_obs[2].do_str[ovarv1[v1]] =
			    dap_malloc(strlen(dap_obs[0].do_str[varv1[v1]]) + 1,
				       "merge: dap_obs[0].do_str[ovarv1[v1]]");
			  strcpy(dap_obs[2].do_str[ovarv1[v1]],
				 dap_obs[0].do_str[varv1[v1]]);
			}
		    }
		  for (v2 = 0; v2 < nvar2; v2++)
		    {
		      if (dap_obs[1].do_len[varv2[v2]] == DBL)
			dap_obs[2].do_dbl[ovarv2[v2]] =
			  dap_obs[1].do_dbl[varv2[v2]];
		      else if (dap_obs[1].do_len[varv2[v2]] == INT)
			dap_obs[2].do_int[ovarv2[v2]] =
			  dap_obs[1].do_int[varv2[v2]];
		      else
			{
			  if (dap_obs[2].do_str[ovarv2[v2]])
			    dap_free(dap_obs[2].do_str[ovarv2[v2]],
				     "merge: dap_obs[2].do_str[ovarv2[v2]]");
			  dap_obs[2].do_str[ovarv2[v2]] =
			    dap_malloc(strlen(dap_obs[1].do_str[varv2[v2]]) + 1,
				       "merge: dap_obs[1].do_str[ovarv2[v2]]");
			  strcpy(dap_obs[2].do_str[ovarv2[v2]],
				 dap_obs[1].do_str[varv2[v2]]);
			}
		    }
		  dap_ono = 2; /* prepare to output to merged file */
		  output();
		  dap_ono = 0;
		  goon1 = step();
		}
	      if (!nmark)
		break;
	    }
	}
      else
	break;
    }
  dap_ono = 0;
  if (dap_in[0])
    {
      dfclose(dap_in[0]);
      dap_in[0] = (DFILE *) NULL;
    }
  if (dap_in[1])
    {
      dfclose(dap_in[1]);
      dap_in[1] = (DFILE *) NULL;
    }
  if (dap_out[dap_ono])
    {
      dfclose(dap_out[dap_ono]);
      dap_out[dap_ono] = (DFILE *) NULL;
    }
  dap_free(outlist, "merge: outlist");
  dap_free(outlist1, "merge: outlist1");
  dap_free(outlist2, "merge: outlist2");
  dap_free(ovarv1, "merge: ovarv1");
  dap_free(ovarv2, "merge: ovarv2");
  dap_free(markv1, "merge: markv1");
  dap_free(markv2, "merge: markv2");
  if (vars1null)
    dap_free(vars1, "merge: vars1");
  if (vars2null)
    dap_free(vars2, "merge: vars2");
  if (exclude1 < 0)
    {
      dap_free(vars1a, "merge: vars1a");
      dap_free(varv1a, "merge: varv1a");
    }
  else
    dap_free(varv1, "merge: varv1");
  if (exclude2 < 0)
    {
      dap_free(vars2a, "merge: vars2a");
      dap_free(varv2a, "merge: varv2a");
    }
  else
    dap_free(varv2, "merge: varv2");
}

void title(char *text)
{
  dap_title = text;
}

void dap_head(int markv[], int nmark)
{
  time_t t;
  int m;

  fputs("\n=================================", dap_lst);
  fprintf(dap_lst, "\nDap %3d. ", pageno++);
  time(&t);
  fputs(ctime(&t), dap_lst);
  putc('\n', dap_lst);
  if (dap_title)
    {
      fputs(dap_title, dap_lst);
      putc('\n', dap_lst);
    }
  if (nmark)
    {
      fprintf(dap_lst, "\nFor: ");
      for (m = 0; m < nmark; m++)
	{
	  switch(dap_obs[dap_ono].do_len[markv[m]])
	    {
	    case DBL:
	      fprintf(dap_lst, "%s = %g",
		      dap_obs[dap_ono].do_nam[markv[m]],
		      dap_obs[dap_ono].do_dbl[markv[m]]);
	      break;
	    case INT:
	      fprintf(dap_lst, "%s = %d",
		      dap_obs[dap_ono].do_nam[markv[m]],
		      dap_obs[dap_ono].do_int[markv[m]]);
	      break;
	    default:
	      fprintf(dap_lst, "%s = %s",
		      dap_obs[dap_ono].do_nam[markv[m]],
		      dap_obs[dap_ono].do_str[markv[m]]);
	      break;
	    }
	  if (m < nmark - 1)
	    fputs(", ", dap_lst);
	}
      putc('\n', dap_lst);
    }
  putc('\n', dap_lst);
}

typedef struct CharList CharList;
struct CharList {
   char * word;
   CharList *next;
};


#define DOUBLER 1
#define STRINGER 0

typedef struct AttributeList AttributeList;
struct AttributeList {
   char * word;
   int size;
   int type;
   AttributeList *next;
};



/**
Max 50000 words
*/
CharList extractWords(char * buffer, long size,char  *delimiter)
{
	char * bufferWord= (char*) malloc (sizeof(char)*size+1);
	memset (bufferWord,'\0',size+1);
	CharList list;
	list.word=NULL;
	list.next=NULL;
	CharList *current=&list;
	long i=0l;
	long sSize=0l;
	long sIndex=0l;
	for(i=0l;i<size;i++)
	{
		if (buffer[i]=='\r' || buffer[i]=='\t')
			continue;
		if (buffer[i]==delimiter[0])
		{
			current->word= (char*) malloc (sizeof(char)*sIndex+5);
			strcpy(current->word,bufferWord);
			current->next= (char*) malloc (sizeof(CharList));
			current=current->next;
			sSize=sIndex;
			sIndex=0;
			memset (bufferWord,'\0',size+1);
		}
		else
		{
			bufferWord[sIndex]=buffer[i];
			sIndex++;
		}
		
	}
	if (sIndex>0)
	{
		current->word= (char*) malloc ((sizeof(char)*strlen(bufferWord))+1);
		strcpy(current->word,bufferWord);
		current->next= NULL;
	}
	free(bufferWord);
		
	return list;
}

void cleanAttributeList( AttributeList *list)
{
	AttributeList *actualatt=list;
	do{
		actualatt=list;
		AttributeList *prev=list;
		AttributeList *prev2=list;
		do{
			prev2=prev;
			prev=actualatt;
			actualatt=actualatt->next;
		}while(actualatt!=NULL);
		if (prev!=list){
			free(prev->word);
			free(prev);
		}
		prev2->next=NULL;
	}while(list->next!=NULL);
}

void cleanCharList( CharList *list)
{
	CharList *actualatt=list;
	do{
		actualatt=list;
		CharList *prev=list;
		CharList *prev2=list;
		do{
			prev2=prev;
			prev=actualatt;
			actualatt=actualatt->next;
		}while(actualatt!=NULL);
		if (prev!=list)
		{
			free(prev->word);
			free(prev);
		}
		prev2->next=NULL;
	}while(list->next!=NULL);
}



int import(char* fname,  char* fileToLoad, char * format, char  *delimiter,int replace,int getnames){
	
	infile(fileToLoad,delimiter);
	FILE * pFile;
	long lSize;
	char * buffer;
	char * bufferline;
	size_t result;
	if (strcmp(format,"CSV")&&strcmp(format,"DLM")&&strcmp(format,"csv")&&strcmp(format,"dlm")
		&&strcmp(format,"TAB")&&strcmp(format,"tab"))
	{
		printf ("Format not supported :%s\n",format); exit (1);
	}
	if (strlen(delimiter)==0)
	{
		if(strcmp(format,"CSV")||strcmp(format,"csv"))
			delimiter=",";
		if(strcmp(format,"DLM")||strcmp(format,"dlm"))
			delimiter=" ";
		if(strcmp(format,"TAB")||strcmp(format,"tab"))
			delimiter="\t";
	}
	pFile = fopen (fileToLoad , "rb" );
	if (pFile==NULL) {
		printf ("File loading error :%s\n",fileToLoad); exit (1);
	}
	// obtain file size:
	fseek (pFile , 0 , SEEK_END);
	lSize = ftell (pFile);
	rewind (pFile);
	// allocate memory to contain the whole file:
	buffer = (char*) malloc (sizeof(char)*lSize);
	if (buffer == NULL) {printf ("Memory error \n"); exit (2);}
	bufferline = (char*) malloc (sizeof(char)*lSize);
	if (bufferline == NULL) {printf ("2nd Memory error \n"); exit (2);}

	// copy the file into the buffer:
	result = fread (buffer,1,lSize,pFile);
	if (result != lSize) {printf ("Reading error \n"); exit (3);}

	long sIndex=0l;
	long sSize=0l;
	long i=0l;
	
	AttributeList listatt;
	listatt.word=NULL;
	listatt.next=NULL;
	 //the whole file is now loaded in the memory buffer. 
	int lineCnt=0;
	for(i=0l;i<lSize;i++)
	{
		
		if (buffer[i] == '\n')
		{
			CharList list=extractWords(bufferline,sIndex,  delimiter);
			CharList *actual=&list;
			int counter=0;
			do{
				char *word=actual->word;
				int sizeStr=strlen(word);
				AttributeList *actualatt=&listatt;
				AttributeList *prev=actualatt;
				
				if(lineCnt==0)
				{
					
					
					if (actualatt->word==NULL)
					{
						if(getnames)
						{
							actualatt->word= (char*) malloc (sizeof(char)*strlen(word)+5);
							strcpy(actualatt->word,word);
						}
						else
						{
							actualatt->word= (char*) malloc (sizeof(char)*10);
							sprintf(actualatt->word,"X%d",counter);
						}	
					}
					else
					{
						do{
							char *wordatt=actualatt->word;
							if (strcmp(wordatt,word)==0)
							{
								break;
							}
							prev=actualatt;
							actualatt=actualatt->next;
						}while(actualatt!=NULL);
						if (actualatt==NULL)
						{
							prev->next=(AttributeList*) malloc (sizeof(AttributeList));
							prev->next->word=NULL;
							prev=prev->next;
							if(getnames)
							{
								prev->word= (char*) malloc (sizeof(char)*strlen(word)+5);
								strcpy(prev->word,word);
							}
							else
							{
								prev->word= (char*) malloc (sizeof(char)*10);
								sprintf(prev->word,"X%d",counter);
							}
							prev->next=NULL;
							
						}
					}
				}
				actualatt=&listatt;
				prev=actualatt;
				if((getnames&&lineCnt>0)||!getnames)
				{
					
					int counterbis=0;
					do{
						if (counter==counterbis)
							break;
						actualatt=actualatt->next;
						counterbis++;
					}while(actualatt!=NULL);
					if (actualatt!=NULL)
					{
						//measure column size
						if (sizeStr>actualatt->size)
							actualatt->size=sizeStr;
						if (actualatt->size>1000)
							actualatt->size=1000;
						float f;
						if(sscanf(word, "%f", &f) != 0)
							actualatt->type=DOUBLER;
						else
							actualatt->type=STRINGER;
					}
					
				}
				actual=actual->next;
				counter++;
			}while(actual!=NULL);
			sSize=sIndex;
			sIndex=0;
			lineCnt++;
			cleanCharList(&list);
		}
		else
		{
			bufferline[sIndex]=buffer[i];
			sIndex++;
		}
		
	}
	// terminate
	fclose (pFile);
	free (buffer);
	free (bufferline);
	AttributeList *actualatt=&listatt;
	int countcol=0;
	
	do{
		char *wordatt=actualatt->word;
		if(wordatt!=NULL)
		{

			int sierr=strlen(wordatt)+6;
			char *bufferer= (char*) malloc (sizeof(char)*sierr);
			
			
			if(actualatt->type==DOUBLER)
			{
				sprintf(bufferer,"%s -1",wordatt);
				dap_vd(bufferer, -1);
				
			}
			else
			{
				int size=1000;
				if (actualatt->size<1000)
					size=actualatt->size;
				sprintf(bufferer,"%s %d",wordatt,actualatt->size);
				dap_vd(bufferer,size);
				
			
			}
		}
		countcol++;
		actualatt=actualatt->next;
	}while(actualatt!=NULL);
	
	outset(fname, "");
	skip(2);
        while (step())
          output();

	cleanAttributeList(&listatt);
	
	return 0;
}
