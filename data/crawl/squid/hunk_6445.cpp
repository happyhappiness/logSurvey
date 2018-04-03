 	for (l = LOG_TAG_NONE; l < LOG_TYPE_MAX; l++) {
 	    if (c->Http.result_hist[l] == 0)
 		continue;
+	    http_total += c->Http.result_hist[l];
+	    if (isTcpHit(l))
+		http_hits += c->Http.result_hist[l];
 	    storeAppendPrintf(sentry,
 		"        %-20.20s %7d %3d%%\n",
 		log_tags[l],
