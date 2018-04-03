    peer *e = NULL;
    struct _domain_ping *d = NULL;
    icp_opcode op;
    if (peers == NULL)
	storeAppendPrintf(sentry, "There are no neighbors installed.\n");
    for (e = peers; e; e = e->next) {
