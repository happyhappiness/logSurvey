     null_initialised = 0;
 }
 
-static void
-storeNullDirStats(SwapDir * SD, StoreEntry * sentry)
+static SwapDir *
+storeNullNew(void)
 {
-    (void) 0;
+    SwapDir *result = new NullSwapDir;
+    return result;
 }
 
-static void
-storeNullDirInit(SwapDir * sd)
+void
+NullSwapDir::init()
 {
     store_dirs_rebuilding++;
     eventAdd("storeNullDirRebuildComplete", storeNullDirRebuildComplete,
 	NULL, 0.0, 1);
 }
 
+StoreIOState::Pointer
+NullSwapDir::createStoreIO(StoreEntry &, STFNCB *, STIOCB *, void *)
+{
+    fatal ("Attempt to get a StoreIO from the NULL store!\n");
+    return NULL;
+}
+
+StoreIOState::Pointer
+NullSwapDir::openStoreIO(StoreEntry &, STFNCB *, STIOCB *, void *)
+{
+    fatal ("Attempt to get a StoreIO from the NULL store!\n");
+    return NULL;
+}
+
 static void
 storeNullDirRebuildComplete(void *unused)
 {
