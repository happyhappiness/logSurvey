            storeAppendPrintf(&e, "Current entries: %9d %.2f%%\n",
                              entryCount, (100.0 * entryCount / limit));

            if (limit < 100) { // XXX: otherwise too expensive to count
                Ipc::ReadWriteLockStats stats;
                map->updateStats(stats);
