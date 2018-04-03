	IpcacheStats.negative_hits);
    storeAppendPrintf(sentry, "IPcache Misses: %d\n",
	IpcacheStats.misses);
    storeAppendPrintf(sentry, "\n\n");
    storeAppendPrintf(sentry, "IP Cache Contents:\n\n");
    storeAppendPrintf(sentry, " %-29.29s %3s %6s %6s %1s\n",
