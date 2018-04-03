 
 
 /* generate logfile status information */
-static void
-log_status_get(const cacheinfo * obj, StoreEntry * sentry)
+void
+log_status_get(StoreEntry * sentry)
 {
-    if (obj->logfile_status == LOG_ENABLE) {
+    if (LogfileStatus == LOG_ENABLE) {
 	storeAppendPrintf(sentry, "{\"Logfile is Enabled. Filename: %s\"}\n",
-	    obj->logfilename);
+	    LogfileName);
     } else {
 	storeAppendPrintf(sentry, "{\"Logfile is Disabled.\"}\n");
     }
