    safe_free(data);
    sprintf(tmp_filename, "%s.new", swaplog_file);
    if (rename(tmp_filename, swaplog_file) < 0) {
	debug(20, 0, "storeRebuiltFromDisk: rename failed: %s\n",
	    xstrerror());
    }
    file_update_open(swaplog_fd, swaplog_file);
    /* file_update_open clears the lock so we must reset it */
    swaplog_lock = file_write_lock(swaplog_fd);
}

