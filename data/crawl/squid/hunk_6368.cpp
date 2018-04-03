 ipcache_release(ipcache_entry * i)
 {
     hash_link *table_entry = NULL;
-    if ((table_entry = hash_lookup(ip_table, i->name)) == NULL)
-	fatalf("ipcache_release: key '%s' not found\n", i->name);
+    if ((table_entry = hash_lookup(ip_table, i->name)) == NULL) {
+	snprintf(tmp_error_buf, ERROR_BUF_SZ, "ipcache_release: key '%s' not found\n", i->name);
+	fatal_dump(tmp_error_buf);
+    }
     assert(i == (ipcache_entry *) table_entry);
     if (i->locks) {
 	i->expires = squid_curtime;