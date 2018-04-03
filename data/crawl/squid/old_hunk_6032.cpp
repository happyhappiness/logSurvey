#else
    x = ipcCreate(IPC_FIFO,
#endif
        SQUID_PREFIX "/bin/diskd",
        args,
        "diskd",
        &rfd,
        &diskdinfo->wfd);
    if (x < 0)
        fatal("execl " SQUID_PREFIX "/bin/diskd failed");
    if (rfd != diskdinfo->wfd)
        comm_close(rfd);
    fd_note(diskdinfo->wfd, "squid -> diskd");
    commSetTimeout(diskdinfo->wfd, -1, NULL, NULL);
    commSetNonBlocking(diskdinfo->wfd);
