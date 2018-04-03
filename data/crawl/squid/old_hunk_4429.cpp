                      (int) i->addrs.count,
                      (int) i->addrs.badcount);

    for (k = 0; k < (int) i->addrs.count; k++) {
        storeAppendPrintf(sentry, " %15s-%3s", inet_ntoa(i->addrs.in_addrs[k]),
                          i->addrs.bad_mask[k] ? "BAD" : "OK ");
    }

    storeAppendPrintf(sentry, "\n");
}

/* process objects list */
