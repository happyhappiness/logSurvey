            || fcntl (job_fds[1], F_GETFL, 0) < 0)
          {
            error (NILF,
                   "warning: jobserver unavailable (using -j1).  Add `+' to parent make rule.");
            job_slots = 1;
            job_fds[0] = job_fds[1] = -1;
            job_slots_str = "1";
