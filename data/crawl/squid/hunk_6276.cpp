     char *name = inet_ntoa(addr);
     fqdncache_entry *f = NULL;
     struct in_addr ip;
-
-    if (!name)
-	fatal_dump("fqdncache_gethostbyaddr: NULL name");
+    assert(name);
     FqdncacheStats.requests++;
     if ((f = fqdncache_get(name))) {
 	if (fqdncacheExpiredEntry(f)) {
