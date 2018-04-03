             if (e->options.htcp) {
                 storeAppendPrintf(sentry, "\tMisses\t%8d %3d%%\n",
                                   e->htcp.counts[0],
-                                  percent(e->htcp.counts[0], e->stats.pings_acked));
+                                  Math::intPercent(e->htcp.counts[0], e->stats.pings_acked));
                 storeAppendPrintf(sentry, "\tHits\t%8d %3d%%\n",
                                   e->htcp.counts[1],
-                                  percent(e->htcp.counts[1], e->stats.pings_acked));
+                                  Math::intPercent(e->htcp.counts[1], e->stats.pings_acked));
             } else {
 #endif
 
