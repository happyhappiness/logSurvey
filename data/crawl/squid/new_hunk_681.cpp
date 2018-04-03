        if (head->flags.ignore_no_store)
            storeAppendPrintf(entry, " ignore-no-store");

        if (head->flags.ignore_private)
            storeAppendPrintf(entry, " ignore-private");
#endif
