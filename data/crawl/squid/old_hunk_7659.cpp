    e->lock_count++;
    debug(20, 3, "storeLockObject: locks %d: '%s'\n", e->lock_count, e->key);

    if ((e->mem_status == NOT_IN_MEMORY) &&	/* Not in memory */
	(e->swap_status != SWAP_OK) &&	/* Not on disk */
	(e->store_status != STORE_PENDING)	/* Not being fetched */
	) {
	debug(20, 0, "storeLockObject: NOT_IN_MEMORY && !SWAP_OK && !STORE_PENDING conflict: <URL:%s>. aborting...\n", e->url);
	/* If this sanity check fails, we should just ... */
	fatal_dump(NULL);
    }
    e->lastref = squid_curtime;

    /* If the object is NOT_IN_MEMORY, fault it in. */
