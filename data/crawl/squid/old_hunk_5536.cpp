void
storeAufsDirDump(StoreEntry * entry, SwapDir * s)
{
    squidaioinfo_t *aioinfo = (squidaioinfo_t *) s->fsdata;
    storeAppendPrintf(entry, " %d %d %d",
	s->max_size >> 10,
	aioinfo->l1,
	aioinfo->l2);
    dump_cachedir_options(entry, options, s);
}

/*
 * Only "free" the filesystem specific stuff here
 */
static void
storeAufsDirFree(SwapDir * s)
{
    squidaioinfo_t *aioinfo = (squidaioinfo_t *) s->fsdata;
    if (aioinfo->swaplog_fd > -1) {
	file_close(aioinfo->swaplog_fd);
	aioinfo->swaplog_fd = -1;
    }
    filemapFreeMemory(aioinfo->map);
    xfree(aioinfo);
    s->fsdata = NULL;		/* Will aid debugging... */
}

char *
storeAufsDirFullPath(SwapDir * SD, sfileno filn, char *fullpath)
{
    LOCAL_ARRAY(char, fullfilename, SQUID_MAXPATHLEN);
    squidaioinfo_t *aioinfo = (squidaioinfo_t *) SD->fsdata;
    int L1 = aioinfo->l1;
    int L2 = aioinfo->l2;
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
 * storeAufsCleanupDoubleCheck
 *
 * This is called by storeCleanup() if -S was given on the command line.
 */
static int
storeAufsCleanupDoubleCheck(SwapDir * sd, StoreEntry * e)
{
    struct stat sb;
    if (stat(storeAufsDirFullPath(sd, e->swap_filen, NULL), &sb) < 0) {
	debug(47, 0) ("storeAufsCleanupDoubleCheck: MISSING SWAP FILE\n");
	debug(47, 0) ("storeAufsCleanupDoubleCheck: FILENO %08X\n", e->swap_filen);
	debug(47, 0) ("storeAufsCleanupDoubleCheck: PATH %s\n",
	    storeAufsDirFullPath(sd, e->swap_filen, NULL));
	storeEntryDump(e, 0);
	return -1;
    }
    if (e->swap_file_sz != sb.st_size) {
	debug(47, 0) ("storeAufsCleanupDoubleCheck: SIZE MISMATCH\n");
	debug(47, 0) ("storeAufsCleanupDoubleCheck: FILENO %08X\n", e->swap_filen);
	debug(47, 0) ("storeAufsCleanupDoubleCheck: PATH %s\n",
	    storeAufsDirFullPath(sd, e->swap_filen, NULL));
	debug(47, 0) ("storeAufsCleanupDoubleCheck: ENTRY SIZE: %ld, FILE SIZE: %ld\n",
	    (long int) e->swap_file_sz, (long int) sb.st_size);
	storeEntryDump(e, 0);
	return -1;
    }
    return 0;
}

/*
 * storeAufsDirParse *
 * Called when a *new* fs is being setup.
