    return store_table;
}

/*
 * if object is in memory, also insert into in_mem_table
 */

static int storeHashInsert(e)
     StoreEntry *e;
{
    debug(20, 3, "storeHashInsert: Inserting Entry %p key '%s'\n",
	e, e->key);
    if (e->mem_status == IN_MEMORY)
	hash_insert(in_mem_table, e->key, e);
    return (hash_join(store_table, (hash_link *) e));
}

/*
 * if object in memory, also remove from in_mem_table
 */

static int storeHashDelete(e)
     StoreEntry *e;
{
    hash_link *hptr = NULL;
    if (e->mem_status == IN_MEMORY && e->key) {
	if ((hptr = hash_lookup(in_mem_table, e->key)))
	    hash_delete_link(in_mem_table, hptr);
    }
    return (hash_remove_link(store_table, (hash_link *) e));
}

/*
 * maintain the in-mem hash table according to the changes of mem_status
 * This routine replaces the instruction "e->store_status = status;"
 */

void storeSetMemStatus(e, status)
     StoreEntry *e;
     mem_status_t status;
{
    hash_link *ptr = NULL;

    if (e->key == NULL)
	fatal_dump("storeSetMemStatus: NULL key");

    if (status != IN_MEMORY && e->mem_status == IN_MEMORY) {
	if ((ptr = hash_lookup(in_mem_table, e->key)))
	    hash_delete_link(in_mem_table, ptr);
    } else if (status == IN_MEMORY && e->mem_status != IN_MEMORY) {
	hash_insert(in_mem_table, e->key, e);
    }
    e->mem_status = status;
}

