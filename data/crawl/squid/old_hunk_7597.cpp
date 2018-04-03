
    /* Kick LRU out until we have enough memory space */
    for (i = 0; i < list_count; i++) {
	if (meta_data.hot_vm > store_hotobj_low) {
	    storePurgeMem(*(list + i));
	    n_purged++;
	} else if ((store_mem_size + size) > store_mem_low) {
	    storePurgeMem(*(list + i));
	    n_purged++;
	} else
	    break;
    }

    debug(20, 2, "storeGetMemSpace: After freeing size: %7d bytes\n", store_mem_size);
    debug(20, 2, "storeGetMemSpace: Purged:             %7d items\n", n_purged);
    if (meta_data.hot_vm > store_hotobj_high) {
	if (squid_curtime - last_warning > 600) {
	    debug(20, 0, "WARNING: Over hot_vm object count (%d > %d)\n",
		meta_data.hot_vm, store_hotobj_high);
	    debug(20, 0, "       : %d objects locked in memory\n", n_locked);
	    debug(20, 0, "       : purged %d of %d candidates\n",
		n_purged,
		list_count);
	    last_warning = squid_curtime;
	}
    } else if ((store_mem_size + size) > store_mem_high) {
	if (squid_curtime - last_warning > 600) {
	    debug(20, 0, "WARNING: Over store_mem high-water mark (%d > %d)\n",
		store_mem_size + size, store_mem_high);
	    debug(20, 0, "       : %d objects locked in memory\n", n_locked);
	    debug(20, 0, "       : released %d of %d candidates\n",
		n_purged,
		list_count);
	    last_warning = squid_curtime;
	}
    }
    debug(20, 2, "storeGetMemSpace: Done.\n");
    xfree(list);
    return 0;
}