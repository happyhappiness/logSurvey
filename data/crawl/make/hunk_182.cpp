         if (got_token < 0)
           {
             DWORD err = GetLastError ();
-            fatal (NILF, _("semaphore or child process wait: (Error %ld: %s)"),
-                   err, map_windows32_error_to_string (err));
+            const char *estr = map_windows32_error_to_string (err);
+            OSN (fatal, NILF,
+                 _("semaphore or child process wait: (Error %ld: %s)"),
+                 err, estr);
           }
 #else
         /* Set interruptible system calls, and read() for a job token.  */
