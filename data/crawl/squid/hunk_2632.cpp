     int totl_in = 0;
     int free_in = 0;
     int x;
-    const double currentSizeInKB = currentSize() / 1024.0;
     storeAppendPrintf(&sentry, "First level subdirectories: %d\n", l1);
     storeAppendPrintf(&sentry, "Second level subdirectories: %d\n", l2);
-    storeAppendPrintf(&sentry, "Maximum Size: %"PRIu64" KB\n", max_size);
-    storeAppendPrintf(&sentry, "Current Size: %.2f KB\n", currentSizeInKB);
+    storeAppendPrintf(&sentry, "Maximum Size: %"PRIu64" KB\n", maxSize() >> 10);
+    storeAppendPrintf(&sentry, "Current Size: %.2f KB\n", currentSize() / 1024.0);
     storeAppendPrintf(&sentry, "Percent Used: %0.2f%%\n",
-                      Math::doublePercent(currentSizeInKB, max_size));
+                      Math::doublePercent(currentSize(), maxSize()));
     storeAppendPrintf(&sentry, "Filemap bits in use: %d of %d (%d%%)\n",
                       map->n_files_in_map, map->max_n_files,
                       Math::intPercent(map->n_files_in_map, map->max_n_files));
