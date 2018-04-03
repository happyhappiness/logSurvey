        error (NILF,
               _("warning: jobserver unavailable (using -j1).  Add `+' to parent make rule."));
        job_slots = 1;
        job_fds[0] = job_fds[1] = -1;
        free (jobserver_fds->list);
        free (jobserver_fds);
