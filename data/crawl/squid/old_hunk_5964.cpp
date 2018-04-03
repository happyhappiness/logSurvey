	n_disk_objects);

#if XMALLOC_STATISTICS
    storeAppendPrintf(sentry, "Memory allocation statistics\n");
    malloc_statistics(info_get_mallstat, sentry);
#endif
}
