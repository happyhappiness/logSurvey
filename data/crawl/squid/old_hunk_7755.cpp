	}
    }
    storeAppendPrintf(sentry, "{Internal Data Structures:}\n");
    storeAppendPrintf(sentry, "{Meta Data:}\n");

    storeAppendPrintf(sentry, "{\t\tStoreEntry %d x %d bytes = %d KB}\n",
	meta_data.store_entries,
	(int) sizeof(StoreEntry),
	(int) (meta_data.store_entries * sizeof(StoreEntry) >> 10));

    storeAppendPrintf(sentry, "{\t\tStoreMemObject %d x %d bytes = %d KB}\n",
	meta_data.store_in_mem_objects,
	(int) sizeof(MemObject),
	(int) (meta_data.store_in_mem_objects * sizeof(MemObject) >> 10));

    storeAppendPrintf(sentry, "{\t\tIPCacheEntry %d x %d bytes = %d KB}\n",
	meta_data.ipcache_count,
	(int) sizeof(ipcache_entry),
	(int) (meta_data.ipcache_count * sizeof(ipcache_entry) >> 10));

    storeAppendPrintf(sentry, "{\t\tHash link  %d x %d bytes = %d KB}\n",
	meta_data.hash_links = hash_links_allocated,
	(int) sizeof(hash_link),
	(int) (meta_data.hash_links * sizeof(hash_link) >> 10));

    storeAppendPrintf(sentry, "{\t\tURL strings %d KB}\n",
	meta_data.url_strings >> 10);

    storeAppendPrintf(sentry, "{\t\tHot Object Cache Items %d}\n", meta_data.hot_vm);

    storeAppendPrintf(sentry, "{\t\tPool for disk I/O %d KB (Free %d KB)}\n",
	disk_stats.total_pages_allocated * disk_stats.page_size >> 10,
	(disk_stats.total_pages_allocated - disk_stats.n_pages_in_use) * disk_stats.page_size >> 10);

    storeAppendPrintf(sentry, "{\t\tPool for in-memory objects %d KB (Free %d KB)}\n",
	sm_stats.total_pages_allocated * sm_stats.page_size >> 10,
	(sm_stats.total_pages_allocated - sm_stats.n_pages_in_use) * sm_stats.page_size >> 10);

    storeAppendPrintf(sentry, "{\tTotal Accounted %d KB}\n",
	(int) (meta_data.store_entries * sizeof(StoreEntry) +
	    meta_data.store_in_mem_objects * sizeof(MemObject) +
	    meta_data.ipcache_count * sizeof(ipcache_entry) +
	    meta_data.hash_links * sizeof(hash_link) +
	    sm_stats.total_pages_allocated * sm_stats.page_size +
	    disk_stats.total_pages_allocated * disk_stats.page_size +
	    meta_data.url_strings) >> 10);

    storeAppendPrintf(sentry, "}\n");
}


