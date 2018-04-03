      if (result != URLOK || u->proto != URLHTTP)
	{
	  if (u->proto == URLHTTP)
	    logprintf (LOG_NOTQUIET, "Proxy %s: %s.\n", proxy, uerrmsg(result));
	  else
	    logprintf (LOG_NOTQUIET, _("Proxy %s: Must be HTTP.\n"), proxy);
	  freeurl (u, 1);
