	storeAppendPrintf(sentry, "{Status     : %s}\n",
	    neighborUp(e) ? "Up" : "Down");
	storeAppendPrintf(sentry, "{AVG RTT    : %d msec}\n", e->stats.rtt);
	storeAppendPrintf(sentry, "{LAST QUERY : %8d seconds ago}\n",
	    (int) (squid_curtime - e->stats.last_query));
	storeAppendPrintf(sentry, "{LAST REPLY : %8d seconds ago}\n",
	    (int) (squid_curtime - e->stats.last_reply));
	storeAppendPrintf(sentry, "{PINGS SENT : %8d}\n", e->stats.pings_sent);
	storeAppendPrintf(sentry, "{PINGS ACKED: %8d %3d%%}\n",
	    e->stats.pings_acked,
