     storeAppendPrintf(sentry, " ");
 }
 
-static void log_disable(obj, sentry)
-     cacheinfo *obj;
-     StoreEntry *sentry;
+static void
+log_disable(cacheinfo * obj, StoreEntry * sentry)
 {
     if (obj->logfile_status == LOG_ENABLE)
 	file_close(obj->logfile_fd);
