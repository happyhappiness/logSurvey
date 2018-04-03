    if (p->options.no_delay)
	storeAppendPrintf(sentry, " no-delay");
#endif
    if (p->mcast.ttl > 0)
	storeAppendPrintf(sentry, " ttl=%d", p->mcast.ttl);
    storeAppendPrintf(sentry, "\n");
