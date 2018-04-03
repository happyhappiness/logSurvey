	printf("WARNING: cache_swap (%d kbytes) is less than cache_mem (%d bytes).\n", Config.Swap.maxSize, Config.Mem.maxSize);
	printf("         This will cause serious problems with your cache!!!\n");
	printf("         Change your configuration file.\n");
	Config.Swap.maxSize = Config.Mem.maxSize >> 10;
	printf("         For this run, however, %s will use %d kbytes for cache_swap.\n", appname, Config.Swap.maxSize);
	fflush(stdout);		/* print message */
    }
    if (Config.cleanRate > -1 && Config.cleanRate < 60) {
