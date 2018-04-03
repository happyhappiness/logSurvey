 /* local routines */
 
 static void
-memStringStats(StoreEntry * sentry)
+memStringStats(std::ostream &stream)
 {
-    const char *pfmt = "%-20s\t %d\t %d\n";
     int i;
     int pooled_count = 0;
     size_t pooled_volume = 0;
     /* heading */
-    storeAppendPrintf(sentry,
-                      "String Pool\t Impact\t\t\n"
-                      " \t (%%strings)\t (%%volume)\n");
+    stream << "String Pool\t Impact\t\t\n \t (%%strings)\t (%%volume)\n";
     /* table body */
 
     for (i = 0; i < mem_str_pool_count; i++) {
         const MemAllocator *pool = StrPools[i].pool;
         const int plevel = pool->getMeter().inuse.level;
-        storeAppendPrintf(sentry, pfmt,
-                          pool->objectType(),
-                          xpercentInt(plevel, StrCountMeter.level),
-                          xpercentInt(plevel * pool->objectSize(), StrVolumeMeter.level));
+        stream << std::setw(20) << std::left << pool->objectType();
+        stream << std::right << "\t " << xpercentInt(plevel, StrCountMeter.level);
+        stream << "\t " << xpercentInt(plevel * pool->objectSize(), StrVolumeMeter.level) << "\n";
         pooled_count += plevel;
         pooled_volume += plevel * pool->objectSize();
     }
 
     /* malloc strings */
-    storeAppendPrintf(sentry, pfmt,
-                      "Other Strings",
-                      xpercentInt(StrCountMeter.level - pooled_count, StrCountMeter.level),
-                      xpercentInt(StrVolumeMeter.level - pooled_volume, StrVolumeMeter.level));
+    stream << std::setw(20) << std::left << "Other Strings";
+
+    stream << std::right << "\t ";
 
-    storeAppendPrintf(sentry, "\n");
+    stream << xpercentInt(StrCountMeter.level - pooled_count, StrCountMeter.level) << "\t ";
+
+    stream << xpercentInt(StrVolumeMeter.level - pooled_volume, StrVolumeMeter.level) << "\n\n";
 }
 
 static void
-memBufStats(StoreEntry * sentry)
+memBufStats(std::ostream & stream)
 {
-    storeAppendPrintf(sentry, "Large buffers: %ld (%ld KB)\n",
-                      (long int) HugeBufCountMeter.level,
-                      (long int) HugeBufVolumeMeter.level / 1024);
+    stream << "Large buffers: " <<
+    HugeBufCountMeter.level << " (" <<
+    HugeBufVolumeMeter.level / 1024 << " KB)\n";
 }
 
 void
 Mem::Stats(StoreEntry * sentry)
 {
-    storeBuffer(sentry);
-    Report(sentry);
-    memStringStats(sentry);
-    memBufStats(sentry);
-    storeBufferFlush(sentry);
+    StoreEntryStream stream(sentry);
+    Report(stream);
+    memStringStats(stream);
+    memBufStats(stream);
+    stream.flush();
 }
 
 /*
