dynamic_array *cache_dirs = NULL;
int ncache_dirs = 0;

static MemObject *new_MemObject()
{
    MemObject *m = NULL;
    m = xcalloc(1, sizeof(MemObject));
    meta_data.store_in_mem_objects++;
    debug(20, 3, "new_MemObject: returning %p\n", m);
    return m;
}

static StoreEntry *new_StoreEntry(mem_obj_flag)
{
    StoreEntry *e = NULL;

    e = (StoreEntry *) xcalloc(1, sizeof(StoreEntry));
    meta_data.store_entries++;
    if (mem_obj_flag)
	e->mem_obj = new_MemObject();
    debug(20, 3, "new_StoreEntry: returning %p\n", e);
    return e;
}

static void destroy_MemObject(m)
     MemObject *m;
{
    debug(20, 3, "destroy_MemObject: destroying %p\n", m);
    xfree(m);
    if (m->mime_hdr)
	xfree(m->mime_hdr);
    meta_data.store_in_mem_objects--;
}

static void destroy_StoreEntry(e)
     StoreEntry *e;
{
    debug(20, 3, "destroy_StoreEntry: destroying %p\n", e);
    if (!e)
	fatal_dump("destroy_StoreEntry: NULL Entry\n");
    if (e->mem_obj)
	destroy_MemObject(e->mem_obj);
    xfree(e);
    meta_data.store_entries--;
}

static mem_ptr new_MemObjectData()
{
    debug(20, 3, "new_MemObjectData: calling memInit()\n");
    meta_data.hot_vm++;
    return memInit();
}

static void destroy_MemObjectData(m)
     MemObject *m;
{
    debug(20, 3, "destroy_MemObjectData: destroying %p\n", m->data);
    store_mem_size -= m->e_current_len - m->e_lowest_offset;
    debug(20, 8, "destroy_MemObjectData: Freeing %d in-memory bytes\n",
	m->e_current_len);
    debug(20, 8, "destroy_MemObjectData: store_mem_size = %d\n",
	store_mem_size);
    if (m->data) {
	m->data->mem_free(m->data);
	m->data = NULL;
	meta_data.hot_vm--;
    }
    m->e_current_len = 0;
}

/* Check if there is memory allocated for object in memory */
int has_mem_obj(e)
     StoreEntry *e;
{
    if (!e)
	fatal_dump("has_mem_obj: NULL Entry\n");
    if (e->mem_obj)
	return 1;
    return 0;
}

/* ----- INTERFACE BETWEEN STORAGE MANAGER AND HASH TABLE FUNCTIONS --------- */
