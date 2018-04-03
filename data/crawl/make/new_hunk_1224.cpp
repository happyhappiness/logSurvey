	     live and call reap_children again.  */
	  block_sigs ();

#ifdef MAKE_JOBSERVER
	  /* If this job has a token out, return it.  */
          if (c->job_token)
	    {
	      assert(job_slots_used > 0);
	      write (job_fds[1], &c->job_token, 1);
	      if (debug_flag)
		printf ("Released token `%c' for child 0x%08lx.\n",
			c->job_token, (unsigned long int) c);
	      c->job_token = 0;
	    }
#endif
	  /* There is now another slot open.  */
	  if (job_slots_used > 0)
	    --job_slots_used;

	  /* Remove the child from the chain and free it.  */
	  if (lastc == 0)
	    children = c->next;
