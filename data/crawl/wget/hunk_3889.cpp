   FREE_MAYBE (proxyauth);
 
   /* Send the request to server.  */
+#ifdef HAVE_SSL
+  if (u->proto==URLHTTPS) {
+  num_written = ssl_iwrite (ssl, request, strlen (request));
+  } else {
+#endif /* HAVE_SSL */
   num_written = iwrite (sock, request, strlen (request));
+#ifdef HAVE_SSL
+  }
+#endif /* HAVE_SSL */
   if (num_written < 0)
     {
       logprintf (LOG_VERBOSE, _("Failed writing HTTP request: %s.\n"),
 		 strerror (errno));
-      CLOSE_INVALIDATE (sock);
+#ifndef HAVE_SSL
+		CLOSE_INVALIDATE (sock);
+#else
+		CLOSE_INVALIDATE (sock,ssl);
+#endif /* HAVE_SSL */
       return WRITEFAILED;
     }
   logprintf (LOG_VERBOSE, _("%s request sent, awaiting response... "),
