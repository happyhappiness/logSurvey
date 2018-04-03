     storeAppendPrintf(sentry, "\tCPU Usage, 60 minute avg:\t%.2f%%\n",
                       stats.cpu_usage60);
 
-#if HAVE_SBRK
-
-    storeAppendPrintf(sentry, "\tProcess Data Segment Size via sbrk(): %.0f KB\n",
-                      stats.proc_data_seg / 1024);
-
-#endif
-
     storeAppendPrintf(sentry, "\tMaximum Resident Size: %.0f KB\n",
                       stats.maxrss);
 
