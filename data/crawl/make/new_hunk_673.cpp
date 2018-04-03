      fatal (NILF,
             _("internal error: invalid --jobserver-fds string `%s'"), cp);

    DB (DB_JOBS,
	(_("Jobserver client (fds %d,%d)\n"), job_fds[0], job_fds[1]));

    /* The combination of a pipe + !job_slots means we're using the
       jobserver.  If !job_slots and we don't have a pipe, we can start
       infinite jobs.  If we see both a pipe and job_slots >0 that means the
