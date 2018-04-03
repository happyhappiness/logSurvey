	memInUse(MEM_STOREENTRY));
    storeAppendPrintf(sentry, "\t%6d StoreEntries with MemObjects\n",
	memInUse(MEM_MEMOBJECT));
    storeAppendPrintf(sentry, "\t%6d StoreEntries with MemObject Data\n",
	memInUse(MEM_MEM_HDR));
    storeAppendPrintf(sentry, "\t%6d Hot Object Cache Items\n",
	hot_obj_count);
    storeAppendPrintf(sentry, "\t%6d Filemap bits set\n",
