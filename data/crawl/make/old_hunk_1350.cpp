	    notice_finished_file (c->file);

	  if (debug_flag)
	    printf ("Removing child 0x%08lx PID %d%s from chain.\n",
		    (unsigned long int) c,
		    c->pid, c->remote ? " (remote)" : "");

	  /* Block fatal signals while frobnicating the list, so that
	     children and job_slots_used are always consistent.  Otherwise
