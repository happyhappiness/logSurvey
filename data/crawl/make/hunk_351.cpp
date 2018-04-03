       int dontcare;
 
       if (err && block)
-	{
+        {
           static int printed = 0;
 
-	  /* We might block for a while, so let the user know why.
+          /* We might block for a while, so let the user know why.
              Only print this message once no matter how many jobs are left.  */
-	  fflush (stdout);
+          fflush (stdout);
           if (!printed)
             error (NILF, _("*** Waiting for unfinished jobs...."));
           printed = 1;
-	}
+        }
 
       /* We have one less dead child to reap.  As noted in
-	 child_handler() above, this count is completely unimportant for
-	 all modern, POSIX-y systems that support wait3() or waitpid().
-	 The rest of this comment below applies only to early, broken
-	 pre-POSIX systems.  We keep the count only because... it's there...
-
-	 The test and decrement are not atomic; if it is compiled into:
-		register = dead_children - 1;
-		dead_children = register;
-	 a SIGCHLD could come between the two instructions.
-	 child_handler increments dead_children.
-	 The second instruction here would lose that increment.  But the
-	 only effect of dead_children being wrong is that we might wait
-	 longer than necessary to reap a child, and lose some parallelism;
-	 and we might print the "Waiting for unfinished jobs" message above
-	 when not necessary.  */
+         child_handler() above, this count is completely unimportant for
+         all modern, POSIX-y systems that support wait3() or waitpid().
+         The rest of this comment below applies only to early, broken
+         pre-POSIX systems.  We keep the count only because... it's there...
+
+         The test and decrement are not atomic; if it is compiled into:
+                register = dead_children - 1;
+                dead_children = register;
+         a SIGCHLD could come between the two instructions.
+         child_handler increments dead_children.
+         The second instruction here would lose that increment.  But the
+         only effect of dead_children being wrong is that we might wait
+         longer than necessary to reap a child, and lose some parallelism;
+         and we might print the "Waiting for unfinished jobs" message above
+         when not necessary.  */
 
       if (dead_children > 0)
-	--dead_children;
+        --dead_children;
 
       any_remote = 0;
       any_local = shell_function_pid != 0;
       for (c = children; c != 0; c = c->next)
-	{
-	  any_remote |= c->remote;
-	  any_local |= ! c->remote;
-	  DB (DB_JOBS, (_("Live child %p (%s) PID %s %s\n"),
+        {
+          any_remote |= c->remote;
+          any_local |= ! c->remote;
+          DB (DB_JOBS, (_("Live child %p (%s) PID %s %s\n"),
                         c, c->file->name, pid2str (c->pid),
                         c->remote ? _(" (remote)") : ""));
 #ifdef VMS
-	  break;
+          break;
 #endif
-	}
+        }
 
       /* First, check for remote children.  */
       if (any_remote)
-	pid = remote_status (&exit_code, &exit_sig, &coredump, 0);
+        pid = remote_status (&exit_code, &exit_sig, &coredump, 0);
       else
-	pid = 0;
+        pid = 0;
 
       if (pid > 0)
-	/* We got a remote child.  */
-	remote = 1;
+        /* We got a remote child.  */
+        remote = 1;
       else if (pid < 0)
-	{
+        {
           /* A remote status command failed miserably.  Punt.  */
-	remote_status_lose:
-	  pfatal_with_name ("remote_status");
-	}
+        remote_status_lose:
+          pfatal_with_name ("remote_status");
+        }
       else
-	{
-	  /* No remote children.  Check for local children.  */
+        {
+          /* No remote children.  Check for local children.  */
 #if !defined(__MSDOS__) && !defined(_AMIGA) && !defined(WINDOWS32)
-	  if (any_local)
-	    {
+          if (any_local)
+            {
 #ifdef VMS
-	      vmsWaitForChildren (&status);
-	      pid = c->pid;
+              vmsWaitForChildren (&status);
+              pid = c->pid;
 #else
 #ifdef WAIT_NOHANG
-	      if (!block)
-		pid = WAIT_NOHANG (&status);
-	      else
+              if (!block)
+                pid = WAIT_NOHANG (&status);
+              else
 #endif
-		EINTRLOOP(pid, wait (&status));
+                EINTRLOOP(pid, wait (&status));
 #endif /* !VMS */
-	    }
-	  else
-	    pid = 0;
+            }
+          else
+            pid = 0;
 
-	  if (pid < 0)
-	    {
+          if (pid < 0)
+            {
               /* The wait*() failed miserably.  Punt.  */
-	      pfatal_with_name ("wait");
-	    }
-	  else if (pid > 0)
-	    {
-	      /* We got a child exit; chop the status word up.  */
-	      exit_code = WEXITSTATUS (status);
-	      exit_sig = WIFSIGNALED (status) ? WTERMSIG (status) : 0;
-	      coredump = WCOREDUMP (status);
+              pfatal_with_name ("wait");
+            }
+          else if (pid > 0)
+            {
+              /* We got a child exit; chop the status word up.  */
+              exit_code = WEXITSTATUS (status);
+              exit_sig = WIFSIGNALED (status) ? WTERMSIG (status) : 0;
+              coredump = WCOREDUMP (status);
 
               /* If we have started jobs in this second, remove one.  */
               if (job_counter)
                 --job_counter;
-	    }
-	  else
-	    {
-	      /* No local children are dead.  */
+            }
+          else
+            {
+              /* No local children are dead.  */
               reap_more = 0;
 
-	      if (!block || !any_remote)
+              if (!block || !any_remote)
                 break;
 
               /* Now try a blocking wait for a remote child.  */
