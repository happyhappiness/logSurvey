 	    /* These will be neg-cached objects */
 	    n_released += storeRelease(e);
 	} else {
-	    debug_trap("storeGetMemSpace: Bad Entry in LRU list");
+	    fatal_dump("storeGetMemSpace: Bad Entry in LRU list");
 	}
     }
 
     i = 3;
     if (sm_stats.n_pages_in_use > store_pages_max) {
-	if (squid_curtime - last_warning > 600) {
+	if (sm_stats.n_pages_in_use > last_warning * 1.05) {
 	    debug(20, 0) ("WARNING: Exceeded 'cache_mem' size (%dK > %dK)\n",
 		sm_stats.n_pages_in_use * 4, store_pages_max * 4);
-	    last_warning = squid_curtime;
+	    last_warning = sm_stats.n_pages_in_use;
 	    debug(20, 0) ("Perhaps you should increase cache_mem?\n");
 	    i = 0;
 	}
