void
StoreController::stat(StoreEntry &output) const
{
    storeAppendPrintf(&output, "Store Directory Statistics:\n");
    storeAppendPrintf(&output, "Store Entries          : %lu\n",
                      (unsigned long int)StoreEntry::inUseCount());
    storeAppendPrintf(&output, "Maximum Swap Size      : %"PRIu64" KB\n",
                      maxSize());
    storeAppendPrintf(&output, "Current Store Swap Size: %"PRIu64" KB\n",
                      currentSize());
    storeAppendPrintf(&output, "Current Capacity       : %"PRId64"%% used, %"PRId64"%% free\n",
                      Math::int64Percent(currentSize(), maxSize()),
                      Math::int64Percent((maxSize() - currentSize()), maxSize()));

    if (memStore)
        memStore->stat(output);
