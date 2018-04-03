AC_DEFINE(LIBRESOLV_DNS_TTL_HACK)],
AC_MSG_RESULT(no))

dnl Need the debugging version of malloc if available
XTRA_OBJS=''
if test "$ac_cv_lib_malloc_main" = "yes" ; then