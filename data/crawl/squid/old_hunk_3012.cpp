

    storeAppendPrintf(sentry, "\tStorage Mem size:\t%lu KB\n",
                      (unsigned long)mem_node::StoreMemSize() >> 10);

    storeAppendPrintf(sentry, "\tStorage Mem capacity:\t%4.1f%% used, %4.1f%% free\n",
                      Math::doublePercent(mem_node::InUseCount(), store_pages_max),
