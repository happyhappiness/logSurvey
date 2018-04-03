storeSwapSubSubDir(int fn, char *fullpath)
{
    LOCAL_ARRAY(char, fullfilename, SQUID_MAXPATHLEN);
    int dirn = (fn >> SWAP_DIR_SHIFT) % Config.cacheSwap.n_configured;
    int filn = fn & SWAP_FILE_MASK;
    if (!fullpath)
	fullpath = fullfilename;
    fullpath[0] = '\0';
    sprintf(fullpath, "%s/%02X/%02X",
	Config.cacheSwap.swapDirs[dirn].path,
	filn % Config.cacheSwap.swapDirs[dirn].l1,
	filn / Config.cacheSwap.swapDirs[dirn].l1 % Config.cacheSwap.swapDirs[dirn].l2);
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
