    safeunlink(tmp_filename, 1);
    /* close the existing write-only swaplog, and open a temporary
     * write-only swaplog  */
    if (file_write_unlock(swaplog_fd, swaplog_lock) != DISK_OK)
	fatal_dump("storeStartRebuildFromDisk: swaplog unlock failed");
    if (swaplog_fd > -1)
	file_close(swaplog_fd);
    sprintf(tmp_filename, "%s.new", swaplog_file);
