 fqdncache_restart(void)
 {
     fqdncache_entry *this;
-    if (fqdn_table == 0)
-	fatal_dump("fqdncache_restart: fqdn_table == 0\n");
+    assert(fqdn_table);
     while (fqdncacheDequeue());
     hash_first(fqdn_table);
     while ((this = (fqdncache_entry *) hash_next(fqdn_table))) {