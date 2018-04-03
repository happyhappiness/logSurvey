dynamic_array *cache_dirs = NULL;
int ncache_dirs = 0;

/* Allocate memory for a new store structure */
StoreEntry *create_StoreEntry()
{
    StoreEntry *e = NULL;

    e = (StoreEntry *) xcalloc(1, sizeof(StoreEntry));
    e->mem_obj = (MemObject *) xcalloc(1, sizeof(MemObject));
    meta_data.store_in_mem_objects++;

    return (e);
}

StoreEntry *create_StoreEntry_only()
{
    return ((StoreEntry *) xcalloc(1, sizeof(StoreEntry)));
}

/* Free memory of a store structure */
/* free a StoreEntry */
void destroy_StoreEntry(e)
     StoreEntry *e;
{
    if (e) {
	if (e->mem_obj) {
	    meta_data.store_in_mem_objects--;
	    xfree(e->mem_obj);
	}
	safe_free(e);
    }
}


/* free unused memory while object is not in memory */
void destroy_store_mem_obj(e)
     StoreEntry *e;
{
    if (e && e->mem_obj) {
	safe_free(e->mem_obj->mime_hdr);
	safe_free(e->mem_obj);
	meta_data.store_in_mem_objects--;
    }
}

/* Check if there is memory allocated for object in memory */
int has_mem_obj(e)
     StoreEntry *e;
{
    if (e && e->mem_obj)
	return (TRUE);
    return (FALSE);
}

/* allocate memory for swapping object in memory */
void create_store_mem_obj(e)
     StoreEntry *e;
{
    if (e) {
	if (has_mem_obj(e))
	    debug(20, 1, "create_store_mem_obj: old memory not released\n");
	e->mem_obj = (MemObject *) xcalloc(1, sizeof(MemObject));
	meta_data.store_in_mem_objects++;
    }
}

/* ----- INTERFACE BETWEEN STORAGE MANAGER AND HASH TABLE FUNCTIONS --------- */
