 }
 
 static void
-dump_address(struct in_addr addr)
+dump_address(StoreEntry *entry, const char *name, struct in_addr addr)
 {
-    printf("%s", inet_ntoa(addr));
+    storeAppendPrintf(entry, "%s %s\n", name, inet_ntoa(addr));
 }
 
 static void
