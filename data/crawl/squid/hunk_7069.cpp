 #define free_gb_size_t free_size_t
 
 static void
-dump_ushort(StoreEntry *entry, const char *name, u_short var)
+dump_ushort(StoreEntry * entry, const char *name, u_short var)
 {
     storeAppendPrintf(entry, "%s %d\n", name, var);
 }
