     StatCounters *f = &Counter;
     storeAppendPrintf(sentry, "Current incoming_icp_interval: %d\n",
 	incoming_icp_interval >> INCOMING_FACTOR);
+    storeAppendPrintf(sentry, "Current incoming_dns_interval: %d\n",
+	incoming_dns_interval >> INCOMING_FACTOR);
     storeAppendPrintf(sentry, "Current incoming_http_interval: %d\n",
 	incoming_http_interval >> INCOMING_FACTOR);
     storeAppendPrintf(sentry, "\n");
