      if (print_data_base_flag)
	print_data_base ();

      /* Sanity: have we written all our jobserver tokens back?  */

      if (jobserver_tokens)
        error (NILF,
               "INTERNAL: Exiting with %u jobserver tokens (should be 0)!",
               jobserver_tokens);

      /* Sanity: If we're the master, were all the tokens written back?  */

      if (master_job_slots)
        {
          char token;
          /* We didn't write one for ourself, so start at 1.  */
          unsigned int tcnt = 1;

