 
     if (fd < 0) {
         debug(47, 1) ("%s: %s\n", path, xstrerror());
-        fatal("storeCossDirInit: Failed to open a COSS directory.");
+        fatal("storeCossDirInit: Failed to open a COSS file.");
     }
 
     n_coss_dirs++;
-    (void) storeDirGetBlkSize(path, &fs.blksize);
+    /*
+     * fs.blksize is normally determined by calling statvfs() etc,
+     * but we just set it here.  It is used in accounting the
+     * total store size, and is reported in cachemgr 'storedir'
+     * page.
+     */
+    fs.blksize = 1 << blksz_bits;
 }
 
 void
