		port,
		COMM_NONBLOCKING,
		"WCCP Port");
	    theOutGreConnection = comm_open(SOCK_RAW,
		GRE_PROTOCOL,
		Config.Addrs.wccp_outgoing,
		0,
		COMM_NONBLOCKING,
		"GRE Port");
	    leave_suid();
	    if ((theOutWccpConnection < 0) || (theOutGreConnection < 0))
		fatal("Cannot open Outgoing WCCP Port");
	    commSetSelect(theOutWccpConnection,
		COMM_SELECT_READ,
		wccpHandleUdp,
		NULL, 0);
	    commSetSelect(theInGreConnection,
		COMM_SELECT_READ,
		wccpHandleGre,
		NULL, 0);
	    debug(1, 1) ("Outgoing WCCP messages on port %d, FD %d.\n",
		(int) port, theOutWccpConnection);
	    fd_note(theOutWccpConnection, "Outgoing WCCP socket");
