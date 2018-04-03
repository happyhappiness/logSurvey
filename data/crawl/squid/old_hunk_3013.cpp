    storeAppendPrintf(sentry, "\tMean Object Size:\t%0.2f KB\n",
                      n_disk_objects ? (double) store_swap_size / n_disk_objects : 0.0);

    storeAppendPrintf(sentry, "\tRequests given to unlinkd:\t%d\n",
                      statCounter.unlink.requests);

    storeAppendPrintf(sentry, "Median Service Times (seconds)  5 min    60 min:\n");

