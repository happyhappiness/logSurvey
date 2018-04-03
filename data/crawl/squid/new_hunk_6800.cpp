	XAVG(icp.kbytes_sent.kb));
    storeAppendPrintf(sentry, "icp.kbytes_recv = %f/sec\n",
	XAVG(icp.kbytes_recv.kb));
    x = statLogHistDeltaMedian(&l->icp.svc_time, &f->icp.svc_time);
    storeAppendPrintf(sentry, "icp.median_svc_time = %f seconds\n",
	x / 1000000.0);
    storeAppendPrintf(sentry, "unlink.requests = %f/sec\n",
	XAVG(unlink.requests));
    storeAppendPrintf(sentry, "page_faults = %f/sec\n",
