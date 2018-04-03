 
     debug(18, 5) ("stat_init: Initializing...\n");
     obj = xcalloc(1, sizeof(cacheinfo));
-    obj->stat_get = stat_get;
-    obj->info_get = info_get;
-    obj->cache_size_get = cache_size_get;
-    obj->log_get_start = log_get_start;
-    obj->log_status_get = log_status_get;
-    obj->log_append = log_append;
-    obj->log_clear = log_clear;
-    obj->log_enable = log_enable;
-    obj->log_disable = log_disable;
-    obj->logfile_status = LOG_ENABLE;
-    obj->squid_get_start = squid_get_start;
-    obj->parameter_get = parameter_get;
-    obj->server_list = server_list;
     if (logfilename) {
-	memset(obj->logfilename, '\0', SQUID_MAXPATHLEN);
-	xstrncpy(obj->logfilename, logfilename, SQUID_MAXPATHLEN);
-	obj->logfile_fd = file_open(obj->logfilename, O_WRONLY | O_CREAT, NULL, NULL);
-	if (obj->logfile_fd == DISK_ERROR) {
-	    debug(50, 0) ("%s: %s\n", obj->logfilename, xstrerror());
+	memset(LogfileName, '\0', SQUID_MAXPATHLEN);
+	xstrncpy(LogfileName, logfilename, SQUID_MAXPATHLEN);
+	LogfileFD = file_open(LogfileName, O_WRONLY | O_CREAT, NULL, NULL);
+	if (LogfileFD == DISK_ERROR) {
+	    debug(50, 0) ("%s: %s\n", LogfileName, xstrerror());
 	    fatal("Cannot open logfile.");
 	}
     }
+    obj->log_append = log_append;
     obj->proto_id = urlParseProtocol;
     obj->proto_newobject = proto_newobject;
     obj->proto_purgeobject = proto_purgeobject;
     obj->proto_touchobject = proto_touchobject;
     obj->proto_count = proto_count;
-    obj->NotImplement = dummyhandler;
     for (i = PROTO_NONE; i <= PROTO_MAX; i++) {
 	switch (i) {
 	case PROTO_HTTP:
