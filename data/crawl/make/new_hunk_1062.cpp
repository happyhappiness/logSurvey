  /* If not, start it locally.  */
  if (!c->remote)
    {
      /* If we are running at least one job already and the load average
	 is too high, make this one wait.  */
      if (job_slots_used > 0 && load_too_high ())
