	    tmp_filename, swaplog_file, xstrerror());
	fatal_dump("storeRebuiltFromDisk: rename failed");
    }
    file_close(swaplog_fd);
    if ((swaplog_fd = file_open(swaplog_file, NULL, O_WRONLY | O_CREAT)) < 0)
	fatal_dump("storeRebuiltFromDisk: file_open(swaplog_file) failed");
}

static void
