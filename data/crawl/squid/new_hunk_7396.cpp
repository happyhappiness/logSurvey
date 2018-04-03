    safeunlink(tmp_filename, 1);
    /* close the existing write-only swaplog, and open a temporary
     * write-only swaplog  */
    if (swaplog_fd > -1)
	file_close(swaplog_fd);
    sprintf(tmp_filename, "%s.new", swaplog_file);
