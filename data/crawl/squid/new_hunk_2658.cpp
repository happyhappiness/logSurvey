}

void
MemStore::stat(StoreEntry &e) const
{
    storeAppendPrintf(&e, "\n\nShared Memory Cache\n");

    storeAppendPrintf(&e, "Maximum Size: %.0f KB\n", Config.memMaxSize/1024.0);

    if (map) {
        const int limit = map->entryLimit();
        storeAppendPrintf(&e, "Maximum entries: %9d\n", limit);
        if (limit > 0) {
            const int entryCount = map->entryCount();
            storeAppendPrintf(&e, "Current entries: %9d %.2f%%\n",
                entryCount, (100.0 * entryCount / limit));

            if (limit < 100) { // XXX: otherwise too expensive to count
                Ipc::ReadWriteLockStats stats;
                map->updateStats(stats);
                stats.dump(e);
			}
		}
	}    
}

void