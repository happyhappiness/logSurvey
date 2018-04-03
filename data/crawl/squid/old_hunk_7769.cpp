{
    if (e->flag & RELEASE_REQUEST)
	return;
    debug(20, 3, "storeReleaseRequest: FOR '%s'\n", e->key ? e->key : e->url);
    e->flag |= RELEASE_REQUEST;
}

/* unlock object, return -1 if object get released after unlock
 * otherwise lock_count */

int storeUnlockObject(e)
     StoreEntry *e;
{
    int e_lock_count;


    if ((int) e->lock_count > 0)
	e->lock_count--;
