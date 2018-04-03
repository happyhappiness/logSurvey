 static void ipcache_release(i)
      ipcache_entry *i;
 {
-    ipcache_entry *result = 0;
     hash_link *table_entry = NULL;
     int k;
 
     if ((table_entry = hash_lookup(ip_table, i->name)) == NULL) {
 	debug(14, 0, "ipcache_release: Could not find key '%s'\n", i->name);
 	return;
     }
-    result = (ipcache_entry *) table_entry;
-    if (i != result)
-	fatal_dump("ipcache_release: expected i == result!");
+    if (i != (ipcache_entry *) table_entry)
+	fatal_dump("ipcache_release: i != table_entry!");
     if (i->status == IP_PENDING) {
 	debug(14, 1, "ipcache_release: Someone called on a PENDING entry\n");
 	return;
