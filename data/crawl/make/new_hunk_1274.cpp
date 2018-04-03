      int child_failed;
      int any_remote, any_local;

      if (err && block)
	{
	  /* We might block for a while, so let the user know why.  */
	  fflush (stdout);
	  error (NILF, "*** Waiting for unfinished jobs....");
	}

#ifndef WAIT_NOHANG
      /* We have one less dead child to reap.
	 The test and decrement are not atomic; if it is compiled into:
	 	register = dead_children - 1;
