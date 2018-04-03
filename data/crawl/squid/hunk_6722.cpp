     storeAppendPrintf(sentry, "cpu_usage = %f%%\n", dpercent(ct, dt));
 }
 
-static void
-statCounterInit(StatCounters * C)
-{
-    C->timestamp = current_time;
-    /*
-     * HTTP svc_time hist is kept in milli-seconds; max of 3 hours.
-     */
-    statLogHistInit(&C->client_http.all_svc_time, 0.0, 3600000.0 * 3.0);
-    statLogHistInit(&C->client_http.miss_svc_time, 0.0, 3600000.0 * 3.0);
-    statLogHistInit(&C->client_http.nm_svc_time, 0.0, 3600000.0 * 3.0);
-    statLogHistInit(&C->client_http.hit_svc_time, 0.0, 3600000.0 * 3.0);
-    /*
-     * ICP svc_time hist is kept in micro-seconds; max of 1 minute.
-     */
-    statLogHistInit(&C->icp.query_svc_time, 0.0, 1000000.0 * 60.0);
-    statLogHistInit(&C->icp.reply_svc_time, 0.0, 1000000.0 * 60.0);
-    /*
-     * DNS svc_time hist is kept in milli-seconds; max of 10 minutes.
-     */
-    statLogHistInit(&C->dns.svc_time, 0.0, 60000.0 * 10.0);
-}
-
 void
 statInit(void)
 {
     int i;
     debug(18, 5) ("statInit: Initializing...\n");
     memset(CountHist, '\0', N_COUNT_HIST * sizeof(StatCounters));
     for (i = 0; i < N_COUNT_HIST; i++)
-	statCounterInit(&CountHist[i]);
-    statCounterInit(&Counter);
+	statCountersInit(&CountHist[i]);
+    statCountersInit(&Counter);
     eventAdd("statAvgTick", statAvgTick, NULL, 60);
     cachemgrRegister("info",
 	"General Runtime Information",
