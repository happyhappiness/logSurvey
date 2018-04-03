 	storeAppendPrintf(sentry, "\n");
 	c = (ClientInfo *) hash_next(client_table);
     }
+    storeAppendPrintf(sentry, "TOTALS\n");
+    storeAppendPrintf(sentry, "ICP : %d Queries, %d Hits (%3d%%)\n",
+	icp_total, icp_hits, percent(icp_hits, icp_total));
+    storeAppendPrintf(sentry, "HTTP: %d Requests, %d Hits (%3d%%)\n",
+	http_total, http_hits, percent(http_hits, http_total));
 }
 
 static void