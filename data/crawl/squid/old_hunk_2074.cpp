    fp = fopen(swaplog_path, "rb");

    if (fp == NULL) {
        debugs(50, 0, "" << swaplog_path << ": " << xstrerror());
        fatal("Failed to open swap log for reading");
    }

