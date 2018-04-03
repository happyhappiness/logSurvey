	XAVG(icp.kbytes_sent.kb));
    storeAppendPrintf(sentry, "icp.kbytes_recv = %f/sec\n",
	XAVG(icp.kbytes_recv.kb));
    x = statHistDeltaMedian(&l->icp.query_svc_time, &f->icp.query_svc_time);
    storeAppendPrintf(sentry, "icp.query_median_svc_time = %f seconds\n",
	x / 1000000.0);
    x = statHistDeltaMedian(&l->icp.reply_svc_time, &f->icp.reply_svc_time);
    storeAppendPrintf(sentry, "icp.reply_median_svc_time = %f seconds\n",
	x / 1000000.0);
    x = statHistDeltaMedian(&l->dns.svc_time, &f->dns.svc_time);
    storeAppendPrintf(sentry, "dns.median_svc_time = %f seconds\n",
	x / 1000.0);
    storeAppendPrintf(sentry, "unlink.requests = %f/sec\n",