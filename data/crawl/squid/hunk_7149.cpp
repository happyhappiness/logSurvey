     char *path;
     int fd;
     SwapDir *SD;
-    for (i = 0; i < ncache_dirs; i++) {
-	SD = &SwapDirs[i];
+    for (i = 0; i < Config.cacheSwap.n_configured; i++) {
+	SD = &Config.cacheSwap.swapDirs[i];
 	path = storeDirSwapLogFile(i, NULL);
 	fd = file_open(path, O_WRONLY | O_CREAT, NULL, NULL);
 	if (fd < 0) {
 	    debug(50, 1) ("%s: %s\n", path, xstrerror());
 	    fatal("storeDirOpenSwapLogs: Failed to open swap log.");
 	}
-	debug(20, 3) ("Cache Dir #%d log opened on FD %d\n", i, fd);
+	debug(47, 3) ("Cache Dir #%d log opened on FD %d\n", i, fd);
 	SD->swaplog_fd = fd;
     }
 }
