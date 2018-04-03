	  logputs (LOG_VERBOSE, _("Length: "));
	  if (contlen != -1)
	    {
	      logputs (LOG_VERBOSE, legible (contlen + contrange));
	      if (contrange)
		logprintf (LOG_VERBOSE, _(" (%s to go)"), legible (contlen));
	    }
	  else
	    logputs (LOG_VERBOSE,
