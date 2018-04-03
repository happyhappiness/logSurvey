
    if (fd < 0) {
        debugs(50, DBG_IMPORTANT, "ERROR: while opening swap log" << new_path << ": " << xstrerror());
        fatal("UFSSwapDir::openTmpSwapLog: Failed to open swap log.");
    }

    swaplog_fd = fd;
