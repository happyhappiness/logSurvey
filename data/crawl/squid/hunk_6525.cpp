     return xpercent(on_count, bit_count);
 }
 
+void
+cacheDigestReport(CacheDigest *cd, const char *label, StoreEntry * e)
+{
+    int bit_count, on_count;
+    assert(cd && e);
+    cacheDigestUtil(cd, &bit_count, &on_count);
+    storeAppendPrintf(e, "%s digest: size: %d bytes.\n",
+	label ? label : "",
+	bit_count/8
+    );
+    storeAppendPrintf(e, "\t entries: count: %d capacity: %d util: %d%%\n",
+	cd->count,
+	cd->capacity,
+	xpercentInt(cd->count, cd->capacity)
+    );
+    storeAppendPrintf(e, "\t deletion attempts: %d\n", 
+	cd->del_count
+    );
+    storeAppendPrintf(e, "\t bits: on: %d capacity: %d util: %d%%\n", 
+	on_count, bit_count,
+	xpercentInt(on_count, bit_count)
+    );
+}
+
 static void
 cacheDigestHashKey(int bit_count, const char *key)
 {
