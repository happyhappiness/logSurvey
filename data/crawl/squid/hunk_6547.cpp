 
 /* makes digest based on currently hashed entries */
 static void
-cacheIndexInitDigest(CacheIndex *idx)
+cacheIndexInitDigest(CacheIndex * idx)
 {
     hash_link *hashr = NULL;
     struct timeval t_start, t_end;
     assert(idx && !idx->digest);
     fprintf(stderr, "%s: init-ing digest with %d entries\n", idx->name, idx->count);
-    idx->digest = cacheDigestCreate(2*idx->count); /* 50% utilization */
+    idx->digest = cacheDigestCreate(2 * idx->count);	/* 50% utilization */
     gettimeofday(&t_start, NULL);
     for (hashr = hash_first(idx->hash); hashr; hashr = hash_next(idx->hash)) {
 	cacheDigestAdd(idx->digest, hashr->key);
     }
     gettimeofday(&t_end, NULL);
     assert(idx->digest->count == idx->count);
-    fprintf(stderr, "%s: init-ed  digest with %d entries\n", 
+    fprintf(stderr, "%s: init-ed  digest with %d entries\n",
 	idx->name, idx->digest->count);
     fprintf(stderr, "%s: init took: %f sec, %f sec/M\n",
 	idx->name,
 	tvSubDsec(t_start, t_end),
-	(double)1e6*tvSubDsec(t_start, t_end)/idx->count);
+	(double) 1e6 * tvSubDsec(t_start, t_end) / idx->count);
     /* check how long it takes to traverse the hash */
     gettimeofday(&t_start, NULL);
     for (hashr = hash_first(idx->hash); hashr; hashr = hash_next(idx->hash)) {
