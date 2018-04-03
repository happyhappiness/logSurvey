	{
	  logputs (LOG_NOTQUIET, _("Could not find proxy host.\n"));
	  url_free (u);
	  if (redirections)
	    string_set_free (redirections);
	  xfree (url);
	  return PROXERR;
	}
