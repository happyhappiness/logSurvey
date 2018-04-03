        if (head->flags.ignore_reload)
            storeAppendPrintf(entry, " ignore-reload");

#endif

        storeAppendPrintf(entry, "\n");
