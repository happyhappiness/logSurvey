	for (l = LOG_TAG_NONE; l < LOG_TYPE_MAX; l++) {
	    if (c->Icp.result_hist[l] == 0)
		continue;
	    icp_total += c->Icp.result_hist[l];
	    if (LOG_UDP_HIT == l)
		icp_hits += c->Icp.result_hist[l];
	    storeAppendPrintf(sentry,
		"        %-20.20s %7d %3d%%\n",
		log_tags[l],