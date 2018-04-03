 }
 
 static void
-dump_acl_access(struct _acl_access *head)
+dump_acl_access(StoreEntry *entry, const char *name, struct _acl_access *head)
 {
-    assert(0);
+    storeAppendPrintf(entry, "%s -- UNIMPLEMENTED\n", name);
 }
 
 static void
