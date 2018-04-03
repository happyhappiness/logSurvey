	fatal_dump("cache_dir pathname is too long");
    if (SwapDirs == NULL) {
	SwapDirsAllocated = 4;
	SwapDirs = xcalloc(SwapDirsAllocated, sizeof(char *));
    }
    if (SwapDirsAllocated == ncache_dirs) {
	SwapDirsAllocated <<= 1;
	tmp = xcalloc(SwapDirsAllocated, sizeof(char *));
	for (i = 0; i < ncache_dirs; i++)
	    tmp[i] = SwapDirs[i];
	xfree(SwapDirs);
	SwapDirs = tmp;
    }
    SwapDirs[ncache_dirs].path = xstrdup(path);
    SwapDirs[ncache_dirs].max_size = size;
    SwapDirs[ncache_dirs].l1 = l1;
    SwapDirs[ncache_dirs].l2 = l2;
    SwapDirs[ncache_dirs].read_only = read_only;
    SwapDirs[ncache_dirs].map = file_map_create(MAX_FILES_PER_DIR);
    return ++ncache_dirs;
}

static int
storeVerifyOrCreateDir(const char *path)
{
    struct stat sb;
    if (stat(path, &sb) == 0 && S_ISDIR(sb.st_mode) == 0)
	return 0;
    safeunlink(path, 0);
    if (mkdir(path, 0777) < 0) {
