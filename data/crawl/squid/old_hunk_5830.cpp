}

void
storeUfsDirDump(StoreEntry * entry, const char *name, SwapDir * s)
{
    ufsinfo_t *ufsinfo = (ufsinfo_t *) s->fsdata;
    storeAppendPrintf(entry, "%s %s %s %d %d %d\n",
	name,
	"ufs",
	s->path,
	s->max_size >> 10,
	ufsinfo->l1,
	ufsinfo->l2);
}

/*
