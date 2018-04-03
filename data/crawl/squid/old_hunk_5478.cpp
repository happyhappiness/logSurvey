
#include "ufscommon.h"
#include "Store.h"

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

static int n_dirs = 0;
static int *dir_index = NULL;
#if 0
MemPool *squidaio_state_pool = NULL;
MemPool *aufs_qread_pool = NULL;
MemPool *aufs_qwrite_pool = NULL;
static int asyncufs_initialised = 0;
#endif
static int commonUfsFilenoBelongsHere(int fn, int F0, int F1, int F2);
static char *commonUfsDirSwapSubDir(SwapDir *, int subdirn);
static int commonUfsDirCreateDirectory(const char *path, int);
static int commonUfsDirVerifyCacheDirs(SwapDir * sd);
static int commonUfsDirVerifyDirectory(const char *path);
static void commonUfsDirCreateSwapSubDirs(SwapDir *);
static int commonUfsDirMapBitTest(SwapDir * SD, sfileno filn);
static char *commonUfsDirSwapLogFile(SwapDir *, const char *);
static EVH commonUfsDirRebuildFromDirectory;
static EVH commonUfsDirRebuildFromSwapLog;
static int commonUfsDirGetNextFile(RebuildState *, sfileno *, int *size);
static StoreEntry *commonUfsDirAddDiskRestore(SwapDir * SD, const cache_key * key,
    sfileno file_number,
    size_t swap_file_sz,
    time_t expires,
    time_t timestamp,
    time_t lastref,
    time_t lastmod,
    u_int32_t refcount,
    u_int16_t flags,
    int clean);
static void commonUfsDirRebuild(SwapDir * sd);
static void commonUfsDirCloseTmpSwapLog(SwapDir * sd);
static FILE *commonUfsDirOpenTmpSwapLog(SwapDir *, int *, int *);
#if 0
static STLOGOPEN commonUfsDirOpenSwapLog;
static STINIT commonUfsDirInit;
static STFREE commonUfsDirFree;
static STLOGCLEANSTART commonUfsDirWriteCleanStart;
static STLOGCLEANNEXTENTRY commonUfsDirCleanLogNextEntry;
#endif
static STLOGCLEANWRITE commonUfsDirWriteCleanEntry;
#if 0
static STLOGCLEANDONE commonUfsDirWriteCleanDone;
static STLOGCLOSE commonUfsDirCloseSwapLog;
static STLOGWRITE commonUfsDirSwapLog;
static STNEWFS commonUfsDirNewfs;
static STCHECKOBJ commonUfsDirCheckObj;
#endif
static QS rev_int_sort;
static void commonUfsDirMapBitSet(SwapDir * SD, sfileno filn);
static EVH commonUfsDirCleanEvent;
static int commonUfsDirClean(int swap_index);
static int commonUfsDirIs(SwapDir * sd);
#if 0
static int commonUfsCleanupDoubleCheck(SwapDir *, StoreEntry *);
#endif
static void commonUfsDirInitBitmap(SwapDir *);
static int commonUfsDirValidFileno(SwapDir * SD, sfileno filn, int flag);
static int commonUfsDirMapBitTest(SwapDir * SD, sfileno filn);
void commonUfsDirMapBitReset(SwapDir * SD, sfileno filn);

#if 0

/* The MAIN externally visible function */
STSETUP storeFsSetup_aufs;

/*
 * These functions were ripped straight out of the heart of store_dir.c.
 * They assume that the given filenum is on a asyncufs partiton, which may or
 * may not be true.. 
 * XXX this evilness should be tidied up at a later date!
 */

#endif
int
commonUfsDirMapBitTest(SwapDir * SD, sfileno filn)
{
    squidufsinfo_t *ioinfo;
    ioinfo = (squidufsinfo_t *) SD->fsdata;
    return file_map_bit_test(ioinfo->map, filn);
}

void
commonUfsDirMapBitSet(SwapDir * SD, sfileno filn)
{
    squidufsinfo_t *ioinfo;
    ioinfo = (squidufsinfo_t *) SD->fsdata;
    file_map_bit_set(ioinfo->map, filn);
}

void
commonUfsDirMapBitReset(SwapDir * SD, sfileno filn)
{
    squidufsinfo_t *ioinfo;
    ioinfo = (squidufsinfo_t *) SD->fsdata;
    /*
     * We have to test the bit before calling file_map_bit_reset.
     * file_map_bit_reset doesn't do bounds checking.  It assumes
     * filn is a valid file number, but it might not be because
     * the map is dynamic in size.  Also clearing an already clear
     * bit puts the map counter of-of-whack.
     */
    if (file_map_bit_test(ioinfo->map, filn))
	file_map_bit_reset(ioinfo->map, filn);
}

int
commonUfsDirMapBitAllocate(SwapDir * SD)
{
    squidufsinfo_t *ioinfo = (squidufsinfo_t *) SD->fsdata;
    int fn;
    fn = file_map_allocate(ioinfo->map, ioinfo->suggest);
    file_map_bit_set(ioinfo->map, fn);
    ioinfo->suggest = fn + 1;
    return fn;
}

/*
 * Initialise the asyncufs bitmap
 *
 * If there already is a bitmap, and the numobjects is larger than currently
 * configured, we allocate a new bitmap and 'grow' the old one into it.
 */
void
commonUfsDirInitBitmap(SwapDir * sd)
{
    squidufsinfo_t *ioinfo = (squidufsinfo_t *) sd->fsdata;

    if (ioinfo->map == NULL) {
	/* First time */
	ioinfo->map = file_map_create();
    } else if (ioinfo->map->max_n_files) {
	/* it grew, need to expand */
	/* XXX We don't need it anymore .. */
    }
    /* else it shrunk, and we leave the old one in place */
}

char *
commonUfsDirSwapSubDir(SwapDir * sd, int subdirn)
{
    squidufsinfo_t *ioinfo = (squidufsinfo_t *) sd->fsdata;

    LOCAL_ARRAY(char, fullfilename, SQUID_MAXPATHLEN);
    assert(0 <= subdirn && subdirn < ioinfo->l1);
    snprintf(fullfilename, SQUID_MAXPATHLEN, "%s/%02X", sd->path, subdirn);
    return fullfilename;
}

int
commonUfsDirCreateDirectory(const char *path, int should_exist)
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
#ifdef _SQUID_MSWIN_
    } else if (0 == mkdir(path)) {
#else
    } else if (0 == mkdir(path, 0755)) {
#endif
	debug(47, should_exist ? 1 : 3) ("%s created\n", path);
	created = 1;
    } else {
	fatalf("Failed to make swap directory %s: %s",
	    path, xstrerror());
    }
    return created;
}

int
commonUfsDirVerifyDirectory(const char *path)
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
 * This function is called by commonUfsDirInit().  If this returns < 0,
 * then Squid exits, complains about swap directories not
 * existing, and instructs the admin to run 'squid -z'
 */
int
commonUfsDirVerifyCacheDirs(SwapDir * sd)
{
    squidufsinfo_t *ioinfo = (squidufsinfo_t *) sd->fsdata;
    int j;
    const char *path = sd->path;

    if (commonUfsDirVerifyDirectory(path) < 0)
	return -1;
    for (j = 0; j < ioinfo->l1; j++) {
	path = commonUfsDirSwapSubDir(sd, j);
	if (commonUfsDirVerifyDirectory(path) < 0)
	    return -1;
    }
    return 0;
}

void
commonUfsDirCreateSwapSubDirs(SwapDir * sd)
{
    squidufsinfo_t *ioinfo = (squidufsinfo_t *) sd->fsdata;
    int i, k;
    int should_exist;
    LOCAL_ARRAY(char, name, MAXPATHLEN);
    for (i = 0; i < ioinfo->l1; i++) {
	snprintf(name, MAXPATHLEN, "%s/%02X", sd->path, i);
	if (commonUfsDirCreateDirectory(name, 0))
	    should_exist = 0;
	else
	    should_exist = 1;
	debug(47, 1) ("Making directories in %s\n", name);
	for (k = 0; k < ioinfo->l2; k++) {
	    snprintf(name, MAXPATHLEN, "%s/%02X/%02X", sd->path, i, k);
	    commonUfsDirCreateDirectory(name, should_exist);
	}
    }
}

char *
commonUfsDirSwapLogFile(SwapDir * sd, const char *ext)
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

void
commonUfsDirOpenSwapLog(SwapDir * sd)
{
    squidufsinfo_t *ioinfo = (squidufsinfo_t *) sd->fsdata;
    char *path;
    int fd;
    path = commonUfsDirSwapLogFile(sd, NULL);
    fd = file_open(path, O_WRONLY | O_CREAT | O_BINARY);
    if (fd < 0) {
	debug(50, 1) ("%s: %s\n", path, xstrerror());
	fatal("commonUfsDirOpenSwapLog: Failed to open swap log.");
    }
    debug(50, 3) ("Cache Dir #%d log opened on FD %d\n", sd->index, fd);
    ioinfo->swaplog_fd = fd;
    if (0 == n_dirs)
	assert(NULL == dir_index);
    ++n_dirs;
    assert(n_dirs <= Config.cacheSwap.n_configured);
}

void
commonUfsDirCloseSwapLog(SwapDir * sd)
{
    squidufsinfo_t *ioinfo = (squidufsinfo_t *) sd->fsdata;
    if (ioinfo->swaplog_fd < 0)	/* not open */
	return;
    file_close(ioinfo->swaplog_fd);
    debug(47, 3) ("Cache Dir #%d log closed on FD %d\n",
	sd->index, ioinfo->swaplog_fd);
    ioinfo->swaplog_fd = -1;
    n_dirs--;
    assert(n_dirs >= 0);
    if (0 == n_dirs)
	safe_free(dir_index);
}

void
commonUfsDirInit(SwapDir * sd)
{
    static int started_clean_event = 0;
    static const char *errmsg =
    "\tFailed to verify one of the swap directories, Check cache.log\n"
    "\tfor details.  Run 'squid -z' to create swap directories\n"
    "\tif needed, or if running Squid for the first time.";
    commonUfsDirInitBitmap(sd);
    if (commonUfsDirVerifyCacheDirs(sd) < 0)
	fatal(errmsg);
    commonUfsDirOpenSwapLog(sd);
    commonUfsDirRebuild(sd);
    if (!started_clean_event) {
	eventAdd("storeDirClean", commonUfsDirCleanEvent, NULL, 15.0, 1);
	started_clean_event = 1;
    }
    (void) storeDirGetBlkSize(sd->path, &sd->fs.blksize);
}

void
commonUfsDirRebuildFromDirectory(void *data)
{
    RebuildState *rb = (RebuildState *)data;
    SwapDir *SD = rb->sd;
    LOCAL_ARRAY(char, hdr_buf, SM_PAGE_SIZE);
    StoreEntry *e = NULL;
    StoreEntry tmpe;
    cache_key key[MD5_DIGEST_CHARS];
    sfileno filn = 0;
    int count;
    int size;
    struct stat sb;
    int swap_hdr_len;
    int fd = -1;
    tlv *tlv_list;
    tlv *t;
    assert(rb != NULL);
    debug(47, 3) ("commonUfsDirRebuildFromDirectory: DIR #%d\n", rb->sd->index);
    for (count = 0; count < rb->speed; count++) {
	assert(fd == -1);
	fd = commonUfsDirGetNextFile(rb, &filn, &size);
	if (fd == -2) {
	    debug(47, 1) ("Done scanning %s swaplog (%d entries)\n",
		rb->sd->path, rb->n_read);
	    store_dirs_rebuilding--;
	    commonUfsDirCloseTmpSwapLog(rb->sd);
	    storeRebuildComplete(&rb->counts);
	    cbdataFree(rb);
	    return;
	} else if (fd < 0) {
	    continue;
