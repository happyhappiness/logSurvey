     int i, dnssocket;
     char fd_note_buf[FD_ASCII_NOTE_SZ];
 
-    debug(3, "ipcache_init: Called.  ipcache_initialized=%d  getDnsChildren()=%d\n", ipcache_initialized, getDnsChildren());
+    debug(0, 3, "ipcache_init: Called.  ipcache_initialized=%d  getDnsChildren()=%d\n", ipcache_initialized, getDnsChildren());
 
     if (ipcache_initialized)
 	return;
 
     if (mkdir("dns", 0755) < 0 && errno != EEXIST) {
-	debug(0, "ipcache_init: mkdir %s\n", xstrerror());
+	debug(0, 0, "ipcache_init: mkdir %s\n", xstrerror());
     }
     last_dns_dispatched = getDnsChildren() - 1;
     dns_error_message = xcalloc(1, 256);
 
     /* test naming lookup */
     if (!do_dns_test) {
-	debug(4, "ipcache_init: Skipping DNS name lookup tests, -D flag given.\n");
+	debug(0, 4, "ipcache_init: Skipping DNS name lookup tests, -D flag given.\n");
     } else if (ipcache_testname() < 0) {
-	debug(0, "ipcache_init: DNS name lookup appears to be broken on this machine.\n");
+	debug(0, 0, "ipcache_init: DNS name lookup appears to be broken on this machine.\n");
 	fprintf(stderr, "ipcache_init: DNS name lookup appears to be broken on this machine.\n");
 	exit(-1);
     } else {
-	debug(4, "ipcache_init: Successful DNS name lookup tests...\n");
+	debug(0, 4, "ipcache_init: Successful DNS name lookup tests...\n");
     }
 
     ip_table = hash_create(urlcmp, 229);	/* small hash table */
