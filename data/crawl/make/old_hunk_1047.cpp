  /* If we are controlling multiple jobs make sure we have a token before
     starting the child. */

  else if (job_fds[0] >= 0)
    if (children == 0)
    {
      char token = '-';

      while (token == '-')
        /* If we don't already have a job started, use our "free" token.  */
        if (children == 0)
          token = '+';

        /* Read a token.  As long as there's no token available we'll block.
           If we get a SIGCHLD we'll return with EINTR.  If one happened
           before we got here we'll return immediately with EBADF because
           the signal handler closes the dup'd file descriptor.  */

        else if (read (job_rfd, &c->job_token, 1) < 1)
          {
            if (errno != EINTR && errno != EBADF)
              pfatal_with_name (_("read jobs pipe"));

            /* Re-dup the read side of the pipe, so the signal handler can
               notify us if we miss a child.  */
            if (job_rfd < 0)
              job_rfd = dup (job_fds[0]);

            /* Something's done.  We don't want to block for a whole child,
               just reap whatever's there.  */
            reap_children (0, 0);
          }

      assert (c->job_token != '-');
      if (debug_flag)
        printf (_("Obtained token for child 0x%08lx (%s).\n"),
                (unsigned long int) c, c->file->name);
    }
#endif

  /* The job is now primed.  Start it running.
