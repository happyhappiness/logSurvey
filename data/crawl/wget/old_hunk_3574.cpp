	  if (!opt.verbose)
	    {
	      /* #### Ugly ugly ugly! */
	      char *hurl = str_url (u->proxy ? u->proxy : u, 1);
	      logprintf (LOG_NONVERBOSE, "%s:\n", hurl);
	      xfree (hurl);
	    }
	  logprintf (LOG_NOTQUIET, _("%s ERROR %d: %s.\n"),
		     tms, hstat.statcode, hstat.error);
	  logputs (LOG_VERBOSE, "\n");
	  FREEHSTAT (hstat);
	  return WRONGCODE;
	}

