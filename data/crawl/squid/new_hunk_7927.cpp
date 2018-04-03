    int status = 0;

    e->lock_count++;
    debug(20, 5, "storeLockObject: locks %d: <URL:%s>\n", e->lock_count, e->url);

    if ((e->mem_status == NOT_IN_MEMORY) &&	/* Not in memory */
	(e->swap_status != SWAP_OK) &&	/* Not on disk */
	(e->status != STORE_PENDING)	/* Not being fetched */
	) {
	debug(20, 0, "storeLockObject: NOT_IN_MEMORY && !SWAP_OK && !STORE_PENDING conflict: <URL:%s>. aborting...\n", e->url);
	/* If this sanity check fails, we should just ... */
	fatal_dump(NULL);
    }
