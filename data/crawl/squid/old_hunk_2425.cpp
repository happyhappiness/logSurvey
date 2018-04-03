        fatal("memory_cache_shared is on, but no support for atomic operations detected");
    } else if (Config.memShared && !Ipc::Mem::Segment::Enabled()) {
        fatal("memory_cache_shared is on, but no support for shared memory detected");
    }

    if (!Config.memShared)
        return;

    if (IamMasterProcess()) {
        Must(!owner);
        const int64_t entryLimit = MemStore::EntryLimit();
        if (entryLimit <= 0)
            return; // no memory cache configured or a misconfiguration
        owner = MemStoreMap::Init(ShmLabel, entryLimit);
    }
}

MemStoreRr::~MemStoreRr()
