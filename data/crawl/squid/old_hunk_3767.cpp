    if (p->connect_timeout > 0)
        storeAppendPrintf(sentry, " connect-timeout=%d", (int) p->connect_timeout);

#if USE_CACHE_DIGESTS

    if (p->digest_url)
