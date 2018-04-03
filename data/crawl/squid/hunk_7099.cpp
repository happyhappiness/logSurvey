 	storeAppendPrintf(sentry, "{Name: %s}\n", fqdnFromAddr(c->addr));
 	storeAppendPrintf(sentry, "{    ICP Requests %d}\n",
 	    c->Icp.n_requests);
-	for (l = LOG_TAG_NONE; l < ERR_MAX; l++) {
+	for (l = LOG_TAG_NONE; l < LOG_TYPE_MAX; l++) {
 	    if (c->Icp.result_hist[l] == 0)
 		continue;
 	    storeAppendPrintf(sentry,
