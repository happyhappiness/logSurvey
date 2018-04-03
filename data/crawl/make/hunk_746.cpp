           fatal (NILF, "INTERNAL: no children as we go to sleep on read\n");
 
         /* Set interruptible system calls, and read() for a job token.  */
-	set_child_handler_action_flags (0);
+	set_child_handler_action_flags (1, waiting_jobs != NULL);
 	got_token = read (job_rfd, &token, 1);
 	saved_errno = errno;
-#ifdef __EMX__
-        /* The child handler must be turned off here.  */
-        signal (SIGCHLD, SIG_DFL);
-#endif
-	set_child_handler_action_flags (SA_RESTART);
+	set_child_handler_action_flags (0, waiting_jobs != NULL);
 
         /* If we got one, we're done here.  */
 	if (got_token == 1)
