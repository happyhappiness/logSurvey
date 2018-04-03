#endif
}

static void
statCountersDump(StoreEntry * sentry)
{
    StatCounters *f = &Counter;
    struct rusage rusage;
    squid_getrusage(&rusage);
    f->page_faults = rusage_pagefaults(&rusage);
    f->cputime = rusage_cputime(&rusage);

    storeAppendPrintf(sentry, "client_http.requests = %d\n",
	f->client_http.requests);
    storeAppendPrintf(sentry, "client_http.hits = %d\n",
	f->client_http.hits);
    storeAppendPrintf(sentry, "client_http.errors = %d\n",
	f->client_http.errors);
    storeAppendPrintf(sentry, "client_http.kbytes_in = %d\n",
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
	f->icp.pkts_recv);
    storeAppendPrintf(sentry, "icp.kbytes_sent = %d\n",
	(int) f->icp.kbytes_sent.kb);
    storeAppendPrintf(sentry, "icp.kbytes_recv = %d\n",
	(int) f->icp.kbytes_recv.kb);
    storeAppendPrintf(sentry, "icp.query_svc_time histogram:\n");
    statLogHistDump(sentry, &f->icp.query_svc_time);
    storeAppendPrintf(sentry, "icp.reply_svc_time histogram:\n");
    statLogHistDump(sentry, &f->icp.reply_svc_time);

    storeAppendPrintf(sentry, "dns.svc_time histogram:\n");
    statLogHistDump(sentry, &f->dns.svc_time);
    storeAppendPrintf(sentry, "unlink.requests = %d\n",
	f->unlink.requests);
    storeAppendPrintf(sentry, "page_faults = %d\n",
	f->page_faults);
    storeAppendPrintf(sentry, "select_loops = %d\n",
	f->select_loops);
    storeAppendPrintf(sentry, "cpu_time = %f\n",
	f->cputime);
    storeAppendPrintf(sentry, "wall_time = %f\n",
	tvSubDsec(f->timestamp, current_time));
}

#define XAVG(X) (dt ? (double) (f->X - l->X) / dt : 0.0)
static void
statAvgDump(StoreEntry * sentry, int minutes)
