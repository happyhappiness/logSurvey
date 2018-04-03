{
    storeAppendPrintf(&e, "\n");
    storeAppendPrintf(&e, "Maximum Size: %"PRIu64" KB\n", max_size);
    storeAppendPrintf(&e, "Current Size: %"PRIu64" KB %.2f%%\n",
                      currentSize(), 100.0 * currentSize() / max_size);

    if (map) {
        const int limit = map->entryLimit();
