		port,
		COMM_NONBLOCKING,
		"WCCP Port");
	    leave_suid();
	    if (theOutWccpConnection < 0)
		fatal("Cannot open Outgoing WCCP Port");
	    commSetSelect(theOutWccpConnection,
		COMM_SELECT_READ,
		wccpHandleUdp,
		NULL, 0);
	    debug(1, 1) ("Outgoing WCCP messages on port %d, FD %d.\n",
		(int) port, theOutWccpConnection);
	    fd_note(theOutWccpConnection, "Outgoing WCCP socket");
