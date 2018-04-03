     char *name;
     int fd;
{
    ipcache_entry *i = NULL;
    struct _ip_pending *p = NULL;
    int n = 0;

    debug(14, 3, "ipcache_unregister: FD %d, name '%s'\n", fd, name);
    if ((i = ipcache_get(name)) == NULL)
	return 0;
    if (i->status == IP_PENDING || i->status == IP_DISPATCHED) {
	for (p = i->pending_head; p; p = p->next) {
	    if (p->fd == fd && p->handler != NULL) {
		p->handler = NULL;
		p->fd = -1;
		n++;
	    }
	}
    }
    debug(14, 3, "ipcache_unregister: unregistered %d handlers\n", n);
    return n;
}

struct hostent *ipcache_gethostbyname(name, flags)
     char *name;
     int flags;
{
    ipcache_entry *i = NULL;
    struct hostent *hp = NULL;
    unsigned int ip;

    if (!name)
	fatal_dump("ipcache_gethostbyname: NULL name");
    IpcacheStats.requests++;
    if ((i = ipcache_get(name))) {
	if (i->status == IP_PENDING || i->status == IP_DISPATCHED) {
	    IpcacheStats.pending_hits++;
	    return NULL;
	} else if (i->status == IP_NEGATIVE_CACHED) {
	    IpcacheStats.negative_hits++;
	    dns_error_message = i->error_message;
	    return NULL;
	} else {
	    IpcacheStats.hits++;
	    i->lastref = squid_curtime;
	    return &i->entry;
	}
    }
    IpcacheStats.misses++;
    /* check if it's already a IP address in text form. */
    if ((ip = inet_addr(name)) != INADDR_NONE) {
	*((u_num32 *) (void *) static_result->h_addr_list[0]) = ip;
	strncpy(static_result->h_name, name, MAX_HOST_NAME);
	return static_result;
    }
    if (flags & IP_BLOCKING_LOOKUP) {
	IpcacheStats.ghbn_calls++;
	hp = gethostbyname(name);
	if (hp && hp->h_name && (hp->h_name[0] != '\0') && ip_table) {
	    /* good address, cached */
	    ipcache_add(name, ipcache_create(), hp, 1);
	    i = ipcache_get(name);
	    return &i->entry;
	}
	/* bad address, negative cached */
	if (ip_table)
	    ipcache_add(name, ipcache_create(), hp, 0);
	return NULL;
    }
    if (flags & IP_LOOKUP_IF_MISS)
	ipcache_nbgethostbyname(name, -1, dummy_handler, NULL);
    return NULL;
}


/* process objects list */
void stat_ipcache_get(sentry)
     StoreEntry *sentry;
{
    ipcache_entry *i = NULL;
    int k;
    int ttl;

    if (!ip_table)
	return;

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
    storeAppendPrintf(sentry, "{dnsserver requests: %d}\n",
	IpcacheStats.dnsserver_requests);
    storeAppendPrintf(sentry, "{dnsserver replies: %d}\n",
	IpcacheStats.dnsserver_replies);
    storeAppendPrintf(sentry, "{dnsserver avg service time: %d msec}\n",
	IpcacheStats.avg_svc_time);
    storeAppendPrintf(sentry, "{number of dnsservers: %d}\n",
	getDnsChildren());
    storeAppendPrintf(sentry, "{dnsservers use histogram:}\n");
    for (k = 0; k < getDnsChildren(); k++) {
	storeAppendPrintf(sentry, "{    dnsserver #%d: %d}\n",
	    k + 1,
	    IpcacheStats.dnsserver_hist[k]);
    }
    storeAppendPrintf(sentry, "}\n\n");
    storeAppendPrintf(sentry, "{IP Cache Contents:\n\n");

    for (i = ipcache_GetFirst(); i; i = ipcache_GetNext()) {
	if (i->status == IP_PENDING || i->status == IP_DISPATCHED)
	    ttl = 0;
	else
	    ttl = (i->ttl - squid_curtime + i->lastref);
	storeAppendPrintf(sentry, " {%-32.32s %c%c %6d %d",
	    i->name,
	    ipcache_status_char[i->status],
	    i->lock ? 'L' : ' ',
	    ttl,
	    i->addr_count);
	for (k = 0; k < (int) i->addr_count; k++) {
	    struct in_addr addr;
	    xmemcpy(&addr, i->entry.h_addr_list[k], i->entry.h_length);
	    storeAppendPrintf(sentry, " %15s", inet_ntoa(addr));
	}
	for (k = 0; k < (int) i->alias_count; k++) {
	    storeAppendPrintf(sentry, " %s", i->entry.h_aliases[k]);
	}
	if (i->entry.h_name && strncmp(i->name, i->entry.h_name, MAX_LINELEN)) {
	    storeAppendPrintf(sentry, " %s", i->entry.h_name);
	}
	storeAppendPrintf(sentry, close_bracket);
    }
    storeAppendPrintf(sentry, close_bracket);
}

void ipcacheShutdownServers()
{
    dnsserver_t *dnsData = NULL;
    int k;
    static char *shutdown = "$shutdown\n";

    debug(14, 3, "ipcacheShutdownServers:\n");

    for (k = 0; k < getDnsChildren(); k++) {
	dnsData = *(dns_child_table + k);
	if (!(dnsData->flags & DNS_FLAG_ALIVE))
	    continue;
	if (dnsData->flags & DNS_FLAG_BUSY)
	    continue;
	if (dnsData->flags & DNS_FLAG_CLOSING)
	    continue;
	debug(14, 3, "ipcacheShutdownServers: sending '$shutdown' to dnsserver #%d\n", dnsData->id);
	debug(14, 3, "ipcacheShutdownServers: --> FD %d\n", dnsData->outpipe);
	comm_write(dnsData->outpipe,
	    xstrdup(shutdown),
	    strlen(shutdown),
	    0,			/* timeout */
	    NULL,		/* Handler */
	    NULL);		/* Handler-data */
	dnsData->flags |= DNS_FLAG_CLOSING;
    }
}

static int dummy_handler(u1, u2, u3)
     int u1;
     struct hostent *u2;
     void *u3;
{
    return 0;
}

void ipcacheLockEntry(name)
     char *name;
{
    ipcache_entry *i;
    if ((i = ipcache_get(name)) == NULL)
	return;
    i->lock++;
}

static int ipcacheHasPending(i)
     ipcache_entry *i;
{
    struct _ip_pending *p = NULL;
    if (i->status != IP_PENDING)
	return 0;
    for (p = i->pending_head; p; p = p->next)
	if (p->handler)
	    return 1;
    return 0;
}
