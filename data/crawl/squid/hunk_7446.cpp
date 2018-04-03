     struct _net_db_name *x;
     int k;
     int i;
-    storeAppendPrintf(sentry, "{Network DB Statistics:\n");
-    */
-} */
-
-storeAppendPrintf(sentry, "{%-16.16s %9s %7s %5s %s}\n",
-    "Network",
-    "recv/sent",
-    "RTT",
-    "Hops",
-    "Hostnames");
-list = xcalloc(meta_data.netdb_addrs, sizeof(netdbEntry *));
-i = 0;
-for (n = netdbGetFirst(addr_table); n; n = netdbGetNext(addr_table))
-    *(list + i++) = n;
-qsort((char *) list,
-    i,
-    sizeof(netdbEntry *),
-    (QS) sortByHops);
-for (k = 0; k < i; k++) {
-    n = *(list + k);
-    storeAppendPrintf(sentry, "{%-16.16s %4d/%4d %7.1f %5.1f",	/* } */
-	n->network,
-	n->pings_recv,
-	n->pings_sent,
-	n->rtt,
-	n->hops);
-    for (x = n->hosts; x; x = x->next)
-	storeAppendPrintf(sentry, " %s", x->name);
+    storeAppendPrintf(sentry, "{Network DB Statistics:\n");	/* } */
+    storeAppendPrintf(sentry, "{%-16.16s %9s %7s %5s %s}\n",
+	"Network",
+	"recv/sent",
+	"RTT",
+	"Hops",
+	"Hostnames");
+    list = xcalloc(meta_data.netdb_addrs, sizeof(netdbEntry *));
+    i = 0;
+    for (n = netdbGetFirst(addr_table); n; n = netdbGetNext(addr_table))
+	*(list + i++) = n;
+    qsort((char *) list,
+	i,
+	sizeof(netdbEntry *),
+	(QS) sortByHops);
+    for (k = 0; k < i; k++) {
+	n = *(list + k);
+	storeAppendPrintf(sentry, "{%-16.16s %4d/%4d %7.1f %5.1f",	/* } */
+	    n->network,
+	    n->pings_recv,
+	    n->pings_sent,
+	    n->rtt,
+	    n->hops);
+	for (x = n->hosts; x; x = x->next)
+	    storeAppendPrintf(sentry, " %s", x->name);
+	storeAppendPrintf(sentry, close_bracket);
+    }
     storeAppendPrintf(sentry, close_bracket);
-}
-storeAppendPrintf(sentry, close_bracket);
-xfree(list);
+    xfree(list);
 #endif
 }
