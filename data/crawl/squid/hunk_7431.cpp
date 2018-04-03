 server_list(const cacheinfo * obj, StoreEntry * sentry)
 {
     edge *e = NULL;
-    dom_list *d = NULL;
+    struct _domain_ping *d = NULL;
     icp_opcode op;
 
     storeAppendPrintf(sentry, open_bracket);
