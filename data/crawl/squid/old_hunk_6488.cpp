    char *new_path = xstrdup(storeDirSwapLogFile(dirn, ".new"));
    SwapDir *SD = &Config.cacheSwap.swapDirs[dirn];
    int fd;
    if (rename(new_path, swaplog_path) < 0) {
	debug(50, 0) ("%s,%s: %s\n", new_path, swaplog_path, xstrerror());
	fatal("storeDirCloseTmpSwapLog: rename failed");
    }
    file_close(SD->swaplog_fd);
    fd = file_open(swaplog_path, O_WRONLY | O_CREAT, NULL, NULL, NULL);
    if (fd < 0) {
	debug(50, 1) ("%s: %s\n", swaplog_path, xstrerror());
