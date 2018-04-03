}

/* get the first ip entry in the storage */
static ipcache_entry *
ipcache_GetFirst()
{
    return (ipcache_entry *) hash_first(ip_table);
}

/* get the next ip entry in the storage for a given search pointer */
static ipcache_entry *
ipcache_GetNext()
{
    return (ipcache_entry *) hash_next(ip_table);
}

static int
ipcache_compareLastRef(ipcache_entry ** e1, ipcache_entry ** e2)
{
    if (!e1 || !e2)
	fatal_dump(NULL);
