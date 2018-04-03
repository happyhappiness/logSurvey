	IpcacheStats.avg_svc_time);
    storeAppendPrintf(sentry, "}\n\n");
    storeAppendPrintf(sentry, "{IP Cache Contents:\n\n");
    storeAppendPrintf(sentry, " {%-29.29s %5s %6s %6s %1s}\n",
	"Hostname",
	"Flags",
	"lstref",
	"TTL",
	"N");
    list = xcalloc(meta_data.ipcache_count, sizeof(ipcache_entry *));
    N = 0;
    for (i = ipcache_GetFirst(); i; i = ipcache_GetNext()) {
	*(list + N) = i;
	if (++N > meta_data.ipcache_count)
	    fatal_dump("stat_ipcache_get: meta_data.ipcache_count mismatch");
    }
    qsort((char *) list,
	N,
	sizeof(ipcache_entry *),
	(QS) ipcache_reverseLastRef);
    for (k = 0; k < N; k++)
	ipcacheStatPrint(*(list + k), sentry);
    storeAppendPrintf(sentry, close_bracket);
}

