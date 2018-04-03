	storelog_fd = file_open(fname, O_WRONLY | O_CREAT, NULL, NULL);
    if (storelog_fd < 0)
	debug(20, 1) ("Store logging disabled\n");
    storeVerifySwapDirs();
    storeDirOpenSwapLogs();
    if (!opt_zap_disk_store)