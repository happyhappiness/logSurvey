     ipcache_entry *i;
     if (ipcache_get(name))
 	fatal_dump("ipcacheAddNew: somebody adding a duplicate!");
-    debug(14, 10, "ipcacheAddNew: Adding '%s', status=%c\n",
+    debug(14, 10) ("ipcacheAddNew: Adding '%s', status=%c\n",
 	name,
 	ipcache_status_char[status]);
     i = ipcache_create(name);
