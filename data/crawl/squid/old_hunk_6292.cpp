	    e->stats.ignored_replies,
	    percent(e->stats.ignored_replies, e->stats.pings_acked));
	storeAppendPrintf(sentry, "Histogram of PINGS ACKED:\n");
	for (op = ICP_INVALID; op < ICP_END; op++) {
	    if (e->icp.counts[op] == 0)
		continue;
