    return 999;
}

/*
 * storeUfsDirRefObj
 *
 * This routine is called whenever an object is referenced, so we can
 * maintain replacement information within the storage fs.
 */
void
storeUfsDirRefObj(SwapDir * SD, StoreEntry * e)
{
    debug(47, 3) ("storeUfsDirRefObj: referencing %p %d/%d\n", e, e->swap_dirn,
	e->swap_filen);
    if (SD->repl->Referenced)
	SD->repl->Referenced(SD->repl, e, &e->repl);
}

/*
 * storeUfsDirUnrefObj
 * This routine is called whenever the last reference to an object is
 * removed, to maintain replacement information within the storage fs.
 */
void
storeUfsDirUnrefObj(SwapDir * SD, StoreEntry * e)
{
    debug(47, 3) ("storeUfsDirUnrefObj: referencing %p %d/%d\n", e, e->swap_dirn,
	e->swap_filen);
    if (SD->repl->Dereferenced)
	SD->repl->Dereferenced(SD->repl, e, &e->repl);
}

/*
 * storeUfsDirUnlinkFile
 *
 * This routine unlinks a file and pulls it out of the bitmap.
 * It used to be in storeUfsUnlink(), however an interface change
 * forced this bit of code here. Eeek.
 */
void
storeUfsDirUnlinkFile(SwapDir * SD, sfileno f)
{
    debug(79, 3) ("storeUfsDirUnlinkFile: unlinking fileno %08X\n", f);
    /* storeUfsDirMapBitReset(SD, f); */
#if USE_UNLINKD
    unlinkdUnlink(storeUfsDirFullPath(SD, f, NULL));
#elif USE_TRUNCATE
    truncate(storeUfsDirFullPath(SD, f, NULL), 0);
#else
    unlink(storeUfsDirFullPath(SD, f, NULL));
#endif
}

/*
 * Add and remove the given StoreEntry from the replacement policy in
 * use.
 */

void
storeUfsDirReplAdd(SwapDir * SD, StoreEntry * e)
{
    debug(47, 4) ("storeUfsDirReplAdd: added node %p to dir %d\n", e,
	SD->index);
    SD->repl->Add(SD->repl, e, &e->repl);
}


void
storeUfsDirReplRemove(StoreEntry * e)
{
    SwapDir *SD = INDEXSD(e->swap_dirn);
    debug(47, 4) ("storeUfsDirReplRemove: remove node %p from dir %d\n", e,
	SD->index);
    SD->repl->Remove(SD->repl, e, &e->repl);
}



/* ========== LOCAL FUNCTIONS ABOVE, GLOBAL FUNCTIONS BELOW ========== */

void
storeUfsDirStats(SwapDir * SD, StoreEntry * sentry)
{
    ufsinfo_t *ufsinfo = SD->fsdata;
    int totl_kb = 0;
    int free_kb = 0;
    int totl_in = 0;
    int free_in = 0;
    int x;
    storeAppendPrintf(sentry, "First level subdirectories: %d\n", ufsinfo->l1);
    storeAppendPrintf(sentry, "Second level subdirectories: %d\n", ufsinfo->l2);
    storeAppendPrintf(sentry, "Maximum Size: %d KB\n", SD->max_size);
    storeAppendPrintf(sentry, "Current Size: %d KB\n", SD->cur_size);
    storeAppendPrintf(sentry, "Percent Used: %0.2f%%\n",
	100.0 * SD->cur_size / SD->max_size);
    storeAppendPrintf(sentry, "Filemap bits in use: %d of %d (%d%%)\n",
	ufsinfo->map->n_files_in_map, ufsinfo->map->max_n_files,
	percent(ufsinfo->map->n_files_in_map, ufsinfo->map->max_n_files));
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

static struct cache_dir_option options[] =
{
#if NOT_YET_DONE
