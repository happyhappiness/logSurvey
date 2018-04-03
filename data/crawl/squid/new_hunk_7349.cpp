	fatal_dump("storeSwapDir: bad index");
    return SwapDirs[dirn].path;
}

void
storeDirSwapLog(const StoreEntry * e)
{
    LOCAL_ARRAY(char, logmsg, MAX_URL << 1);
    int dirn;
    if (e->swap_file_number < 0)
	fatal_dump("storeDirSwapLog: swap_file_number < 0");
    dirn = e->swap_file_number >> SWAP_DIR_SHIFT;
    /* Note this printf format appears in storeWriteCleanLog() too */
    sprintf(logmsg, "%08x %08x %08x %08x %9d %s\n",
        (int) e->swap_file_number,
        (int) e->timestamp,
        (int) e->expires,
        (int) e->lastmod,
        e->object_len,
        e->url);
    file_write(SwapDirs[dirn].swaplog_fd,
        xstrdup(logmsg),
        strlen(logmsg),
        NULL,
        NULL,
        xfree);
}

static char *
storeDirSwapLogFile(int dirn)
{
    LOCAL_ARRAY(char, path, SQUID_MAXPATHLEN);
    LOCAL_ARRAY(char, digit, 32);
    if (Config.Log.swap) {
	xstrncpy(path, Config.Log.swap, SQUID_MAXPATHLEN - 64);
	strcat(path, ".");
	sprintf(digit, "%02d", dirn);
	strncat(path, digit, 32);
    } else {
	xstrncpy(path, storeSwapDir(dirn), SQUID_MAXPATHLEN - 64);
	strcat(path, "/log");
    }
    return path;
}

void
storeDirOpenSwapLogs(void)
{
    int i;
    int fd;
    char *path;
    SwapDir *SD;
    for (i = 0; i < ncache_dirs; i++) {
	SD = &SwapDirs[i];
	path = storeDirSwapLogFile(i);
	fd = file_open(path, NULL, O_WRONLY | O_CREAT, NULL, NULL);
	if (fd < 0) {
	    debug(50, 1, "%s: %s\n", path, xstrerror());
	    fatal("storeDirOpenSwapLogs: Failed to open swap log.");
	}
	SD->swaplog_fd = fd;
    }
}