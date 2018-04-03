	  /* Notice if the target of the commands has been changed.  */
	  notice_finished_file (c->file);

	  if (debug_flag)
	    printf ("Removing child 0x%08lx PID %d%s from chain.\n",
		    (unsigned long int) c,
		    c->pid, c->remote ? " (remote)" : "");

	  /* Remove the child from the chain and free it.  */
	  if (lastc == 0)
	    children = c->next;
