static void
peerSourceHashCachemgr(StoreEntry * sentry)
{
    CachePeer *p;
    int sumfetches = 0;
    storeAppendPrintf(sentry, "%24s %10s %10s %10s %10s\n",
                      "Hostname",