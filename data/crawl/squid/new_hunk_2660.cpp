void
StoreController::stat(StoreEntry &output) const
{
    if (memStore)
        memStore->stat(output);

    storeAppendPrintf(&output, "Store Directory Statistics:\n");
    storeAppendPrintf(&output, "Store Entries          : %lu\n",
                      (unsigned long int)StoreEntry::inUseCount());
