
    /** \par
     * Cached entries have IPs listed with a BNF of:   ip-address '-' ('OK'|'BAD') */
    bool firstLine = true;
    for (const auto &addr: i->addrs.raw()) {
        /* Display tidy-up: IPv6 are so big make the list vertical */
        const char *indent = firstLine ? "" : "                                                         ";
        storeAppendPrintf(sentry, "%s %45.45s-%3s\n",
                          indent,
                          addr.ip.toStr(buf, MAX_IPSTRLEN),
                          addr.bad() ? "BAD" : "OK ");
        firstLine = false;
    }
}

