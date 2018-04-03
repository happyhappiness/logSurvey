 }
 
 static void
-dump_regexlist(relist * var)
+dump_regexlist(StoreEntry *entry, const char *name, relist * var)
 {
-    assert(0);
+    storeAppendPrintf(entry, "%s -- UNIMPLEMENTED\n", name);
 }
 
 static void
