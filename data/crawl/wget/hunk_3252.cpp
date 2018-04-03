        logprintf.  */
     int save_errno = errno;
     if (sock >= 0)
-      CLOSE (sock);
+      xclose (sock);
     if (print)
       logprintf (LOG_VERBOSE, "failed: %s.\n", strerror (errno));
     errno = save_errno;
