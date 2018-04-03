    extern char *optarg;
    int c;

    while ((c = getopt(argc, argv, "vCDRVUbsif:a:p:u:m:zh?")) != -1) {
	switch (c) {
	case 'v':
	    printf("Squid Cache: Version %s\n", version_string);
	    exit(0);
	    /* NOTREACHED */
	case 'b':
	    unbuffered_logs = 0;
	    break;
	case 'V':
	    vhost_mode = 1;
	    break;
	case 'C':
	    catch_signals = 0;
	    break;
	case 'D':
	    do_dns_test = 0;
	    break;
	case 's':
	    syslog_enable = 0;
	    break;
	case 'R':
	    do_reuse = 0;
	    break;
	case 'U':
	    opt_unlink_on_reload = 1;
	    break;
	case 'f':
	    xfree(ConfigFile);
	    ConfigFile = xstrdup(optarg);
	    break;
	case 'a':
	    asciiPortNumOverride = atoi(optarg);
	    break;
	case 'u':
	    udpPortNumOverride = atoi(optarg);
	    break;
	case 'm':
	    malloc_debug_level = atoi(optarg);
	    break;
	case 'z':
	    zap_disk_store = 1;
	    break;
	case '?':
	case 'h':
	default:
	    usage();
	    break;
	}
    }
}

void serverConnectionsOpen()
{
    /* Get our real priviliges */
    get_suid();

    /* Open server ports */
    theAsciiConnection = comm_open(COMM_NONBLOCKING,
	getAsciiPortNum(),
	0,
	"Ascii Port");
    if (theAsciiConnection < 0) {
	fatal("Cannot open ascii Port");
    }
    fd_note(theAsciiConnection, "HTTP (Ascii) socket");
    comm_listen(theAsciiConnection);
    comm_set_select_handler(theAsciiConnection,
	COMM_SELECT_READ,
	asciiHandleConn,
	0);
    debug(1, 1, "Accepting HTTP (ASCII) connections on FD %d.\n",
	theAsciiConnection);

    if (!httpd_accel_mode || getAccelWithProxy()) {
	if (getUdpPortNum() > -1) {
	    theUdpConnection = comm_open(COMM_NONBLOCKING | COMM_DGRAM,
		getUdpPortNum(),
		0,
		"Ping Port");
	    if (theUdpConnection < 0)
		fatal("Cannot open UDP Port");
	    fd_note(theUdpConnection, "ICP (UDP) socket");
	    comm_set_select_handler(theUdpConnection,
		COMM_SELECT_READ,
		icpHandleUdp,
		0);
	    debug(1, 1, "Accepting ICP (UDP) connections on FD %d.\n",
		theUdpConnection);
	}
    }
    /* And restore our priviliges to normal */
    check_suid();
}

void serverConnectionsClose()
{
    if (theAsciiConnection >= 0) {
	debug(21, 1, "FD %d Closing Ascii connection\n",
	    theAsciiConnection);
	comm_close(theAsciiConnection);
	comm_set_select_handler(theAsciiConnection,
	    COMM_SELECT_READ,
	    NULL,
	    0);
	theAsciiConnection = -1;
    }
    if (theUdpConnection >= 0) {
	debug(21, 1, "FD %d Closing Udp connection\n",
	    theUdpConnection);
	/* Dont actually close it, just disable the read handler */
	/* so we can still transmit while shutdown pending */
	/* comm_close(theUdpConnection); */
	comm_set_select_handler(theUdpConnection,
	    COMM_SELECT_READ,
	    NULL,
	    0);
	/* theUdpConnection = -1; */
    }
}

