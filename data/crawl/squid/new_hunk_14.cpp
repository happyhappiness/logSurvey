        return;
    }

    storeAppendPrintf(sentry, " %-32.32s %c%c %6d %6d %2d(%2d)",
                      hashKeyStr(&i->hash),
                      i->flags.fromhosts ? 'H' : ' ',
                      i->flags.negcached ? 'N' : ' ',
                      (int) (squid_curtime - i->lastref),
                      (int) ((i->flags.fromhosts ? -1 : i->expires - squid_curtime)),
                      static_cast<int>(i->addrs.size()),
                      static_cast<int>(i->addrs.badCount()));

    /** \par
     * Negative-cached entries have no IPs listed. */
