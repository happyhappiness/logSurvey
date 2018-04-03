 static void
 fqdncache_release(fqdncache_entry * f)
 {
-    hash_link *table_entry = NULL;
     int k;
-
-    if ((table_entry = hash_lookup(fqdn_table, f->name)) == NULL) {
-	debug(35, 0) ("fqdncache_release: Could not find key '%s'\n", f->name);
-	return;
-    }
-    if (f != (fqdncache_entry *) table_entry)
-	fatal_dump("fqdncache_release: f != table_entry!");
-    if (f->status == FQDN_PENDING) {
-	debug(35, 1) ("fqdncache_release: Someone called on a PENDING entry\n");
-	return;
-    }
-    if (f->status == FQDN_DISPATCHED) {
-	debug(35, 1) ("fqdncache_release: Someone called on a DISPATCHED entry\n");
-	return;
-    }
-    if (f->pending_head)
-	fatal_dump("fqdncache_release: still have pending clients");
-    if (hash_remove_link(fqdn_table, table_entry)) {
+    assert(f->status != FQDN_PENDING);
+    assert(f->status != FQDN_DISPATCHED);
+    assert(f->pending_head == NULL);
+    if (hash_remove_link(fqdn_table, (hash_link *) f)) {
 	debug(35, 0) ("fqdncache_release: hash_remove_link() failed for '%s'\n",
 	    f->name);
 	return;
