
    /* open a write-only FD for the new log */
    fd = file_open(new_path, O_WRONLY | O_CREAT | O_TRUNC | O_BINARY);
    
    if (fd < 0) {
        debugs(50, 1, "" << new_path << ": " << xstrerror());
        fatal("storeDirOpenTmpSwapLog: Failed to open swap log.");
    }
    
    swaplog_fd = fd;

    head = new StoreSwapLogHeader;

    file_write(swaplog_fd, -1, head, head->record_size,
               NULL, NULL, FreeHeader);

    /* open a read-only stream of the old log */
    fp = fopen(swaplog_path, "rb");

