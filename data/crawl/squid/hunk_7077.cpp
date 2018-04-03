 }
 
 static void
-dump_cachemgrpasswd(cachemgr_passwd * list)
+dump_cachemgrpasswd(StoreEntry *entry, const char *name, cachemgr_passwd * list)
 {
-    assert(0);
+    storeAppendPrintf(entry, "%s -- UNIMPLEMENTED\n", name);
 }
 
 static void
