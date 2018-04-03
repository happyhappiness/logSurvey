                       (unsigned long)StoreEntry::inUseCount());
     storeAppendPrintf(sentry, "\t%6lu StoreEntries with MemObjects\n",
                       (unsigned long)MemObject::inUseCount());
-    storeAppendPrintf(sentry, "\t%6d Hot Object Cache Items\n",
-                      hot_obj_count);
-    storeAppendPrintf(sentry, "\t%6d on-disk objects\n",
-                      n_disk_objects);
+    storeAppendPrintf(sentry, "\t%6ld Hot Object Cache Items\n",
+                      (long)hot_obj_count);
+    storeAppendPrintf(sentry, "\t%6ld on-disk objects\n",
+                      (long)n_disk_objects);
 
 #if XMALLOC_STATISTICS
 
