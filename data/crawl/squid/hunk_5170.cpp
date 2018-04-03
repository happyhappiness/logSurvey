 static void
 memBufStats(StoreEntry * sentry)
 {
-    storeAppendPrintf(sentry, "Large buffers: %d (%d KB)\n",
-                      HugeBufCountMeter.level,
-                      HugeBufVolumeMeter.level / 1024);
+    storeAppendPrintf(sentry, "Large buffers: %ld (%ld KB)\n",
+                      (long int) HugeBufCountMeter.level,
+                      (long int) HugeBufVolumeMeter.level / 1024);
 }
 
 void
