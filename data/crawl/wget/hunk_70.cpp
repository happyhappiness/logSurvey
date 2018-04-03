       if (bufsize < 512)
         bufsize = 512;          /* avoid pathologically small values */
 #ifdef SO_RCVBUF
-      setsockopt (sock, SOL_SOCKET, SO_RCVBUF,
-                  (void *)&bufsize, (socklen_t)sizeof (bufsize));
+      if (setsockopt (sock, SOL_SOCKET, SO_RCVBUF,
+                  (void *) &bufsize, (socklen_t) sizeof (bufsize)))
+        logprintf (LOG_NOTQUIET, _("setsockopt SO_RCVBUF failed: %s\n"),
+                   strerror (errno));
 #endif
       /* When we add limit_rate support for writing, which is useful
          for POST, we should also set SO_SNDBUF here.  */
