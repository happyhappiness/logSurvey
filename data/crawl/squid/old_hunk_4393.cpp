                      IpcacheStats.numeric_hits);
    storeAppendPrintf(sentry, "IPcache Misses:          %d\n",
                      IpcacheStats.misses);
    storeAppendPrintf(sentry, "IPcache Invalid Request: %d\n",
                      IpcacheStats.invalid);
    storeAppendPrintf(sentry, "\n\n");
