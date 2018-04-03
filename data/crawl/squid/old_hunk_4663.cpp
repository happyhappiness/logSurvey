    storeAppendPrintf(sentry, "Median Service Times (seconds)  5 min    60 min:\n");

    storeAppendPrintf(sentry, "\tHTTP Requests (All):  %8.5f %8.5f\n",
                      statMedianSvc(5, MEDIAN_HTTP) / 1000.0,
                      statMedianSvc(60, MEDIAN_HTTP) / 1000.0);

    storeAppendPrintf(sentry, "\tCache Misses:         %8.5f %8.5f\n",
                      statMedianSvc(5, MEDIAN_MISS) / 1000.0,
                      statMedianSvc(60, MEDIAN_MISS) / 1000.0);

    storeAppendPrintf(sentry, "\tCache Hits:           %8.5f %8.5f\n",
                      statMedianSvc(5, MEDIAN_HIT) / 1000.0,
                      statMedianSvc(60, MEDIAN_HIT) / 1000.0);

    storeAppendPrintf(sentry, "\tNear Hits:            %8.5f %8.5f\n",
                      statMedianSvc(5, MEDIAN_NH) / 1000.0,
                      statMedianSvc(60, MEDIAN_NH) / 1000.0);

    storeAppendPrintf(sentry, "\tNot-Modified Replies: %8.5f %8.5f\n",
                      statMedianSvc(5, MEDIAN_NM) / 1000.0,
                      statMedianSvc(60, MEDIAN_NM) / 1000.0);

    storeAppendPrintf(sentry, "\tDNS Lookups:          %8.5f %8.5f\n",
                      statMedianSvc(5, MEDIAN_DNS) / 1000.0,
                      statMedianSvc(60, MEDIAN_DNS) / 1000.0);

    storeAppendPrintf(sentry, "\tICP Queries:          %8.5f %8.5f\n",
                      statMedianSvc(5, MEDIAN_ICP_QUERY) / 1000000.0,
                      statMedianSvc(60, MEDIAN_ICP_QUERY) / 1000000.0);

    squid_getrusage(&rusage);

