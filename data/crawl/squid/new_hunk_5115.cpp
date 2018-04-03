    char *new_path = xstrdup(storeCossDirSwapLogFile(sd, ".new"));
    int anfd;
    file_close(sd->swaplog_fd);

    if (xrename(new_path, swaplog_path) < 0) {
        fatal("storeCossDirCloseTmpSwapLog: rename failed");
    }
