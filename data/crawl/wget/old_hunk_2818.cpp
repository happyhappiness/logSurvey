	  logputs (LOG_VERBOSE, _("Length: "));
	  if (contlen != -1)
	    {
	      logputs (LOG_VERBOSE, with_thousand_seps (contlen + contrange));
	      if (contlen + contrange >= 1024)
		logprintf (LOG_VERBOSE, " (%s)",
			   human_readable (contlen + contrange));
