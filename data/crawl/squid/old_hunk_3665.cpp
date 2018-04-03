#else
        socklen_t len=sizeof(socklen_t);
#endif
	if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) exit(1);
#if (defined(WIN32) || defined(__WIN32__) || defined(__WIN32)) && !(defined(__CYGWIN32__) || defined(__CYGWIN__))
        if (getsockopt(fd, SOL_SOCKET, SO_RCVBUF, (char *)&val, &len) < 0) exit(1);
	WSACleanup();
#else
        if (getsockopt(fd, SOL_SOCKET, SO_RCVBUF, &val, &len) < 0) exit(1);
#endif
	if (val <= 0) exit(1);
	fp = fopen("conftestval", "w"); 
	fprintf (fp, "%d\n", val);
	exit(0);
}
],
SQUID_TCP_SO_RCVBUF=`cat conftestval`,
SQUID_TCP_SO_RCVBUF=16384,
SQUID_TCP_SO_RCVBUF=16384)
AC_MSG_RESULT($SQUID_TCP_SO_RCVBUF)
if test $SQUID_TCP_SO_RCVBUF -gt 65535; then
    AC_MSG_NOTICE([Limiting receive buffer size to 64K])
    SQUID_TCP_SO_RCVBUF=65535
fi
AC_DEFINE_UNQUOTED(SQUID_TCP_SO_RCVBUF, $SQUID_TCP_SO_RCVBUF,[TCP receive buffer size])
AC_CACHE_CHECK(if sys_errlist is already defined, ac_cv_needs_sys_errlist,
  AC_TRY_COMPILE([#include <stdio.h>],[char *s = sys_errlist;],
    ac_cv_needs_sys_errlist="no",
    ac_cv_needs_sys_errlist="yes")
)
if test "$ac_cv_needs_sys_errlist" = "yes" ; then
  AC_DEFINE(NEED_SYS_ERRLIST,1,[If we need to declare sys_errlist[] as external])
fi

dnl Not cached since people are likely to change this
AC_MSG_CHECKING(for libresolv _dns_ttl_ hack)
AC_TRY_LINK(extern int _dns_ttl_;,return _dns_ttl_;,
[AC_MSG_RESULT(yes)
AC_DEFINE(LIBRESOLV_DNS_TTL_HACK,1,[If libresolv.a has been hacked to export _dns_ttl_])],
AC_MSG_RESULT(no))

if test "$ac_cv_header_sys_statvfs_h" = "yes" ; then
AC_MSG_CHECKING(for working statvfs() interface)
AC_TRY_COMPILE([
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/statvfs.h>
],
[
struct statvfs sfs;
sfs.f_blocks = sfs.f_bfree = sfs.f_frsize = 
sfs.f_files = sfs.f_ffree = 0;
statvfs("/tmp", &sfs);
],
  ac_cv_func_statvfs=yes,
  ac_cv_func_statvfs=no)
AC_MSG_RESULT($ac_cv_func_statvfs)
if test "$ac_cv_func_statvfs" = "yes" ; then
  AC_DEFINE(HAVE_STATVFS,1,[If your system has statvfs(), and if it actually works!])
