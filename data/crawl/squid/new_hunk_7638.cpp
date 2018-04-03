    return store_table;
}

static void storeHashMemInsert(e)
     StoreEntry *e;
{
    hash_insert(in_mem_table, e->key, e);
    meta_data.hot_vm++;
}

static void storeHashMemDelete(e)
     StoreEntry *e;
{
    hash_link *hptr = hash_lookup(in_mem_table, e->key);
    if (hptr == NULL)
	fatal_dump("storeHashMemDelete: key not found");
    hash_delete_link(in_mem_table, hptr);
    meta_data.hot_vm--;
}

static int storeHashInsert(e)
     StoreEntry *e;
{
    debug(20, 3, "storeHashInsert: Inserting Entry %p key '%s'\n",
	e, e->key);
    if (e->mem_status == IN_MEMORY)
	storeHashMemInsert(e);
    return hash_join(store_table, (hash_link *) e);
}

static int storeHashDelete(e)
     StoreEntry *e;
{
    if (e->mem_status == IN_MEMORY)
	storeHashMemDelete(e);
    return hash_remove_link(store_table, (hash_link *) e);
}

/*
 * maintain the in-mem hash table according to the changes of mem_status
 * This routine replaces the instruction "e->store_status = status;"
 */
void storeSetMemStatus(e, status)
     StoreEntry *e;
     mem_status_t status;
{
    if (e->key == NULL)
	fatal_dump("storeSetMemStatus: NULL key");
    if (status != IN_MEMORY && e->mem_status == IN_MEMORY)
	storeHashMemDelete(e);
    else if (status == IN_MEMORY && e->mem_status != IN_MEMORY)
	storeHashMemInsert(e);
    e->mem_status = status;
}

