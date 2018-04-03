 /* ========== LOCAL FUNCTIONS ABOVE, GLOBAL FUNCTIONS BELOW ========== */
 
 void
-storeAufsDirStats(SwapDir *SD, StoreEntry * sentry)
+storeAufsDirStats(SwapDir * SD, StoreEntry * sentry)
 {
     aioinfo_t *aioinfo;
 #if HAVE_STATVFS
     struct statvfs sfs;
 #endif
-    aioinfo = (aioinfo_t *)SD->fsdata;
+    aioinfo = (aioinfo_t *) SD->fsdata;
     storeAppendPrintf(sentry, "First level subdirectories: %d\n", aioinfo->l1);
     storeAppendPrintf(sentry, "Second level subdirectories: %d\n", aioinfo->l2);
     storeAppendPrintf(sentry, "Maximum Size: %d KB\n", SD->max_size);
     storeAppendPrintf(sentry, "Current Size: %d KB\n", SD->cur_size);
     storeAppendPrintf(sentry, "Percent Used: %0.2f%%\n",
-        100.0 * SD->cur_size / SD->max_size);
+	100.0 * SD->cur_size / SD->max_size);
     storeAppendPrintf(sentry, "Filemap bits in use: %d of %d (%d%%)\n",
-    aioinfo->map->n_files_in_map, aioinfo->map->max_n_files,
-    percent(aioinfo->map->n_files_in_map, aioinfo->map->max_n_files));
+	aioinfo->map->n_files_in_map, aioinfo->map->max_n_files,
+	percent(aioinfo->map->n_files_in_map, aioinfo->map->max_n_files));
 #if HAVE_STATVFS
 #define fsbtoblk(num, fsbs, bs) \
     (((fsbs) != 0 && (fsbs) < (bs)) ? \
             (num) / ((bs) / (fsbs)) : (num) * ((fsbs) / (bs)))
-	if (!statvfs(SD->path, &sfs)) {
-            storeAppendPrintf(sentry, "Filesystem Space in use: %d/%d KB (%d%%)\n",
-            fsbtoblk((sfs.f_blocks - sfs.f_bfree), sfs.f_frsize, 1024),
-            fsbtoblk(sfs.f_blocks, sfs.f_frsize, 1024),
-            percent(sfs.f_blocks - sfs.f_bfree, sfs.f_blocks));
-            storeAppendPrintf(sentry, "Filesystem Inodes in use: %d/%d (%d%%)\n",
-            sfs.f_files - sfs.f_ffree, sfs.f_files,
-            percent(sfs.f_files - sfs.f_ffree, sfs.f_files));
+    if (!statvfs(SD->path, &sfs)) {
+	storeAppendPrintf(sentry, "Filesystem Space in use: %d/%d KB (%d%%)\n",
+	    fsbtoblk((sfs.f_blocks - sfs.f_bfree), sfs.f_frsize, 1024),
+	    fsbtoblk(sfs.f_blocks, sfs.f_frsize, 1024),
+	    percent(sfs.f_blocks - sfs.f_bfree, sfs.f_blocks));
+	storeAppendPrintf(sentry, "Filesystem Inodes in use: %d/%d (%d%%)\n",
+	    sfs.f_files - sfs.f_ffree, sfs.f_files,
+	    percent(sfs.f_files - sfs.f_ffree, sfs.f_files));
     }
 #endif
     storeAppendPrintf(sentry, "Flags:");
     if (SD->flags.selected)
-        storeAppendPrintf(sentry, " SELECTED");
+	storeAppendPrintf(sentry, " SELECTED");
     if (SD->flags.read_only)
-        storeAppendPrintf(sentry, " READ-ONLY");
+	storeAppendPrintf(sentry, " READ-ONLY");
     storeAppendPrintf(sentry, "\n");
 #if !HEAP_REPLACEMENT
     storeAppendPrintf(sentry, "LRU Expiration Age: %6.2f days\n",
