	     live and call reap_children again.  */
	  block_sigs ();

	  /* Remove the child from the chain and free it.  */
	  if (lastc == 0)
	    children = c->next;
