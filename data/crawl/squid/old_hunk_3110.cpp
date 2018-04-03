SQUID_DEFINE_BOOL(USE_GNUREGEX,$enable_gnuregex,[Define if we should use GNU regex])
AC_SUBST(REGEXLIB)


dnl Not cached since people are likely to tune this
AC_MSG_CHECKING(Default UDP send buffer size)
AC_RUN_IFELSE([AC_LANG_SOURCE([[
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#if HAVE_SYS_SOCKET_H
#include <sys/socket.h>
#endif
#if HAVE_NETINET_IN_H
#include <netinet/in.h>
#endif
#if HAVE_WINSOCK_H
#include <winsock.h>
#endif
#if HAVE_WINSOCK2_H
#include <winsock2.h>
#endif
int main(int argc, char **argv)
{
	FILE *fp;
        int fd,val=0;
#if (defined(WIN32) || defined(__WIN32__) || defined(__WIN32)) && !(defined(__CYGWIN32__) || defined(__CYGWIN__))
        int len=sizeof(int);
	WSADATA wsaData;
	WSAStartup(2, &wsaData);
#else
        socklen_t len=sizeof(socklen_t);
#endif
	if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) return 1;
#if (defined(WIN32) || defined(__WIN32__) || defined(__WIN32)) && !(defined(__CYGWIN32__) || defined(__CYGWIN__))
        if (getsockopt(fd, SOL_SOCKET, SO_SNDBUF, (char *)&val, &len) < 0) return 1;
	WSACleanup();
#else
        if (getsockopt(fd, SOL_SOCKET, SO_SNDBUF, &val, &len) < 0) return 1;
#endif
	if (val<=0) return 1;
        fp = fopen("conftestval", "w");
        fprintf (fp, "%d\n", val);
	return 0;
}
]])],[SQUID_DETECT_UDP_SO_SNDBUF=`cat conftestval`],[SQUID_DETECT_UDP_SO_SNDBUF=16384],[SQUID_DETECT_UDP_SO_SNDBUF=16384])
AC_MSG_RESULT($SQUID_DETECT_UDP_SO_SNDBUF)
AC_DEFINE_UNQUOTED(SQUID_DETECT_UDP_SO_SNDBUF, $SQUID_DETECT_UDP_SO_SNDBUF,[UDP send buffer size])

dnl Not cached since people are likely to tune this
AC_MSG_CHECKING(Default UDP receive buffer size)
AC_RUN_IFELSE([AC_LANG_SOURCE([[
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#if HAVE_SYS_SOCKET_H
#include <sys/socket.h>
#endif
#if HAVE_NETINET_IN_H
#include <netinet/in.h>
#endif
#if HAVE_WINSOCK_H
#include <winsock.h>
#endif
#if HAVE_WINSOCK2_H
#include <winsock2.h>
#endif
int main(int argc, char **argv)
{
	FILE *fp;
        int fd,val=0;
#if (defined(WIN32) || defined(__WIN32__) || defined(__WIN32)) && !(defined(__CYGWIN32__) || defined(__CYGWIN__))
        int len=sizeof(int);
	WSADATA wsaData;
	WSAStartup(2, &wsaData);
#else
        socklen_t len=sizeof(socklen_t);
#endif
	if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) return 1;
#if (defined(WIN32) || defined(__WIN32__) || defined(__WIN32)) && !(defined(__CYGWIN32__) || defined(__CYGWIN__))
        if (getsockopt(fd, SOL_SOCKET, SO_RCVBUF, (char *)&val, &len) < 0) return 1;
	WSACleanup();
#else
        if (getsockopt(fd, SOL_SOCKET, SO_RCVBUF, &val, &len) < 0) return 1;
#endif
	if (val <= 0) return 1;
	fp = fopen("conftestval", "w"); 
	fprintf (fp, "%d\n", val);
	return 0;
}
]])],[SQUID_DETECT_UDP_SO_RCVBUF=`cat conftestval`],[SQUID_DETECT_UDP_SO_RCVBUF=16384],[SQUID_DETECT_UDP_SO_RCVBUF=16384])
AC_MSG_RESULT($SQUID_DETECT_UDP_SO_RCVBUF)
AC_DEFINE_UNQUOTED(SQUID_DETECT_UDP_SO_RCVBUF, $SQUID_DETECT_UDP_SO_RCVBUF,[UDP receive buffer size])

dnl Not cached since people are likely to tune this
AC_MSG_CHECKING(Default TCP send buffer size)
AC_RUN_IFELSE([AC_LANG_SOURCE([[
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#if HAVE_SYS_SOCKET_H
#include <sys/socket.h>
#endif
#if HAVE_NETINET_IN_H
#include <netinet/in.h>
#endif
#if HAVE_WINSOCK_H
#include <winsock.h>
#endif
#if HAVE_WINSOCK2_H
#include <winsock2.h>
#endif
int main(int argc, char **argv)
{
	FILE *fp;
        int fd,val=0;
#if (defined(WIN32) || defined(__WIN32__) || defined(__WIN32)) && !(defined(__CYGWIN32__) || defined(__CYGWIN__))
        int len=sizeof(int);
	WSADATA wsaData;
	WSAStartup(2, &wsaData);
#else
        socklen_t len=sizeof(socklen_t);
#endif
	if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) return 1;
#if (defined(WIN32) || defined(__WIN32__) || defined(__WIN32)) && !(defined(__CYGWIN32__) || defined(__CYGWIN__))
        if (getsockopt(fd, SOL_SOCKET, SO_SNDBUF, (char *)&val, &len) < 0) return 1;
	WSACleanup();
#else
        if (getsockopt(fd, SOL_SOCKET, SO_SNDBUF, &val, &len) < 0) return 1;
#endif
	if (val <= 0) return 1;
	fp = fopen("conftestval", "w"); 
	fprintf (fp, "%d\n", val);
	return 0;
}
]])],[SQUID_TCP_SO_SNDBUF=`cat conftestval`],[SQUID_TCP_SO_SNDBUF=16384],[SQUID_TCP_SO_SNDBUF=16384])
AC_MSG_RESULT($SQUID_TCP_SO_SNDBUF)
if test $SQUID_TCP_SO_SNDBUF -gt 32768; then
    AC_MSG_NOTICE([Limiting send buffer size to 32K])
    SQUID_TCP_SO_SNDBUF=32768
fi
AC_DEFINE_UNQUOTED(SQUID_TCP_SO_SNDBUF, $SQUID_TCP_SO_SNDBUF,[TCP send buffer size])

dnl Not cached since people are likely to tune this
AC_MSG_CHECKING(Default TCP receive buffer size)
AC_RUN_IFELSE([AC_LANG_SOURCE([[
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#if HAVE_SYS_SOCKET_H
#include <sys/socket.h>
#endif
#if HAVE_NETINET_IN_H
#include <netinet/in.h>
#endif
#if HAVE_WINSOCK_H
#include <winsock.h>
#endif
#if HAVE_WINSOCK2_H
#include <winsock2.h>
#endif
int main(int argc, char **argv)
{
	FILE *fp;
        int fd,val=0;
#if (defined(WIN32) || defined(__WIN32__) || defined(__WIN32)) && !(defined(__CYGWIN32__) || defined(__CYGWIN__))
        int len=sizeof(int);
	WSADATA wsaData;
	WSAStartup(2, &wsaData);
#else
        socklen_t len=sizeof(socklen_t);
#endif
	if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) return 1;
#if (defined(WIN32) || defined(__WIN32__) || defined(__WIN32)) && !(defined(__CYGWIN32__) || defined(__CYGWIN__))
        if (getsockopt(fd, SOL_SOCKET, SO_RCVBUF, (char *)&val, &len) < 0) return 1;
	WSACleanup();
#else
        if (getsockopt(fd, SOL_SOCKET, SO_RCVBUF, &val, &len) < 0) return 1;
#endif
	if (val <= 0) return 1;
	fp = fopen("conftestval", "w"); 
	fprintf (fp, "%d\n", val);
	return 0;
}
]])],[SQUID_TCP_SO_RCVBUF=`cat conftestval`],[SQUID_TCP_SO_RCVBUF=16384],[SQUID_TCP_SO_RCVBUF=16384])
AC_MSG_RESULT($SQUID_TCP_SO_RCVBUF)
if test $SQUID_TCP_SO_RCVBUF -gt 65535; then
    AC_MSG_NOTICE([Limiting receive buffer size to 64K])
    SQUID_TCP_SO_RCVBUF=65535
fi
AC_DEFINE_UNQUOTED(SQUID_TCP_SO_RCVBUF, $SQUID_TCP_SO_RCVBUF,[TCP receive buffer size])
AC_CACHE_CHECK(if sys_errlist is already defined, ac_cv_needs_sys_errlist,
  AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <stdio.h>]], [[char *s = sys_errlist;]])],[ac_cv_needs_sys_errlist="no"],[ac_cv_needs_sys_errlist="yes"])
)