 * done by the upper layers.
 */
int
storeCossDirCheckObj(SwapDir * SD, const StoreEntry * e)
{
    CossInfo *cs = (CossInfo *) SD->fsdata;
    int loadav;

    /* Check if the object is a special object, we can't cache these */
    if (EBIT_TEST(e->flags, ENTRY_SPECIAL))
	return -1;

    /* Otherwise, we're ok */
    /* Return load, cs->aq.aq_numpending out of MAX_ASYNCOP */
    loadav = cs->aq.aq_numpending * 1000 / MAX_ASYNCOP;
    return loadav;
}


/*
 * storeCossDirCallback - do the IO completions
 */
static int
storeCossDirCallback(SwapDir * SD)
{
    CossInfo *cs = (CossInfo *) SD->fsdata;

    return a_file_callback(&cs->aq);
}

/* ========== LOCAL FUNCTIONS ABOVE, GLOBAL FUNCTIONS BELOW ========== */

static void
storeCossDirStats(SwapDir * SD, StoreEntry * sentry)
{
    CossInfo *cs = (CossInfo *) SD->fsdata;

    storeAppendPrintf(sentry, "\n");
    storeAppendPrintf(sentry, "Maximum Size: %d KB\n", SD->max_size);
    storeAppendPrintf(sentry, "Current Size: %d KB\n", SD->cur_size);
    storeAppendPrintf(sentry, "Percent Used: %0.2f%%\n",
	100.0 * SD->cur_size / SD->max_size);
    storeAppendPrintf(sentry, "Number of object collisions: %d\n", (int) cs->numcollisions);
#if 0
    /* is this applicable? I Hope not .. */
    storeAppendPrintf(sentry, "Filemap bits in use: %d of %d (%d%%)\n",
	SD->map->n_files_in_map, SD->map->max_n_files,
	percent(SD->map->n_files_in_map, SD->map->max_n_files));
#endif
    storeAppendPrintf(sentry, "Pending operations: %d out of %d\n", cs->aq.aq_numpending, MAX_ASYNCOP);
    storeAppendPrintf(sentry, "Flags:");
    if (SD->flags.selected)
	storeAppendPrintf(sentry, " SELECTED");
    if (SD->flags.read_only)
	storeAppendPrintf(sentry, " READ-ONLY");
    storeAppendPrintf(sentry, "\n");
}

static void
storeCossDirParse(SwapDir * sd, int index, char *path)
{
    unsigned int i;
    unsigned int size;
    CossInfo *cs;

    i = GetInteger();
    size = i << 10;		/* Mbytes to Kbytes */
    if (size <= 0)
	fatal("storeCossDirParse: invalid size value");

    cs = (CossInfo *)xmalloc(sizeof(CossInfo));
    if (cs == NULL)
	fatal("storeCossDirParse: couldn't xmalloc() CossInfo!\n");

    sd->index = index;
    sd->path = xstrdup(path);
    sd->max_size = size;
    sd->fsdata = cs;

    cs->fd = -1;
    cs->swaplog_fd = -1;

    sd->init = storeCossDirInit;
    sd->newfs = storeCossDirNewfs;
    sd->dump = storeCossDirDump;
    sd->freefs = storeCossDirShutdown;
    sd->dblcheck = NULL;
    sd->statfs = storeCossDirStats;
    sd->maintainfs = NULL;
    sd->checkobj = storeCossDirCheckObj;
    sd->refobj = NULL;		/* LRU is done in storeCossRead */
    sd->unrefobj = NULL;
    sd->callback = storeCossDirCallback;
    sd->sync = storeCossSync;

    sd->obj.create = storeCossCreate;
    sd->obj.open = storeCossOpen;
    sd->obj.close = storeCossClose;
    sd->obj.read = storeCossRead;
    sd->obj.write = storeCossWrite;
    sd->obj.unlink = storeCossUnlink;

    sd->log.open = storeCossDirOpenSwapLog;
    sd->log.close = storeCossDirCloseSwapLog;
    sd->log.write = storeCossDirSwapLog;
    sd->log.clean.start = storeCossDirWriteCleanStart;
    sd->log.clean.write = storeCossDirWriteCleanEntry;
    sd->log.clean.nextentry = storeCossDirCleanLogNextEntry;
    sd->log.clean.done = storeCossDirWriteCleanDone;

    cs->current_offset = 0;
    cs->fd = -1;
    cs->swaplog_fd = -1;
    cs->numcollisions = 0;
    cs->membufs.head = cs->membufs.tail = NULL;		/* set when the rebuild completes */
    cs->current_membuf = NULL;
    cs->index.head = NULL;
    cs->index.tail = NULL;

    parse_cachedir_options(sd, NULL, 0);
    /* Enforce maxobjsize being set to something */
    if (sd->max_objsize == -1)
	fatal("COSS requires max-size to be set to something other than -1!\n");
}


static void
storeCossDirReconfigure(SwapDir * sd, int index, char *path)
{
    unsigned int i;
    unsigned int size;
