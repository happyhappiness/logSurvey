	storeAppendPrintf(sentry, " login=%s", p->login);
    if (p->mcast.ttl > 0)
	storeAppendPrintf(sentry, " ttl=%d", p->mcast.ttl);
    if (p->connect_timeout > 0)
	storeAppendPrintf(sentry, " connect-timeout=%d", (int) p->connect_timeout);
#if USE_CACHE_DIGESTS
    if (p->digest_url)
	storeAppendPrintf(sentry, " digest-url=%s", p->digest_url);
#endif
    if (p->options.allow_miss)
	storeAppendPrintf(sentry, " allow-miss");
    if (p->max_conn > 0)
	storeAppendPrintf(sentry, " max-conn=%d", p->max_conn);
    if (p->options.originserver)
	storeAppendPrintf(sentry, " originserver");
    if (p->domain)
	storeAppendPrintf(sentry, " forceddomain=%s", p->domain);
    storeAppendPrintf(sentry, "\n");
}

