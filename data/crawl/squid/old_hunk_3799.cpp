AC_DEFINE(LIBRESOLV_DNS_TTL_HACK,1,[If libresolv.a has been hacked to export _dns_ttl_])],
AC_MSG_RESULT(no))

AC_MSG_CHECKING(if inet_ntoa() actually works)
AC_TRY_RUN([
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
main ()
{
	FILE *fp;
	struct in_addr in;
	in.s_addr = inet_addr("1.2.3.4");
	fp = fopen("conftestval", "w"); 
	fprintf (fp, "%s\n", inet_ntoa(in));
	exit(0);
}
],
INET_NTOA_RESULT=`cat conftestval`,
INET_NTOA_RESULT="broken",
INET_NTOA_RESULT="broken")
if test "$INET_NTOA_RESULT" = "1.2.3.4" ; then
	AC_MSG_RESULT("yes")
else
	AC_MSG_RESULT("no")
	case "$host_os" in
	mingw|mingw32)
	  AC_MSG_NOTICE([Using Win32 resolver instead.])
	  ;;
	*)
	  AC_MSG_NOTICE([Will use our own inet_ntoa().])
	  AC_LIBOBJ(inet_ntoa)
#	  AC_MSG_WARN([This looks bad, and probably prevents Squid from working.])
#	  AC_MSG_WARN([If you're on IRIX and using GCC 2.8, you probably need])
#	  AC_MSG_WARN([to use the IRIX C compiler instead.])
#	  sleep 10
	  ;;
	esac
fi

if test "$ac_cv_header_sys_statvfs_h" = "yes" ; then
AC_MSG_CHECKING(for working statvfs() interface)
AC_TRY_COMPILE([
