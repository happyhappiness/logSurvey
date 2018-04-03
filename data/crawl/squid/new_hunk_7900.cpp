void storeFreeEntry(e)
     StoreEntry *e;
{
    int i;

    if (!e)
	fatal_dump("storeFreeEntry: NULL Entry\n");

    debug(20, 5, "storeFreeEntry: Freeing %s\n", e->url);

    if (has_mem_obj(e)) {
	destroy_MemObjectData(e->mem_obj);
	e->mem_obj->data = NULL;
    }
    meta_data.url_strings -= strlen(e->url);
    safe_free(e->url);
