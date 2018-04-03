    storeAppendPrintf(sentry, "Current Capacity       : %d%% used, %d%% free\n",
	percent((int) store_swap_size, (int) Config.Swap.maxSize),
	percent((int) (Config.Swap.maxSize - store_swap_size), (int) Config.Swap.maxSize));

    /* Now go through each swapdir, calling its statfs routine */
    for (i = 0; i < Config.cacheSwap.n_configured; i++) {
        storeAppendPrintf(sentry, "\n");
        SD = &(Config.cacheSwap.swapDirs[i]);
        storeAppendPrintf(sentry, "Store Directory #%d (%s): %s\n", i, SD->type,
          storeSwapDir(i));
        SD->statfs(SD, sentry);
    }
}

void
