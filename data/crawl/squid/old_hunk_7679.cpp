	IpcacheStats.misses);
    storeAppendPrintf(sentry, "{Blocking calls to gethostbyname(): %d}\n",
	IpcacheStats.ghbn_calls);
    storeAppendPrintf(sentry, "{dnsserver requests: %d}\n",
	IpcacheStats.dnsserver_requests);
    storeAppendPrintf(sentry, "{dnsserver replies: %d}\n",
	IpcacheStats.dnsserver_replies);
    storeAppendPrintf(sentry, "{dnsserver avg service time: %d msec}\n",
	IpcacheStats.avg_svc_time);
    storeAppendPrintf(sentry, "{number of dnsservers: %d}\n",
	getDnsChildren());
    storeAppendPrintf(sentry, "{dnsservers use histogram:}\n");
    for (k = 0; k < getDnsChildren(); k++) {
	storeAppendPrintf(sentry, "{    dnsserver #%d: %d}\n",
	    k + 1,
	    IpcacheStats.dnsserver_hist[k]);
    }
    storeAppendPrintf(sentry, "}\n\n");
    storeAppendPrintf(sentry, "{IP Cache Contents:\n\n");

