 {
     ipcache_entry *this;
     ipcache_entry *next;
-    if (ip_table == 0)
-	fatal_dump("ipcache_restart: ip_table == 0\n");
+    assert(ip_table != NULL);
     while (ipcacheDequeue());
     next = (ipcache_entry *) hash_first(ip_table);
     while ((this = next)) {
