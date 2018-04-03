      if (!fp)
	{
	  logprintf (LOG_NOTQUIET, "%s: %s\n", u->local, strerror (errno));
#ifndef HAVE_SSL
		CLOSE_FINISH (sock);
#else
		CLOSE_FINISH (sock,ssl);
#endif /* HAVE_SSL */
	  FREE_MAYBE (all_headers);
	  return FOPENERR;
	}
