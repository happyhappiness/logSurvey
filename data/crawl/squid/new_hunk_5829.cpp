}

void
storeDiskdDirDump(StoreEntry * entry, SwapDir * s)
{
    diskdinfo_t *diskdinfo = s->fsdata;
    storeAppendPrintf(entry, " %d %d %d",
	s->max_size >> 10,
	diskdinfo->l1,
	diskdinfo->l2);
    dump_cachedir_options(entry, options, s);
}

/*
