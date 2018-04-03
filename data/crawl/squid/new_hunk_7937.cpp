    StoreEntry *e = NULL;
    static char swapfilename[MAX_FILE_NAME_LEN];
    static char clean_log[MAX_FILE_NAME_LEN];
    FILE *fp = NULL;
    int n = 0;
    time_t start, stop, r;

    if (!ok_write_clean_log) {
	debug(20, 1, "storeWriteCleanLog: Not currently OK to rewrite swap log.\n");
	debug(20, 1, "storeWriteCleanLog: Operation aborted.\n");
	return 0;
    }
    debug(20, 1, "storeWriteCleanLog: Starting...\n");
    start = cached_curtime = time(NULL);
    sprintf(clean_log, "%s/log_clean", swappath(0));
    if ((fp = fopen(clean_log, "a+")) == NULL) {
	debug(20, 0, "storeWriteCleanLog: %s: %s", clean_log, xstrerror());
	return 0;
    }
    for (e = storeGetFirst(); e; e = storeGetNext()) {
	debug(20, 5, "storeWriteCleanLog: <URL:%s>\n", e->url);
	if (e->swap_file_number < 0)
	    continue;
	if (e->swap_status != SWAP_OK)
	    continue;
	if (e->object_len <= 0)
	    continue;
	storeSwapFullPath(e->swap_file_number, swapfilename);
	fprintf(fp, "%s %s %d %d %d\n",
	    swapfilename, e->url, (int) e->expires, (int) e->timestamp,
	    e->object_len);
	if ((++n & 0xFFF) == 0) {
	    cached_curtime = time(NULL);
	    debug(20, 1, "  %7d lines written so far.\n", n);
	}
    }
    fclose(fp);

    if (file_write_unlock(swaplog_fd, swaplog_lock) != DISK_OK) {
	debug(20, 0, "storeWriteCleanLog: Failed to unlock swaplog!\n");
	debug(20, 0, "storeWriteCleanLog: Current swap logfile not replaced.\n");
	return 0;
    }
    if (rename(clean_log, swaplog_file) < 0) {
	debug(20, 0, "storeWriteCleanLog: rename failed: %s\n",
	    xstrerror());
	return 0;
    }
    file_close(swaplog_fd);
    swaplog_fd = file_open(swaplog_file, NULL, O_RDWR | O_CREAT | O_APPEND);
    if (swaplog_fd < 0) {
	sprintf(tmp_error_buf, "Cannot open swap logfile: %s", swaplog_file);
	fatal(tmp_error_buf);
    }
    swaplog_stream = fdopen(swaplog_fd, "w");
    if (!swaplog_stream) {
	sprintf(tmp_error_buf, "Cannot open a stream for swap logfile: %s",
	    swaplog_file);
	fatal(tmp_error_buf);
    }
    swaplog_lock = file_write_lock(swaplog_fd);

    stop = cached_curtime = time(NULL);
    r = stop - start;
    debug(20, 1, "  Finished.  Wrote %d lines.\n", n);
    debug(20, 1, "  Took %d seconds (%6.1lf lines/sec).\n",
	r > 0 ? r : 0, (double) n / (r > 0 ? r : 1));

    /* touch a timestamp file */
    sprintf(clean_log, "%s/log-last-clean", swappath(0));
    file_close(file_open(clean_log, NULL, O_WRONLY | O_CREAT | O_TRUNC));
    return n;
}
