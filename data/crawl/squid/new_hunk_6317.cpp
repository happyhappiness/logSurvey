    if (EBIT_TEST(p->options, NEIGHBOR_HTCP))
	storeAppendPrintf(sentry, " htcp");
#endif
    if (EBIT_TEST(p->options, NEIGHBOR_NO_NETDB_EXCHANGE))
	storeAppendPrintf(sentry, " no-netdb-exchange");
    if (p->mcast.ttl > 0)
	storeAppendPrintf(sentry, " ttl=%d", p->mcast.ttl);
    storeAppendPrintf(sentry, "\n");