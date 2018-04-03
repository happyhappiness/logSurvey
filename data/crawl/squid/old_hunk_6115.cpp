 */

#include "squid.h"
#if HAVE_STATVFS
#if HAVE_SYS_STATVFS_H
#include <sys/statvfs.h>
#endif
#endif

#define SWAP_DIR_SHIFT 24
#define SWAP_FILE_MASK 0x00FFFFFF
#define DefaultLevelOneDirs     16
#define DefaultLevelTwoDirs     256

static char *storeSwapSubDir(int dirn, int subdirn);
static int storeDirSelectSwapDir(void);
static int storeVerifyDirectory(const char *path);
static int storeCreateDirectory(const char *path, int);
static void storeCreateSwapSubDirs(int j);

char *
storeSwapFullPath(sfileno f, char *buf)
{
	return storeUfsFullPath(f, buf);
}

static char *
storeSwapSubDir(int dirn, int subdirn)
{
    LOCAL_ARRAY(char, fullfilename, SQUID_MAXPATHLEN);
    SwapDir *SD;
    assert(0 <= dirn && dirn < Config.cacheSwap.n_configured);
    SD = &Config.cacheSwap.swapDirs[dirn];
    assert(0 <= subdirn && subdirn < SD->l1);
    snprintf(fullfilename, SQUID_MAXPATHLEN, "%s/%02X",
	Config.cacheSwap.swapDirs[dirn].path,
	subdirn);
    return fullfilename;
}

char *
storeSwapSubSubDir(int fn, char *fullpath)
{
    LOCAL_ARRAY(char, fullfilename, SQUID_MAXPATHLEN);
    int dirn = (fn >> SWAP_DIR_SHIFT) % Config.cacheSwap.n_configured;
    int filn = fn & SWAP_FILE_MASK;
    int L1 = Config.cacheSwap.swapDirs[dirn].l1;
    int L2 = Config.cacheSwap.swapDirs[dirn].l2;
    if (!fullpath)
	fullpath = fullfilename;
    fullpath[0] = '\0';
    snprintf(fullpath, SQUID_MAXPATHLEN, "%s/%02X/%02X",
	Config.cacheSwap.swapDirs[dirn].path,
	((filn / L2) / L2) % L1,
	(filn / L2) % L2);
    return fullpath;
}

/*
 * Does swapfile number 'fn' belong in cachedir #F0,
 * level1 dir #F1, level2 dir #F2?
 *
 * This is called by storeDirClean(), but placed here because
 * the algorithm needs to match storeSwapSubSubDir().
 *
 * Don't check that (fn >> SWAP_DIR_SHIFT) == F0 because
 * 'fn' may not have the directory bits set.
 */
int
storeFilenoBelongsHere(int fn, int F0, int F1, int F2)
{
    int D1, D2;
    int L1, L2;
    int filn = fn & SWAP_FILE_MASK;
    assert(F0 < Config.cacheSwap.n_configured);
    L1 = Config.cacheSwap.swapDirs[F0].l1;
    L2 = Config.cacheSwap.swapDirs[F0].l2;
    D1 = ((filn / L2) / L2) % L1;
    if (F1 != D1)
	return 0;
    D2 = (filn / L2) % L2;
    if (F2 != D2)
	return 0;
    return 1;
}

static int
storeCreateDirectory(const char *path, int should_exist)
{
    int created = 0;
    struct stat st;
    getCurrentTime();
    if (0 == stat(path, &st)) {
	if (S_ISDIR(st.st_mode)) {
	    debug(20, should_exist ? 3 : 1) ("%s exists\n", path);
	} else {
	    fatalf("Swap directory %s is not a directory.", path);
	}
    } else if (0 == mkdir(path, 0755)) {
	debug(20, should_exist ? 1 : 3) ("%s created\n", path);
	created = 1;
    } else {
	fatalf("Failed to make swap directory %s: %s",
	    path, xstrerror());
    }
    return created;
}

static int
storeVerifyDirectory(const char *path)
{
    struct stat sb;
    if (stat(path, &sb) < 0) {
	debug(20, 0) ("%s: %s\n", path, xstrerror());
	return -1;
    }
    if (S_ISDIR(sb.st_mode) == 0) {
	debug(20, 0) ("%s is not a directory\n", path);
	return -1;
    }
    return 0;
}

/*
