        error (NILF,
               _("warning: -jN forced in submake: disabling jobserver mode."));

      /* Create a duplicate pipe, that will be closed in the SIGCHLD
         handler.  If this fails with EBADF, the parent has closed the pipe
         on us because it didn't think we were a submake.  If so, print a
         warning then default to -j1.  */

      else if ((job_rfd = dup (job_fds[0])) < 0)
        {
          if (errno != EBADF)
