
    storeAppendPrintf(e, "%s %s",
                      n,
                      s->s.toUrl(buf,MAX_IPSTRLEN));

    // MODES and specific sub-options.
    if (s->flags.natIntercept)
