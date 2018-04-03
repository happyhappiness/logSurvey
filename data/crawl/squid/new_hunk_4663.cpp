    storeAppendPrintf(sentry, "Median Service Times (seconds)  5 min    60 min:\n");

    storeAppendPrintf(sentry, "\tHTTP Requests (All):  %8.5f %8.5f\n",
                      statPctileSvc(0.5, 5, PCTILE_HTTP) / 1000.0,
                      statPctileSvc(0.5, 60, PCTILE_HTTP) / 1000.0);

    storeAppendPrintf(sentry, "\tCache Misses:         %8.5f %8.5f\n",
                      statPctileSvc(0.5, 5, PCTILE_MISS) / 1000.0,
                      statPctileSvc(0.5, 60, PCTILE_MISS) / 1000.0);

    storeAppendPrintf(sentry, "\tCache Hits:           %8.5f %8.5f\n",
                      statPctileSvc(0.5, 5, PCTILE_HIT) / 1000.0,
                      statPctileSvc(0.5, 60, PCTILE_HIT) / 1000.0);

    storeAppendPrintf(sentry, "\tNear Hits:            %8.5f %8.5f\n",
                      statPctileSvc(0.5, 5, PCTILE_NH) / 1000.0,
                      statPctileSvc(0.5, 60, PCTILE_NH) / 1000.0);

    storeAppendPrintf(sentry, "\tNot-Modified Replies: %8.5f %8.5f\n",
                      statPctileSvc(0.5, 5, PCTILE_NM) / 1000.0,
                      statPctileSvc(0.5, 60, PCTILE_NM) / 1000.0);

    storeAppendPrintf(sentry, "\tDNS Lookups:          %8.5f %8.5f\n",
                      statPctileSvc(0.5, 5, PCTILE_DNS) / 1000.0,
                      statPctileSvc(0.5, 60, PCTILE_DNS) / 1000.0);

    storeAppendPrintf(sentry, "\tICP Queries:          %8.5f %8.5f\n",
                      statPctileSvc(0.5, 5, PCTILE_ICP_QUERY) / 1000000.0,
                      statPctileSvc(0.5, 60, PCTILE_ICP_QUERY) / 1000000.0);

    squid_getrusage(&rusage);

