 #endif
 }
 
-static void
-service_times(StoreEntry * sentry)
+void
+GetServiceTimesStats(Mgr::ServiceTimesActionData& stats)
+{
+    for (int i = 0; i < Mgr::ServiceTimesActionData::seriesSize; ++i) {
+        double p = (i + 1) * 5 / 100.0;
+        stats.http_requests5[i] = statPctileSvc(p, 5, PCTILE_HTTP);
+        stats.http_requests60[i] = statPctileSvc(p, 60, PCTILE_HTTP);
+
+        stats.cache_misses5[i] = statPctileSvc(p, 5, PCTILE_MISS);
+        stats.cache_misses60[i] = statPctileSvc(p, 60, PCTILE_MISS);
+
+        stats.cache_hits5[i] = statPctileSvc(p, 5, PCTILE_HIT);
+        stats.cache_hits60[i] = statPctileSvc(p, 60, PCTILE_HIT);
+
+        stats.near_hits5[i] = statPctileSvc(p, 5, PCTILE_NH);
+        stats.near_hits60[i] = statPctileSvc(p, 60, PCTILE_NH);
+
+        stats.not_modified_replies5[i] = statPctileSvc(p, 5, PCTILE_NM);
+        stats.not_modified_replies60[i] = statPctileSvc(p, 60, PCTILE_NM);
+
+        stats.dns_lookups5[i] = statPctileSvc(p, 5, PCTILE_DNS);
+        stats.dns_lookups60[i] = statPctileSvc(p, 60, PCTILE_DNS);
+
+        stats.icp_queries5[i] = statPctileSvc(p, 5, PCTILE_ICP_QUERY);
+        stats.icp_queries60[i] = statPctileSvc(p, 60, PCTILE_ICP_QUERY);
+    }
+}
+
+void
+DumpServiceTimesStats(Mgr::ServiceTimesActionData& stats, StoreEntry* sentry)
 {
-    int p;
     storeAppendPrintf(sentry, "Service Time Percentiles            5 min    60 min:\n");
-    for (p = 5; p < 100; p += 5) {
+    double fct = stats.count > 1 ? stats.count * 1000.0 : 1000.0;
+    for (int i = 0; i < Mgr::ServiceTimesActionData::seriesSize; ++i) {
         storeAppendPrintf(sentry, "\tHTTP Requests (All):  %2d%%  %8.5f %8.5f\n",
-                          p,
-                          statPctileSvc((double) p / 100.0, 5, PCTILE_HTTP) / 1000.0,
-                          statPctileSvc((double) p / 100.0, 60, PCTILE_HTTP) / 1000.0);
+                          (i + 1) * 5,
+                          stats.http_requests5[i] / fct,
+                          stats.http_requests60[i] / fct);
     }
-    for (p = 5; p < 100; p += 5) {
+    for (int i = 0; i < Mgr::ServiceTimesActionData::seriesSize; ++i) {
         storeAppendPrintf(sentry, "\tCache Misses:         %2d%%  %8.5f %8.5f\n",
-                          p,
-                          statPctileSvc((double) p / 100.0, 5, PCTILE_MISS) / 1000.0,
-                          statPctileSvc((double) p / 100.0, 60, PCTILE_MISS) / 1000.0);
+                          (i + 1) * 5,
+                          stats.cache_misses5[i] / fct,
+                          stats.cache_misses60[i] / fct);
     }
-    for (p = 5; p < 100; p += 5) {
+    for (int i = 0; i < Mgr::ServiceTimesActionData::seriesSize; ++i) {
         storeAppendPrintf(sentry, "\tCache Hits:           %2d%%  %8.5f %8.5f\n",
-                          p,
-                          statPctileSvc((double) p / 100.0, 5, PCTILE_HIT) / 1000.0,
-                          statPctileSvc((double) p / 100.0, 60, PCTILE_HIT) / 1000.0);
+                          (i + 1) * 5,
+                          stats.cache_hits5[i] / fct,
+                          stats.cache_hits60[i] / fct);
     }
-    for (p = 5; p < 100; p += 5) {
+    for (int i = 0; i < Mgr::ServiceTimesActionData::seriesSize; ++i) {
         storeAppendPrintf(sentry, "\tNear Hits:            %2d%%  %8.5f %8.5f\n",
-                          p,
-                          statPctileSvc((double) p / 100.0, 5, PCTILE_NH) / 1000.0,
-                          statPctileSvc((double) p / 100.0, 60, PCTILE_NH) / 1000.0);
+                          (i + 1) * 5,
+                          stats.near_hits5[i] / fct,
+                          stats.near_hits60[i] / fct);
     }
-    for (p = 5; p < 100; p += 5) {
+    for (int i = 0; i < Mgr::ServiceTimesActionData::seriesSize; ++i) {
         storeAppendPrintf(sentry, "\tNot-Modified Replies: %2d%%  %8.5f %8.5f\n",
-                          p,
-                          statPctileSvc((double) p / 100.0, 5, PCTILE_NM) / 1000.0,
-                          statPctileSvc((double) p / 100.0, 60, PCTILE_NM) / 1000.0);
+                          (i + 1) * 5,
+                          stats.not_modified_replies5[i] / fct,
+                          stats.not_modified_replies60[i] / fct);
     }
-    for (p = 5; p < 100; p += 5) {
+    for (int i = 0; i < Mgr::ServiceTimesActionData::seriesSize; ++i) {
         storeAppendPrintf(sentry, "\tDNS Lookups:          %2d%%  %8.5f %8.5f\n",
-                          p,
-                          statPctileSvc((double) p / 100.0, 5, PCTILE_DNS) / 1000.0,
-                          statPctileSvc((double) p / 100.0, 60, PCTILE_DNS) / 1000.0);
+                          (i + 1) * 5,
+                          stats.dns_lookups5[i] / fct,
+                          stats.dns_lookups60[i] / fct);
     }
-    for (p = 5; p < 100; p += 5) {
+    fct = stats.count > 1 ? stats.count * 1000000.0 : 1000000.0;
+    for (int i = 0; i < Mgr::ServiceTimesActionData::seriesSize; ++i) {
         storeAppendPrintf(sentry, "\tICP Queries:          %2d%%  %8.5f %8.5f\n",
-                          p,
-                          statPctileSvc((double) p / 100.0, 5, PCTILE_ICP_QUERY) / 1000000.0,
-                          statPctileSvc((double) p / 100.0, 60, PCTILE_ICP_QUERY) / 1000000.0);
+                          (i + 1) * 5,
+                          stats.icp_queries5[i] / fct,
+                          stats.icp_queries60[i] / fct);
     }
 }
 
-#define XAVG(X) (dt ? (double) (f->X - l->X) / dt : 0.0)
 static void
 statAvgDump(StoreEntry * sentry, int minutes, int hours)
+{
+    Mgr::IntervalActionData stats;
+    GetAvgStat(stats, minutes, hours);
+    DumpAvgStat(stats, sentry);
+}
+
+#define XAVG(X) (dt ? (double) (f->X - l->X) / dt : 0.0)
+void
+GetAvgStat(Mgr::IntervalActionData& stats, int minutes, int hours)
 {
     StatCounters *f;
     StatCounters *l;
     double dt;
     double ct;
-    double x;
     assert(N_COUNT_HIST > 1);
     assert(minutes > 0 || hours > 0);
     f = &CountHist[0];
