      if (! open_jobserver_semaphore(cp))
        {
          DWORD err = GetLastError();
          fatal (NILF, _("internal error: unable to open jobserver semaphore `%s': (Error %ld: %s)"), 
                 cp, err, map_windows32_error_to_string(err));
        }
      DB (DB_JOBS, (_("Jobserver client (semaphore %s)\n"), cp));
#else
      if (sscanf (cp, "%d,%d", &job_fds[0], &job_fds[1]) != 2)
        fatal (NILF,
               _("internal error: invalid --jobserver-fds string `%s'"), cp);

      DB (DB_JOBS,
          (_("Jobserver client (fds %d,%d)\n"), job_fds[0], job_fds[1]));
