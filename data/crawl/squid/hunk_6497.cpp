 static void
 cacheReport(Cache * cache)
 {
-    fprintf(stdout, "%s: entries: %d reqs: %d bad-add: %d bad-del: %d\n", 
+    fprintf(stdout, "%s: entries: %d reqs: %d bad-add: %d bad-del: %d\n",
 	cache->name, cache->count, cache->req_count,
 	cache->bad_add_count, cache->bad_del_count);
 
 }
 
 static void
-cacheFetch(Cache *cache, const RawAccessLogEntry *e)
+cacheFetch(Cache * cache, const RawAccessLogEntry * e)
 {
     assert(e);
     cache->req_count++;
