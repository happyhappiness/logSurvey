

static void
commIncomingStats(StoreEntry * sentry) {
    StatCounters *f = &statCounter;
    storeAppendPrintf(sentry, "Current incoming_icp_interval: %d\n",
                      incoming_icp_interval >> INCOMING_FACTOR);
