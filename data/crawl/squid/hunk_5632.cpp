 	storeAppendPrintf(sentry, " proxy-only");
     if (p->options.no_query)
 	storeAppendPrintf(sentry, " no-query");
+    if (p->options.background_ping)
+	storeAppendPrintf(sentry, " background-ping");
     if (p->options.no_digest)
 	storeAppendPrintf(sentry, " no-digest");
     if (p->options.default_parent)
 	storeAppendPrintf(sentry, " default");
     if (p->options.roundrobin)
 	storeAppendPrintf(sentry, " round-robin");
+    if (p->options.weighted_roundrobin)
+	storeAppendPrintf(sentry, " weighted-round-robin");
     if (p->options.mcast_responder)
 	storeAppendPrintf(sentry, " multicast-responder");
     if (p->options.closest_only)
