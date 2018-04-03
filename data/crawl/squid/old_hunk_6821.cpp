{
    dlink_node *m;
    assert(ip_table != NULL);
    storeAppendPrintf(sentry, "{IP Cache Statistics:\n");
    storeAppendPrintf(sentry, "{IPcache Entries: %d}\n",
	meta_data.ipcache_count);
    storeAppendPrintf(sentry, "{IPcache Requests: %d}\n",
	IpcacheStats.requests);
    storeAppendPrintf(sentry, "{IPcache Hits: %d}\n",
	IpcacheStats.hits);
    storeAppendPrintf(sentry, "{IPcache Pending Hits: %d}\n",
	IpcacheStats.pending_hits);
    storeAppendPrintf(sentry, "{IPcache Negative Hits: %d}\n",
	IpcacheStats.negative_hits);
    storeAppendPrintf(sentry, "{IPcache Misses: %d}\n",
	IpcacheStats.misses);
    storeAppendPrintf(sentry, "{Blocking calls to gethostbyname(): %d}\n",
	IpcacheStats.ghbn_calls);
    storeAppendPrintf(sentry, "{Attempts to release locked entries: %d}\n",
	IpcacheStats.release_locked);
    storeAppendPrintf(sentry, "{dnsserver avg service time: %d msec}\n",
	IpcacheStats.avg_svc_time);
    storeAppendPrintf(sentry, "{pending queue length: %d}\n", queue_length);
    storeAppendPrintf(sentry, "}\n\n");
    storeAppendPrintf(sentry, "{IP Cache Contents:\n\n");
    storeAppendPrintf(sentry, " {%-29.29s %5s %6s %6s %1s}\n",
	"Hostname",
	"Flags",
	"lstref",
	"TTL",
	"N");
    for (m = lru_list.head; m; m = m->next)
	ipcacheStatPrint(m->data, sentry);
    storeAppendPrintf(sentry, close_bracket);
}

static void
