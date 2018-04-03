    return loadav;
}

/*
 * storeAufsDirRefObj
 *
 * This routine is called whenever an object is referenced, so we can
 * maintain replacement information within the storage fs.
 */
void
storeAufsDirRefObj(SwapDir * SD, StoreEntry * e)
{
    debug(47, 3) ("storeAufsDirRefObj: referencing %p %d/%d\n", e, e->swap_dirn,
	e->swap_filen);
    if (SD->repl->Referenced)
	SD->repl->Referenced(SD->repl, e, &e->repl);
}

/*
 * storeAufsDirUnrefObj
 * This routine is called whenever the last reference to an object is
 * removed, to maintain replacement information within the storage fs.
 */
void
storeAufsDirUnrefObj(SwapDir * SD, StoreEntry * e)
{
    debug(47, 3) ("storeAufsDirUnrefObj: referencing %p %d/%d\n", e, e->swap_dirn,
	e->swap_filen);
    if (SD->repl->Dereferenced)
	SD->repl->Dereferenced(SD->repl, e, &e->repl);
}

/*
 * storeAufsDirUnlinkFile
 *
 * This routine unlinks a file and pulls it out of the bitmap.
 * It used to be in storeAufsUnlink(), however an interface change
 * forced this bit of code here. Eeek.
 */
void
storeAufsDirUnlinkFile(SwapDir * SD, sfileno f)
{
    debug(79, 3) ("storeAufsDirUnlinkFile: unlinking fileno %08X\n", f);
    /* storeAufsDirMapBitReset(SD, f); */
#if USE_TRUNCATE_NOT_UNLINK
    aioTruncate(storeAufsDirFullPath(SD, f, NULL), NULL, NULL);
#else
    aioUnlink(storeAufsDirFullPath(SD, f, NULL), NULL, NULL);
#endif
}

/*
 * Add and remove the given StoreEntry from the replacement policy in
 * use.
 */

void
storeAufsDirReplAdd(SwapDir * SD, StoreEntry * e)
{
    debug(47, 4) ("storeAufsDirReplAdd: added node %p to dir %d\n", e,
	SD->index);
    SD->repl->Add(SD->repl, e, &e->repl);
}


void
storeAufsDirReplRemove(StoreEntry * e)
{
    SwapDir *SD = INDEXSD(e->swap_dirn);
    debug(47, 4) ("storeAufsDirReplRemove: remove node %p from dir %d\n", e,
	SD->index);
    SD->repl->Remove(SD->repl, e, &e->repl);
}



/* ========== LOCAL FUNCTIONS ABOVE, GLOBAL FUNCTIONS BELOW ========== */

void
storeAufsDirStats(SwapDir * SD, StoreEntry * sentry)
{
    squidaioinfo_t *aioinfo = SD->fsdata;
    int totl_kb = 0;
    int free_kb = 0;
    int totl_in = 0;
    int free_in = 0;
    int x;
    storeAppendPrintf(sentry, "First level subdirectories: %d\n", aioinfo->l1);
    storeAppendPrintf(sentry, "Second level subdirectories: %d\n", aioinfo->l2);
    storeAppendPrintf(sentry, "Maximum Size: %d KB\n", SD->max_size);
    storeAppendPrintf(sentry, "Current Size: %d KB\n", SD->cur_size);
    storeAppendPrintf(sentry, "Percent Used: %0.2f%%\n",
	100.0 * SD->cur_size / SD->max_size);
    storeAppendPrintf(sentry, "Filemap bits in use: %d of %d (%d%%)\n",
	aioinfo->map->n_files_in_map, aioinfo->map->max_n_files,
	percent(aioinfo->map->n_files_in_map, aioinfo->map->max_n_files));
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
