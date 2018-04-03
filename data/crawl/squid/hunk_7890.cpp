     if (CacheInfo->logfile_fd == DISK_ERROR) {
 	debug(18, 0, "rotate_logs: Cannot open logfile: %s\n", fname);
 	CacheInfo->logfile_status = LOG_DISABLE;
-	fatal("Cannot open logfile.\n");
+	fatal("Cannot open logfile.");
     }
     CacheInfo->logfile_access = file_write_lock(CacheInfo->logfile_fd);
 }
