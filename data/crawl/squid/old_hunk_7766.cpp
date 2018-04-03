	fatal_dump("destroy_StoreEntry: NULL Entry");
    if (e->mem_obj)
	destroy_MemObject(e->mem_obj);
    xfree(e);
    meta_data.store_entries--;
}
