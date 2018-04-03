    storeAppendPrintf(sentry, "{Resource usage for %s:}\n", appname);
    storeAppendPrintf(sentry, "{\tUP Time:\t%.3f seconds}\n", runtime);
    storeAppendPrintf(sentry, "{\tCPU Time:\t%.3f seconds}\n", cputime);
    storeAppendPrintf(sentry, "{\tCPU Usage:\t%d%%}\n",
	dpercent(cputime, runtime));
    storeAppendPrintf(sentry, "{\tMaximum Resident Size: %ld KB}\n",
	rusage_maxrss(&rusage));
