 static void
 commIncomingStats(StoreEntry * sentry)
 {
-    storeAppendPrintf(sentry, "Current incoming_icp_interval: %d\n",
-                      incoming_icp_interval >> INCOMING_FACTOR);
+    storeAppendPrintf(sentry, "Current incoming_udp_interval: %d\n",
+                      incoming_udp_interval >> INCOMING_FACTOR);
     storeAppendPrintf(sentry, "Current incoming_dns_interval: %d\n",
                       incoming_dns_interval >> INCOMING_FACTOR);
-    storeAppendPrintf(sentry, "Current incoming_http_interval: %d\n",
-                      incoming_http_interval >> INCOMING_FACTOR);
+    storeAppendPrintf(sentry, "Current incoming_tcp_interval: %d\n",
+                      incoming_tcp_interval >> INCOMING_FACTOR);
     storeAppendPrintf(sentry, "\n");
     storeAppendPrintf(sentry, "Histogram of events per incoming socket type\n");
-    storeAppendPrintf(sentry, "ICP Messages handled per comm_select_icp_incoming() call:\n");
-    statCounter.comm_icp_incoming.dump(sentry, statHistIntDumper);
+    storeAppendPrintf(sentry, "ICP Messages handled per comm_select_udp_incoming() call:\n");
+    statCounter.comm_udp_incoming.dump(sentry, statHistIntDumper);
     storeAppendPrintf(sentry, "DNS Messages handled per comm_select_dns_incoming() call:\n");
     statCounter.comm_dns_incoming.dump(sentry, statHistIntDumper);
-    storeAppendPrintf(sentry, "HTTP Messages handled per comm_select_http_incoming() call:\n");
-    statCounter.comm_http_incoming.dump(sentry, statHistIntDumper);
+    storeAppendPrintf(sentry, "HTTP Messages handled per comm_select_tcp_incoming() call:\n");
+    statCounter.comm_tcp_incoming.dump(sentry, statHistIntDumper);
 }
 
 void
