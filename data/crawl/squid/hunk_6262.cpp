 {
     int i;
     SwapDir *SD;
+#if HAVE_SYS_STATFS_H
+    struct statfs sfs;
+#endif
     storeAppendPrintf(sentry, "Store Directory Statistics:\n");
     storeAppendPrintf(sentry, "Store Entries          : %d\n",
 	memInUse(MEM_STOREENTRY));
