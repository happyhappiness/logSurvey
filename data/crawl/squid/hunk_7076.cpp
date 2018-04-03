 }
 
 static void
-dump_peer(peer * p)
+dump_peer(StoreEntry *entry, const char *name, peer * p)
 {
-    assert(0);
+    storeAppendPrintf(entry, "%s -- UNIMPLEMENTED\n", name);
 }
 
 static void
