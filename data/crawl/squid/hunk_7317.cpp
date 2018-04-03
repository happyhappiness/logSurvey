     }
     if (i != (ipcache_entry *) table_entry)
 	fatal_dump("ipcache_release: i != table_entry!");
-    if (i->status == IP_PENDING) {
-	debug(14, 1, "ipcache_release: Someone called on a PENDING entry\n");
-	return;
-    }
-    if (i->status == IP_DISPATCHED) {
-	debug(14, 1, "ipcache_release: Someone called on a DISPATCHED entry\n");
+    if (i->locks) {
+	i->expires = squid_curtime;
+	IpcacheStats.release_locked++;
 	return;
     }
     if (hash_remove_link(ip_table, table_entry)) {
