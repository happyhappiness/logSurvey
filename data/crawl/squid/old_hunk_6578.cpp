	storeAppendPrintf(sentry, " multicast-responder");
    if (EBIT_TEST(p->options, NEIGHBOR_CLOSEST_ONLY))
	storeAppendPrintf(sentry, " closest-only");
    if (p->mcast.ttl > 0)
	storeAppendPrintf(sentry, " ttl=%d", p->mcast.ttl);
    storeAppendPrintf(sentry, "\n");
