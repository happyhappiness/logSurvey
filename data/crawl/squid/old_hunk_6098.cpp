	if (theInWccpConnection < 0)
	    fatal("Cannot open WCCP Port");
	commSetSelect(theInWccpConnection, COMM_SELECT_READ, wccpHandleUdp, NULL, 0);
	debug(1, 1) ("Accepting WCCP UDP messages on port %d, FD %d.\n",
	    (int) port, theInWccpConnection);
	if (Config.Wccp.outgoing.s_addr != no_addr.s_addr) {
	    enter_suid();
