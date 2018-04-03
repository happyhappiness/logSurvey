 }
 
 
-/* initialize the ipcache */
-void ipcache_init()
+void ipcacheOpenServers()
 {
-    int i, dnssocket;
-    char fd_note_buf[FD_ASCII_NOTE_SZ];
-
-    debug(14, 3, "ipcache_init: Called.  ipcache_initialized=%d  getDnsChildren()=%d\n", ipcache_initialized, getDnsChildren());
-
-    if (ipcache_initialized)
-	return;
+    int N = getDnsChildren();
+    char *prg = getDnsProgram();
+    int i;
+    int dnssocket;
+    static char fd_note_buf[FD_ASCII_NOTE_SZ];
 
-    if (mkdir("dns", 0755) < 0 && errno != EEXIST) {
-	debug(14, 0, "ipcache_init: mkdir %s\n", xstrerror());
-    }
-    last_dns_dispatched = getDnsChildren() - 1;
-    dns_error_message = xcalloc(1, 256);
+    if (mkdir("dns", 0755) < 0 && errno != EEXIST)
+	debug(14, 0, "ipcacheOpenServers: mkdir %s\n", xstrerror());
 
-    /* test naming lookup */
-    if (!do_dns_test) {
-	debug(14, 4, "ipcache_init: Skipping DNS name lookup tests, -D flag given.\n");
-    } else if (ipcache_testname() < 0) {
-	fatal("ipcache_init: DNS name lookup appears to be broken on this machine.");
-    } else {
-	debug(14, 1, "Successful DNS name lookup tests...\n");
-    }
-
-    ip_table = hash_create(urlcmp, 229);	/* small hash table */
-    /* init static area */
-    static_result = (struct hostent *) xcalloc(1, sizeof(struct hostent));
-    static_result->h_length = 4;
-    /* Need a terminating NULL address (h_addr_list[1]) */
-    static_result->h_addr_list = (char **) xcalloc(2, sizeof(char *));
-    static_result->h_addr_list[0] = (char *) xcalloc(1, 4);
-    static_result->h_name = (char *) xcalloc(1, MAX_HOST_NAME + 1);
     /* start up companion process */
-    dns_child_table = (dnsserver_entry **) xcalloc(getDnsChildren(), sizeof(dnsserver_entry));
+    safe_free(dns_child_table);
+    dns_child_table = (dnsserver_entry **) xcalloc(N, sizeof(dnsserver_entry));
     dns_child_alive = 0;
-    debug(14, 1, "ipcache_init: Starting %d 'dns_server' processes\n",
-	getDnsChildren());
-    for (i = 0; i < getDnsChildren(); i++) {
+    debug(14, 1, "ipcache_init: Starting %d 'dns_server' processes\n", N);
+    for (i = 0; i < N; i++) {
 	dns_child_table[i] = (dnsserver_entry *) xcalloc(1, sizeof(dnsserver_entry));
-	if ((dnssocket = ipcache_create_dnsserver(getDnsProgram())) < 0) {
+	if ((dnssocket = ipcache_create_dnsserver(prg)) < 0) {
 	    debug(14, 1, "ipcache_init: WARNING: Cannot run 'dnsserver' process.\n");
 	    debug(14, 1, "              Fallling back to the blocking version.\n");
 	    dns_child_table[i]->alive = 0;
