void
storeDiskdDirDump(StoreEntry * entry, const char *name, SwapDir * s)
{
    diskdinfo_t *diskdinfo = (diskdinfo_t *)s->fsdata;
    storeAppendPrintf(entry, "%s %s %s %d %d %d\n",
	name,
        "diskd",
	s->path,
	s->max_size >> 10,
	diskdinfo->l1,
