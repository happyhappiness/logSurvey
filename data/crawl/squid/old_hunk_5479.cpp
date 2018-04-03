	    s.lastmod,
	    s.refcount,
	    s.flags,
	    (int) rb->flags.clean);
	storeDirSwapLog(e, SWAP_LOG_ADD);
    }
    eventAdd("storeRebuild", commonUfsDirRebuildFromSwapLog, rb, 0.0, 1);
}

int
commonUfsDirGetNextFile(RebuildState * rb, sfileno * filn_p, int *size)
{
    SwapDir *SD = rb->sd;
    squidufsinfo_t *ioinfo = (squidufsinfo_t *) SD->fsdata;
    int fd = -1;
    int used = 0;
    int dirs_opened = 0;
    debug(47, 3) ("commonUfsDirGetNextFile: flag=%d, %d: /%02X/%02X\n",
	rb->flags.init,
	rb->sd->index,
	rb->curlvl1,
	rb->curlvl2);
    if (rb->done)
	return -2;
    while (fd < 0 && rb->done == 0) {
	fd = -1;
	if (0 == rb->flags.init) {	/* initialize, open first file */
	    rb->done = 0;
	    rb->curlvl1 = 0;
	    rb->curlvl2 = 0;
	    rb->in_dir = 0;
	    rb->flags.init = 1;
	    assert(Config.cacheSwap.n_configured > 0);
	}
	if (0 == rb->in_dir) {	/* we need to read in a new directory */
	    snprintf(rb->fullpath, SQUID_MAXPATHLEN, "%s/%02X/%02X",
		rb->sd->path,
		rb->curlvl1, rb->curlvl2);
	    if (dirs_opened)
		return -1;
	    rb->td = opendir(rb->fullpath);
	    dirs_opened++;
	    if (rb->td == NULL) {
		debug(47, 1) ("commonUfsDirGetNextFile: opendir: %s: %s\n",
		    rb->fullpath, xstrerror());
	    } else {
		rb->entry = readdir(rb->td);	/* skip . and .. */
		rb->entry = readdir(rb->td);
		if (rb->entry == NULL && errno == ENOENT)
		    debug(47, 1) ("commonUfsDirGetNextFile: directory does not exist!.\n");
		debug(47, 3) ("commonUfsDirGetNextFile: Directory %s\n", rb->fullpath);
	    }
	}
	if (rb->td != NULL && (rb->entry = readdir(rb->td)) != NULL) {
	    rb->in_dir++;
	    if (sscanf(rb->entry->d_name, "%x", &rb->fn) != 1) {
		debug(47, 3) ("commonUfsDirGetNextFile: invalid %s\n",
		    rb->entry->d_name);
		continue;
	    }
	    if (!commonUfsFilenoBelongsHere(rb->fn, rb->sd->index, rb->curlvl1, rb->curlvl2)) {
		debug(47, 3) ("commonUfsDirGetNextFile: %08X does not belong in %d/%d/%d\n",
		    rb->fn, rb->sd->index, rb->curlvl1, rb->curlvl2);
		continue;
	    }
	    used = commonUfsDirMapBitTest(SD, rb->fn);
	    if (used) {
		debug(47, 3) ("commonUfsDirGetNextFile: Locked, continuing with next.\n");
		continue;
	    }
	    snprintf(rb->fullfilename, SQUID_MAXPATHLEN, "%s/%s",
		rb->fullpath, rb->entry->d_name);
	    debug(47, 3) ("commonUfsDirGetNextFile: Opening %s\n", rb->fullfilename);
	    fd = file_open(rb->fullfilename, O_RDONLY | O_BINARY);
	    if (fd < 0)
		debug(47, 1) ("commonUfsDirGetNextFile: %s: %s\n", rb->fullfilename, xstrerror());
	    else
		store_open_disk_fd++;
	    continue;
	}
	if (rb->td != NULL)
	    closedir(rb->td);
	rb->td = NULL;
	rb->in_dir = 0;
	if (++rb->curlvl2 < ioinfo->l2)
	    continue;
	rb->curlvl2 = 0;
	if (++rb->curlvl1 < ioinfo->l1)
	    continue;
	rb->curlvl1 = 0;
	rb->done = 1;
    }
    *filn_p = rb->fn;
    return fd;
}

/* Add a new object to the cache with empty memory copy and pointer to disk
 * use to rebuild store from disk. */
StoreEntry *
commonUfsDirAddDiskRestore(SwapDir * SD, const cache_key * key,
    sfileno file_number,
    size_t swap_file_sz,
    time_t expires,
    time_t timestamp,
    time_t lastref,
    time_t lastmod,
    u_int32_t refcount,
    u_int16_t flags,
    int clean)
{
    StoreEntry *e = NULL;
    debug(47, 5) ("commonUfsAddDiskRestore: %s, fileno=%08X\n", storeKeyText(key), file_number);
    /* if you call this you'd better be sure file_number is not 
     * already in use! */
    e = new_StoreEntry(STORE_ENTRY_WITHOUT_MEMOBJ, NULL, NULL);
    e->store_status = STORE_OK;
    storeSetMemStatus(e, NOT_IN_MEMORY);
    e->swap_status = SWAPOUT_DONE;
    e->swap_filen = file_number;
    e->swap_dirn = SD->index;
    e->swap_file_sz = swap_file_sz;
    e->lock_count = 0;
    e->lastref = lastref;
    e->timestamp = timestamp;
    e->expires = expires;
    e->lastmod = lastmod;
    e->refcount = refcount;
    e->flags = flags;
    EBIT_SET(e->flags, ENTRY_CACHABLE);
    EBIT_CLR(e->flags, RELEASE_REQUEST);
    EBIT_CLR(e->flags, KEY_PRIVATE);
    e->ping_status = PING_NONE;
    EBIT_CLR(e->flags, ENTRY_VALIDATED);
    commonUfsDirMapBitSet(SD, e->swap_filen);
    storeHashInsert(e, key);	/* do it after we clear KEY_PRIVATE */
    commonUfsDirReplAdd(SD, e);
    return e;
}

CBDATA_TYPE(RebuildState);

void
commonUfsDirRebuild(SwapDir * sd)
{
    RebuildState *rb;
    int clean = 0;
    int zero = 0;
    FILE *fp;
    EVH *func = NULL;
    CBDATA_INIT_TYPE(RebuildState);
    rb = cbdataAlloc(RebuildState);
    rb->sd = sd;
    rb->speed = opt_foreground_rebuild ? 1 << 30 : 50;
    /*
     * If the swap.state file exists in the cache_dir, then
     * we'll use commonUfsDirRebuildFromSwapLog(), otherwise we'll
     * use commonUfsDirRebuildFromDirectory() to open up each file
     * and suck in the meta data.
     */
    fp = commonUfsDirOpenTmpSwapLog(sd, &clean, &zero);
    if (fp == NULL || zero) {
	if (fp != NULL)
	    fclose(fp);
	func = commonUfsDirRebuildFromDirectory;
    } else {
	func = commonUfsDirRebuildFromSwapLog;
	rb->log = fp;
	rb->flags.clean = (unsigned int) clean;
    }
    if (!clean)
	rb->flags.need_to_validate = 1;
    debug(47, 1) ("Rebuilding storage in %s (%s)\n",
	sd->path, clean ? "CLEAN" : "DIRTY");
    store_dirs_rebuilding++;
    eventAdd("storeRebuild", func, rb, 0.0, 1);
}

void
commonUfsDirCloseTmpSwapLog(SwapDir * sd)
{
    squidufsinfo_t *ioinfo = (squidufsinfo_t *) sd->fsdata;
    char *swaplog_path = xstrdup(commonUfsDirSwapLogFile(sd, NULL));
    char *new_path = xstrdup(commonUfsDirSwapLogFile(sd, ".new"));
    int fd;
    file_close(ioinfo->swaplog_fd);
#if defined (_SQUID_OS2_) || defined (_SQUID_CYGWIN_) || defined(_SQUID_MSWIN_)
    if (unlink(swaplog_path) < 0) {
	debug(50, 0) ("%s: %s\n", swaplog_path, xstrerror());
	fatal("commonUfsDirCloseTmpSwapLog: unlink failed");
    }
#endif
    if (xrename(new_path, swaplog_path) < 0) {
	fatal("commonUfsDirCloseTmpSwapLog: rename failed");
    }
    fd = file_open(swaplog_path, O_WRONLY | O_CREAT | O_BINARY);
    if (fd < 0) {
	debug(50, 1) ("%s: %s\n", swaplog_path, xstrerror());
	fatal("commonUfsDirCloseTmpSwapLog: Failed to open swap log.");
    }
    safe_free(swaplog_path);
    safe_free(new_path);
    ioinfo->swaplog_fd = fd;
    debug(47, 3) ("Cache Dir #%d log opened on FD %d\n", sd->index, fd);
}

FILE *
commonUfsDirOpenTmpSwapLog(SwapDir * sd, int *clean_flag, int *zero_flag)
{
    squidufsinfo_t *ioinfo = (squidufsinfo_t *) sd->fsdata;
    char *swaplog_path = xstrdup(commonUfsDirSwapLogFile(sd, NULL));
    char *clean_path = xstrdup(commonUfsDirSwapLogFile(sd, ".last-clean"));
    char *new_path = xstrdup(commonUfsDirSwapLogFile(sd, ".new"));
    struct stat log_sb;
    struct stat clean_sb;
    FILE *fp;
    int fd;
    if (stat(swaplog_path, &log_sb) < 0) {
	debug(47, 1) ("Cache Dir #%d: No log file\n", sd->index);
	safe_free(swaplog_path);
	safe_free(clean_path);
	safe_free(new_path);
	return NULL;
    }
    *zero_flag = log_sb.st_size == 0 ? 1 : 0;
    /* close the existing write-only FD */
    if (ioinfo->swaplog_fd >= 0)
	file_close(ioinfo->swaplog_fd);
    /* open a write-only FD for the new log */
    fd = file_open(new_path, O_WRONLY | O_CREAT | O_TRUNC | O_BINARY);
    if (fd < 0) {
	debug(50, 1) ("%s: %s\n", new_path, xstrerror());
	fatal("storeDirOpenTmpSwapLog: Failed to open swap log.");
    }
    ioinfo->swaplog_fd = fd;
    /* open a read-only stream of the old log */
    fp = fopen(swaplog_path, "rb");
    if (fp == NULL) {
	debug(50, 0) ("%s: %s\n", swaplog_path, xstrerror());
	fatal("Failed to open swap log for reading");
    }
    memset(&clean_sb, '\0', sizeof(struct stat));
    if (stat(clean_path, &clean_sb) < 0)
	*clean_flag = 0;
    else if (clean_sb.st_mtime < log_sb.st_mtime)
	*clean_flag = 0;
    else
	*clean_flag = 1;
    safeunlink(clean_path, 1);
    safe_free(swaplog_path);
    safe_free(clean_path);
    safe_free(new_path);
    return fp;
}

struct _clean_state {
    char *cur;
    char *newLog;
    char *cln;
    char *outbuf;
    off_t outbuf_offset;
    int fd;
    RemovalPolicyWalker *walker;
};

#define CLEAN_BUF_SZ 16384

/*
 * Begin the process to write clean cache state.  For AUFS this means
 * opening some log files and allocating write buffers.  Return 0 if
 * we succeed, and assign the 'func' and 'data' return pointers.
 */
int
commonUfsDirWriteCleanStart(SwapDir * sd)
{
    struct _clean_state *state = (struct _clean_state *)xcalloc(1, sizeof(*state));
#if HAVE_FCHMOD
    struct stat sb;
#endif
    sd->log.clean.write = NULL;
    sd->log.clean.state = NULL;
    state->newLog = xstrdup(commonUfsDirSwapLogFile(sd, ".clean"));
    state->fd = file_open(state->newLog, O_WRONLY | O_CREAT | O_TRUNC | O_BINARY);
    if (state->fd < 0) {
	xfree(state->newLog);
	xfree(state);
	return -1;
    }
    state->cur = xstrdup(commonUfsDirSwapLogFile(sd, NULL));
    state->cln = xstrdup(commonUfsDirSwapLogFile(sd, ".last-clean"));
    state->outbuf = (char *)xcalloc(CLEAN_BUF_SZ, 1);
    state->outbuf_offset = 0;
    state->walker = sd->repl->WalkInit(sd->repl);
    unlink(state->cln);
    debug(47, 3) ("storeDirWriteCleanLogs: opened %s, FD %d\n",
	state->newLog, state->fd);
#if HAVE_FCHMOD
    if (stat(state->cur, &sb) == 0)
	fchmod(state->fd, sb.st_mode);
#endif
    sd->log.clean.write = commonUfsDirWriteCleanEntry;
    sd->log.clean.state = state;
    return 0;
}

/*
 * Get the next entry that is a candidate for clean log writing
 */
const StoreEntry *
commonUfsDirCleanLogNextEntry(SwapDir * sd)
{
    const StoreEntry *entry = NULL;
    struct _clean_state *state = (struct _clean_state *)sd->log.clean.state;
    if (state->walker)
	entry = state->walker->Next(state->walker);
    return entry;
}

/*
 * "write" an entry to the clean log file.
 */
void
commonUfsDirWriteCleanEntry(SwapDir * sd, const StoreEntry * e)
{
    storeSwapLogData s;
    static size_t ss = sizeof(storeSwapLogData);
    struct _clean_state *state = (struct _clean_state *)sd->log.clean.state;
    memset(&s, '\0', ss);
    s.op = (char) SWAP_LOG_ADD;
    s.swap_filen = e->swap_filen;
    s.timestamp = e->timestamp;
    s.lastref = e->lastref;
    s.expires = e->expires;
    s.lastmod = e->lastmod;
    s.swap_file_sz = e->swap_file_sz;
    s.refcount = e->refcount;
    s.flags = e->flags;
    xmemcpy(&s.key, e->key, MD5_DIGEST_CHARS);
    xmemcpy(state->outbuf + state->outbuf_offset, &s, ss);
    state->outbuf_offset += ss;
    /* buffered write */
    if (state->outbuf_offset + ss > CLEAN_BUF_SZ) {
	if (FD_WRITE_METHOD(state->fd, state->outbuf, state->outbuf_offset) < 0) {
	    debug(50, 0) ("storeDirWriteCleanLogs: %s: write: %s\n",
		state->newLog, xstrerror());
	    debug(50, 0) ("storeDirWriteCleanLogs: Current swap logfile not replaced.\n");
	    file_close(state->fd);
	    state->fd = -1;
	    unlink(state->newLog);
	    safe_free(state);
	    sd->log.clean.state = NULL;
	    sd->log.clean.write = NULL;
	    return;
	}
	state->outbuf_offset = 0;
    }
}

void
commonUfsDirWriteCleanDone(SwapDir * sd)
{
    int fd;
    struct _clean_state *state = (struct _clean_state *)sd->log.clean.state;
    if (NULL == state)
	return;
    if (state->fd < 0)
	return;
    state->walker->Done(state->walker);
    if (FD_WRITE_METHOD(state->fd, state->outbuf, state->outbuf_offset) < 0) {
	debug(50, 0) ("storeDirWriteCleanLogs: %s: write: %s\n",
	    state->newLog, xstrerror());
	debug(50, 0) ("storeDirWriteCleanLogs: Current swap logfile "
	    "not replaced.\n");
	file_close(state->fd);
	state->fd = -1;
	unlink(state->newLog);
    }
    safe_free(state->outbuf);
    /*
     * You can't rename open files on Microsoft "operating systems"
     * so we have to close before renaming.
     */
    commonUfsDirCloseSwapLog(sd);
    /* save the fd value for a later test */
    fd = state->fd;
    /* rename */
    if (state->fd >= 0) {
#if defined(_SQUID_OS2_) || defined (_SQUID_CYGWIN_) || defined(_SQUID_MSWIN_)
	file_close(state->fd);
	state->fd = -1;
	if (unlink(state->cur) < 0)
	    debug(50, 0) ("storeDirWriteCleanLogs: unlinkd failed: %s, %s\n",
		xstrerror(), state->cur);
#endif
	xrename(state->newLog, state->cur);
    }
    /* touch a timestamp file if we're not still validating */
    if (store_dirs_rebuilding)
	(void) 0;
    else if (fd < 0)
	(void) 0;
    else
	file_close(file_open(state->cln, O_WRONLY | O_CREAT | O_TRUNC | O_BINARY));
    /* close */
    safe_free(state->cur);
    safe_free(state->newLog);
    safe_free(state->cln);
    if (state->fd >= 0)
	file_close(state->fd);
    state->fd = -1;
    safe_free(state);
    sd->log.clean.state = NULL;
    sd->log.clean.write = NULL;
}

void
storeSwapLogDataFree(void *s)
{
    memFree(s, MEM_SWAP_LOG_DATA);
}

void
commonUfsDirSwapLog(const SwapDir * sd, const StoreEntry * e, int op)
{
    squidufsinfo_t *ioinfo = (squidufsinfo_t *) sd->fsdata;
    storeSwapLogData *s = (storeSwapLogData *)memAllocate(MEM_SWAP_LOG_DATA);
    s->op = (char) op;
    s->swap_filen = e->swap_filen;
    s->timestamp = e->timestamp;
    s->lastref = e->lastref;
    s->expires = e->expires;
    s->lastmod = e->lastmod;
    s->swap_file_sz = e->swap_file_sz;
    s->refcount = e->refcount;
    s->flags = e->flags;
    xmemcpy(s->key, e->key, MD5_DIGEST_CHARS);
    file_write(ioinfo->swaplog_fd,
	-1,
	s,
	sizeof(storeSwapLogData),
	NULL,
	NULL,
	(FREE *) storeSwapLogDataFree);
}

void
commonUfsDirNewfs(SwapDir * sd)
{
    debug(47, 3) ("Creating swap space in %s\n", sd->path);
    commonUfsDirCreateDirectory(sd->path, 0);
    commonUfsDirCreateSwapSubDirs(sd);
}

static int
rev_int_sort(const void *A, const void *B)
{
    const int *i1 = (const int *)A;
    const int *i2 = (const int *)B;
    return *i2 - *i1;
}

int
commonUfsDirClean(int swap_index)
{
    DIR *dp = NULL;
    struct dirent *de = NULL;
    LOCAL_ARRAY(char, p1, MAXPATHLEN + 1);
    LOCAL_ARRAY(char, p2, MAXPATHLEN + 1);
#if USE_TRUNCATE
    struct stat sb;
#endif
    int files[20];
    int swapfileno;
    int fn;			/* same as swapfileno, but with dirn bits set */
    int n = 0;
    int k = 0;
    int N0, N1, N2;
    int D0, D1, D2;
    SwapDir *SD;
    squidufsinfo_t *ioinfo;
    N0 = n_dirs;
    D0 = dir_index[swap_index % N0];
    SD = &Config.cacheSwap.swapDirs[D0];
    ioinfo = (squidufsinfo_t *) SD->fsdata;
    N1 = ioinfo->l1;
    D1 = (swap_index / N0) % N1;
    N2 = ioinfo->l2;
    D2 = ((swap_index / N0) / N1) % N2;
    snprintf(p1, SQUID_MAXPATHLEN, "%s/%02X/%02X",
	Config.cacheSwap.swapDirs[D0].path, D1, D2);
    debug(36, 3) ("storeDirClean: Cleaning directory %s\n", p1);
    dp = opendir(p1);
    if (dp == NULL) {
	if (errno == ENOENT) {
	    debug(36, 0) ("storeDirClean: WARNING: Creating %s\n", p1);
#ifdef _SQUID_MSWIN_
	    if (mkdir(p1) == 0)
#else
	    if (mkdir(p1, 0777) == 0)
#endif
		return 0;
	}
	debug(50, 0) ("storeDirClean: %s: %s\n", p1, xstrerror());
	safeunlink(p1, 1);
	return 0;
    }
    while ((de = readdir(dp)) != NULL && k < 20) {
	if (sscanf(de->d_name, "%X", &swapfileno) != 1)
	    continue;
	fn = swapfileno;	/* XXX should remove this cruft ! */
	if (commonUfsDirValidFileno(SD, fn, 1))
	    if (commonUfsDirMapBitTest(SD, fn))
		if (commonUfsFilenoBelongsHere(fn, D0, D1, D2))
		    continue;
#if USE_TRUNCATE
	if (!stat(de->d_name, &sb))
	    if (sb.st_size == 0)
		continue;
#endif
	files[k++] = swapfileno;
    }
    closedir(dp);
    if (k == 0)
	return 0;
    qsort(files, k, sizeof(int), rev_int_sort);
    if (k > 10)
	k = 10;
    for (n = 0; n < k; n++) {
	debug(36, 3) ("storeDirClean: Cleaning file %08X\n", files[n]);
	snprintf(p2, MAXPATHLEN + 1, "%s/%08X", p1, files[n]);
#if USE_TRUNCATE
	truncate(p2, 0);
#else
	safeunlink(p2, 0);
#endif
	statCounter.swap.files_cleaned++;
    }
    debug(36, 3) ("Cleaned %d unused files from %s\n", k, p1);
    return k;
}

void
commonUfsDirCleanEvent(void *unused)
{
    static int swap_index = 0;
    int i;
    int j = 0;
    int n = 0;
    /*
     * Assert that there are AUFS cache_dirs configured, otherwise
     * we should never be called.
     */
    assert(n_dirs);
    if (NULL == dir_index) {
	SwapDir *sd;
	squidufsinfo_t *ioinfo;
	/*
	 * Initialize the little array that translates AUFS cache_dir
	 * number into the Config.cacheSwap.swapDirs array index.
	 */
	dir_index = (int *)xcalloc(n_dirs, sizeof(*dir_index));
	for (i = 0, n = 0; i < Config.cacheSwap.n_configured; i++) {
	    sd = &Config.cacheSwap.swapDirs[i];
	    if (!commonUfsDirIs(sd))
		continue;
	    dir_index[n++] = i;
	    ioinfo = (squidufsinfo_t *) sd->fsdata;
	    j += (ioinfo->l1 * ioinfo->l2);
	}
	assert(n == n_dirs);
	/*
	 * Start the commonUfsDirClean() swap_index with a random
	 * value.  j equals the total number of AUFS level 2
	 * swap directories
	 */
	swap_index = (int) (squid_random() % j);
    }
    if (0 == store_dirs_rebuilding) {
	n = commonUfsDirClean(swap_index);
	swap_index++;
    }
    eventAdd("storeDirClean", commonUfsDirCleanEvent, NULL,
	15.0 * exp(-0.25 * n), 1);
}

int
commonUfsDirIs(SwapDir * sd)
{
    if (strncmp(sd->type, "aufs", 4) == 0)
	return 1;
    if (strncmp(sd->type, "diskd", 5) == 0)
	return 1;
    if (strncmp(sd->type, "ufs", 3) == 0)
	return 1;
    return 0;
}

/*
 * Does swapfile number 'fn' belong in cachedir #F0,
 * level1 dir #F1, level2 dir #F2?
 */
int
commonUfsFilenoBelongsHere(int fn, int F0, int F1, int F2)
{
    int D1, D2;
    int L1, L2;
    int filn = fn;
    squidufsinfo_t *ioinfo;
    assert(F0 < Config.cacheSwap.n_configured);
    ioinfo = (squidufsinfo_t *) Config.cacheSwap.swapDirs[F0].fsdata;
    L1 = ioinfo->l1;
    L2 = ioinfo->l2;
    D1 = ((filn / L2) / L2) % L1;
    if (F1 != D1)
	return 0;
    D2 = (filn / L2) % L2;
    if (F2 != D2)
	return 0;
    return 1;
}

int
commonUfsDirValidFileno(SwapDir * SD, sfileno filn, int flag)
{
    squidufsinfo_t *ioinfo = (squidufsinfo_t *) SD->fsdata;
    if (filn < 0)
	return 0;
    /*
     * If flag is set it means out-of-range file number should
     * be considered invalid.
     */
    if (flag)
	if (filn > ioinfo->map->max_n_files)
	    return 0;
    return 1;
}

void
commonUfsDirMaintain(SwapDir * SD)
{
    StoreEntry *e = NULL;
    int removed = 0;
    int max_scan;
    int max_remove;
    double f;
    RemovalPurgeWalker *walker;
    /* We can't delete objects while rebuilding swap */
    if (store_dirs_rebuilding) {
	return;
    } else {
	f = (double) (SD->cur_size - SD->low_size) / (SD->max_size - SD->low_size);
	f = f < 0.0 ? 0.0 : f > 1.0 ? 1.0 : f;
	max_scan = (int) (f * 400.0 + 100.0);
	max_remove = (int) (f * 70.0 + 10.0);
	/*
	 * This is kinda cheap, but so we need this priority hack?
	 */
    }
    debug(47, 3) ("storeMaintainSwapSpace: f=%f, max_scan=%d, max_remove=%d\n",
	f, max_scan, max_remove);
    walker = SD->repl->PurgeInit(SD->repl, max_scan);
    while (1) {
	if (SD->cur_size < SD->low_size)
	    break;
	if (removed >= max_remove)
	    break;
	e = walker->Next(walker);
	if (!e)
	    break;		/* no more objects */
	removed++;
	storeRelease(e);
    }
    walker->Done(walker);
    debug(47, (removed ? 2 : 3)) ("commonUfsDirMaintain: %s removed %d/%d f=%.03f max_scan=%d\n",
	SD->path, removed, max_remove, f, max_scan);
}

#if 0
/*
 * commonUfsDirCheckObj
 *
 * This routine is called by storeDirSelectSwapDir to see if the given
 * object is able to be stored on this filesystem. AUFS filesystems will
 * happily store anything as long as the LRU time isn't too small.
 */
int
commonUfsDirCheckObj(SwapDir * SD, const StoreEntry * e)
{
    int loadav;
    int ql;

#if OLD_UNUSED_CODE
    if (commonUfsDirExpiredReferenceAge(SD) < 300) {
	debug(47, 3) ("commonUfsDirCheckObj: NO: LRU Age = %d\n",
	    commonUfsDirExpiredReferenceAge(SD));
	/* store_check_cachable_hist.no.lru_age_too_low++; */
	return -1;
    }
#endif
    ql = aioQueueSize();
    if (ql == 0)
	loadav = 0;
    loadav = ql * 1000 / MAGIC1;
    debug(47, 9) ("commonUfsDirCheckObj: load=%d\n", loadav);
    return loadav;
}
#endif
/*
 * commonUfsDirRefObj
 *
 * This routine is called whenever an object is referenced, so we can
 * maintain replacement information within the storage fs.
 */
void
commonUfsDirRefObj(SwapDir * SD, StoreEntry * e)
{
    debug(47, 3) ("commonUfsDirRefObj: referencing %p %d/%d\n", e, e->swap_dirn,
	e->swap_filen);
    if (SD->repl->Referenced)
	SD->repl->Referenced(SD->repl, e, &e->repl);
}

/*
 * commonUfsDirUnrefObj
 * This routine is called whenever the last reference to an object is
 * removed, to maintain replacement information within the storage fs.
 */
void
commonUfsDirUnrefObj(SwapDir * SD, StoreEntry * e)
{
    debug(47, 3) ("commonUfsDirUnrefObj: referencing %p %d/%d\n", e, e->swap_dirn,
	e->swap_filen);
    if (SD->repl->Dereferenced)
	SD->repl->Dereferenced(SD->repl, e, &e->repl);
}

/*
 * commonUfsDirUnlinkFile
 *
 * This routine unlinks a file and pulls it out of the bitmap.
 * It used to be in commonUfsUnlink(), however an interface change
 * forced this bit of code here. Eeek.
 */
void
commonUfsDirUnlinkFile(SwapDir * SD, sfileno f)
{
    squidufsinfo_t *ioinfo = (squidufsinfo_t *)SD->fsdata;
    debug(79, 3) ("commonUfsDirUnlinkFile: unlinking fileno %08X\n", f);
    /* commonUfsDirMapBitReset(SD, f); */
    assert(ioinfo->io.storeDirUnlinkFile);
    ioinfo->io.storeDirUnlinkFile(commonUfsDirFullPath(SD, f, NULL));
}


/*
 * Add and remove the given StoreEntry from the replacement policy in
 * use.
 */

void
commonUfsDirReplAdd(SwapDir * SD, StoreEntry * e)
{
    debug(47, 4) ("commonUfsDirReplAdd: added node %p to dir %d\n", e,
	SD->index);
    SD->repl->Add(SD->repl, e, &e->repl);
}


void
commonUfsDirReplRemove(StoreEntry * e)
{
    SwapDir *SD;
    if (e->swap_dirn < 0)
	return;
    SD = INDEXSD(e->swap_dirn);
    debug(47, 4) ("commonUfsDirReplRemove: remove node %p from dir %d\n", e,
	SD->index);
    SD->repl->Remove(SD->repl, e, &e->repl);
}



/* ========== LOCAL FUNCTIONS ABOVE, GLOBAL FUNCTIONS BELOW ========== */

void
commonUfsDirStats(SwapDir * SD, StoreEntry * sentry)
{
    squidufsinfo_t *ioinfo = (squidufsinfo_t *)SD->fsdata;
    int totl_kb = 0;
    int free_kb = 0;
    int totl_in = 0;
    int free_in = 0;
    int x;
    storeAppendPrintf(sentry, "First level subdirectories: %d\n", ioinfo->l1);
    storeAppendPrintf(sentry, "Second level subdirectories: %d\n", ioinfo->l2);
    storeAppendPrintf(sentry, "Maximum Size: %d KB\n", SD->max_size);
    storeAppendPrintf(sentry, "Current Size: %d KB\n", SD->cur_size);
    storeAppendPrintf(sentry, "Percent Used: %0.2f%%\n",
	100.0 * SD->cur_size / SD->max_size);
    storeAppendPrintf(sentry, "Filemap bits in use: %d of %d (%d%%)\n",
	ioinfo->map->n_files_in_map, ioinfo->map->max_n_files,
	percent(ioinfo->map->n_files_in_map, ioinfo->map->max_n_files));
    x = storeDirGetUFSStats(SD->path, &totl_kb, &free_kb, &totl_in, &free_in);
    if (0 == x) {
	storeAppendPrintf(sentry, "Filesystem Space in use: %d/%d KB (%d%%)\n",
	    totl_kb - free_kb,
	    totl_kb,
	    percent(totl_kb - free_kb, totl_kb));
	storeAppendPrintf(sentry, "Filesystem Inodes in use: %d/%d (%d%%)\n",
	    totl_in - free_in,
	    totl_in,
	    percent(totl_in - free_in, totl_in));
    }
    storeAppendPrintf(sentry, "Flags:");
    if (SD->flags.selected)
	storeAppendPrintf(sentry, " SELECTED");
    if (SD->flags.read_only)
	storeAppendPrintf(sentry, " READ-ONLY");
    storeAppendPrintf(sentry, "\n");
}

#if 0
static struct cache_dir_option options[] =
{
#if NOT_YET_DONE
    {"L1", commonUfsDirParseL1, commonUfsDirDumpL1},
    {"L2", commonUfsDirParseL2, commonUfsDirDumpL2},
#endif
    {NULL, NULL}
};

/*
 * commonUfsDirReconfigure
 *
 * This routine is called when the given swapdir needs reconfiguring 
 */
static void
commonUfsDirReconfigure(SwapDir * sd, int index, char *path)
{
    int i;
    int size;
    int l1;
    int l2;

    i = GetInteger();
    size = i << 10;		/* Mbytes to kbytes */
    if (size <= 0)
	fatal("commonUfsDirReconfigure: invalid size value");
    i = GetInteger();
    l1 = i;
    if (l1 <= 0)
	fatal("commonUfsDirReconfigure: invalid level 1 directories value");
    i = GetInteger();
    l2 = i;
    if (l2 <= 0)
	fatal("commonUfsDirReconfigure: invalid level 2 directories value");

    /* just reconfigure it */
    if (size == sd->max_size)
	debug(3, 1) ("Cache dir '%s' size remains unchanged at %d KB\n",
	    path, size);
    else
	debug(3, 1) ("Cache dir '%s' size changed to %d KB\n",
	    path, size);
    sd->max_size = size;

    parse_cachedir_options(sd, options, 0);

    return;
}

#endif

void
commonUfsDirDump(StoreEntry * entry, SwapDir * s)
{
    squidufsinfo_t *ioinfo = (squidufsinfo_t *) s->fsdata;
    storeAppendPrintf(entry, " %d %d %d",
	s->max_size >> 10,
	ioinfo->l1,
	ioinfo->l2);
}

/*
 * Only "free" the filesystem specific stuff here
 */
void
commonUfsDirFree(SwapDir * s)
{
    squidufsinfo_t *ioinfo = (squidufsinfo_t *) s->fsdata;
    if (ioinfo->swaplog_fd > -1) {
	file_close(ioinfo->swaplog_fd);
	ioinfo->swaplog_fd = -1;
    }
    filemapFreeMemory(ioinfo->map);
    xfree(ioinfo);
    s->fsdata = NULL;		/* Will aid debugging... */
}


char *
commonUfsDirFullPath(SwapDir * SD, sfileno filn, char *fullpath)
{
    LOCAL_ARRAY(char, fullfilename, SQUID_MAXPATHLEN);
    squidufsinfo_t *ioinfo = (squidufsinfo_t *) SD->fsdata;
    int L1 = ioinfo->l1;
    int L2 = ioinfo->l2;
    if (!fullpath)
	fullpath = fullfilename;
    fullpath[0] = '\0';
    snprintf(fullpath, SQUID_MAXPATHLEN, "%s/%02X/%02X/%08X",
	SD->path,
	((filn / L2) / L2) % L1,
	(filn / L2) % L2,
	filn);
    return fullpath;
}

/*
 * commonUfsCleanupDoubleCheck
 *
 * This is called by storeCleanup() if -S was given on the command line.
 */
int
commonUfsCleanupDoubleCheck(SwapDir * sd, StoreEntry * e)
{
    struct stat sb;
    if (stat(commonUfsDirFullPath(sd, e->swap_filen, NULL), &sb) < 0) {
	debug(47, 0) ("commonUfsCleanupDoubleCheck: MISSING SWAP FILE\n");
	debug(47, 0) ("commonUfsCleanupDoubleCheck: FILENO %08X\n", e->swap_filen);
	debug(47, 0) ("commonUfsCleanupDoubleCheck: PATH %s\n",
	    commonUfsDirFullPath(sd, e->swap_filen, NULL));
	storeEntryDump(e, 0);
	return -1;
    }
    if ((off_t)e->swap_file_sz != sb.st_size) {
	debug(47, 0) ("commonUfsCleanupDoubleCheck: SIZE MISMATCH\n");
	debug(47, 0) ("commonUfsCleanupDoubleCheck: FILENO %08X\n", e->swap_filen);
	debug(47, 0) ("commonUfsCleanupDoubleCheck: PATH %s\n",
	    commonUfsDirFullPath(sd, e->swap_filen, NULL));
	debug(47, 0) ("commonUfsCleanupDoubleCheck: ENTRY SIZE: %ld, FILE SIZE: %ld\n",
	    (long int) e->swap_file_sz, (long int) sb.st_size);
	storeEntryDump(e, 0);
	return -1;
    }
    return 0;
}
