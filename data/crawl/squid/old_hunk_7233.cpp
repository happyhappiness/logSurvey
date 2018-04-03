	    fatal_dump(NULL);
	if (shutdown_pending || reconfigure_pending) {
	    serverConnectionsClose();
	    ftpServerClose();
	    dnsShutdownServers();
	    redirectShutdownServers();
	    /* shutdown_pending will be set to
