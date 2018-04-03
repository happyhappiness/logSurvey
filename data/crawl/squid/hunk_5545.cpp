 void
 storeUfsDirDump(StoreEntry * entry, SwapDir * s)
 {
-    ufsinfo_t *ufsinfo = (ufsinfo_t *) s->fsdata;
-    storeAppendPrintf(entry, " %d %d %d",
-	s->max_size >> 10,
-	ufsinfo->l1,
-	ufsinfo->l2);
+    commonUfsDirDump (entry, s);
     dump_cachedir_options(entry, options, s);
 }
 
-/*
- * Only "free" the filesystem specific stuff here
- */
-static void
-storeUfsDirFree(SwapDir * s)
-{
-    ufsinfo_t *ufsinfo = (ufsinfo_t *) s->fsdata;
-    if (ufsinfo->swaplog_fd > -1) {
-	file_close(ufsinfo->swaplog_fd);
-	ufsinfo->swaplog_fd = -1;
-    }
-    filemapFreeMemory(ufsinfo->map);
-    xfree(ufsinfo);
-    s->fsdata = NULL;		/* Will aid debugging... */
-
-}
-
-char *
-storeUfsDirFullPath(SwapDir * SD, sfileno filn, char *fullpath)
-{
-    LOCAL_ARRAY(char, fullfilename, SQUID_MAXPATHLEN);
-    ufsinfo_t *ufsinfo = (ufsinfo_t *) SD->fsdata;
-    int L1 = ufsinfo->l1;
-    int L2 = ufsinfo->l2;
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
- * storeUfsCleanupDoubleCheck
- *
- * This is called by storeCleanup() if -S was given on the command line.
- */
-static int
-storeUfsCleanupDoubleCheck(SwapDir * sd, StoreEntry * e)
-{
-    struct stat sb;
-    if (stat(storeUfsDirFullPath(sd, e->swap_filen, NULL), &sb) < 0) {
-	debug(47, 0) ("storeUfsCleanupDoubleCheck: MISSING SWAP FILE\n");
-	debug(47, 0) ("storeUfsCleanupDoubleCheck: FILENO %08X\n", e->swap_filen);
-	debug(47, 0) ("storeUfsCleanupDoubleCheck: PATH %s\n",
-	    storeUfsDirFullPath(sd, e->swap_filen, NULL));
-	storeEntryDump(e, 0);
-	return -1;
-    }
-    if (e->swap_file_sz != sb.st_size) {
-	debug(47, 0) ("storeUfsCleanupDoubleCheck: SIZE MISMATCH\n");
-	debug(47, 0) ("storeUfsCleanupDoubleCheck: FILENO %08X\n", e->swap_filen);
-	debug(47, 0) ("storeUfsCleanupDoubleCheck: PATH %s\n",
-	    storeUfsDirFullPath(sd, e->swap_filen, NULL));
-	debug(47, 0) ("storeUfsCleanupDoubleCheck: ENTRY SIZE: %ld, FILE SIZE: %ld\n",
-	    (long int) e->swap_file_sz, (long int) sb.st_size);
-	storeEntryDump(e, 0);
-	return -1;
-    }
-    return 0;
-}
-
 /*
  * storeUfsDirParse
  *
