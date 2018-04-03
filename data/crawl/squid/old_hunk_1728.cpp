        /* Display tidy-up: IPv6 are so big make the list vertical */
        if (k == 0)
            storeAppendPrintf(sentry, " %45.45s-%3s\n",
                              i->addrs.in_addrs[k].NtoA(buf,MAX_IPSTRLEN),
                              i->addrs.bad_mask[k] ? "BAD" : "OK ");
        else
            storeAppendPrintf(sentry, "%s %45.45s-%3s\n",
                              "                                                         ", /* blank-space indenting IP list */
                              i->addrs.in_addrs[k].NtoA(buf,MAX_IPSTRLEN),
                              i->addrs.bad_mask[k] ? "BAD" : "OK ");
    }
}
