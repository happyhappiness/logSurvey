        if (!children)
          fatal (NILF, "INTERNAL: no children as we go to sleep on read\n");

        /* Set interruptible system calls, and read() for a job token.  */
	set_child_handler_action_flags (1, waiting_jobs != NULL);
	got_token = read (job_rfd, &token, 1);
	saved_errno = errno;
	set_child_handler_action_flags (0, waiting_jobs != NULL);

        /* If we got one, we're done here.  */
	if (got_token == 1)
