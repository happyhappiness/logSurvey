    storeAppendPrintf(sentry, "\tCPU Usage, 60 minute avg:\t%.2f%%\n",
                      stats.cpu_usage60);

    storeAppendPrintf(sentry, "\tMaximum Resident Size: %.0f KB\n",
                      stats.maxrss);

