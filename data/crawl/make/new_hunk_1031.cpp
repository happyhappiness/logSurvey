      fatal (NILF,
             _("internal error: invalid --jobserver-fds string `%s'"), cp);

    /* The combination of a pipe + !job_slots means we're using the
       jobserver.  If !job_slots and we don't have a pipe, we can start
       infinite jobs.  If we see both a pipe and job_slots >0 that means the
       user set -j explicitly.  This is broken; in this case obey the user
       (ignore the jobserver pipe for this make) but print a message.  */

    if (job_slots > 0)
      error (NILF, _("warning: -jN set for submakes: ignoring jobserver."));

    /* Create a duplicate pipe, that will be closed in the SIGCHLD
       handler.  If this fails with EBADF, the parent has closed the pipe
       on us because it didn't think we were a submake.  If so, print a
       warning then default to -j1.  */

    else if ((job_rfd = dup (job_fds[0])) < 0)
      {
        if (errno != EBADF)
          pfatal_with_name (_("dup jobserver"));
