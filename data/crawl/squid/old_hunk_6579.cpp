	Counter.icp.pkts_recv);
    storeAppendPrintf(sentry, "\tNumber of ICP messages sent:\t%u\n",
	Counter.icp.pkts_sent);
    storeAppendPrintf(sentry, "\tRequest failure ratio:\t%5.2f%%\n",
	request_failure_ratio);

