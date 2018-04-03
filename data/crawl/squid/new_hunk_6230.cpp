    if (p->options.no_delay)
	storeAppendPrintf(sentry, " no-delay");
#endif
    if (p->login)
	storeAppendPrintf(sentry, " login=%s", p->login);
    if (p->mcast.ttl > 0)
	storeAppendPrintf(sentry, " ttl=%d", p->mcast.ttl);
    storeAppendPrintf(sentry, "\n");
