 {
     squid_read_data_t *data;
 
-    data = (squid_read_data_t *) xmalloc(sizeof(squid_read_data_t));
-    memset(data, '\0', sizeof(squid_read_data_t));
+    data = xcalloc(1, sizeof(squid_read_data_t));
     data->sentry = sentry;
     data->fd = file_open((char *) ConfigFile, NULL, O_RDONLY);
-    storeAppendPrintf(sentry, "{\n");
+    storeAppendPrintf(sentry, open_bracket);
     file_walk(data->fd, (FILE_WALK_HD) squidReadEndHandler, (void *) data,
 	(FILE_WALK_LHD) squidReadHandler, (void *) data);
 }
