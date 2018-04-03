     cachemgrRegister("ipcache",
 	"IP Cache Stats and Contents",
 	stat_ipcache_get, 0, 1);
-}
-
-int
-ipcacheUnregister(const char *name, void *data)
-{
-    ipcache_entry *i = NULL;
-    ip_pending *p = NULL;
-    int n = 0;
-    debug(14, 3) ("ipcacheUnregister: name '%s'\n", name);
-    if ((i = ipcache_get(name)) == NULL)
-	return 0;
-    if (i->status == IP_PENDING || i->status == IP_DISPATCHED) {
-	for (p = i->pending_head; p; p = p->next) {
-	    if (p->handlerData != data)
-		continue;
-	    p->handler = NULL;
-	    n++;
-	}
-    }
-    assert(n > 0);
-    debug(14, 3) ("ipcacheUnregister: unregistered %d handlers\n", n);
-    return n;
+    memDataInit(MEM_IPCACHE_ENTRY, "ipcache_entry", sizeof(ipcache_entry), 0);
 }
 
 const ipcache_addrs *
 ipcache_gethostbyname(const char *name, int flags)
 {
     ipcache_entry *i = NULL;
     ipcache_addrs *addrs;
-    if (!name)
-	fatal_dump("ipcache_gethostbyname: NULL name");
+    assert(name);
     debug(14, 3) ("ipcache_gethostbyname: '%s', flags=%x\n", name, flags);
     IpcacheStats.requests++;
-    if ((i = ipcache_get(name))) {
-	if (ipcacheExpiredEntry(i)) {
-	    ipcache_release(i);
-	    i = NULL;
-	}
-    }
-    if (i) {
-	if (i->status == IP_NEGATIVE_CACHED) {
-	    IpcacheStats.negative_hits++;
-	    dns_error_message = i->error_message;
-	    return NULL;
-	} else if (i->addrs.count == 0) {
-	    (void) 0;
-	} else {
-	    IpcacheStats.hits++;
-	    i->lastref = squid_curtime;
-	    return &i->addrs;
-	}
+    i = ipcache_get(name);
+    if (NULL == i) {
+	(void) 0;
+    } else if (ipcacheExpiredEntry(i)) {
+	ipcacheRelease(i);
+	i = NULL;
+    } else if (i->flags.negcached) {
+	IpcacheStats.negative_hits++;
+	dns_error_message = i->error_message;
+	return NULL;
+    } else {
+	IpcacheStats.hits++;
+	i->lastref = squid_curtime;
+	return &i->addrs;
     }
     if ((addrs = ipcacheCheckNumeric(name)))
 	return addrs;
