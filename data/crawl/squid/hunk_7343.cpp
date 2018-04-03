 static void
 storeStartRebuildFromDisk(void)
 {
-    struct stat sb;
     int i;
-    struct storeRebuild_data *data;
-    time_t last_clean;
-    if (stat(swaplog_file, &sb) < 0) {
-	debug(20, 1, "storeRebuildFromDisk: No log file\n");
-	store_rebuilding = STORE_NOT_REBUILDING;
-	return;
-    }
-    data = xcalloc(1, sizeof(*data));
-    for (i = 0; i < ncache_dirs; i++)
-	debug(20, 1, "Rebuilding storage from disk image in %s\n", storeSwapDir(i));
-    data->start = getCurrentTime();
-    /* Check if log is clean */
-    sprintf(tmp_filename, "%s-last-clean", swaplog_file);
-    if (stat(tmp_filename, &sb) >= 0) {
-	last_clean = sb.st_mtime;
-	if (stat(swaplog_file, &sb) >= 0)
-	    store_rebuilding = (sb.st_mtime <= last_clean) ?
-		STORE_REBUILDING_CLEAN : STORE_REBUILDING_DIRTY;
-    }
-    /* Remove timestamp in case we crash during rebuild */
-    safeunlink(tmp_filename, 1);
-    /* close the existing write-only swaplog, and open a temporary
-     * write-only swaplog  */
-    if (swaplog_fd > -1)
-	file_close(swaplog_fd);
-    sprintf(tmp_filename, "%s.new", swaplog_file);
-    swaplog_fd = file_open(tmp_filename, NULL, O_WRONLY | O_CREAT | O_TRUNC, NULL, NULL);
-    debug(20, 3, "swaplog_fd %d is now '%s'\n", swaplog_fd, tmp_filename);
-    if (swaplog_fd < 0) {
-	debug(50, 0, "storeStartRebuildFromDisk: %s: %s\n",
-	    tmp_filename, xstrerror());
-	fatal("storeStartRebuildFromDisk: Can't open tmp swaplog");
-    }
-    /* Open the existing swap log for reading */
-    if ((data->log = fopen(swaplog_file, "r")) == (FILE *) NULL) {
-	sprintf(tmp_error_buf, "storeRebuildFromDisk: %s: %s",
-	    swaplog_file, xstrerror());
-	fatal(tmp_error_buf);
-    }
-    debug(20, 3, "data->log %d is now '%s'\n", fileno(data->log), swaplog_file);
-    debug(20, 1, "Rebuilding in %s log.\n",
-	store_rebuilding == STORE_REBUILDING_CLEAN ? "CLEAN" : "DIRTY");
-    store_validating = store_rebuilding == STORE_REBUILDING_CLEAN ? 0 : 1;
-    memset(data->line_in, '\0', 4096);
-    data->speed = 50;
-    /* Start reading the log file */
+    struct storeRebuildState *RB;
+    struct _rebuild_dir *d;
+    FILE *fp;
+    int clean;
+    RB = xcalloc(1, sizeof(struct storeRebuildState));
+    RB->start = squid_curtime;
+    for (i = 0; i < ncache_dirs; i++) {
+	fp = storeDirOpenTmpSwapLog(i, &clean);
+	if (fp == NULL)
+	    continue;
+	d = xcalloc(1, sizeof(struct _rebuild_dir));
+	d->dirn = i;
+	d->log = fp;
+	d->clean = clean;
+	d->speed = opt_foreground_rebuild ? 1 << 30 : 50;
+	d->next = RB->rebuild_dir;
+	RB->rebuild_dir = d;
+	if (!clean)
+	    store_validating = 1;
+	debug(20, 1, "Rebuilding storage in Cache Dir #%d (%s)\n",
+	    i, clean ? "CLEAN" : "DIRTY");
+    }
+    RB->line_in_sz = 4096;
+    RB->line_in = xcalloc(1, RB->line_in_sz);
     if (opt_foreground_rebuild) {
-	data->speed = 1 << 30;
-	storeDoRebuildFromDisk(data);
+	storeDoRebuildFromDisk(RB);
     } else {
-	eventAdd("storeRebuild", storeDoRebuildFromDisk, data, 0);
+	eventAdd("storeRebuild", storeDoRebuildFromDisk, RB, 0);
     }
 }
 
