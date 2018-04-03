    statHistDump(&f->cd.client_svc_time, sentry, NULL);

    storeAppendPrintf(sentry, "\nMedian service times:\n");
    x = statHistDeltaMedian(&l->client_http.all_svc_time,
	&f->client_http.all_svc_time);
    storeAppendPrintf(sentry, "client_http.all_median_svc_time = %f seconds\n",
	x / 1000.0);
    x = statHistDeltaMedian(&l->client_http.miss_svc_time,
	&f->client_http.miss_svc_time);
    storeAppendPrintf(sentry, "client_http.miss_median_svc_time = %f seconds\n",
	x / 1000.0);
    x = statHistDeltaMedian(&l->client_http.hit_svc_time,
	&f->client_http.hit_svc_time);
    storeAppendPrintf(sentry, "client_http.hit_median_svc_time = %f seconds\n",
	x / 1000.0);
    x = statHistDeltaMedian(&l->cd.client_svc_time,
	&f->cd.client_svc_time);
    storeAppendPrintf(sentry, "cd.client_median_svc_time = %f seconds\n",