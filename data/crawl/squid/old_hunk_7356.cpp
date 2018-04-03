    va_end(args);
}

/* add directory to swap disk */
static int
storeAddSwapDisk(const char *path)
{
    char **tmp = NULL;
    int i;
    if (strlen(path) > (SQUID_MAXPATHLEN - 32))
	fatal_dump("cache_dir pathname is too long");
    if (CacheDirs == NULL) {
	CacheDirsAllocated = 4;
	CacheDirs = xcalloc(CacheDirsAllocated, sizeof(char *));
    }
    if (CacheDirsAllocated == ncache_dirs) {
	CacheDirsAllocated <<= 1;
	tmp = xcalloc(CacheDirsAllocated, sizeof(char *));
	for (i = 0; i < ncache_dirs; i++)
	    *(tmp + i) = *(CacheDirs + i);
	xfree(CacheDirs);
	CacheDirs = tmp;
    }
    *(CacheDirs + ncache_dirs) = xstrdup(path);
    return ++ncache_dirs;
}

/* return the nth swap directory */
const char *
swappath(int n)
{
    return *(CacheDirs + (n % ncache_dirs));
}

/* return full name to swapfile */
static char *
storeSwapFullPath(int fn, char *fullpath)
{
    LOCAL_ARRAY(char, fullfilename, SQUID_MAXPATHLEN);
    if (!fullpath)
	fullpath = fullfilename;
    fullpath[0] = '\0';
    sprintf(fullpath, "%s/%02X/%02X/%08X",
	swappath(fn),
	(fn / ncache_dirs) % Config.levelOneDirs,
	(fn / ncache_dirs) / Config.levelOneDirs % Config.levelTwoDirs,
	fn);
    return fullpath;
}

/* swapping in handle */
static int
storeSwapInHandle(int fd_notused, const char *buf, int len, int flag, StoreEntry * e)
