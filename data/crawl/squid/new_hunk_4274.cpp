    storeAppendPrintf(sentry, "\tSelect loop called: %d times, %0.3f ms avg\n",
                      statCounter.select_loops, 1000.0 * runtime / statCounter.select_loops);

    storeAppendPrintf(sentry, "Cache information for %s:\n",APP_SHORTNAME);

    storeAppendPrintf(sentry, "\tHits as %% of all requests:\t5min: %3.1f%%, 60min: %3.1f%%\n",
                      statRequestHitRatio(5),
