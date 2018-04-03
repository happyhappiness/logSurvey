     u_short port;
     int len;
     int x;
-    enter_suid();
-    theHttpConnection = comm_open(SOCK_STREAM,
-	0,
-	Config.Addrs.tcp_incoming,
-	Config.Port.http,
-	COMM_NONBLOCKING,
-	"HTTP Port");
-    leave_suid();
-    if (theHttpConnection < 0) {
-	fatal("Cannot open HTTP Port");
+    int fd;
+    for (x = 0; x< Config.Port.n_http; x++) {
+        enter_suid();
+        fd = comm_open(SOCK_STREAM,
+	    0,
+	    Config.Addrs.tcp_incoming,
+	    Config.Port.http[x],
+	    COMM_NONBLOCKING,
+	    "HTTP Socket");
+        leave_suid();
+	if (fd < 0)
+		continue;
+        comm_listen(fd);
+        commSetSelect(fd, COMM_SELECT_READ, httpAccept, NULL, 0);
+        debug(1, 1, "Accepting HTTP connections on port %d, FD %d.\n",
+    	    (int) Config.Port.http[x], fd);
+	HttpSockets[NHttpSockets++] = fd;
     }
-    fd_note(theHttpConnection, "HTTP socket");
-    comm_listen(theHttpConnection);
-    commSetSelect(theHttpConnection,
-	COMM_SELECT_READ,
-	asciiHandleConn,
-	NULL, 0);
-    debug(1, 1, "Accepting HTTP connections on FD %d.\n",
-	theHttpConnection);
-
+    if (NHttpSockets < 1)
+	fatal("Cannot open HTTP Port");
     if (!httpd_accel_mode || Config.Accel.withProxy) {
 	if ((port = Config.Port.icp) > (u_short) 0) {
 	    enter_suid();
