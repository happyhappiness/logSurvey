 *
 * This routine is called when the given swapdir needs reconfiguring 
 */
static void
storeUfsDirReconfigure(SwapDir * sd, int index, char *path)
{
    int i;
    int size;
    int l1;
    int l2;

    i = GetInteger();
    size = i << 10;		/* Mbytes to kbytes */
    if (size <= 0)
	fatal("storeUfsDirReconfigure: invalid size value");
    i = GetInteger();
    l1 = i;
    if (l1 <= 0)
	fatal("storeUfsDirReconfigure: invalid level 1 directories value");
    i = GetInteger();
    l2 = i;
    if (l2 <= 0)
	fatal("storeUfsDirReconfigure: invalid level 2 directories value");

    /* just reconfigure it */
    if (size == sd->max_size)
	debug(3, 1) ("Cache dir '%s' size remains unchanged at %d KB\n",
	    path, size);
    else
	debug(3, 1) ("Cache dir '%s' size changed to %d KB\n",
	    path, size);
    sd->max_size = size;

    parse_cachedir_options(sd, options, 1);
}

void
storeUfsDirDump(StoreEntry * entry, SwapDir * s)
{
    commonUfsDirDump (entry, s);
    dump_cachedir_options(entry, options, s);
}

/*
 * storeUfsDirParse
 *
 * Called when a *new* fs is being setup.
 */
static void
storeUfsDirParse(SwapDir * sd, int index, char *path)
{
    int i;
    int size;
    int l1;
    int l2;
    squidufsinfo_t *ufsinfo;

    i = GetInteger();
    size = i << 10;		/* Mbytes to kbytes */
    if (size <= 0)
	fatal("storeUfsDirParse: invalid size value");
    i = GetInteger();
    l1 = i;
    if (l1 <= 0)
	fatal("storeUfsDirParse: invalid level 1 directories value");
    i = GetInteger();
    l2 = i;
    if (l2 <= 0)
	fatal("storeUfsDirParse: invalid level 2 directories value");

    ufsinfo = (squidufsinfo_t *)xmalloc(sizeof(squidufsinfo_t));
    if (ufsinfo == NULL)
	fatal("storeUfsDirParse: couldn't xmalloc() squidufsinfo_t!\n");

    sd->index = index;
    sd->path = xstrdup(path);
    sd->max_size = size;
    sd->fsdata = ufsinfo;
    ufsinfo->l1 = l1;
    ufsinfo->l2 = l2;
    ufsinfo->swaplog_fd = -1;
    ufsinfo->map = NULL;	/* Debugging purposes */
    ufsinfo->suggest = 0;
    ufsinfo->io.storeDirUnlinkFile = storeUfsDirIOUnlinkFile;
    sd->init = commonUfsDirInit;
    sd->newfs = commonUfsDirNewfs;
    sd->dump = storeUfsDirDump;
    sd->freefs = commonUfsDirFree;
    sd->dblcheck = commonUfsCleanupDoubleCheck;
    sd->statfs = commonUfsDirStats;
    sd->maintainfs = commonUfsDirMaintain;
    sd->checkobj = storeUfsDirCheckObj;
    sd->refobj = commonUfsDirRefObj;
    sd->unrefobj = commonUfsDirUnrefObj;
    sd->callback = NULL;
    sd->sync = NULL;
    sd->obj.create = storeUfsCreate;
    sd->obj.open = storeUfsOpen;
    sd->obj.close = storeUfsClose;
    sd->obj.read = storeUfsRead;
    sd->obj.write = storeUfsWrite;
    sd->obj.unlink = storeUfsUnlink;
    sd->log.open = commonUfsDirOpenSwapLog;
    sd->log.close = commonUfsDirCloseSwapLog;
    sd->log.write = commonUfsDirSwapLog;
    sd->log.clean.start = commonUfsDirWriteCleanStart;
    sd->log.clean.nextentry = commonUfsDirCleanLogNextEntry;
    sd->log.clean.done = commonUfsDirWriteCleanDone;

    parse_cachedir_options(sd, options, 1);

    /* Initialise replacement policy stuff */
    sd->repl = createRemovalPolicy(Config.replPolicy);
}

/*
 * Initial setup / end destruction
 */
static void
storeUfsDirDone(void)
{
    memPoolDestroy(&ufs_state_pool);
    ufs_initialised = 0;
}

void
storeFsSetup_ufs(storefs_entry_t * storefs)
{
    assert(!ufs_initialised);
    storefs->parsefunc = storeUfsDirParse;
    storefs->reconfigurefunc = storeUfsDirReconfigure;
    storefs->donefunc = storeUfsDirDone;
    ufs_state_pool = memPoolCreate("UFS IO State data", sizeof(ufsstate_t));
    ufs_initialised = 1;
}
