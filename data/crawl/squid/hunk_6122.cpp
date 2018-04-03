 	    COMM_NONBLOCKING,
 	    "WCCP Port");
 	theInGreConnection = comm_open(SOCK_RAW,
-	    47,
+	    GRE_PROTOCOL,
 	    Config.Addrs.wccp_incoming,
 	    0,
 	    COMM_NONBLOCKING,
 	    "GRE Port");
 	leave_suid();
 	if ((theInWccpConnection < 0) || (theInGreConnection < 0))
-	    fatal("Cannot open wccp Port");
+	    fatal("Cannot open WCCP Port");
 	commSetSelect(theInWccpConnection, COMM_SELECT_READ, wccpHandleUdp, NULL, 0);
 	commSetSelect(theInGreConnection, COMM_SELECT_READ, wccpHandleGre, NULL, 0);
 	debug(1, 1) ("Accepting WCCP UDP messages on port %d, FD %d.\n",
