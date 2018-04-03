	printf("WARNING: client_lifetime (%d seconds) is less than read_timeout (%d seconds).\n",
	    getClientLifetime(), getReadTimeout());
	printf("         This may cause serious problems with your cache!!!\n");
	printf("         Change your cached.conf file.\n");
	fflush(stdout);		/* print message */
    }
    if (getCacheSwapMax() < (getCacheMemMax() >> 10)) {
	printf("WARNING: cache_swap (%d kbytes) is less than cache_mem (%d bytes).\n", getCacheSwapMax(), getCacheMemMax());
	printf("         This will cause serious problems with your cache!!!\n");
	printf("         Change your cached.conf file.\n");
	Config.Swap.maxSize = getCacheMemMax() >> 10;
	printf("         For this run, however, cached will use %d kbytes for cache_swap.\n", getCacheSwapMax());
	fflush(stdout);		/* print message */
    }
    if (getCleanRate() > -1 && getCleanRate() < 60) {
	Config.cleanRate = (30 * 60);
	printf("WARNING: clean_rate is less than one minute.\n");
	printf("         This will cause serious problems with your cache!!!\n");
	printf("         Change your cached.conf file.\n");
	printf("         For this run, however, cached will use %d minutes for clean_rate.\n", (int) (getCleanRate() / 60));
	fflush(stdout);		/* print message */
    }
    if (accel_ip_acl == NULL)
