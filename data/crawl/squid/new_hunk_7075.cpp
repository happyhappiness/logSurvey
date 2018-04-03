}

static void
dump_cachedir(StoreEntry * entry, const char *name, struct _cacheSwap swap)
{
    SwapDir *s;
    int i;
    for (i = 0; i<swap.n_configured; i++) {
	s = swap.swapDirs+i;
	storeAppendPrintf(entry, "%s %s %d %d %d\n",
	    name,
	    s->path,
	    s->max_size>>10,
	    s->l1,
	    s->l2);
    }
}

static int
check_null_cachedir(struct _cacheSwap swap)
{
    return swap.swapDirs == NULL;
}

static void
