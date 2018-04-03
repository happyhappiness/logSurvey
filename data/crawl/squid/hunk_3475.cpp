                               "        %-20.20s %7d %3d%%\n",
                               log_tags[l],
                               c->Http.result_hist[l],
-                              percent(c->Http.result_hist[l], c->Http.n_requests));
+                              Math::intPercent(c->Http.result_hist[l], c->Http.n_requests));
         }
 
         storeAppendPrintf(sentry, "\n");
     }
 
     storeAppendPrintf(sentry, "TOTALS\n");
     storeAppendPrintf(sentry, "ICP : %d Queries, %d Hits (%3d%%)\n",
-                      icp_total, icp_hits, percent(icp_hits, icp_total));
+                      icp_total, icp_hits, Math::intPercent(icp_hits, icp_total));
     storeAppendPrintf(sentry, "HTTP: %d Requests, %d Hits (%3d%%)\n",
-                      http_total, http_hits, percent(http_hits, http_total));
+                      http_total, http_hits, Math::intPercent(http_hits, http_total));
 }
 
 static void
