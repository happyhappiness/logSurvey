      register struct child *lastc, *c;
      int child_failed;

      if (err && !child_died)
	{
	  /* We might block for a while, so let the user know why.  */
	  fflush (stdout);
	  error ("*** Waiting for unfinished jobs....");
	}

      child_died = 0;

      /* First, check for remote children.  */
      pid = remote_status (&exit_code, &exit_sig, &coredump, 0);
