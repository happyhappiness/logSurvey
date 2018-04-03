 storeDiskdDirStats(SwapDir * SD, StoreEntry * sentry)
 {
     diskdinfo_t *diskdinfo = SD->fsdata;
-    int totl_kb = 0;
-    int free_kb = 0;
-    int totl_in = 0;
-    int free_in = 0;
-    int x;
-    storeAppendPrintf(sentry, "First level subdirectories: %d\n", diskdinfo->l1);
-    storeAppendPrintf(sentry, "Second level subdirectories: %d\n", diskdinfo->l2);
-    storeAppendPrintf(sentry, "Maximum Size: %d KB\n", SD->max_size);
-    storeAppendPrintf(sentry, "Current Size: %d KB\n", SD->cur_size);
-    storeAppendPrintf(sentry, "Percent Used: %0.2f%%\n",
-	100.0 * SD->cur_size / SD->max_size);
-    storeAppendPrintf(sentry, "Filemap bits in use: %d of %d (%d%%)\n",
-	diskdinfo->map->n_files_in_map, diskdinfo->map->max_n_files,
-	percent(diskdinfo->map->n_files_in_map, diskdinfo->map->max_n_files));
-    x = storeDirGetUFSStats(SD->path, &totl_kb, &free_kb, &totl_in, &free_in);
-    if (0 == x) {
-	storeAppendPrintf(sentry, "Filesystem Space in use: %d/%d KB (%d%%)\n",
-	    totl_kb - free_kb,
-	    totl_kb,
-	    percent(totl_kb - free_kb, totl_kb));
-	storeAppendPrintf(sentry, "Filesystem Inodes in use: %d/%d (%d%%)\n",
-	    totl_in - free_in,
-	    totl_in,
-	    percent(totl_in - free_in, totl_in));
-    }
-    storeAppendPrintf(sentry, "Flags:");
-    if (SD->flags.selected)
-	storeAppendPrintf(sentry, " SELECTED");
-    if (SD->flags.read_only)
-	storeAppendPrintf(sentry, " READ-ONLY");
-    storeAppendPrintf(sentry, "\n");
+    commonUfsDirStats (SD, sentry);
     storeAppendPrintf(sentry, "Pending operations: %d\n", diskdinfo->away);
 }
 
