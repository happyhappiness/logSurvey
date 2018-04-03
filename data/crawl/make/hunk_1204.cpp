 
 #ifdef MAKE_JOBSERVER
   /* If extended jobs are available then the -j option can have one of 4
-     formats: (1) not specified: default is "1"; (2) specified with no
-     value: default is "0" (infinite); (3) specified with a single
-     value: this means the user wants N job slots; or (4) specified with
-     2 values separated by commas.  The latter means we're a submake and
-     the two values are the read and write FDs, respectively, for the
-     pipe.  Note this last form is undocumented for the user!
-   */
+     formats: (1) not specified: default is "1"; (2) specified with no value:
+     default is "0" (infinite); (3) specified with a single value: this means
+     the user wants N job slots; or (4) specified with 2 values separated by
+     a comma.  The latter means we're a submake; the two values are the read
+     and write FDs, respectively, for the pipe.  Note this last form is
+     undocumented for the user!  */
+
   sscanf(job_slots_str, "%d", &job_slots);
   {
     char *cp = index(job_slots_str, ',');
 
+    /* In case #4, get the FDs.  */
     if (cp && sscanf(cp+1, "%d", &job_fds[1]) == 1)
       {
-	job_fds[0] = job_slots;
-	job_slots = 0;
+        /* Set up the first FD and set job_slots to 0.  The combination of a
+           pipe + !job_slots means we're using the jobserver.  If !job_slots
+           and we don't have a pipe, we can start infinite jobs.  */
+        job_fds[0] = job_slots;
+        job_slots = 0;
+
+        /* Make sure the pipe is open!  The parent might have closed it
+           because it didn't think we were a submake.  If so, print a warning
+           then default to -j1.  */
+        if (fcntl (job_fds[0], F_GETFL, 0) < 0
+            || fcntl (job_fds[1], F_GETFL, 0) < 0)
+          {
+            error (NILF,
+                   "warning: jobserver unavailable (using -j1).  Add `+' to parent make rule.");
+            job_slots = 1;
+            job_fds[0] = job_fds[1] = -1;
+            job_slots_str = "1";
+          }
       }
   }
 
