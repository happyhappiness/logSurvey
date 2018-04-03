	  if (!opt.verbose)
	    {
	      /* #### Ugly ugly ugly! */
	      char *hurl = url_string (u, 1);
	      logprintf (LOG_NONVERBOSE, "%s:\n", hurl);
	      xfree (hurl);
	    }
	  logprintf (LOG_NOTQUIET, _("%s ERROR %d: %s.\n"),
		     tms, hstat.statcode, hstat.error);
	  logputs (LOG_VERBOSE, "\n");
	  free_hstat (&hstat);
	  FREE_MAYBE (dummy);
	  return WRONGCODE;
	}

