
    if (!httpd_accel_mode || Config.Accel.withProxy) {
	if ((port = Config.Port.icp) > (u_short) 0) {
	    theInIcpConnection = comm_open(COMM_NONBLOCKING | COMM_DGRAM,
		Config.Addrs.udp_incoming,
		port,
		"ICP Port");
	    if (theInIcpConnection < 0)
		fatal("Cannot open ICP Port");
