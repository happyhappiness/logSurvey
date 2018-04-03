static void
dump_peer(StoreEntry * entry, const char *name, peer * p)
{
    while (p != NULL) {
	storeAppendPrintf(entry, "%s %s %s %d %d",
	    name,
	    p->host,
	    neighborTypeStr(p),
	    p->http_port,
	    p->icp_port);
	if (EBIT_TEST(p->options, NEIGHBOR_PROXY_ONLY))
	    storeAppendPrintf(entry, " proxy-only");
	if (EBIT_TEST(p->options, NEIGHBOR_NO_QUERY))
	    storeAppendPrintf(entry, " no-query");
	if (EBIT_TEST(p->options, NEIGHBOR_DEFAULT_PARENT))
	    storeAppendPrintf(entry, " default");
	if (EBIT_TEST(p->options, NEIGHBOR_ROUNDROBIN))
	    storeAppendPrintf(entry, " round-robin");
	if (EBIT_TEST(p->options, NEIGHBOR_MCAST_RESPONDER))
	    storeAppendPrintf(entry, " multicast-responder");
	if (EBIT_TEST(p->options, NEIGHBOR_CLOSEST_ONLY))
	    storeAppendPrintf(entry, " closest-only");
	if (p->mcast.ttl > 0)
	    storeAppendPrintf(entry, " ttl=%d", p->mcast.ttl);
	storeAppendPrintf(entry, "\n");
	p = p->next;
    }
}

static void
