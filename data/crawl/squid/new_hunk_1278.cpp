                      Math::doublePercent(currentSize(), maxSize()));

    if (map) {
        const int entryLimit = map->entryLimit();
        const int slotLimit = map->sliceLimit();
        storeAppendPrintf(&e, "Maximum entries: %9d\n", entryLimit);
        if (entryLimit > 0) {
            storeAppendPrintf(&e, "Current entries: %" PRId64 " %.2f%%\n",
                              currentCount(), (100.0 * currentCount() / entryLimit));
        }

        storeAppendPrintf(&e, "Maximum slots:   %9d\n", slotLimit);
        if (slotLimit > 0) {
            const unsigned int slotsFree =
                Ipc::Mem::PagesAvailable(Ipc::Mem::PageId::cachePage);
            if (slotsFree <= static_cast<const unsigned int>(slotLimit)) {
                const int usedSlots = slotLimit - static_cast<const int>(slotsFree);
                storeAppendPrintf(&e, "Used slots:      %9d %.2f%%\n",
                                  usedSlots, (100.0 * usedSlots / slotLimit));
            }

            if (slotLimit < 100) { // XXX: otherwise too expensive to count
                Ipc::ReadWriteLockStats stats;
                map->updateStats(stats);
                stats.dump(e);
