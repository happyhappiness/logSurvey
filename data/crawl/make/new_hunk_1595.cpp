      register struct child *lastc, *c;
      int child_failed;

      if (err && dead_children == 0)
	{
	  /* We might block for a while, so let the user know why.  */
	  fflush (stdout);
	  error ("*** Waiting for unfinished jobs....");
	}

      /* We have one less dead child to reap.
	 The test and decrement are not atomic; if it is compiled into:
	 	register = dead_children - 1;
		dead_children = register;
	 a SIGCHLD could come between the two instructions.
	 child_handler increments dead_children.
	 The second instruction here would lose that increment.  But the
	 only effect of dead_children being wrong is that we might wait
	 longer than necessary to reap a child, and lose some parallelism;
	 and we might print the "Waiting for unfinished jobs" message above
	 when not necessary.  */

      if (dead_children != 0)
	--dead_children;

      if (debug_flag)
	for (c = children; c != 0; c = c->next)
	  printf ("Live child 0x%08lx PID %d%s\n",
		  (unsigned long int) c,
		  c->pid, c->remote ? " (remote)" : "");

      /* First, check for remote children.  */
      pid = remote_status (&exit_code, &exit_sig, &coredump, 0);
