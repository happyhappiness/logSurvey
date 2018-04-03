         jobserver.  If !job_slots and we don't have a pipe, we can start
         infinite jobs.  If we see both a pipe and job_slots >0 that means the
         user set -j explicitly.  This is broken; in this case obey the user
         (ignore the jobserver pipe for this make) but print a message.  */

      if (job_slots > 0)
        error (NILF,
               _("warning: -jN forced in submake: disabling jobserver mode."));

#ifndef WINDOWS32
      /* Create a duplicate pipe, that will be closed in the SIGCHLD
         handler.  If this fails with EBADF, the parent has closed the pipe
