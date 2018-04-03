    ps_state *psstate = data;
    psstate->icp.n_recv++;
}

static void
neighborDumpPeers(StoreEntry * sentry)
{
    dump_peers(sentry, Config.peers);
}

static void
neighborDumpNonPeers(StoreEntry * sentry)
{
    dump_peers(sentry, non_peers);
}

static void
dump_peers(StoreEntry * sentry, peer * peers)
{
    peer *e = NULL;
    struct _domain_ping *d = NULL;
    icp_opcode op;
    if (peers == NULL)
	storeAppendPrintf(sentry, "There are no neighbors installed.\n");
    for (e = peers; e; e = e->next) {
	assert(e->host != NULL);
	storeAppendPrintf(sentry, "\n%-11.11s: %s/%d/%d\n",
	    neighborTypeStr(e),
	    e->host,
	    e->http_port,
	    e->icp_port);
	storeAppendPrintf(sentry, "Status     : %s\n",
	    neighborUp(e) ? "Up" : "Down");
	storeAppendPrintf(sentry, "AVG RTT    : %d msec\n", e->stats.rtt);
	storeAppendPrintf(sentry, "LAST QUERY : %8d seconds ago\n",
	    (int) (squid_curtime - e->stats.last_query));
	storeAppendPrintf(sentry, "LAST REPLY : %8d seconds ago\n",
	    (int) (squid_curtime - e->stats.last_reply));
	storeAppendPrintf(sentry, "PINGS SENT : %8d\n", e->stats.pings_sent);
	storeAppendPrintf(sentry, "PINGS ACKED: %8d %3d%%\n",
	    e->stats.pings_acked,
	    percent(e->stats.pings_acked, e->stats.pings_sent));
	storeAppendPrintf(sentry, "FETCHES    : %8d %3d%%\n",
	    e->stats.fetches,
	    percent(e->stats.fetches, e->stats.pings_acked));
	storeAppendPrintf(sentry, "IGNORED    : %8d %3d%%\n",
	    e->stats.ignored_replies,
	    percent(e->stats.ignored_replies, e->stats.pings_acked));
	storeAppendPrintf(sentry, "Histogram of PINGS ACKED:\n");
	for (op = ICP_INVALID; op < ICP_END; op++) {
	    if (e->stats.counts[op] == 0)
		continue;
	    storeAppendPrintf(sentry, "    %12.12s : %8d %3d%%\n",
		icp_opcode_str[op],
		e->stats.counts[op],
		percent(e->stats.counts[op], e->stats.pings_acked));
	}
	if (e->last_fail_time) {
	    storeAppendPrintf(sentry, "Last failed connect() at: %s\n",
		mkhttpdlogtime(&(e->last_fail_time)));
	}
	if (e->pinglist != NULL)
	    storeAppendPrintf(sentry, "DOMAIN LIST: ");
	for (d = e->pinglist; d; d = d->next) {
	    if (d->do_ping)
		storeAppendPrintf(sentry, "%s ", d->domain);
	    else
		storeAppendPrintf(sentry, "!%s ", d->domain);
	}
	storeAppendPrintf(sentry, "Keep-Alive Ratio: %d%%\n",
	    percent(e->stats.n_keepalives_recv, e->stats.n_keepalives_sent));
    }
}
