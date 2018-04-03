    storeAppendPrintf(&output, "Maximum Swap Size      : %"PRIu64" KB\n",
                      maxSize());
    storeAppendPrintf(&output, "Current Store Swap Size: %8lu KB\n",
                      store_swap_size);
    storeAppendPrintf(&output, "Current Capacity       : %"PRId64"%% used, %"PRId64"%% free\n",
                      Math::int64Percent(store_swap_size, maxSize()),
                      Math::int64Percent((maxSize() - store_swap_size), maxSize()));

    if (memStore)
        memStore->stat(output);
