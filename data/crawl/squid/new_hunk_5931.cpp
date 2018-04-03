	SD = &(Config.cacheSwap.swapDirs[i]);
	storeAppendPrintf(sentry, "Store Directory #%d (%s): %s\n", i, SD->type,
	    storeSwapDir(i));
	storeAppendPrintf(sentry, "FS Block Size %d KB\n",
	    SD->fs.kperblk);
	SD->statfs(SD, sentry);
    }
}
