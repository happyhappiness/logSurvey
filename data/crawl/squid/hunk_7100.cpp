 	}
 	storeAppendPrintf(sentry, "{    HTTP Requests %d}\n",
 	    c->Http.n_requests);
-	for (l = LOG_TAG_NONE; l < ERR_MAX; l++) {
+	for (l = LOG_TAG_NONE; l < LOG_TYPE_MAX; l++) {
 	    if (c->Http.result_hist[l] == 0)
 		continue;
 	    storeAppendPrintf(sentry,
