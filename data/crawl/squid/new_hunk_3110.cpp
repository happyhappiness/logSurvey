SQUID_DEFINE_BOOL(USE_GNUREGEX,$enable_gnuregex,[Define if we should use GNU regex])
AC_SUBST(REGEXLIB)

SQUID_DETECT_UDP_SND_BUFSIZE
SQUID_DETECT_UDP_RECV_BUFSIZE
SQUID_DETECT_TCP_SND_BUFSIZE
SQUID_DETECT_TCP_RECV_BUFSIZE

AC_CACHE_CHECK(if sys_errlist is already defined, ac_cv_needs_sys_errlist,
  AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <stdio.h>]], [[char *s = sys_errlist;]])],[ac_cv_needs_sys_errlist="no"],[ac_cv_needs_sys_errlist="yes"])
)