	RESERVED_FD);

    storeAppendPrintf(sentry, "{Internal Data Structures:}\n");
    storeAppendPrintf(sentry, "{\tHot Object Cache Items %d}\n",
	meta_data.hot_vm);
    storeAppendPrintf(sentry, "{\tStoreEntries with MemObjects %d}\n",
	meta_data.store_in_mem_objects);

    storeAppendPrintf(sentry, "{Meta Data:}\n");
    storeAppendPrintf(sentry, "{\t%-25.25s %7d x %4d bytes = %6d KB}\n",
	"StoreEntry",
	meta_data.store_entries,