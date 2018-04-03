 
             storeAppendPrintf(sentry, "PINGS ACKED: %8d %3d%%\n",
                               e->stats.pings_acked,
-                              percent(e->stats.pings_acked, e->stats.pings_sent));
+                              Math::intPercent(e->stats.pings_acked, e->stats.pings_sent));
         }
 
-        storeAppendPrintf(sentry, "IGNORED    : %8d %3d%%\n",
-                          e->stats.ignored_replies,
-                          percent(e->stats.ignored_replies, e->stats.pings_acked));
+        storeAppendPrintf(sentry, "IGNORED    : %8d %3d%%\n", e->stats.ignored_replies, Math::intPercent(e->stats.ignored_replies, e->stats.pings_acked));
 
         if (!e->options.no_query) {
             storeAppendPrintf(sentry, "Histogram of PINGS ACKED:\n");
