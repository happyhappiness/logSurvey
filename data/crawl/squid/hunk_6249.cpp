     } else {
 	fatal_dump("ipcache_nbgethostbyname: BAD ipcache_entry status");
     }
-
-    /* for HIT, PENDING, DISPATCHED we've returned.  For MISS we continue */
-
-    if ((dnsData = dnsGetFirstAvailable())) {
-	ipcache_dnsDispatch(dnsData, i);
-    } else if (NDnsServersAlloc) {
-	ipcacheEnqueue(i);
-    } else {
-	/* generate abort if we get here */
-	assert(NDnsServersAlloc);
-    }
-}
-
-static void
-ipcache_dnsDispatch(dnsserver_t * dns, ipcache_entry * i)
-{
-    char *buf = NULL;
-    assert(dns->flags.alive);
-    if (!ipcacheHasPending(i)) {
-	debug(14, 3) ("Skipping lookup of '%s' because client(s) disappeared.\n",
-	    i->name);
-	i->status = IP_NEGATIVE_CACHED;
-	ipcache_release(i);
-	return;
-    }
-    assert(i->status == IP_PENDING);
-    buf = xcalloc(1, 256);
-    snprintf(buf, 256, "%s\n", i->name);
-    dns->flags.busy = 1;
-    dns->data = i;
+    /* for HIT, PENDING, DISPATCHED we've returned.  For MISS we submit */
+    c = xcalloc(1, sizeof(*c));
+    c->data = i;
+    cbdataAdd(c, MEM_NONE);
     i->status = IP_DISPATCHED;
-    cbdataLock(dns);
-    comm_write(dns->outpipe,
-	buf,
-	strlen(buf),
-	NULL,			/* Handler */
-	NULL,			/* Handler-data */
-	xfree);
-    commSetSelect(dns->outpipe,
-	COMM_SELECT_READ,
-	ipcache_dnsHandleRead,
-	dns, 0);
-    debug(14, 5) ("ipcache_dnsDispatch: Request sent to DNS server #%d.\n",
-	dns->id);
-    dns->dispatch_time = current_time;
-    DnsStats.requests++;
-    DnsStats.hist[dns->id - 1]++;
-    ipcacheLockEntry(i);	/* lock while IP_DISPATCHED */
+    ipcacheLockEntry(i);
+    dnsSubmit(i->name, ipcacheHandleReply, c);
 }
 
-
 /* initialize the ipcache */
 void
 ipcache_init(void)
 {
     int n;
     debug(14, 3) ("Initializing IP Cache...\n");
-
     memset(&IpcacheStats, '\0', sizeof(IpcacheStats));
     memset(&lru_list, '\0', sizeof(lru_list));
-
     /* test naming lookup */
     if (!opt_dns_tests) {
 	debug(14, 4) ("ipcache_init: Skipping DNS name lookup tests.\n");
