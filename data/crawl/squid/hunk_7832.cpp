     safe_free(data);
     sprintf(tmp_filename, "%s.new", swaplog_file);
     if (rename(tmp_filename, swaplog_file) < 0) {
-	debug(20, 0, "storeRebuiltFromDisk: rename failed: %s\n",
-	    xstrerror());
+	debug(20, 0, "storeRebuiltFromDisk: %s,%s: %s\n",
+		tmp_filename, swaplog_file, xstrerror());
+	fatal_dump("storeRebuiltFromDisk: rename failed");
     }
-    file_update_open(swaplog_fd, swaplog_file);
-    /* file_update_open clears the lock so we must reset it */
+    if (file_write_unlock(swaplog_fd, swaplog_lock) != DISK_OK)
+	fatal_dump("storeRebuiltFromDisk: swaplog unlock failed");
+    if (file_close(swaplog_fd) != DISK_OK)
+	fatal_dump("storeRebuiltFromDisk: file_close(swaplog_fd) failed");
+    if ((swaplog_fd = file_open(swaplog_file, NULL, O_WRONLY | O_CREAT | O_APPEND)) < 0)
+	fatal_dump("storeRebuiltFromDisk: file_open(swaplog_file) failed");
     swaplog_lock = file_write_lock(swaplog_fd);
 }
 
