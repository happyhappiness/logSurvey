void
StoreController::stat(StoreEntry &output) const
{
    const double currentSizeInKB = currentSize() / 1024.0;
    storeAppendPrintf(&output, "Store Directory Statistics:\n");
    storeAppendPrintf(&output, "Store Entries          : %lu\n",
                      (unsigned long int)StoreEntry::inUseCount());
    storeAppendPrintf(&output, "Maximum Swap Size      : %"PRIu64" KB\n",
                      maxSize());
    storeAppendPrintf(&output, "Current Store Swap Size: %.2f KB\n",
                      currentSizeInKB);
    storeAppendPrintf(&output, "Current Capacity       : %.2f%% used, %.2f%% free\n",
                      Math::doublePercent(currentSizeInKB, maxSize()),
                      Math::doublePercent((maxSize() - currentSizeInKB), maxSize()));

    if (memStore)
        memStore->stat(output);
