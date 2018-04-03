 clientdbDump(StoreEntry * sentry)
 {
     const char *name;
-    ClientInfo *c;
     int icp_total = 0;
     int icp_hits = 0;
     int http_total = 0;
     int http_hits = 0;
     storeAppendPrintf(sentry, "Cache Clients:\n");
     hash_first(client_table);
 
-    while ((c = (ClientInfo *) hash_next(client_table))) {
-        storeAppendPrintf(sentry, "Address: %s\n", hashKeyStr(&c->hash));
+    while (hash_link *hash = hash_next(client_table)) {
+        const ClientInfo *c = reinterpret_cast<const ClientInfo *>(hash);
+        storeAppendPrintf(sentry, "Address: %s\n", hashKeyStr(hash));
         if ( (name = fqdncache_gethostbyaddr(c->addr, 0)) ) {
             storeAppendPrintf(sentry, "Name:    %s\n", name);
         }
