     StoreEntry *e;
{
    if (!e)
	fatal_dump("has_mem_obj: NULL Entry\n");
    if (e->mem_obj)
	return 1;
    return 0;
