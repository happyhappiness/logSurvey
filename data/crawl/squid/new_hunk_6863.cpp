
    storeAppendPrintf(sentry, "{Internal Data Structures:}\n");
    storeAppendPrintf(sentry, "{\t%6d StoreEntries}\n",
	memInUse(MEM_STOREENTRY));
    storeAppendPrintf(sentry, "{\t%6d StoreEntries with MemObjects}\n",
	memInUse(MEM_MEMOBJECT));
    storeAppendPrintf(sentry, "{\t%6d StoreEntries with MemObject Data}\n",
	memInUse(MEM_MEM_HDR));
    storeAppendPrintf(sentry, "{\t%6d Hot Object Cache Items}\n",
	meta_data.hot_vm);

    storeAppendPrintf(sentry, "{\t%-25.25s                      = %6d KB}\n",
	"StoreEntry Keys",
	meta_data.store_keys >> 10);
