    if (p->options.mcast_responder)
        storeAppendPrintf(sentry, " multicast-responder");

    if (p->weight != 1)
        storeAppendPrintf(sentry, " weight=%d", p->weight);

