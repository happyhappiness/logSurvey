	storelog_fd = file_open(fname, NULL, O_WRONLY | O_CREAT, NULL, NULL);
    if (storelog_fd < 0)
	debug(20, 1, "Store logging disabled\n");
    for (w = Config.cache_dirs; w; w = w->next)
	storeAddSwapDisk(w->key);
    storeSanityCheck();
    dir_created = storeVerifySwapDirs(opt_zap_disk_store);
    if (Config.Log.swap)
	xstrncpy(swaplog_file, Config.Log.swap, SQUID_MAXPATHLEN);
    else
	sprintf(swaplog_file, "%s/log", swappath(0));
    swaplog_fd = file_open(swaplog_file, NULL, O_WRONLY | O_CREAT, NULL, NULL);
    debug(20, 3, "swaplog_fd %d is now '%s'\n", swaplog_fd, swaplog_file);
    if (swaplog_fd < 0) {
