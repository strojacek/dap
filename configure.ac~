dnl Process this file with autoconf to produce a configure script.
dnl
dnl This file is free software; as a special exception the author gives
dnl unlimited permission to copy and/or distribute it, with or without
dnl modifications, as long as this notice is preserved.
dnl
dnl This program is distributed in the hope that it will be useful, but
dnl WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
dnl implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

AC_INIT([GNU dap], [3.10], [bug-dap@gnu.org])

AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE()
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])

dnl Check C compiler
AM_PROG_CC_STDC

dnl Checks for programs.
AC_PROG_INSTALL
AC_PROG_MAKE_SET

dnl Checks for libraries.
#AC_PROG_RANLIB
LT_INIT

dnl Checks for header files.
AC_HEADER_STDC
AC_HEADER_SYS_WAIT
AC_CHECK_HEADERS(fcntl.h strings.h unistd.h)

dnl Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_MODE_T
AC_TYPE_SIZE_T
AC_TYPE_PID_T
AC_TYPE_SSIZE_T

dnl Checks for library functions.
AC_CHECK_FUNCS(mkdir)
AC_CHECK_FUNCS([floor])
AC_CHECK_FUNCS([rint])
AC_CHECK_FUNCS([sqrt])
AC_CHECK_FUNCS([pow])
AC_FUNC_FORK
AC_FUNC_MALLOC


AC_OUTPUT(doc/Makefile src/Makefile examples/Makefile Makefile)
