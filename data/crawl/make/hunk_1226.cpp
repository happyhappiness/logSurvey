 start_waiting_job (c)
      struct child *c;
 {
+  struct file *f = c->file;
+
   /* If we can start a job remotely, we always want to, and don't care about
      the local load average.  We record that the job should be started
      remotely in C->remote for start_job_command to test.  */
 
   c->remote = start_remote_job_p (1);
 
-  /* If this job is to be started locally, and we are already running
-     some jobs, make this one wait if the load average is too high.  */
-  if (!c->remote && job_slots_used > 0 && load_too_high ())
+  /* If not, start it locally.  */
+  if (!c->remote)
     {
-      /* Put this child on the chain of children waiting
-	 for the load average to go down.  */
-      set_command_state (c->file, cs_running);
-      c->next = waiting_jobs;
-      waiting_jobs = c;
-      return 0;
+#ifdef MAKE_JOBSERVER
+      /* If this is not a recurse command and we are controlling
+	 multiple jobs, obtain a token before starting child. */
+      if (job_fds[0] >= 0 && !f->cmds->any_recurse)
+	{
+	  fd_set rfds;
+
+	  FD_ZERO(&rfds);
+	  FD_SET(job_fds[0], &rfds);
+
+	  /* Read a token.  We set the non-blocking bit on this earlier,
+	     so if there's no token to be read we'll fall through to the
+	     select.  The select block until (a) there's data to read,
+	     in which case we come back around and try to grab the token
+	     before someone else does, or (b) a signal, such as SIGCHLD,
+	     is caught (because we installed a handler for it).  If the
+	     latter, call reap_children() to try to free up some slots.  */
+
+	  while (read (job_fds[0], &c->job_token, 1) < 1)
+	    {
+	      int r = select (job_fds[0]+1, SELECT_FD_SET_CAST &rfds,
+                              NULL, NULL, NULL);
+
+	      if (r < 0)
+		{
+#ifdef EINTR
+		  if (errno != EINTR)
+		    /* We should definitely handle this more gracefully!
+		       What kinds of things can happen here?  ^C closes the
+		       pipe?  Something else closes it?  */
+		    pfatal_with_name ("read jobs pipe");
+#endif
+		  /* We were interrupted; handle any dead children.  */
+		  reap_children (1, 0);
+		}
+	    }
+
+	  assert(c->job_token != 0);
+	  if (debug_flag)
+	    printf ("Obtained token `%c' for child 0x%08lx.\n",
+		    c->job_token, (unsigned long int) c);
+	}
+#endif
+      /* If we are running at least one job already and the load average
+	 is too high, make this one wait.  */
+      if (job_slots_used > 0 && load_too_high ())
+	{
+	  /* Put this child on the chain of children waiting
+	     for the load average to go down.  */
+	  set_command_state (f, cs_running);
+	  c->next = waiting_jobs;
+	  waiting_jobs = c;
+	  return 0;
+	}
     }
 
   /* Start the first command; reap_children will run later command lines.  */
   start_job_command (c);
 
-  switch (c->file->command_state)
+  switch (f->command_state)
     {
     case cs_running:
       c->next = children;
