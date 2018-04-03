       char *cp;
       char c = '+';
 
+#ifdef WINDOWS32
+      /* sub_proc.c cannot wait for more than MAXIMUM_WAIT_OBJECTS objects
+       * and one of them is the job-server semaphore object.  Limit the 
+       * number of available job slots to (MAXIMUM_WAIT_OBJECTS - 1). */
+
+      if (job_slots >= MAXIMUM_WAIT_OBJECTS)
+        {
+          job_slots = MAXIMUM_WAIT_OBJECTS - 1;
+          DB (DB_JOBS, (_("Jobserver slots limited to %d\n"), job_slots));
+        }
+
+      if (! create_jobserver_semaphore(job_slots - 1))
+        {
+          DWORD err = GetLastError();
+          fatal (NILF,_("creating jobserver semaphore: (Error %d: %s)"),
+                 err, map_windows32_error_to_string(err));
+        }
+#else
       if (pipe (job_fds) < 0 || (job_rfd = dup (job_fds[0])) < 0)
 	pfatal_with_name (_("creating jobs pipe"));
+#endif
 
       /* Every make assumes that it always has one job it can run.  For the
          submakes it's the token they were given by their parent.  For the
