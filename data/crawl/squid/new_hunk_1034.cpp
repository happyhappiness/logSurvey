static void
dump_peers(StoreEntry * sentry, CachePeer * peers)
{
    char ntoabuf[MAX_IPSTRLEN];
    icp_opcode op;
    int i;

    if (peers == NULL)
        storeAppendPrintf(sentry, "There are no neighbors installed.\n");

    for (CachePeer *e = peers; e; e = e->next) {
        assert(e->host != NULL);
        storeAppendPrintf(sentry, "\n%-11.11s: %s\n",
                          neighborTypeStr(e),
