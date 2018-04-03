	{
	  logputs (LOG_NOTQUIET, _("Could not find proxy host.\n"));
	  freeurl (u, 1);
	  return PROXERR;
	}
      /* Parse the proxy URL.  */
