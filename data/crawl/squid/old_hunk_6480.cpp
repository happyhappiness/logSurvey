    statHistDump(&f->cd.client_svc_time, sentry, NULL);

    storeAppendPrintf(sentry, "\nMedian service times:\n");
    x = statHistDeltaMedian(&l->cd.client_svc_time,
	&f->cd.client_svc_time);
    storeAppendPrintf(sentry, "cd.client_median_svc_time = %f seconds\n",