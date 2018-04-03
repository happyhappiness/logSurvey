	RESERVED_FD);

    storeAppendPrintf(sentry, "{Internal Data Structures:}\n");
    storeAppendPrintf(sentry, "{\t%6d StoreEntries}\n",
	meta_data.store_entries);
    storeAppendPrintf(sentry, "{\t%6d StoreEntries with MemObjects}\n",
	meta_data.mem_obj_count);
    storeAppendPrintf(sentry, "{\t%6d StoreEntries with MemObject Data}\n",
	meta_data.mem_data_count);
    storeAppendPrintf(sentry, "{\t%6d Hot Object Cache Items}\n",
	meta_data.hot_vm);

    storeAppendPrintf(sentry, "{Accounted Memory Usage:}\n");
    storeAppendPrintf(sentry, "{\t%-25.25s %7d x %4d bytes = %6d KB}\n",
	"StoreEntry",
	meta_data.store_entries,