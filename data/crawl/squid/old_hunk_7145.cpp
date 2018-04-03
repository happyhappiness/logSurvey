storeSwapSubSubDir(int fn, char *fullpath)
{
    LOCAL_ARRAY(char, fullfilename, SQUID_MAXPATHLEN);
    int dirn = (fn >> SWAP_DIR_SHIFT) % ncache_dirs;
    int filn = fn & SWAP_FILE_MASK;
    if (!fullpath)
	fullpath = fullfilename;
    fullpath[0] = '\0';
    sprintf(fullpath, "%s/%02X/%02X",
	SwapDirs[dirn].path,
	filn % SwapDirs[dirn].l1,
	filn / SwapDirs[dirn].l1 % SwapDirs[dirn].l2);
    return fullpath;
}

/* add directory to swap disk */
int
storeAddSwapDisk(const char *path, int size, int l1, int l2, int read_only)
{
    SwapDir *tmp = NULL;
    int i;
    if (strlen(path) > (SQUID_MAXPATHLEN - 32))
	fatal_dump("cache_dir pathname is too long");
    if (SwapDirs == NULL) {
	SwapDirsAllocated = 4;
	SwapDirs = xcalloc(SwapDirsAllocated, sizeof(SwapDir));
    }
    if (SwapDirsAllocated == ncache_dirs) {
	SwapDirsAllocated <<= 1;
	tmp = xcalloc(SwapDirsAllocated, sizeof(SwapDir));
	for (i = 0; i < ncache_dirs; i++)
	    tmp[i] = SwapDirs[i];
	xfree(SwapDirs);
	SwapDirs = tmp;
    }
    debug(20, 1) ("Creating Swap Dir #%d in %s\n", ncache_dirs + 1, path);
    tmp = SwapDirs + ncache_dirs;
    tmp->path = xstrdup(path);
    tmp->max_size = size;
    tmp->l1 = l1;
    tmp->l2 = l2;
    tmp->read_only = read_only;
    tmp->map = file_map_create(MAX_FILES_PER_DIR);
    tmp->swaplog_fd = -1;
    return ++ncache_dirs;
}

void
storeReconfigureSwapDisk(const char *path, int size, int l1, int l2, int read_only)
{
    int i;
    for (i = 0; i < ncache_dirs; i++) {
	if (!strcmp(path, SwapDirs[i].path))
	    break;
    }
    if (i == ncache_dirs)
	return;
    SwapDirs[i].max_size = size;
    SwapDirs[i].read_only = read_only;
    /* ignore the rest */
}

static int
storeVerifyOrCreateDir(const char *path)
{
    struct stat sb;
    if (stat(path, &sb) == 0 && S_ISDIR(sb.st_mode)) {
	debug(20, 3) ("%s exists\n", path);
	return 0;
    }
    safeunlink(path, 1);
