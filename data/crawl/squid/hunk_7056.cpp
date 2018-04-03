 }
 
 static void
-dump_address(StoreEntry *entry, const char *name, struct in_addr addr)
+dump_address(StoreEntry * entry, const char *name, struct in_addr addr)
 {
     storeAppendPrintf(entry, "%s %s\n", name, inet_ntoa(addr));
 }
