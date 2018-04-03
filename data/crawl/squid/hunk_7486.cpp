 
 #if USE_ICMP
     storeAppendPrintf(sentry, "{\t%-25.25s %7d x %4d bytes = %6d KB}\n",
-	"Network Data Entries",
-	meta_data.netdb,
+	"NetDB Address Entries",
+	meta_data.netdb_addrs,
 	(int) sizeof(netdbEntry),
-	(int) (meta_data.netdb * sizeof(netdbEntry) >> 10));
+	(int) (meta_data.netdb_addrs * sizeof(netdbEntry) >> 10));
+
+    storeAppendPrintf(sentry, "{\t%-25.25s %7d x %4d bytes = %6d KB}\n",
+	"NetDB Host Entries",
+	meta_data.netdb_hosts,
+	(int) sizeof(struct _net_db_name),
+	(int) (meta_data.netdb_hosts * sizeof(struct _net_db_name) >> 10));
 #endif
 
     storeAppendPrintf(sentry, "{\t%-25.25s                      = %6d KB}\n",