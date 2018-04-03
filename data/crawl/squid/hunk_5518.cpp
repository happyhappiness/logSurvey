 static void
 aclLookupDstIPDone(const ipcache_addrs * ia, void *data)
 {
-    aclCheck_t *checklist = data;
+    aclCheck_t *checklist = (aclCheck_t *)data;
     checklist->state[ACL_DST_IP] = ACL_LOOKUP_DONE;
     aclCheck(checklist);
 }
 
 static void
 aclLookupDstIPforASNDone(const ipcache_addrs * ia, void *data)
 {
-    aclCheck_t *checklist = data;
+    aclCheck_t *checklist = (aclCheck_t *)data;
     checklist->state[ACL_DST_ASN] = ACL_LOOKUP_DONE;
     aclCheck(checklist);
 }
 
 static void
 aclLookupSrcFQDNDone(const char *fqdn, void *data)
 {
-    aclCheck_t *checklist = data;
+    aclCheck_t *checklist = (aclCheck_t *)data;
     checklist->state[ACL_SRC_DOMAIN] = ACL_LOOKUP_DONE;
     aclCheck(checklist);
 }
 
 static void
 aclLookupDstFQDNDone(const char *fqdn, void *data)
 {
-    aclCheck_t *checklist = data;
+    aclCheck_t *checklist = (aclCheck_t *)data;
     checklist->state[ACL_DST_DOMAIN] = ACL_LOOKUP_DONE;
     aclCheck(checklist);
 }
 
 static void
 aclLookupProxyAuthDone(void *data, char *result)
 {
-    aclCheck_t *checklist = data;
+    aclCheck_t *checklist = (aclCheck_t *)data;
     checklist->state[ACL_PROXY_AUTH] = ACL_LOOKUP_DONE;
     if (result != NULL)
 	fatal("AclLookupProxyAuthDone: Old code floating around somewhere.\nMake clean and if that doesn't work, report a bug to the squid developers.\n");
