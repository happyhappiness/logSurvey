/* ========== LOCAL FUNCTIONS ABOVE, GLOBAL FUNCTIONS BELOW ========== */

void
storeDiskdDirStats(SwapDir * SD, StoreEntry * sentry)
{
    diskdinfo_t *diskdinfo;
#if HAVE_STATVFS
    struct statvfs sfs;
#endif
    diskdinfo = (diskdinfo_t *) SD->fsdata;
    storeAppendPrintf(sentry, "First level subdirectories: %d\n", diskdinfo->l1);
    storeAppendPrintf(sentry, "Second level subdirectories: %d\n", diskdinfo->l2);
    storeAppendPrintf(sentry, "Maximum Size: %d KB\n", SD->max_size);
    storeAppendPrintf(sentry, "Current Size: %d KB\n", SD->cur_size);
    storeAppendPrintf(sentry, "Percent Used: %0.2f%%\n",
	100.0 * SD->cur_size / SD->max_size);
    storeAppendPrintf(sentry, "Filemap bits in use: %d of %d (%d%%)\n",
	diskdinfo->map->n_files_in_map, diskdinfo->map->max_n_files,
	percent(diskdinfo->map->n_files_in_map, diskdinfo->map->max_n_files));
#if HAVE_STATVFS
#define fsbtoblk(num, fsbs, bs) \
    (((fsbs) != 0 && (fsbs) < (bs)) ? \
            (num) / ((bs) / (fsbs)) : (num) * ((fsbs) / (bs)))
    if (!statvfs(SD->path, &sfs)) {
	storeAppendPrintf(sentry, "Filesystem Space in use: %d/%d KB (%d%%)\n",
	    fsbtoblk((sfs.f_blocks - sfs.f_bfree), sfs.f_frsize, 1024),
	    fsbtoblk(sfs.f_blocks, sfs.f_frsize, 1024),
	    percent(sfs.f_blocks - sfs.f_bfree, sfs.f_blocks));
	storeAppendPrintf(sentry, "Filesystem Inodes in use: %d/%d (%d%%)\n",
	    sfs.f_files - sfs.f_ffree, sfs.f_files,
	    percent(sfs.f_files - sfs.f_ffree, sfs.f_files));
    }
#endif
    storeAppendPrintf(sentry, "Flags:");
    if (SD->flags.selected)
	storeAppendPrintf(sentry, " SELECTED");
    if (SD->flags.read_only)
	storeAppendPrintf(sentry, " READ-ONLY");
    storeAppendPrintf(sentry, "\n");
#if !HEAP_REPLACEMENT
    storeAppendPrintf(sentry, "LRU Expiration Age: %6.2f days\n",
	(double) storeDiskdDirExpiredReferenceAge(SD) / 86400.0);
#else
#if 0
    storeAppendPrintf(sentry, "Storage Replacement Threshold:\t%f\n",
	heap_peepminkey(sd.repl.heap.heap));
#endif
#endif
    storeAppendPrintf(sentry, "Pending operations: %d\n", diskdinfo->away);
