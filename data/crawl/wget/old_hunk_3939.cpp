	      /* #### Ugly ugly ugly! */
	      char *hurl = str_url (u->proxy ? u->proxy : u, 1);
	      logprintf (LOG_NONVERBOSE, "%s:\n", hurl);
	      free (hurl);
	    }
	  logprintf (LOG_NOTQUIET, _("%s ERROR %d: %s.\n"),
		     tms, hstat.statcode, hstat.error);
	  logputs (LOG_VERBOSE, "\n");
	  FREEHSTAT (hstat);
	  free(filename_plus_orig_suffix);  /* must precede every return! */
	  return WRONGCODE;
	}

