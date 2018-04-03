     StoreEntry *e;
     mem_status_t status;
{
    if (e->key == NULL)
	fatal_dump("storeSetMemStatus: NULL key");
    if (status != IN_MEMORY && e->mem_status == IN_MEMORY)
	storeHashMemDelete(e);
    else if (status == IN_MEMORY && e->mem_status != IN_MEMORY)
	storeHashMemInsert(e);
