        storeAppendPrintf(e, " disable-pmtu-discovery=%s", pmtu);
    }

    if (s->s.IsAnyAddr() && !s->s.IsIPv6())
        storeAppendPrintf(e, " ipv4");

    if (s->tcp_keepalive.enabled) {
