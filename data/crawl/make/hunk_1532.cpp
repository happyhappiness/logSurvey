       if (dead_children != 0)
 	--dead_children;
 
-      if (debug_flag)
-	for (c = children; c != 0; c = c->next)
-	  printf ("Live child 0x%08lx PID %d%s\n",
-		  (unsigned long int) c,
-		  c->pid, c->remote ? " (remote)" : "");
+      any_remote = 0;
+      for (c = children; c != 0; c = c->next)
+	{
+	  any_remote |= c->remote;
+	  if (debug_flag)
+	    printf ("Live child 0x%08lx PID %d%s\n",
+		    (unsigned long int) c,
+		    c->pid, c->remote ? " (remote)" : "");
+	}
 
       /* First, check for remote children.  */
-      pid = remote_status (&exit_code, &exit_sig, &coredump, 0);
-      if (pid <= 0)
+      if (any_remote)
+	pid = remote_status (&exit_code, &exit_sig, &coredump, 0);
+      else
+	pid = 0;
+      if (pid < 0)
+	{
+	remote_status_lose:
+#ifdef	EINTR
+	  if (errno == EINTR)
+	    continue;
+#endif
+	  pfatal_with_name ("remote_status");
+	}
+      else if (pid == 0)
 	{
 	  /* No remote children.  Check for local children.  */
 
