 	if (e->object_len <= 0)
 	    continue;
 	storeSwapFullPath(e->swap_file_number, swapfilename);
-	fprintf(fp, "%s %s %d %d %d\n",
+	x = fprintf(fp, "%s %s %d %d %d\n",
 	    swapfilename, e->url, (int) e->expires, (int) e->timestamp,
 	    e->object_len);
+	if (x < 0) {
+	    debug(20, 0, "storeWriteCleanLog: %s: %s", tmp_filename, xstrerror());
+	    debug(20, 0, "storeWriteCleanLog: Current swap logfile not replaced.\n");
+	    fclose(fp);
+	    safeunlink(tmp_filename, 0);
+	    return 0;
+	}
 	if ((++n & 0xFFF) == 0) {
 	    getCurrentTime();
 	    debug(20, 1, "  %7d lines written so far.\n", n);
 	}
     }
-    fclose(fp);
-
+    if (fclose(fp) < 0) {
+	debug(20, 0, "storeWriteCleanLog: %s: %s", tmp_filename, xstrerror());
+	debug(20, 0, "storeWriteCleanLog: Current swap logfile not replaced.\n");
+	safeunlink(tmp_filename, 0);
+	return 0;
+    }
     if (file_write_unlock(swaplog_fd, swaplog_lock) != DISK_OK) {
 	debug(20, 0, "storeWriteCleanLog: Failed to unlock swaplog!\n");
 	debug(20, 0, "storeWriteCleanLog: Current swap logfile not replaced.\n");
