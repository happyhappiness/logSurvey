	}
	storeAppendPrintf(sentry, "    HTTP Requests %d\n",
	    c->Http.n_requests);
	for (l = LOG_TAG_NONE; l < LOG_TYPE_MAX; ++l) {
	    if (c->Http.result_hist[l] == 0)
		continue;
	    http_total += c->Http.result_hist[l];
