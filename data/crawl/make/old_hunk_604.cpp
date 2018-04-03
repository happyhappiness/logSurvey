  /* If the jobserver-fds option is seen, make sure that -j is reasonable.  */

  if (jobserver_fds)
  {
    const char *cp;
    unsigned int ui;

    for (ui=1; ui < jobserver_fds->idx; ++ui)
      if (!streq (jobserver_fds->list[0], jobserver_fds->list[ui]))
        fatal (NILF, _("internal error: multiple --jobserver-fds options"));

    /* Now parse the fds string and make sure it has the proper format.  */

    cp = jobserver_fds->list[0];

    if (sscanf (cp, "%d,%d", &job_fds[0], &job_fds[1]) != 2)
      fatal (NILF,
             _("internal error: invalid --jobserver-fds string `%s'"), cp);

    DB (DB_JOBS,
	(_("Jobserver client (fds %d,%d)\n"), job_fds[0], job_fds[1]));

    /* The combination of a pipe + !job_slots means we're using the
       jobserver.  If !job_slots and we don't have a pipe, we can start
       infinite jobs.  If we see both a pipe and job_slots >0 that means the
       user set -j explicitly.  This is broken; in this case obey the user
       (ignore the jobserver pipe for this make) but print a message.  */

    if (job_slots > 0)
      error (NILF,
             _("warning: -jN forced in submake: disabling jobserver mode."));

    /* Create a duplicate pipe, that will be closed in the SIGCHLD
       handler.  If this fails with EBADF, the parent has closed the pipe
       on us because it didn't think we were a submake.  If so, print a
       warning then default to -j1.  */

    else if ((job_rfd = dup (job_fds[0])) < 0)
      {
        if (errno != EBADF)
          pfatal_with_name (_("dup jobserver"));

        error (NILF,
               _("warning: jobserver unavailable: using -j1.  Add `+' to parent make rule."));
        job_slots = 1;
      }

    if (job_slots > 0)
      {
        close (job_fds[0]);
        close (job_fds[1]);
        job_fds[0] = job_fds[1] = -1;
        free (jobserver_fds->list);
        free (jobserver_fds);
        jobserver_fds = 0;
      }
  }

  /* If we have >1 slot but no jobserver-fds, then we're a top-level make.
     Set up the pipe and install the fds option for our children.  */
