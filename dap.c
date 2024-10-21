/* Controls processes for preprocessing,
 * compiling, and running Dap programs.  
 */

/*  Copyright (C) 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.
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
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

#define PAGE "/bin/more"
#define GCC "/usr/bin/gcc"
#define PS "/usr/bin/X11/gv"

#define DAPPP "/usr/local/bin/dappp"
#define INCDIR "/usr/local/include"
#define LIBDIR "/usr/local/lib"

char *pager;
char *pageopts;
char *compiler;
char *compopts;
char *viewer;
char *viewopts;

char *dappp;
char *incdir;
char *libdir;

int dappprun(int argc, char **argv);
int gccrun(int argc, char **argv, int debug);
int run(int argc, char **argv, int keep);
void view(char name[], char suff[]);
void showps(char name[]);
char *argcpy(char arg[], int extra);
void suffix(char name[], char suff[]);
int parseopts(char *opts, char **arg);

char *ecopy(char *e)
{
  char *copy;

  if (e)
    {
      if (!(copy = malloc(strlen(e) + 1)))
	{
	  perror("dap");
	  exit(1);
	}
      strcpy(copy, e);
      return copy;
    }
  return NULL;
}

int main(int argc, char **argv)
{
  int keep;	/* flag: keep .lst file and append to it each run? */
  int debug;	/* flag: save .dap.c for debugging? */
  int runstat;	/* return status of execution of program */

  fputs("\nDap, Copyright (C) 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.\n",
	stderr);
  fputs("Dap comes with ABSOLUTELY NO WARRANTY;\n", stderr);
  fputs("for details see the GNU Public License.\n", stderr);
  fputs("This is free software, and you are welcome to\n", stderr);
  fputs("redistribute it under certain conditions; see\n", stderr);
  fputs("the GNU Public License for details.\n\n", stderr);

  if (argc < 2)
    {
      fputs("dap: no files to process\n", stderr);
      exit(1);
    }
  keep = 0;	/* FALSE value */
  debug = 0;	/* FALSE value */
  while (argv[1][0] == '-')
    {
      --argc;
      argv++;
      if (!strcmp(argv[0], "-k") || !strcmp(argv[0], "--keep"))
	keep = -1;	/* initial TRUE value */
      else if (!strcmp(argv[0], "-d") || !strcmp(argv[0], "--debug"))
	debug = 1;	/* initial TRUE value */
      else if (!strcmp(argv[0], "--help"))
	{
	  fputs("Usage:\ndap [-k] [-d] FILE1.c [ FILE2.c ... ] [-a ARG1 ...]\n", stderr);
	  fputs("dap [--keep] [--debug] FILE1.c [ FILE2.c ... ] [--args] ARG1 ...]\n", stderr);
	  fputs("dap [-k] [-d] FILE1.sas [ FILE2.c ... ]\n", stderr);
	  fputs("dap [--keep] [--debug] FILE1.sas [ FILE2.c ... ]\n", stderr);
	  fputs("\nReport bugs to <bug-dap@gnu.org>\n", stderr);
	  exit(1);
	}
      else if (!strcmp(argv[0], "--version") || !strcmp(argv[0], "-v"))
	{
	  fputs("Dap 3.6\n", stderr);
	  exit(1);
	}
      else
	{
	  fprintf(stderr, "dap: bad option: %s\n", argv[0]);
	  exit(1);
	}
    }
  if (!(pager = ecopy(getenv("DAPPAGER"))))
    pager = PAGE;
  if (!(pageopts = ecopy(getenv("DAPPAGEOPTS"))))
    pageopts = NULL;
  if (!(compiler = ecopy(getenv("DAPCOMPILER"))))
    compiler = GCC;
  if (!(compopts = ecopy(getenv("DAPCOMPOPTS"))))
    compopts = NULL;
  if (!(viewer = ecopy(getenv("DAPVIEWER"))))
    viewer = PS;
  if (!(viewopts = ecopy(getenv("DAPVIEWOPTS"))))
    viewopts = NULL;
  if (!(dappp = ecopy(getenv("DAPPP"))))
    dappp = DAPPP;
  if (!(incdir = ecopy(getenv("INCDIR"))))
    incdir = INCDIR;
  if (!(libdir = ecopy(getenv("LIBDIR"))))
    libdir = LIBDIR;
  if (!dappprun(argc, argv))
    {
      if (!gccrun(argc, argv, debug))
	{
	  runstat = run(argc, argv, keep);
	  view(argv[1], ".err");
	  if (!runstat)
	    {
	      if (keep == -1)
		keep = 1;	/* non-initial TRUE value */
	      showps(argv[1]);
	    }
	}
    }
  return 0;
}

/* run preprocessor */
int dappprun(int argc, char **argv)
{
  char **arg;	/* copy of arguments, modified */
  int a;		/* index to arguments */
  int status;	/* return status of preprocessor */
  pid_t pid;	/* process id of preprocessor */

  if (!(arg = (char **) malloc(sizeof(char *) * (argc + 1))))
    {
      perror("dap");
      exit(1);
    }
  arg[0] = dappp;
  /* Only use arguments preceding "-a"; arguments following "-a"
   * are arguments to program  
   */
  for (a = 1; a < argc && strcmp(argv[a], "-a") && strcmp(argv[a], "--args"); a++)
    arg[a] = argv[a];
  arg[a] = NULL;
  if (!(pid = fork()))
    {
      fputs("Preprocessing...\n", stderr);
      execv(arg[0], arg);
      perror(arg[0]);
      exit(1);
    }
  else if (pid == -1)
    {
      perror("dap");
      exit(1);
    }
  waitpid(pid, &status, 0);
  return status;
}

/* replace trailing ".c" with suff */
void suffix(char name[], char suff[])
{
  int n;

  n = strlen(name);
  if (n > 2 && !strcmp(name + n - 2, ".c"))
    {
      name[n - 2] = '\0';
      strcat(name, suff);
    }
  else if (n > 4 && !strcmp(name + n - 4, ".sas"))
    {
      name[n - 4] = '\0';
      strcat(name, suff);
    }
  else
    {
      fprintf(stderr, "dap: name must end in .c or .sas: %s\n", name);
      exit(1);
    }
}

/* allocate copy of argument, with extra characters if requested,
 * and copy argument; return address of copy
 */
char *argcpy(char arg[], int extra)
{
  char *cpy;

  if (!(cpy = malloc(strlen(arg) + extra + 1)))
    {
      perror("dap");
      exit(1);
    }
  strcpy(cpy, arg);
  return cpy;
}

/* run the compiler */
int gccrun(int argc, char **argv, int debug)
{
  char **arg;	/* copy of arguments, modified */
  int ncompopts;	/* number of compiler options */
  int g, a;	/* indices to arguments */
  int argstart;	/* index of first file name */
  int argend;	/* index of "-a", if any, otherwise 0 */
  int status;	/* return status of compiler */
  pid_t pid;	/* process id of compiler */

  ncompopts = parseopts(compopts, NULL);
  if (!(arg = (char **) malloc(sizeof(char *) * (argc + 11 + ncompopts))))
    {
      perror("dap");
      exit(1);
    }
  g = 0;
  arg[g++] = compiler;			/* first arg is compiler name */
  g += parseopts(compopts, arg + g);	/* now get compiler opts, if any */
  arg[g++] = "-o";			/* always name output file */
  arg[g] = argcpy(argv[1], 4);		/* and this is its name */
  suffix(arg[g], ".dap");			/* except have to attach suffix */
  g++;
  arg[g++] = "-I";			/* need to make use of... */
  arg[g++] = incdir;			/* ... header files */
  /* Only use arguments preceding "-a"; arguments following "-a"
   * are arguments to program  
   */
  argstart = g;				/* this is where file names start */
  for (a = 1; a < argc && strcmp(argv[a], "-a") && strcmp(argv[a], "--args"); a++, g++)
    {
      arg[g] = argcpy(argv[a], 6);	/* file name + chars for ".dap.c" */
      suffix(arg[g], ".dap.c");
    }
  argend = g;				/* this is after then end */
  arg[g++] = "-L";
  arg[g++] = libdir;
  arg[g++] = "-ldap";
  arg[g++] = "-lm";
  arg[g] = NULL;
  if (!(pid = fork()))
    {
      fputs("Compiling...\n", stderr);
      execv(arg[0], arg);
      perror(arg[0]);
      exit(1);
    }
  else if (pid == -1)
    {
      perror("dap");
      exit(1);
    }
  waitpid(pid, &status, 0);
  if (!status && !debug)
    {
      for (g = argstart; g < argend; g++)
	unlink(arg[g]);
    }
  return status;
}

/* run compiled program */
int run(int argc, char **argv, int keep)
{
  char **arg;	/* copy of arguments, modified */
  char *lstname;	/* name of .lst file */
  char *psname;	/* name of .ps file */
  int g, a;	/* indices to arguments */
  int status;	/* return status of executable program */
  pid_t pid;	/* process id of executable program */

  if (!(arg = (char **) malloc(sizeof(char *) * (argc + 1))))
    {
      perror("dap");
      exit(1);
    }
  arg[0] = argcpy(argv[1], 4);	/* name of executable */
  suffix(arg[0], ".dap");
  lstname = argcpy(argv[1], 4);
  suffix(lstname, ".lst");
  if (keep != 1)		/* remove .lst file if first run or !keep */
    unlink(lstname);
  psname = argcpy(argv[1], 3);
  suffix(psname, ".ps");
  unlink(psname);		/* always remove .ps file */
  for (a = 1; a < argc && strcmp(argv[a], "-a") && strcmp(argv[a], "--args"); a++)
    ;
  for (g = 1, a++; a < argc; a++, g++)	/* copy runtime arguments */
    arg[g] = argcpy(argv[a], 0);
  arg[g] = NULL;
  if (!(pid = fork()))
    {
      fputs("Executing...\n", stderr);
      execv(arg[0], arg);
      perror(arg[0]);
      exit(1);
    }
  else if (pid == -1)
    {
      perror("dap");
      exit(1);
    }
  waitpid(pid, &status, 0);
  return status;
}

/* Ask user the question, get response, return 0 or 1.  */
int ask(char *question)
{
  int c;

  do	{
    fprintf(stderr, "%s? [y/q] ", question);
    c = getchar();
    while (getchar() != '\n')
      ;
    if (c != 'y' && c != 'q')
      fprintf(stderr, "Invalid response. ");
  } while (c != 'y' && c != 'q');
  return (c == 'y');
}

/* View .err file, if any.  */
void view(char name[], char suff[])
{
  char *lstname;
  char **arg;
  int a;			/* index to arg */
  int status;
  struct stat buf;
  pid_t pid;

  if (!(arg = (char **) malloc(sizeof(char *) *
			       (3 + parseopts(pageopts, NULL)))))
    {
      perror("dap");
      exit(1);
    }
  lstname = argcpy(name, strlen(suff));
  suffix(lstname, suff);
  if (!stat(lstname, &buf) && buf.st_size)
    {
      a = 0;
      arg[a++] = pager;
      a += parseopts(pageopts, arg + a);
      arg[a++] = lstname;
      arg[a] = NULL;
      if (!(pid = fork()))
	{
	  execv(arg[0], arg);
	  perror(arg[0]);
	  exit(1);
	}
      else if (pid == -1)
	{
	  perror("dap");
	  exit(1);
	}
      waitpid(pid, &status, 0);
    }
}

/* View graphics file, if any.  */
void showps(char name[])
{
  char *psname;		/* name of graphics file */
  char **arg;		/* arguments for execution of graphics viewer */
  int a;			/* index to arg */
  struct stat buf;	/* for call to stat: unused */
  static int gv = 0;	/* flag: graphics viewer started? */
  pid_t pid;		/* process id of viewer */

  if (!(arg = (char **) malloc(sizeof(char *) *
			       (3 + parseopts(viewopts, NULL)))))
    {
      perror("dap");
      exit(1);
    }
  psname = argcpy(name, 3);
  suffix(psname, ".ps");
  if (!gv && !stat(psname, &buf))
    {
      gv = 1;
      a = 0;
      arg[a++] = viewer;
      a += parseopts(viewopts, arg + a);
      arg[a++] = psname;
      arg[a++] = NULL;
      if (!(pid = fork()))
	{
	  execv(arg[0], arg);
	  perror(arg[0]);
	  exit(1);
	}
      else if (pid == -1)
	{
	  perror("dap");
	  exit(1);
	}
    }
}

/* If arg non NULL, copy arguments, report number found,
 * else just report number found.  
 */
int parseopts(char *opts, char **arg)
{
  static char *optcpy = NULL;	/* copy of opts */
  static int optlen = 0;
  int i;		/* index to opts */
  int a;		/* arg count */

  if (!opts)
    return 0;
  if (strlen(opts) > optlen)
    {
      if (optcpy)
	free(optcpy);
      optlen = strlen(opts);
      if (!(optcpy = malloc(optlen + 1)))
	{
	  perror("dap");
	  exit(1);
	}
    }
  strcpy(optcpy, opts);
  for (i = 0; optcpy[i] == ' '; i++)
    ;
  for (a = 0; optcpy[i]; a++)
    {
      if (arg)
	arg[a] = optcpy + i;
      while (optcpy[i] && optcpy[i] != ' ')
	i++;
      if (optcpy[i])
	{
	  if (arg)
	    optcpy[i] = '\0';
	  for (i++; optcpy[i] == ' '; i++)
	    ;
	}
    }
  return a;
}
