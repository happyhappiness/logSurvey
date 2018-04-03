    }

    /* Sanity checks */
    if (Config.lifetimeDefault < Config.readTimeout) {
	printf("WARNING: client_lifetime (%d seconds) is less than read_timeout (%d seconds).\n",
	    Config.lifetimeDefault, Config.readTimeout);
	printf("         This may cause serious problems with your cache!!!\n");
	printf("         Change your configuration file.\n");
	fflush(stdout);		/* print message */
    }
    if (Config.Swap.maxSize < (Config.Mem.maxSize >> 10)) {
	printf("WARNING: cache_swap (%d kbytes) is less than cache_mem (%d bytes).\n", Config.Swap.maxSize, Config.Mem.maxSize);
	printf("         This will cause serious problems with your cache!!!\n");
	printf("         Change your configuration file.\n");
	Config.Swap.maxSize = Config.Mem.maxSize >> 10;
	printf("         For this run, however, %s will use %d kbytes for cache_swap.\n", appname, Config.Swap.maxSize);
	fflush(stdout);		/* print message */
    }
    if (Config.cleanRate > -1 && Config.cleanRate < 60) {
	Config.cleanRate = (30 * 60);
	printf("WARNING: clean_rate is less than one minute.\n");
	printf("         This will cause serious problems with your cache!!!\n");
	printf("         Change your configuration file.\n");
	printf("         For this run, however, %s will use %d minutes for clean_rate.\n", appname, (int) (Config.cleanRate / 60));
	fflush(stdout);		/* print message */
    }
    if (Config.dnsChildren < 1) {
	printf("WARNING: dns_children was set to a bad value: %d\n",
	    Config.dnsChildren);
	Config.dnsChildren = DefaultDnsChildren;
	printf("Setting it to the default (%d).\n", DefaultDnsChildren);
    } else if (Config.dnsChildren > DefaultDnsChildrenMax) {
	printf("WARNING: dns_children was set to a bad value: %d\n",
	    Config.dnsChildren);
	printf("Setting it to the maximum (%d).\n", DefaultDnsChildrenMax);
	Config.dnsChildren = DefaultDnsChildrenMax;
    }
    if (Config.redirectChildren < 1) {
	printf("WARNING: redirect_children was set to a bad value: %d\n",
	    Config.redirectChildren);
	Config.redirectChildren = DefaultRedirectChildren;
	printf("Setting it to the default (%d).\n", DefaultRedirectChildren);
    } else if (Config.redirectChildren > DefaultRedirectChildrenMax) {
	printf("WARNING: redirect_children was set to a bad value: %d\n",
	    Config.redirectChildren);
	printf("Setting it to the maximum (%d).\n", DefaultRedirectChildrenMax);
	Config.redirectChildren = DefaultRedirectChildrenMax;
    }
