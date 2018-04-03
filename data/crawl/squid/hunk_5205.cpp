     size = i << 10;		/* Mbytes to kbytes */
 
     if (size <= 0)
-        fatal("storeDiskdDirReconfigure: invalid size value");
-
-    l1 = GetInteger();
-
-    if (l1 <= 0)
-        fatal("storeDiskdDirReconfigure: invalid level 1 directories value");
-
-    l2 = GetInteger();
-
-    if (l2 <= 0)
-        fatal("storeDiskdDirReconfigure: invalid level 2 directories value");
+        fatal("UFSSwapDir::parseSizeL1L2: invalid size value");
 
     /* just reconfigure it */
     if (size == max_size)
