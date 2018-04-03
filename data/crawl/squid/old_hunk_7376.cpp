 * storeAbort()
 * {http,ftp,gopher,wais}Start()
 */
int
storeLockObject(StoreEntry * e, SIH handler, void *data)
{
    int status = 0;
    e->lock_count++;
    debug(20, 3, "storeLockObject: key '%s' count=%d\n",
	e->key, (int) e->lock_count);
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
    /* If the object is NOT_IN_MEMORY, fault it in. */
    if ((e->mem_status == NOT_IN_MEMORY) && (e->swap_status == SWAP_OK)) {
	/* object is in disk and no swapping daemon running. Bring it in. */
	if ((status = storeSwapInStart(e, handler, data)) < 0) {
	    /* We couldn't find or couldn't open object's swapfile.
	     * So, return a -1 here, indicating that we will treat
	     * the reference like a MISS_TTL, force a keychange and
	     storeRelease.  */
	    e->lock_count--;
	}
    } else if (e->mem_status == IN_MEMORY && handler) {
	/* its already in memory, so call the handler */
	handler(0, data);
    } else if (handler) {
	/* The object is probably in state SWAPPING_IN, not much we can do.
	 * Instead of returning failure here, we should have a list of complete
	 * handlers which we could append to... */
	handler(1, data);
    }
    return status;
}

void
