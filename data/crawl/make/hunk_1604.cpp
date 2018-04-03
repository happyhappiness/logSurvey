       register struct child *lastc, *c;
       int child_failed;
 
+      if (err && !child_died)
+	{
+	  fflush (stdout);
+	  error ("*** Waiting for unfinished jobs....");
+	}
+
+      child_died = 0;
+
       /* First, check for remote children.  */
       pid = remote_status (&exit_code, &exit_sig, &coredump, 0);
       if (pid < 0)
