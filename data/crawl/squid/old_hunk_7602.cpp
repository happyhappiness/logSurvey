

/* get rid of memory copy of the object */
void storePurgeMem(e)
     StoreEntry *e;
{
    debug(20, 3, "storePurgeMem: Freeing memory-copy of %s\n", e->key);
    if (e->mem_obj == NULL)
	return;
    if (storeEntryLocked(e)) {
	debug(20, 0, "storePurgeMem: someone is purging a locked object?\n");
	debug(20, 0, "%s", storeToString(e));
	fatal_dump(NULL);
    }
    storeSetMemStatus(e, NOT_IN_MEMORY);
    destroy_MemObject(e->mem_obj);
    e->mem_obj = NULL;
}

/* lock the object for reading, start swapping in if necessary */
/* Called by:
 * icp_hit_or_miss()
 * storeAbort()
 * {http,ftp,gopher,wais}Start()
 */
