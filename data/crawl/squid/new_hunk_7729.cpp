}


static int ipcache_dnsHandleRead(fd, dnsData)
     int fd;
     dnsserver_t *dnsData;
{
    int char_scanned;
    int len;
    int svc_time;
    int n;
    ipcache_entry *i = NULL;

    len = read(fd,
	dnsData->ip_inbuf + dnsData->offset,
	dnsData->size - dnsData->offset);
    debug(14, 5, "ipcache_dnsHandleRead: Result from DNS ID %d (%d bytes)\n",
	dnsData->id, len);
    if (len <= 0) {
	debug(14, dnsData->flags & DNS_FLAG_CLOSING ? 5 : 1,
	    "FD %d: Connection from DNSSERVER #%d is closed, disabling\n",
	    fd, dnsData->id);
	dnsData->flags = 0;
	comm_set_select_handler(fd,
	    COMM_SELECT_WRITE,
	    NULL,
	    NULL);
	comm_close(fd);
	return 0;
    }
    n = ++IpcacheStats.dnsserver_replies;
    dnsData->offset += len;
    dnsData->ip_inbuf[dnsData->offset] = '\0';

    if (strstr(dnsData->ip_inbuf, "$end\n")) {
	/* end of record found */
	svc_time = tvSubMsec(dnsData->dispatch_time, current_time);
	if (n > IPCACHE_AV_FACTOR)
	    n = IPCACHE_AV_FACTOR;
	IpcacheStats.avg_svc_time
	    = (IpcacheStats.avg_svc_time * (n - 1) + svc_time) / n;
	char_scanned = ipcache_parsebuffer(dnsData->ip_inbuf,
	    dnsData->offset,
	    dnsData);
	if (char_scanned > 0) {
	    /* update buffer */
	    xmemcpy(dnsData->ip_inbuf,
		dnsData->ip_inbuf + char_scanned,
		dnsData->offset - char_scanned);
	    dnsData->offset -= char_scanned;
	    dnsData->ip_inbuf[dnsData->offset] = '\0';
	}
    }
    if (dnsData->offset == 0) {
	dnsData->ip_entry = NULL;
	dnsData->flags &= ~DNS_FLAG_BUSY;
    }
    /* reschedule */
    comm_set_select_handler(dnsData->inpipe,
	COMM_SELECT_READ,
	(PF) ipcache_dnsHandleRead,
	dnsData);
    while ((dnsData = dnsGetFirstAvailable()) && (i = dnsDequeue()))
	dnsDispatch(dnsData, i);
    return 0;
}

static void ipcacheAddPending(i, fd, handler, handlerData)
     ipcache_entry *i;
     int fd;
     IPH handler;
     void *handlerData;
{
    struct _ip_pending *pending = xcalloc(1, sizeof(struct _ip_pending));
    struct _ip_pending **I = NULL;

    pending->fd = fd;
    pending->handler = handler;
    pending->handlerData = handlerData;

    for (I = &(i->pending_head); *I; I = &((*I)->next));
    *I = pending;
}

int ipcache_nbgethostbyname(name, fd, handler, handlerData)
     char *name;
     int fd;
     IPH handler;
     void *handlerData;
{
    ipcache_entry *i = NULL;
    dnsserver_t *dnsData = NULL;

    if (!handler)
	fatal_dump("ipcache_nbgethostbyname: NULL handler");

    debug(14, 4, "ipcache_nbgethostbyname: FD %d: Name '%s'.\n", fd, name);
    IpcacheStats.requests++;

    if (name == NULL || name[0] == '\0') {
	debug(14, 4, "ipcache_nbgethostbyname: Invalid name!\n");
	ipcache_call_pending_badname(fd, handler, handlerData);
	return 0;
    }
    if ((i = ipcache_get(name))) {
	if (ipcacheExpiredEntry(i)) {
	    ipcache_release(i);
	    i = NULL;
	}
    }
    if (i == NULL) {
	/* MISS: No entry, create the new one */
	debug(14, 5, "ipcache_nbgethostbyname: MISS for '%s'\n", name);
	IpcacheStats.misses++;
	i = ipcache_create();
	i->name = xstrdup(name);
	i->status = IP_PENDING;
	ipcacheAddPending(i, fd, handler, handlerData);
	ipcache_add_to_hash(i);
    } else if (i->status == IP_CACHED || i->status == IP_NEGATIVE_CACHED) {
	/* HIT */
	debug(14, 4, "ipcache_nbgethostbyname: HIT for '%s'\n", name);
	if (i->status == IP_NEGATIVE_CACHED)
	    IpcacheStats.negative_hits++;
	else
	    IpcacheStats.hits++;
	ipcacheAddPending(i, fd, handler, handlerData);
	ipcache_call_pending(i);
	return 0;
    } else if (i->status == IP_PENDING || i->status == IP_DISPATCHED) {
	debug(14, 4, "ipcache_nbgethostbyname: PENDING for '%s'\n", name);
	IpcacheStats.pending_hits++;
	ipcacheAddPending(i, fd, handler, handlerData);
	return 0;
    } else {
	fatal_dump("ipcache_nbgethostbyname: BAD ipcache_entry status");
    }

    /* for HIT, PENDING, DISPATCHED we've returned.  For MISS we continue */

    if ((dnsData = dnsGetFirstAvailable()))
	dnsDispatch(dnsData, i);
    else
	dnsEnqueue(i);
    return 0;
}

static void dnsEnqueue(i)
     ipcache_entry *i;
{
    struct dnsQueueData *new = xcalloc(1, sizeof(struct dnsQueueData));
    new->ip_entry = i;
    *dnsQueueTailP = new;
    dnsQueueTailP = &new->next;
}

static ipcache_entry *dnsDequeue()
{
    struct dnsQueueData *old = NULL;
    ipcache_entry *i = NULL;
    if (dnsQueueHead) {
	i = dnsQueueHead->ip_entry;
	old = dnsQueueHead;
	dnsQueueHead = dnsQueueHead->next;
	if (dnsQueueHead == NULL)
	    dnsQueueTailP = &dnsQueueHead;
	safe_free(old);
    }
#ifdef SANITY_CHECK
    if (i == NULL) {
	for (i = ipcache_GetFirst(); i; i = ipcache_GetNext()) {
	    if (i->status == IP_PENDING) {	/* This can't happen */
		debug(14, 0, "IP Cache inconsistency: %s still pending\n",
		    i->name);
	    }
	}
	i = NULL;
    }
#endif
    return i;
}

static dnsserver_t *dnsGetFirstAvailable()
{
    int k;
    dnsserver_t *dns = NULL;
    for (k = 0; k < NDnsServersAlloc; k++) {
	dns = *(dns_child_table + k);
	if (!(dns->flags & DNS_FLAG_BUSY))
	    return dns;
    }
    return NULL;
}

static void dnsDispatch(dns, i)
     dnsserver_t *dns;
     ipcache_entry *i;
{
    char *buf = NULL;
    if (!ipcacheHasPending(i)) {
	debug(14, 0, "dnsDispatch: skipping '%s' because no handler.\n",
	    i->name);
	i->status = IP_NEGATIVE_CACHED;
	ipcache_release(i);
	return;
    }
    i->status = IP_DISPATCHED;
    buf = xcalloc(1, 256);
    sprintf(buf, "%1.254s\n", i->name);
    dns->flags |= DNS_FLAG_BUSY;
    dns->ip_entry = i;
    comm_write(dns->outpipe,
	buf,
	strlen(buf),
	0,			/* timeout */
	NULL,			/* Handler */
	NULL);			/* Handler-data */
    debug(14, 5, "dnsDispatch: Request sent to DNS server #%d.\n",
	dns->id);
    dns->dispatch_time = current_time;
    IpcacheStats.dnsserver_requests++;
    IpcacheStats.dnsserver_hist[dns->id - 1]++;
}


void ipcacheOpenServers()
{
    int N = getDnsChildren();
    char *prg = getDnsProgram();
    int k;
    int dnssocket;
    static char fd_note_buf[FD_ASCII_NOTE_SZ];

    /* free old structures if present */
    if (dns_child_table) {
	for (k = 0; k < NDnsServersAlloc; k++) {
	    safe_free(dns_child_table[k]->ip_inbuf);
	    safe_free(dns_child_table[k]);
	}
	safe_free(dns_child_table);
    }
    dns_child_table = xcalloc(N, sizeof(dnsserver_t *));
    NDnsServersAlloc = N;
    debug(14, 1, "ipcacheOpenServers: Starting %d 'dns_server' processes\n", N);
    for (k = 0; k < N; k++) {
	dns_child_table[k] = xcalloc(1, sizeof(dnsserver_t));
	if ((dnssocket = ipcache_create_dnsserver(prg)) < 0) {
	    debug(14, 1, "ipcacheOpenServers: WARNING: Cannot run 'dnsserver' process.\n");
	    debug(14, 1, "              Fallling back to the blocking version.\n");
	    dns_child_table[k]->flags &= ~DNS_FLAG_ALIVE;
	} else {
	    debug(14, 4, "ipcacheOpenServers: FD %d connected to %s #%d.\n",
		dnssocket, prg, k + 1);
	    dns_child_table[k]->flags |= DNS_FLAG_ALIVE;
	    dns_child_table[k]->id = k + 1;
	    dns_child_table[k]->inpipe = dnssocket;
	    dns_child_table[k]->outpipe = dnssocket;
	    dns_child_table[k]->lastcall = squid_curtime;
	    dns_child_table[k]->size = IP_INBUF_SZ - 1;		/* spare one for \0 */
	    dns_child_table[k]->offset = 0;
	    dns_child_table[k]->ip_inbuf = xcalloc(IP_INBUF_SZ, 1);

	    /* update fd_stat */

	    sprintf(fd_note_buf, "%s #%d", prg, dns_child_table[k]->id);
	    fd_note(dns_child_table[k]->inpipe, fd_note_buf);
	    commSetNonBlocking(dns_child_table[k]->inpipe);

	    /* clear unused handlers */
	    comm_set_select_handler(dns_child_table[k]->inpipe,
		COMM_SELECT_WRITE,
		0,
		0);
	    comm_set_select_handler(dns_child_table[k]->outpipe,
		COMM_SELECT_READ,
		0,
		0);

	    /* set handler for incoming result */
	    comm_set_select_handler(dns_child_table[k]->inpipe,
		COMM_SELECT_READ,
		(PF) ipcache_dnsHandleRead,
		(void *) dns_child_table[k]);
	    debug(14, 3, "ipcacheOpenServers: 'dns_server' %d started\n", k);
	}
    }
}
