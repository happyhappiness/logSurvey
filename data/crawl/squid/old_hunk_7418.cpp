    while (c) {
	storeAppendPrintf(sentry, "{Address: %s}\n", c->key);
	storeAppendPrintf(sentry, "{Name: %s}\n", fqdnFromAddr(c->addr));
	storeAppendPrintf(sentry, "{    HTTP Requests %d}\n",
	    c->n_http);
	storeAppendPrintf(sentry, "{    ICP Requests %d}\n",
	    c->n_icp);
	storeAppendPrintf(sentry, "{    Log Code Histogram:}\n");
	for (l = LOG_TAG_NONE; l < ERR_MAX; l++) {
	    if (c->result_hist[l] == 0)
		continue;
	    storeAppendPrintf(sentry,
		"{        %-20.20s %7d %3d%%}\n",
		log_tags[l],
		c->result_hist[l],
		percent(c->result_hist[l], c->n_requests));
	}
	storeAppendPrintf(sentry, "{}\n");
	c = (ClientInfo *) hash_next(client_table);