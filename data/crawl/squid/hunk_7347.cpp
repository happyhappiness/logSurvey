 	SD->swaplog_fd = fd;
     }
 }
+
+void
+storeDirCloseSwapLogs(void)
+{
+    int i;
+    SwapDir *SD;
+    for (i = 0; i < ncache_dirs; i++) {
+	SD = &SwapDirs[i];
+	file_close(SD->swaplog_fd);
+    }
+}
+
+FILE *
+storeDirOpenTmpSwapLog(int dirn, int *clean_flag)
+{
+    char *swaplog_path = xstrdup(storeDirSwapLogFile(dirn, NULL));
+    char *clean_path = xstrdup(storeDirSwapLogFile(dirn, ".last-clean"));
+    char *new_path = xstrdup(storeDirSwapLogFile(dirn, ".new"));
+    struct stat log_sb;
+    struct stat clean_sb;
+    SwapDir *SD = &SwapDirs[dirn];
+    FILE *fp;
+    int fd;
+    if (stat(swaplog_path, &log_sb) < 0) {
+	debug(20, 1, "Cache Dir #%d: No log file\n", dirn);
+	safe_free(swaplog_path);
+	safe_free(clean_path);
+	safe_free(new_path);
+	return NULL;
+    }
+    debug(20, 1, "Rebuilding storage from %s\n", swaplog_path);
+    /* close the existing write-only FD */
+    file_close(SD->swaplog_fd);
+    /* open a write-only FD for the new log */
+    fd = file_open(new_path, NULL, O_WRONLY | O_CREAT, NULL, NULL);
+    if (fd < 0) {
+	debug(50, 1, "%s: %s\n", new_path, xstrerror());
+	fatal("storeDirOpenTmpSwapLog: Failed to open swap log.");
+    }
+    SD->swaplog_fd = fd;
+    /* open a read-only stream of the old log */
+    fp = fopen(swaplog_path, "r");
+    if (fp == NULL) {
+	debug(50, 0, "%s: %s\n", swaplog_path, xstrerror());
+	fatal("Failed to open swap log for reading");
+    }
+    if (stat(clean_path, &clean_sb) < 0)
+	*clean_flag = 0;
+    else if (clean_sb.st_mtime < log_sb.st_mtime)
+	*clean_flag = 0;
+    else
+	*clean_flag = 1;
+    safeunlink(clean_path, 1);
+    safe_free(swaplog_path);
+    safe_free(clean_path);
+    safe_free(new_path);
+    return fp;
+}
+
+void
+storeDirCloseTmpSwapLog(int dirn)
+{
+    char *swaplog_path = xstrdup(storeDirSwapLogFile(dirn, NULL));
+    char *new_path = xstrdup(storeDirSwapLogFile(dirn, ".new"));
+    SwapDir *SD = &SwapDirs[dirn];
+    int fd;
+    if (rename(new_path, swaplog_path) < 0) {
+	debug(50, 0, "%s,%s: %s\n", new_path, swaplog_path, xstrerror());
+	fatal("storeDirCloseTmpSwapLog: rename failed");
+    }
+    file_close(SD->swaplog_fd);
+    fd = file_open(swaplog_path, NULL, O_WRONLY | O_CREAT, NULL, NULL);
+    if (fd < 0) {
+	debug(50, 1, "%s: %s\n", swaplog_path, xstrerror());
+	fatal("storeDirCloseTmpSwapLog: Failed to open swap log.");
+    }
+    SD->swaplog_fd = fd;
+}
