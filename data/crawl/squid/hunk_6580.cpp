 	XAVG(icp.pkts_sent));
     storeAppendPrintf(sentry, "icp.pkts_recv = %f/sec\n",
 	XAVG(icp.pkts_recv));
+    storeAppendPrintf(sentry, "icp.replies_queued = %f/sec\n",
+	XAVG(icp.replies_queued));
     storeAppendPrintf(sentry, "icp.kbytes_sent = %f/sec\n",
 	XAVG(icp.kbytes_sent.kb));
     storeAppendPrintf(sentry, "icp.kbytes_recv = %f/sec\n",