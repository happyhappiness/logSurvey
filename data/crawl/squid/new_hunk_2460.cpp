    fatal("not implemented");
}

void
StoreController::handleIdleEntry(StoreEntry &e)
{
    bool keepInLocalMemory = false;
    if (memStore) {
        memStore->considerKeeping(e);
        // leave keepInLocalMemory false; memStore maintains its own cache
    } else {
        keepInLocalMemory = e.memoryCachable() && // entry is in good shape and
                            // the local memory cache is not overflowing
                            (mem_node::InUseCount() <= store_pages_max);
    }

    // An idle, unlocked entry that belongs to a SwapDir which controls
    // its own index, should not stay in the global store_table.
    if (!dereference(e)) {
        debugs(20, 5, HERE << "destroying unlocked entry: " << &e << ' ' << e);
        destroyStoreEntry(static_cast<hash_link*>(&e));
        return;
    }

    // TODO: move this into [non-shared] memory cache class when we have one
    if (keepInLocalMemory) {
        e.setMemStatus(IN_MEMORY);
        e.mem_obj->unlinkRequest();
    } else {
        e.purgeMem(); // may free e
    }
}

StoreHashIndex::StoreHashIndex()
{
    if (store_table)
