 	NULL);
     if (x != DISK_OK)
 	fatal_dump(NULL);	/* This shouldn't happen */
-    return 0;
+    xfree(swapfilename);
 }
 
 /* recreate meta data from disk image in swap directory */
-
 /* Add one swap file at a time from disk storage */
 static void
 storeDoRebuildFromDisk(void *data)
