#endif /* HAVE_MALLINFO */
    storeAppendPrintf(sentry, "Memory accounted for:\n");
    storeAppendPrintf(sentry, "\tTotal accounted:       %6d KB\n",
	memTotalAllocated() >> 10);
    storeAppendPrintf(sentry, "\tmemPoolAlloc calls: %d\n",
	mem_pool_alloc_calls);
    storeAppendPrintf(sentry, "\tmemPoolFree calls: %d\n",
