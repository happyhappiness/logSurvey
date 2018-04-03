    }

    /* enable syslog by default */
    syslog_enable = 0;
    /* preinit for debug module */
    debug_log = stderr;
    hash_init(0);

    while ((c = getopt(argc, argv, "vCDRVsif:a:p:u:m:zh?")) != -1)
	switch (c) {
	case 'v':
	    printf("Harvest Cache: Version %s\n", SQUID_VERSION);
