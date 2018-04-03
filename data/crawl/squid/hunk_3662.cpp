 #else
         socklen_t len=sizeof(socklen_t);
 #endif
-	if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) exit(1);
+	if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) return 1;
 #if (defined(WIN32) || defined(__WIN32__) || defined(__WIN32)) && !(defined(__CYGWIN32__) || defined(__CYGWIN__))
-        if (getsockopt(fd, SOL_SOCKET, SO_SNDBUF, (char *)&val, &len) < 0) exit(1);
+        if (getsockopt(fd, SOL_SOCKET, SO_SNDBUF, (char *)&val, &len) < 0) return 1;
 	WSACleanup();
 #else
-        if (getsockopt(fd, SOL_SOCKET, SO_SNDBUF, &val, &len) < 0) exit(1);
+        if (getsockopt(fd, SOL_SOCKET, SO_SNDBUF, &val, &len) < 0) return 1;
 #endif
-	if (val<=0) exit(1);
+	if (val<=0) return 1;
         fp = fopen("conftestval", "w");
         fprintf (fp, "%d\n", val);
-	exit(0);
+	return 0;
 }
-],
-SQUID_DETECT_UDP_SO_SNDBUF=`cat conftestval`,
-SQUID_DETECT_UDP_SO_SNDBUF=16384,
-SQUID_DETECT_UDP_SO_SNDBUF=16384)
+]])],[SQUID_DETECT_UDP_SO_SNDBUF=`cat conftestval`],[SQUID_DETECT_UDP_SO_SNDBUF=16384],[SQUID_DETECT_UDP_SO_SNDBUF=16384])
 AC_MSG_RESULT($SQUID_DETECT_UDP_SO_SNDBUF)
 AC_DEFINE_UNQUOTED(SQUID_DETECT_UDP_SO_SNDBUF, $SQUID_DETECT_UDP_SO_SNDBUF,[UDP send buffer size])
 
 dnl Not cached since people are likely to tune this
 AC_MSG_CHECKING(Default UDP receive buffer size)
-AC_TRY_RUN([
+AC_RUN_IFELSE([AC_LANG_SOURCE([[
 #include <stdlib.h>
 #include <stdio.h>
 #include <sys/types.h>
