 {
     ClientInfo *c;
     log_type l;
+    int icp_total = 0;
+    int icp_hits = 0;
+    int http_total = 0;
+    int http_hits = 0;
     storeAppendPrintf(sentry, "Cache Clients:\n");
     c = (ClientInfo *) hash_first(client_table);
     while (c) {
