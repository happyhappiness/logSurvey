    int maxfd;
    int nfds;
    int num;
    static int incoming_counter = 0;
    static time_t last_timeout = 0;
    struct timeval poll_time;
    static int lastinc;
    time_t timeout;

    /* assume all process are very fast (less than 1 second). Call
     * time() only once */
    /* use only 1 second granularity */
    timeout = squid_curtime + sec;

    do {
	FD_ZERO(&readfds);
	FD_ZERO(&writefds);
	if (shutdown_pending || reconfigure_pending) {
	    serverConnectionsClose();
	    dnsShutdownServers();
