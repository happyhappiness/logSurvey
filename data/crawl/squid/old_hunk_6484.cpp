	&f->cd.client_svc_time);
    storeAppendPrintf(sentry, "cd.client_median_svc_time = %f seconds\n",
	x / 1000.0);
    x = statHistDeltaMedian(&l->icp.client_svc_time,
	&f->icp.client_svc_time);
    storeAppendPrintf(sentry, "icp.client_median_svc_time = %f seconds\n",
	x / 1000.0);
#endif

    storeAppendPrintf(sentry, "server.all.requests = %f/sec\n",
