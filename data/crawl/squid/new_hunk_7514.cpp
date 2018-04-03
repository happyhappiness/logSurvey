    N = 0;
    for (i = ipcache_GetFirst(); i; i = ipcache_GetNext()) {
	*(list + N) = i;
	if (++N > meta_data.ipcache_count) {
	    debug_trap("stat_ipcache_get: meta_data.ipcache_count mismatch");
	    break;
	}
    }
    qsort((char *) list,
	N,
