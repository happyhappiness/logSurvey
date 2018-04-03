	{
	  logprintf (LOG_NOTQUIET, _("Error parsing proxy URL %s: %s.\n"),
		     proxy, url_error (up_error_code));
	  if (redirections)
	    string_set_free (redirections);
	  xfree (url);
	  return PROXERR;
	}
