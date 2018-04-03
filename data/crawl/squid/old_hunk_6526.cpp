	storeAppendPrintf(sentry, " proxy-only");
    if (EBIT_TEST(p->options, NEIGHBOR_NO_QUERY))
	storeAppendPrintf(sentry, " no-query");
    if (EBIT_TEST(p->options, NEIGHBOR_DEFAULT_PARENT))
	storeAppendPrintf(sentry, " default");
    if (EBIT_TEST(p->options, NEIGHBOR_ROUNDROBIN))
