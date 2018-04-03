static void
cbdataDump(StoreEntry * sentry)
{
    storeAppendPrintf(sentry, "%" PRIu64 " cbdata entries\n", cbdataCount);
#if USE_CBDATA_DEBUG

    storeAppendPrintf(sentry, "Pointer\tType\tLocks\tAllocated by\n");
