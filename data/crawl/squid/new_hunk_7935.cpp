    return 0;
}

static int storeVerifySwapDirs(clean)
     int clean;
{
    int inx;
    char *path = NULL;
    struct stat sb;
    int directory_created = 0;
    char *cmdbuf = NULL;

    for (inx = 0; inx < ncache_dirs; ++inx) {
	path = swappath(inx);
	debug(20, 10, "storeInit: Creating swap space in %s\n", path);
	if (stat(path, &sb) < 0) {
	    /* we need to create a directory for swap file here. */
	    if (mkdir(path, 0777) < 0) {
		if (errno != EEXIST) {
		    sprintf(tmp_error_buf, "Failed to create swap directory %s: %s",
			path,
			xstrerror());
		    fatal(tmp_error_buf);
		}
	    }
	    if (stat(path, &sb) < 0) {
		sprintf(tmp_error_buf,
		    "Failed to verify swap directory %s: %s",
		    path, xstrerror());
		fatal(tmp_error_buf);
	    }
	    debug(20, 1, "storeInit: Created swap directory %s\n", path);
	    directory_created = 1;
	}
	if (clean) {
	    debug(20, 1, "storeInit: Zapping all objects on disk storage.\n");
	    /* This could be dangerous, second copy of cache can destroy
	     * the existing swap files of the previous cache. We may
	     * use rc file do it. */
	    cmdbuf = xcalloc(1, BUFSIZ);
	    sprintf(cmdbuf, "cd %s; /bin/rm -rf log [0-9][0-9]", path);
	    debug(20, 1, "storeInit: Running '%s'\n", cmdbuf);
	    system(cmdbuf);	/* XXX should avoid system(3) */
	    xfree(cmdbuf);
	}
    }
    return directory_created;
}

static void storeCreateSwapSubDirs()
{
    int i, j;
    static char name[1024];
    for (j = 0; j < ncache_dirs; j++) {
	for (i = 0; i < SWAP_DIRECTORIES; i++) {
	    sprintf(name, "%s/%02d", swappath(j), i);
	    if (mkdir(name, 0755) < 0) {
		if (errno != EEXIST) {
		    sprintf(tmp_error_buf,
			"Failed to make swap directory %s: %s",
			name, xstrerror());
		    fatal(tmp_error_buf);
		}
	    }
	}
    }
}

int storeInit()
{
    int dir_created;

    file_map_create(MAX_SWAP_FILE);
    dir_created = storeVerifySwapDirs(zap_disk_store);

    sprintf(swaplog_file, "%s/log", swappath(0));

    if (!zap_disk_store) {
	ok_write_clean_log = 0;
	storeRebuildFromDisk();
	ok_write_clean_log = 1;
    }
    swaplog_fd = file_open(swaplog_file, NULL, O_WRONLY | O_CREAT | O_APPEND);
    if (swaplog_fd < 0) {
	sprintf(tmp_error_buf, "Cannot open swap logfile: %s", swaplog_file);
	fatal(tmp_error_buf);
    }
    swaplog_stream = fdopen(swaplog_fd, "w");
    if (!swaplog_stream) {
	debug(20, 1, "storeInit: fdopen(%d, \"w\"): %s\n",
	    swaplog_fd,
	    xstrerror());
	sprintf(tmp_error_buf,
	    "Cannot open a stream for swap logfile: %s\n",
	    swaplog_file);
	fatal(tmp_error_buf);
    }
    swaplog_lock = file_write_lock(swaplog_fd);

    if (dir_created || zap_disk_store)
	storeCreateSwapSubDirs();

    store_mem_high = (long) (getCacheMemMax() / 100) *
	getCacheMemHighWaterMark();
    store_mem_low = (long) (getCacheMemMax() / 100) *
