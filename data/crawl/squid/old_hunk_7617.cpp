	printf("         Change your configuration file.\n");
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