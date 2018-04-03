   starting_directory = current_directory;
 
 #ifdef MAKE_JOBSERVER
-  /* If the jobserver-fds option is seen, make sure that -j is reasonable.
+  /* If the jobserver_fds option is seen, make sure that -j is reasonable.
      This can't be usefully set in the makefile, and we want to verify the
      FDs are valid before any other aspect of make has a chance to start
      using them for something else.  */
 
   if (jobserver_fds)
     {
-      /* Make sure the jobserver option has the proper format.  */
-      const char *cp = jobserver_fds;
-
-#ifdef WINDOWS32
-      if (! open_jobserver_semaphore (cp))
-        {
-          DWORD err = GetLastError ();
-          const char *estr = map_windows32_error_to_string (err);
-          fatal (NILF, strlen (cp) + INTSTR_LENGTH + strlen (estr),
-                 _("internal error: unable to open jobserver semaphore '%s': (Error %ld: %s)"),
-                 cp, err, estr);
-        }
-      DB (DB_JOBS, (_("Jobserver client (semaphore %s)\n"), cp));
-#else
-      if (sscanf (cp, "%d,%d", &job_fds[0], &job_fds[1]) != 2)
-        OS (fatal, NILF,
-            _("internal error: invalid --jobserver-fds string '%s'"), cp);
-
-      DB (DB_JOBS,
-          (_("Jobserver client (fds %d,%d)\n"), job_fds[0], job_fds[1]));
-#endif
-
-      /* The combination of a pipe + !job_slots means we're using the
-         jobserver.  If !job_slots and we don't have a pipe, we can start
-         infinite jobs.  If we see both a pipe and job_slots >0 that means the
+      /* The combination of jobserver_fds and !job_slots means we're using the
+         jobserver.  If !job_slots and no jobserver_fds, we can start infinite
+         jobs.  If we see both jobserver_fds and job_slots >0 that means the
          user set -j explicitly.  This is broken; in this case obey the user
-         (ignore the jobserver pipe for this make) but print a message.
-         If we've restarted, we already printed this the first time.  */
+         (ignore the jobserver for this make) but print a message.  If we've
+         restarted, we already printed this the first time.  */
 
-      if (job_slots > 0)
-        {
-          if (! restarts)
-            O (error, NILF,
-               _("warning: -jN forced in submake: disabling jobserver mode."));
-        }
-#ifndef WINDOWS32
-#ifdef HAVE_FCNTL
-# define FD_OK(_f) ((fcntl ((_f), F_GETFD) != -1) || (errno != EBADF))
-#else
-# define FD_OK(_f) 1
-#endif
-      /* Create a duplicate pipe, that will be closed in the SIGCHLD
-         handler.  If this fails with EBADF, the parent has closed the pipe
-         on us because it didn't think we were a submake.  If so, print a
-         warning then default to -j1.  */
-      else if (!FD_OK (job_fds[0]) || !FD_OK (job_fds[1])
-               || (job_rfd = dup (job_fds[0])) < 0)
-        {
-          if (errno != EBADF)
-            pfatal_with_name (_("dup jobserver"));
+      if (!job_slots)
+        jobserver_parse_arg (jobserver_fds);
 
-          O (error, NILF,
-             _("warning: jobserver unavailable: using -j1.  Add '+' to parent make rule."));
-          job_slots = 1;
-          job_fds[0] = job_fds[1] = -1;
-        }
-#endif
+      else if (! restarts)
+        O (error, NILF,
+           _("warning: -jN forced in submake: disabling jobserver mode."));
 
       if (job_slots > 0)
         {
-#ifdef WINDOWS32
-          free_jobserver_semaphore ();
-#else
-          if (job_fds[0] >= 0)
-            close (job_fds[0]);
-          if (job_fds[1] >= 0)
-            close (job_fds[1]);
-#endif
-          job_fds[0] = job_fds[1] = -1;
-
+          /* If job_slots is set now then we're not using jobserver */
+          jobserver_clear ();
           free (jobserver_fds);
-          jobserver_fds = 0;
+          jobserver_fds = NULL;
         }
     }
 #endif
