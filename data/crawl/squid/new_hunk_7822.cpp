     cacheinfo *obj;
     StoreEntry *sentry;
{
    storeAppendPrintf(sentry, "{ \"Not_Implemented_yet.\"}\n");
}

void server_list(obj, sentry)
     cacheinfo *obj;
     StoreEntry *sentry;
{
    edge *e = NULL;
    dom_list *d = NULL;

    storeAppendPrintf(sentry, "{\n");

    if (getFirstEdge() == (edge *) NULL) {
	storeAppendPrintf(sentry, "{There are no neighbors installed.}\n");
    }
    for (e = getFirstEdge(); e; e = getNextEdge(e)) {
	if (e->host == NULL)
	    fatal_dump("Found an edge without a hostname!");
	storeAppendPrintf(sentry, "\n{Hostname:    %s}\n", e->host);
	storeAppendPrintf(sentry, "{Edge type:   %s}\n",
	    e->type == EDGE_PARENT ? "parent" : "neighbor");
	storeAppendPrintf(sentry, "{Status:      %s}\n",
	    e->neighbor_up ? "Up" : "Down");
	storeAppendPrintf(sentry, "{UDP PORT:    %d}\n", e->udp_port);
	storeAppendPrintf(sentry, "{ASCII PORT:  %d}\n", e->ascii_port);
	storeAppendPrintf(sentry, "{ACK DEFICIT: %d}\n", e->ack_deficit);
	storeAppendPrintf(sentry, "{PINGS SENT:  %d}\n", e->num_pings);
	storeAppendPrintf(sentry, "{PINGS ACKED: %d}\n", e->pings_acked);
	if (e->last_fail_time) {
	    storeAppendPrintf(sentry, "{Last failed connect() at: %s}\n",
		mkhttpdlogtime(&(e->last_fail_time)));
	}
	storeAppendPrintf(sentry, "{DOMAIN LIST: ");
	for (d = e->domains; d; d = d->next) {
	    if (d->do_ping)
		storeAppendPrintf(sentry, "%s ", d->domain);
	    else
		storeAppendPrintf(sentry, "!%s ", d->domain);
	}
	storeAppendPrintf(sentry, "}\n");
    }
    storeAppendPrintf(sentry, "}\n");
}


