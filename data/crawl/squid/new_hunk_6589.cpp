    dump_peers(sentry, non_peers);
}

void
dump_peer_options(StoreEntry * sentry, peer * p)
{
    if (EBIT_TEST(p->options, NEIGHBOR_PROXY_ONLY))
	storeAppendPrintf(sentry, " proxy-only");
    if (EBIT_TEST(p->options, NEIGHBOR_NO_QUERY))
	storeAppendPrintf(sentry, " no-query");
    if (EBIT_TEST(p->options, NEIGHBOR_DEFAULT_PARENT))
	storeAppendPrintf(sentry, " default");
    if (EBIT_TEST(p->options, NEIGHBOR_ROUNDROBIN))
	storeAppendPrintf(sentry, " round-robin");
    if (EBIT_TEST(p->options, NEIGHBOR_MCAST_RESPONDER))
	storeAppendPrintf(sentry, " multicast-responder");
    if (EBIT_TEST(p->options, NEIGHBOR_CLOSEST_ONLY))
	storeAppendPrintf(sentry, " closest-only");
    if (p->mcast.ttl > 0)
	storeAppendPrintf(sentry, " ttl=%d", p->mcast.ttl);
    storeAppendPrintf(sentry, "\n");
}

static void
dump_peers(StoreEntry * sentry, peer * peers)
{
