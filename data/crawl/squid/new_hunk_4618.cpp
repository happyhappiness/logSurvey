
    assert(pd);

    const char *host = pd->host.c_str();
    storeAppendPrintf(e, "\npeer digest from %s\n", host);

    cacheDigestGuessStatsReport(&pd->stats.guess, e, host);
