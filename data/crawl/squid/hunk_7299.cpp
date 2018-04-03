 
 /* squid convert handler */
 /* call for each line in file, use fileWalk routine */
-static int
-squidReadHandler(int fd_unused, const char *buf, int size_unused, squid_read_data_t * data)
+static void
+squidReadHandler(int fd_unused, const char *buf, int size_unused, void *data)
 {
-    storeAppendPrintf(data->sentry, "{\"%s\"}\n", buf);
-    return 0;
+    squid_read_data_t *ctrl = data;
+    storeAppendPrintf(ctrl->sentry, "{\"%s\"}\n", buf);
 }
 
 /* squid convert end handler */
 /* call when a walk is completed or error. */
 static void
-squidReadEndHandler(int fd_unused, int errflag_unused, squid_read_data_t * data)
+squidReadEndHandler(int fd_unused, int errflag_unused, void *data)
 {
-    storeAppendPrintf(data->sentry, close_bracket);
-    storeComplete(data->sentry);
-    file_close(data->fd);
-    safe_free(data);
+    squid_read_data_t *ctrl = data;
+    storeAppendPrintf(ctrl->sentry, close_bracket);
+    storeComplete(ctrl->sentry);
+    file_close(ctrl->fd);
+    safe_free(ctrl);
 }
 
 
