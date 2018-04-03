 ipcache_release(ipcache_entry * i)
 {
     hash_link *table_entry = NULL;
-    if ((table_entry = hash_lookup(ip_table, i->name)) == NULL) {
-	debug(14, 0) ("ipcache_release: Could not find key '%s'\n", i->name);
-	return;
-    }
+    if ((table_entry = hash_lookup(ip_table, i->name)) == NULL)
+	fatalf("ipcache_release: key '%s' not found\n", i->name);
     assert(i == (ipcache_entry *) table_entry);
     if (i->locks) {
 	i->expires = squid_curtime;