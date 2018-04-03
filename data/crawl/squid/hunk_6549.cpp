 }
 
 static void
-cacheIndexInitReport(CacheIndex *idx)
+cacheIndexInitReport(CacheIndex * idx)
 {
     assert(idx);
     fprintf(stderr, "%s: bad swap_add:  %d\n",
 	idx->name, idx->bad_add_count);
-    fprintf(stderr, "%s: bad swap_del:  %d\n", 
+    fprintf(stderr, "%s: bad swap_del:  %d\n",
 	idx->name, idx->bad_del_count);
-    fprintf(stderr, "%s: scanned lines: %d\n", 
+    fprintf(stderr, "%s: scanned lines: %d\n",
 	idx->name, idx->scanned_count);
 }
 
 #if 0
 static int
-cacheIndexGetLogEntry(CacheIndex *idx, storeSwapLogData *s)
+cacheIndexGetLogEntry(CacheIndex * idx, storeSwapLogData * s)
 {
     if (!idx->has_log_entry)
 	cacheIndexStepLogEntry();
