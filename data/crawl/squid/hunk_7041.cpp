 	if (sm_stats.n_pages_in_use + pages_needed < store_pages_low)
 	    break;
     }
-
-#if OLD_CODE
-    list = xcalloc(meta_data.mem_obj_count, sizeof(ipcache_entry *));
-    for (e = storeGetInMemFirst(); e; e = storeGetInMemNext()) {
-	if (list_count == meta_data.mem_obj_count)
-	    break;
-	if (storeEntryLocked(e))
-	    continue;
-	if (storeCheckExpired(e, 0)) {
-	    debug(20, 2) ("storeGetMemSpace: Expired: %s\n", e->url);
-	    n_expired++;
-	    storeRelease(e);
-	} else if (storeCheckPurgeMem(e)) {
-	    debug(20, 3) ("storeGetMemSpace: Adding '%s'\n", e->url);
-	    *(list + list_count) = e;
-	    list_count++;
-	} else if (!storeEntryLocked(e)) {
-	    debug(20, 3) ("storeGetMemSpace: Adding '%s'\n", e->url);
-	    *(list + list_count) = e;
-	    list_count++;
-	} else {
-	    n_locked++;
-	}
-    }
-    debug(20, 5) ("storeGetMemSpace: Sorting LRU_list: %7d items\n", list_count);
-    qsort((char *) list,
-	list_count,
-	sizeof(StoreEntry *),
-	(QS *) compareSize);
-    /* Kick LRU out until we have enough memory space */
-    for (i = 0; i < list_count; i++) {
-	if (sm_stats.n_pages_in_use + pages_needed < store_pages_low)
-	    break;
-	e = *(list + i);
-	if (storeCheckPurgeMem(e)) {
-	    storePurgeMem(e);
-	    n_purged++;
-	} else if (!storeEntryLocked(e)) {
-	    /* These will be neg-cached objects */
-	    n_released += storeRelease(e);
-	} else {
-	    fatal_dump("storeGetMemSpace: Bad Entry in LRU list");
-	}
-    }
-    i = 3;
-    if (sm_stats.n_pages_in_use > store_pages_max) {
-	if (sm_stats.n_pages_in_use > last_warning * 1.10) {
-	    debug(20, 0) ("WARNING: Exceeded 'cache_mem' size (%dK > %dK)\n",
-		sm_stats.n_pages_in_use * 4, store_pages_max * 4);
-	    last_warning = sm_stats.n_pages_in_use;
-	    debug(20, 0) ("Perhaps you should increase cache_mem?\n");
-	    i = 0;
-	}
-    }
-    debug(20, i) ("storeGetMemSpace stats:\n");
-    debug(20, i) ("  %6d objects locked in memory\n", n_locked);
-    debug(20, i) ("  %6d LRU candidates\n", list_count);
-    debug(20, i) ("  %6d were purged\n", n_purged);
-    debug(20, i) ("  %6d were released\n", n_released);
-    xfree(list);
-#endif
-
     debug(20, 0) ("storeGetMemSpace stats:\n");
     debug(20, 0) ("  %6d HOT objects\n", meta_data.hot_vm);
     debug(20, 0) ("  %6d were purged\n", n_purged);
     debug(20, 0) ("  %6d were released\n", n_released);
 }
 
-#if OLD_CODE
-static int
-compareSize(StoreEntry ** e1, StoreEntry ** e2)
-{
-    if (!e1 || !e2)
-	fatal_dump(NULL);
-    if ((*e1)->mem_obj->inmem_hi > (*e2)->mem_obj->inmem_hi)
-	return (1);
-    if ((*e1)->mem_obj->inmem_hi < (*e2)->mem_obj->inmem_hi)
-	return (-1);
-    return (0);
-}
-#endif
-
 static int
 compareLastRef(StoreEntry ** e1, StoreEntry ** e2)
 {
