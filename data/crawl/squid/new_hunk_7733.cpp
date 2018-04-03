    extern char *optarg;
    int c;

    while ((c = getopt(argc, argv, "CDFRUVYa:bf:hm:su:vz?")) != -1) {
	switch (c) {
	case 'C':
	    catch_signals = 0;
	    break;
	case 'D':
	    opt_dns_tests = 0;
	    break;
	case 'F':
	    opt_foreground_rebuild = 1;
	    break;
	case 'R':
	    do_reuse = 0;
	    break;
	case 'U':
	    opt_unlink_on_reload = 1;
	    break;
	case 'V':
	    vhost_mode = 1;
	    break;
	case 'Y':
	    opt_reload_hit_only = 1;
	    break;
	case 'a':
	    httpPortNumOverride = atoi(optarg);
	    break;
	case 'b':
	    unbuffered_logs = 0;
	    break;
	case 'f':
	    xfree(ConfigFile);
	    ConfigFile = xstrdup(optarg);
	    break;
	case 'h':
	    usage();
	    break;
	case 'm':
#if MALLOC_DBG
	    malloc_debug_level = atoi(optarg);
	    break;
#else
	    fatal("Need to add -DMALLOC_DBG when compiling to use -m option");
#endif
	case 's':
	    syslog_enable = 0;
	    break;
	case 'u':
	    icpPortNumOverride = atoi(optarg);
	    if (icpPortNumOverride < 0)
		icpPortNumOverride = 0;
	    break;
	case 'v':
	    printf("Squid Cache: Version %s\n", version_string);
	    exit(0);
	    /* NOTREACHED */
	case 'z':
	    zap_disk_store = 1;
	    break;
	case '?':
	default:
	    usage();
	    break;
	}
    }
}

void rotate_logs(sig)
     int sig;
{
    debug(21, 1, "rotate_logs: SIGUSR1 received.\n");
    rotate_pending = 1;
#if !HAVE_SIGACTION
    signal(sig, rotate_logs);
#endif
}

void reconfigure(sig)
     int sig;
{
    debug(21, 1, "reconfigure: SIGHUP received\n");
    debug(21, 1, "Waiting %d seconds for active connections to finish\n",
	getShutdownLifetime());
    reread_pending = 1;
#if !HAVE_SIGACTION
    signal(sig, reconfigure);
#endif
}

void shut_down(sig)
     int sig;
{
    debug(21, 1, "Preparing for shutdown after %d connections\n",
	ntcpconn + nudpconn);
    debug(21, 1, "Waiting %d seconds for active connections to finish\n",
	getShutdownLifetime());
    shutdown_pending = 1;
}

void serverConnectionsOpen()
{
    struct in_addr addr;
    u_short port;
    /* Get our real priviliges */

    /* Open server ports */
    enter_suid();
    theHttpConnection = comm_open(COMM_NONBLOCKING,
	getTcpIncomingAddr(),
	getHttpPortNum(),
	"HTTP Port");
    leave_suid();
    if (theHttpConnection < 0) {
	fatal("Cannot open HTTP Port");
    }
    fd_note(theHttpConnection, "HTTP socket");
    comm_listen(theHttpConnection);
    comm_set_select_handler(theHttpConnection,
	COMM_SELECT_READ,
	asciiHandleConn,
	0);
    debug(1, 1, "Accepting HTTP connections on FD %d.\n",
	theHttpConnection);

    if (!httpd_accel_mode || getAccelWithProxy()) {
	if ((port = getIcpPortNum()) > 0) {
	    theInIcpConnection = comm_open(COMM_NONBLOCKING | COMM_DGRAM,
		getUdpIncomingAddr(),
		port,
		"ICP Port");
	    if (theInIcpConnection < 0)
		fatal("Cannot open ICP Port");
	    fd_note(theInIcpConnection, "ICP socket");
	    comm_set_select_handler(theInIcpConnection,
		COMM_SELECT_READ,
		icpHandleUdp,
		0);
	    debug(1, 1, "Accepting ICP connections on FD %d.\n",
		theInIcpConnection);

	    if ((addr = getUdpOutgoingAddr()).s_addr != INADDR_NONE) {
		theOutIcpConnection = comm_open(COMM_NONBLOCKING | COMM_DGRAM,
		    addr,
		    port,
		    "ICP Port");
		if (theOutIcpConnection < 0)
		    fatal("Cannot open Outgoing ICP Port");
		comm_set_select_handler(theOutIcpConnection,
		    COMM_SELECT_READ,
		    icpHandleUdp,
		    0);
		debug(1, 1, "Accepting ICP connections on FD %d.\n",
		    theOutIcpConnection);
		fd_note(theOutIcpConnection, "Outgoing ICP socket");
		fd_note(theInIcpConnection, "Incoming ICP socket");
	    } else {
		theOutIcpConnection = theInIcpConnection;
	    }
	}
    }
}

void serverConnectionsClose()
{
    /* NOTE, this function will be called repeatedly while shutdown
     * is pending */
    if (theHttpConnection >= 0) {
	debug(21, 1, "FD %d Closing HTTP connection\n",
	    theHttpConnection);
	comm_close(theHttpConnection);
	comm_set_select_handler(theHttpConnection,
	    COMM_SELECT_READ,
	    NULL,
	    0);
	theHttpConnection = -1;
    }
    if (theInIcpConnection >= 0) {
	/* NOTE, don't close outgoing ICP connection, we need to write to
	 * it during shutdown */
	debug(21, 1, "FD %d Closing ICP connection\n",
	    theInIcpConnection);
	if (theInIcpConnection != theOutIcpConnection)
	    comm_close(theInIcpConnection);
	comm_set_select_handler(theInIcpConnection,
	    COMM_SELECT_READ,
	    NULL,
	    0);
	if (theInIcpConnection != theOutIcpConnection)
	    comm_set_select_handler(theOutIcpConnection,
		COMM_SELECT_READ,
		NULL,
		0);
	theInIcpConnection = -1;
    }
}

