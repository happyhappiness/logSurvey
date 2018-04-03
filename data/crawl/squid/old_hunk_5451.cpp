	if (DnsSocket < 0)
	    fatal("Could not create a DNS socket");
	/* Ouch... we can't call functions using debug from a debug
	 * statement. Doing so messes up the internal _db_level
	 */
	port = comm_local_port(DnsSocket);
	debug(78, 1) ("DNS Socket created at %s, port %d, FD %d\n",
