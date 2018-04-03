    MemObject *mem = NULL;
    swapin_ctrl_t *ctrlp = (swapin_ctrl_t *) data;
    StoreEntry *e = ctrlp->e;
    if (fd < 0) {
	debug(20, 0, "storeSwapInStartComplete: Failed for '%s'\n", e->url);
	if (!e->mem_obj)
	    storeSetMemStatus(e, NOT_IN_MEMORY);
	/* Invoke a store abort that should free the memory object */
	(ctrlp->callback) (ctrlp->callback_data, -1);
	xfree(ctrlp->path);
	xfree(ctrlp);
	return;
    }
    if (e->mem_obj)
	fatal_dump("storeSwapInStartComplete already exists");
    if (e->swap_status != SWAP_OK)
	fatal_dump("storeSwapInStartComplete: bad swap_status");
    storeSetMemStatus(e, SWAPPING_IN);
    mem = e->mem_obj = new_MemObject();
    mem->swapin_fd = (short) fd;
