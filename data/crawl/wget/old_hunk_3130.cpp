	  logputs (LOG_VERBOSE, _("Length: "));
	  if (contlen != -1)
	    {
	      logputs (LOG_VERBOSE, legible (contlen));
	      if (contrange != -1)
		logprintf (LOG_VERBOSE, _(" (%s to go)"),
			   legible (contlen - contrange));
	    }
	  else
	    logputs (LOG_VERBOSE,
