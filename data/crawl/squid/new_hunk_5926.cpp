	SD = &(Config.cacheSwap.swapDirs[i]);
	storeAppendPrintf(sentry, "Store Directory #%d (%s): %s\n", i, SD->type,
	    storeSwapDir(i));
	storeAppendPrintf(sentry, "FS Block Size %d Bytes\n",
	    SD->fs.blksize);
	SD->statfs(SD, sentry);
    }
}
