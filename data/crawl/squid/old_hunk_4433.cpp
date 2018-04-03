
    for (k = 0; k < i; k++) {
        n = *(list + k);
        storeAppendPrintf(sentry, "%-16.16s %4d/%4d %7.1f %5.1f",
                          n->network,
                          n->pings_recv,
                          n->pings_sent,
