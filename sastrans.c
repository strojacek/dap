/* SAS to Dap translator */

/*  Copyright (C) 2003, 2004 Free Software Foundation, Inc.
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
#include "sas.h"
#include <stdlib.h>
#include <string.h>

/* step types */
#define DATA 1
#define PROC 2
#define UNKNOWN 3

int sastempnum; /* number of current temp dataset */
char sastmp[TOKENLEN + 1]; /* name of current temp dataset */
int saslineno; /* input line number */
extern int sashaspicts; /* are there picts? */
extern void importtrans(char *step, FILE *dapfile);
extern void surveyselecttrans(char *step, FILE *dapfile);
extern void unget1c(int c, FILE *dotc, FILE *dapc);
static char *keyword[] = /* SAS keywords inside data step */
{
  "set",
  "infile",
  "input",
  "length",
  "merge",
  "by",
  "drop",
  "keep",
  "output",
  "do",
  "end",
  "if",
  "then",
  "else",
  "while",
  ""
};

int iskeyword(char *str)
{
  int k;

  for (k = 0; *keyword[k]; k++)
    {
      if (!linecmp(str, keyword[k]))
	return 1;
    }
  return 0;
}

void namecvt(char *sasname)
{
  int dot;

  for (dot = 0; sasname[dot]; dot++)
    ;
  while (--dot >= 0 && sasname[dot] != '.')
    ;
  if (dot <= 0)
    {
      fprintf(stderr, "sas: %s not a .sas file\n", sasname);
      exit(1);
    }
  strcpy(sasname + dot, ".c");
}

int is_space(int c)
{
  return c == EOF || c == ' ' || c == '\t' || c == '\n';
}

int sasgetc(FILE *sasfile)
{
  int c;

  c = dgetc(sasfile, NULL, 0); /* process comments */
  if (c == '\n')
    saslineno++;
  return c;
}

/* quotes are not tokens; a token that starts with a quote must end
 * with a matching quote
 */
int sastoken(FILE *sasfile, char *token)
{
  int t; /* index to token */
  int c; /* input character */
  int cprev; /* previous c for double character tokens */
  int quote; /* to save quote character encountered (single or double) */

  t = 0;
  while ((c = sasgetc(sasfile)) == ' ' || c == '\t' || c == '\n' || incomment)
    ;
  if (c == EOF)
    {
      token[0] = '\0';
      return 0;
    }
  if ((('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) || c == '_') /* string */
    {
      for (t = 0;
	   ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') ||
	     ('0' <= c && c <= '9') || c == '_' || c == '.';
	   c = sasgetc(sasfile))
	{
	  if (t < TOKENLEN)
	    token[t++] = c;
	  else
	    {
	      token[t] = '\0';
	      fprintf(stderr, "sastrans: before %d: token too long: %s\n", saslineno, token);
	      exit(1);
	    }
	}
    }
  else if (c == '.' || ('0' <= c && c <= '9')) /* number */
    {
      for (t = 0; c == '.' || ('0' <= c && c <= '9'); c = sasgetc(sasfile))
	{
	  if (t < TOKENLEN)
	    token[t++] = c;
	  else
	    {
	      token[t] = '\0';
	      fprintf(stderr, "sastrans: before %d: token too long: %s\n", saslineno, token);
	      exit(1);
	    }
	}
    }
  else if (c == '=' || c == '+' || c == '-' || c == '*' || c == '/' || c == '>' ||
	   c == '<' || c == '^' || c == '~' || c == '!' || c == '&' || c == '|')
    {
      t = 0;
      token[t++] = c;
      cprev = c;
      c = sasgetc(sasfile);
      if (c == '=' || (cprev == c))
	{
	  if (t < TOKENLEN)
	    token[t++] = c;
	  else
	    {
	      token[t] = '\0';
	      fprintf(stderr, "sastrans: before %d: token too long: %s\n", saslineno, token);
	      exit(1);
	    }
	  c = sasgetc(sasfile);
	}
    }
  else if (c == '"' || c == '\'')
    {
      quote = c;
      t = 0;
      token[t++] = c;
      cprev = c;
      c = sasgetc(sasfile);
      for ( ; c != EOF && c != quote; cprev = c, c = sasgetc(sasfile))
	{
	  if (c == '\n')
	    {
	      if (cprev == '\\')
		--t;
	      else
		break;
	    }
	  else if (t < TOKENLEN)
	    token[t++] = c;
	  else
	    {
	      token[t] = '\0';
	      fprintf(stderr, "sastrans: before %d: token too long: %s\n", saslineno, token);
	      exit(1);
	    }
	}
      if (t < TOKENLEN)
	token[t++] = c;
      else
	{
	  token[t] = '\0';
	  fprintf(stderr, "sastrans: before %d: token too long: %s\n", saslineno, token);
	  exit(1);
	}
      c = sasgetc(sasfile);
    }
  else
    {
      t = 0;
      token[t++] = c;
      c = sasgetc(sasfile);
    }
  token[t] = '\0';
  while (c != EOF && c == ' ' || c == '\t' || c == '\n' || incomment)
    c = sasgetc(sasfile);
  if (c != EOF)
    {
      unget1c(c, sasfile, NULL);
      if (c == '\'')
	inquote1 = !inquote1;
      else if (c == '"')
	inquote2 = !inquote2;
      if (c == '\n')
	--saslineno;
    }
  return t;
}

/* puts token (i.e., line) to dapfile */
int lineput(char *line, FILE *dapfile)
{
  int l;

  for (l = 0; line[l] && line[l] != '\n'; l++)
    putc(line[l], dapfile);
  return l;
}

int getstatement(FILE *sasfile, char *statement)
{
  int s; /* index to statement */
  static char token[TOKENLEN + 1];
  int toklen; /* length of token */

  for (s = 0; (toklen = sastoken(sasfile, token)) && linecmp(token, ";"); )
    {
      if (s + toklen + 1 < STATELEN)
	{
	  strcpy(statement + s, token);
	  s += toklen;
	  statement[s++] = '\n';
	}
    }
  if (!linecmp(token, ";")) /* if there was at least a ; */
    {
      statement[s++] = ';';
      statement[s++] = '\n';
    }
  statement[s] = '\0';
  return s;
}

/* If l1 not NULL, copy up to newline. Return number of chars read (without the null) */
int linecpy(char *l1, char *l2)
{
  char *start;

  start = l2;
  while (*l2 && *l2 != '\n')
    {
      if (l1)
	*l1++ = *l2++;
      else
	l2++;
    }
  if (l1)
    *l1 = '\0';
  return l2 - start;
}

/* copy lines up to term to file, converting '\n' to ' ', report number of chars,
 * also put ' ' at end
 */
int putlines(char *line, FILE *file, int term)
{
  char *start;

  for (start = line; *line && *line != term; line++)
    {
      if (*line == '\n')
	putc(' ', file);
      else
	putc(*line, file);
    }
  putc(' ', file);
  return line - start;
}

/* converts to lower case */
int lower(int c)
{
  if ('A' <= c && c <= 'Z')
    return c + 'a' - 'A';
  else
    return c;
}

/* compares two "lines" or strings, ignores case */
int linecmp(char *l1, char *l2)
{
  while (lower(*l1) == lower(*l2) &&
	 *l1 && *l2 && *l1 != '\n' && *l2 != '\n')
    {
      l1++;
      l2++;
    }
  return (*l1 && *l1 != '\n') || (*l2 && *l2 != '\n');
}

/* Get one complete data or proc step. Return type else return 0
 * if failed.
 */
int getstep(FILE *sasfile, char *step)
{
  static char statement[STATELEN + 1];
  int steptype;
  int s; /* index to step */
  static int statelen = -1; /* length of token */

  if (statelen < 0)
    {
      if (!(statelen = getstatement(sasfile, statement)))
	return 0;
    }
  if (!linecmp(statement, "data"))
    steptype = DATA;
  else if (!linecmp(statement, "proc"))
    steptype = PROC;
  else
    return 0;
  strcpy(step, statement);
  s = statelen;
  while ((statelen = getstatement(sasfile, statement)))
    {
      if (!linecmp(statement, "data") &&
	  (alpha(statement[5]) || statement[5] == ';' || statement[5] == '('))
	break;
      else if (!linecmp(statement, "proc") && alpha(statement[5]))
	break;
      if (s + statelen + 1 < STEPLEN)
	{
	  strcpy(step + s, statement);
	  s += statelen;
	}
      else
	{
	  fprintf(stderr,
		  "sastrans: before %d: %s step too long\n",
		  saslineno, ((steptype == DATA) ? "data" : "proc"));
	  exit(1);
	}
    }
  step[s] = '\0';
  return steptype;
}

int findvar(char *varname, char var[][TOKENLEN + 1], int nvars)
{
  int v;

  for (v = 0; v < nvars; v++)
    {
      if (!linecmp(varname, var[v]))
	break;
    }
  if (v < MAXVARS - 1)
    strcpy(var[v], varname);
  return v;
}

/* if relational op, translates to C, else just copies token;
 * returns number of characters to advance
 */
int opfix(char *token, FILE *dapfile)
{
  int t; /* index to token */

  if (inquote1 || inquote2)
    return lineput(token, dapfile) + 1;
  else if (!linecmp(token, "="))
    {
      fputs("==", dapfile);
      return 2;
    }
  else if (!linecmp(token, "^=") || !linecmp(token, "~="))
    {
      fputs("!=", dapfile);
      return 3;
    }
  else if (!linecmp(token, "&"))
    {
      fputs("&&", dapfile);
      return 2;
    }
  else if (!linecmp(token, "|"))
    {
      fputs("||", dapfile);
      return 2;
    }
  else if (!linecmp(token, "^") || !linecmp(token, "~"))
    {
      fputs("!", dapfile);
      return 2;
    }
  else if (!strncmp(token, "first.", 6))
    {
      putc('_', dapfile);
      for (t = 6; token[t] && token[t] != '\n'; t++)
	putc(token[t], dapfile);
      putc('_', dapfile);
      return t + 1;
    }
  else if (!linecmp(token, "["))
    {
      fputs("[(int)(", dapfile); /* C-style array subscripting */
      return 2;
    }
  else if (!linecmp(token, "]"))
    {
      fputs(")-1]", dapfile); /* C-style array subscripting */
      return 2;
    }
  else
    return lineput(token, dapfile) + 1;
}

char *nonaction(char *step) /* is not an action statement? */
{
  static char type[TOKENLEN + 1];

  if (!linecmp(step, "set") || !linecmp(step, "infile") ||
      !linecmp(step, "input") || !linecmp(step, "length") ||
      !linecmp(step, "merge") || !linecmp(step, "by") ||
      !linecmp(step, "drop") || !linecmp(step, "keep") ||
      !linecmp(step, "title"))
    {
      linecpy(type, step);
      return type;
    }
  return NULL;
}

/* translates statement to C, returns number number of chars processed */
int statementtrans(char *step, FILE *dapfile, int *isoutput)
{
  int s; /* index to step */
  char *statementtype;

  s = 0;
  if ((statementtype = nonaction(step)))
    {
      while (step[s] && step[s] != ';')
	s++;
      if (step[s] == ';')
	return s + 2;
      else
	{
	  fprintf(stderr,
		  "sastrans: before %d: missing ; after %s statement in data step\n",
		  saslineno, statementtype);
	  exit(1);
	}
    }
  else if (!linecmp(step, "output"))
    {
      fputs("output();\n", dapfile);
      s += 7;
      *isoutput = 1;
      statementtype = "output";
    }
  else if (!linecmp(step, "end"))
    {
      fputs("}\n", dapfile);
      s += 4;
      statementtype = "end";
    }
  else if (!linecmp(step, "if"))
    {
      s += 3;
      fputs("if (", dapfile);
      while (step[s] && linecmp(step + s, "then"))
	s += opfix(step + s, dapfile);
      fputs(")\n", dapfile);
      s += 5; /* get past the then */
      s += statementtrans(step + s, dapfile, isoutput) - 2;
      /* need - 2 because recursive call picked up the ; */
      statementtype = "if";
    }
  else if (!linecmp(step, "else"))
    {
      fputs("else\n", dapfile);
      s += 5;
      return s;
    }
  else if (!linecmp(step + s, "do")) /* for do or do while */
    {
      s += 3;
      if (!linecmp(step + s, "while")) /* yes, it's a do while */
	{
	  s += 6;
	  if (linecmp(step + s, "("))
	    {
	      fprintf(stderr,
		      "sastrans: before %d: missing ( after do while\n", saslineno);
	      exit(1);
	    }
	  s += 2;
	  fputs("while (", dapfile);
	  while (step[s] && linecmp(step + s, ")"))
	    s += opfix(step + s, dapfile);
	  fputs(")\n{\n", dapfile);
	  s += 2; /* get past the ) */
	  statementtype = "do while";
	}
      else /* no, just a do */
	{
	  fputs("{\n", dapfile);
	  statementtype = "do";
	}
    }
  else /* assignment? */
    {
      while (step[s] && step[s] != ';')
	{
	  if (step[s] == '\n')
	    putc(' ', dapfile);
	  else if (step[s] == '[') /* C-style array subscripting */
	    fputs("[(int)(", dapfile);
	  else if (step[s] == ']') /* C-style array subscripting */
	    fputs(")-1]", dapfile);
	  else
	    putc(step[s], dapfile);
	  s++;
	}
      putc(';', dapfile);
      putc('\n', dapfile);
      statementtype = "assignment";
    }
  if (linecmp(step + s, ";"))
    {
      fprintf(stderr,
	      "sastrans: before %d: missing ; after %s statement in data step\n",
	      saslineno, statementtype);
      exit(1);
    }
  s += 2;
  return s;
}

void globaltrans(char *statement, FILE *dapfile)
{
  int s; /* index to statement */

  if (!linecmp(statement, "title"))
    {
      fputs("title(", dapfile);
      if (statement[6] == '"')
	{
	  for (s = 6; statement[s] && statement[s] != '\n'; s++)
	    putc(statement[s], dapfile);
	  s++;
	  if (statement[s] != ';')
	    {
	      fprintf(stderr,
		      "sastrans: before %d: missing ; at end of title statement\n",
		      saslineno);
	      exit(1);
	    }
	}
      else if (statement[6] == ';')
	fputs("NULL", dapfile);
      else
	{
	  fprintf(stderr,
		  "sastrans: before %d: title must begin with \"\n", saslineno);
	  exit(1);
	}
      fputs(");\n", dapfile);
    }
  else
    {
      fprintf(stderr, "sastrans: before %d: unknown global statement: %s\n", saslineno, statement);
      exit(1);
    }
}

void datatrans(char *step, FILE *dapfile)
{
  static char inputname[TOKENLEN + 5]; /* +4 extra for .srt if needed */
  static char outputname[TOKENLEN + 1];
  int setnum; /* to count to 2 for "merge" */
  static char delim[5]; /* need 5 for, for example, "\t" */
  static char var[MAXVARS][TOKENLEN + 1];
  static int len[MAXVARS]; /* descriptor for each var: DBL, INT, or length */
  int vn; /* variable number */
  int nvars;
  static char varname[TOKENLEN + 1];
  int v; /* index to varname */
  int s; /* index to step */
  int sincr; /* increment for s */
  int inputisfile; /* is input a file? 0 if not or, if so, position following "infile" */
  static char skip[TOKENLEN + 1]; /* number of lines to skip on input */
  int inputisnull; /* but is that file just NULL? */
  int inputcolumn; /* is input in columns? */
  int sic; /* index to step if input is column */
  int startcol, endcol; /* start and end columns of column input */
  int isdouble; /* are there vars of type double? */
  int firstdec; /* first declaration on line (no comma) */
  int isoutput; /* is there an output statement? */
  int dropping; /* is there a drop option or statement? */
  int keeping; /* is there a keep option or statement? */
  int start; /* start of first.variable name for dropping */
  int bymark; /* if there was a "by" statement, its position, otherwise -1 */
  int nby; /* number of "by" variables */
  int b; /* index to "by" vars */
  int i; /* index to constant string for character variables */
  
  nvars = 0;
  dropping = 0;
  keeping = 0;

  /* Because the order of statements differs between SAS and Dap, we pass
   * through step several times.
   */

  fputs("sastrans: processing data step...\n", stderr);
  fflush(stderr);

  bymark = isby(step); /* get this out of the way */

  /* first take care of globals */
  if ((s = findstatement(step, "title")))
    globaltrans(step + s - 6, dapfile);

  /* then we look for the input file name */
  inputisnull = 0; /* not NULL until proven guilty */
  inputcolumn = 0; /* not unless columns found */
  delim[0] = '\0';
  if ((inputisfile = findstatement(step, "infile")))
    {
      s = inputisfile + linecpy(inputname, step + inputisfile) + 1;
      fprintf(dapfile, "infile(%s, ", inputname);
      if ((sincr = getoption(step + s, "delimiter", delim, 1)) ||
	  (sincr = getoption(step + s, "dlm", delim, 1)))
	{
	  s += sincr;
	  fputs(delim, dapfile);
	}
      else if ((sic = findstatement(step, "input"))) /* do we have column input? */
	{
	  while (step[sic] && step[sic] != ';')
	    {
	      while (step[sic] && step[sic] != '\n') /* skip variable name */
		sic++;
	      sic++; /* get to next variable or column number */
	      if (num(step[sic])) /* looks like a column number */
		{
		  if (!inputcolumn) /* haven't started yet */
		    {
		      inputcolumn = 1;
		      putc('"', dapfile);
		      endcol = 0;
		    }
		  for (startcol = 0; step[sic] && num(step[sic]); sic++)
		    startcol = 10 * startcol + step[sic] - '0';
		  if (step[sic] != '\n' || startcol != endcol + 1)
		    {
		      fprintf(stderr,
			      "sastrans: before %d: bad start column in input statement.\n",
			      saslineno);
		      exit(1);
		    }
		  sic++; /* get to next variable or - */
		  if (step[sic] == '-') /* we have an end column */
		    {
		      for (sic += 2, endcol = 0; step[sic] && num(step[sic]); sic++)
			endcol = 10 * endcol + step[sic] - '0';
		      if (step[sic] != '\n')
			{
			  fprintf(stderr,
				  "sastrans: before %d: bad end column in input statement.\n",
				  saslineno);
			  exit(1);
			}
		      sic++; /* get to next variable or - */
		    }
		  else
		    endcol = startcol;
		  fprintf(dapfile, "x%d", endcol - startcol + 1);
		}
	      else
		break;
	    }
	}
      if (inputcolumn)
	fputs("\"", dapfile);
      else if (!delim[0])
	fputs("\" \"", dapfile);
      fputs(")\n{\n", dapfile);
    }
  else if ((s = findstatement(step, "set")))
    {
      s += linecpy(inputname, step + s) + 1;
      fprintf(dapfile, "inset (\"%s\")\n{\n", inputname);
      if (step[s] != ';')
	{
	  fprintf(stderr,
		  "sastrans: before %d: missing ; or extra characters at end of set statement.\n",
		  saslineno);
	  exit(1);
	}
    }
  else if ((s = findstatement(step, "merge")))
    {
      fputs("merge (\"", dapfile);
      for (setnum = 0; setnum < 2; setnum++)
	{
	  s += linecpy(inputname, step + s) + 1;
	  fprintf(dapfile, "%s\", \"", inputname);
	  if (!linecmp(step + s, "(")) /* have "drop" or "keep" */
	    {
	      s += 2;
	      if (!linecmp(step + s, "keep") || !linecmp(step + s, "drop"))
		{
		  if (step[s] == 'd') /* for drop */
		    putc('!', dapfile);
		  s += 5;
		  if (linecmp(step + s, "="))
		    {
		      fprintf(stderr,
			      "sastrans: before %d: missing = after keep or drop option in merge statement.\n",
			      saslineno);
		      exit(1);
		    }
		  s += 2; /* to next token */
		  s += putlines(step + s, dapfile, ')');
		  if (step[s] != ')')
		    {
		      fprintf(stderr,
			      "sastrans: before %d: missing ) after keep or drop option in merge statement.\n",
			      saslineno);
		      exit(1);
		    }
		  s += 2;
		}
	      else
		{
		  fprintf(stderr,
			  "sastrans: before %d: invalid dataset option in merge statement.\n",
			  saslineno);
		  exit(1);
		}
	    }
	  fputs("\", \"", dapfile);
	}
      if (step[s] != ';')
	{
	  fprintf(stderr,
		  "sastrans: before %d: missing ; at end of merge statement.\n",
		  saslineno);
	  exit(1);
	}
      copylist(step, "by", dapfile);
      sprintf(sastmp, "sastmp%02d", ++sastempnum);
      strcpy(inputname, sastmp);
      fprintf(dapfile, "\", \"%s\");\n", sastmp);
      fprintf(dapfile, "inset(\"%s\")\n{\n", sastmp);
    }
  else /* no infile or set or merge found */
    {
      inputisnull = 1;
      fputs("infile (NULL, NULL)\n{\n", dapfile);
    }

  /* now we look for length statement declaring string variables */
  if ((s = findstatement(step, "length")))
    {
      fputs("char ", dapfile);
      firstdec = 1;
      while (step[s] && step[s] != ';')
	{
	  s += linecpy(varname, step + s) + 1;
	  if (findvar(varname, var, nvars) == nvars)
	    {
	      if (firstdec)
		firstdec = 0;
	      else
		putc(',', dapfile);
	      fprintf(dapfile, "%s[", varname);
	    }
	  else
	    {
	      fprintf(stderr, "sastrans: before %d: redeclaration of %s\n",
		      saslineno, varname);
	      exit(1);
	    }
	  if (linecmp(step + s, "$"))
	    {
	      fprintf(stderr,
		      "sastrans: before %d: missing $ in length statement for %s\n",
		      saslineno, varname);
	      exit(1);
	    }
	  s += 2;
	  s += linecpy(varname, step + s) + 1;
	  if (!sscanf(varname, "%d", len + nvars) || len[nvars] <= 0)
	    {
	      fprintf(stderr,
		      "sastrans: before %d: bad length in length statement: %s\n",
		      saslineno, varname);
	      exit(1);
	    }
	  fprintf(dapfile, "%d]", len[nvars] + 1);
	  nvars++;
	}
      if (step[s] != ';')
	{
	  fprintf(stderr,
		  "sastrans: before %d: missing ; or extra characters at end of length statement.\n",
		  saslineno);
	  exit(1);
	}
      fputs(";\n", dapfile);
    }

  /* now look for variables and declare them: if not declared with "length"
   * statement, then assume double
   */
  /* first see if there are any */
  isdouble = 0;
  /* check "input" statement */
  if ((s = findstatement(step, "input")))
    {
      while (step[s] && step[s] != ';')
	{
	  s += linecpy(varname, step + s) + 1;
	  if (findvar(varname, var, nvars) == nvars) /* if not declared in length statement */
	    {
	      isdouble = 1; /* then it's a double */
	      break;
	    }
	  if (inputcolumn) /* this was determined previously */
	    {
	      while (step[s] && num(step[s])) /* skip column number */
		s++;
	      s++; /* to next column number or variable */
	      if (step[s] == '-')
		{
		  for (s += 2; step[s] && num(step[s]); s++) /* skip column number */
		    ;
		  s++; /* to next column number or variable */
		}
	    }
	}
    }
  /* skip past data statement */
  for (s = 0; step[s] && step[s] != ';'; s++)
    ;
  if (!step[s])
    {
      fprintf(stderr,
	      "sastrans: before %d: null data step body or missing ; in data statement.\n",
	      saslineno);
      exit(1);
    }
  for (s += 2; !isdouble && step[s]; s += 2)
    {
      if (nonaction(step + s))
	{
	  while (step[s] && step[s] != ';')
	    s++;
	}
      else
	{
	  while (!isdouble && step[s] && step[s] != ';')
	    {
	      if ((('a' <= step[s] && step[s] <= 'z') || step[s] == '_')
		  && !iskeyword(step + s))
		{
		  s += linecpy(varname, step + s) + 1;
		  if (step[s] != '(' && strncmp(varname, "first.", 6) &&
		      findvar(varname, var, nvars) == nvars)
		    {
		      isdouble = 1;
		      break;
		    }
		}
	      else
		{
		  while (step[s] && step[s] != '\n')
		    s++;
		  s++;
		}
	    }
	}
    }
  /* now declare them */
  if (isdouble)
    {
      fputs("double ", dapfile);
      firstdec = 1;
      /* now do vars from input statement, if exists */
      if ((s = findstatement(step, "input")))
	{
	  while (step[s] && step[s] != ';')
	    {
	      s += linecpy(varname, step + s) + 1;
	      if (findvar(varname, var, nvars) == nvars) /* not declared in length statement */
		{
		  if (firstdec)
		    firstdec = 0;
		  else
		    putc(',', dapfile);
		  len[nvars] = DBL;
		  nvars++;
		  fputs(varname, dapfile);
		}
	      if (inputcolumn) /* this was determined previously */
		{
		  while (step[s] && num(step[s])) /* skip column number */
		    s++;
		  s++; /* to next column number or variable */
		  if (step[s] == '-')
		    {
		      for (s += 2; step[s] && num(step[s]); s++) /* skip column number */
			;
		      s++; /* to next column number or variable */
		    }
		}
	    }
	}
      /* skip past data statement */
      for (s = 0; step[s] && step[s] != ';'; s++)
	;
      if (!step[s])
	{
	  fprintf(stderr,
		  "sastrans: before %d: null data step body or missing ; in data statement.\n",
		  saslineno);
	  exit(1);
	}
      for (s += 2; step[s]; s += 2)
	{
	  if (nonaction(step + s))
	    {
	      while (step[s] && step[s] != ';')
		s++;
	    }
	  else
	    {
	      while (step[s] && step[s] != ';')
		{
		  if ((('a' <= step[s] && step[s] <= 'z') || step[s] == '_')
		      && !iskeyword(step + s))
		    {
		      s += linecpy(varname, step + s) + 1;
		      if (step[s] != '(' && strncmp(varname, "first.", 6) &&
			  findvar(varname, var, nvars) == nvars)
			{
			  if (firstdec)
			    firstdec = 0;
			  else
			    putc(',', dapfile);
			  fputs(varname, dapfile);
			  len[nvars] = DBL;
			  nvars++;
			}
		    }
		  else
		    {
		      while (step[s] && step[s] != '\n')
			s++;
		      s++;
		    }
		}
	    }
	}
      fputs(";\n", dapfile);
    }

  /* if there are "by" variables, we'll need an array of ints */
  if (bymark >= 0)
    {
      fputs("int", dapfile);
      /* now we have to declare "by" string vars for first.variables */
      for (s = bymark, nby = 0; step[s] && step[s] != ';'; nby++)
	{
	  s += linecpy(varname, step + s) + 1;
	  if (nby)
	    putc(',', dapfile);
	  fprintf(dapfile, " _%s_", varname);
	}
      fprintf(dapfile, ", _partv_[%d], _firstobs_;\n", nby);
    }

  /* now, if input is file, look for input statement */
  if (inputisfile)
    {
      if ((s = findstatement(step, "input")))
	{
	  fputs("input(\"", dapfile);
	  while (step[s] && step[s] != ';')
	    {
	      while (step[s] && step[s] != '\n')
		{
		  putc(step[s], dapfile);
		  s++;
		}
	      s++; /* to next variable or column number */
	      putc(' ', dapfile);
	      if (inputcolumn) /* this was determined previously */
		{
		  while (step[s] && num(step[s])) /* skip column number */
		    s++;
		  s++; /* to next column number or variable */
		  if (step[s] == '-')
		    {
		      for (s += 2; step[s] && num(step[s]); s++) /* skip column number */
			;
		      s++; /* to next column number or variable */
		    }
		}
	    }
	  fputs("\");\n", dapfile);
	  if (step[s] != ';')
	    {
	      fprintf(stderr,
		      "sastrans: before %d: missing ; in input statement.\n",
		      saslineno);
	      exit(1);
	    }
	}
      else
	{
	  fprintf(stderr,
		  "sastrans: before %d: infile statement present but missing input statement.\n",
		  saslineno);
	  exit(1);
	}
    }

  s = 5; /* get to token following "data" */
  if ('a' <= step[s] && step[s] <= 'z')
    {
      s += linecpy(outputname, step + s) + 1;
      strcpy(sastmp, outputname);
      if (step[s] != '(' && step[s] != ';')
	{
	  fprintf(stderr,
		  "sastrans: before %d: missing ; or extra characters at end of data statement.\n",
		  saslineno);
	  exit(1);
	}
    }
  else
    {
      sprintf(sastmp, "sastmp%02d", ++sastempnum);
      strcpy(outputname, sastmp);
    }

  fprintf(dapfile, "outset(\"%s\", \"", outputname);

  if (step[s] == '(') /* output dataset options */
    {
      s += 2;
      if (!linecmp(step + s, "drop"))
	{
	  dropping = 1;
	  putc('!', dapfile);
	}
      else if (!linecmp(step + s, "keep"))
	keeping = 1;
      else
	{
	  fprintf(stderr,
		  "sastrans: before %d: bad option for data statement.\n",
		  saslineno);
	  exit(1);
	}
      s += 5;
      if (linecmp(step + s, "="))
	{
	  fprintf(stderr,
		  "sastrans: before %d: missing = after option name in data statement.\n",
		  saslineno);
	  exit(1);
	}
      s += 2;
      s += putlines(step + s, dapfile, ')');
      if (step[s] != ')')
	{
	  fprintf(stderr,
		  "sastrans: before %d: missing ) after option for data statement.\n",
		  saslineno);
	  exit(1);
	}
      s += 2;
      if (step[s] != ';')
	{
	  fprintf(stderr,
		  "sastrans: before %d: missing ; at end of data statement.\n",
		  saslineno);
	  exit(1);
	}
    }
  else if ((s = findstatement(step, "drop")))
    {
      dropping = 1;
      putc('!', dapfile);
      while (step[s] && step[s] != ';')
	{
	  if (step[s] == '\n')
	    putc(' ', dapfile);
	  else if (alphanum(step[s]))
	    putc(step[s], dapfile);
	  else
	    {
	      fprintf(stderr,
		      "sastrans: before %d: invalid character %c in variable name in drop statement.\n",
		      saslineno, step[s]);
	      exit(1);
	    }
	  s++;
	}
    }
  else if ((s = findstatement(step, "keep")))
    {
      keeping = 1;
      s += putlines(step + s, dapfile, ';');
    }

  /* now need to drop the first.variables unless there's dropping or no keeping */
  if ((dropping || !keeping) && (s = bymark) >= 0)
    {
      start = 1;
      if (!dropping)
	fputs("!_firstobs_ _partv_ ", dapfile);
      while (step[s] && step[s] != ';')
	{
	  if (start)
	    putc('_', dapfile);
	  if (step[s] == '\n')
	    {
	      fputs("_ ", dapfile);
	      start = 1;
	    }
	  else
	    {
	      putc(step[s], dapfile);
	      start = 0;
	    }
	  s++;
	}
    }

  fputs("\");\n", dapfile);

      /* if there's a "by" statement, need to set up first.variables */
  if ((s = bymark) >= 0)
    {
      fputs("dap_list(\"", dapfile);
      copylist(step, "by", dapfile);
      fprintf(dapfile, "\", _partv_, %d);\n", nby);
      /* and mark first obs */
      fputs("_firstobs_ = 1;\n", dapfile);
    }
  /* initialize null terminators of character variables */
  for (v = 0; v < nvars; v++)
    {
      if (len[v] > 0) /* char variable */
	fprintf(dapfile, "%s[%d] = '\\0';\n", var[v], len[v]);
    }

  if (!inputisnull)
    {
      if (inputisfile && (s = getoption(step + inputisfile, "firstobs", skip, 1)))
	fprintf(dapfile, "skip(%s - 1);\n", skip);
      fputs("while (step())\n{\n", dapfile);
      if ((s = bymark) >= 0)
	{
	  for (b = 1; b <= nby; b++)
	    {
	      fprintf(dapfile, "if (_firstobs_ || dap_newpart(_partv_, %d))\n", b);
	      s += linecpy(varname, step + s) + 1;
	      fprintf(dapfile, "_%s_ = 1;\nelse _%s_ = 0;\n", varname, varname);
	    }
	}
    }

  /* now copy action statements */
  /* skip past data statement */
  for (s = 0; step[s] && step[s] != ';'; s++)
    ;

  if (!step[s])
    {
      fprintf(stderr,
	      "sastrans: before %d: null data step body or missing ; in data statement.\n",
	      saslineno);
      exit(1);
    }
  for (s += 2, isoutput = 0; step[s]; )
    s += statementtrans(step + s, dapfile, &isoutput);

  if (!isoutput)
    fputs("output();\n", dapfile);
  if (!inputisnull)
    {
      if (bymark >= 0)
	fputs("_firstobs_ = 0;\n", dapfile);
      fputs("}\n", dapfile);
    }
  fputs("}\n", dapfile);
}

void proctrans(char *step, FILE *dapfile)
{
  int s; /* index to step */
  char procname[TOKENLEN + 1];

  linecpy(procname, step + 5);
  fprintf(stderr, "sastrans: processing proc %s...\n", procname);
  fflush(stderr);

  /* look for globals */
  if (linecmp(step + 5, "dap") && (s = findstatement(step, "title")))
    globaltrans(step + s - 6, dapfile);

  if (!linecmp(step + 5, "print"))
    printtrans(step + 11, dapfile);
  else if (!linecmp(step + 5, "means"))
    meanstrans(step + 11, dapfile);
  else if (!linecmp(step + 5, "sort"))
    sorttrans(step + 10, dapfile);
  else if (!linecmp(step + 5, "chart"))
    charttrans(step + 11, dapfile);
  else if (!linecmp(step + 5, "datasets"))
    datasetstrans(step + 14, dapfile);
  else if (!linecmp(step + 5, "freq"))
    freqtrans(step + 10, dapfile);
  else if (!linecmp(step + 5, "tabulate"))
    tabulatetrans(step + 14, dapfile);
  else if (!linecmp(step + 5, "corr"))
    corrtrans(step + 10, dapfile);
  else if (!linecmp(step + 5, "plot"))
    plottrans(step + 10, dapfile);
  else if (!linecmp(step + 5, "rank"))
    ranktrans(step + 10, dapfile);
  else if (!linecmp(step + 5, "univariate"))
    univariatetrans(step + 16, dapfile);
  else if (!linecmp(step + 5, "glm"))
    glmtrans(step + 9, dapfile);
  else if (!linecmp(step + 5, "logistic"))
    logistictrans(step + 14, dapfile);
  else if (!linecmp(step + 5, "npar1way"))
    npar1waytrans(step + 14, dapfile);
  else if (!linecmp(step + 5, "reg"))
    regtrans(step + 9, dapfile);
  else if (!linecmp(step + 5, "dap"))
    daptrans(step + 9, dapfile);
   else if (!linecmp(step + 5, "import"))
    importtrans(step + 9, dapfile);
   else if (!linecmp(step + 5, "surveyselect"))
    surveyselecttrans(step + 9, dapfile);
  else
    {
      for (s = 5; step[s] && step[s] != '\n'; s++)
	;
      step[s] = '\0';
      fprintf(stderr, "sastrans: before %d: unknown proc.\n", saslineno);
      exit(1);
    }
}

void header(FILE *dap)
{
  fputs("#include <dap.h>\n", dap);
  fputs("void main()\n", dap);
  fputs("{\n", dap);
  fprintf(dap, "pict *_saspict_[%d];\n", MAXPICTS); /* alloc pict lists */
  fprintf(dap, "int _saspictcnt_[%d];\n", MAXPICTS); /* number of picts in each array */
  fprintf(dap, "int _saspictpage_[%d];\n", MAXPICTS); /* number of picts per page */
  fputs("int _sasnpicts_ = 0, _saspictn_, _saspictindex_;\n", dap);
}

void trailer(FILE *dap)
{
  if (sashaspicts)
    {
      fprintf(dap, "pict_port(%d);\n", MAXPICTS);
      fputs("for (_saspictn_ = 0; _saspictn_ < _sasnpicts_; _saspictn_++)\n{\n", dap);
      fputs("for (_saspictindex_ = 0; _saspictindex_ < _saspictcnt_[_saspictn_];", dap);
      fputs("_saspictindex_++)\n{\n", dap);
      fputs("pict_page();\n", dap);
      fputs("pict_show(_saspict_[_saspictn_] + _saspictindex_ * _saspictpage_[_saspictn_]);\n",
	    dap);
      fputs("}\n}\npict_end();\n", dap);
    }
  fputs("}\n", dap);
}

/* See if there's a "by" statement so that sorting needs to be done
 * Return position or -1 if none
 */
int isby(char *step)
{
  int s;

  for (s = 0; step[s]; s += 2)
    {
      if (!linecmp(step + s, "by"))
	return s + 3;
      else
	{
	  while (step[s] && step[s] != ';')
	    s++;
	}
    }
  return -1;
}

/* Get option from one statement using <key>=. Note that string "step"
 * starts at the point at which the search should begin. Returns 0 on fail.
 * If optvalue is the NULL pointer, getoption just looks for the option and, if found,
 * returns relative position of the next toke after the '=', otherwise
 * returns relative position of next token after the option value on success.
 * "equals" parameter says to complain if '=' doesn't follow key.
 */
int getoption(char *step, char *key, char *optvalue, int equals)
{
  int s;
  int keylen;

  keylen = strlen(key);
  for (s = 0; step[s] && step[s] != ';'; s++)
    {
      if (!linecmp(step + s, key))
	{
	  s += keylen + 1;
	  if (!linecmp(step + s, "="))
	    {
	      s += 2;
	      if (optvalue)
		s += linecpy(optvalue, step + s) + 1;
	      return s;
	    }
	  else if (equals)
	    {
	      fprintf(stderr, "sastrans: before %d: missing = in option\n", saslineno);
	      exit(1);
	    }
	}
      while (step[s] && step[s] != '\n')
	s++;
    }
  return 0;
}

/* Find relative position of a statement with given key.
 * Return relative position of token past key if found, 0 otherwise
 */
int findstatement(char *step, char *key)
{
  int s;
  int keylen;

  keylen = strlen(key);
  for (s = 0; step[s]; s += 2)
    {
      if (!linecmp(step + s, key))
	return s + keylen + 1;
      while (step[s] && step[s] != ';')
	s++;
    }
  return 0;
}

/* count number of parts in dataset */
void countparts(char *step, char *setname, FILE *dapfile)
{
  char sortname[TOKENLEN + 4 + 1]; /* +4 for .srt */

  fprintf(dapfile, "sort(\"%s\", \"", setname);
  strcpy(sortname, setname);
  strcat(sortname, ".srt");
  copylist(step, "by", dapfile);
  fputs("\", \"u\");\n", dapfile);
  fprintf(dapfile, "inset(\"%s\")\n{\n", sortname);
  fputs("for (_saspictcnt_[_sasnpicts_] = 0; step(); _saspictcnt_[_sasnpicts_]++)\n;\n}\n",
	dapfile);
}

/* extract string of tokens in statement matching key and write to dapfile */
/* return position of start of tokens or -1 if key unmatched */
/* includes leading and trailing blanks */
int copylist(char *step, char *key, FILE *dapfile)
{
  int s; /* index to step */
  int start; /* start of tokens */

  for (s = 0, start = -1; step[s]; s += 2)
    {
      if (!linecmp(step + s, key))
	{
	  s += strlen(key) + 1;
	  start = s;
	  putc(' ', dapfile);
	  s += putlines(step + s, dapfile, ';');
	}
      else
	{
	  while (step[s] && step[s] != ';')
	    s++;
	}
    }
  return start;
}

void sastrans(char *name)
{
  FILE *sas, *dap;
  static char step[STEPLEN + 1];
  int steptype;

  if (!(sas = fopen(name, "r")))
    {
      fprintf(stderr, "sastrans: can't read %s\n", name);
      exit(1);
    }
  namecvt(name);
  if (!(dap = fopen(name, "w")))
    {
      fprintf(stderr, "sastrans: can't write %s\n", name);
      exit(1);
    }
  sastempnum = 0;
  saslineno = 1;
  sashaspicts = 0;
  header(dap);
  sastmp[0] = '\0';
  newline = 1; /* set up variables for dgetc to process comments */
  incomment = 0;
  inquote1 = 0;
  inquote2 = 0;
  escape = 0;
  while ((steptype = getstep(sas, step)))
    {
      switch (steptype)
	{
	case DATA:
	  datatrans(step, dap);
	  break;
	case PROC:
	  proctrans(step, dap);
	  break;
	}
    }
  trailer(dap);
  fclose(sas);
  fclose(dap);
}
