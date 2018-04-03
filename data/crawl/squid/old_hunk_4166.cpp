    if (s->vport)
        storeAppendPrintf(e, " vport");

    if (s->disable_pmtu_discovery != DISABLE_PMTU_OFF) {
        const char *pmtu;

