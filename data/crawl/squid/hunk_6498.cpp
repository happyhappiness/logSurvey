 	 * fname, scanned_count, method, buf); */
 	return frError;
     }
-    while (*url) url--;
+    while (*url)
+	url--;
     url++;
     *hier = '\0';
     hier += 3;
     *strchr(hier, '/') = '\0';
     /*fprintf(stdout, "%s:%d: %s %s %s\n",
      * fname, count, method, url, hier); */
-    entry->use_icp =  strcmp(hier, "NONE");
-	/* no ICP lookup for these status codes */
-/*	strcmp(hier, "NONE") &&
-	strcmp(hier, "DIRECT") &&
-	strcmp(hier, "FIREWALL_IP_DIRECT") &&
-	strcmp(hier, "LOCAL_IP_DIRECT") &&
-	strcmp(hier, "NO_DIRECT_FAIL") &&
-	strcmp(hier, "NO_PARENT_DIRECT") &&
-	strcmp(hier, "SINGLE_PARENT") &&
-	strcmp(hier, "PASSTHROUGH_PARENT") &&
-	strcmp(hier, "SSL_PARENT_MISS") &&
-	strcmp(hier, "DEFAULT_PARENT");
-*/
+    entry->use_icp = strcmp(hier, "NONE");
+    /* no ICP lookup for these status codes */
+/*      strcmp(hier, "NONE") &&
+ * strcmp(hier, "DIRECT") &&
+ * strcmp(hier, "FIREWALL_IP_DIRECT") &&
+ * strcmp(hier, "LOCAL_IP_DIRECT") &&
+ * strcmp(hier, "NO_DIRECT_FAIL") &&
+ * strcmp(hier, "NO_PARENT_DIRECT") &&
+ * strcmp(hier, "SINGLE_PARENT") &&
+ * strcmp(hier, "PASSTHROUGH_PARENT") &&
+ * strcmp(hier, "SSL_PARENT_MISS") &&
+ * strcmp(hier, "DEFAULT_PARENT");
+ */
     memcpy(entry->key, storeKeyPublic(url, method_id), sizeof(entry->key));
     /*fprintf(stdout, "%s:%d: %s %s %s %s\n",
-	fname, count, method, storeKeyText(entry->key), url, hier); */
+     * fname, count, method, storeKeyText(entry->key), url, hier); */
     return frOk;
 }
 
 
 static void
-cachePurge(Cache *cache, storeSwapLogData *s, int update_digest)
+cachePurge(Cache * cache, storeSwapLogData * s, int update_digest)
 {
     CacheEntry *olde = (CacheEntry *) hash_lookup(cache->hash, s->key);
     if (!olde) {
