 	(int) sizeof(ipcache_entry),
 	(int) (meta_data.ipcache_count * sizeof(ipcache_entry) >> 10));
 
+    storeAppendPrintf(sentry, "{\t%-25.25s %7d x %4d bytes = %6d KB}\n",
+	"FQDNCacheEntry",
+	meta_data.fqdncache_count,
+	(int) sizeof(fqdncache_entry),
+	(int) (meta_data.fqdncache_count * sizeof(fqdncache_entry) >> 10));
+
     storeAppendPrintf(sentry, "{\t%-25.25s %7d x %4d bytes = %6d KB}\n",
 	"Hash link",
 	meta_data.hash_links = hash_links_allocated,