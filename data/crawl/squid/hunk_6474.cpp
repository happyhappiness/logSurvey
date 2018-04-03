     storeAppendPrintf(sentry, "client_http.hit_median_svc_time = %f seconds\n",
 	x / 1000.0);
 #if SQUID_PEER_DIGEST
+    storeAppendPrintf(sentry, "cd.msgs_sent = %f/sec\n",
+	XAVG(cd.msgs_sent));
+    storeAppendPrintf(sentry, "cd.msgs_recv = %f/sec\n",
+	XAVG(cd.msgs_recv));
+    storeAppendPrintf(sentry, "cd.kbytes_sent = %f/sec\n",
+	XAVG(cd.kbytes_sent.kb));
+    storeAppendPrintf(sentry, "cd.kbytes_recv = %f/sec\n",
+	XAVG(cd.kbytes_recv.kb));
     x = statHistDeltaMedian(&l->cd.client_svc_time,
 	&f->cd.client_svc_time);
     storeAppendPrintf(sentry, "cd.client_median_svc_time = %f seconds\n",
