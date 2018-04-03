	  /* If the job failed, and the -k flag was not given, die.  */
	  if (child_failed && !keep_going_flag)
	    die (1);

	  /* See if we have reached our quota for blocking.  */
	  ++dead_children;
	  if (sig < 0 && dead_children == -sig)
	    break;
#if	defined(USG) && !defined(HAVE_SYS_WAIT)
	  else if (sig > 0)
	    break;
#endif
	}
    }

#ifdef	USG
  if (sig > 0)
    (void) SIGNAL (sig, child_handler);
#endif

  if (sig > 0)
    unblock_signals ();

  return 0;
}


/* Wait for N children, blocking if necessary.
   If N is zero, wait until we run out of children.
   If ERR is nonzero and we have any children to wait for,
   print a message on stderr.  */

void
wait_for_children (n, err)
     unsigned int n;
     int err;
{
  push_signals_blocked_p (1);

  if (err && (children != 0 || shell_function_pid != 0))
    {
      fflush (stdout);
      error ("*** Waiting for unfinished jobs....");
    }

  /* Call child_handler to do the work.  */
  (void) child_handler (- (int) n);

  pop_signals_blocked_p ();
}

/* Free the storage allocated for CHILD.  */
