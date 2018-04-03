  /* If we are controlling multiple jobs make sure we have a token before
     starting the child. */

  /* This can be inefficient.  There's a decent chance that this job won't
     actually have to run any subprocesses: the command script may be empty
     or otherwise optimized away.  It would be nice if we could defer
     obtaining a token until just before we need it, in start_job_command.
     To do that we'd need to keep track of whether we'd already obtained a
     token (since start_job_command is called for each line of the job, not
     just once).  Also more thought needs to go into the entire algorithm;
     this is where the old parallel job code waits, so...  */

  else if (job_fds[0] >= 0)
    while (1)
      {
        char token;

        /* If we don't already have a job started, use our "free" token.  */
        if (!children)
          break;

        /* Read a token.  As long as there's no token available we'll block.
           If we get a SIGCHLD we'll return with EINTR.  If one happened
           before we got here we'll return immediately with EBADF because
           the signal handler closes the dup'd file descriptor.  */

        if (read (job_rfd, &token, 1) == 1)
          {
            if (debug_flag)
              printf (_("Obtained token for child 0x%08lx (%s).\n"),
                      (unsigned long int) c, c->file->name);
            break;
          }

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
#endif

  /* The job is now primed.  Start it running.
