 
     data = xcalloc(1, sizeof(squid_read_data_t));
     data->sentry = sentry;
-    data->fd = file_open(ConfigFile, NULL, O_RDONLY);
+    data->fd = file_open(ConfigFile, NULL, O_RDONLY, NULL, NULL);
     storeAppendPrintf(sentry, open_bracket);
     file_walk(data->fd, (FILE_WALK_HD) squidReadEndHandler, (void *) data,
 	(FILE_WALK_LHD) squidReadHandler, (void *) data);
