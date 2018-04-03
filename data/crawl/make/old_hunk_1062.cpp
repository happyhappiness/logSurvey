  /* If not, start it locally.  */
  if (!c->remote)
    {
#ifdef MAKE_JOBSERVER
      /* If we are controlling multiple jobs, and we don't yet have one,
       * obtain a token before starting the child. */
      if (job_fds[0] >= 0)
        {
          while (c->job_token == '-')
            /* If the reserved token is available, just use that.  */
            if (my_job_token != '-')
              {
                c->job_token = my_job_token;
                my_job_token = '-';
              }
            /* Read a token.  We set the non-blocking bit on this earlier, so
               if there's no token to be read we'll return immediately.  */
            else if (read (job_fds[0], &c->job_token, 1) < 1)
              {
                fd_set rfds;
                int r;

                FD_ZERO(&rfds);
                FD_SET(job_fds[0], &rfds);

                /* The select blocks until (a) there's data to read, in which
                   case we come back around and try to grab the token before
                   someone else does, or (b) a signal (SIGCHLD), is reported
                   (because we installed a handler for it).  If the latter,
                   call reap_children() to try to free up some slots.  */

                r = select (job_fds[0]+1, SELECT_FD_SET_CAST &rfds,
                            NULL, NULL, NULL);

                if (r < 0)
                  {
#ifdef EINTR
                    if (errno != EINTR)
                      /* We should definitely handle this more gracefully!
                         What kinds of things can happen here?  ^C closes the
                         pipe?  Something else closes it?  */
                      pfatal_with_name (_("read jobs pipe"));
#endif
                    /* We were interrupted; handle any dead children.  */
                    reap_children (1, 0);
                  }
              }

          assert(c->job_token != '-');
	  if (debug_flag)
	    printf (_("Obtained token `%c' for child 0x%08lx (%s).\n"),
		    c->job_token, (unsigned long int) c, c->file->name);
	}
#endif
      /* If we are running at least one job already and the load average
	 is too high, make this one wait.  */
      if (job_slots_used > 0 && load_too_high ())
