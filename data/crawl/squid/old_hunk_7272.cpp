	debug(20, 1, "Store logging disabled\n");
    if (ncache_dirs < 1)
	fatal("No cache_dir's specified in config file");
    dir_created = storeVerifySwapDirs();

    if (!opt_zap_disk_store)
	storeStartRebuildFromDisk();
    else
