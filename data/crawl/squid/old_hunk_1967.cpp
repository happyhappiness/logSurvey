        if (head->flags.ignore_reload)
            storeAppendPrintf(entry, " ignore-reload");

        if (head->flags.ignore_no_cache)
            storeAppendPrintf(entry, " ignore-no-cache");

        if (head->flags.ignore_no_store)
            storeAppendPrintf(entry, " ignore-no-store");

