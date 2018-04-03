 
 
 static void
-dump_denyinfo(struct _acl_deny_info_list *var)
+dump_denyinfo(StoreEntry *entry, const char *name, struct _acl_deny_info_list *var)
 {
-    assert(0);
+    storeAppendPrintf(entry, "%s -- UNIMPLEMENTED\n", name);
 }
 
 static void
