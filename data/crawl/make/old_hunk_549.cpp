      /* We didn't write one for ourself, so start at 1.  */
      unsigned int tcnt = 1;

      /* Close the write side, so the read() won't hang.  */
      close (job_fds[1]);

      while (read (job_fds[0], &token, 1) == 1)
        ++tcnt;

      if (tcnt != master_job_slots)
        error (NILF,
               "INTERNAL: Exiting with %u jobserver tokens available; should be %u!",
               tcnt, master_job_slots);

      close (job_fds[0]);

      /* Clean out jobserver_fds so we don't pass this information to any
         sub-makes.  Also reset job_slots since it will be put on the command
