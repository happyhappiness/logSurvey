    if (SD->flags.read_only)
	storeAppendPrintf(sentry, " READ-ONLY");
    storeAppendPrintf(sentry, "\n");
#if OLD_UNUSED_CODE
#if !HEAP_REPLACEMENT
    storeAppendPrintf(sentry, "LRU Expiration Age: %6.2f days\n",
	(double) storeAufsDirExpiredReferenceAge(SD) / 86400.0);
#else
    storeAppendPrintf(sentry, "Storage Replacement Threshold:\t%f\n",
	heap_peepminkey(sd.repl.heap.heap));
#endif
#endif /* OLD_UNUSED_CODE */
}

/*
