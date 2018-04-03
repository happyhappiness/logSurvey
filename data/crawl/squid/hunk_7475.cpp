 	return 0;
 }
 
+#endif /* USE_ICMP */
+
+/* PUBLIC FUNCTIONS */
+
 void
-netdbDump(StoreEntry * sentry)
+netdbInit(void)
+{
+#if USE_ICMP
+    addr_table = hash_create((int (*)_PARAMS((char *, char *))) strcmp, 229, hash_string);
+    host_table = hash_create((int (*)_PARAMS((char *, char *))) strcmp, 467, hash_string);
+#endif
+}
+
+void
+netdbPingSite(char *hostname)
 {
+#if USE_ICMP
     netdbEntry *n;
-    netdbEntry **list;
-    struct _net_db_name *x;
-    int k;
-    int i;
-    storeAppendPrintf(sentry, "{Network DB Statistics:\n");
-    storeAppendPrintf(sentry, "{%-16.16s %9s %7s %5s %s}\n",
-	"Network",
-	"recv/sent",
-	"RTT",
-	"Hops",
-	"Hostnames");
-    list = xcalloc(meta_data.netdb_addrs, sizeof(netdbEntry *));
-    i = 0;
-    for (n = netdbGetFirst(addr_table); n; n = netdbGetNext(addr_table))
-	*(list + i++) = n;
-    qsort((char *) list,
-	i,
-	sizeof(netdbEntry *),
-	(QS) sortByHops);
-    for (k = 0; k < i; k++) {
-	n = *(list + k);
-	storeAppendPrintf(sentry, "{%-16.16s %4d/%4d %7.1f %5.1f",
-	    n->network,
-	    n->pings_recv,
-	    n->pings_sent,
-	    n->rtt,
-	    n->hops);
-	for (x = n->hosts; x; x = x->next)
-	    storeAppendPrintf(sentry, " %s", x->name);
-	storeAppendPrintf(sentry, close_bracket);
-    }
-    storeAppendPrintf(sentry, close_bracket);
-    xfree(list);
+    if ((n = netdbLookupHost(hostname)) != NULL)
+	if (n->next_ping_time > squid_curtime)
+	    return;
+    ipcache_nbgethostbyname(hostname,
+	-1,
+	netdbSendPing,
+	(void *) xstrdup(hostname));
+#endif
 }
 
-int
-netdbHops(struct in_addr addr)
+void
+netdbHandlePingReply(struct sockaddr_in *from, int hops, int rtt)
 {
-    netdbEntry *n = netdbLookupAddr(addr);
-    if (n && n->pings_recv) {
-	n->last_use_time = squid_curtime;
-	return (int) (n->hops + 0.5);
-    }
-    return 256;
+#if USE_ICMP
+    netdbEntry *n;
+    int N;
+    debug(37, 3, "netdbHandlePingReply: from %s\n", inet_ntoa(from->sin_addr));
+    if ((n = netdbLookupAddr(from->sin_addr)) == NULL)
+	return;
+    N = ++n->n;
+    if (N > 100)
+	N = 100;
+    n->hops = ((n->hops * (N - 1)) + hops) / N;
+    n->rtt = ((n->rtt * (N - 1)) + rtt) / N;
+    n->pings_recv++;
+    debug(37, 3, "netdbHandlePingReply: %s; rtt=%5.1f  hops=%4.1f\n",
+	n->network,
+	n->rtt,
+	n->hops);
+#endif
 }
 
 void
 netdbFreeMemory(void)
 {
+#if USE_ICMP
     netdbEntry *n;
     netdbEntry **L1;
     hash_link *h;
     hash_link **L2;
     struct _net_db_name *x;
     int i = 0;
     int j;
-
     L1 = xcalloc(meta_data.netdb_addrs, sizeof(netdbEntry *));
     n = (netdbEntry *) hash_first(addr_table);
     while (n && i < meta_data.netdb_addrs) {
