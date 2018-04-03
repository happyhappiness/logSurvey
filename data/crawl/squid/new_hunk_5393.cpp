	storeAppendPrintf(sentry, "FETCHES    : %d\n", e->stats.fetches);
	storeAppendPrintf(sentry, "OPEN CONNS : %d\n", e->stats.conn_open);
	storeAppendPrintf(sentry, "AVG RTT    : %d msec\n", e->stats.rtt);
	if (!e->options.no_query) {
	    storeAppendPrintf(sentry, "LAST QUERY : %8d seconds ago\n",
		(int) (squid_curtime - e->stats.last_query));
	    if (e->stats.last_reply > 0)
		storeAppendPrintf(sentry, "LAST REPLY : %8d seconds ago\n",
		    (int) (squid_curtime - e->stats.last_reply));
	    else
		storeAppendPrintf(sentry, "LAST REPLY : none received\n");
	    storeAppendPrintf(sentry, "PINGS SENT : %8d\n", e->stats.pings_sent);
	    storeAppendPrintf(sentry, "PINGS ACKED: %8d %3d%%\n",
		e->stats.pings_acked,
		percent(e->stats.pings_acked, e->stats.pings_sent));
	}
	storeAppendPrintf(sentry, "IGNORED    : %8d %3d%%\n",
	    e->stats.ignored_replies,
	    percent(e->stats.ignored_replies, e->stats.pings_acked));
	if (!e->options.no_query) {
	    storeAppendPrintf(sentry, "Histogram of PINGS ACKED:\n");
#if USE_HTCP
	    if (e->options.htcp) {
		storeAppendPrintf(sentry, "\tMisses\t%8d %3d%%\n",
		    e->htcp.counts[0],
		    percent(e->htcp.counts[0], e->stats.pings_acked));
		storeAppendPrintf(sentry, "\tHits\t%8d %3d%%\n",
		    e->htcp.counts[1],
		    percent(e->htcp.counts[1], e->stats.pings_acked));
	    } else {
#endif
		for (op = ICP_INVALID; op < ICP_END; ++op) {
		    if (e->icp.counts[op] == 0)
			continue;
		    storeAppendPrintf(sentry, "    %12.12s : %8d %3d%%\n",
			icp_opcode_str[op],
			e->icp.counts[op],
			percent(e->icp.counts[op], e->stats.pings_acked));
		}
#if USE_HTCP
	    }
#endif
	}
	if (e->stats.last_connect_failure) {
	    storeAppendPrintf(sentry, "Last failed connect() at: %s\n",
		mkhttpdlogtime(&(e->stats.last_connect_failure)));
