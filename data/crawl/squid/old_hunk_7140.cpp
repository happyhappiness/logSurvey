    }
    if (NHttpSockets < 1)
	fatal("Cannot open HTTP Port");
    if (!httpd_accel_mode || Config.Accel.withProxy) {
	if ((port = Config.Port.icp) > (u_short) 0) {
	    enter_suid();
	    theInIcpConnection = comm_open(SOCK_DGRAM,
