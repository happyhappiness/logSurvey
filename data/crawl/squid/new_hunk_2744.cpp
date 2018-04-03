    if (map) {
        const int limit = map->entryLimit();
        storeAppendPrintf(&e, "Maximum entries: %9d\n", limit);
        if (limit > 0) {
            const int entryCount = map->entryCount();
            storeAppendPrintf(&e, "Current entries: %9d %.2f%%\n",
                entryCount, (100.0 * entryCount / limit));

            if (limit < 100) { // XXX: otherwise too expensive to count
                MapStats stats;
                map->updateStats(stats);
                stats.dump(e);
            }
        }
    }    

    storeAppendPrintf(&e, "Pending operations: %d out of %d\n",
