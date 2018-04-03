 
 /* local prototypes */
 static void storeDigestRebuildStart(void *datanotused);
-static void storeDigestRebuildResume();
-static void storeDigestRebuildFinish();
+static void storeDigestRebuildResume(void);
+static void storeDigestRebuildFinish(void);
 static void storeDigestRebuildStep(void *datanotused);
-static void storeDigestRewriteStart();
-static void storeDigestRewriteResume();
+static void storeDigestRewriteStart(void *);
+static void storeDigestRewriteResume(void);
 static void storeDigestRewriteFinish(StoreEntry * e);
 static EVH storeDigestSwapOutStep;
 static void storeDigestCBlockSwapOut(StoreEntry * e);
-static int storeDigestCalcCap();
-static int storeDigestResize();
+static int storeDigestCalcCap(void);
+static int storeDigestResize(void);
+static void storeDigestAdd(const StoreEntry *);
 
+#endif /* USE_CACHE_DIGESTS */
+
+/*
+ * PUBLIC FUNCTIONS
+ */
 
 void
-storeDigestInit()
+storeDigestInit(void)
 {
 #if USE_CACHE_DIGESTS
     const int cap = storeDigestCalcCap();
     store_digest = cacheDigestCreate(cap, StoreDigestBitsPerEntry);
     debug(71, 1) ("Local cache digest enabled; rebuild/rewrite every %d/%d sec\n",
 	StoreDigestRebuildPeriod, StoreDigestRewritePeriod);
-#else
-    store_digest = NULL;
-    debug(71, 1) ("Local cache digest is 'off'\n");
-#endif
     memset(&sd_state, 0, sizeof(sd_state));
     cachemgrRegister("store_digest", "Store Digest",
 	storeDigestReport, 0);
+#else
+    store_digest = NULL;
+    debug(71, 3) ("Local cache digest is 'off'\n");
+#endif
 }
 
 /* called when store_rebuild completes */
 void
-storeDigestNoteStoreReady()
+storeDigestNoteStoreReady(void)
 {
+#if USE_CACHE_DIGESTS
     storeDigestRebuildStart(NULL);
     storeDigestRewriteStart(NULL);
+#endif
+}
+
+void
+storeDigestDel(const StoreEntry * entry)
+{
+#if USE_CACHE_DIGESTS
+    assert(entry && store_digest);
+    debug(71, 6) ("storeDigestDel: checking entry, key: %s\n",
+	storeKeyText(entry->key));
+    if (!EBIT_TEST(entry->flag, KEY_PRIVATE)) {
+	if (!cacheDigestTest(store_digest, entry->key)) {
+	    sd_stats.del_lost_count++;
+	    debug(71, 6) ("storeDigestDel: lost entry, key: %s url: %s\n",
+		storeKeyText(entry->key), storeUrl(entry));
+	} else {
+	    sd_stats.del_count++;
+	    cacheDigestDel(store_digest, entry->key);
+	    debug(71, 6) ("storeDigestDel: deled entry, key: %s\n",
+		storeKeyText(entry->key));
+	}
+    }
+#endif
 }
 
 void
+storeDigestReport(StoreEntry * e)
+{
+#if USE_CACHE_DIGESTS
+    if (store_digest) {
+	cacheDigestReport(store_digest, "store", e);
+	storeAppendPrintf(e, "\t added: %d rejected: %d ( %.2f %%) del-ed: %d\n",
+	    sd_stats.add_count,
+	    sd_stats.rej_count,
+	    xpercent(sd_stats.rej_count, sd_stats.rej_count + sd_stats.add_count),
+	    sd_stats.del_count);
+	storeAppendPrintf(e, "\t collisions: on add: %.2f %% on rej: %.2f %%\n",
+	    xpercent(sd_stats.add_coll_count, sd_stats.add_count),
+	    xpercent(sd_stats.rej_coll_count, sd_stats.rej_count));
+    } else {
+	storeAppendPrintf(e, "store digest: disabled.\n");
+    }
+#endif
+}
+
+/*
+ * LOCAL FUNCTIONS
+ */
+
+#if USE_CACHE_DIGESTS
+
+static void
 storeDigestAdd(const StoreEntry * entry)
 {
     int good_entry = 0;
