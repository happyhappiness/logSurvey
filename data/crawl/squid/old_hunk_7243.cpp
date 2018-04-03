    e->mem_obj = NULL;
}

/* lock the object for reading, start swapping in if necessary */
/* Called by:
 * icpProcessRequest()
 * storeAbort()
 * {http,ftp,gopher,wais}Start()
 */
void
storeLockObject(StoreEntry * e, SIH * callback, void *callback_data)
{
    lock_ctrl_t *ctrlp;
    e->lock_count++;
    debug(20, 3, "storeLockObject: key '%s' count=%d\n",
	e->key, (int) e->lock_count);
    if (e->mem_status != NOT_IN_MEMORY)
	(void) 0;
    else if (e->swap_status == SWAP_OK)
	(void) 0;
    else if (e->store_status == STORE_PENDING)
	(void) 0;
    else
	fatal_dump(storeDescribeStatus(e));
    e->lastref = squid_curtime;
    /* If the object is NOT_IN_MEMORY, fault it in. */
    if (e->mem_status == NOT_IN_MEMORY && e->swap_status == SWAP_OK) {
	/* object is in disk and no swapping daemon running. Bring it in. */
	if (callback == NULL)
	    debug_trap("storeLockObject: NULL callback\n");
	ctrlp = xmalloc(sizeof(lock_ctrl_t));
	ctrlp->callback = callback;
	ctrlp->callback_data = callback_data;
	ctrlp->e = e;
	storeSwapInStart(e, storeLockObjectComplete, ctrlp);
    } else {
	if (callback)
	    (callback) (callback_data, 0);
    }
}

static void
storeLockObjectComplete(void *data, int status)
{
    lock_ctrl_t *ctrlp = (lock_ctrl_t *) data;
    if (status < 0)
	ctrlp->e->lock_count--;
    if (ctrlp->callback)
	(ctrlp->callback) (ctrlp->callback_data, status);
    xfree(ctrlp);
}

void
