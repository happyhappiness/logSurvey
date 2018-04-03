 	storeAppendPrintf(sentry, "There are no neighbors installed.\n");
     for (e = peers; e; e = e->next) {
 	assert(e->host != NULL);
-	storeAppendPrintf(sentry, "\n%-11.11s: %s/%d/%d\n",
+	storeAppendPrintf(sentry, "\n%-11.11s: %s\n",
 	    neighborTypeStr(e),
+	    e->name);
+	storeAppendPrintf(sentry, "Host       : %s/%d/%d\n",
 	    e->host,
 	    e->http_port,
 	    e->icp.port);
