     StoreEntry *e;
{
    if (!e)
	fatal_dump("has_mem_obj: NULL Entry");
    if (e->mem_obj)
	return 1;
    return 0;
