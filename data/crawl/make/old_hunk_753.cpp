        /* Reap anything that's currently waiting.  */
        reap_children (0, 0);

        /* If our "free" token has become available, use it.  */
        if (!children)
          break;

        /* Set interruptible system calls, and read() for a job token.  */
	set_child_handler_action_flags (0);
	got_token = read (job_rfd, &token, 1);
