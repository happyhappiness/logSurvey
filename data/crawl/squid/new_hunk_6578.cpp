	storeAppendPrintf(sentry, " multicast-responder");
    if (EBIT_TEST(p->options, NEIGHBOR_CLOSEST_ONLY))
	storeAppendPrintf(sentry, " closest-only");
    if (EBIT_TEST(p->options, NEIGHBOR_HTCP))
	storeAppendPrintf(sentry, " htcp");
    if (p->mcast.ttl > 0)
	storeAppendPrintf(sentry, " ttl=%d", p->mcast.ttl);
    storeAppendPrintf(sentry, "\n");
