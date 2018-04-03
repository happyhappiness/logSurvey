     storeAppendPrintf(sentry, "\t%6d StoreEntries with MemObject Data\n",
 	memInUse(MEM_MEM_HDR));
     storeAppendPrintf(sentry, "\t%6d Hot Object Cache Items\n",
-	meta_data.hot_vm);
-
-    storeAppendPrintf(sentry, "\t%-25.25s                      = %6d KB\n",
-	"StoreEntry Keys",
-	meta_data.store_keys >> 10);
-
-    storeAppendPrintf(sentry, "\t%-25.25s %7d x %4d bytes = %6d KB\n",
-	"IPCacheEntry",
-	meta_data.ipcache_count,
-	(int) sizeof(ipcache_entry),
-	(int) (meta_data.ipcache_count * sizeof(ipcache_entry) >> 10));
-
-    storeAppendPrintf(sentry, "\t%-25.25s %7d x %4d bytes = %6d KB\n",
-	"FQDNCacheEntry",
-	meta_data.fqdncache_count,
-	(int) sizeof(fqdncache_entry),
-	(int) (meta_data.fqdncache_count * sizeof(fqdncache_entry) >> 10));
-
-    storeAppendPrintf(sentry, "\t%-25.25s %7d x %4d bytes = %6d KB\n",
-	"Hash link",
-	hash_links_allocated,
-	(int) sizeof(hash_link),
-	(int) (hash_links_allocated * sizeof(hash_link) >> 10));
-
-    storeAppendPrintf(sentry, "\t%-25.25s %7d x %4d bytes = %6d KB\n",
-	"NetDB Peer Entries",
-	meta_data.netdb_peers,
-	(int) sizeof(struct _net_db_peer),
-	             (int) (meta_data.netdb_peers * sizeof(struct _net_db_peer) >> 10));
-
-    storeAppendPrintf(sentry, "\t%-25.25s %7d x %4d bytes = %6d KB\n",
-	"ClientDB Entries",
-	meta_data.client_info,
-	client_info_sz,
-	(int) (meta_data.client_info * client_info_sz >> 10));
-
-    storeAppendPrintf(sentry, "\t%-25.25s                      = %6d KB\n",
-	"Miscellaneous",
-	meta_data.misc >> 10);
-
-    storeAppendPrintf(sentry, "\t%-25.25s                      = %6d KB\n",
-	"Total Accounted",
-	statMemoryAccounted() >> 10);
+	hot_obj_count);
 
 #if XMALLOC_STATISTICS
     storeAppendPrintf(sentry, "Memory allocation statistics\n");
