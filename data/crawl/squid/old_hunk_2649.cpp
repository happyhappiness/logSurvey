{
    storeAppendPrintf(&e, "\n");
    storeAppendPrintf(&e, "Maximum Size: %"PRIu64" KB\n", max_size);
    storeAppendPrintf(&e, "Current Size: %"PRIu64" KB %.2f%%\n", cur_size,
                      100.0 * cur_size / max_size);

    if (map) {
        const int limit = map->entryLimit();
