 redirectStats(StoreEntry * sentry)
 {
     int k;
-    storeAppendPrintf(sentry, open_bracket);
-    storeAppendPrintf(sentry, "{Redirector Statistics:}\n");
-    storeAppendPrintf(sentry, "{requests: %d}\n",
+    storeAppendPrintf(sentry, "Redirector Statistics:\n");
+    storeAppendPrintf(sentry, "requests: %d\n",
 	RedirectStats.requests);
-    storeAppendPrintf(sentry, "{replies: %d}\n",
+    storeAppendPrintf(sentry, "replies: %d\n",
 	RedirectStats.replies);
-    storeAppendPrintf(sentry, "{queue length: %d}\n",
+    storeAppendPrintf(sentry, "queue length: %d\n",
 	RedirectStats.queue_size);
-    storeAppendPrintf(sentry, "{avg service time: %d msec}\n",
+    storeAppendPrintf(sentry, "avg service time: %d msec\n",
 	RedirectStats.avg_svc_time);
-    storeAppendPrintf(sentry, "{number of redirectors: %d}\n",
+    storeAppendPrintf(sentry, "number of redirectors: %d\n",
 	NRedirectors);
-    storeAppendPrintf(sentry, "{use histogram:}\n");
+    storeAppendPrintf(sentry, "use histogram:\n");
     for (k = 0; k < NRedirectors; k++) {
-	storeAppendPrintf(sentry, "{    redirector #%d: %d (%d rewrites)}\n",
+	storeAppendPrintf(sentry, "    redirector #%d: %d (%d rewrites)\n",
 	    k + 1,
 	    RedirectStats.use_hist[k],
 	    RedirectStats.rewrites[k]);
     }
-    storeAppendPrintf(sentry, close_bracket);
 }
