      if (c == 0)
	{
	  /* An unknown child died.  */
#ifdef	USG
	  if (!unknown_children_possible)
	    {
#endif
	      char buf[100];
	      sprintf (buf, "Unknown%s job %d", remote ? " remote" : "", pid);
	      if (child_failed)
		child_error (buf, exit_code, exit_sig, coredump,
			     ignore_errors_flag);
	      else
		error ("%s finished.", buf);
#ifdef	USG
	    }
#endif
	}
      else
	{
