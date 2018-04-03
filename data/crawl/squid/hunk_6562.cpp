     struct timeval t_start, t_end;
     assert(idx && !idx->digest);
     fprintf(stderr, "%s: init-ing digest with %d entries\n", idx->name, idx->count);
-    idx->digest = cacheDigestCreate(idx->count); /* no "fat" */
+    idx->digest = cacheDigestCreate(2*idx->count); /* 50% utilization */
     gettimeofday(&t_start, NULL);
     for (hashr = hash_first(idx->hash); hashr; hashr = hash_next(idx->hash)) {
 	cacheDigestAdd(idx->digest, hashr->key);
