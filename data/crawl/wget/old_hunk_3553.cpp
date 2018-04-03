  if (res == -2)
    {
      logprintf (LOG_NOTQUIET, _("%s: %s, closing control connection.\n"),
		 u->local, strerror (errno));
      CLOSE (csock);
      rbuf_uninitialize (&con->rbuf);
      return FWRITEERR;
