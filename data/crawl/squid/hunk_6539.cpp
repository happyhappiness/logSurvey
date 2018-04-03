 }
 #endif
 
-static int
-cacheIndexScanCleanPrefix(CacheIndex * idx, const char *fname, FILE * file)
-{
-    int count = 0;
-    storeSwapLogData s;
-    fprintf(stderr, "%s scanning\n", fname);
-    while (fread(&s, sizeof(s), 1, file) == 1) {
-	count++;
-	idx->scanned_count++;
-	if (s.op == SWAP_LOG_ADD) {
-	    CacheEntry *olde = (CacheEntry *) hash_lookup(idx->hash, s.key);
-	    if (olde) {
-		idx->bad_add_count++;
-	    } else {
-		CacheEntry *e = cacheEntryCreate(&s);
-		hash_join(idx->hash, (hash_link *) e);
-		idx->count++;
-	    }
-	} else if (s.op == SWAP_LOG_DEL) {
-	    break;
-	} else {
-	    fprintf(stderr, "%s:%d: unknown swap log action\n", fname, count);
-	    exit(-3);
-	}
-    }
-    fprintf(stderr, "%s scanned %d entries, alloc: %d bytes\n",
-	fname, count,
-	(int) (count * sizeof(CacheEntry)));
-    return count;
-}
-
 /* Us */
 
-static int we_icp_query_count = 0;
-static int we_true_hit_count = 0;
-static int we_true_miss_count = 0;
-static int we_false_hit_count = 0;
-static int we_false_miss_count = 0;
-
-static void
-cacheIndexQueryPeer(CacheIndex * idx, const cache_key * key)
-{
-    const int peer_has_it = hash_lookup(Peer->hash, key) != NULL;
-    const int we_think_we_have_it = cacheDigestTest(Peer->digest, key);
-
-    we_icp_query_count++;
-    if (peer_has_it)
-	if (we_think_we_have_it)
-	    we_true_hit_count++;
-	else
-	    we_false_miss_count++;
-    else if (we_think_we_have_it)
-	we_false_hit_count++;
-    else
-	we_true_miss_count++;
-}
-
-static void
-cacheIndexIcpReport(CacheIndex * idx)
-{
-    fprintf(stdout, "we: icp: %d\n", we_icp_query_count);
-    fprintf(stdout, "we: t-hit: %d (%d%%) t-miss: %d (%d%%) t-*: %d (%d%%)\n",
-	we_true_hit_count, xpercentInt(we_true_hit_count, we_icp_query_count),
-	we_true_miss_count, xpercentInt(we_true_miss_count, we_icp_query_count),
-	we_true_hit_count + we_true_miss_count,
-	xpercentInt(we_true_hit_count + we_true_miss_count, we_icp_query_count)
-	);
-    fprintf(stdout, "we: f-hit: %d (%d%%) f-miss: %d (%d%%) f-*: %d (%d%%)\n",
-	we_false_hit_count, xpercentInt(we_false_hit_count, we_icp_query_count),
-	we_false_miss_count, xpercentInt(we_false_miss_count, we_icp_query_count),
-	we_false_hit_count + we_false_miss_count,
-	xpercentInt(we_false_hit_count + we_false_miss_count, we_icp_query_count)
-	);
-}
-
 static int
-cacheIndexAddAccessLog(CacheIndex * idx, const char *fname)
+cacheAddAccessLog(Cache * idx, const char *fname)
 {
     FILE *file;
     int scanned_count = 0;
