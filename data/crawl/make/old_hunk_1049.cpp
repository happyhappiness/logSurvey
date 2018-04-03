
    if (sscanf (cp, "%d,%d", &job_fds[0], &job_fds[1]) != 2)
      fatal (NILF,
             _("internal error: invalid --jobserver-fds string `%s'."), cp);

    /* Set job_slots to 0.  The combination of a pipe + !job_slots means
       we're using the jobserver.  If !job_slots and we don't have a pipe, we
       can start infinite jobs.  */

    job_slots = 0;

    /* Create a duplicate pipe, that will be closed in the SIGCHLD
       handler.  If this fails with EBADF, the parent has closed the pipe
