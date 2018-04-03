 #endif
     if (c->valid || c->locks)
 	return;
-    cbdataReallyFree(c);
+    cbdataCount--;
+    debug(45, 3) ("cbdataUnlock: Freeing %p\n", p);
+    if (c->unlock_func)
+	c->unlock_func((void *) p);
+    memPoolFree(cbdata_memory_pool[c->type], c);
 }
 
 int
 cbdataValid(const void *p)
 {
     cbdata *c;
-    /* Maybe NULL should be considered valid? */
     if (p == NULL)
-	return 0;
-    c = (cbdata *) hash_lookup(htable, p);
+	return 1;		/* A NULL pointer cannot become invalid */
     debug(45, 3) ("cbdataValid: %p\n", p);
-    assert(c != NULL);
+    c = (cbdata *) (((char *) p) - OFFSET_OF(cbdata, data));
+    assert(c->y == c);
     assert(c->locks > 0);
     return c->valid;
 }
 
-void
-cbdataXfree(void *p, int unused)
-{
-    xfree(p);
-}
-
-
 static void
 cbdataDump(StoreEntry * sentry)
 {
-    hash_link *hptr;
-    cbdata *c;
     storeAppendPrintf(sentry, "%d cbdata entries\n", cbdataCount);
-    hash_first(htable);
-    while ((hptr = hash_next(htable))) {
-	c = (cbdata *) hptr;
-#if CBDATA_DEBUG
-	storeAppendPrintf(sentry, "%20p %10s %d locks %s:%d\n",
-	    c->hash.key,
-	    c->valid ? "VALID" : "NOT VALID",
-	    c->locks,
-	    c->file, c->line);
-#else
-	storeAppendPrintf(sentry, "%20p %10s %d locks\n",
-	    c->hash.key,
-	    c->valid ? "VALID" : "NOT VALID",
-	    c->locks);
-#endif
-    }
+    storeAppendPrintf(sentry, "see also memory pools section\n");
 }
