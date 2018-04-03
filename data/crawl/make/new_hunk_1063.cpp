  /* Fetch the first command line to be run.  */
  job_next_command (c);

  /* Wait for a job slot to be freed up.  If we allow an infinite number
     don't bother; also job_slots will == 0 if we're using the jobserver.  */
  if (job_slots != 0)
    while (job_slots_used == job_slots)
      reap_children (1, 0);
#ifdef MAKE_JOBSERVER
  /* If we are controlling multiple jobs, and we don't yet have one,
     obtain a token before starting the child. */
  else if (job_fds[0] >= 0)
    {
      while (c->job_token == '-')
        /* If the reserved token is available, just use that.  */
        if (my_job_token == '+')
          {
            c->job_token = my_job_token;
            my_job_token = '-';
          }
        /* Read a token.  As long as there's no token available we'll block.
           If we get a SIGCHLD we'll return with EINTR.  If one happened
           before we got here we'll return with EBADF.  */
        else if (read (job_rfd, &c->job_token, 1) < 1)
          {
            if (errno == EINTR)
              ;

            /* If EBADF, we got a SIGCHLD before.  Otherwise, who knows?  */
            else if (errno != EBADF)
              pfatal_with_name (_("read jobs pipe"));

            /* Something's done; reap it.  We don't force a block here; if
               something strange happened and nothing's ready, just come back
               and wait some more.  */
            reap_children (0, 0);
          }

      assert(c->job_token != '-');
      if (debug_flag)
        printf (_("Obtained token `%c' for child 0x%08lx (%s).\n"),
                c->job_token, (unsigned long int) c, c->file->name);
    }
#endif

  /* The job is now primed.  Start it running.
     (This will notice if there are in fact no commands.)  */
  (void)start_waiting_job (c);
