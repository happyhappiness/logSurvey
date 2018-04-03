 }
 
 static void
-dump_time_t(time_t var)
+dump_time_t(StoreEntry *entry, const char *name, time_t var)
 {
-    printf("%d", (int) var);
+    storeAppendPrintf(entry, "%s %d seconds\n", name, (int) var);
 }
 
 static void
