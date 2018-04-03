    storeAppendPrintf(&output, "Store Directory Statistics:\n");
    storeAppendPrintf(&output, "Store Entries          : %lu\n",
                      (unsigned long int)StoreEntry::inUseCount());
    storeAppendPrintf(&output, "Maximum Swap Size      : %"PRIu64" KB\n",
                      maxSize());
    storeAppendPrintf(&output, "Current Store Swap Size: %8lu KB\n",
                      store_swap_size);
    storeAppendPrintf(&output, "Current Capacity       : %"PRId64"%% used, %"PRId64"%% free\n",
                      Math::int64Percent(store_swap_size, maxSize()),
                      Math::int64Percent((maxSize() - store_swap_size), maxSize()));
    /* FIXME Here we should output memory statistics */

    /* now the swapDir */
    swapDir->stat(output);
}

/* if needed, this could be taught to cache the result */
uint64_t
StoreController::maxSize() const
{
    /* TODO: include memory cache ? */
    return swapDir->maxSize();
}

uint64_t
StoreController::minSize() const
{
    /* TODO: include memory cache ? */
