     ipcache_entry *i = NULL;
     dnsserver_t *dnsData = NULL;
     const ipcache_addrs *addrs = NULL;
-
-    if (!handler)
-	fatal_dump("ipcache_nbgethostbyname: NULL handler");
-
+    assert(handler != NULL);
     debug(14, 4) ("ipcache_nbgethostbyname: Name '%s'.\n", name);
     IpcacheStats.requests++;
 