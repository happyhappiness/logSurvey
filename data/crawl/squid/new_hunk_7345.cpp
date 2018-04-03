	fatal_dump("cache_dir pathname is too long");
    if (SwapDirs == NULL) {
	SwapDirsAllocated = 4;
	SwapDirs = xcalloc(SwapDirsAllocated, sizeof(SwapDir *));
    }
    if (SwapDirsAllocated == ncache_dirs) {
	SwapDirsAllocated <<= 1;
	tmp = xcalloc(SwapDirsAllocated, sizeof(SwapDir *));
	for (i = 0; i < ncache_dirs; i++)
	    tmp[i] = SwapDirs[i];
	xfree(SwapDirs);
	SwapDirs = tmp;
    }
    tmp = SwapDirs+ncache_dirs;
    tmp->path = xstrdup(path);
    tmp->max_size = size;
    tmp->l1 = l1;
    tmp->l2 = l2;
    tmp->read_only = read_only;
    tmp->map = file_map_create(MAX_FILES_PER_DIR);
    return ++ncache_dirs;
}

static int
storeVerifyOrCreateDir(const char *path)
{
    struct stat sb;
    if (stat(path, &sb) == 0 && S_ISDIR(sb.st_mode))
	return 0;
    safeunlink(path, 0);
    if (mkdir(path, 0777) < 0) {
