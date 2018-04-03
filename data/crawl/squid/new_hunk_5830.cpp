}

void
storeUfsDirDump(StoreEntry * entry, SwapDir * s)
{
    ufsinfo_t *ufsinfo = (ufsinfo_t *) s->fsdata;
    storeAppendPrintf(entry, " %d %d %d",
	s->max_size >> 10,
	ufsinfo->l1,
	ufsinfo->l2);
    dump_cachedir_options(entry, options, s);
}

/*
