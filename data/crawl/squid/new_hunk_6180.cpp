    SwapDir *SD = &Config.cacheSwap.swapDirs[dirn];
    int fd;
    file_close(SD->swaplog_fd);
#ifdef _SQUID_OS2_
    if (unlink(swaplog_path) < 0) {
	debug(50, 0) ("%s: %s\n", swaplog_path, xstrerror());
	fatal("storeDirCloseTmpSwapLog: unlink failed");
    }
#endif
    if (rename(new_path, swaplog_path) < 0) {
	debug(50, 0) ("%s,%s: %s\n", new_path, swaplog_path, xstrerror());
	fatal("storeDirCloseTmpSwapLog: rename failed");
