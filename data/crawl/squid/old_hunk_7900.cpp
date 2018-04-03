void storeFreeEntry(e)
     StoreEntry *e;
{
    meta_data.store_entries--;

    if (e == (StoreEntry *) NULL)
	return;

    debug(20, 5, "storeFreeEntry: Freeing %s\n", e->url);

    if (has_mem_obj(e)) {
	store_mem_size -= e->mem_obj->e_current_len - e->mem_obj->e_lowest_offset;
	debug(20, 8, "storeFreeEntry: Freeing %d in-memory bytes\n",
	    e->mem_obj->e_current_len);
	debug(20, 8, "storeFreeEntry: store_mem_size = %d\n", store_mem_size);
	if (e->mem_obj->data) {
	    e->mem_obj->data->mem_free(e->mem_obj->data);
	    e->mem_obj->data = NULL;
	    --meta_data.hot_vm;
	}
    }
    meta_data.url_strings -= strlen(e->url);
    safe_free(e->url);
