      free ((char *) child->environment);
    }

#ifdef MAKE_JOBSERVER
  /* If this child has a token it hasn't relinquished, give it up now.
     This can happen if the job completes immediately, mainly because
     all the command lines evaluated to empty strings.  */
  if (child->job_token)
    {
      write (job_fds[1], &child->job_token, 1);
      if (debug_flag)
	printf ("Freed token `%c' for child 0x%08lx.\n",
		child->job_token, (unsigned long int) child);
    }
#endif

  free ((char *) child);
}
