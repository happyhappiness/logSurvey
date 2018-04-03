 
     storeAppendPrintf(sentry, "CPU Profiling Statistics:\n");
     storeAppendPrintf(sentry,
-	"  (CPU times are in arbitrary units, most probably in CPU clock ticks)\n");
+                      "  (CPU times are in arbitrary units, most probably in CPU clock ticks)\n");
     storeAppendPrintf(sentry,
-	"Probe Name\t Event Count\t last Interval \t Avg Interval \t since squid start \t (since system boot) \n");
+                      "Probe Name\t Event Count\t last Interval \t Avg Interval \t since squid start \t (since system boot) \n");
     storeAppendPrintf(sentry, "Total\t %lu\t %llu \t %llu \t %llu \t %llu\n",
-	(long unsigned) xprof_events,
-	xprof_delta,
-	xprof_average_delta,
-	now - xprof_verystart,
-	now);
+                      (long unsigned) xprof_events,
+                      xprof_delta,
+                      xprof_average_delta,
+                      now - xprof_verystart,
+                      now);
 
     xprof_summary_item(sentry, "Last 1 sec averages", xprof_stats_avg1sec);
     xprof_summary_item(sentry, "Last 5 sec averages", xprof_stats_avg5sec);
