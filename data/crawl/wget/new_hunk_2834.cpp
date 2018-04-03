	  if (!opt.verbose)
	    {
	      /* #### Ugly ugly ugly! */
	      char *hurl = url_string (u, true);
	      logprintf (LOG_NONVERBOSE, "%s:\n", hurl);
	      xfree (hurl);
	    }
