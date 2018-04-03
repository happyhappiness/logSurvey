    SwapDir *SD;

    storeAppendPrintf(sentry, "Store Directory Statistics:\n");
    storeAppendPrintf(sentry, "Store Entries          : %d\n",
	storeEntryInUse());
    storeAppendPrintf(sentry, "Maximum Swap Size      : %8ld KB\n",
	(long int) Config.Swap.maxSize);
    storeAppendPrintf(sentry, "Current Store Swap Size: %8lu KB\n",