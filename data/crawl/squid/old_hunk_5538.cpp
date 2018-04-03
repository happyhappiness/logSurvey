
#include "store_diskd.h"

#define DefaultLevelOneDirs     16
#define DefaultLevelTwoDirs     256
#define STORE_META_BDISKDZ 4096

diskd_stats_t diskd_stats;

typedef struct _RebuildState RebuildState;
struct _RebuildState {
    SwapDir *sd;
    int n_read;
    FILE *log;
    int speed;
    int curlvl1;
    int curlvl2;
    struct {
	unsigned int need_to_validate:1;
	unsigned int clean:1;
	unsigned int init:1;
    } flags;
    int done;
    int in_dir;
    int fn;
    struct dirent *entry;
    DIR *td;
    char fullpath[SQUID_MAXPATHLEN];
    char fullfilename[SQUID_MAXPATHLEN];
    struct _store_rebuild_data counts;
};

static int n_diskd_dirs = 0;
static int *diskd_dir_index = NULL;
MemPool *diskd_state_pool = NULL;
static int diskd_initialised = 0;

static char *storeDiskdDirSwapSubDir(SwapDir *, int subdirn);
static int storeDiskdDirCreateDirectory(const char *path, int);
static int storeDiskdDirVerifyCacheDirs(SwapDir *);
static int storeDiskdDirVerifyDirectory(const char *path);
static void storeDiskdDirCreateSwapSubDirs(SwapDir *);
static char *storeDiskdDirSwapLogFile(SwapDir *, const char *);
static EVH storeDiskdDirRebuildFromDirectory;
static EVH storeDiskdDirRebuildFromSwapLog;
static int storeDiskdDirGetNextFile(RebuildState *, sfileno *, int *size);
static StoreEntry *storeDiskdDirAddDiskRestore(SwapDir * SD, const cache_key * key,
    sfileno file_number,
    size_t swap_file_sz,
    time_t expires,
    time_t timestamp,
    time_t lastref,
    time_t lastmod,
    u_int32_t refcount,
    u_int16_t flags,
    int clean);
static void storeDiskdDirRebuild(SwapDir * sd);
static void storeDiskdDirCloseTmpSwapLog(SwapDir * sd);
static FILE *storeDiskdDirOpenTmpSwapLog(SwapDir *, int *, int *);
static STLOGOPEN storeDiskdDirOpenSwapLog;
static STINIT storeDiskdDirInit;
static STFREE storeDiskdDirFree;
static STLOGCLEANSTART storeDiskdDirWriteCleanStart;
static STLOGCLEANNEXTENTRY storeDiskdDirCleanLogNextEntry;
static STLOGCLEANWRITE storeDiskdDirWriteCleanEntry;
static STLOGCLEANDONE storeDiskdDirWriteCleanDone;
static STLOGCLOSE storeDiskdDirCloseSwapLog;
static STLOGWRITE storeDiskdDirSwapLog;
static STNEWFS storeDiskdDirNewfs;
static STDUMP storeDiskdDirDump;
static STMAINTAINFS storeDiskdDirMaintain;
static STCHECKOBJ storeDiskdDirCheckObj;
static STREFOBJ storeDiskdDirRefObj;
static STUNREFOBJ storeDiskdDirUnrefObj;
static QS rev_int_sort;
static int storeDiskdDirClean(int swap_index);
static EVH storeDiskdDirCleanEvent;
static int storeDiskdDirIs(SwapDir * sd);
static int storeDiskdFilenoBelongsHere(int fn, int F0, int F1, int F2);
static int storeDiskdCleanupDoubleCheck(SwapDir *, StoreEntry *);
static void storeDiskdDirStats(SwapDir *, StoreEntry *);
static void storeDiskdDirInitBitmap(SwapDir *);
static int storeDiskdDirValidFileno(SwapDir *, sfileno, int);
static void storeDiskdStats(StoreEntry * sentry);
static void storeDiskdDirSync(SwapDir *);

/* The only externally visible interface */
STSETUP storeFsSetup_diskd;

/*
 * These functions were ripped straight out of the heart of store_dir.c.
 * They assume that the given filenum is on a diskd partiton, which may or
 * may not be true.. 
 * XXX this evilness should be tidied up at a later date!
 */

static int
storeDiskdDirMapBitTest(SwapDir * SD, sfileno filn)
{
    diskdinfo_t *diskdinfo;
    diskdinfo = SD->fsdata;
    return file_map_bit_test(diskdinfo->map, filn);
}

static void
storeDiskdDirMapBitSet(SwapDir * SD, sfileno filn)
{
    diskdinfo_t *diskdinfo;
    diskdinfo = SD->fsdata;
    file_map_bit_set(diskdinfo->map, filn);
}

void
storeDiskdDirMapBitReset(SwapDir * SD, sfileno filn)
{
    diskdinfo_t *diskdinfo;
    diskdinfo = SD->fsdata;
    /* 
     * We have to test the bit before calling file_map_bit_reset.
     * file_map_bit_reset doesn't do bounds checking.  It assumes
     * filn is a valid file number, but it might not be because
     * the map is dynamic in size.  Also clearing an already clear
     * bit puts the map counter of-of-whack.
     */
    if (file_map_bit_test(diskdinfo->map, filn))
	file_map_bit_reset(diskdinfo->map, filn);
}

int
storeDiskdDirMapBitAllocate(SwapDir * SD)
{
    diskdinfo_t *diskdinfo = SD->fsdata;
    int fn;
    fn = file_map_allocate(diskdinfo->map, diskdinfo->suggest);
    file_map_bit_set(diskdinfo->map, fn);
    diskdinfo->suggest = fn + 1;
    return fn;
}

/*
 * Initialise the diskd bitmap
 *
 * If there already is a bitmap, and the numobjects is larger than currently
 * configured, we allocate a new bitmap and 'grow' the old one into it.
 */
static void
storeDiskdDirInitBitmap(SwapDir * sd)
{
    diskdinfo_t *diskdinfo = sd->fsdata;

    if (diskdinfo->map == NULL) {
	/* First time */
	diskdinfo->map = file_map_create();
    } else if (diskdinfo->map->max_n_files) {
	/* it grew, need to expand */
	/* XXX We don't need it anymore .. */
    }
    /* else it shrunk, and we leave the old one in place */
}

static char *
storeDiskdDirSwapSubDir(SwapDir * sd, int subdirn)
{
    diskdinfo_t *diskdinfo = sd->fsdata;

    LOCAL_ARRAY(char, fullfilename, SQUID_MAXPATHLEN);
    assert(0 <= subdirn && subdirn < diskdinfo->l1);
    snprintf(fullfilename, SQUID_MAXPATHLEN, "%s/%02X", sd->path, subdirn);
    return fullfilename;
}

static int
storeDiskdDirCreateDirectory(const char *path, int should_exist)
{
    int created = 0;
    struct stat st;
    getCurrentTime();
    if (0 == stat(path, &st)) {
	if (S_ISDIR(st.st_mode)) {
	    debug(47, should_exist ? 3 : 1) ("%s exists\n", path);
	} else {
	    fatalf("Swap directory %s is not a directory.", path);
	}
    } else if (0 == mkdir(path, 0755)) {
	debug(47, should_exist ? 1 : 3) ("%s created\n", path);
	created = 1;
    } else {
	fatalf("Failed to make swap directory %s: %s",
	    path, xstrerror());
    }
    return created;
}

static int
storeDiskdDirVerifyDirectory(const char *path)
{
    struct stat sb;
    if (stat(path, &sb) < 0) {
	debug(47, 0) ("%s: %s\n", path, xstrerror());
	return -1;
    }
    if (S_ISDIR(sb.st_mode) == 0) {
	debug(47, 0) ("%s is not a directory\n", path);
	return -1;
    }
    return 0;
}

/*
 * This function is called by storeDiskdDirInit().  If this returns < 0,
 * then Squid exits, complains about swap directories not
 * existing, and instructs the admin to run 'squid -z'
 */
static int
storeDiskdDirVerifyCacheDirs(SwapDir * sd)
{
    diskdinfo_t *diskdinfo = sd->fsdata;
    int j;
    const char *path = sd->path;

    if (storeDiskdDirVerifyDirectory(path) < 0)
	return -1;
    for (j = 0; j < diskdinfo->l1; j++) {
	path = storeDiskdDirSwapSubDir(sd, j);
	if (storeDiskdDirVerifyDirectory(path) < 0)
	    return -1;
    }
    return 0;
}

static void
storeDiskdDirCreateSwapSubDirs(SwapDir * sd)
{
    diskdinfo_t *diskdinfo = sd->fsdata;
    int i, k;
    int should_exist;
    LOCAL_ARRAY(char, name, MAXPATHLEN);
    for (i = 0; i < diskdinfo->l1; i++) {
	snprintf(name, MAXPATHLEN, "%s/%02X", sd->path, i);
	if (storeDiskdDirCreateDirectory(name, 0))
	    should_exist = 0;
	else
	    should_exist = 1;
	debug(47, 1) ("Making directories in %s\n", name);
	for (k = 0; k < diskdinfo->l2; k++) {
	    snprintf(name, MAXPATHLEN, "%s/%02X/%02X", sd->path, i, k);
	    storeDiskdDirCreateDirectory(name, should_exist);
	}
    }
}

static char *
storeDiskdDirSwapLogFile(SwapDir * sd, const char *ext)
{
    LOCAL_ARRAY(char, path, SQUID_MAXPATHLEN);
    LOCAL_ARRAY(char, pathtmp, SQUID_MAXPATHLEN);
    LOCAL_ARRAY(char, digit, 32);
    char *pathtmp2;
    if (Config.Log.swap) {
	xstrncpy(pathtmp, sd->path, SQUID_MAXPATHLEN - 64);
	pathtmp2 = pathtmp;
	while ((pathtmp2 = strchr(pathtmp2, '/')) != NULL)
	    *pathtmp2 = '.';
	while (strlen(pathtmp) && pathtmp[strlen(pathtmp) - 1] == '.')
	    pathtmp[strlen(pathtmp) - 1] = '\0';
	for (pathtmp2 = pathtmp; *pathtmp2 == '.'; pathtmp2++);
	snprintf(path, SQUID_MAXPATHLEN - 64, Config.Log.swap, pathtmp2);
	if (strncmp(path, Config.Log.swap, SQUID_MAXPATHLEN - 64) == 0) {
	    strcat(path, ".");
	    snprintf(digit, 32, "%02d", sd->index);
	    strncat(path, digit, 3);
	}
    } else {
	xstrncpy(path, sd->path, SQUID_MAXPATHLEN - 64);
	strcat(path, "/swap.state");
    }
    if (ext)
	strncat(path, ext, 16);
    return path;
}

static void
storeDiskdDirOpenSwapLog(SwapDir * sd)
{
    diskdinfo_t *diskdinfo = sd->fsdata;
    char *path;
    int fd;
    path = storeDiskdDirSwapLogFile(sd, NULL);
    fd = file_open(path, O_WRONLY | O_CREAT);
    if (fd < 0) {
	debug(50, 1) ("%s: %s\n", path, xstrerror());
	fatal("storeDiskdDirOpenSwapLog: Failed to open swap log.");
    }
    debug(47, 3) ("Cache Dir #%d log opened on FD %d\n", sd->index, fd);
    diskdinfo->swaplog_fd = fd;
    if (0 == n_diskd_dirs)
	assert(NULL == diskd_dir_index);
    n_diskd_dirs++;
    assert(n_diskd_dirs <= Config.cacheSwap.n_configured);
}

static void
storeDiskdDirCloseSwapLog(SwapDir * sd)
{
    diskdinfo_t *diskdinfo = sd->fsdata;
    if (diskdinfo->swaplog_fd < 0)	/* not open */
	return;
    file_close(diskdinfo->swaplog_fd);
    debug(47, 3) ("Cache Dir #%d log closed on FD %d\n",
	sd->index, diskdinfo->swaplog_fd);
    diskdinfo->swaplog_fd = -1;
    n_diskd_dirs--;
    assert(n_diskd_dirs >= 0);
    if (0 == n_diskd_dirs)
	safe_free(diskd_dir_index);
}

static void
storeDiskdDirInit(SwapDir * sd)
{
    static int started_clean_event = 0;
    int x;
    int i;
    int rfd;
