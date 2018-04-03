  /* Fetch the first command line to be run.  */
  job_next_command (c);

  /* The job is now primed.  Start it running.
     (This will notice if there are in fact no commands.)  */
  (void)start_waiting_job (c);
