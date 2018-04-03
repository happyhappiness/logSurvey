 static void
 refreshCountsStats(StoreEntry * sentry, struct RefreshCounts *rc)
 {
+    int sum = 0;
+    int tot = rc->total;
+
     storeAppendPrintf(sentry, "\n\n%s histogram:\n", rc->proto);
     storeAppendPrintf(sentry, "Category\tCount\t%%Total\n");
 
-    storeAppendPrintf(sentry, "revalidate_stale\t%6d\t%6.2f\n",
-	rc->revalidate_stale, xpercent(rc->revalidate_stale, rc->total));
-    storeAppendPrintf(sentry, "request_max_age_stale\t%6d\t%6.2f\n",
-	rc->request_max_age_stale, xpercent(rc->request_max_age_stale, rc->total));
-    storeAppendPrintf(sentry, "response_expires_stale\t%6d\t%6.2f\n",
-	rc->response_expires_stale, xpercent(rc->response_expires_stale, rc->total));
-    storeAppendPrintf(sentry, "response_expires_fresh\t%6d\t%6.2f\n",
-	rc->response_expires_fresh, xpercent(rc->response_expires_fresh, rc->total));
-    storeAppendPrintf(sentry, "conf_max_age_stale\t%6d\t%6.2f\n",
-	rc->conf_max_age_stale, xpercent(rc->conf_max_age_stale, rc->total));
-    storeAppendPrintf(sentry, "last_modified_factor_fresh\t%6d\t%6.2f\n",
-	rc->last_modified_factor_fresh, xpercent(rc->last_modified_factor_fresh, rc->total));
-    storeAppendPrintf(sentry, "last_modified_factor_stale\t%6d\t%6.2f\n",
-	rc->last_modified_factor_stale, xpercent(rc->last_modified_factor_stale, rc->total));
-    storeAppendPrintf(sentry, "conf_min_age_fresh\t%6d\t%6.2f\n",
-	rc->conf_min_age_fresh, xpercent(rc->conf_min_age_fresh, rc->total));
-    storeAppendPrintf(sentry, "default_stale\t%6d\t%6.2f\n",
-	rc->default_stale, xpercent(rc->default_stale, rc->total));
-    storeAppendPrintf(sentry, "total\t%6d\t%6.2f\n",
-	rc->total, xpercent(rc->total, rc->total));
+#define refreshCountsStatsEntry(name) { \
+    if (rc->name || !strcmp(#name, "total")) \
+	storeAppendPrintf(sentry, "%s\t%6d\t%6.2f\n", \
+	    #name, rc->name, xpercent(rc->name, tot)); \
+    sum += rc->name; \
+}
+    refreshCountsStatsEntry(revalidate_stale);
+    refreshCountsStatsEntry(request_reload2ims_stale);
+    refreshCountsStatsEntry(request_reload_stale);
+    refreshCountsStatsEntry(request_max_age_stale);
+    refreshCountsStatsEntry(min_age_override_exp_fresh);
+    refreshCountsStatsEntry(response_expires_stale);
+    refreshCountsStatsEntry(response_expires_fresh);
+    refreshCountsStatsEntry(conf_max_age_stale);
+    refreshCountsStatsEntry(min_age_override_lmt_fresh);
+    refreshCountsStatsEntry(last_modified_factor_fresh);
+    refreshCountsStatsEntry(last_modified_factor_stale);
+    refreshCountsStatsEntry(conf_min_age_fresh);
+    refreshCountsStatsEntry(default_stale);
+    tot = sum; /* paranoid: "total" line shows 100% if we forgot nothing */
+    refreshCountsStatsEntry(total);
 }
 
 static void