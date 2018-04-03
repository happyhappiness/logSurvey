                      IpcacheStats.numeric_hits);
    storeAppendPrintf(sentry, "IPcache Misses:          %d\n",
                      IpcacheStats.misses);
    storeAppendPrintf(sentry, "IPcache Retrieved A: %d\n",
                      IpcacheStats.rr_a);
    storeAppendPrintf(sentry, "IPcache Retrieved AAAA: %d\n",
                      IpcacheStats.rr_aaaa);
    storeAppendPrintf(sentry, "IPcache Retrieved CNAME: %d\n",
                      IpcacheStats.rr_cname);
    storeAppendPrintf(sentry, "IPcache CNAME-Only Response: %d\n",
                      IpcacheStats.cname_only);
    storeAppendPrintf(sentry, "IPcache Invalid Request: %d\n",
                      IpcacheStats.invalid);
    storeAppendPrintf(sentry, "\n\n");
