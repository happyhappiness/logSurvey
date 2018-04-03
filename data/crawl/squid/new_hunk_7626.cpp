	storeGetSwapSize() >> 10);
    storeAppendPrintf(sentry, "{\tStorage Mem size:\t%d KB}\n",
	storeGetMemSize() >> 10);

#if HAVE_GETRUSAGE && defined(RUSAGE_SELF)
    storeAppendPrintf(sentry, "{Resource usage for %s:}\n", appname);