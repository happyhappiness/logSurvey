        ipa.GetInAddr(_SQUID_RES_NSADDR_LIST[_SQUID_RES_NSADDR_COUNT++].sin_addr);
    } else if ( ipa.IsIPv6() ) {
#if USE_IPV6 && defined(_SQUID_RES_NSADDR6_LIST)
         /* because things NEVER seem to resolve in tests without _res.nscount being a total. */
        if (_SQUID_RES_NSADDR_COUNT == MAXNS) {
            fprintf(stderr, "Too many -s options, only %d are allowed\n", MAXNS);
            return;
