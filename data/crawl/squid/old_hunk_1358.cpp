                      currentSize() / 1024.0,
                      Math::doublePercent(currentSize(), maxSize()));

    if (map) {
        const int limit = map->entryLimit();
        storeAppendPrintf(&e, "Maximum entries: %9d\n", limit);
        if (limit > 0) {
            const int entryCount = map->entryCount();
            storeAppendPrintf(&e, "Current entries: %9d %.2f%%\n",
                              entryCount, (100.0 * entryCount / limit));

            const unsigned int slotsFree = !freeSlots ? 0 : freeSlots->size();
            if (slotsFree <= static_cast<const unsigned int>(limit)) {
                const int usedSlots = limit - static_cast<const int>(slotsFree);
                storeAppendPrintf(&e, "Used slots:      %9d %.2f%%\n",
                                  usedSlots, (100.0 * usedSlots / limit));
            }
            if (limit < 100) { // XXX: otherwise too expensive to count
                Ipc::ReadWriteLockStats stats;
                map->updateStats(stats);
                stats.dump(e);
            }
        }
    }

    storeAppendPrintf(&e, "Pending operations: %d out of %d\n",
