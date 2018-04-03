 AC_MSG_RESULT($SQUID_FD_SETSIZE)
 AC_DEFINE_UNQUOTED(SQUID_FD_SETSIZE, $SQUID_FD_SETSIZE)
 
+AC_MSG_CHECKING(Default UDP send buffer size)
+AC_TRY_RUN([
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+main ()
+{
+        int fd,val=0,len=sizeof(int);
+	if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) exit(1);
+        if (getsockopt(fd, SOL_SOCKET, SO_SNDBUF, &val, &len) < 0) exit(1);
+	if (val<=0) exit(1);
+        fprintf (fopen("conftestval", "w"), "%d\n", val);
+	exit(0);
+}
+],
+SQUID_UDP_SO_SNDBUF=`cat conftestval`,
+SQUID_UDP_SO_SNDBUF=8192,
+SQUID_UDP_SO_SNDBUF=8192)
+AC_MSG_RESULT($SQUID_UDP_SO_SNDBUF)
+AC_DEFINE_UNQUOTED(SQUID_UDP_SO_SNDBUF, $SQUID_UDP_SO_SNDBUF)
+
+AC_MSG_CHECKING(Default UDP receive buffer size)
+AC_TRY_RUN([
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+main ()
+{
+        int fd,val=0,len=sizeof(int);
+	if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) exit(1);
+        if (getsockopt(fd, SOL_SOCKET, SO_RCVBUF, &val, &len) < 0) exit(1);
+	if (val <= 0) exit(1);
+        fprintf (fopen("conftestval", "w"), "%d\n", val);
+	exit(0);
+}
+],
+SQUID_UDP_SO_RCVBUF=`cat conftestval`,
+SQUID_UDP_SO_RCVBUF=8192,
+SQUID_UDP_SO_RCVBUF=8192)
+AC_MSG_RESULT($SQUID_UDP_SO_RCVBUF)
+AC_DEFINE_UNQUOTED(SQUID_UDP_SO_RCVBUF, $SQUID_UDP_SO_RCVBUF)
+
+AC_MSG_CHECKING(Default TCP send buffer size)
+AC_TRY_RUN([
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+main ()
+{
+        int fd,val=0,len=sizeof(int);
+	if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) exit(1);
+        if (getsockopt(fd, SOL_SOCKET, SO_SNDBUF, &val, &len) < 0) exit(1);
+	if (val <= 0) exit(1);
+        fprintf (fopen("conftestval", "w"), "%d\n", val);
+	exit(0);
+}
+],
+SQUID_TCP_SO_SNDBUF=`cat conftestval`,
+SQUID_TCP_SO_SNDBUF=8192,
+SQUID_TCP_SO_SNDBUF=8192)
+AC_MSG_RESULT($SQUID_TCP_SO_SNDBUF)
+AC_DEFINE_UNQUOTED(SQUID_TCP_SO_SNDBUF, $SQUID_TCP_SO_SNDBUF)
+
+AC_MSG_CHECKING(Default TCP receive buffer size)
+AC_TRY_RUN([
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+main ()
+{
+        int fd,val=0,len=sizeof(int);
+	if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) exit(1);
+        if (getsockopt(fd, SOL_SOCKET, SO_RCVBUF, &val, &len) < 0) exit(1);
+	if (val <= 0) exit(1);
+        fprintf (fopen("conftestval", "w"), "%d\n", val);
+	exit(0);
+}
+],
+SQUID_TCP_SO_RCVBUF=`cat conftestval`,
+SQUID_TCP_SO_RCVBUF=8192,
+SQUID_TCP_SO_RCVBUF=8192)
+AC_MSG_RESULT($SQUID_TCP_SO_RCVBUF)
+AC_DEFINE_UNQUOTED(SQUID_TCP_SO_RCVBUF, $SQUID_TCP_SO_RCVBUF)
+
+AC_MSG_CHECKING(if sys_errlist[] is already defined)
+AC_TRY_COMPILE([#include <stdio.h>],
+[char *s = sys_errlist[0];],
+AC_MSG_RESULT(yes),
+[AC_MSG_RESULT(no)
+AC_DEFINE(NEED_SYS_ERRLIST)])
+
 dnl Need the debugging version of malloc if available
 XTRA_OBJS=''
 if test "$HAVE_LIBMALLOC" = "yes" ; then
