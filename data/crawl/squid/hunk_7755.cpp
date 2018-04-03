 	}
     }
     storeAppendPrintf(sentry, "{Internal Data Structures:}\n");
+    storeAppendPrintf(sentry, "{\tHot Object Cache Items %d}\n",
+	meta_data.hot_vm);
+    storeAppendPrintf(sentry, "{\tStoreEntries with MemObjects %d}\n",
+	meta_data.store_in_mem_objects);
+
     storeAppendPrintf(sentry, "{Meta Data:}\n");
 
-    storeAppendPrintf(sentry, "{\t\tStoreEntry %d x %d bytes = %d KB}\n",
+    storeAppendPrintf(sentry, "{\t%-25.25s %7d x %4d bytes = %6d KB}\n",
+	"StoreEntry",
 	meta_data.store_entries,
 	(int) sizeof(StoreEntry),
 	(int) (meta_data.store_entries * sizeof(StoreEntry) >> 10));
 
-    storeAppendPrintf(sentry, "{\t\tStoreMemObject %d x %d bytes = %d KB}\n",
-	meta_data.store_in_mem_objects,
-	(int) sizeof(MemObject),
-	(int) (meta_data.store_in_mem_objects * sizeof(MemObject) >> 10));
-
-    storeAppendPrintf(sentry, "{\t\tIPCacheEntry %d x %d bytes = %d KB}\n",
+    storeAppendPrintf(sentry, "{\t%-25.25s %7d x %4d bytes = %6d KB}\n",
+	"IPCacheEntry",
 	meta_data.ipcache_count,
 	(int) sizeof(ipcache_entry),
 	(int) (meta_data.ipcache_count * sizeof(ipcache_entry) >> 10));
 
-    storeAppendPrintf(sentry, "{\t\tHash link  %d x %d bytes = %d KB}\n",
+    storeAppendPrintf(sentry, "{\t%-25.25s %7d x %4d bytes = %6d KB}\n",
+	"Hash link",
 	meta_data.hash_links = hash_links_allocated,
 	(int) sizeof(hash_link),
 	(int) (meta_data.hash_links * sizeof(hash_link) >> 10));
 
-    storeAppendPrintf(sentry, "{\t\tURL strings %d KB}\n",
+    storeAppendPrintf(sentry, "{\t%-25.25s                      = %6d KB}\n",
+	"URL strings",
 	meta_data.url_strings >> 10);
 
-    storeAppendPrintf(sentry, "{\t\tHot Object Cache Items %d}\n", meta_data.hot_vm);
+    storeAppendPrintf(sentry, "{\t%-25.25s %7d x %4d bytes = %6d KB (%6d free)}\n",
+	"Pool MemObject structures",
+	mem_obj_pool.total_pages_allocated,
+	mem_obj_pool.page_size,
+	mem_obj_pool.total_pages_allocated * mem_obj_pool.page_size >> 10,
+	(mem_obj_pool.total_pages_allocated - mem_obj_pool.n_pages_in_use) * mem_obj_pool.page_size >> 10);
+
+    storeAppendPrintf(sentry, "{\t%-25.25s %7d x %4d bytes = %6d KB (%6d free)}\n",
+	"Pool for Request structures",
+	request_pool.total_pages_allocated,
+	request_pool.page_size,
+	request_pool.total_pages_allocated * request_pool.page_size >> 10,
+	(request_pool.total_pages_allocated - request_pool.n_pages_in_use) * request_pool.page_size >> 10);
+
+    storeAppendPrintf(sentry, "{\t%-25.25s %7d x %4d bytes = %6d KB (%6d free)}\n",
+	"Pool for in-memory object data",
+	sm_stats.total_pages_allocated,
+	sm_stats.page_size,
+	sm_stats.total_pages_allocated * sm_stats.page_size >> 10,
+	(sm_stats.total_pages_allocated - sm_stats.n_pages_in_use) * sm_stats.page_size >> 10);
 
-    storeAppendPrintf(sentry, "{\t\tPool for disk I/O %d KB (Free %d KB)}\n",
+    storeAppendPrintf(sentry, "{\t%-25.25s %7d x %4d bytes = %6d KB (%6d free)}\n",
+	"Pool for disk I/O",
+	disk_stats.total_pages_allocated,
+	disk_stats.page_size,
 	disk_stats.total_pages_allocated * disk_stats.page_size >> 10,
 	(disk_stats.total_pages_allocated - disk_stats.n_pages_in_use) * disk_stats.page_size >> 10);
 
-    storeAppendPrintf(sentry, "{\t\tPool for in-memory objects %d KB (Free %d KB)}\n",
-	sm_stats.total_pages_allocated * sm_stats.page_size >> 10,
-	(sm_stats.total_pages_allocated - sm_stats.n_pages_in_use) * sm_stats.page_size >> 10);
+    storeAppendPrintf(sentry, "{\t%-25.25s                      = %6d KB}\n",
+	"Miscellaneous",
+	meta_data.misc >> 10);
 
-    storeAppendPrintf(sentry, "{\tTotal Accounted %d KB}\n",
+    storeAppendPrintf(sentry, "{\t%-25.25s                      = %6d KB}\n",
+	"Total Accounted",
 	(int) (meta_data.store_entries * sizeof(StoreEntry) +
-	    meta_data.store_in_mem_objects * sizeof(MemObject) +
 	    meta_data.ipcache_count * sizeof(ipcache_entry) +
 	    meta_data.hash_links * sizeof(hash_link) +
 	    sm_stats.total_pages_allocated * sm_stats.page_size +
 	    disk_stats.total_pages_allocated * disk_stats.page_size +
-	    meta_data.url_strings) >> 10);
+	    request_pool.total_pages_allocated * request_pool.page_size +
+	    mem_obj_pool.total_pages_allocated * mem_obj_pool.page_size +
+	    meta_data.url_strings +
+	    meta_data.misc) >> 10);
+
+#if XMALLOC_STATISTICS
+    storeAppendPrintf(sentry, "{Memory allocation statistics}\n");
+    malloc_statistics(info_get_mallstat, sentry);
+#endif
 
-    storeAppendPrintf(sentry, "}\n");
+    storeAppendPrintf(sentry, close_bracket);
 }
 
 
