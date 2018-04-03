 	fatal_dump("storeRebuiltFromDisk: rename failed");
     }
     file_close(swaplog_fd);
-    if ((swaplog_fd = file_open(swaplog_file, NULL, O_WRONLY | O_CREAT)) < 0)
+    if ((swaplog_fd = file_open(swaplog_file, NULL, O_WRONLY | O_CREAT, NULL, NULL)) < 0)
 	fatal_dump("storeRebuiltFromDisk: file_open(swaplog_file) failed");
+    if (store_validating) {
+	debug(20, 1, "Beginning Validation Procedure\n");
+	eventAdd("storeCleanup", storeCleanup, NULL, 0);
+    }
 }
 
 static void
