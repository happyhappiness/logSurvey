AC_MSG_RESULT($SQUID_FD_SETSIZE)
AC_DEFINE_UNQUOTED(SQUID_FD_SETSIZE, $SQUID_FD_SETSIZE)

dnl Need the debugging version of malloc if available
XTRA_OBJS=''
if test "$HAVE_LIBMALLOC" = "yes" ; then
