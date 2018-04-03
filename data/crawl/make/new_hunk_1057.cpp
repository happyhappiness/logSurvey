#endif

#ifdef MAKE_JOBSERVER
  /* If the jobserver-fds option is seen, make sure that -j is reasonable.  */

  if (jobserver_fds)
  {
    char *cp;

    if (jobserver_fds->max > 1)
      fatal (NILF, _("internal error: multiple --jobserver-fds options."));

    if (job_slots > 0)
      fatal (NILF, _("internal error: --jobserver-fds unexpected."));

    /* Now parse the fds string and make sure it has the proper format.  */

    cp = jobserver_fds->list[0];

    if (sscanf (cp, "%d,%d", &job_fds[0], &job_fds[1]) != 2)
      fatal (NILF,
             _("internal error: invalid --jobserver-fds string `%s'."), cp);

    /* Set job_slots to 0.  The combination of a pipe + !job_slots means
       we're using the jobserver.  If !job_slots and we don't have a pipe, we
       can start infinite jobs.  */

    job_slots = 0;

    /* Create a duplicate pipe, that will be closed in the SIGCHLD
       handler.  If this fails with EBADF, the parent has closed the pipe
       on us because it didn't think we were a submake.  If so, print a
       warning then default to -j1.  */

    if ((job_rfd = dup (job_fds[0])) < 0)
      {
        if (errno != EBADF)
          pfatal_with_name (_("dup jobserver"));

        error (NILF,
               _("warning: jobserver unavailable (using -j1).  Add `+' to parent make rule."));
        job_slots = 1;
        job_fds[0] = job_fds[1] = -1;
        free (jobserver_fds->list);
        free (jobserver_fds);
        jobserver_fds = 0;
      }
  }

  /* If we have >1 slot but no jobserver-fds, then we're a top-level make.
     Set up the pipe and install the fds option for our children.  */

  else if (job_slots > 1)
    {
      char c = '+';

      if (pipe (job_fds) < 0 || (job_rfd = dup (job_fds[0])) < 0)
	pfatal_with_name (_("creating jobs pipe"));
