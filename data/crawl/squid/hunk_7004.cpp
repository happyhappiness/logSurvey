 	(int) (meta_data.store_entries * sizeof(StoreEntry) >> 10));
 
     storeAppendPrintf(sentry, "{\t%-25.25s                      = %6d KB}\n",
-	"URL strings",
-	meta_data.url_strings >> 10);
+	"StoreEntry Keys",
+	meta_data.store_keys >> 10);
 
     storeAppendPrintf(sentry, "{\t%-25.25s %7d x %4d bytes = %6d KB}\n",
 	"IPCacheEntry",
