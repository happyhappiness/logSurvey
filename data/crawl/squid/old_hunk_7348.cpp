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
	sprintf(tmp_error_buf, "Cannot open swap logfile: %s", swaplog_file);
	fatal(tmp_error_buf);
    }
    if (!opt_zap_disk_store)
	storeStartRebuildFromDisk();
    else
