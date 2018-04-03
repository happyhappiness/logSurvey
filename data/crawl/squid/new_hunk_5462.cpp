    return path;
}

void
CossSwapDir::openLog()
{
    char *logPath;
    logPath = storeCossDirSwapLogFile(this, NULL);
    swaplog_fd = file_open(logPath, O_WRONLY | O_CREAT | O_BINARY);
    if (swaplog_fd < 0) {
	debug(47, 1) ("%s: %s\n", logPath, xstrerror());
	fatal("storeCossDirOpenSwapLog: Failed to open swap log.");
    }
    debug(47, 3) ("Cache COSS Dir #%d log opened on FD %d\n", index, swaplog_fd);
}

void
CossSwapDir::closeLog()
{
    if (swaplog_fd < 0)	/* not open */
	return;
    file_close(swaplog_fd);
    debug(47, 3) ("Cache COSS Dir #%d log closed on FD %d\n",
	index, swaplog_fd);
    swaplog_fd = -1;
}

void
CossSwapDir::init()
{
    a_file_setupqueue(&aq);
    openLog();
    storeCossDirRebuild(this);
    fd = file_open(path, O_RDWR | O_CREAT);
    if (fd < 0) {
	debug(47, 1) ("%s: %s\n", path, xstrerror());
	fatal("storeCossDirInit: Failed to open a COSS directory.");
    }
    n_coss_dirs++;
    (void) storeDirGetBlkSize(path, &fs.blksize);
}

void
storeCossRemove(CossSwapDir * sd, StoreEntry * e)
{
    CossIndexNode *coss_node = (CossIndexNode *)e->repl.data;
    e->repl.data = NULL;
    dlinkDelete(&coss_node->node, &sd->cossindex);
    memPoolFree(coss_index_pool, coss_node);
    sd->count -= 1;
}

void
storeCossAdd(CossSwapDir * sd, StoreEntry * e)
{
    CossIndexNode *coss_node = (CossIndexNode *)memPoolAlloc(coss_index_pool);
    assert(!e->repl.data);
    e->repl.data = coss_node;
    dlinkAdd(e, &coss_node->node, &sd->cossindex);
    sd->count += 1;
}

static void
storeCossRebuildComplete(void *data)
{
    RebuildState *rb = (RebuildState *)data;
    CossSwapDir *sd = rb->sd;
    storeCossStartMembuf(sd);
    store_dirs_rebuilding--;
    storeCossDirCloseTmpSwapLog(rb->sd);
