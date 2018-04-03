    MemObject *mem = NULL;

    /* sanity check! */
    if (e->swap_status != SWAP_OK) {
	debug_trap("storeSwapInStart: bad swap_status");
	return -1;
    } else if (e->swap_file_number < 0) {
	debug_trap("storeSwapInStart: bad swap_file_number");
	return -1;
    } else if (e->mem_obj) {
	debug_trap("storeSwapInStart: mem_obj already present");
	return -1;
    }

    e->mem_obj = mem = new_MemObject();

