    qsort((char *) list,
	N,
	sizeof(ipcache_entry *),
	ipcache_reverseLastRef);
    for (k = 0; k < N; k++)
	ipcacheStatPrint(*(list + k), sentry);
    storeAppendPrintf(sentry, close_bracket);
    xfree(list);
}

static void
dummy_handler(const ipcache_addrs * addrsnotused, void *datanotused)
{
    return;
}
