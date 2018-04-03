    char *new_path = xstrdup(logFile(".new"));
    int fd;
    file_close(swaplog_fd);

    if (xrename(new_path, swaplog_path) < 0) {
        fatal("commonUfsDirCloseTmpSwapLog: rename failed");
    }
