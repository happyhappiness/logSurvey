 	continue;
 
       if (child != -1)
-	if (WIFSIGNALED (wait_status)
+	{
+	  if (WIFSIGNALED (wait_status)
 #if 0
-	    && !WIFSTOPPED (wait_status)
+	      && !WIFSTOPPED (wait_status)
 #endif
-	    )
-	  {
-	    /* SIGPIPE is OK, everything else is a problem.  */
+	      )
+	    {
+	      /* SIGPIPE is OK, everything else is a problem.  */
 
-	    if (WTERMSIG (wait_status) != SIGPIPE)
-	      ERROR ((0, 0, _("Child died with signal %d%s"),
-		      WTERMSIG (wait_status),
-		      WCOREDUMP (wait_status) ? _(" (core dumped)") : ""));
-	  }
-	else
-	  {
-	    /* Child voluntarily terminated -- but why?  /bin/sh returns
-	       SIGPIPE + 128 if its child, then do nothing.  */
+	      if (WTERMSIG (wait_status) != SIGPIPE)
+		ERROR ((0, 0, _("Child died with signal %d%s"),
+			WTERMSIG (wait_status),
+			WCOREDUMP (wait_status) ? _(" (core dumped)") : ""));
+	    }
+	  else
+	    {
+	      /* Child voluntarily terminated -- but why?  /bin/sh returns
+		 SIGPIPE + 128 if its child, then do nothing.  */
 
-	    if (WEXITSTATUS (wait_status) != (SIGPIPE + 128)
-		&& WEXITSTATUS (wait_status))
-	      ERROR ((0, 0, _("Child returned status %d"),
-		      WEXITSTATUS (wait_status)));
-	  }
+	      if (WEXITSTATUS (wait_status) != (SIGPIPE + 128)
+		  && WEXITSTATUS (wait_status))
+		ERROR ((0, 0, _("Child returned status %d"),
+			WEXITSTATUS (wait_status)));
+	    }
+	}
     }
 #endif /* !MSDOS */
 
