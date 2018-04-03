    null_initialised = 0;
}

static void
storeNullDirStats(SwapDir * SD, StoreEntry * sentry)
{
    (void) 0;
}

static void
storeNullDirInit(SwapDir * sd)
{
    store_dirs_rebuilding++;
    eventAdd("storeNullDirRebuildComplete", storeNullDirRebuildComplete,
	NULL, 0.0, 1);
}

static void
storeNullDirRebuildComplete(void *unused)
{
