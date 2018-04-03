    storeAppendPrintf(sentry, "client_http.hit_svc_time histogram:\n");
    statHistDump(&f->client_http.hit_svc_time, sentry, NULL);

    storeAppendPrintf(sentry, "server.requests = %d\n",
	(int) f->server.requests);
    storeAppendPrintf(sentry, "server.errors = %d\n",
	(int) f->server.errors);
    storeAppendPrintf(sentry, "server.kbytes_in = %d\n",
	(int) f->server.kbytes_in.kb);
    storeAppendPrintf(sentry, "server.kbytes_out = %d\n",
	(int) f->server.kbytes_out.kb);

    storeAppendPrintf(sentry, "icp.pkts_sent = %d\n",
	f->icp.pkts_sent);
