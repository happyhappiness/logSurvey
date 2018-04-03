     while ((c = (ClientInfo *) hash_next(client_table))) {
 	storeAppendPrintf(sentry, "Address: %s\n", c->key);
 	storeAppendPrintf(sentry, "Name: %s\n", fqdnFromAddr(c->addr));
+	storeAppendPrintf(sentry, "Currently established connections: %d\n",
+	    c->n_established);
 	storeAppendPrintf(sentry, "    ICP Requests %d\n",
 	    c->Icp.n_requests);
 	for (l = LOG_TAG_NONE; l < LOG_TYPE_MAX; l++) {
