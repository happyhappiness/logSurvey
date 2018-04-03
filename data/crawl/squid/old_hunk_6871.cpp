    return fullpath;
}

static int
storeVerifyOrCreateDir(const char *path)
{
    struct stat sb;
    if (stat(path, &sb) == 0 && S_ISDIR(sb.st_mode)) {
	debug(47, 3) ("%s exists\n", path);
	return 0;
    }
    safeunlink(path, 1);
    if (mkdir(path, 0777) < 0) {
	if (errno != EEXIST) {
	    snprintf(tmp_error_buf, ERROR_BUF_SZ,
		"Failed to create swap directory %s: %s",
		path,
		xstrerror());
	    fatal(tmp_error_buf);
	}
    }
    debug(47, 1) ("Created directory %s\n", path);
    if (stat(path, &sb) < 0 || !S_ISDIR(sb.st_mode)) {
	snprintf(tmp_error_buf, ERROR_BUF_SZ,
	    "Failed to create directory %s: %s", path, xstrerror());
	fatal(tmp_error_buf);
    }
    return 1;
}

int
storeVerifySwapDirs(void)
{
    int i;
    const char *path = NULL;
    int directory_created = 0;
    for (i = 0; i < Config.cacheSwap.n_configured; i++) {
	path = Config.cacheSwap.swapDirs[i].path;
	debug(47, 3) ("storeVerifySwapDirs: Creating swap space in %s\n", path);
	storeVerifyOrCreateDir(path);
	storeCreateSwapSubDirs(i);
    }
    return directory_created;
}

void
storeCreateSwapSubDirs(int j)
{
    int i, k;
    SwapDir *SD = &Config.cacheSwap.swapDirs[j];
    LOCAL_ARRAY(char, name, MAXPATHLEN);
    for (i = 0; i < SD->l1; i++) {
	snprintf(name, MAXPATHLEN, "%s/%02X", SD->path, i);
	if (storeVerifyOrCreateDir(name) == 0)
	    continue;
	debug(47, 1) ("Making directories in %s\n", name);
	for (k = 0; k < SD->l2; k++) {
	    snprintf(name, MAXPATHLEN, "%s/%02X/%02X", SD->path, i, k);
	    storeVerifyOrCreateDir(name);
	}
    }
}

int
storeMostFreeSwapDir(void)
{
    double least_used = 1.0;