	{
	  logputs (LOG_NOTQUIET, _("Could not find proxy host.\n"));
	  freeurl (u, 1);
	  free_slist (redirections);
	  return PROXERR;
	}
      /* Parse the proxy URL.  */
