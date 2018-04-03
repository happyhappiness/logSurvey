   struct timeval tmout;
   int result;
 
+  if (fd >= FD_SETSIZE)
+    {
+      logprintf (LOG_NOTQUIET, _("Too many fds open.  Cannot use select on a fd >= %d\n"), FD_SETSIZE);
+      exit (WGET_EXIT_GENERIC_ERROR);
+    }
   FD_ZERO (&fdset);
   FD_SET (fd, &fdset);
   if (wait_for & WAIT_FOR_READ)
