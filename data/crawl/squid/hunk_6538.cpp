 }
 
 static void
-cacheIndexInitReport(CacheIndex * idx)
+cacheInitReport(Cache * cache)
 {
     assert(idx);
     fprintf(stderr, "%s: bad swap_add:  %d\n",
