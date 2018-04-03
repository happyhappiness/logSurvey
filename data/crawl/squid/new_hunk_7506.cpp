#endif
#endif

    while ((c = getopt(argc, argv, "vhd")) != -1) {
	switch (c) {
	case 'v':
	    printf("dnsserver version %s\n", SQUID_VERSION);
	    exit(0);
	    break;
