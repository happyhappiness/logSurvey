void
statAvgInit(void)
{
    int i;
    memset(CountHist, '\0', N_COUNT_HIST * sizeof(StatCounters));
    for (i=0; i<N_COUNT_HIST; i++)
	CountHist[i].timestamp = current_time;
    eventAdd("statAvgTick", statAvgTick, NULL, 60);
}

static void
statAvgTick(void *notused)
{
    StatCounters *t = &CountHist[0];
    StatCounters *p = &CountHist[1];
    StatCounters *c = &Counter;
    struct rusage rusage;
    eventAdd("statAvgTick", statAvgTick, NULL, 60);
    squid_getrusage(&rusage);
    c->page_faults = rusage_pagefaults(&rusage);
    c->cputime = rusage_cputime(&rusage);
    c->timestamp = current_time;
    memmove(p, t, (N_COUNT_HIST - 1) * sizeof(StatCounters));
    memcpy(t, c, sizeof(StatCounters));
    NCountHist++;
}

void
statAvgDump(StoreEntry * sentry)
{
    StatCounters *f = &CountHist[0];
    StatCounters *l = &CountHist[N_COUNT_HIST - 1];
    double dt;
    double ct;
    eventDelete(statAvgTick, NULL);
    statAvgTick(NULL);
    dt = tvSubDsec(l->timestamp, f->timestamp);
    ct = f->cputime - l->cputime;
debug(0,0)("statAvgDump: dt=%f\n", dt);
debug(0,0)("statAvgDump: ct=%f\n", ct);
#define XAVG(X) (double) (f->X - l->X) / dt
    storeBuffer(sentry);
    storeAppendPrintf(sentry, "client_http.requests = %f/sec\n",
	XAVG(client_http.requests));
    storeAppendPrintf(sentry, "client_http.hits = %f/sec\n",
	XAVG(client_http.hits));
    storeAppendPrintf(sentry, "client_http.errors = %f/sec\n",
	XAVG(client_http.errors));
    storeAppendPrintf(sentry, "client_http.bytes_in = %f/sec\n",
	XAVG(client_http.bytes_in));
    storeAppendPrintf(sentry, "client_http.bytes_out = %f/sec\n",
	XAVG(client_http.bytes_out));
    storeAppendPrintf(sentry, "icp.pkts_sent = %f/sec\n",
	XAVG(icp.pkts_sent));
    storeAppendPrintf(sentry, "icp.pkts_recv = %f/sec\n",
	XAVG(icp.pkts_recv));
    storeAppendPrintf(sentry, "icp.bytes_sent = %f/sec\n",
	XAVG(icp.bytes_sent));
    storeAppendPrintf(sentry, "icp.bytes_recv = %f/sec\n",
	XAVG(icp.bytes_recv));
    storeAppendPrintf(sentry, "unlink.requests = %f/sec\n",
	XAVG(unlink.requests));
    storeAppendPrintf(sentry, "page_faults = %f/sec\n",
	XAVG(page_faults));
    storeAppendPrintf(sentry, "select_loops = %f/sec\n",
	XAVG(select_loops));
    storeAppendPrintf(sentry, "cpu_time = %f seconds\n", ct);
    storeAppendPrintf(sentry, "wall_time = %f seconds\n", dt);
    storeAppendPrintf(sentry, "cpu_usage %f%%\n", 100.0*ct/dt);
    storeBufferFlush(sentry);
}
