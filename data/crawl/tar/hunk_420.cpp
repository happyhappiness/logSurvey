 
   if (child_pid)
     {
-      WAIT_T wait_status;
-      pid_t child;
-
-      /* Loop waiting for the right child to die, or for no more kids.  */
+      int wait_status;
 
-      while ((child = wait (&wait_status), child != child_pid)
-	     && child != -1)
-	continue;
+      while (waitpid (child_pid, &wait_status, 0) == -1)
+	if (errno != EINTR)
+	  {
+	    ERROR ((0, errno, _("While waiting for child")));
+	    break;
+	  }
 
-      if (child != -1)
+      if (WIFSIGNALED (wait_status))
 	{
-	  if (WIFSIGNALED (wait_status)
-#if 0
-	      && !WIFSTOPPED (wait_status)
-#endif
-	      )
-	    {
-	      /* SIGPIPE is OK, everything else is a problem.  */
-
-	      if (WTERMSIG (wait_status) != SIGPIPE)
-		ERROR ((0, 0, _("Child died with signal %d%s"),
-			WTERMSIG (wait_status),
-			WCOREDUMP (wait_status) ? _(" (core dumped)") : ""));
-	    }
-	  else
-	    {
-	      /* Child voluntarily terminated -- but why?  /bin/sh returns
-		 SIGPIPE + 128 if its child, then do nothing.  */
-
-	      if (WEXITSTATUS (wait_status) != (SIGPIPE + 128)
-		  && WEXITSTATUS (wait_status))
-		ERROR ((0, 0, _("Child returned status %d"),
-			WEXITSTATUS (wait_status)));
-	    }
+	  /* SIGPIPE is OK, everything else is a problem.  */
+	  
+	  if (WTERMSIG (wait_status) != SIGPIPE)
+	    ERROR ((0, 0, _("Child died with signal %d"),
+		    WTERMSIG (wait_status)));
+	}
+      else
+	{
+	  /* Child voluntarily terminated -- but why?  /bin/sh returns
+	     SIGPIPE + 128 if its child, then do nothing.  */
+	      
+	  if (WEXITSTATUS (wait_status)
+	      && WEXITSTATUS (wait_status) != (SIGPIPE + 128))
+	    ERROR ((0, 0, _("Child returned status %d"),
+		    WEXITSTATUS (wait_status)));
 	}
     }
 #endif /* !MSDOS */
