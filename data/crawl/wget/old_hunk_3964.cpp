	{
	  logputs (LOG_NOTQUIET, _("Could not find proxy host.\n"));
	  freeurl (u, 1);
	  free_slist (redirections);
	  free (url);
	  return PROXERR;
	}
