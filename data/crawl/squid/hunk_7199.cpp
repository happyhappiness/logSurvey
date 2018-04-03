     int k;
 
     if ((table_entry = hash_lookup(fqdn_table, f->name)) == NULL) {
-	debug(35, 0, "fqdncache_release: Could not find key '%s'\n", f->name);
+	debug(35, 0) ("fqdncache_release: Could not find key '%s'\n", f->name);
 	return;
     }
     if (f != (fqdncache_entry *) table_entry)
 	fatal_dump("fqdncache_release: f != table_entry!");
     if (f->status == FQDN_PENDING) {
-	debug(35, 1, "fqdncache_release: Someone called on a PENDING entry\n");
+	debug(35, 1) ("fqdncache_release: Someone called on a PENDING entry\n");
 	return;
     }
     if (f->status == FQDN_DISPATCHED) {
-	debug(35, 1, "fqdncache_release: Someone called on a DISPATCHED entry\n");
+	debug(35, 1) ("fqdncache_release: Someone called on a DISPATCHED entry\n");
 	return;
     }
     if (f->pending_head)
 	fatal_dump("fqdncache_release: still have pending clients");
     if (hash_remove_link(fqdn_table, table_entry)) {
-	debug(35, 0, "fqdncache_release: hash_remove_link() failed for '%s'\n",
+	debug(35, 0) ("fqdncache_release: hash_remove_link() failed for '%s'\n",
 	    f->name);
 	return;
     }
     if (f->status == FQDN_CACHED) {
 	for (k = 0; k < (int) f->name_count; k++)
 	    safe_free(f->names[k]);
-	debug(35, 5, "fqdncache_release: Released FQDN record for '%s'.\n",
+	debug(35, 5) ("fqdncache_release: Released FQDN record for '%s'.\n",
 	    f->name);
     }
     safe_free(f->name);
