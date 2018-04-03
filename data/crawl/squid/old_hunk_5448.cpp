	statCounter.icp.pkts_sent);
    storeAppendPrintf(sentry, "\tNumber of queued ICP replies:\t%u\n",
	statCounter.icp.replies_queued);
    storeAppendPrintf(sentry, "\tRequest failure ratio:\t%5.2f%%\n",
	request_failure_ratio);

    storeAppendPrintf(sentry, "\tAverage HTTP requests per minute since start:\t%.1f\n",
