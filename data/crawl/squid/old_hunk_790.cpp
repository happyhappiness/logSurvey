
    storeAppendPrintf(sentry, "Connection information for %s:\n",APP_SHORTNAME);

    storeAppendPrintf(sentry, "\tNumber of clients accessing cache:\t%.0f\n",
                      stats.client_http_clients);

    storeAppendPrintf(sentry, "\tNumber of HTTP requests received:\t%.0f\n",
                      stats.client_http_requests);