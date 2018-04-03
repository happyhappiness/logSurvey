    storeAppendPrintf(sentry, "\tRequest failure ratio:\t%5.2f%%\n",
	request_failure_ratio);

    storeAppendPrintf(sentry, "\tAverage HTTP requests per minute since start:\t%.1f\n",
	statCounter.client_http.requests / (runtime / 60.0));
    storeAppendPrintf(sentry, "\tAverage ICP messages per minute since start:\t%.1f\n",
	(statCounter.icp.pkts_sent + statCounter.icp.pkts_recv) / (runtime / 60.0));
    storeAppendPrintf(sentry, "\tSelect loop called: %d times, %0.3f ms avg\n",
	statCounter.select_loops, 1000.0 * runtime / statCounter.select_loops);