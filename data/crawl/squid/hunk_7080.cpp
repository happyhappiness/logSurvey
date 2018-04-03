 }
 
 static void
-dump_int(int var)
+dump_int(StoreEntry *entry, const char *name, int var)
 {
-    printf("%d", var);
+    storeAppendPrintf(entry, "%s %d\n", name, var);
 }
 
 static void
