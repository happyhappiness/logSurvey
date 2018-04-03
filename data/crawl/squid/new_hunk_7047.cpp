	    fatal_dump("storeGetMemSpace: Bad Entry in LRU list");
	}
    }
    i = 3;
    if (sm_stats.n_pages_in_use > store_pages_max) {
	if (sm_stats.n_pages_in_use > last_warning * 1.10) {
