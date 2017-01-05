#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_CONFIG_AUX_DIR([build-aux])
AC_INIT([openkeeper-cli], [2.0], [rain.by.zhou@gmail.com])
AC_CONFIG_SRCDIR([src/dialnetkeeper.h])

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL

# Checks for libraries.
AC_CHECK_LIB([crypto], [MD5_Init], [], [AC_MSG_ERROR([please install libssl])])
AC_CHECK_HEADERS([openssl/md5.h], [], [AC_MSG_ERROR([please install libssl headers])])

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h time.h])

# Checks for scripts.
AC_CHECK_PROG(PPPOE_CONNECT, pppoe-connect, yes)
if test x"$PPPOE_CONNECT" != x"yes" ; then
    AC_MSG_ERROR([please install rp-pppoe])
fi

AC_FUNC_MALLOC
AC_CHECK_FUNCS([strcspn])

AC_CONFIG_FILES([Makefile ok ok-start])
AC_OUTPUT
