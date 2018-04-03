 }
 
 static void
-cacheQueryReport(Cache * cache, CacheQueryStats *stats)
+cacheQueryReport(Cache * cache, CacheQueryStats * stats)
 {
-    fprintf(stdout, "%s: peer queries: %d (%d%%)\n", 
-	cache->name, 
+    fprintf(stdout, "%s: peer queries: %d (%d%%)\n",
+	cache->name,
 	stats->query_count, xpercentInt(stats->query_count, cache->req_count)
 	);
     fprintf(stdout, "%s: t-hit: %d (%d%%) t-miss: %d (%d%%) t-*: %d (%d%%)\n",
-	cache->name, 
+	cache->name,
 	stats->true_hit_count, xpercentInt(stats->true_hit_count, stats->query_count),
 	stats->true_miss_count, xpercentInt(stats->true_miss_count, stats->query_count),
 	stats->true_hit_count + stats->true_miss_count,
 	xpercentInt(stats->true_hit_count + stats->true_miss_count, stats->query_count)
 	);
     fprintf(stdout, "%s: f-hit: %d (%d%%) f-miss: %d (%d%%) f-*: %d (%d%%)\n",
-	cache->name, 
+	cache->name,
 	stats->false_hit_count, xpercentInt(stats->false_hit_count, stats->query_count),
 	stats->false_miss_count, xpercentInt(stats->false_miss_count, stats->query_count),
 	stats->false_hit_count + stats->false_miss_count,
