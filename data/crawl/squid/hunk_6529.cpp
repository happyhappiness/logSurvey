     if (cache->digest) {
 	int bit_count, on_count;
 	cacheDigestUtil(cache->digest, &bit_count, &on_count);
-	fprintf(stdout, "%s: digest entries: cnt: %d cap: %d util: %d%% size: %d b\n", 
+	fprintf(stdout, "%s: digest entries: cnt: %d (-=%d) cap: %d util: %d%% size: %d b\n", 
 	    cache->name, 
-	    cache->digest->count, cache->digest->capacity,
+	    cache->digest->count, cache->digest->del_count,
+	    cache->digest->capacity,
 	    xpercentInt(cache->digest->count, cache->digest->capacity),
 	    bit_count/8
 	);
