     storeAppendPrintf(sentry, "Current Capacity       : %d%% used, %d%% free\n",
 	percent((int) store_swap_size, (int) Config.Swap.maxSize),
 	percent((int) (Config.Swap.maxSize - store_swap_size), (int) Config.Swap.maxSize));
-    for (i = 0; i < Config.cacheSwap.n_configured; i++) {
-	SD = &Config.cacheSwap.swapDirs[i];
-	storeAppendPrintf(sentry, "\n");
-	storeAppendPrintf(sentry, "Store Directory #%d: %s\n", i, SD->path);
-	storeAppendPrintf(sentry, "First level subdirectories: %d\n", SD->l1);
-	storeAppendPrintf(sentry, "Second level subdirectories: %d\n", SD->l2);
-	storeAppendPrintf(sentry, "Maximum Size: %d KB\n", SD->max_size);
-	storeAppendPrintf(sentry, "Current Size: %d KB\n", SD->cur_size);
-	storeAppendPrintf(sentry, "Percent Used: %0.2f%%\n",
-	    100.0 * SD->cur_size / SD->max_size);
-	storeAppendPrintf(sentry, "Filemap bits in use: %d of %d (%d%%)\n",
-	    SD->map->n_files_in_map, SD->map->max_n_files,
-	    percent(SD->map->n_files_in_map, SD->map->max_n_files));
-#if HAVE_STATVFS
-#define fsbtoblk(num, fsbs, bs) \
-        (((fsbs) != 0 && (fsbs) < (bs)) ? \
-                (num) / ((bs) / (fsbs)) : (num) * ((fsbs) / (bs)))
-	if (!statvfs(SD->path, &sfs)) {
-	    storeAppendPrintf(sentry, "Filesystem Space in use: %d/%d KB (%d%%)\n",
-		fsbtoblk((sfs.f_blocks - sfs.f_bfree), sfs.f_frsize, 1024),
-		fsbtoblk(sfs.f_blocks, sfs.f_frsize, 1024),
-		percent(sfs.f_blocks - sfs.f_bfree, sfs.f_blocks));
-	    storeAppendPrintf(sentry, "Filesystem Inodes in use: %d/%d (%d%%)\n",
-		sfs.f_files - sfs.f_ffree, sfs.f_files,
-		percent(sfs.f_files - sfs.f_ffree, sfs.f_files));
-	}
-#endif
-	storeAppendPrintf(sentry, "Flags:");
-	if (SD->flags.selected)
-	    storeAppendPrintf(sentry, " SELECTED");
-	if (SD->flags.read_only)
-	    storeAppendPrintf(sentry, " READ-ONLY");
-	storeAppendPrintf(sentry, "\n");
-    }
+    storeUfsDirStats(sentry);
 }
 
 int
