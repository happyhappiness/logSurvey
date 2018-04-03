 	statCPUUsage(5));
     storeAppendPrintf(sentry, "\tCPU Usage, 60 minute avg:\t%.2f%%\n",
 	statCPUUsage(60));
+#if HAVE_SBRK
+    storeAppendPrintf(sentry, "\tProcess Data Segment Size via sbrk(): %d KB\n",
+	(sbrk(0) - sbrk_start) >> 10);
+#endif
     storeAppendPrintf(sentry, "\tMaximum Resident Size: %d KB\n",
 	rusage_maxrss(&rusage));
     storeAppendPrintf(sentry, "\tPage faults with physical i/o: %d\n",