    if (map) {
        const int limit = map->entryLimit();
        storeAppendPrintf(&e, "Maximum entries: %9d\n", limit);
        if (limit > 0)
            storeAppendPrintf(&e, "Current entries: %9d %.2f%%\n",
                map->entryCount(), (100.0 * map->entryCount() / limit));
    }    

    storeAppendPrintf(&e, "Pending operations: %d out of %d\n",
