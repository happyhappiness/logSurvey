 	store_check_cachable_hist.no.private_key);
     storeAppendPrintf(sentry, "no.too_many_open_files\t%d\n",
 	store_check_cachable_hist.no.too_many_open_files);
+    storeAppendPrintf(sentry, "no.too_many_open_fds\t%d\n",
+	store_check_cachable_hist.no.too_many_open_fds);
     storeAppendPrintf(sentry, "no.lru_age_too_low\t%d\n",
 	store_check_cachable_hist.no.lru_age_too_low);
     storeAppendPrintf(sentry, "yes.default\t%d\n",