                      stats.request_hit_disk_ratio60 / fct);

    storeAppendPrintf(sentry, "\tStorage Swap size:\t%.0f KB\n",
                      stats.store.swap.size / 1024);

    storeAppendPrintf(sentry, "\tStorage Swap capacity:\t%4.1f%% used, %4.1f%% free\n",
                      Math::doublePercent(stats.store.swap.size, stats.store.swap.capacity),
                      Math::doublePercent(stats.store.swap.available(), stats.store.swap.capacity));

    storeAppendPrintf(sentry, "\tStorage Mem size:\t%.0f KB\n",
                      stats.store.mem.size / 1024);

    storeAppendPrintf(sentry, "\tStorage Mem capacity:\t%4.1f%% used, %4.1f%% free\n",
                      Math::doublePercent(stats.store.mem.size, stats.store.mem.capacity),
                      Math::doublePercent(stats.store.mem.available(), stats.store.mem.capacity));

    storeAppendPrintf(sentry, "\tMean Object Size:\t%0.2f KB\n",
                      stats.store.swap.meanObjectSize() / 1024);

    storeAppendPrintf(sentry, "\tRequests given to unlinkd:\t%.0f\n",
                      stats.unlink_requests);
