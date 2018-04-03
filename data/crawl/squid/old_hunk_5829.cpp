}

void
storeDiskdDirDump(StoreEntry * entry, const char *name, SwapDir * s)
{
    diskdinfo_t *diskdinfo = s->fsdata;
    storeAppendPrintf(entry, "%s %s %s %d %d %d\n",
	name,
	"diskd",
	s->path,
	s->max_size >> 10,
	diskdinfo->l1,
	diskdinfo->l2);
}

/*
