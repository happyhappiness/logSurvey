     storeAppendPrintf(sentry, "\tNumber of queued ICP replies:\t%u\n",
                       statCounter.icp.replies_queued);
 
+#if USE_HTCP
+
+    storeAppendPrintf(sentry, "\tNumber of HTCP messages received:\t%u\n",
+                      statCounter.htcp.pkts_recv);
+
+    storeAppendPrintf(sentry, "\tNumber of HTCP messages sent:\t%u\n",
+                      statCounter.htcp.pkts_sent);
+
+#endif
+
     storeAppendPrintf(sentry, "\tRequest failure ratio:\t%5.2f\n",
                       request_failure_ratio);
 
