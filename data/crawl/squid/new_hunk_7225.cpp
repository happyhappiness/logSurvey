    SwapDir *SD = &SwapDirs[dirn];
    int fd;
    if (rename(new_path, swaplog_path) < 0) {
	debug(50, 0) ("%s,%s: %s\n", new_path, swaplog_path, xstrerror());
	fatal("storeDirCloseTmpSwapLog: rename failed");
    }
    file_close(SD->swaplog_fd);
    fd = file_open(swaplog_path, O_WRONLY | O_CREAT, NULL, NULL);
    if (fd < 0) {
	debug(50, 1) ("%s: %s\n", swaplog_path, xstrerror());
	fatal("storeDirCloseTmpSwapLog: Failed to open swap log.");
    }
    safe_free(swaplog_path);
    safe_free(new_path);
    SD->swaplog_fd = fd;
    debug(20, 3) ("Cache Dir #%d log opened on FD %d\n", dirn, fd);
}

void
