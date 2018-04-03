	storelog_fd = file_open(fname, NULL, O_WRONLY | O_CREAT, NULL, NULL);
    if (storelog_fd < 0)
	debug(20, 1, "Store logging disabled\n");
    if (ncache_dirs < 1)
	fatal("No cache_dir's specified in config file");
    dir_created = storeVerifySwapDirs();
    if (Config.Log.swap)
	xstrncpy(swaplog_file, Config.Log.swap, SQUID_MAXPATHLEN);
    else
	sprintf(swaplog_file, "%s/log", storeSwapDir(0));
    swaplog_fd = file_open(swaplog_file, NULL, O_WRONLY | O_CREAT, NULL, NULL);
    debug(20, 3, "swaplog_fd %d is now '%s'\n", swaplog_fd, swaplog_file);
    if (swaplog_fd < 0) {
