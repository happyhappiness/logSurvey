
    if (!httpd_accel_mode || Config.Accel.withProxy) {
	if ((port = Config.Port.icp) > (u_short) 0) {
	    theInIcpConnection = comm_open(SOCK_DGRAM,
		0,
		Config.Addrs.udp_incoming,
		port,
		COMM_NONBLOCKING,
		"ICP Port");
	    if (theInIcpConnection < 0)
		fatal("Cannot open ICP Port");
