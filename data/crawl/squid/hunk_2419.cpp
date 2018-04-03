     storeAppendPrintf(sentry, "\tReserved number of file descriptors:  %4.0f\n",
                       stats.reserved_fd);
     storeAppendPrintf(sentry, "\tStore Disk files open:                %4.0f\n",
-                      stats.store_open_disk_fd);
+                      stats.store.swap.open_disk_fd);
 
     storeAppendPrintf(sentry, "Internal Data Structures:\n");
     storeAppendPrintf(sentry, "\t%6.0f StoreEntries\n",
-                      stats.store_entries);
+                      stats.store.store_entry_count);
     storeAppendPrintf(sentry, "\t%6.0f StoreEntries with MemObjects\n",
-                      stats.store_mem_entries);
+                      stats.store.mem_object_count);
     storeAppendPrintf(sentry, "\t%6.0f Hot Object Cache Items\n",
-                      stats.hot_obj_count);
+                      stats.store.mem.count);
     storeAppendPrintf(sentry, "\t%6.0f on-disk objects\n",
-                      stats.n_disk_objects);
+                      stats.store.swap.count);
 }
 
 void
