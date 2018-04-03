        StoreController::store_dirs_rebuilding--;
        assert(0 == StoreController::store_dirs_rebuilding);

        if (opt_store_doublecheck)
            assert(store_errors == 0);

        if (store_digest)
            storeDigestNoteStoreReady();