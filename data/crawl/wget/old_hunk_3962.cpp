      if (!fp)
	{
	  logprintf (LOG_NOTQUIET, "%s: %s\n", u->local, strerror (errno));
	  CLOSE (sock);
	  FREE_MAYBE (all_headers);
	  return FOPENERR;
	}
