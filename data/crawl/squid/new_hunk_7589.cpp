int storeEntryLocked(e)
     StoreEntry *e;
{
    if (e->lock_count)
	return 1;
    if (e->swap_status == SWAPPING_OUT)
