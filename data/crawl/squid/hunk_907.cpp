 void
 cbdataDumpHistory(StoreEntry *sentry)
 {
-    storeAppendPrintf(sentry, "%" PRIu64 " cbdata entries\n", cbdataCount);
+    storeAppendPrintf(sentry, "%d cbdata entries\n", cbdataCount);
     storeAppendPrintf(sentry, "Pointer\tType\tLocks\tAllocated by\n");
     CBDataHistoryDumper dumper(sentry);
     for_each (cbdataEntries, dumper);