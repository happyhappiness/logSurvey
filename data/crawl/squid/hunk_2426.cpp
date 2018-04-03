     if (max_objsize <= 0)
         fatal("Rock store requires a positive max-size");
 
-#if THIS_CODE_IS_FIXED_AND_MOVED
-    // XXX: should not use map as it is not yet created
-    // XXX: max_size is in Bytes now
-    // XXX: Use DBG_IMPORTANT (and DBG_CRITICAL if opt_parse_cfg_only?)
-    // TODO: Shrink max_size to avoid waste?
-    const int64_t mapRoundWasteMx = max_objsize*sizeof(long)*8;
-    const int64_t sizeRoundWasteMx = 1024; // max_size stored in KB
-    const int64_t roundingWasteMx = max(mapRoundWasteMx, sizeRoundWasteMx);
-    const int64_t totalWaste = maxSize() - diskOffsetLimit();
-    assert(diskOffsetLimit() <= maxSize());
+    const int64_t maxSizeRoundingWaste = 1024 * 1024; // size is configured in MB
+    const int64_t maxObjectSizeRoundingWaste = maxObjectSize();
+    const int64_t maxRoundingWaste =
+        max(maxSizeRoundingWaste, maxObjectSizeRoundingWaste);
+    const int64_t usableDiskSize = diskOffset(entryLimitAllowed());
+    const int64_t diskWasteSize = maxSize() - usableDiskSize;
+    Must(diskWasteSize >= 0);
 
     // warn if maximum db size is not reachable due to sfileno limit
-    if (map->entryLimit() == entryLimitHigh() && totalWaste > roundingWasteMx) {
-        debugs(47, 0, "Rock store cache_dir[" << index << "]:");
-        debugs(47, 0, "\tmaximum number of entries: " << map->entryLimit());
-        debugs(47, 0, "\tmaximum entry size: " << max_objsize << " bytes");
-        debugs(47, 0, "\tmaximum db size: " << maxSize() << " bytes");
-        debugs(47, 0, "\tusable db size:  " << diskOffsetLimit() << " bytes");
-        debugs(47, 0, "\tdisk space waste: " << totalWaste << " bytes");
-        debugs(47, 0, "WARNING: Rock store config wastes space.");
+    if (entryLimitAllowed() == entryLimitHigh() &&
+        diskWasteSize >= maxRoundingWaste) {
+        debugs(47, DBG_CRITICAL, "Rock store cache_dir[" << index << "] '" << path << "':");
+        debugs(47, DBG_CRITICAL, "\tmaximum number of entries: " << entryLimitAllowed());
+        debugs(47, DBG_CRITICAL, "\tmaximum object size: " << maxObjectSize() << " Bytes");
+        debugs(47, DBG_CRITICAL, "\tmaximum db size: " << maxSize() << " Bytes");
+        debugs(47, DBG_CRITICAL, "\tusable db size:  " << usableDiskSize << " Bytes");
+        debugs(47, DBG_CRITICAL, "\tdisk space waste: " << diskWasteSize << " Bytes");
+        debugs(47, DBG_CRITICAL, "WARNING: Rock store config wastes space.");
     }
-#endif
 }
 
 void
