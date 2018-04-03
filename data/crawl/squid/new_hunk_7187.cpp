    unsigned long nfds;
    int num;
    static time_t last_timeout = 0;
    static int lastinc = 0;
    int poll_time;
    static int incoming_counter = 0;
    time_t timeout;
    /* assume all process are very fast (less than 1 second). Call
     * time() only once */
    /* use only 1 second granularity */
    timeout = squid_curtime + sec;
    do {
	if (shutdown_pending || reconfigure_pending) {
	    serverConnectionsClose();
	    dnsShutdownServers();
