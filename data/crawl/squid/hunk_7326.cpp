 #if USE_ICMP
     netdbEntry *n;
     netdbEntry **list;
-    struct _net_db_name *x;
+    net_db_name *x;
     int k;
     int i;
+    int j;
+    net_db_peer *p;
     storeAppendPrintf(sentry, "{Network DB Statistics:\n");	/* } */
     storeAppendPrintf(sentry, "{%-16.16s %9s %7s %5s %s}\n",
 	"Network",
