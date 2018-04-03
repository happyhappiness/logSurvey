 	storeAppendPrintf(sentry, "PINGS ACKED: %8d %3d%%\n",
 	    e->stats.pings_acked,
 	    percent(e->stats.pings_acked, e->stats.pings_sent));
-	storeAppendPrintf(sentry, "FETCHES    : %8d %3d%%\n",
-	    e->stats.fetches,
-	    percent(e->stats.fetches, e->stats.pings_acked));
 	storeAppendPrintf(sentry, "IGNORED    : %8d %3d%%\n",
 	    e->stats.ignored_replies,
 	    percent(e->stats.ignored_replies, e->stats.pings_acked));