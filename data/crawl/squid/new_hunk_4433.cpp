
    for (k = 0; k < i; k++) {
        n = *(list + k);
        storeAppendPrintf(sentry, "%-46.46s %4d/%4d %7.1f %5.1f", /* Max between 16 (IPv4) or 46 (IPv6)   */
                          n->network,
                          n->pings_recv,
                          n->pings_sent,
