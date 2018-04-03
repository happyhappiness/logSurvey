static void
storeStartRebuildFromDisk(void)
{
    int i;
    struct storeRebuildState *RB;
    struct _rebuild_dir *d;
    FILE *fp;
    int clean;
    RB = xcalloc(1, sizeof(struct storeRebuildState));
    RB->start = squid_curtime;
    for (i = 0; i < ncache_dirs; i++) {
	fp = storeDirOpenTmpSwapLog(i, &clean);
	if (fp == NULL)
	    continue;
	d = xcalloc(1, sizeof(struct _rebuild_dir));
	d->dirn = i;
	d->log = fp;
	d->clean = clean;
	d->speed = opt_foreground_rebuild ? 1 << 30 : 50;
	d->next = RB->rebuild_dir;
	RB->rebuild_dir = d;
	if (!clean)
	    store_validating = 1;
	debug(20, 1, "Rebuilding storage in Cache Dir #%d (%s)\n",
	    i, clean ? "CLEAN" : "DIRTY");
    }
    RB->line_in_sz = 4096;
    RB->line_in = xcalloc(1, RB->line_in_sz);
    if (opt_foreground_rebuild) {
	storeDoRebuildFromDisk(RB);
    } else {
	eventAdd("storeRebuild", storeDoRebuildFromDisk, RB, 0);
    }
}

