      if (dead_children != 0)
	--dead_children;

      if (debug_flag)
	for (c = children; c != 0; c = c->next)
	  printf ("Live child 0x%08lx PID %d%s\n",
		  (unsigned long int) c,
		  c->pid, c->remote ? " (remote)" : "");

      /* First, check for remote children.  */
      pid = remote_status (&exit_code, &exit_sig, &coredump, 0);
      if (pid <= 0)
	{
	  /* No remote children.  Check for local children.  */

