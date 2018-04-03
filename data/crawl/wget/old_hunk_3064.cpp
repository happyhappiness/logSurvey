	      xfree (hurl);
	    }
	  logprintf (LOG_NOTQUIET, _("%s ERROR %d: %s.\n"),
		     tms, hstat.statcode, hstat.error);
	  logputs (LOG_VERBOSE, "\n");
	  free_hstat (&hstat);
	  xfree_null (dummy);
