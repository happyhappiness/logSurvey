 	storelog_fd = file_open(fname, O_WRONLY | O_CREAT, NULL, NULL);
     if (storelog_fd < 0)
 	debug(20, 1) ("Store logging disabled\n");
-    if (ncache_dirs < 1)
+    if (Config.cacheSwap.n_configured < 1)
 	fatal("No cache_dir's specified in config file");
     storeVerifySwapDirs();
     storeDirOpenSwapLogs();
