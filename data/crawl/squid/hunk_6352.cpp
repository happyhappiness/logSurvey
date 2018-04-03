 	mkrfc1123(current_time.tv_sec));
     storeAppendPrintf(sentry, "Connection information for %s:\n",
 	appname);
+    storeAppendPrintf(sentry, "\tNumber of clients accessing cache:\t%u\n",
+	Counter.client_http.clients);
     storeAppendPrintf(sentry, "\tNumber of HTTP requests received:\t%u\n",
 	Counter.client_http.requests);
     storeAppendPrintf(sentry, "\tNumber of ICP messages received:\t%u\n",
