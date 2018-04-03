	handler(addrs, handlerData);
	return;
    }
    if ((i = ipcache_get(name))) {
	if (ipcacheExpiredEntry(i)) {
	    ipcache_release(i);
	    i = NULL;
	}
    }
    if (i == NULL) {
	/* MISS: No entry, create the new one */
	debug(14, 5) ("ipcache_nbgethostbyname: MISS for '%s'\n", name);
	IpcacheStats.misses++;
	i = ipcacheAddNew(name, NULL, IP_PENDING);
	ipcacheAddPending(i, handler, handlerData);
	i->request_time = current_time;
    } else if (i->status == IP_CACHED || i->status == IP_NEGATIVE_CACHED) {
	/* HIT */
	debug(14, 4) ("ipcache_nbgethostbyname: HIT for '%s'\n", name);
	if (i->status == IP_NEGATIVE_CACHED)
	    IpcacheStats.negative_hits++;
	else
	    IpcacheStats.hits++;
	ipcacheAddPending(i, handler, handlerData);
	ipcache_call_pending(i);
	return;
    } else if (i->status == IP_PENDING || i->status == IP_DISPATCHED) {
	debug(14, 4) ("ipcache_nbgethostbyname: PENDING for '%s'\n", name);
	IpcacheStats.pending_hits++;
	ipcacheAddPending(i, handler, handlerData);
	if (squid_curtime - i->expires > 600) {
	    debug(14, 0) ("ipcache_nbgethostbyname: '%s' PENDING for %d seconds, aborting\n", name, (int) (squid_curtime + Config.negativeDnsTtl - i->expires));
	    ipcacheChangeKey(i);
	    ipcache_call_pending(i);
	}
	return;
    } else {
	fatal_dump("ipcache_nbgethostbyname: BAD ipcache_entry status");
    }
    /* for HIT, PENDING, DISPATCHED we've returned.  For MISS we submit */
    c = xcalloc(1, sizeof(*c));
    c->data = i;
    cbdataAdd(c, cbdataXfree, 0);
    i->status = IP_DISPATCHED;
    ipcacheLockEntry(i);
#if USE_DNSSERVERS
    dnsSubmit(i->name, ipcacheHandleReply, c);
#else
