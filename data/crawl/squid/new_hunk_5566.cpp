	    if (c->Http.result_hist[l] == 0)
		continue;
	    http_total += c->Http.result_hist[l];
	    if (logTypeIsATcpHit(l))
		http_hits += c->Http.result_hist[l];
	    storeAppendPrintf(sentry,
		"        %-20.20s %7d %3d%%\n",
