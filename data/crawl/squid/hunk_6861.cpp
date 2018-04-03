     NCountHist++;
 }
 
-#define XAVG(X) (double) (f->X - l->X) / dt
 void
-statAvgDump(StoreEntry * sentry)
+statAvg5min(StoreEntry *e)
 {
-    StatCounters *f = &CountHist[0];
-    StatCounters *l = &CountHist[N_COUNT_HIST - 1];
-    double dt;
-    double ct;
-    eventDelete(statAvgTick, NULL);
-    statAvgTick(NULL);
-    dt = tvSubDsec(l->timestamp, f->timestamp);
-    ct = f->cputime - l->cputime;
-    storeBuffer(sentry);
-    storeAppendPrintf(sentry, "client_http.requests = %f/sec\n",
-	XAVG(client_http.requests));
-    storeAppendPrintf(sentry, "client_http.hits = %f/sec\n",
-	XAVG(client_http.hits));
-    storeAppendPrintf(sentry, "client_http.errors = %f/sec\n",
-	XAVG(client_http.errors));
-    storeAppendPrintf(sentry, "client_http.bytes_in = %f/sec\n",
-	XAVG(client_http.bytes_in));
-    storeAppendPrintf(sentry, "client_http.bytes_out = %f/sec\n",
-	XAVG(client_http.bytes_out));
-    storeAppendPrintf(sentry, "icp.pkts_sent = %f/sec\n",
-	XAVG(icp.pkts_sent));
-    storeAppendPrintf(sentry, "icp.pkts_recv = %f/sec\n",
-	XAVG(icp.pkts_recv));
-    storeAppendPrintf(sentry, "icp.bytes_sent = %f/sec\n",
-	XAVG(icp.bytes_sent));
-    storeAppendPrintf(sentry, "icp.bytes_recv = %f/sec\n",
-	XAVG(icp.bytes_recv));
-    storeAppendPrintf(sentry, "unlink.requests = %f/sec\n",
-	XAVG(unlink.requests));
-    storeAppendPrintf(sentry, "page_faults = %f/sec\n",
-	XAVG(page_faults));
-    storeAppendPrintf(sentry, "select_loops = %f/sec\n",
-	XAVG(select_loops));
-    storeAppendPrintf(sentry, "cpu_time = %f seconds\n", ct);
-    storeAppendPrintf(sentry, "wall_time = %f seconds\n", dt);
-    storeAppendPrintf(sentry, "cpu_usage = %f%%\n", 100.0*ct/dt);
-    storeBufferFlush(sentry);
+#if NOT_YET
+	statCountersDump(e);
+	storeAppendPrintf(e, "\n");
+#endif
+	statAvgDump(e, 5);
+}
+
+void
+statAvg60min(StoreEntry *e)
+{
+#if NOT_YET
+	statCountersDump(e);
+	storeAppendPrintf(e, "\n");
+#endif
+	statAvgDump(e, 60);
 }
