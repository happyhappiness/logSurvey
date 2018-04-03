 #endif
 }
 
+static void
+statCountersHistograms(StoreEntry *sentry)
+{
+    StatCounters *f = &Counter;
+#if TOO_MUCH_OUTPUT
+    storeAppendPrintf(sentry, "client_http.all_svc_time histogram:\n");
+    statHistDump(&f->client_http.all_svc_time, sentry, NULL);
+    storeAppendPrintf(sentry, "client_http.miss_svc_time histogram:\n");
+    statHistDump(&f->client_http.miss_svc_time, sentry, NULL);
+    storeAppendPrintf(sentry, "client_http.nm_svc_time histogram:\n");
+    statHistDump(&f->client_http.nm_svc_time, sentry, NULL);
+    storeAppendPrintf(sentry, "client_http.hit_svc_time histogram:\n");
+    statHistDump(&f->client_http.hit_svc_time, sentry, NULL);
+#endif
+#if SQUID_PEER_DIGEST
+    storeAppendPrintf(sentry, "\nicp.query_svc_time histogram:\n");
+    statHistDump(&f->icp.query_svc_time, sentry, NULL);
+    storeAppendPrintf(sentry, "\nicp.reply_svc_time histogram:\n");
+    statHistDump(&f->icp.reply_svc_time, sentry, NULL);
+    storeAppendPrintf(sentry, "\nicp.client_svc_time histogram:\n");
+    statHistDump(&f->icp.client_svc_time, sentry, NULL);
+    storeAppendPrintf(sentry, "\ncd.client_svc_time histogram:\n");
+    statHistDump(&f->cd.client_svc_time, sentry, NULL);
+#endif
+#if TOO_MUCH_OUTPUT
+    storeAppendPrintf(sentry, "icp.query_svc_time histogram:\n");
+    statHistDump(&f->icp.query_svc_time, sentry, NULL);
+    storeAppendPrintf(sentry, "icp.reply_svc_time histogram:\n");
+    statHistDump(&f->icp.reply_svc_time, sentry, NULL);
+    storeAppendPrintf(sentry, "dns.svc_time histogram:\n");
+    statHistDump(&f->dns.svc_time, sentry, NULL);
+#endif
+}
+
 static void
 statCountersDump(StoreEntry * sentry)
 {
