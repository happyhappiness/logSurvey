		theInIcpConnection);

	    if ((addr = Config.Addrs.udp_outgoing).s_addr != INADDR_NONE) {
		theOutIcpConnection = comm_open(COMM_NONBLOCKING | COMM_DGRAM,
		    addr,
		    port,
		    "ICP Port");
		if (theOutIcpConnection < 0)
		    fatal("Cannot open Outgoing ICP Port");
