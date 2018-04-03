     else
 	return REFRESH_DEFAULT_MAX;
 }
+
+static void
+refreshStats(StoreEntry * sentry)
+{
+    storeAppendPrintf(sentry, "refreshCounts.total\t%d\n",
+	refreshCounts.total);
+    storeAppendPrintf(sentry, "refreshCounts.revalidate_stale\t%d\n",
+	refreshCounts.revalidate_stale);
+    storeAppendPrintf(sentry, "refreshCounts.request_max_age_stale\t%d\n",
+	refreshCounts.request_max_age_stale);
+    storeAppendPrintf(sentry, "refreshCounts.response_expires_stale\t%d\n",
+	refreshCounts.response_expires_stale);
+    storeAppendPrintf(sentry, "refreshCounts.response_expires_fresh\t%d\n",
+	refreshCounts.response_expires_fresh);
+    storeAppendPrintf(sentry, "refreshCounts.conf_max_age_stale\t%d\n",
+	refreshCounts.conf_max_age_stale);
+    storeAppendPrintf(sentry, "refreshCounts.last_modified_factor_fresh\t%d\n",
+	refreshCounts.last_modified_factor_fresh);
+    storeAppendPrintf(sentry, "refreshCounts.last_modified_factor_stale\t%d\n",
+	refreshCounts.last_modified_factor_stale);
+    storeAppendPrintf(sentry, "refreshCounts.conf_min_age_fresh\t%d\n",
+	refreshCounts.conf_min_age_fresh);
+    storeAppendPrintf(sentry, "refreshCounts.default_stale\t%d\n",
+	refreshCounts.default_stale);
+}
+
+void
+refreshInit(void)
+{
+    cachemgrRegister("refresh",
+	"Refresh Algorithm Statistics",
+	refreshStats,
+	0,
+	1);
+}
