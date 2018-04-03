 cbdataDump(StoreEntry * sentry)
 {
     storeAppendPrintf(sentry, "%d cbdata entries\n", cbdataCount);
-#if CBDATA_DEBUG
+#if USE_CBDATA_DEBUG
 
     storeAppendPrintf(sentry, "Pointer\tType\tLocks\tAllocated by\n");
     CBDataDumper dumper(sentry);
