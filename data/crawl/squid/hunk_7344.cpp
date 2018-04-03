 	    continue;
 	if (BIT_TEST(e->flag, KEY_PRIVATE))
 	    continue;
+	if ((dirn = storeDirNumber(e->swap_file_number)) >= ncache_dirs) {
+	    debug_trap("storeWriteCleanLogss: dirn out of range");
+	    continue;
+	}
+	if (fd[dirn] < 0)
+	    continue;
 	sprintf(line, "%08x %08x %08x %08x %9d %s\n",
 	    (int) e->swap_file_number,
 	    (int) e->timestamp,
 	    (int) e->expires,
 	    (int) e->lastmod,
 	    e->object_len,
 	    e->url);
-	if (write(fd, line, strlen(line)) < 0) {
-	    debug(50, 0, "storeWriteCleanLog: %s: %s\n", tmp_filename, xstrerror());
-	    debug(20, 0, "storeWriteCleanLog: Current swap logfile not replaced.\n");
-	    close(fd);
-	    safeunlink(tmp_filename, 0);
-	    return 0;
+	if (write(fd[dirn], line, strlen(line)) < 0) {
+	    debug(50, 0, "storeWriteCleanLogs: %s: %s\n", new[dirn], xstrerror());
+	    debug(20, 0, "storeWriteCleanLogs: Current swap logfile not replaced.\n");
+	    file_close(fd[dirn]);
+	    fd[dirn] = -1;
+	    safeunlink(cln[dirn], 0);
+	    continue;
 	}
-	if ((++n & 0xFFF) == 0) {
+	if ((++n & 0x3FFF) == 0) {
 	    getCurrentTime();
 	    debug(20, 1, "  %7d lines written so far.\n", n);
 	}
     }
-    if (close(fd) < 0) {
-	debug(50, 0, "storeWriteCleanLog: %s: %s\n", tmp_filename, xstrerror());
-	debug(20, 0, "storeWriteCleanLog: Current swap logfile not replaced.\n");
-	safeunlink(tmp_filename, 0);
-	return 0;
-    }
-    if (rename(tmp_filename, swaplog_file) < 0) {
-	debug(50, 0, "storeWriteCleanLog: rename failed: %s\n",
-	    xstrerror());
-	return 0;
-    }
-    file_close(swaplog_fd);
-    swaplog_fd = file_open(swaplog_file, NULL, O_WRONLY | O_CREAT, NULL, NULL);
-    if (swaplog_fd < 0) {
-	sprintf(tmp_error_buf, "Cannot open swap logfile: %s", swaplog_file);
-	fatal(tmp_error_buf);
-    }
+    safe_free(line);
+    for (dirn=0; dirn<ncache_dirs; dirn++) {
+        file_close(fd[dirn]);
+        fd[dirn] = -1;
+        if (rename(new[dirn], cur[dirn]) < 0) {
+	    debug(50, 0, "storeWriteCleanLogs: rename failed: %s\n",
+	        xstrerror());
+        }
+    }
+    storeDirCloseSwapLogs();
+    storeDirOpenSwapLogs();
     stop = getCurrentTime();
     r = stop - start;
     debug(20, 1, "  Finished.  Wrote %d lines.\n", n);
     debug(20, 1, "  Took %d seconds (%6.1lf lines/sec).\n",
 	r > 0 ? r : 0, (double) n / (r > 0 ? r : 1));
-
     /* touch a timestamp file if we're not still validating */
-    if (!store_validating) {
-	sprintf(tmp_filename, "%s-last-clean", swaplog_file);
-	file_close(file_open(tmp_filename, NULL, O_WRONLY | O_CREAT | O_TRUNC, NULL, NULL));
+    for (dirn=0; dirn<ncache_dirs; dirn++) {
+        if (!store_validating)
+	    file_close(file_open(cln[dirn], NULL,
+		O_WRONLY | O_CREAT | O_TRUNC, NULL, NULL));
+	safe_free(cur[dirn]);
+	safe_free(new[dirn]);
+	safe_free(cln[dirn]);
     }
     return n;
 }
