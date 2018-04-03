    if (p->options.roundrobin)
        storeAppendPrintf(sentry, " round-robin");

    if (p->options.weighted_roundrobin)
        storeAppendPrintf(sentry, " weighted-round-robin");

