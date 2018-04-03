    storeAppendPrintf(sentry, "\tAverage ICP messages per minute since start:\t%.1f\n",
                      (statCounter.icp.pkts_sent + statCounter.icp.pkts_recv) / (runtime / 60.0));

    storeAppendPrintf(sentry, "\tSelect loop called: %ld times, %0.3f ms avg\n",
                      statCounter.select_loops, 1000.0 * runtime / statCounter.select_loops);

    storeAppendPrintf(sentry, "Cache information for %s:\n",APP_SHORTNAME);
