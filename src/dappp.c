/* Dap preprocessor.
 * 0. Translates .sas file to .c file
 * 1. Processes simple #defines.  
 * 2. Replaces main with main_dap.  
 * 3. Processes infile and inset statements.  
 * 4. Adds necessary function calls for variable
 *    declarations in infile and inset statement bodies.  
 */

/*  Copyright (C) 2001, 2002, 2003 Free Software Foundation, Inc.
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

#define TOKLEN 127	/* maximum length of token */
#define MAXDEF 512	/* maximum number of defines */

#define DBL (-1)
#define INT 0
#define STR 1

void sastrans(char *name);

char *dotname;		/* name of file to preprocess */

int lineno;		/* line number, for error messages */
int column;		/* column within line */
int newline;		/* flag: was most recent character a newline? */
int pound;		/* flag: got # as first char in line? */
int incomment;		/* flag: inside comment? */
int inquote1;		/* flag: inside single quotes? */
int inquote2;		/* flag: inside double quotes? */
int escape;		/* flag: was previous character a backslash,
			 * outside comments but inside quotes?
			 */

typedef struct		/* defines for array dimensions */
{
  char def_str[TOKLEN + 1];	/* the defined string */
  int def_val;			/* value, a positive integer */
} define;

define def[MAXDEF];		/* the defines */
int ndef;			/* number of defines */

int white(int c)
{
  return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

int alpha(int c)
{
  return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || c == '_';
}

int num(int c)
{
  return '0' <= c && c <= '9';
}

int alphanum(int c)
{
  return alpha(c) || num(c);
}

/* Get one character, update newline, lineno, and column.  */
int get1c(FILE *fp)
{
  int c;

  c = getc(fp);
  if (newline)
    {
      lineno++;
      column = 0;
    }
  else
    column++;
  newline = (c == '\n');
  if (newline)
    pound = 0;
  return c;
}

/* Put one character back into .c file.  If dapc is non-null, also
 * back up .dap.c file one character.  
 */
void unget1c(int c, FILE *dotc, FILE *dapc)
{
  if (newline)
    newline = 0;
  ungetc(c, dotc);
  if (dapc)
    fseek(dapc, ftell(dapc) - 1, SEEK_SET);
}

/* Get one character from .c file. Update comment, inquote1, inquote2,
 * escape.  If out is 1, then copy that character to .dap.c file.
 */
int dgetc(FILE *dotc, FILE *dapc, int out)
{
  int c;			/* the character read from .c file */

  switch (c = get1c(dotc))
    {
    case '#':
      if (!incomment && !column)
	pound = 1;
      escape = 0;
      break;
    case '"':
      if (inquote2 && !escape)
	inquote2 = 0;
      else if (!inquote1 && !incomment)
	inquote2 = 1;
      escape = 0;
      break;
    case '\'':
      if (inquote1 && !escape)
	inquote1 = 0;
      else if (!inquote2 && !incomment)
	inquote1 = 1;
      escape = 0;
      break;
    case '*':
      if (incomment)
	{
	  if ((c = get1c(dotc)) == '/')
	    {
	      if (out)
		fputs("*/", dapc);
	      c = get1c(dotc);
	      incomment = 0;
	    }
	  else
	    {
	      unget1c(c, dotc, NULL);
	      c = '*';
	    }
	}
      escape = 0;
      break;
    case '/':
      if (!incomment && !inquote1 && !inquote2)
	{
	  if ((c = get1c(dotc)) == '*')
	    {
	      if (out)
		fputs("/*", dapc);
	      c = get1c(dotc);
	      incomment = 1;
	    }
	  else
	    {
	      unget1c(c, dotc, NULL);
	      c = '/';
	    }
	}
      escape = 0;
      break;
    case '\\':
      if (!incomment && (inquote1 || inquote2))
	escape = 1;
      break;
    case EOF:
      if (inquote1)
	{
	  fprintf(stderr, "dappp:%s:%d: unmatched '\n", dotname, lineno);
	  exit(1);
	}
      if (inquote2)
	{
	  fprintf(stderr, "dappp:%s:%d: unmatched \"\n", dotname, lineno);
	  exit(1);
	}
      if (incomment)
	{
	  fprintf(stderr, "dappp:%s:%d: non-terminated comment\n", dotname, lineno);
	  exit(1);
	}
      if (escape)
	{
	  fprintf(stderr, "dappp:%s:%d: incomplete escape\n", dotname, lineno);
	  exit(1);
	}
      if (pound)
	{
	  fprintf(stderr, "dappp:%s:%d: incomplete #\n", dotname, lineno);
	  exit(1);
	}
      break;
    default:
      escape = 0;
      break;
    }
  if (out && c != EOF)
    putc(c, dapc);
  return c;
}

/* Get one token from the .c file.  If out is 1, copy the token to
 * the .dap.c file.  Returns 1 if token gotten, 0 if no token and EOF.  
 */
int gettoken(char token[], FILE *dotc, FILE *dapc, int out)
{
  int c;		/* character read from .c file */
  int t;		/* index to token character array */

  token[0] = '\0';
  while (white(c = dgetc(dotc, dapc, out)) || incomment || inquote1 || inquote2)
    ;
  t = 0;
  if (alpha(c))		/* name of function, variable, etc. */
    {
      for ( ; alphanum(c); c = dgetc(dotc, dapc, out))
	{
	  if (t < TOKLEN)
	    token[t++] = c;
	  else
	    {
	      token[t] = '\0';
	      fprintf(stderr, "dappp:%s:%d: token too long: %s\n",
		      dotname, lineno, token);
	      exit(1);
	    }
	}
      unget1c(c, dotc, (out ? dapc : NULL));
    }
  else if (num(c))	/* look for positive integers in #defines */
    {
      for ( ; num(c); c = dgetc(dotc, dapc, out))
	{
	  if (t < TOKLEN)
	    token[t++] = c;
	  else
	    {
	      token[t] = '\0';
	      fprintf(stderr, "dappp:%s:%d: token too long: %s\n",
		      dotname, lineno, token);
	      exit(1);
	    }
	}
      unget1c(c, dotc, (out ? dapc : NULL));
    }
  else if (c != EOF)
    token[t++] = c;
  token[t] = '\0';
  return (t > 0);
}

/* Enter new define.  */
void newdef(FILE *dotc, FILE *dapc)
{
  static char defstr[TOKLEN + 1];	/* string to be defined */
  static char defval[TOKLEN + 1]; /* defined as */
  int d;				/* index to defval */
  int c;				/* defval[d] */
  int v;				/* numerical value of defval */

  if (gettoken(defstr, dotc, dapc, 1))
    {
      if (gettoken(defval, dotc, dapc, 1))
	{
	  for (v = 0, d = 0; num(c = defval[d]); d++)
	    v = 10 * v + c - '0';
	  if (v > 0 && !c)
	    {
	      if (ndef < MAXDEF)
		{
		  strcpy(def[ndef].def_str, defstr);
		  def[ndef].def_val = v;
		  ndef++;
		}
	      else
		{
		  fprintf(stderr, "dappp:%s:%d: too many #defines\n",
			  dotname, lineno);
		  exit(1);
		}
	    }
	}
    }
}

/* Look up define; return positive if found, 0 otherwise */
int defval(char str[])
{
  int d;

  for (d = 0; d < ndef; d++)
    {
      if (!strcmp(def[d].def_str, str))
	return def[d].def_val;
    }
  return 0;
}

/* Preprocess variable declarations: read characters from .c file
 * without copying to .dap.c file, write calls to dap_vd and one of
 * dap_dl, dap_il, or dap_sl for double, int, or string variables,
 * respectively.  dap_vd (dap0.c) declares the variable and dap_dl,
 * dap_il, and dap_sl (dap0.c) point the internal dap storage to the variable
 * in the program.  The only declarations allowed are: double, one-dimensional
 * arrays of double, int, one-dimensional arrays of int, arrays of char.  
 */
void declare(FILE *dotc, FILE *dapc, char decl[])
{
  static char token[TOKLEN + 1];	/* the token read */
  static char tokdel[TOKLEN + 1];	/* the delimiter read */
  static char tokdim[TOKLEN + 1];	/* the array dimension read */
  int c;				/* character read from .c file */
  int dim;			/* dimension of array variable */
  int dimd;			/* index to tokdim */
  int d;				/* index for declaring array variable entries */
  long delpos;			/* file position of delimiter */

  while (gettoken(token, dotc, dapc, 0))
    {
      if ((delpos = ftell(dotc)) < 0)
	{
	  perror("dappp");
	  exit(1);
	}
      if (gettoken(tokdel, dotc, dapc, 0))
	{
	  if (!strcmp(tokdel, "["))
	    {
	      if (!gettoken(tokdim, dotc, dapc, 0))
		{
		  fprintf(stderr, "dappp:%s:%d: missing array dimension\n",
			  dotname, lineno);
		  exit(1);
		}
	      if (!(dim = defval(tokdim)))
		{
		  for (dimd = 0, dim = 0; num(c = tokdim[dimd]); dimd++)
		    dim = 10 * dim + c - '0';
		}
	      if (!dim)
		{
		  fprintf(stderr, "dappp:%s:%d: zero array dimension\n",
			  dotname, lineno);
		  exit(1);
		}
	      if (!gettoken(tokdel, dotc, dapc, 0))
		{
		  fprintf(stderr, "dappp:%s:%d: missing ]\n", dotname, lineno);
		  exit(1);
		}
	      if (strcmp(tokdel, "]"))
		{
		  fprintf(stderr, "dappp:%s:%d: expected ], got %s\n",
			  dotname, lineno, tokdel);
		  exit(1);
		}
	      if (!strcmp(decl, "int"))
		{
		  for (d = 0; d < dim; d++)
		    fprintf(dapc,
			    "dap_vd(\"%s[%d] 0\", 0);", token, d);
		  fprintf(dapc, "dap_il(\"%s\", %s);", token, token);
		}
	      else if (!strcmp(decl, "double"))
		{
		  for (d = 0; d < dim; d++)
		    fprintf(dapc,
			    "dap_vd(\"%s[%d] -1\", 0);", token, d);
		  fprintf(dapc, "dap_dl(\"%s\", %s);", token, token);
		}
	      else
		{
		  if (dim <= 1)
		    {
		      fprintf(stderr,
			      "dappp:%s:%d: dimension of character array must be at least 2\n",
			      dotname, lineno);
		      exit(1);
		    }
		  fprintf(dapc, "dap_vd(\"%s %d\", 0);", token, dim - 1);
		  fprintf(dapc, "dap_sl(\"%s\", %s);", token, token);
		}
	      if (!gettoken(tokdel, dotc, dapc, 0))
		{
		  fprintf(stderr,
			  "dappp:%s:%d: missing delimiter after string declaration\n",
			  dotname, lineno);
		  exit(1);
		}
	    }
	  else if (!strcmp(tokdel, ",") || !strcmp(tokdel, ";"))
	    {
	      if (!strcmp(decl, "int"))
		{
		  fprintf(dapc, "dap_vd(\"%s 0\", 0);", token);
		  fprintf(dapc, "dap_il(\"%s\", &%s);", token, token);
		}
	      else if (!strcmp(decl, "double"))
		{
		  fprintf(dapc, "dap_vd(\"%s -1\", 0);", token);
		  fprintf(dapc, "dap_dl(\"%s\", &%s);", token, token);
		}
	      else
		{
		  fprintf(stderr,
			  "dappp:%s:%d: string variables must be arrays with explicit dimension\n",
			  dotname, lineno);
		  exit(1);
		}
	    }
	}
      if (!strcmp(tokdel, ","))
	{
	  while (white(c = dgetc(dotc, dapc, 0)))
	    ;
	  unget1c(c, dotc, NULL);
	}
      else if (!strcmp(tokdel, ";"))
	break;
      else
	{
	  fprintf(stderr,
		  "dappp:%s:%d: expected `;' or `,', got %s\n",
		  dotname, lineno, tokdel);
	  exit(1);
	}
    }
}

/* Process the body of infile and inset statements.  For the declarations
 * that start the body, copy them, then follow them by function calls to
 * set up data links for input and output (see declare).  After the
 * declarations are processed, just copy until the end of the body of the
 * infile or inset statement.
 */
void preproc(FILE *dotc, FILE *dapc)
{
  int c;				/* character read */
  static char token[TOKLEN + 1];	/* token read */
  static char tokdel[TOKLEN + 1];	/* delimiter read */
  int isdecl;			/* flag: is it a declaration? */
  long decpos;			/* file position at start of current declaration */
  int decline;			/* line number at start of current declaration */
  long inpos;			/* file position at start of first declaration */
  int infline;			/* line number at start of first declaration */
  int indecl;			/* in declaration area of dotc */
  int brace;			/* depth of brace nesting */

  indecl = 0;
  if ((inpos = ftell(dotc)) < 0)
    {
      perror("dappp");
      exit(1);
    }
  infline = lineno;
  do	{
    if ((decpos = ftell(dotc)) < 0)
      {
	perror("dappp");
	exit(1);
      }
    decline = lineno;
    if (gettoken(token, dotc, dapc, 0) &&
	(!strcmp(token, "double") || !strcmp(token, "int") ||
	 !strcmp(token, "char")))
      {
	isdecl = 1;
	if (fseek(dotc, decpos, SEEK_SET) < 0)
	  {
	    perror("dappp");
	    exit(1);
	  }
	lineno = decline;
	while ((c = dgetc(dotc, dapc, 1)) != ';' && c != EOF)
	  ;
      }
    else
      isdecl = 0;
  } while (isdecl);
  if (fseek(dotc, inpos, SEEK_SET) < 0)
    {
      perror("dappp");
      exit(1);
    }
  lineno = infline;
  do	{
    if ((decpos = ftell(dotc)) < 0)
      {
	perror("dappp");
	exit(1);
      }
    decline = lineno;
    if (gettoken(token, dotc, dapc, 0) &&
	(!strcmp(token, "double") || !strcmp(token, "int") ||
	 !strcmp(token, "char")))
      {
	isdecl = 1;
	declare(dotc, dapc, token);
      }
    else
      isdecl = 0;
  } while (isdecl);
  if (fseek(dotc, decpos, SEEK_SET) < 0)
    {
      perror("dappp");
      exit(1);
    }
  lineno = decline;
  for (brace = 1; brace && gettoken(token, dotc, dapc, 1); )
    {
      if (!strcmp(token, "infile") || !strcmp(token, "inset") || !strcmp(token, "main"))
	{
	  if (gettoken(tokdel, dotc, dapc, 1))
	    {
	      if (!strcmp(tokdel, "("))
		{
		  fprintf(stderr,
			  "dappp:%s:%d: call to %s in infile or inset body\n",
			  dotname, lineno, token);
		  exit(1);
		}
	    }
	}
      else if (!strcmp(token, "{"))
	brace++;
      else if (!strcmp(token, "}"))
	--brace;
    }
}

/* Look for infile or inset statements.  */
int infile(FILE *dotc, FILE *dapc)
{
  char token[TOKLEN + 1];		/* could be infile or inset or main or not */
  char tokdel[TOKLEN + 1];	/* delimiter after token */
  int c;				/* character read */
  long dotcpos;			/* file position at start of main in dotc */
  long dapcpos;			/* file position at start of main in dapc */
  int paren;			/* depth of nesting of parentheses */

  while (gettoken(token, dotc, dapc, 1))
    {
      if (pound)
	{
	  if (column > 1)
	    {
	      if (!strcmp(token, "define"))
		newdef(dotc, dapc);
	      pound = 0;
	    }
	}
      else if (!strcmp(token, "main"))
	{
	  dotcpos = ftell(dotc) - 4;
	  dapcpos = ftell(dapc) - 4;
	  if (gettoken(tokdel, dotc, dapc, 1))
	    {
	      if (!strcmp(tokdel, "("))
		{
		  if (fseek(dotc, dotcpos, SEEK_SET) < 0)
		    {
		      perror("dappp");
		      exit(1);
		    }
		  if (fseek(dapc, dapcpos, SEEK_SET) < 0)
		    {
		      perror("dappp");
		      exit(1);
		    }
		  fputs("dap_", dapc);
		  gettoken(token, dotc, dapc, 1);
		  gettoken(tokdel, dotc, dapc, 1);
		}
	    }
	}
      else if (!strcmp(token, "infile") || !strcmp(token, "inset"))
	{
	  if (gettoken(tokdel, dotc, dapc, 1) && !strcmp(tokdel, "("))
	    {
	      for (paren = 1; paren && (c = dgetc(dotc, dapc, 1)) != EOF; )
		{
		  if (!incomment && !inquote1 && !inquote2)
		    {
		      if (c == '(')
			paren++;
		      else if (c == ')')
			--paren;
		    }
		}
	      putc(';', dapc);
	      while (white(c = dgetc(dotc, dapc, 1)) || incomment)
		;
	      if (c == '{')
		{
		  while (white(c = dgetc(dotc, dapc, 1)) || incomment)
		    ;
		  unget1c(c, dotc, dapc);
		}
	      else
		{
		  fprintf(stderr, "dappp:%s:%d: expected {, got %c\n",
			  dotname, lineno, c);
		  exit(1);
		}
	      return 1;
	    }
	  else
	    {
	      fprintf(stderr, "dappp:%s:%d: expected (, got %s\n",
		      dotname, lineno, tokdel);
	      exit(1);
	    }
	}
    }
  return 0;
}

int main(int argc, char **argv)
{
  FILE *dotc, *dapc;
  int namelen;
  char *dapname;

  while (--argc > 0)
    {
      argv++;
      namelen = strlen(*argv);
      if (namelen > 4 && !strcmp(*argv + namelen - 4, ".sas"))
	{
	  sastrans(*argv);
	  namelen -= 2;
	}
      if (namelen <= 2 || strcmp(*argv + namelen - 2, ".c"))
	{
	  fprintf(stderr, "dappp: file name does not end in .c: %s\n", *argv);
	  exit(1);
	}
      if (!(dotname = malloc(namelen + 1)))
	{
	  perror("dappp");
	  exit(1);
	}
      if (!(dapname = malloc(namelen + 5)))
	{
	  perror("dappp");
	  exit(1);
	}
      strcpy(dotname, *argv);
      strcpy(dapname, *argv);
      strcpy(dapname + namelen - 1, "dap.c");
      if (!(dotc = fopen(dotname, "r")))
	{
	  fputs("dappp:", stderr);
	  perror(dotname);
	  exit(1);
	}
      if (!(dapc = fopen(dapname, "w")))
	{
	  fputs("dappp:", stderr);
	  perror(dapname);
	  exit(1);
	}
      lineno = 0;
      column = 0;
      newline = 1;
      incomment = 0;
      inquote1 = 0;
      inquote2 = 0;
      escape = 0;
      ndef = 0;
      while (infile(dotc, dapc))
	preproc(dotc, dapc);
		
      fclose(dotc);
      fclose(dapc);
      free(dotname);
      free(dapname);
    }
  return 0;
}
