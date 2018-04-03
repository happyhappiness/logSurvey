	handler(addrs, handlerData);
	return;
    }
    i = ipcache_get(name);
    if (NULL == i) {
	/* miss */
	(void) 0;
    } else if (ipcacheExpiredEntry(i)) {
	/* hit, but expired -- bummer */
	ipcacheRelease(i);
	i = NULL;
    } else {
	/* hit */
	debug(14, 4) ("ipcache_nbgethostbyname: HIT for '%s'\n", name);
	if (i->flags.negcached)
	    IpcacheStats.negative_hits++;
	else
	    IpcacheStats.hits++;
	i->handler = handler;
	i->handlerData = handlerData;
	cbdataLock(handlerData);
	ipcacheCallback(i);
	return;
    }
    debug(14, 5) ("ipcache_nbgethostbyname: MISS for '%s'\n", name);
    IpcacheStats.misses++;
    i = ipcacheCreateEntry(name);
    i->handler = handler;
    i->handlerData = handlerData;
    cbdataLock(handlerData);
    i->request_time = current_time;
    c = xcalloc(1, sizeof(*c));
    c->data = i;
    cbdataAdd(c, cbdataXfree, 0);
#if USE_DNSSERVERS
    dnsSubmit(i->name, ipcacheHandleReply, c);
#else
