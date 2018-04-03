 	storeAppendPrintf(sentry, " weighted-round-robin");
     if (p->options.mcast_responder)
 	storeAppendPrintf(sentry, " multicast-responder");
+    if (p->weight != 1)
+	storeAppendPrintf(sentry, " weight=%d", p->weight);
     if (p->options.closest_only)
 	storeAppendPrintf(sentry, " closest-only");
 #if USE_HTCP