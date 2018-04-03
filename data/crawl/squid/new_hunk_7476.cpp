	xfree(h);
    }
    xfree(L2);
    hashFreeMemory(addr_table);
    hashFreeMemory(host_table);
#endif
}

int
netdbHops(struct in_addr addr)
{
#if USE_ICMP
    netdbEntry *n = netdbLookupAddr(addr);
    if (n && n->pings_recv) {
	n->last_use_time = squid_curtime;
	return (int) (n->hops + 0.5);
    }
#endif
    return 256;
}

void
netdbDump(StoreEntry * sentry)
{
#if USE_ICMP
    netdbEntry *n;
    netdbEntry **list;
    struct _net_db_name *x;
    int k;
    int i;
    storeAppendPrintf(sentry, "{Network DB Statistics:\n"); */ } */
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
	storeAppendPrintf(sentry, "{%-16.16s %4d/%4d %7.1f %5.1f", /* } */
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
#endif
}
