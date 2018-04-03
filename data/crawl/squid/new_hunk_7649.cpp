
    if (e->mem_status != NOT_IN_MEMORY)
	/* ok, its either IN_MEMORY or SWAPPING_IN */
	debug(20, 5, "storeLockObject: OK: mem_status is %s\n", memStatusStr[e->mem_status]);
    else if (e->swap_status == SWAP_OK)
	/* ok, its NOT_IN_MEMORY, but its swapped out */
	debug(20, 5, "storeLockObject: OK: swap_status is %s\n", swapStatusStr[e->swap_status]);
    else if (e->store_status == STORE_PENDING)
	/* ok, we're reading it in right now */
	debug(20, 5, "storeLockObject: OK: store_status is %s\n", storeStatusStr[e->store_status]);
    else
	fatal_dump(storeDescribeStatus(e));
    e->lastref = squid_curtime;

