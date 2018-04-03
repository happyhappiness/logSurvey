	store_hash_buckets, storeKeyHashHash);
    storeDigestInit();
    storeLogOpen();
    if (storeVerifyCacheDirs() < 0) {
	xstrncpy(tmp_error_buf,
	    "\tFailed to verify one of the swap directories, Check cache.log\n"
	    "\tfor details.  Run 'squid -z' to create swap directories\n"
	    "\tif needed, or if running Squid for the first time.",
	    ERROR_BUF_SZ);
	fatal(tmp_error_buf);
    }
    storeDirOpenSwapLogs();
    store_list.head = store_list.tail = NULL;
    inmem_list.head = inmem_list.tail = NULL;
    stackInit(&LateReleaseStack);
    eventAdd("storeLateRelease", storeLateRelease, NULL, 1.0, 1);
    storeRebuildStart();
    cachemgrRegister("storedir",
	"Store Directory Stats",
	storeDirStats, 0, 1);
