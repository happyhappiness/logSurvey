 {
     ipcache_entry *i = NULL;
     ipcache_addrs *addrs;
-    const struct hostent *hp;
 
     if (!name)
 	fatal_dump("ipcache_gethostbyname: NULL name");
