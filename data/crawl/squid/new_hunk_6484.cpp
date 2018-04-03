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
