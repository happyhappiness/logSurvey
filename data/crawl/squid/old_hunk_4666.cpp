    storeAppendPrintf(sentry, "\tStorage Swap size:\t%lu KB\n",
                      store_swap_size);

    storeAppendPrintf(sentry, "\tStorage Mem size:\t%d KB\n",
                      (int) (mem_node::store_mem_size >> 10));

    storeAppendPrintf(sentry, "\tMean Object Size:\t%0.2f KB\n",
                      n_disk_objects ? (double) store_swap_size / n_disk_objects : 0.0);
