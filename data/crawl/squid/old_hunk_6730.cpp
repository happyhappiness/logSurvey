	XAVG(client_http.kbytes_in.kb));
    storeAppendPrintf(sentry, "client_http.kbytes_out = %f/sec\n",
	XAVG(client_http.kbytes_out.kb));
    x = statLogHistDeltaMedian(&l->client_http.svc_time, &f->client_http.svc_time);
    storeAppendPrintf(sentry, "client_http.median_svc_time = %f seconds\n",
	x / 1000.0);
    storeAppendPrintf(sentry, "icp.pkts_sent = %f/sec\n",
	XAVG(icp.pkts_sent));
    storeAppendPrintf(sentry, "icp.pkts_recv = %f/sec\n",
