 	return REFRESH_DEFAULT_MAX;
 }
 
+static void
+refreshCountsStats(StoreEntry * sentry, struct RefreshCounts *rc)
+{
+    storeAppendPrintf(sentry, "\n\n%s histogram:\n", rc->proto);
+    storeAppendPrintf(sentry, "Category\tCount\t%%Total\n");
+
+    storeAppendPrintf(sentry, "revalidate_stale\t%6d\t%6.2f\n",
+	rc->revalidate_stale, xpercent(rc->revalidate_stale, rc->total));
+    storeAppendPrintf(sentry, "request_max_age_stale\t%6d\t%6.2f\n",
+	rc->request_max_age_stale, xpercent(rc->revalidate_stale, rc->total));
+    storeAppendPrintf(sentry, "response_expires_stale\t%6d\t%6.2f\n",
+	rc->response_expires_stale, xpercent(rc->revalidate_stale, rc->total));
+    storeAppendPrintf(sentry, "response_expires_fresh\t%6d\t%6.2f\n",
+	rc->response_expires_fresh, xpercent(rc->response_expires_fresh, rc->total));
+    storeAppendPrintf(sentry, "conf_max_age_stale\t%6d\t%6.2f\n",
+	rc->conf_max_age_stale, xpercent(rc->conf_max_age_stale, rc->total));
+    storeAppendPrintf(sentry, "last_modified_factor_fresh\t%6d\t%6.2f\n",
+	rc->last_modified_factor_fresh, xpercent(rc->last_modified_factor_fresh, rc->total));
+    storeAppendPrintf(sentry, "last_modified_factor_stale\t%6d\t%6.2f\n",
+	rc->last_modified_factor_stale, xpercent(rc->last_modified_factor_stale, rc->total));
+    storeAppendPrintf(sentry, "conf_min_age_fresh\t%6d\t%6.2f\n",
+	rc->conf_min_age_fresh, xpercent(rc->conf_min_age_fresh, rc->total));
+    storeAppendPrintf(sentry, "default_stale\t%6d\t%6.2f\n",
+	rc->default_stale, xpercent(rc->default_stale, rc->total));
+    storeAppendPrintf(sentry, "total\t%6d\t%6.2f\n",
+	rc->total, xpercent(rc->total, rc->total));
+}
+
 static void
 refreshStats(StoreEntry * sentry)
 {
-    storeAppendPrintf(sentry, "refreshCounts.total\t%d\n",
-	refreshCounts.total);
-    storeAppendPrintf(sentry, "refreshCounts.revalidate_stale\t%d\n",
-	refreshCounts.revalidate_stale);
-    storeAppendPrintf(sentry, "refreshCounts.request_max_age_stale\t%d\n",
-	refreshCounts.request_max_age_stale);
-    storeAppendPrintf(sentry, "refreshCounts.response_expires_stale\t%d\n",
-	refreshCounts.response_expires_stale);
-    storeAppendPrintf(sentry, "refreshCounts.response_expires_fresh\t%d\n",
-	refreshCounts.response_expires_fresh);
-    storeAppendPrintf(sentry, "refreshCounts.conf_max_age_stale\t%d\n",
-	refreshCounts.conf_max_age_stale);
-    storeAppendPrintf(sentry, "refreshCounts.last_modified_factor_fresh\t%d\n",
-	refreshCounts.last_modified_factor_fresh);
-    storeAppendPrintf(sentry, "refreshCounts.last_modified_factor_stale\t%d\n",
-	refreshCounts.last_modified_factor_stale);
-    storeAppendPrintf(sentry, "refreshCounts.conf_min_age_fresh\t%d\n",
-	refreshCounts.conf_min_age_fresh);
-    storeAppendPrintf(sentry, "refreshCounts.default_stale\t%d\n",
-	refreshCounts.default_stale);
+    int i;
+    int total = 0;
+
+    /* get total usage count */
+    for (i = 0; i < rcCount; ++i)
+	total += refreshCounts[i].total;
+
+    /* protocol usage histogram */
+    storeAppendPrintf(sentry, "\nRefreshCheck calls per protocol\n\n");
+    storeAppendPrintf(sentry, "Protocol\t#Calls\t%%Calls\n");
+    for (i = 0; i < rcCount; ++i)
+	storeAppendPrintf(sentry, "%10s\t%6d\t%6.2f\n",
+	    refreshCounts[i].proto,
+	    refreshCounts[i].total, 
+	    xpercent(refreshCounts[i].total, total));
+
+    /* per protocol histograms */
+    storeAppendPrintf(sentry, "\n\nRefreshCheck histograms for various protocols\n");
+    for (i = 0; i < rcCount; ++i)
+	refreshCountsStats(sentry, refreshCounts + i);
 }
 
 void
-refreshInit(void)
+refreshInit()
 {
+    memset(refreshCounts, 0, sizeof(refreshCounts));
+    refreshCounts[rcHTTP].proto = "HTTP";
+    refreshCounts[rcICP].proto = "ICP";
+    refreshCounts[rcCDigest].proto = "Cache Digests";
+
     cachemgrRegister("refresh",
 	"Refresh Algorithm Statistics",
 	refreshStats,
