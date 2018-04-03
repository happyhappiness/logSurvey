	    e->host,
	    e->http_port,
	    e->icp_port);
	storeAppendPrintf(sentry, "Status     : %s\n",
	    neighborUp(e) ? "Up" : "Down");
	storeAppendPrintf(sentry, "AVG RTT    : %d msec\n", e->stats.rtt);