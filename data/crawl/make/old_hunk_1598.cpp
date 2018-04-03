	  /* Notice if the target of the commands has been changed.  */
	  notice_finished_file (c->file);

	  /* Remove the child from the chain and free it.  */
	  if (lastc == 0)
	    children = c->next;
