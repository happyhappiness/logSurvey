	     live and call reap_children again.  */
	  block_sigs ();

	  /* If this job has a token out, return it.  */
          free_job_token(c);

	  /* There is now another slot open.  */
	  if (job_slots_used > 0)
	    --job_slots_used;
