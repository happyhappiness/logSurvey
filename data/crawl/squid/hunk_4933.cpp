 }
 
 void *
-leakFreeFL(void *p, const char *file, int line)
+LeakFinder::free(void *p, const char *file, int line)
 {
-    ptr *c = (ptr *) hash_lookup(htable, p);
     assert(p);
-    assert(c != NULL);
-    hash_remove_link(htable, (hash_link *) c);
-    leakCount--;
-    xfree(c);
+    LeakFinderPtr *c = (LeakFinderPtr *) hash_lookup(table, p);
+    assert(c);
+    hash_remove_link(table, c);
+    count--;
+    delete c;
+    dump();
     return p;
 }
 
 /* ========================================================================= */
 
-static int
-ptr_cmp(const void *p1, const void *p2)
+int
+LeakFinder::cmp(const void *p1, const void *p2)
 {
     return (char *) p1 - (char *) p2;
 }
 
-static unsigned int
-ptr_hash(const void *p, unsigned int mod)
+unsigned int
+LeakFinder::hash(const void *p, unsigned int mod)
 {
     return ((unsigned long) p >> 8) % mod;
 }
 
 
-static void
-ptrDump(StoreEntry * sentry)
+void
+LeakFinder::dump()
 {
-    hash_link *hptr;
-    ptr *c;
-    storeAppendPrintf(sentry, "Tracking %d pointers\n", leakCount);
-    hash_first(htable);
-
-    while ((hptr = (hash_link *)hash_next(htable))) {
-        c = (ptr *) hptr;
-        storeAppendPrintf(sentry, "%20p last used %9d seconds ago by %s:%d\n",
-                          c->key, (int)(squid_curtime - c->when), c->file, c->line);
+    if (0 == count)
+        return;
+
+    if (squid_curtime == last_dump)
+        return;
+
+    last_dump = squid_curtime;
+
+    debug(45,1)("Tracking %d pointers\n", count);
+
+    hash_first(table);
+
+    LeakFinderPtr *c;
+
+    while ((c = (LeakFinderPtr *)hash_next(table))) {
+        debug(45,1)("%20p last used %9d seconds ago by %s:%d\n",
+                    c->key, (int)(squid_curtime - c->when), c->file, c->line);
     }
 }
