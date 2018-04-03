	{
	  logputs (LOG_NOTQUIET, _("Could not find proxy host.\n"));
	  freeurl (u, 1);
	  if (redirections)
	    string_set_free (redirections);
	  free (url);
	  return PROXERR;
	}
