    storeAppendPrintf(sentry, "\t%6d StoreEntries with MemObject Data\n",
	memInUse(MEM_MEM_HDR));
    storeAppendPrintf(sentry, "\t%6d Hot Object Cache Items\n",
	hot_obj_count);

#if XMALLOC_STATISTICS
    storeAppendPrintf(sentry, "Memory allocation statistics\n");
