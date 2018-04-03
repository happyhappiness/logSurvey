     storeAppendPrintf(sentry, "\n");
     storeAppendPrintf(sentry, "Histogram of events per incoming socket type\n");
     storeAppendPrintf(sentry, "ICP Messages handled per comm_poll_icp_incoming() call:\n");
-    f->comm_icp_incoming.dump(sentry, statHistIntDumper);
+    statCounter.comm_icp_incoming.dump(sentry, statHistIntDumper);
     storeAppendPrintf(sentry, "DNS Messages handled per comm_poll_dns_incoming() call:\n");
-    f->comm_dns_incoming.dump(sentry, statHistIntDumper);
+    statCounter.comm_dns_incoming.dump(sentry, statHistIntDumper);
     storeAppendPrintf(sentry, "HTTP Messages handled per comm_poll_http_incoming() call:\n");
-    f->comm_http_incoming.dump(sentry, statHistIntDumper);
+    statCounter.comm_http_incoming.dump(sentry, statHistIntDumper);
 }
 
 /* Called by async-io or diskd to speed up the polling */
