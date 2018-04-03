 void
 storeDiskdDirDump(StoreEntry * entry, SwapDir * s)
 {
-    diskdinfo_t *diskdinfo = s->fsdata;
-    storeAppendPrintf(entry, " %d %d %d",
-	s->max_size >> 10,
-	diskdinfo->l1,
-	diskdinfo->l2);
+    commonUfsDirDump (entry, s);
     dump_cachedir_options(entry, options, s);
 }
 
-/*
- * Only "free" the filesystem specific stuff here
- */
-static void
-storeDiskdDirFree(SwapDir * s)
-{
-    diskdinfo_t *diskdinfo = s->fsdata;
-    if (diskdinfo->swaplog_fd > -1) {
-	file_close(diskdinfo->swaplog_fd);
-	diskdinfo->swaplog_fd = -1;
-    }
-    filemapFreeMemory(diskdinfo->map);
-    xfree(diskdinfo);
-    s->fsdata = NULL;		/* Will aid debugging... */
-
-}
-
-char *
-storeDiskdDirFullPath(SwapDir * SD, sfileno filn, char *fullpath)
-{
-    LOCAL_ARRAY(char, fullfilename, SQUID_MAXPATHLEN);
-    diskdinfo_t *diskdinfo = SD->fsdata;
-    int L1 = diskdinfo->l1;
-    int L2 = diskdinfo->l2;
-    if (!fullpath)
-	fullpath = fullfilename;
-    fullpath[0] = '\0';
-    snprintf(fullpath, SQUID_MAXPATHLEN, "%s/%02X/%02X/%08X",
-	SD->path,
-	((filn / L2) / L2) % L1,
-	(filn / L2) % L2,
-	filn);
-    return fullpath;
-}
-
-/*
- * storeDiskdCleanupDoubleCheck
- *
- * This is called by storeCleanup() if -S was given on the command line.
- */
-static int
-storeDiskdCleanupDoubleCheck(SwapDir * sd, StoreEntry * e)
-{
-    struct stat sb;
-    if (stat(storeDiskdDirFullPath(sd, e->swap_filen, NULL), &sb) < 0) {
-	debug(47, 0) ("storeDiskdCleanupDoubleCheck: MISSING SWAP FILE\n");
-	debug(47, 0) ("storeDiskdCleanupDoubleCheck: FILENO %08X\n", e->swap_filen);
-	debug(47, 0) ("storeDiskdCleanupDoubleCheck: PATH %s\n",
-	    storeDiskdDirFullPath(sd, e->swap_filen, NULL));
-	storeEntryDump(e, 0);
-	return -1;
-    }
-    if (e->swap_file_sz != sb.st_size) {
-	debug(47, 0) ("storeDiskdCleanupDoubleCheck: SIZE MISMATCH\n");
-	debug(47, 0) ("storeDiskdCleanupDoubleCheck: FILENO %08X\n", e->swap_filen);
-	debug(47, 0) ("storeDiskdCleanupDoubleCheck: PATH %s\n",
-	    storeDiskdDirFullPath(sd, e->swap_filen, NULL));
-	debug(47, 0) ("storeDiskdCleanupDoubleCheck: ENTRY SIZE: %ld, FILE SIZE: %ld\n",
-	    (long int) e->swap_file_sz, (long int) sb.st_size);
-	storeEntryDump(e, 0);
-	return -1;
-    }
-    return 0;
-}
-
 /*
  * storeDiskdDirParse
  *
