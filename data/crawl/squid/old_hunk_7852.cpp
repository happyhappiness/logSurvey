
    sprintf(swaplog_file, "%s/log", swappath(0));

    if (!zap_disk_store) {
	ok_write_clean_log = 0;
	storeRebuildFromDisk();
	ok_write_clean_log = 1;
    }
    swaplog_fd = file_open(swaplog_file, NULL, O_WRONLY | O_CREAT | O_APPEND);
    if (swaplog_fd < 0) {
	sprintf(tmp_error_buf, "Cannot open swap logfile: %s", swaplog_file);
	fatal(tmp_error_buf);
    }
    swaplog_stream = fdopen(swaplog_fd, "w");
    if (!swaplog_stream) {
	debug(20, 1, "storeInit: fdopen(%d, \"w\"): %s\n",
	    swaplog_fd,
	    xstrerror());
	sprintf(tmp_error_buf,
	    "Cannot open a stream for swap logfile: %s\n",
	    swaplog_file);
	fatal(tmp_error_buf);
    }
    swaplog_lock = file_write_lock(swaplog_fd);

    if (dir_created || zap_disk_store)
	storeCreateSwapSubDirs();
