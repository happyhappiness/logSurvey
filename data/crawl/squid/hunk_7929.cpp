 	    fast_mode = (sb.st_mtime <= last_clean) ? 1 : 0;
 	}
     }
-    if (fast_mode)
-	debug(0, 1, "Rebuilding in FAST MODE.\n");
+    /* Open the existing swap log for reading */
+    if ((old_log = fopen(swaplog_file, "r")) == (FILE *) NULL) {
+	sprintf(tmp_error_buf, "storeRebuildFromDisk: %s: %s",
+	    swaplog_file, xstrerror());
+	fatal(tmp_error_buf);
+    }
+    /* Open a new log for writing */
+    sprintf(line_in, "%s.new", swaplog_file);
+    new_log_name = xstrdup(line_in);
+    new_log = fopen(new_log_name, "w");
+    if (new_log == (FILE *) NULL) {
+	sprintf(tmp_error_buf, "storeRebuildFromDisk: %s: %s",
+	    new_log_name, xstrerror());
+	fatal(tmp_error_buf);
+    }
 
-    /* go to top of the file */
-    (void) lseek(swaplog_fd, 0L, SEEK_SET);
+    if (fast_mode)
+   debug(20, 1, "Rebuilding in FAST MODE.\n");
 
     memset(line_in, '\0', 4096);
-    while (fgets(line_in, 4096, swaplog_stream)) {
-
+    while (fgets(line_in, 4096, old_log)) {
 	if ((linecount++ & 0x7F) == 0)	/* update current time */
 	    cached_curtime = time(NULL);
 
 	if ((linecount & 0xFFF) == 0)
-	    debug(0, 1, "  %7d Lines read so far.\n", linecount);
+	    debug(20, 1, "  %7d Lines read so far.\n", linecount);
 
-	debug(0, 10, "line_in: %s", line_in);
+	debug(20, 10, "line_in: %s", line_in);
 	if ((line_in[0] == '\0') || (line_in[0] == '\n') ||
 	    (line_in[0] == '#'))
 	    continue;		/* skip bad lines */
