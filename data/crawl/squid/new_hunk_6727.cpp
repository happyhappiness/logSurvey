	(int) f->client_http.kbytes_in.kb);
    storeAppendPrintf(sentry, "client_http.kbytes_out = %d\n",
	(int) f->client_http.kbytes_out.kb);
    storeAppendPrintf(sentry, "client_http.all_svc_time histogram:\n");
    statLogHistDump(sentry, &f->client_http.all_svc_time);
    storeAppendPrintf(sentry, "client_http.miss_svc_time histogram:\n");
    statLogHistDump(sentry, &f->client_http.miss_svc_time);
    storeAppendPrintf(sentry, "client_http.nm_svc_time histogram:\n");
    statLogHistDump(sentry, &f->client_http.nm_svc_time);
    storeAppendPrintf(sentry, "client_http.hit_svc_time histogram:\n");
    statLogHistDump(sentry, &f->client_http.hit_svc_time);

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
    storeAppendPrintf(sentry, "icp.pkts_recv = %d\n",
