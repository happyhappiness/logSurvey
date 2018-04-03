	{
	  logputs (LOG_NOTQUIET, _("Could not find proxy host.\n"));
	  url_free (u);
	  xfree (url);
	  return PROXERR;
	}
