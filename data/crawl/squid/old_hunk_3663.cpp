#else
        socklen_t len=sizeof(socklen_t);
#endif
	if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) exit(1);
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
SQUID_DETECT_UDP_SO_RCVBUF=`cat conftestval`,
SQUID_DETECT_UDP_SO_RCVBUF=16384,
SQUID_DETECT_UDP_SO_RCVBUF=16384)
AC_MSG_RESULT($SQUID_DETECT_UDP_SO_RCVBUF)
AC_DEFINE_UNQUOTED(SQUID_DETECT_UDP_SO_RCVBUF, $SQUID_DETECT_UDP_SO_RCVBUF,[UDP receive buffer size])

dnl Not cached since people are likely to tune this
AC_MSG_CHECKING(Default TCP send buffer size)
AC_TRY_RUN([
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
