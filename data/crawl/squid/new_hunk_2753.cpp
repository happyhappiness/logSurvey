
    if (p->options.carp)
        storeAppendPrintf(sentry, " carp");
#if USE_AUTH
    if (p->options.userhash)
        storeAppendPrintf(sentry, " userhash");

    if (p->options.userhash)
        storeAppendPrintf(sentry, " sourcehash");
#endif
    if (p->options.weighted_roundrobin)
        storeAppendPrintf(sentry, " weighted-round-robin");

