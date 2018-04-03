
    secs = (int) (squid_curtime - squid_starttime);

    storeAppendPrintf(sentry, open_bracket);

    strcpy(p->protoname, "TOTAL");
    p->object_count = 0;
