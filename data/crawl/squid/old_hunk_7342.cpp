	r > 0 ? r : 0, (double) data->objcount / (r > 0 ? r : 1));
    debug(20, 1, "  store_swap_size = %dk\n", store_swap_size);
    store_rebuilding = STORE_NOT_REBUILDING;
    fclose(data->log);
    safe_free(data);
    sprintf(tmp_filename, "%s.new", swaplog_file);
    if (rename(tmp_filename, swaplog_file) < 0) {
	debug(50, 0, "storeRebuiltFromDisk: %s,%s: %s\n",
	    tmp_filename, swaplog_file, xstrerror());
	fatal_dump("storeRebuiltFromDisk: rename failed");
    }
    file_close(swaplog_fd);
    if ((swaplog_fd = file_open(swaplog_file, NULL, O_WRONLY | O_CREAT, NULL, NULL)) < 0)
	fatal_dump("storeRebuiltFromDisk: file_open(swaplog_file) failed");
    if (store_validating) {
	debug(20, 1, "Beginning Validation Procedure\n");
	eventAdd("storeCleanup", storeCleanup, NULL, 0);
