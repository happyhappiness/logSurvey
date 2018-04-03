	if (e->host == NULL)
	    fatal_dump("Found an peer without a hostname!");
	storeAppendPrintf(sentry, "\n{%-11.11s: %s/%d/%d}\n",
	    neighborTypeStr(e),
	    e->host,
	    e->http_port,
	    e->icp_port);
