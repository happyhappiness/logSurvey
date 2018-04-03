
    storeAppendPrintf(sentry, "Delay pools configured: %d\n\n", Config.Delay.pools);
    for (i = 0; i < Config.Delay.pools; i++) {
	switch (Config.Delay.delay_class[i]) {
	case 0:
	    storeAppendPrintf(sentry, "Pool: %d\n\tClass: 0\n\n", i + 1);
	    storeAppendPrintf(sentry, "\tMisconfigured pool.\n\n");
