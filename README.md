# Gnu Dap

## Introduction

Gnu Dap is an open source compiler for the SAS language.
Gnu Dap converts SAS code to C code, which is then ran on the user's computer, using the native C compiler.

Because Dap processes files one line at a time, rather than reading entire files into memory, it can be, and has been, used on data sets that have very many lines and/or very many variables.

Dap is a GNU program and is free software distributed under a GNU-style copyleft.
See the file COPYING for details.

## Features

Gnu Dap has the following features:

- Data Steps:
  - set
  - infile
  - input
  - length
  - merge
  - by
  - drop
  - keep
  - output
  - do: do to loops not currently implemented
  - end
  - if
  - then
  - else
  - while

- Proc Steps:
  - proc print
  - proc means
  - proc sort
  - proc chart
  - proc datasets
  - proc freq
  - proc tabulate
  - proc corr
  - proc plot
  - proc rank
  - proc univariate
  - proc glm
  - proc logistic
  - proc npar1way
  - proc reg
  - proc import: CSV, DBF, and Tab delimited files currently
  - proc surveyselect

## Contributors

- Susan Bassein
- Anna Reidenbach
- Jeffrin Jose
- Seth Trojacek

## Next Steps

- Implementing cards/datalines/datalines4 functionality.
- NaN/NULL value handling
- proc glmmix
- proc import: import/export .xlsx files
- proc sgplot/plot/chart: Using Gnuplot, instead of current PostScript usage
- Native functionality on Windows (works on MacOS, Linux and WSL).
- SAS macro language
- proc mcmc
- proc sql
- proc R
- Read .sas7bdat, .sas7cat and XPORT files