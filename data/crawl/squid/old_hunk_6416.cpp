	hot_obj_count);
    storeAppendPrintf(sentry, "\t%6d Filemap bits set\n",
	storeDirMapBitsInUse());

#if XMALLOC_STATISTICS
    storeAppendPrintf(sentry, "Memory allocation statistics\n");