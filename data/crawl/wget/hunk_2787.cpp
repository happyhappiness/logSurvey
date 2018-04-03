   return res;
 }
 
+/* Report the most recent error(s) on FD.  This should only be called
+   after fd_* functions, such as fd_read and fd_write, and only if
+   they return a negative result.  For errors coming from other calls
+   such as setsockopt or fopen, strerror should continue to be
+   used.
+
+   If the transport doesn't support error messages or doesn't supply
+   one, strerror(errno) is returned.  */
+
+const char *
+fd_errstr (int fd)
+{
+  /* Don't bother with LAZY_RETRIEVE_INFO, as this will only be called
+     in case of error, never in a tight loop.  */
+  struct transport_info *info = NULL;
+  if (transport_map)
+    info = hash_table_get (transport_map, (void *) fd);
+
+  if (info && info->imp->errstr)
+    {
+      const char *err = info->imp->errstr (fd, info->ctx);
+      if (err)
+	return err;
+      /* else, fall through and print the system error. */
+    }
+  return strerror (errno);
+}
+
 /* Close the file descriptor FD.  */
 
 void
