    /* Now go through each swapdir, calling its statfs routine */
    for (i = 0; i < Config.cacheSwap.n_configured; i++) {
	storeAppendPrintf(sentry, "\n");
	SD = &(Config.cacheSwap.swapDirs[i]);
	storeAppendPrintf(sentry, "Store Directory #%d (%s): %s\n", i, SD->type,
	    storeSwapDir(i));
	storeAppendPrintf(sentry, "FS Block Size %d Bytes\n",
	    SD->fs.blksize);
	SD->statfs(SD, sentry);
	if (SD->repl) {
	    storeAppendPrintf(sentry, "Removal policy: %s\n", SD->repl->_type);
	    if (SD->repl->Stats)
