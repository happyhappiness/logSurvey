 void
 SwapDir::stat(StoreEntry &output) const
 {
+    if (!doReportStat())
+        return;
+
     storeAppendPrintf(&output, "Store Directory #%d (%s): %s\n", index, type(),
                       path);
     storeAppendPrintf(&output, "FS Block Size %d Bytes\n",
