#endif /* HAVE_EXT_MALLINFO */
#endif /* HAVE_MALLINFO */
    storeAppendPrintf(sentry, "Memory accounted for:\n");
    storeAppendPrintf(sentry, "\tTotal accounted:       %6d KB\n",
	statMemoryAccounted() >> 10);
    storeAppendPrintf(sentry, "\tmemPoolAlloc calls: %d\n",
	mem_pool_alloc_calls);
    storeAppendPrintf(sentry, "\tmemPoolFree calls: %d\n",
	mem_pool_free_calls);

    storeAppendPrintf(sentry, "File descriptor usage for %s:\n", appname);
    storeAppendPrintf(sentry, "\tMaximum number of file descriptors:   %4d\n",
	Squid_MaxFD);
