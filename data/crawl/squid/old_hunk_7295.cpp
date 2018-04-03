    qsort((char *) list,
	N,
	sizeof(ipcache_entry *),
	(QS) ipcache_reverseLastRef);
    for (k = 0; k < N; k++)
	ipcacheStatPrint(*(list + k), sentry);
    storeAppendPrintf(sentry, close_bracket);
