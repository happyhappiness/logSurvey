    MemObject *mem = NULL;

    /* sanity check! */
    if (e->swap_status != SWAP_OK)
	fatal_dump("storeSwapInStart: bad swap_status");
    if (e->swap_file_number < 0)
	fatal_dump("storeSwapInStart: bad swap_file_number");
    if (e->mem_obj)
	fatal_dump("storeSwapInStart: mem_obj already present");

    e->mem_obj = mem = new_MemObject();

