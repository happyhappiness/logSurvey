 	meta_data.netdb_hosts,
 	(int) sizeof(struct _net_db_name),
 	             (int) (meta_data.netdb_hosts * sizeof(struct _net_db_name) >> 10));
-#endif
+
     storeAppendPrintf(sentry, "{\t%-25.25s %7d x %4d bytes = %6d KB}\n",
 	"ClientDB Entries",
 	meta_data.client_info,
