
        if (head->flags.ignore_private)
            storeAppendPrintf(entry, " ignore-private");
#endif

        storeAppendPrintf(entry, "\n");
