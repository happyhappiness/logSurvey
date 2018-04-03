	    continue;
	if (BIT_TEST(e->flag, KEY_PRIVATE))
	    continue;
	sprintf(line, "%08x %08x %08x %08x %9d %s\n",
	    (int) e->swap_file_number,
	    (int) e->timestamp,
	    (int) e->expires,
	    (int) e->lastmod,
	    e->object_len,
	    e->url);
	if (write(fd, line, strlen(line)) < 0) {
	    debug(50, 0, "storeWriteCleanLog: %s: %s\n", tmp_filename, xstrerror());
	    debug(20, 0, "storeWriteCleanLog: Current swap logfile not replaced.\n");
	    close(fd);
	    safeunlink(tmp_filename, 0);
	    return 0;
	}
	if ((++n & 0xFFF) == 0) {
	    getCurrentTime();
	    debug(20, 1, "  %7d lines written so far.\n", n);
	}
    }
    if (close(fd) < 0) {
	debug(50, 0, "storeWriteCleanLog: %s: %s\n", tmp_filename, xstrerror());
	debug(20, 0, "storeWriteCleanLog: Current swap logfile not replaced.\n");
	safeunlink(tmp_filename, 0);
	return 0;
    }
    if (rename(tmp_filename, swaplog_file) < 0) {
	debug(50, 0, "storeWriteCleanLog: rename failed: %s\n",
	    xstrerror());
	return 0;
    }
    file_close(swaplog_fd);
    swaplog_fd = file_open(swaplog_file, NULL, O_WRONLY | O_CREAT, NULL, NULL);
    if (swaplog_fd < 0) {
	sprintf(tmp_error_buf, "Cannot open swap logfile: %s", swaplog_file);
	fatal(tmp_error_buf);
    }
    stop = getCurrentTime();
    r = stop - start;
    debug(20, 1, "  Finished.  Wrote %d lines.\n", n);
    debug(20, 1, "  Took %d seconds (%6.1lf lines/sec).\n",
	r > 0 ? r : 0, (double) n / (r > 0 ? r : 1));

    /* touch a timestamp file if we're not still validating */
    if (!store_validating) {
	sprintf(tmp_filename, "%s-last-clean", swaplog_file);
	file_close(file_open(tmp_filename, NULL, O_WRONLY | O_CREAT | O_TRUNC, NULL, NULL));
    }
    return n;
}
