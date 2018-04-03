                       (long int) maxSize());
     storeAppendPrintf(&output, "Current Store Swap Size: %8lu KB\n",
                       store_swap_size);
+    // XXX : below capacity display calculation breaks with int overflow on 64-bit systems
     storeAppendPrintf(&output, "Current Capacity       : %d%% used, %d%% free\n",
                       Math::intPercent((int) store_swap_size, (int) maxSize()),
                       Math::intPercent((int) (maxSize() - store_swap_size), (int) maxSize()));