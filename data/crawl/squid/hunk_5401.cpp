 	}
 	storeAppendPrintf(sentry, "Status     : %s\n",
 	    neighborUp(e) ? "Up" : "Down");
-	storeAppendPrintf(sentry, "AVG RTT    : %d msec\n", e->stats.rtt);
+	storeAppendPrintf(sentry, "FETCHES    : %d\n", e->stats.fetches);
 	storeAppendPrintf(sentry, "OPEN CONNS : %d\n", e->stats.conn_open);
+	storeAppendPrintf(sentry, "AVG RTT    : %d msec\n", e->stats.rtt);
 	storeAppendPrintf(sentry, "LAST QUERY : %8d seconds ago\n",
 	    (int) (squid_curtime - e->stats.last_query));
 	storeAppendPrintf(sentry, "LAST REPLY : %8d seconds ago\n",
