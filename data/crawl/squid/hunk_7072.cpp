  *****************************************************************************/
 
 static void
-dump_acl(acl * acl)
+dump_acl(StoreEntry *entry, const char *name, acl * acl)
 {
-    assert(0);
+    storeAppendPrintf(entry, "%s -- UNIMPLEMENTED\n", name);
 }
 
 static void
