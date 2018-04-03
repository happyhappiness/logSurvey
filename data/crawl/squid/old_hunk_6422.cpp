    storeAppendPrintf(sentry, "client_http.hit_median_svc_time = %f seconds\n",
	x / 1000.0);

#if USE_CACHE_DIGESTS
    storeAppendPrintf(sentry, "cd.msgs_sent = %f/sec\n",
	XAVG(cd.msgs_sent));
    storeAppendPrintf(sentry, "cd.msgs_recv = %f/sec\n",
	XAVG(cd.msgs_recv));
    storeAppendPrintf(sentry, "cd.kbytes_sent = %f/sec\n",
	XAVG(cd.kbytes_sent.kb));
    storeAppendPrintf(sentry, "cd.kbytes_recv = %f/sec\n",
	XAVG(cd.kbytes_recv.kb));
    x = statHistDeltaMedian(&l->cd.client_svc_time,
	&f->cd.client_svc_time);
    storeAppendPrintf(sentry, "cd.client_median_svc_time = %f seconds\n",
	x / 1000.0);
    x = statHistDeltaMedian(&l->cd.server_svc_time,
	&f->cd.server_svc_time);
    storeAppendPrintf(sentry, "cd.server_median_svc_time = %f seconds\n",
	x / 1000.0);
    x = statHistDeltaMedian(&l->icp.client_svc_time,
	&f->icp.client_svc_time);
    storeAppendPrintf(sentry, "icp.client_median_svc_time = %f seconds\n",
	x / 1000.0);
    x = statHistDeltaMedian(&l->icp.server_svc_time,
	&f->icp.server_svc_time);
    storeAppendPrintf(sentry, "icp.server_median_svc_time = %f seconds\n",
	x / 1000.0);
#endif

    storeAppendPrintf(sentry, "server.all.requests = %f/sec\n",
	XAVG(server.all.requests));
    storeAppendPrintf(sentry, "server.all.errors = %f/sec\n",
