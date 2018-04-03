 	XAVG(icp.pkts_sent));
     storeAppendPrintf(sentry, "icp.pkts_recv = %f/sec\n",
 	XAVG(icp.pkts_recv));
+    storeAppendPrintf(sentry, "icp.queries_sent = %f/sec\n",
+	XAVG(icp.queries_sent));
+    storeAppendPrintf(sentry, "icp.replies_sent = %f/sec\n",
+	XAVG(icp.replies_sent));
+    storeAppendPrintf(sentry, "icp.queries_recv = %f/sec\n",
+	XAVG(icp.queries_recv));
+    storeAppendPrintf(sentry, "icp.replies_recv = %f/sec\n",
+	XAVG(icp.replies_recv));
     storeAppendPrintf(sentry, "icp.replies_queued = %f/sec\n",
 	XAVG(icp.replies_queued));
+    storeAppendPrintf(sentry, "icp.query_timeouts = %f/sec\n",
+	XAVG(icp.query_timeouts));
     storeAppendPrintf(sentry, "icp.kbytes_sent = %f/sec\n",
 	XAVG(icp.kbytes_sent.kb));
     storeAppendPrintf(sentry, "icp.kbytes_recv = %f/sec\n",
 	XAVG(icp.kbytes_recv.kb));
+    storeAppendPrintf(sentry, "icp.q_kbytes_sent = %f/sec\n",
+	XAVG(icp.q_kbytes_sent.kb));
+    storeAppendPrintf(sentry, "icp.r_kbytes_sent = %f/sec\n",
+	XAVG(icp.r_kbytes_sent.kb));
+    storeAppendPrintf(sentry, "icp.q_kbytes_recv = %f/sec\n",
+	XAVG(icp.q_kbytes_recv.kb));
+    storeAppendPrintf(sentry, "icp.r_kbytes_recv = %f/sec\n",
+	XAVG(icp.r_kbytes_recv.kb));
     x = statHistDeltaMedian(&l->icp.query_svc_time, &f->icp.query_svc_time);
     storeAppendPrintf(sentry, "icp.query_median_svc_time = %f seconds\n",
 	x / 1000000.0);
