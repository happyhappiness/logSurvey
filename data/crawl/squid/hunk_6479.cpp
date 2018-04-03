     StatCounters *l = &CountHist[5];
     double x;
 
+    storeAppendPrintf(sentry, "client_http.all_svc_time histogram:\n");
+    statHistDump(&f->client_http.all_svc_time, sentry, NULL);
+    storeAppendPrintf(sentry, "client_http.miss_svc_time histogram:\n");
+    statHistDump(&f->client_http.miss_svc_time, sentry, NULL);
+    storeAppendPrintf(sentry, "client_http.nm_svc_time histogram:\n");
+    statHistDump(&f->client_http.nm_svc_time, sentry, NULL);
+    storeAppendPrintf(sentry, "client_http.hit_svc_time histogram:\n");
+    statHistDump(&f->client_http.hit_svc_time, sentry, NULL);
     storeAppendPrintf(sentry, "\nicp.query_svc_time histogram:\n");
     statHistDump(&f->icp.query_svc_time, sentry, NULL);
     storeAppendPrintf(sentry, "\nicp.reply_svc_time histogram:\n");
