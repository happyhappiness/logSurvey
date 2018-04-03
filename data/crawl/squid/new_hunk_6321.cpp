    storeAppendPrintf(sentry, "\n");
    storeAppendPrintf(sentry, "WAIS I/O\n");
    storeAppendPrintf(sentry, "number of reads: %d\n", IOStats.Wais.reads);
    storeAppendPrintf(sentry, "Read Histogram:\n");
    for (i = 0; i < 16; i++) {
	storeAppendPrintf(sentry, "%5d-%5d: %9d %2d%%\n",