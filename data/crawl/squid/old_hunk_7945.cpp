	theAsciiConnection);

    if (!httpd_accel_mode || getAccelWithProxy()) {
#ifdef KEEP_BINARY_CONN
	theBinaryConnection = comm_open(COMM_NONBLOCKING,
	    binaryPortNum,
	    0,
	    "Binary Port");

	if (theBinaryConnection < 0) {
	    fatal("Cannot open Binary Port\n");
	}
	comm_listen(theBinaryConnection);
	comm_set_select_handler(theBinaryConnection,
	    COMM_SELECT_READ,
	    icpHandleTcp,
	    0);
	debug(0, 1, "Binary connection opened on fd %d\n", theBinaryConnection);
#endif
	if (getUdpPortNum() > -1) {
	    theUdpConnection = comm_open(COMM_NONBLOCKING | COMM_DGRAM,
		getUdpPortNum(),