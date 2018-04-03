    int i;
    SwapDir *SD;
    storeAppendPrintf(sentry, "Store Directory Statistics:\n");
    storeAppendPrintf(sentry, "Store Entries: %d\n", meta_data.store_entries);
    storeAppendPrintf(sentry, "Store Swap Size: %d KB\n", store_swap_size);
    for (i = 0; i < Config.cacheSwap.n_configured; i++) {
	SD = &Config.cacheSwap.swapDirs[i];
	storeAppendPrintf(sentry, "\n");