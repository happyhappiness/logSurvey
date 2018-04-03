 	: 0.0);
     x = statHistDeltaMedian(&l->select_fds_hist, &f->select_fds_hist);
     storeAppendPrintf(sentry, "median_select_fds = %f\n", x);
-    storeAppendPrintf(sentry, "store_files_cleaned = %f/sec\n",
-	XAVG(store_files_cleaned));
+    storeAppendPrintf(sentry, "swap_files_cleaned = %f/sec\n",
+	XAVG(swap_files_cleaned));
     storeAppendPrintf(sentry, "aborted_requests = %f/sec\n",
 	XAVG(aborted_requests));
 
