	    e->stats.ignored_replies,
	    percent(e->stats.ignored_replies, e->stats.pings_acked));
	storeAppendPrintf(sentry, "Histogram of PINGS ACKED:\n");
#if USE_HTCP
	if (EBIT_TEST(e->options, NEIGHBOR_HTCP)) {
	    storeAppendPrintf(sentry, "\tMisses\t%8d %3d%%\n",
		e->htcp.counts[0],
		percent(e->htcp.counts[0], e->stats.pings_acked));
	    storeAppendPrintf(sentry, "\tHits\t%8d %3d%%\n",
		e->htcp.counts[1],
		percent(e->htcp.counts[1], e->stats.pings_acked));
	} else {
#endif
	for (op = ICP_INVALID; op < ICP_END; op++) {
	    if (e->icp.counts[op] == 0)
		continue;
