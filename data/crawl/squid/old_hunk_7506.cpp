#endif
#endif

    while ((c = getopt(argc, argv, "vhdtp:")) != -1) {
	switch (c) {
	case 'v':
	case 'h':
	    printf("dnsserver version %s\n", SQUID_VERSION);
	    exit(0);
	    break;
