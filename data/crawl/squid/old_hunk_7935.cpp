    return 0;
}

int storeInit()
{
    static char tmpbuf[FATAL_BUF_SIZE];
    static char swaplog_file[MAX_FILE_NAME_LEN];
    static char swaplog_tmp_file[MAX_FILE_NAME_LEN];
    int directory_created = 0;
    struct stat sb;
    int inx;
    char *path = NULL;

    (void) file_map_create(MAX_SWAP_FILE);

    for (inx = 0; inx < ncache_dirs; ++inx) {
	path = swappath(inx);
	debug(0, 10, "storeInit: Creating swap space in %s\n", path);
	if (stat(path, &sb) < 0) {
	    /* we need to create a directory for swap file here. */
	    if (mkdir(path, 0777) < 0) {
		sprintf(tmpbuf,
		    "Failed to create swap directory %s: %s\n",
		    path, xstrerror());
		if (errno != EEXIST)
		    fatal(tmpbuf);
	    }
	    if (stat(path, &sb) < 0) {
		sprintf(tmpbuf,
		    "Failed to verify swap directory %s: %s\n",
		    path, xstrerror());
		fatal(tmpbuf);
	    }
	    debug(0, 1, "storeInit: Created swap directory %s\n", path);
	    directory_created = 1;
	}
	if (zap_disk_store) {
	    debug(0, 1, "storeInit: Zapping all objects on disk storage.\n");
	    /* This could be dangerous, second copy of cache can destroy the existing
	     * swap files of the previous cache. We may use rc file do it. */
	    tmpbuf[0] = '\0';
	    sprintf(tmpbuf, "cd %s; rm -rf log [0-9][0-9]", path);
	    debug(0, 1, "storeInit: Running '%s'\n", tmpbuf);
	    system(tmpbuf);	/* XXX should avoid system(3) */
	}
    }
    sprintf(swaplog_file, "%s/log", swappath(0));

    swaplog_fd = file_open(swaplog_file, NULL, O_RDWR | O_CREAT | O_APPEND);
    if (swaplog_fd < 0) {
	sprintf(tmpbuf, "Cannot open swap logfile: %s\n", swaplog_file);
	fatal(tmpbuf);
    }
    swaplog_stream = fdopen(swaplog_fd, "w");
    if (!swaplog_stream) {
	debug(0, 1, "storeInit: fdopen(%d, \"w\"): %s\n", swaplog_fd, xstrerror());
	sprintf(tmpbuf, "Cannot open a stream for swap logfile: %s\n", swaplog_file);
	fatal(tmpbuf);
    }
    swaplog_lock = file_write_lock(swaplog_fd);

    sprintf(swaplog_tmp_file, "%s/log_tmp", swappath(0));

    swaplog_tmp_fd = file_open(swaplog_tmp_file, NULL, O_RDWR | O_TRUNC | O_CREAT | O_APPEND);
    if (swaplog_tmp_fd < 0) {
	sprintf(tmpbuf, "Cannot open swap tmp logfile: %s\n", swaplog_tmp_file);
	fatal(tmpbuf);
    }
    swaplog_tmp_stream = fdopen(swaplog_tmp_fd, "w");
    if (!swaplog_tmp_stream) {
	sprintf(tmpbuf, "Cannot open a stream for swap tmp logfile: %s\n", swaplog_tmp_file);
	fatal(tmpbuf);
    }
    if (!zap_disk_store) {
	ok_write_clean_log = 0;
	storeRebuildFromDisk();

	/* rename tmp_log to log */
	file_write_unlock(swaplog_fd, swaplog_lock);
	file_close(swaplog_fd);
	safeunlink(swaplog_file, 0);
	link(swaplog_tmp_file, swaplog_file);

	swaplog_fd = file_open(swaplog_file, NULL, O_RDWR | O_CREAT | O_APPEND);
	if (swaplog_fd < 0) {
	    sprintf(tmpbuf, "Cannot reopen swap logfile: %s\n", swaplog_file);
	    fatal(tmpbuf);
	}
	swaplog_stream = fdopen(swaplog_fd, "w");
	if (!swaplog_stream) {
	    sprintf(tmpbuf, "Cannot reopen a stream for swap logfile: %s\n", swaplog_file);
	    fatal(tmpbuf);
	}
	swaplog_lock = file_write_lock(swaplog_fd);
	ok_write_clean_log = 1;
    }
    /* close tmp_log file here. Possibly remove if it is not linked to
     * the real one. */
    file_close(swaplog_tmp_fd);
    safeunlink(swaplog_tmp_file, 0);

    /* Create Small directories in swap */
    if (directory_created || zap_disk_store) {
	int i, j;
	char name[1024];
	for (j = 0; j < ncache_dirs; j++) {
	    for (i = 0; i < SWAP_DIRECTORIES; i++) {
		sprintf(name, "%s/%02d", swappath(j), i);
		if (mkdir(name, 0755) < 0) {
		    if (errno != EEXIST) {
			sprintf(tmpbuf,
			    "Failed to make swap directory %s: %s\n",
			    name, xstrerror());
			fatal(tmpbuf);
		    }
		}
	    }
	}
    }
    store_mem_high = (long) (getCacheMemMax() / 100) *
	getCacheMemHighWaterMark();
    store_mem_low = (long) (getCacheMemMax() / 100) *
