                      number_to_static_string (expected_bytes));
     }
 
+  if (cmd & DO_RETR && restval > 0 && restval == expected_bytes)
+    {
+      /* Server confirms that file has length restval. We should stop now.
+         Some servers (f.e. NcFTPd) return error when receive REST 0 */
+      logputs (LOG_VERBOSE, _("File has already been retrieved.\n"));
+      fd_close (csock);
+      con->csock = -1;
+      return RETRFINISHED;
+    }
+
   /* If anything is to be retrieved, PORT (or PASV) must be sent.  */
   if (cmd & (DO_LIST | DO_RETR))
     {
