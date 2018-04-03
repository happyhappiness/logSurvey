     int x;
     storeAppendPrintf(&sentry, "First level subdirectories: %d\n", l1);
     storeAppendPrintf(&sentry, "Second level subdirectories: %d\n", l2);
-    storeAppendPrintf(&sentry, "Maximum Size: %d KB\n", max_size);
-    storeAppendPrintf(&sentry, "Current Size: %d KB\n", cur_size);
+    storeAppendPrintf(&sentry, "Maximum Size: %Zu KB\n", max_size);
+    storeAppendPrintf(&sentry, "Current Size: %Zu KB\n", cur_size);
     storeAppendPrintf(&sentry, "Percent Used: %0.2f%%\n",
-                      100.0 * cur_size / max_size);
+                      (double)(100.0 * cur_size) / (double)max_size);
     storeAppendPrintf(&sentry, "Filemap bits in use: %d of %d (%d%%)\n",
                       map->n_files_in_map, map->max_n_files,
                       Math::intPercent(map->n_files_in_map, map->max_n_files));
