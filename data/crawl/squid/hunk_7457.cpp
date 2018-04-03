 	storeAppendPrintf(sentry, "{PINGS ACKED: %8d %3d%%}\n",
 	    e->stats.pings_acked,
 	    percent(e->stats.pings_acked, e->stats.pings_sent));
+	storeAppendPrintf(sentry, "{IGNORED    : %8d %3d%%}\n",
+	    e->stats.ignored_replies,
+	    percent(e->stats.ignored_replies, e->stats.pings_acked));
 	storeAppendPrintf(sentry, "{Histogram of PINGS ACKED:}\n");
 	for (op = ICP_OP_INVALID; op < ICP_OP_END; op++) {
 	    if (e->stats.counts[op] == 0)
