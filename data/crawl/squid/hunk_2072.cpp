 }
 
 void
-UFSSwapDir::rebuild()
+Fs::Ufs::UFSSwapDir::rebuild()
 {
     ++StoreController::store_dirs_rebuilding;
-    eventAdd("storeRebuild", RebuildState::RebuildStep, new RebuildState(this), 0.0, 1);
+    eventAdd("storeRebuild", Fs::Ufs::RebuildState::RebuildStep, new Fs::Ufs::RebuildState(this), 0.0, 1);
 }
 
 void
-UFSSwapDir::closeTmpSwapLog()
+Fs::Ufs::UFSSwapDir::closeTmpSwapLog()
 {
     char *swaplog_path = xstrdup(logFile(NULL));
     char *new_path = xstrdup(logFile(".new"));
     int fd;
     file_close(swaplog_fd);
 
     if (xrename(new_path, swaplog_path) < 0) {
-        debugs(50, DBG_IMPORTANT, "ERROR: " << swaplog_path << ": " << xstrerror());
+        debugs(50, DBG_IMPORTANT, HERE << "ERROR: " << swaplog_path << ": " << xstrerror());
         fatalf("Failed to rename log file %s to %s.new", swaplog_path, swaplog_path);
     }
 
     fd = file_open(swaplog_path, O_WRONLY | O_CREAT | O_BINARY);
 
     if (fd < 0) {
-        debugs(50, DBG_IMPORTANT, "ERROR: " << swaplog_path << ": " << xstrerror());
+        debugs(50, DBG_IMPORTANT, HERE << "ERROR: " << swaplog_path << ": " << xstrerror());
         fatalf("Failed to open swap log %s", swaplog_path);
     }
 
     safe_free(swaplog_path);
     safe_free(new_path);
     swaplog_fd = fd;
-    debugs(47, 3, "Cache Dir #" << index << " log opened on FD " << fd);
+    debugs(47, 3, HERE << "Cache Dir #" << index << " log opened on FD " << fd);
 }
 
 FILE *
-UFSSwapDir::openTmpSwapLog(int *clean_flag, int *zero_flag)
+Fs::Ufs::UFSSwapDir::openTmpSwapLog(int *clean_flag, int *zero_flag)
 {
     char *swaplog_path = xstrdup(logFile(NULL));
     char *clean_path = xstrdup(logFile(".last-clean"));
