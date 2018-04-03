int storeEntryLocked(e)
     StoreEntry *e;
{
    if (!e) {
	debug(20, 0, "This entry should be valid.\n");
	debug(20, 0, "%s", storeToString(e));
	fatal_dump(NULL);
    }
    if (e->lock_count)
	return 1;
    if (e->swap_status == SWAPPING_OUT)
