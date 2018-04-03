        if (head->flags.refresh_ims)
            storeAppendPrintf(entry, " refresh-ims");

        if (head->flags.store_stale)
            storeAppendPrintf(entry, " store-stale");

#if HTTP_VIOLATIONS

        if (head->flags.override_expire)
