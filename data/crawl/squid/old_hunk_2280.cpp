        const int limit = map->entryLimit();
        storeAppendPrintf(&e, "Maximum entries: %9d\n", limit);
        if (limit > 0) {
            storeAppendPrintf(&e, "Current entries: %"PRId64" %.2f%%\n",
                              currentCount(), (100.0 * currentCount() / limit));

            if (limit < 100) { // XXX: otherwise too expensive to count
