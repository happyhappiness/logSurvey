    storeAppendPrintf(sentry, "number of reads: %.0f\n", stats.http_reads);
    storeAppendPrintf(sentry, "Read Histogram:\n");

    for (i = 0; i < IoStats::histSize; ++i) {
        storeAppendPrintf(sentry, "%5d-%5d: %9.0f %2.0f%%\n",
                          i ? (1 << (i - 1)) + 1 : 1,
                          1 << i,
