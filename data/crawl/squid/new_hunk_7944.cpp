    debug_log = stderr;
    hash_init(0);

    while ((c = getopt(argc, argv, "vCDRVbsif:a:p:u:m:zh?")) != -1)
	switch (c) {
	case 'v':
	    printf("Harvest Cache: Version %s\n", SQUID_VERSION);
	    exit(0);
	    /* NOTREACHED */
	case 'b':
	    unbuffered_logs = 0;
	    break;
	case 'V':
	    vhost_mode = 1;
	    break;
