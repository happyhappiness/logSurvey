	Counter.icp.pkts_recv);
    storeAppendPrintf(sentry, "{\tNumber of ICP messages sent:\t%u}\n",
	Counter.icp.pkts_sent);

    storeAppendPrintf(sentry, "{\tHTTP requests per minute:\t%.1f}\n",
	Counter.client_http.requests / (runtime / 60.0));
