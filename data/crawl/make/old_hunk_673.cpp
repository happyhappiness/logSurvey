      fatal (NILF,
             _("internal error: invalid --jobserver-fds string `%s'"), cp);

    /* The combination of a pipe + !job_slots means we're using the
       jobserver.  If !job_slots and we don't have a pipe, we can start
       infinite jobs.  If we see both a pipe and job_slots >0 that means the
