    if (SD->swaplog_fd >= 0)
	file_close(SD->swaplog_fd);
    /* open a write-only FD for the new log */
    fd = file_open(new_path, O_WRONLY | O_CREAT | O_TRUNC, NULL, NULL);
    if (fd < 0) {
	debug(50, 1, "%s: %s\n", new_path, xstrerror());
	fatal("storeDirOpenTmpSwapLog: Failed to open swap log.");
