    storeAppendPrintf(sentry, "\tByte Hit Ratios:\t5min: %3.1f%%, 60min: %3.1f%%\n",
	statByteHitRatio(5),
	statByteHitRatio(60));
    storeAppendPrintf(sentry, "\tStorage Swap size:\t%d KB\n",
	store_swap_size);
    storeAppendPrintf(sentry, "\tStorage Mem size:\t%d KB\n",
