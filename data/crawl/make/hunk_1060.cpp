         job_fds[0] = job_slots;
         job_slots = 0;
 
-        /* Make sure the pipe is open!  The parent might have closed it
-           because it didn't think we were a submake.  If so, print a warning
-           then default to -j1.  */
-        if (fcntl (job_fds[0], F_GETFL, 0) < 0
-            || fcntl (job_fds[1], F_GETFL, 0) < 0)
+        /* Create a duplicate pipe, that will be closed in the SIGCHLD
+           handler.  If this fails with EBADF, the parent has closed the pipe
+           on us because it didn't think we were a submake.  If so, print a
+           warning then default to -j1.  */
+        if ((job_rfd = dup (job_fds[0])) < 0)
           {
+            if (errno != EBADF)
+              pfatal_with_name (_("dup jobserver"));
+
             error (NILF,
                    _("warning: jobserver unavailable (using -j1).  Add `+' to parent make rule."));
             job_slots = 1;
