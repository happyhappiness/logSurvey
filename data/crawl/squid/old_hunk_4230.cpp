        storeAppendPrintf(sentry, " closest-only");

#if USE_HTCP

    if (p->options.htcp)
        storeAppendPrintf(sentry, " htcp");

#endif

    if (p->options.no_netdb_exchange)
