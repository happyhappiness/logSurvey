        storeAppendPrintf(e, " disable-pmtu-discovery=%s", pmtu);
    }

    if (s->s.isAnyAddr() && !s->s.isIPv6())
        storeAppendPrintf(e, " ipv4");

    if (s->tcp_keepalive.enabled) {
