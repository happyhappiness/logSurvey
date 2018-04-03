     u_short port = WCCP_PORT;
     struct sockaddr_in router, local;
     int local_len, router_len;
-
     debug(80, 5) ("wccpConnectionOpen: Called\n");
-    if (Config.Wccp.router.s_addr != inet_addr("0.0.0.0")) {
-	theInWccpConnection = comm_open(SOCK_DGRAM,
+    if (Config.Wccp.router.s_addr == any_addr.s_addr) {
+	debug(1, 1) ("WCCP Disabled.\n");
+	return;
+    }
+    theInWccpConnection = comm_open(SOCK_DGRAM,
+	0,
+	Config.Wccp.incoming,
+	port,
+	COMM_NONBLOCKING,
+	"WCCP Socket");
+    if (theInWccpConnection < 0)
+	fatal("Cannot open WCCP Port");
+    commSetSelect(theInWccpConnection,
+	COMM_SELECT_READ,
+	wccpHandleUdp,
+	NULL,
+	0);
+    debug(1, 1) ("Accepting WCCP messages on port %d, FD %d.\n",
+	(int) port, theInWccpConnection);
+    if (Config.Wccp.outgoing.s_addr != no_addr.s_addr) {
+	theOutWccpConnection = comm_open(SOCK_DGRAM,
 	    0,
-	    Config.Wccp.incoming,
+	    Config.Wccp.outgoing,
 	    port,
 	    COMM_NONBLOCKING,
-	    "WCCP Port");
-	if (theInWccpConnection < 0)
-	    fatal("Cannot open WCCP Port");
-	commSetSelect(theInWccpConnection, COMM_SELECT_READ, wccpHandleUdp, NULL, 0);
-	debug(1, 1) ("Accepting WCCP messages on port %d, FD %d.\n",
-	    (int) port, theInWccpConnection);
-	if (Config.Wccp.outgoing.s_addr != no_addr.s_addr) {
-	    theOutWccpConnection = comm_open(SOCK_DGRAM,
-		0,
-		Config.Wccp.outgoing,
-		port,
-		COMM_NONBLOCKING,
-		"WCCP Port");
-	    if (theOutWccpConnection < 0)
-		fatal("Cannot open Outgoing WCCP Port");
-	    commSetSelect(theOutWccpConnection,
-		COMM_SELECT_READ,
-		wccpHandleUdp,
-		NULL, 0);
-	    debug(1, 1) ("Outgoing WCCP messages on port %d, FD %d.\n",
-		(int) port, theOutWccpConnection);
-	    fd_note(theOutWccpConnection, "Outgoing WCCP socket");
-	    fd_note(theInWccpConnection, "Incoming WCCP socket");
-	} else {
-	    theOutWccpConnection = theInWccpConnection;
-	}
+	    "WCCP Socket");
+	if (theOutWccpConnection < 0)
+	    fatal("Cannot open Outgoing WCCP Port");
+	commSetSelect(theOutWccpConnection,
+	    COMM_SELECT_READ,
+	    wccpHandleUdp,
+	    NULL, 0);
+	debug(1, 1) ("Outgoing WCCP messages on port %d, FD %d.\n",
+	    (int) port, theOutWccpConnection);
+	fd_note(theOutWccpConnection, "Outgoing WCCP socket");
+	fd_note(theInWccpConnection, "Incoming WCCP socket");
     } else {
-	debug(1, 1) ("WCCP Disabled.\n");
+	theOutWccpConnection = theInWccpConnection;
     }
-
     router_len = sizeof(router);
     memset(&router, '\0', router_len);
     router.sin_family = AF_INET;
-    router.sin_port = htons(2048);
+    router.sin_port = htons(port);
     router.sin_addr = Config.Wccp.router;
     if (connect(theOutWccpConnection, (struct sockaddr *) &router, router_len))
 	fatal("Unable to connect WCCP out socket");
-
     local_len = sizeof(local);
     memset(&local, '\0', local_len);
     if (getsockname(theOutWccpConnection, (struct sockaddr *) &local, &local_len))
 	fatal("Unable to getsockname on WCCP out socket");
-    local_ip = local.sin_addr.s_addr;
+    local_ip.s_addr = local.sin_addr.s_addr;
 }
 
 void
