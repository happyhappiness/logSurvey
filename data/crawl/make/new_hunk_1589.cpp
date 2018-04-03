  start_job (c);
  switch (file->command_state)
    {
    case cs_not_running:
      /* The child is waiting to run.
	 It has already been put on the `waiting_jobs' chain.  */
      break;

    case cs_running:
      c->next = children;
      if (debug_flag)
	printf ("Putting child 0x%08lx PID %05d%s on the chain.\n",
		(unsigned long int) c,
		c->pid, c->remote ? " (remote)" : "");
      children = c;
