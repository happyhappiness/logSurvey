   /* Send the request to server.  */
 #ifdef HAVE_SSL
   if (conn->scheme == SCHEME_HTTPS)
-    num_written = ssl_iwrite (ssl, request, strlen (request));
+    write_error = ssl_iwrite (ssl, request, strlen (request));
   else
-#endif /* HAVE_SSL */
-    num_written = iwrite (sock, request, strlen (request));
+#endif
+    write_error = iwrite (sock, request, strlen (request));
+
+  if (write_error >= 0)
+    {
+      if (opt.post_data)
+	{
+	  DEBUGP (("[POST data: %s]\n", opt.post_data));
+#ifdef HAVE_SSL
+	  if (conn->scheme == SCHEME_HTTPS)
+	    write_error = ssl_iwrite (ssl, opt.post_data, post_data_size);
+	  else
+#endif
+	    write_error = iwrite (sock, opt.post_data, post_data_size);
+	}
+      else if (opt.post_file_name)
+	{
+#ifdef HAVE_SSL
+	  if (conn->scheme == SCHEME_HTTPS)
+	    write_error = post_file (-1, ssl, opt.post_file_name,
+				     post_data_size);
+	  else
+#endif
+	    write_error = post_file (sock, NULL, opt.post_file_name,
+				     post_data_size);
+	}
+    }
+  DEBUGP (("---request end---\n"));
 
-  if (num_written < 0)
+  if (write_error < 0)
     {
       logprintf (LOG_VERBOSE, _("Failed writing HTTP request: %s.\n"),
 		 strerror (errno));
