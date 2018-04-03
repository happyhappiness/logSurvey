 {
     int i;
     SwapDir *SD;
+    assert (sentry);
 
     storeAppendPrintf(sentry, "Store Directory Statistics:\n");
     storeAppendPrintf(sentry, "Store Entries          : %lu\n",
