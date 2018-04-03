#endif

      if (tcnt != master_job_slots)
        error (NILF,
               "INTERNAL: Exiting with %u jobserver tokens available; should be %u!",
               tcnt, master_job_slots);

#ifdef WINDOWS32
      free_jobserver_semaphore ();
