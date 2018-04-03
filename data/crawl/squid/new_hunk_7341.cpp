}

void
storeDirUpdateSwapSize(int fn, size_t size, int sign)
{
    int dirn = (fn >> SWAP_DIR_SHIFT) % ncache_dirs;
    int k = ((size + 1023) >> 10) * sign;
    SwapDirs[dirn].cur_size += k;
    store_swap_size += k;
}

void
storeDirStats(StoreEntry *sentry)
{
    int i;
    SwapDir *SD;
    storeAppendPrintf(sentry, "Store Directory Statistics:\n");
    storeAppendPrintf(sentry, "Store Entries: %d\n", meta_data.store_entries);
    storeAppendPrintf(sentry, "Store Swap Size: %d KB\n", store_swap_size);
    for (i = 0; i<ncache_dirs; i++) {
	SD = &SwapDirs[i];
	storeAppendPrintf(sentry, "\n");
	storeAppendPrintf(sentry, "Store Directory #%d: %s\n", i, SD->path);
	storeAppendPrintf(sentry, "First level subdirectories: %d\n", SD->l1);
	storeAppendPrintf(sentry, "Second level subdirectories: %d\n", SD->l2);
	storeAppendPrintf(sentry, "Maximum Size: %d KB\n", SD->max_size);
	storeAppendPrintf(sentry, "Current Size: %d KB\n", SD->cur_size);
	storeAppendPrintf(sentry, "Percent Used: %0.2f%%\n",
		100.0 * SD->cur_size /  SD->max_size);
    }
}