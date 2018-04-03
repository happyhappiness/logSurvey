    if (stat(tmp_filename, &sb) >= 0) {
	last_clean = sb.st_mtime;
	if (stat(swaplog_file, &sb) >= 0)
	    data->fast_mode = (sb.st_mtime <= last_clean) ? 1 : 0;
    }
    /* close the existing write-only swaplog, and open a temporary
     * write-only swaplog  */
    if (file_write_unlock(swaplog_fd, swaplog_lock) != DISK_OK)
	fatal_dump("storeStartRebuildFromDisk: swaplog unlock failed");
    if (swaplog_fd > -1)
	file_close(swaplog_fd);
    sprintf(tmp_filename, "%s.new", swaplog_file);
    swaplog_fd = file_open(tmp_filename, NULL, O_WRONLY | O_CREAT | O_APPEND);
    debug(20, 3, "swaplog_fd %d is now '%s'\n", swaplog_fd, tmp_filename);
    if (swaplog_fd < 0) {
	debug(20, 0, "storeStartRebuildFromDisk: %s: %s\n",
