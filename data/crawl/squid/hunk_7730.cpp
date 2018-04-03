 
     debug(14, 3, "Initializing IP Cache...\n");
 
-    last_dns_dispatched = getDnsChildren() - 1;
-    if (!dns_error_message)
-	dns_error_message = xcalloc(1, 256);
+    memset(&IpcacheStats, '\0', sizeof(IpcacheStats));
 
     /* test naming lookup */
-    if (!do_dns_test) {
+    if (!opt_dns_tests) {
 	debug(14, 4, "ipcache_init: Skipping DNS name lookup tests.\n");
     } else if (!ipcache_testname()) {
 	fatal("ipcache_init: DNS name lookup tests failed/");
