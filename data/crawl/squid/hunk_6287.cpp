 	store_check_cachable_hist.no.too_big);
     storeAppendPrintf(sentry, "no.private_key\t%d\n",
 	store_check_cachable_hist.no.private_key);
-    storeAppendPrintf(sentry, "no.http_median_too_high\t%d\n",
-	store_check_cachable_hist.no.http_median_too_high);
+    storeAppendPrintf(sentry, "no.too_many_open_files\t%d\n",
+	store_check_cachable_hist.no.too_many_open_files);
     storeAppendPrintf(sentry, "no.lru_age_too_low\t%d\n",
 	store_check_cachable_hist.no.lru_age_too_low);
     storeAppendPrintf(sentry, "yes.default\t%d\n",
