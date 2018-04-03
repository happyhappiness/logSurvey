     storeAppendPrintf(entry, "%s %d %s\n", name, (int) var, B_BYTES_STR);
 }
 
-#if !USE_DNSHELPER
 static void
 dump_b_ssize_t(StoreEntry * entry, const char *name, ssize_t var)
 {
     storeAppendPrintf(entry, "%s %d %s\n", name, (int) var, B_BYTES_STR);
 }
-#endif
 
 #if UNUSED_CODE
 static void
