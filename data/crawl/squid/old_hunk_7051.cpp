
void
server_list(StoreEntry * sentry)
{
    peer *e = NULL;
    struct _domain_ping *d = NULL;
    icp_opcode op;

    storeAppendPrintf(sentry, open_bracket);

    if (getFirstPeer() == NULL)
	storeAppendPrintf(sentry, "{There are no neighbors installed.}\n");
    for (e = getFirstPeer(); e; e = getNextPeer(e)) {
	if (e->host == NULL)
	    fatal_dump("Found an peer without a hostname!");
	storeAppendPrintf(sentry, "\n{%-11.11s: %s/%d/%d}\n",
	    neighborTypeStr(e),
	    e->host,
