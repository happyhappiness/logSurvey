	}
    }

    /* Scale values */
    Config.maxRequestSize <<= 10;	/* 1k */
    Config.Store.maxObjectSize <<= 10;	/* 1k */
    Config.Mem.maxSize <<= 10;	/* 1m */

    /* Sanity checks */
    if (Config.Swap.maxSize < (Config.Mem.maxSize >> 10)) {
	printf("WARNING: cache_swap (%d kbytes) is less than cache_mem (%d bytes).\n", Config.Swap.maxSize, Config.Mem.maxSize);
