    MemObject *mem = NULL;
    swapin_ctrl_t *ctrlp = (swapin_ctrl_t *) data;
    StoreEntry *e = ctrlp->e;
    assert(e->mem_obj == NULL);
    assert(e->mem_status == NOT_IN_MEMORY);
    assert(e->swap_status == SWAP_OK);
    if (fd < 0) {
	debug(20, 0, "storeSwapInStartComplete: Failed for '%s'\n", e->url);
	/* Invoke a store abort that should free the memory object */
	(ctrlp->callback) (ctrlp->callback_data, -1);
	xfree(ctrlp->path);
	xfree(ctrlp);
	return;
    }
    storeSetMemStatus(e, SWAPPING_IN);
    mem = e->mem_obj = new_MemObject();
    mem->swapin_fd = (short) fd;
