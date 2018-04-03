     x = statLogHistDeltaMedian(&l->icp.svc_time, &f->icp.svc_time);
     storeAppendPrintf(sentry, "icp.median_svc_time = %f seconds\n",
 	x / 1000000.0);
+    x = statLogHistDeltaMedian(&l->dns.svc_time, &f->dns.svc_time);
+    storeAppendPrintf(sentry, "dns.median_svc_time = %f seconds\n",
+	x / 1000000.0);
     storeAppendPrintf(sentry, "unlink.requests = %f/sec\n",
 	XAVG(unlink.requests));
     storeAppendPrintf(sentry, "page_faults = %f/sec\n",
