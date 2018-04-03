
    secs = (int) (squid_curtime - squid_starttime);

    storeAppendPrintf(sentry, "{\n");

    strcpy(p->protoname, "TOTAL");
    p->object_count = 0;
