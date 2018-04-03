   return 1;
 }
 
-/* Read the body of the request, but don't store it anywhere.  This is
-   useful when reading error responses that are not logged anywhere,
-   but which need to be read so the same connection can be reused.  */
+/* Read the body of the request, but don't store it anywhere and don't
+   display a progress gauge.  This is useful for reading the error
+   responses whose bodies don't need to be displayed or logged, but
+   which need to be read anyway.  */
 
 static void
-skip_body (int fd, long contlen)
+skip_short_body (int fd, long contlen)
 {
-  int oldverbose;
-  long dummy;
-
   /* Skipping the body doesn't make sense if the content length is
      unknown because, in that case, persistent connections cannot be
      used.  (#### This is not the case with HTTP/1.1 where they can
      still be used with the magic of the "chunked" transfer!)  */
   if (contlen == -1)
     return;
+  DEBUGP (("Skipping %ld bytes of body data... ", contlen));
 
-  oldverbose = opt.verbose;
-  opt.verbose = 0;
-  fd_read_body (fd, NULL, contlen, 1, 0, &dummy, NULL);
-  opt.verbose = oldverbose;
+  while (contlen > 0)
+    {
+      char dlbuf[512];
+      int ret = fd_read (fd, dlbuf, MIN (contlen, sizeof (dlbuf)), -1);
+      if (ret <= 0)
+	return;
+      contlen -= ret;
+    }
+  DEBUGP (("done.\n"));
 }
 
 /* Persistent connections.  Currently, we cache the most recently used
