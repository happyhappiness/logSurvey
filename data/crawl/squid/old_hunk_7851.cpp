}

/* recreate meta data from disk image in swap directory */
void storeRebuildFromDisk()
{
    int objcount = 0;		/* # objects successfully reloaded */
    int expcount = 0;		/* # objects expired */
    int linecount = 0;		/* # lines parsed from cache logfile */
    int clashcount = 0;		/* # swapfile clashes avoided */
    int dupcount = 0;		/* # duplicates purged */
    static char line_in[4096];
    static char log_swapfile[1024];
    static char swapfile[1024];
    static char url[MAX_URL];
    char *t = NULL;
    StoreEntry *e = NULL;
    struct stat sb;
    time_t start, stop, r;
    time_t expires;
    time_t timestamp;
    time_t last_clean;
    int scan1, scan2, scan3;
    int delta;
    int i;
    int sfileno = 0;
    off_t size;
    int fast_mode = 0;
    FILE *old_log = NULL;
    FILE *new_log = NULL;
    char *new_log_name = NULL;

    if (stat(swaplog_file, &sb) < 0)
	return;

    for (i = 0; i < ncache_dirs; ++i)
	debug(20, 1, "Rebuilding storage from disk image in %s\n", swappath(i));
    start = getCurrentTime();

    sprintf(line_in, "%s/log-last-clean", swappath(0));
    if (stat(line_in, &sb) >= 0) {
	last_clean = sb.st_mtime;
	sprintf(line_in, "%s/log", swappath(0));
	if (stat(line_in, &sb) >= 0) {
	    fast_mode = (sb.st_mtime <= last_clean) ? 1 : 0;
	}
    }
    /* Open the existing swap log for reading */
    if ((old_log = fopen(swaplog_file, "r")) == (FILE *) NULL) {
	sprintf(tmp_error_buf, "storeRebuildFromDisk: %s: %s",
	    swaplog_file, xstrerror());
	fatal(tmp_error_buf);
    }
    /* Open a new log for writing */
    sprintf(line_in, "%s.new", swaplog_file);
    new_log_name = xstrdup(line_in);
    new_log = fopen(new_log_name, "w");
    if (new_log == (FILE *) NULL) {
	sprintf(tmp_error_buf, "storeRebuildFromDisk: %s: %s",
	    new_log_name, xstrerror());
	fatal(tmp_error_buf);
    }
    if (fast_mode)
	debug(20, 1, "Rebuilding in FAST MODE.\n");

    memset(line_in, '\0', 4096);
    while (fgets(line_in, 4096, old_log)) {
	if ((linecount++ & 0x7F) == 0)	/* update current time */
	    getCurrentTime();

	if ((linecount & 0xFFF) == 0)
	    debug(20, 1, "  %7d Lines read so far.\n", linecount);

	debug(20, 10, "line_in: %s", line_in);
	if ((line_in[0] == '\0') || (line_in[0] == '\n') ||
	    (line_in[0] == '#'))
	    continue;		/* skip bad lines */

	url[0] = log_swapfile[0] = '\0';
	expires = cached_curtime;

	scan3 = 0;
	size = 0;
	if (sscanf(line_in, "%s %s %d %d %d",
		log_swapfile, url, &scan1, &scan2, &scan3) != 5) {
	    if (opt_unlink_on_reload && log_swapfile[0])
		safeunlink(log_swapfile, 0);
	    continue;
	}
	expires = (time_t) scan1;
	timestamp = (time_t) scan2;
	size = (off_t) scan3;
	if ((t = strrchr(log_swapfile, '/')))
	    sfileno = atoi(t + 1);
	else
	    sfileno = atoi(log_swapfile);
	storeSwapFullPath(sfileno, swapfile);

	/*
	 * Note that swapfile may be different than log_swapfile if
	 * another cache_dir is added.
	 */

	if (!fast_mode) {
	    if (stat(swapfile, &sb) < 0) {
		if (expires < cached_curtime) {
		    debug(20, 3, "storeRebuildFromDisk: Expired: <URL:%s>\n", url);
		    if (opt_unlink_on_reload)
			safeunlink(swapfile, 1);
		    expcount++;
		} else {
		    debug(20, 3, "storeRebuildFromDisk: Swap file missing: <URL:%s>: %s: %s.\n", url, swapfile, xstrerror());
		    if (opt_unlink_on_reload)
			safeunlink(log_swapfile, 1);
		}
		continue;
	    }
	    if ((size = sb.st_size) == 0) {
		if (opt_unlink_on_reload)
		    safeunlink(log_swapfile, 1);
		continue;
	    }
	    /* timestamp might be a little bigger than sb.st_mtime */
	    delta = abs((int) (timestamp - sb.st_mtime));
	    if (delta > REBUILD_TIMESTAMP_DELTA_MAX) {
		/* this log entry doesn't correspond to this file */
		clashcount++;
		continue;
	    }
	    timestamp = sb.st_mtime;
	    debug(20, 10, "storeRebuildFromDisk: Cached file exists: <URL:%s>: %s\n",
		url, swapfile);
	}
	if ((e = storeGet(url))) {
	    debug(20, 6, "storeRebuildFromDisk: Duplicate: <URL:%s>\n", url);
	    storeRelease(e);
	    objcount--;
	    dupcount++;
	}
	if (expires < cached_curtime) {
	    debug(20, 3, "storeRebuildFromDisk: Expired: <URL:%s>\n", url);
	    if (opt_unlink_on_reload)
		safeunlink(swapfile, 1);
	    expcount++;
	    continue;
	}
	/* update store_swap_size */
	store_swap_size += (int) ((size + 1023) >> 10);
	objcount++;

	fprintf(new_log, "%s %s %d %d %d\n",
	    swapfile, url, (int) expires, (int) timestamp, (int) size);
	storeAddDiskRestore(url, sfileno, (int) size, expires, timestamp);
	CacheInfo->proto_newobject(CacheInfo,
	    CacheInfo->proto_id(url),
	    (int) size, TRUE);
    }

    fclose(old_log);
    fclose(new_log);
    if (rename(new_log_name, swaplog_file) < 0) {
	sprintf(tmp_error_buf, "storeRebuildFromDisk: rename: %s",
	    xstrerror());
	fatal(tmp_error_buf);
    }
    xfree(new_log_name);

    stop = getCurrentTime();
    r = stop - start;
    debug(20, 1, "Finished rebuilding storage from disk image.\n");
    debug(20, 1, "  %7d Lines read from previous logfile.\n", linecount);
    debug(20, 1, "  %7d Objects loaded.\n", objcount);
    debug(20, 1, "  %7d Objects expired.\n", expcount);
    debug(20, 1, "  %7d Duplicate URLs purged.\n", dupcount);
    debug(20, 1, "  %7d Swapfile clashes avoided.\n", clashcount);
    debug(20, 1, "  Took %d seconds (%6.1lf objects/sec).\n",
	r > 0 ? r : 0, (double) objcount / (r > 0 ? r : 1));
    debug(20, 1, "  store_swap_size = %dk\n", store_swap_size);

    /* touch a timestamp file */
    sprintf(line_in, "%s/log-last-clean", swappath(0));
    file_close(file_open(line_in, NULL, O_WRONLY | O_CREAT | O_TRUNC));
}


/* return current swap size in kilo-bytes */
int storeGetSwapSize()
