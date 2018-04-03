     assert(cache);
     fprintf(stderr, "%s: init-ing digest with %d entries\n", cache->name, cache->count);
 
-    if (cache->digest)
-        cacheDigestDestroy(cache->digest);
-
     hash = cache->hash;
 
-    cache->digest = cacheDigestCreate(cache->count + 1, 6);
+    delete cache->digest;
+    cache->digest = new CacheDigest(cache->count + 1, 6);
 
     if (!cache->count)
         return;
