        /* Reap anything that's currently waiting.  */
        reap_children (0, 0);

        /* Kick off any jobs we have waiting for an opportunity that
           can run now (ie waiting for load). */
        start_waiting_jobs ();

        /* If our "free" slot has become available, use it; we don't need an
           actual token.  */
        if (!jobserver_tokens)
          break;

        /* There must be at least one child already, or we have no business
           waiting for a token. */
        if (!children)
          fatal (NILF, "INTERNAL: no children as we go to sleep on read\n");

        /* Set interruptible system calls, and read() for a job token.  */
	set_child_handler_action_flags (0);
	got_token = read (job_rfd, &token, 1);
