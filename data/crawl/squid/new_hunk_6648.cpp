	    n->hops);
	for (x = n->hosts; x; x = x->next)
	    storeAppendPrintf(sentry, " %s", x->name);
	storeAppendPrintf(sentry, "\n");
	p = n->peers;
	for (j = 0; j < n->n_peers; j++, p++) {
	    storeAppendPrintf(sentry, "    %-22.22s %7.1f %5.1f\n",
		p->peername,
		p->rtt,
		p->hops);
	}
    }
    xfree(list);
#else