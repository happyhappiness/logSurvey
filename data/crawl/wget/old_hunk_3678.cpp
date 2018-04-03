      if (opt.always_rest)
	{
	  /* Check for condition #2. */
	  if (hs->restval == contlen)
	    {
	      logputs (LOG_VERBOSE, _("\
\n    The file is already fully retrieved; nothing to do.\n\n"));
