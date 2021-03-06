     storeAppendPrintf(sentry, "number of reads: %.0f\n", stats.ftp_reads);
     storeAppendPrintf(sentry, "Read Histogram:\n");
 
-    for (i = 0; i < _iostats::histSize; i++) {
+    for (i = 0; i < _iostats::histSize; ++i) {
         storeAppendPrintf(sentry, "%5d-%5d: %9.0f %2.0f%%\n",
                           i ? (1 << (i - 1)) + 1 : 1,
                           1 << i,
