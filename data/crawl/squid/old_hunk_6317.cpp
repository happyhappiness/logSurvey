    if (EBIT_TEST(p->options, NEIGHBOR_HTCP))
	storeAppendPrintf(sentry, " htcp");
#endif
    if (p->mcast.ttl > 0)
	storeAppendPrintf(sentry, " ttl=%d", p->mcast.ttl);
    storeAppendPrintf(sentry, "\n");