	storeAppendPrintf(sentry, "There are no neighbors installed.\n");
    for (e = peers; e; e = e->next) {
	assert(e->host != NULL);
	storeAppendPrintf(sentry, "\n%-11.11s: %s/%d/%d\n",
	    neighborTypeStr(e),
	    e->host,
	    e->http_port,
	    e->icp.port);
