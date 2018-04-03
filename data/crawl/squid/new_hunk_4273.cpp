    storeAppendPrintf(sentry, "Current Time:\t%s\n",
                      mkrfc1123(current_time.tv_sec));

    storeAppendPrintf(sentry, "Connection information for %s:\n",APP_SHORTNAME);

    storeAppendPrintf(sentry, "\tNumber of clients accessing cache:\t%u\n",
                      statCounter.client_http.clients);
