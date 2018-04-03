    null_initialised = 0;
}

static SwapDir *
storeNullNew(void)
{
    SwapDir *result = new NullSwapDir;
    return result;
}

void
NullSwapDir::init()
{
    store_dirs_rebuilding++;
    eventAdd("storeNullDirRebuildComplete", storeNullDirRebuildComplete,
	NULL, 0.0, 1);
}

StoreIOState::Pointer
NullSwapDir::createStoreIO(StoreEntry &, STFNCB *, STIOCB *, void *)
{
    fatal ("Attempt to get a StoreIO from the NULL store!\n");
    return NULL;
}

StoreIOState::Pointer
NullSwapDir::openStoreIO(StoreEntry &, STFNCB *, STIOCB *, void *)
{
    fatal ("Attempt to get a StoreIO from the NULL store!\n");
    return NULL;
}

static void
storeNullDirRebuildComplete(void *unused)
{
