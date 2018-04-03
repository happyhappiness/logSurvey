	fatal_dump("destroy_StoreEntry: NULL Entry");
    if (e->mem_obj)
	destroy_MemObject(e->mem_obj);
    if (e->url) {
	meta_data.url_strings -= strlen(e->url);
	safe_free(e->url);
    } else {
	debug(20, 3, "destroy_StoreEntry: WARNING!  Entry without URL string!\n");
    }
    if (BIT_TEST(e->flag, KEY_URL))
	e->key = NULL;
    else
	safe_free(e->key);
    xfree(e);
    meta_data.store_entries--;
}
