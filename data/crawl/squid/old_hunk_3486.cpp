    storeAppendPrintf(sentry, "\tCPU Time:\t%.3f seconds\n", cputime);

    storeAppendPrintf(sentry, "\tCPU Usage:\t%.2f%%\n",
                      dpercent(cputime, runtime));

    storeAppendPrintf(sentry, "\tCPU Usage, 5 minute avg:\t%.2f%%\n",
                      statCPUUsage(5));
