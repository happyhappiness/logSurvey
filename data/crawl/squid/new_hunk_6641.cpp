    storeAppendPrintf(sentry, "client_http.hit_svc_time histogram:\n");
    statHistDump(&f->client_http.hit_svc_time, sentry, NULL);

    storeAppendPrintf(sentry, "server.all.requests = %d\n",
	(int) f->server.all.requests);
    storeAppendPrintf(sentry, "server.all.errors = %d\n",
	(int) f->server.all.errors);
    storeAppendPrintf(sentry, "server.all.kbytes_in = %d\n",
	(int) f->server.all.kbytes_in.kb);
    storeAppendPrintf(sentry, "server.all.kbytes_out = %d\n",
	(int) f->server.all.kbytes_out.kb);

    storeAppendPrintf(sentry, "server.http.requests = %d\n",
	(int) f->server.http.requests);
    storeAppendPrintf(sentry, "server.http.errors = %d\n",
	(int) f->server.http.errors);
    storeAppendPrintf(sentry, "server.http.kbytes_in = %d\n",
	(int) f->server.http.kbytes_in.kb);
    storeAppendPrintf(sentry, "server.http.kbytes_out = %d\n",
	(int) f->server.http.kbytes_out.kb);

    storeAppendPrintf(sentry, "server.ftp.requests = %d\n",
	(int) f->server.ftp.requests);
    storeAppendPrintf(sentry, "server.ftp.errors = %d\n",
	(int) f->server.ftp.errors);
    storeAppendPrintf(sentry, "server.ftp.kbytes_in = %d\n",
	(int) f->server.ftp.kbytes_in.kb);
    storeAppendPrintf(sentry, "server.ftp.kbytes_out = %d\n",
	(int) f->server.ftp.kbytes_out.kb);

    storeAppendPrintf(sentry, "server.other.requests = %d\n",
	(int) f->server.other.requests);
    storeAppendPrintf(sentry, "server.other.errors = %d\n",
	(int) f->server.other.errors);
    storeAppendPrintf(sentry, "server.other.kbytes_in = %d\n",
	(int) f->server.other.kbytes_in.kb);
    storeAppendPrintf(sentry, "server.other.kbytes_out = %d\n",
	(int) f->server.other.kbytes_out.kb);

    storeAppendPrintf(sentry, "icp.pkts_sent = %d\n",
	f->icp.pkts_sent);
