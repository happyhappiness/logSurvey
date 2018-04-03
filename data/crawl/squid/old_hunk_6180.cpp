    SwapDir *SD = &Config.cacheSwap.swapDirs[dirn];
    int fd;
    file_close(SD->swaplog_fd);
    if (rename(new_path, swaplog_path) < 0) {
	debug(50, 0) ("%s,%s: %s\n", new_path, swaplog_path, xstrerror());
	fatal("storeDirCloseTmpSwapLog: rename failed");
