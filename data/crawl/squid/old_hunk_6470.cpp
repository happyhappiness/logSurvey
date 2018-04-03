static void
statDigestBlob(StoreEntry * sentry)
{
#if SQUID_PEER_DIGEST
    StatCounters *f = &CountHist[0];
    StatCounters *l = &CountHist[5];
    double x;

    storeAppendPrintf(sentry, "client_http.all_svc_time histogram:\n");
    statHistDump(&f->client_http.all_svc_time, sentry, NULL);
    storeAppendPrintf(sentry, "client_http.miss_svc_time histogram:\n");
    statHistDump(&f->client_http.miss_svc_time, sentry, NULL);
    storeAppendPrintf(sentry, "client_http.nm_svc_time histogram:\n");
    statHistDump(&f->client_http.nm_svc_time, sentry, NULL);
    storeAppendPrintf(sentry, "client_http.hit_svc_time histogram:\n");
    statHistDump(&f->client_http.hit_svc_time, sentry, NULL);
    storeAppendPrintf(sentry, "\nicp.query_svc_time histogram:\n");
    statHistDump(&f->icp.query_svc_time, sentry, NULL);
    storeAppendPrintf(sentry, "\nicp.reply_svc_time histogram:\n");
    statHistDump(&f->icp.reply_svc_time, sentry, NULL);
    storeAppendPrintf(sentry, "\nicp.client_svc_time histogram:\n");
    statHistDump(&f->icp.client_svc_time, sentry, NULL);
    storeAppendPrintf(sentry, "\ncd.client_svc_time histogram:\n");
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
	x / 1000.0);
    x = statHistDeltaMedian(&l->icp.client_svc_time,
	&f->icp.client_svc_time);
    storeAppendPrintf(sentry, "icp.client_median_svc_time = %f seconds\n",
	x / 1000.0);

    storeAppendPrintf(sentry, "\nTraffic:\n");
    storeAppendPrintf(sentry, "icp.times_used = %d\n",
	f->icp.times_used);
    storeAppendPrintf(sentry, "icp.pkts_sent = %d\n",
	f->icp.pkts_sent);
    storeAppendPrintf(sentry, "icp.pkts_recv = %d\n",
	f->icp.pkts_recv);
    storeAppendPrintf(sentry, "icp.replies_queued = %d\n",
	f->icp.replies_queued);
    storeAppendPrintf(sentry, "icp.kbytes_sent = %d\n",
	(int) f->icp.kbytes_sent.kb);
    storeAppendPrintf(sentry, "icp.kbytes_recv = %d\n",
	(int) f->icp.kbytes_recv.kb);
    storeAppendPrintf(sentry, "cd.times_used = %d\n",
	f->cd.times_used);
    storeAppendPrintf(sentry, "cd.msgs_sent = %d\n",
	f->cd.msgs_sent);
    storeAppendPrintf(sentry, "cd.msgs_recv = %d\n",
	f->cd.msgs_recv);
    storeAppendPrintf(sentry, "cd.kbytes_sent = %d\n",
	(int) f->cd.kbytes_sent.kb);
    storeAppendPrintf(sentry, "cd.kbytes_recv = %d\n",
	(int) f->cd.kbytes_recv.kb);
    storeAppendPrintf(sentry, "cd.peer_memory = %d\n",
	(int) f->cd.memory.kb);
    storeAppendPrintf(sentry, "cd.store_memory = %d\n",
	(int) (store_digest ? store_digest->mask_size/1024 : 0));
    storeAppendPrintf(sentry, "\n");
#endif
    statPeerSelect(sentry);
    storeAppendPrintf(sentry, "\n");
    storeDigestReport(sentry);
}

static void
statCounters(StoreEntry * e)
{
    statCountersDump(e);
}

static void
statAvg5min(StoreEntry * e)
{
