    storeAppendPrintf(&output, "Current Store Swap Size: %8lu KB\n",
                      store_swap_size);
    storeAppendPrintf(&output, "Current Capacity       : %d%% used, %d%% free\n",
                      Math::intPercent((int) store_swap_size, (int) maxSize()),
                      Math::intPercent((int) (maxSize() - store_swap_size), (int) maxSize()));
    /* FIXME Here we should output memory statistics */

    /* now the swapDir */
