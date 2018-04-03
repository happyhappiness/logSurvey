    u_short port;
    int len;
    int x;
    enter_suid();
    theHttpConnection = comm_open(SOCK_STREAM,
	0,
	Config.Addrs.tcp_incoming,
	Config.Port.http,
	COMM_NONBLOCKING,
	"HTTP Port");
    leave_suid();
    if (theHttpConnection < 0) {
	fatal("Cannot open HTTP Port");
    }
    fd_note(theHttpConnection, "HTTP socket");
    comm_listen(theHttpConnection);
    commSetSelect(theHttpConnection,
	COMM_SELECT_READ,
	asciiHandleConn,
	NULL, 0);
    debug(1, 1, "Accepting HTTP connections on FD %d.\n",
	theHttpConnection);

    if (!httpd_accel_mode || Config.Accel.withProxy) {
	if ((port = Config.Port.icp) > (u_short) 0) {
	    enter_suid();
