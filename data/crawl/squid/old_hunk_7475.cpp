	return 0;
}

void
netdbDump(StoreEntry * sentry)
{
    netdbEntry *n;
    netdbEntry **list;
    struct _net_db_name *x;
    int k;
    int i;
    storeAppendPrintf(sentry, "{Network DB Statistics:\n");
    storeAppendPrintf(sentry, "{%-16.16s %9s %7s %5s %s}\n",
	"Network",
	"recv/sent",
	"RTT",
	"Hops",
	"Hostnames");
    list = xcalloc(meta_data.netdb_addrs, sizeof(netdbEntry *));
    i = 0;
    for (n = netdbGetFirst(addr_table); n; n = netdbGetNext(addr_table))
	*(list + i++) = n;
    qsort((char *) list,
	i,
	sizeof(netdbEntry *),
	(QS) sortByHops);
    for (k = 0; k < i; k++) {
	n = *(list + k);
	storeAppendPrintf(sentry, "{%-16.16s %4d/%4d %7.1f %5.1f",
	    n->network,
	    n->pings_recv,
	    n->pings_sent,
	    n->rtt,
	    n->hops);
	for (x = n->hosts; x; x = x->next)
	    storeAppendPrintf(sentry, " %s", x->name);
	storeAppendPrintf(sentry, close_bracket);
    }
    storeAppendPrintf(sentry, close_bracket);
    xfree(list);
}

int
netdbHops(struct in_addr addr)
{
    netdbEntry *n = netdbLookupAddr(addr);
    if (n && n->pings_recv) {
	n->last_use_time = squid_curtime;
	return (int) (n->hops + 0.5);
    }
    return 256;
}

void
netdbFreeMemory(void)
{
    netdbEntry *n;
    netdbEntry **L1;
    hash_link *h;
    hash_link **L2;
    struct _net_db_name *x;
    int i = 0;
    int j;

    L1 = xcalloc(meta_data.netdb_addrs, sizeof(netdbEntry *));
    n = (netdbEntry *) hash_first(addr_table);
    while (n && i < meta_data.netdb_addrs) {
