        StoreController::store_dirs_rebuilding--;
        assert(0 == StoreController::store_dirs_rebuilding);

        if (opt_store_doublecheck && store_errors) {
            fatalf("Quitting after finding %d cache index inconsistencies. " \
                   "Removing cache index will force its slow rebuild. " \
                   "Removing -S will let Squid start with an inconsistent " \
                   "cache index (at your own risk).\n", store_errors);
        }

        if (store_digest)
            storeDigestNoteStoreReady();