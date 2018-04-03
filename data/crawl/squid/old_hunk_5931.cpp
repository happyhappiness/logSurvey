	SD = &(Config.cacheSwap.swapDirs[i]);
	storeAppendPrintf(sentry, "Store Directory #%d (%s): %s\n", i, SD->type,
	    storeSwapDir(i));
	SD->statfs(SD, sentry);
    }
}
