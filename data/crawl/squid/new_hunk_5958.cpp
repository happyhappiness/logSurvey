	    n->rtt,
	    n->hops);
	for (x = n->hosts; x; x = x->next)
	    storeAppendPrintf(sentry, " %s", hashKeyStr(&x->hash));
	storeAppendPrintf(sentry, "\n");
	p = n->peers;
	for (j = 0; j < n->n_peers; j++, p++) {
