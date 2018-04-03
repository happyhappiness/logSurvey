
    if (fd < 0) {
        debugs(50, DBG_IMPORTANT, "ERROR: while opening swap log" << new_path << ": " << xstrerror());
        fatalf("Failed to open swap log %s", new_path);
    }

    swaplog_fd = fd;
