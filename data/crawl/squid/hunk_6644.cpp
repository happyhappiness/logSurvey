 	    e->host,
 	    e->http_port,
 	    e->icp_port);
+	for (i = 0; i < e->n_addresses; i++) {
+	    storeAppendPrintf(sentry, "Address[%d] : %s\n", i,
+		inet_ntoa(e->addresses[i]));
+	}
 	storeAppendPrintf(sentry, "Status     : %s\n",
 	    neighborUp(e) ? "Up" : "Down");
 	storeAppendPrintf(sentry, "AVG RTT    : %d msec\n", e->stats.rtt);