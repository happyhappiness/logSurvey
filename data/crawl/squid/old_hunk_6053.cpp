    storeAppendPrintf(sentry, "Current Capacity       : %d%% used, %d%% free\n",
	percent((int) store_swap_size, (int) Config.Swap.maxSize),
	percent((int) (Config.Swap.maxSize - store_swap_size), (int) Config.Swap.maxSize));
    storeUfsDirStats(sentry);	/* XXX */
}

int
storeDirMapBitsInUse(void)
{
    int i;
    int n = 0;
    for (i = 0; i < Config.cacheSwap.n_configured; i++)
	n += Config.cacheSwap.swapDirs[i].map->n_files_in_map;
    return n;
}

void
