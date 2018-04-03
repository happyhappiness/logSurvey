
      assert (c->job_token != '-');
      if (debug_flag)
        printf (_("Obtained token `%c' for child 0x%08lx (%s).\n"),
                c->job_token, (unsigned long int) c, c->file->name);
    }
#endif

  /* The job is now primed.  Start it running.
     (This will notice if there are in fact no commands.)  */
  (void)start_waiting_job (c);

  if (job_slots == 1)
    /* Since there is only one job slot, make things run linearly.
