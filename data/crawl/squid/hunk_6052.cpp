 void
 storeDirStats(StoreEntry * sentry)
 {
+    int i;
+    SwapDir *SD;
+
     storeAppendPrintf(sentry, "Store Directory Statistics:\n");
     storeAppendPrintf(sentry, "Store Entries          : %d\n",
 	memInUse(MEM_STOREENTRY));
