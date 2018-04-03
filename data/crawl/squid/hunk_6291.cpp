     storeAppend(e, buf, strlen(buf));
 }
 
+struct _store_check_cachable_hist {
+    struct {
+	int non_get;
+	int not_entry_cachable;
+	int release_request;
+	int wrong_content_length;
+	int negative_cached;
+	int too_big;
+	int private_key;
+	int http_median_too_high;
+	int lru_age_too_low;
+    } no;
+    struct {
+	int Default;
+    } yes;
+} store_check_cachable_hist;
+
 int
 storeCheckCachable(StoreEntry * e)
 {
 #if CACHE_ALL_METHODS
     if (e->mem_obj->method != METHOD_GET) {
 	debug(20, 2) ("storeCheckCachable: NO: non-GET method\n");
+	store_check_cachable_hist.no.non_get++;
     } else
 #endif
     if (!EBIT_TEST(e->flag, ENTRY_CACHABLE)) {
 	debug(20, 2) ("storeCheckCachable: NO: not cachable\n");
+	store_check_cachable_hist.no.not_entry_cachable++;
     } else if (EBIT_TEST(e->flag, RELEASE_REQUEST)) {
 	debug(20, 2) ("storeCheckCachable: NO: release requested\n");
+	store_check_cachable_hist.no.release_request++;
     } else if (e->store_status == STORE_OK && EBIT_TEST(e->flag, ENTRY_BAD_LENGTH)) {
 	debug(20, 2) ("storeCheckCachable: NO: wrong content-length\n");
+	store_check_cachable_hist.no.wrong_content_length++;
     } else if (EBIT_TEST(e->flag, ENTRY_NEGCACHED)) {
 	debug(20, 3) ("storeCheckCachable: NO: negative cached\n");
+	store_check_cachable_hist.no.negative_cached++;
 	return 0;		/* avoid release call below */
     } else if (e->mem_obj->inmem_hi > Config.Store.maxObjectSize) {
 	debug(20, 2) ("storeCheckCachable: NO: too big\n");
+	store_check_cachable_hist.no.too_big++;
     } else if (EBIT_TEST(e->flag, KEY_PRIVATE)) {
 	debug(20, 3) ("storeCheckCachable: NO: private key\n");
+	store_check_cachable_hist.no.private_key++;
+    } else if (statMedianSvc(5, MEDIAN_HTTP) > 2000.0) {
+	debug(20, 2) ("storeCheckCachable: NO: median HTTP svc time = %d\n",
+	    statMedianSvc(5, MEDIAN_HTTP));
+	store_check_cachable_hist.no.http_median_too_high++;
     } else if (storeExpiredReferenceAge() < 300) {
 	debug(20, 2) ("storeCheckCachable: NO: LRU Age = %d\n",
 	    storeExpiredReferenceAge());
+	store_check_cachable_hist.no.lru_age_too_low++;
     } else {
+	store_check_cachable_hist.yes.Default++;
 	return 1;
     }
     storeReleaseRequest(e);
     EBIT_CLR(e->flag, ENTRY_CACHABLE);
     return 0;
 }
 
+static void
+storeCheckCachableStats(StoreEntry * sentry)
+{
+    storeAppendPrintf(sentry, "no.non_get\t%d\n",
+	store_check_cachable_hist.no.non_get);
+    storeAppendPrintf(sentry, "no.not_entry_cachable\t%d\n",
+	store_check_cachable_hist.no.not_entry_cachable);
+    storeAppendPrintf(sentry, "no.release_request\t%d\n",
+	store_check_cachable_hist.no.release_request);
+    storeAppendPrintf(sentry, "no.wrong_content_length\t%d\n",
+	store_check_cachable_hist.no.wrong_content_length);
+    storeAppendPrintf(sentry, "no.negative_cached\t%d\n",
+	store_check_cachable_hist.no.negative_cached);
+    storeAppendPrintf(sentry, "no.too_big\t%d\n",
+	store_check_cachable_hist.no.too_big);
+    storeAppendPrintf(sentry, "no.private_key\t%d\n",
+	store_check_cachable_hist.no.private_key);
+    storeAppendPrintf(sentry, "no.http_median_too_high\t%d\n",
+	store_check_cachable_hist.no.http_median_too_high);
+    storeAppendPrintf(sentry, "no.lru_age_too_low\t%d\n",
+	store_check_cachable_hist.no.lru_age_too_low);
+    storeAppendPrintf(sentry, "yes.default\t%d\n",
+	store_check_cachable_hist.yes.Default);
+}
+
 /* Complete transfer into the local cache.  */
 void
 storeComplete(StoreEntry * e)
