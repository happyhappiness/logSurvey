 	    fqdncacheQueueTailP = &fqdncacheQueueHead;
 	safe_free(old);
     }
+    if (f && f->status != FQDN_PENDING)
+	debug_trap("fqdncacheDequeue: status != FQDN_PENDING");
     return f;
 }
 
 /* removes the given fqdncache entry */
 static void
 fqdncache_release(fqdncache_entry * f)
 {
-    fqdncache_entry *result = NULL;
     hash_link *table_entry = NULL;
     int k;
 
     if ((table_entry = hash_lookup(fqdn_table, f->name)) == NULL) {
 	debug(35, 0, "fqdncache_release: Could not find key '%s'\n", f->name);
 	return;
     }
-    result = (fqdncache_entry *) table_entry;
-    if (f != result)
-	fatal_dump("fqdncache_release: expected f == result!");
+    if (f != (fqdncache_entry *) table_entry)
+	fatal_dump("fqdncache_release: f != table_entry!");
     if (f->status == FQDN_PENDING) {
 	debug(35, 1, "fqdncache_release: Someone called on a PENDING entry\n");
 	return;
