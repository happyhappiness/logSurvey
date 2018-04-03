

/* get rid of memory copy of the object */
/* Only call this if storeCheckPurgeMem(e) returns 1 */
void storePurgeMem(e)
     StoreEntry *e;
{
    debug(20, 3, "storePurgeMem: Freeing memory-copy of %s\n", e->key);
    if (e->mem_obj == NULL)
	return;
    storeSetMemStatus(e, NOT_IN_MEMORY);
    destroy_MemObject(e->mem_obj);
    e->mem_obj = NULL;
}

/* lock the object for reading, start swapping in if necessary */
/* Called by:
 * icpProcessRequest()
 * storeAbort()
 * {http,ftp,gopher,wais}Start()
 */
