 netdbSaveState(void *foo)
 {
     LOCAL_ARRAY(char, path, SQUID_MAXPATHLEN);
-    int fd;
+    Logfile *lf;
     netdbEntry *n;
     net_db_name *x;
     struct timeval start = current_time;
     int count = 0;
-    size_t wl = 4096;
-    char *wbuf = xmalloc(wl);
-    off_t wo = 0;
     snprintf(path, SQUID_MAXPATHLEN, "%s/netdb_state", storeSwapDir(0));
     /*
      * This was nicer when we were using stdio, but thanks to
      * Solaris bugs, its a bad idea.  fopen can fail if more than
      * 256 FDs are open.
      */
-    fd = file_open(path, O_WRONLY | O_CREAT | O_TRUNC);
-    if (fd < 0) {
+    lf = logfileOpen(path, 4096, 0);
+    if (NULL == lf) {
 	debug(50, 1) ("netdbSaveState: %s: %s\n", path, xstrerror());
 	return;
     }
     hash_first(addr_table);
     while ((n = (netdbEntry *) hash_next(addr_table))) {
-#define RBUF_SZ 4096
-	char rbuf[RBUF_SZ];
-	off_t ro;
 	if (n->pings_recv == 0)
 	    continue;
-	ro = 0;
-	ro += snprintf(rbuf, RBUF_SZ, "%s %d %d %10.5f %10.5f %d %d",
+	logfilePrintf(lf, "%s %d %d %10.5f %10.5f %d %d",
 	    n->network,
 	    n->pings_sent,
 	    n->pings_recv,
