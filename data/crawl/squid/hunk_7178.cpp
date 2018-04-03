 	debug(18, 1) ("log_append: File write failed.\n");
 }
 
-static void
-log_enable(cacheinfo * obj, StoreEntry * sentry)
+void
+log_enable(StoreEntry * sentry)
 {
-    if (obj->logfile_status == LOG_DISABLE) {
-	obj->logfile_status = LOG_ENABLE;
-
+    if (LogfileStatus == LOG_DISABLE) {
+	LogfileStatus = LOG_ENABLE;
 	/* open the logfile */
-	obj->logfile_fd = file_open(obj->logfilename, O_WRONLY | O_CREAT, NULL, NULL);
-	if (obj->logfile_fd == DISK_ERROR) {
-	    debug(18, 0) ("Cannot open logfile: %s\n", obj->logfilename);
-	    obj->logfile_status = LOG_DISABLE;
+	LogfileFD = file_open(LogfileName, O_WRONLY | O_CREAT, NULL, NULL);
+	if (LogfileFD == DISK_ERROR) {
+	    debug(18, 0) ("Cannot open logfile: %s\n", LogfileName);
+	    LogfileStatus = LOG_DISABLE;
 	}
     }
-    /* at the moment, store one char to make a storage manager happy */
-    storeAppendPrintf(sentry, " ");
 }
 
-static void
-log_disable(cacheinfo * obj, StoreEntry * sentry)
+void
+log_disable(StoreEntry * sentry)
 {
-    if (obj->logfile_status == LOG_ENABLE)
-	file_close(obj->logfile_fd);
-
-    obj->logfile_status = LOG_DISABLE;
-    /* at the moment, store one char to make a storage manager happy */
-    storeAppendPrintf(sentry, " ");
+    if (LogfileStatus == LOG_ENABLE)
+	file_close(LogfileFD);
+    LogfileStatus = LOG_DISABLE;
 }
 
-
-
-static void
-log_clear(cacheinfo * obj, StoreEntry * sentry)
+void
+log_clear(StoreEntry * sentry)
 {
     /* what should be done here. Erase file ??? or move it to another name?  At the moment, just erase it.  bug here need to be fixed. what if there are still data in memory. Need flush here */
-    if (obj->logfile_status == LOG_ENABLE)
-	file_close(obj->logfile_fd);
-
-    unlink(obj->logfilename);
-
+    if (LogfileStatus == LOG_ENABLE)
+	file_close(LogfileFD);
+    unlink(LogfileName);
     /* reopen it anyway */
-    obj->logfile_fd = file_open(obj->logfilename, O_WRONLY | O_CREAT, NULL, NULL);
-    if (obj->logfile_fd == DISK_ERROR) {
-	debug(18, 0) ("Cannot open logfile: %s\n", obj->logfilename);
-	obj->logfile_status = LOG_DISABLE;
+    LogfileFD = file_open(LogfileName, O_WRONLY | O_CREAT, NULL, NULL);
+    if (LogfileFD == DISK_ERROR) {
+	debug(18, 0) ("Cannot open logfile: %s\n", LogfileName);
+	LogfileStatus = LOG_DISABLE;
     }
     /* at the moment, store one char to make a storage manager happy */
     storeAppendPrintf(sentry, " ");
